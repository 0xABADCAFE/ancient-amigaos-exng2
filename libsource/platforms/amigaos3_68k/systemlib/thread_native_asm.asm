
	mc68020

	SECTION ":0", CODE

	XREF _throwIllegalAddress
	XREF _throwBadAlignment
	XREF _throwZeroDivide
	XREF _throwRangeError
	XREF _throw68K
	XREF _SysBase

	XDEF _trapCPU68K
	
_trapCPU68K
	cmp.l		#2, (a7)
	beq.b		.segFault
	
	cmp.l		#3, (a7)
	beq.b		.badAlign

	cmp.l		#5, (a7)
	beq.b 	.divZero

	cmp.l		#6, (a7)
	beq.b		.rangeErr

	lea		4(a7), a7
	move.l	#_throw68K, 2(a7)
	rte

.segFault
	lea		4(a7), a7
	move.l	#_throwIllegalAddress, 2(a7)
	rte
	
.badAlign
	lea		4(a7), a7
	move.l	#_throwBadAlignment, 2(a7)
	rte

.divZero
	lea		4(a7), a7
	move.l	#_throwZeroDivide, 2(a7)
	rte

.rangeErr
	lea		4(a7), a7
	move.l	#_throwRangeError, 2(a7)
	rte

