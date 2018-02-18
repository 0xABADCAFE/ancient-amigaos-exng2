#NO_APP
.text
	.even
.globl __dfRTTI__12RuntimeError
__dfRTTI__12RuntimeError:
	rts
	nop
	.even
.globl __dfRTTI__12InvalidValue
__dfRTTI__12InvalidValue:
	rts
	nop
	.even
.globl __dfRTTI__11NullPointer
__dfRTTI__11NullPointer:
	rts
	nop
	.even
.globl __dfRTTI__10ZeroDivide
__dfRTTI__10ZeroDivide:
	rts
	nop
	.even
.globl __dfRTTI__14IllegalAddress
__dfRTTI__14IllegalAddress:
	rts
	nop
	.even
.globl __dfRTTI__12BadAlignment
__dfRTTI__12BadAlignment:
	rts
	nop
	.even
.globl __dfRTTI__10RangeError
__dfRTTI__10RangeError:
	rts
	nop
	.even
.globl __dfRTTI__14ObjectModified
__dfRTTI__14ObjectModified:
	rts
	nop
	.even
.globl __dfRTTI__15ObjectDestroyed
__dfRTTI__15ObjectDestroyed:
	rts
	nop
	.even
.globl __dfRTTI__13ResourceError
__dfRTTI__13ResourceError:
	rts
	nop
	.even
.globl __dfRTTI__15ResourceInvalid
__dfRTTI__15ResourceInvalid:
	rts
	nop
	.even
.globl __dfRTTI__17ResourceExhausted
__dfRTTI__17ResourceExhausted:
	rts
	nop
	.even
.globl __dfRTTI__19ResourceUnavailable
__dfRTTI__19ResourceUnavailable:
	rts
	nop
	.even
.globl __dfRTTI__14ResourceLocked
__dfRTTI__14ResourceLocked:
	rts
	nop
	.even
.globl __dfRTTI__15ResourceVersion
__dfRTTI__15ResourceVersion:
	rts
	nop
	.even
.globl _getClass__C12RuntimeError
_getClass__C12RuntimeError:
	movel sp@(4),a0
	movel a0@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,a0
	movel a0@,d0
	rts
	nop
	.even
.globl _throwInvalidValue
_throwInvalidValue:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_12InvalidValue,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L238,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L237
	.even
L238:
	jra L244
	.even
L237:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_12InvalidValue,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-32),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-32),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L244:
L235:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwNullPointer
_throwNullPointer:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_11NullPointer,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L261,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L260
	.even
L261:
	jra L267
	.even
L260:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_11NullPointer,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-32),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-32),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L267:
L258:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwZeroDivide
_throwZeroDivide:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_10ZeroDivide,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L284,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L283
	.even
L284:
	jra L290
	.even
L283:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_10ZeroDivide,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-32),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-32),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L290:
L281:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwIllegalAddress
_throwIllegalAddress:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_14IllegalAddress,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L307,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L306
	.even
L307:
	jra L313
	.even
L306:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_14IllegalAddress,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-32),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-32),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L313:
L304:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwBadAlignment
_throwBadAlignment:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_12BadAlignment,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L330,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L329
	.even
L330:
	jra L336
	.even
L329:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_12BadAlignment,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-32),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-32),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L336:
L327:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwRangeError
_throwRangeError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_10RangeError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L353,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L352
	.even
L353:
	jra L359
	.even
L352:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_10RangeError,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-32),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-32),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L359:
L350:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwObjectModified
_throwObjectModified:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_14ObjectModified,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L376,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L375
	.even
L376:
	jra L382
	.even
L375:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_14ObjectModified,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-32),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-32),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L382:
L373:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwObjectDestroyed
_throwObjectDestroyed:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_15ObjectDestroyed,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L399,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L398
	.even
L399:
	jra L405
	.even
