;//****************************************************************************//
;//**                                                                        **//
;//** File:         libsrc/plat/amigaos3_68k/systemlib/thread_native.asm     **//
;//** Description:  Native thread handling code                              **//
;//** Comment(s):                                                            **//
;//** Library:      systemlib                                                **//
;//** Created:      2003-02-09                                               **//
;//** Updated:      2003-02-09                                               **//
;//** Author(s):    Karl Churchill                                           **//
;//** Note(s):                                                               **//
;//** Copyright:    (C)1996-2007, eXtropia Studios                           **//
;//**               Karl Churchill                                           **//
;//**               All Rights Reserved.                                     **//
;//**                                                                        **//
;//****************************************************************************//

	mc68020

	SECTION ":0", CODE

	XREF _throwErrorIllegalAddress
	XREF _throwErrorBadAlignment
	XREF _throwErrorZeroDivide
	XREF _throwErrorRange
	XREF _throw68K
	XREF _SysBase

	XDEF _trapCPU68K

; Exception trapping
; Called in supervisor mode, this trap pokes the address of a C-linkage function
; that throws a relevant C++ exception into the 020+ stack frame then rte's.
; The result is that the operation that raised the 680x0 trap appears to throw
; a C++ exception

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
	move.l	#_throwErrorIllegalAddress, 2(a7)
	rte

.badAlign
	lea		4(a7), a7
	move.l	#_throwErrorBadAlignment, 2(a7)
	rte

.divZero
	lea		4(a7), a7
	move.l	#_throwErrorZeroDivide, 2(a7)
	rte

.rangeErr
	lea		4(a7), a7
	move.l	#_throwErrorRange, 2(a7)
	rte

