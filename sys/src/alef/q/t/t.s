	GLOBL	ff+0(SB),$4
	TEXT	g<>+0(SB),$4
	RETURN	
	TEXT	f<>+0(SB),$16
	MOVW	ff+0(SB),R7
	ANDCC	$7,R7,R10
	MOVW	R10,R7
	MOVW	R10,R8
	MOVW	R10,k-8(SP)
	MOVW	R10,4(R1)
	BL	,g<>+0(SB)
	MOVW	k-8(SP),R3
	BR	,1(PC)
	RETURN	
	TEXT	main+0(SB),$12
	MOVW	$3,R7
	MOVW	R7,4(R1)
	BL	,f<>+0(SB)
	RETURN	