L398:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_15ObjectDestroyed,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-32),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-32),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L405:
L396:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwResourceError
_throwResourceError:
	link a5,#-40
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-40)
	movel #___vt_13ResourceError,a5@(-8)
	movel a5@(8),a5@(-4)
	pea 8:w
	jbsr ___eh_alloc
	movel d0,a5@(-36)
	movel a5@(-40),a0
	addql #4,a0
	movel a0@,a5@(-32)
	clrl a5@(-28)
	movel a5,a5@(-24)
	movel #L418,a5@(-20)
	movel sp,a5@(-16)
	movel a0,a1
	jra L417
	.even
L418:
	jra L424
	.even
L417:
	lea a5@(-32),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-36),a0
	movel #___vt_13ResourceError,a0@
	movel a5@(-4),a0@(4)
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-36),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-36),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L424:
L415:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwResourceInvalid
_throwResourceInvalid:
	link a5,#-40
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-40)
	movel a5@(8),a5@(-4)
	movel #___vt_15ResourceInvalid,a5@(-8)
	pea 8:w
	jbsr ___eh_alloc
	movel d0,a5@(-36)
	movel a5@(-40),a0
	addql #4,a0
	movel a0@,a5@(-32)
	clrl a5@(-28)
	movel a5,a5@(-24)
	movel #L441,a5@(-20)
	movel sp,a5@(-16)
	movel a0,a1
	jra L440
	.even
L441:
	jra L449
	.even
L440:
	lea a5@(-32),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-36),a0
	movel #___vt_13ResourceError,a0@
	movel a5@(-4),a0@(4)
	movel #___vt_15ResourceInvalid,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-36),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-36),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L449:
L438:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwResourceExhausted
_throwResourceExhausted:
	link a5,#-40
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-40)
	movel a5@(8),a5@(-4)
	movel #___vt_17ResourceExhausted,a5@(-8)
	pea 8:w
	jbsr ___eh_alloc
	movel d0,a5@(-36)
	movel a5@(-40),a0
	addql #4,a0
	movel a0@,a5@(-32)
	clrl a5@(-28)
	movel a5,a5@(-24)
	movel #L466,a5@(-20)
	movel sp,a5@(-16)
	movel a0,a1
	jra L465
	.even
L466:
	jra L474
	.even
L465:
	lea a5@(-32),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-36),a0
	movel #___vt_13ResourceError,a0@
	movel a5@(-4),a0@(4)
	movel #___vt_17ResourceExhausted,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-36),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-36),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L474:
L463:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwResourceUnavailable
_throwResourceUnavailable:
	link a5,#-40
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-40)
	movel a5@(8),a5@(-4)
	movel #___vt_19ResourceUnavailable,a5@(-8)
	pea 8:w
	jbsr ___eh_alloc
	movel d0,a5@(-36)
	movel a5@(-40),a0
	addql #4,a0
	movel a0@,a5@(-32)
	clrl a5@(-28)
	movel a5,a5@(-24)
	movel #L491,a5@(-20)
	movel sp,a5@(-16)
	movel a0,a1
	jra L490
	.even
L491:
	jra L499
	.even
L490:
	lea a5@(-32),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-36),a0
	movel #___vt_13ResourceError,a0@
	movel a5@(-4),a0@(4)
	movel #___vt_19ResourceUnavailable,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-36),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-36),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L499:
L488:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwResourceLocked
_throwResourceLocked:
	link a5,#-40
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-40)
	movel a5@(8),a5@(-4)
	movel #___vt_14ResourceLocked,a5@(-8)
	pea 8:w
	jbsr ___eh_alloc
	movel d0,a5@(-36)
	movel a5@(-40),a0
	addql #4,a0
	movel a0@,a5@(-32)
	clrl a5@(-28)
	movel a5,a5@(-24)
	movel #L516,a5@(-20)
	movel sp,a5@(-16)
	movel a0,a1
	jra L515
	.even
L516:
	jra L524
	.even
L515:
	lea a5@(-32),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-36),a0
	movel #___vt_13ResourceError,a0@
	movel a5@(-4),a0@(4)
	movel #___vt_14ResourceLocked,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-36),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-36),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L524:
