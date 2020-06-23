TEXT	_main(SB), 1, $16

	MOVW	$setSB(SB), R2
	MOVW	$0, R0
	MOVW	R3, _clock(SB)

	MOVW	inargc-4(FP), R3
	MOVW	$inargv+0(FP), R4
	MOVW	R3, 4(R1)
	MOVW	R4, 8(R1)
	BL	ALEF_init(SB)
loop:
	BR	loop

GLOBL	_clock(SB), $4
