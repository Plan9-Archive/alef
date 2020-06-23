	TEXT	memchr(SB), $0
#define	BDNZ	BC	16,0,
	MOVW	s1+0(FP), R3
	MOVW	n+8(FP), R7
	MOVBZ	c+7(FP), R4
	CMP	R7, $0
	BEQ	nf
	MOVW	R7, CTR
	SUB	$1, R3
l1:
	MOVBZU	1(R3), R6
	CMP	R6, R4
	BEQ	eq
	BDNZ	l1
nf:
	MOVW	$0, R3
	RETURN
eq:
	RETURN