L513:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwResourceVersion
_throwResourceVersion:
	link a5,#-40
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-40)
	movel a5@(8),a5@(-4)
	movel #___vt_15ResourceVersion,a5@(-8)
	pea 8:w
	jbsr ___eh_alloc
	movel d0,a5@(-36)
	movel a5@(-40),a0
	addql #4,a0
	movel a0@,a5@(-32)
	clrl a5@(-28)
	movel a5,a5@(-24)
	movel #L541,a5@(-20)
	movel sp,a5@(-16)
	movel a0,a1
	jra L540
	.even
L541:
	jra L549
	.even
L540:
	lea a5@(-32),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-36),a0
	movel #___vt_13ResourceError,a0@
	movel a5@(-4),a0@(4)
	movel #___vt_15ResourceVersion,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-36),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-36),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L549:
L538:
	jbsr _terminate__Fv
	nop
.globl ___vt_15ResourceVersion
	.even
___vt_15ResourceVersion:
	.long 0
	.long ___tf15ResourceVersion
	.long __dfRTTI__15ResourceVersion
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_14ResourceLocked
	.even
___vt_14ResourceLocked:
	.long 0
	.long ___tf14ResourceLocked
	.long __dfRTTI__14ResourceLocked
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_19ResourceUnavailable
	.even
___vt_19ResourceUnavailable:
	.long 0
	.long ___tf19ResourceUnavailable
	.long __dfRTTI__19ResourceUnavailable
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_17ResourceExhausted
	.even
___vt_17ResourceExhausted:
	.long 0
	.long ___tf17ResourceExhausted
	.long __dfRTTI__17ResourceExhausted
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_15ResourceInvalid
	.even
___vt_15ResourceInvalid:
	.long 0
	.long ___tf15ResourceInvalid
	.long __dfRTTI__15ResourceInvalid
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_13ResourceError
	.even
___vt_13ResourceError:
	.long 0
	.long ___tf13ResourceError
	.long __dfRTTI__13ResourceError
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_15ObjectDestroyed
	.even
___vt_15ObjectDestroyed:
	.long 0
	.long ___tf15ObjectDestroyed
	.long __dfRTTI__15ObjectDestroyed
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_14ObjectModified
	.even
___vt_14ObjectModified:
	.long 0
	.long ___tf14ObjectModified
	.long __dfRTTI__14ObjectModified
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_10RangeError
	.even
___vt_10RangeError:
	.long 0
	.long ___tf10RangeError
	.long __dfRTTI__10RangeError
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_12BadAlignment
	.even
___vt_12BadAlignment:
	.long 0
	.long ___tf12BadAlignment
	.long __dfRTTI__12BadAlignment
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_14IllegalAddress
	.even
___vt_14IllegalAddress:
	.long 0
	.long ___tf14IllegalAddress
	.long __dfRTTI__14IllegalAddress
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_10ZeroDivide
	.even
___vt_10ZeroDivide:
	.long 0
	.long ___tf10ZeroDivide
	.long __dfRTTI__10ZeroDivide
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_11NullPointer
	.even
___vt_11NullPointer:
	.long 0
	.long ___tf11NullPointer
	.long __dfRTTI__11NullPointer
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_12InvalidValue
	.even
___vt_12InvalidValue:
	.long 0
	.long ___tf12InvalidValue
	.long __dfRTTI__12InvalidValue
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_12RuntimeError
	.even
___vt_12RuntimeError:
	.long 0
	.long ___tf12RuntimeError
	.long __dfRTTI__12RuntimeError
	.long _getClass__C12RuntimeError
	.skip 4
.comm ___ti12RuntimeError,8
LC0:
	.ascii "12RuntimeError\0"
.comm ___ti12InvalidValue,12
LC1:
	.ascii "12InvalidValue\0"
.comm ___ti11NullPointer,12
LC2:
	.ascii "11NullPointer\0"
