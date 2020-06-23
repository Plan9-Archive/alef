/*
 * BUG: it's slow
 */
	TEXT	strcpy(SB), $0
	MOVW	s1+0(FP), R3
	MOVW	s2+4(FP), R4
	SUB	$1, R3
	SUB	$1, R4
l1:
	MOVBZU	1(R4), R6
	CMP	R6, $0
	MOVBZU	R6, 1(R3)
	BNE	l1
	MOVW	s1+0(FP), R3
	RETURN
