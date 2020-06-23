/*
 *	Link to a new stack, freeing the parent
 */

	TEXT	ALEF_linksp(SB), $-4
	MOVW	0(FP), R3		/* ptr to spin */
	MOVW	4(FP), R8		/* new stack */
	MOVW	8(FP), R9		/* func to exec */
	MOVW	R9, LR

	MOVW	$0, R0
	MOVW	R0, (R3)		/* free parent */
	ADD	$-4, R8
	MOVW	R8, R1			/* new stack */
	BL	(LR)

	MOVW	$0, R0
	MOVW	R0,R8
	MOVW	R8,4(R1)
	BL	terminate(SB)
	RETURN
/*
 *	Return R3 which at func entry contains 
 *	a pointer to the return complex
 */
	TEXT	ALEF_getrp(SB), $-4
	RETURN
/*
 *	task switch
 */
	TEXT	ALEF_switch(SB),$0
	MOVW	0(FP), R8		/* from task */
	MOVW	4(FP), R9		/* to task */
	MOVW	8(FP), R3
	CMP	R8, R9
	BEQ	done			/* same task in/out */
	CMP	R8, $0
	BEQ	nosave
	MOVW	LR, R15
	MOVW	R15, 4(R8)		/* pc */
	MOVW	R1, 0(R8)		/* sp */
nosave:	MOVW	4(R9), R15
	MOVW	R15, LR
	MOVW	0(R9), R1
done:	RETURN
/*
 *	link to a coroutine
 */
	TEXT	ALEF_linktask(SB),$-4
	CMP	R3, $0
	BEQ	nofree
	SUB	$8, R1
	MOVW	R3, 4(R1)
	BL	free(SB)
	ADD	$8, R1
nofree:
	MOVW	0(R1),R3
	MOVW	R3, LR
	MOVW	$0, R0
	MOVW	R0, 0(R1)		/* terminate stack root for acid */
	BL	(LR)
	MOVW	$0, R0
	MOVW	R0,4(R1)
	BL	terminate(SB)
	RETURN

	TEXT	abort(SB),$-4
	MOVW	$0, R0
	MOVW	R3,0(R0)
	RETURN
TEXT	tas(SB), $0
	SYNC
	MOVW	0(FP), R4
	MOVW	$0xdeaddead,R5
tas1:
	DCBF	(R4)	/* 603 bug */
	LWAR	(R4), R3
	CMP	R3, $0
	BNE	tas0
	STWCCC	R5, (R4)
	BNE	tas1
tas0:
	ISYNC
	RETURN