.comm ___ti10ZeroDivide,12
LC3:
	.ascii "10ZeroDivide\0"
.comm ___ti14IllegalAddress,12
LC4:
	.ascii "14IllegalAddress\0"
.comm ___ti12BadAlignment,12
LC5:
	.ascii "12BadAlignment\0"
.comm ___ti10RangeError,12
LC6:
	.ascii "10RangeError\0"
.comm ___ti14ObjectModified,12
LC7:
	.ascii "14ObjectModified\0"
.comm ___ti15ObjectDestroyed,12
LC8:
	.ascii "15ObjectDestroyed\0"
.comm ___ti13ResourceError,12
LC9:
	.ascii "13ResourceError\0"
.comm ___ti15ResourceInvalid,12
LC10:
	.ascii "15ResourceInvalid\0"
.comm ___ti17ResourceExhausted,12
LC11:
	.ascii "17ResourceExhausted\0"
.comm ___ti19ResourceUnavailable,12
LC12:
	.ascii "19ResourceUnavailable\0"
.comm ___ti14ResourceLocked,12
LC13:
	.ascii "14ResourceLocked\0"
.comm ___ti15ResourceVersion,12
LC14:
	.ascii "15ResourceVersion\0"
	.even
.globl ___tf12RuntimeError
___tf12RuntimeError:
	movel a2,sp@-
	lea ___ti12RuntimeError,a2
	tstl a2@
	jne L551
	pea LC0
	movel a2,sp@-
	jbsr ___rtti_user
	addql #8,sp
L551:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf12InvalidValue
___tf12InvalidValue:
	movel a2,sp@-
	lea ___ti12InvalidValue,a2
	tstl a2@
	jne L553
	tstl ___ti12RuntimeError
	jne L555
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L555:
	pea ___ti12RuntimeError
	pea LC1
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L553:
	movel #___ti12InvalidValue,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf11NullPointer
___tf11NullPointer:
	movel a2,sp@-
	lea ___ti11NullPointer,a2
	tstl a2@
	jne L557
	tstl ___ti12RuntimeError
	jne L559
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L559:
	pea ___ti12RuntimeError
	pea LC2
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L557:
	movel #___ti11NullPointer,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf10ZeroDivide
___tf10ZeroDivide:
	movel a2,sp@-
	lea ___ti10ZeroDivide,a2
	tstl a2@
	jne L561
	tstl ___ti12RuntimeError
	jne L563
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L563:
	pea ___ti12RuntimeError
	pea LC3
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L561:
	movel #___ti10ZeroDivide,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf14IllegalAddress
___tf14IllegalAddress:
	movel a2,sp@-
	lea ___ti14IllegalAddress,a2
	tstl a2@
	jne L565
	tstl ___ti12RuntimeError
	jne L567
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L567:
	pea ___ti12RuntimeError
	pea LC4
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L565:
	movel #___ti14IllegalAddress,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf12BadAlignment
___tf12BadAlignment:
	movel a2,sp@-
	lea ___ti12BadAlignment,a2
	tstl a2@
	jne L569
	tstl ___ti12RuntimeError
	jne L571
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L571:
	pea ___ti12RuntimeError
	pea LC5
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L569:
	movel #___ti12BadAlignment,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf10RangeError
___tf10RangeError:
	movel a2,sp@-
	lea ___ti10RangeError,a2
	tstl a2@
	jne L573
	tstl ___ti12RuntimeError
	jne L575
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L575:
	pea ___ti12RuntimeError
	pea LC6
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L573:
	movel #___ti10RangeError,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf14ObjectModified
___tf14ObjectModified:
	movel a2,sp@-
	lea ___ti14ObjectModified,a2
	tstl a2@
	jne L577
	tstl ___ti12RuntimeError
	jne L579
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L579:
	pea ___ti12RuntimeError
	pea LC7
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L577:
	movel #___ti14ObjectModified,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf15ObjectDestroyed
___tf15ObjectDestroyed:
	movel a2,sp@-
	lea ___ti15ObjectDestroyed,a2
	tstl a2@
	jne L581
	tstl ___ti12RuntimeError
	jne L583
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L583:
	pea ___ti12RuntimeError
	pea LC8
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L581:
	movel #___ti15ObjectDestroyed,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf13ResourceError
___tf13ResourceError:
	movel a2,sp@-
	lea ___ti13ResourceError,a2
	tstl a2@
	jne L585
	tstl ___ti12RuntimeError
	jne L587
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L587:
	pea ___ti12RuntimeError
	pea LC9
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L585:
	movel #___ti13ResourceError,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf15ResourceInvalid
___tf15ResourceInvalid:
	tstl ___ti15ResourceInvalid
	jne L589
	tstl ___ti13ResourceError
	jne L593
	tstl ___ti12RuntimeError
	jne L592
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L592:
	pea ___ti12RuntimeError
	pea LC9
	pea ___ti13ResourceError
	jbsr ___rtti_si
	addw #12,sp
L593:
	pea ___ti13ResourceError
	pea LC10
	pea ___ti15ResourceInvalid
	jbsr ___rtti_si
	addw #12,sp
L589:
	movel #___ti15ResourceInvalid,d0
	rts
	nop
	.even
.globl ___tf17ResourceExhausted
___tf17ResourceExhausted:
	tstl ___ti17ResourceExhausted
	jne L595
	tstl ___ti13ResourceError
	jne L599
	tstl ___ti12RuntimeError
	jne L598
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L598:
	pea ___ti12RuntimeError
	pea LC9
	pea ___ti13ResourceError
	jbsr ___rtti_si
	addw #12,sp
L599:
	pea ___ti13ResourceError
	pea LC11
	pea ___ti17ResourceExhausted
	jbsr ___rtti_si
	addw #12,sp
L595:
	movel #___ti17ResourceExhausted,d0
	rts
	nop
	.even
.globl ___tf19ResourceUnavailable
___tf19ResourceUnavailable:
	tstl ___ti19ResourceUnavailable
	jne L601
	tstl ___ti13ResourceError
	jne L605
	tstl ___ti12RuntimeError
	jne L604
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L604:
	pea ___ti12RuntimeError
	pea LC9
	pea ___ti13ResourceError
	jbsr ___rtti_si
	addw #12,sp
L605:
	pea ___ti13ResourceError
	pea LC12
	pea ___ti19ResourceUnavailable
	jbsr ___rtti_si
	addw #12,sp
L601:
	movel #___ti19ResourceUnavailable,d0
	rts
	nop
	.even
.globl ___tf14ResourceLocked
___tf14ResourceLocked:
	tstl ___ti14ResourceLocked
	jne L607
	tstl ___ti13ResourceError
	jne L611
	tstl ___ti12RuntimeError
	jne L610
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L610:
	pea ___ti12RuntimeError
	pea LC9
	pea ___ti13ResourceError
	jbsr ___rtti_si
	addw #12,sp
L611:
	pea ___ti13ResourceError
	pea LC13
	pea ___ti14ResourceLocked
	jbsr ___rtti_si
	addw #12,sp
L607:
	movel #___ti14ResourceLocked,d0
	rts
	nop
	.even
.globl ___tf15ResourceVersion
___tf15ResourceVersion:
	tstl ___ti15ResourceVersion
	jne L613
	tstl ___ti13ResourceError
	jne L617
	tstl ___ti12RuntimeError
	jne L616
	pea LC0
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L616:
	pea ___ti12RuntimeError
	pea LC9
	pea ___ti13ResourceError
	jbsr ___rtti_si
	addw #12,sp
L617:
	pea ___ti13ResourceError
	pea LC14
	pea ___ti15ResourceVersion
	jbsr ___rtti_si
	addw #12,sp
L613:
	movel #___ti15ResourceVersion,d0
	rts
	nop
