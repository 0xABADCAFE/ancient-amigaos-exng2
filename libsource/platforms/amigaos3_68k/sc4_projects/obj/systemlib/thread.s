#NO_APP
.text
	.even
.globl __dfRTTI__17ThreadRunObserver
__dfRTTI__17ThreadRunObserver:
	rts
	nop
	.even
.globl __dfRTTI__19ThreadStateObserver
__dfRTTI__19ThreadStateObserver:
	rts
	nop
	.even
.globl __dfRTTI__8Lockable
__dfRTTI__8Lockable:
	rts
	nop
	.even
.globl __dfRTTI__6Thread
__dfRTTI__6Thread:
	rts
	nop
	.even
.globl _throwThreadError
_throwThreadError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q26Thread11ThreadError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L222,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L221
	.even
L222:
	jra L228
	.even
L221:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q26Thread11ThreadError,a0@
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
L228:
L219:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwThreadSecurityViolation
_throwThreadSecurityViolation:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q26Thread23ThreadSecurityViolation,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L251,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L250
	.even
L251:
	jra L259
	.even
L250:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q26Thread23ThreadSecurityViolation,a0@
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
L259:
L248:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwThreadStateViolation
_throwThreadStateViolation:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q26Thread20ThreadStateViolation,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L282,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L281
	.even
L282:
	jra L290
	.even
L281:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q26Thread20ThreadStateViolation,a0@
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
L279:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwThreadStartupFailure
_throwThreadStartupFailure:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q26Thread20ThreadStartupFailure,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L313,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L312
	.even
L313:
	jra L321
	.even
L312:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q26Thread20ThreadStartupFailure,a0@
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
L321:
L310:
	jbsr _terminate__Fv
	nop
.globl ___vt_19ThreadStateObserver
	.even
___vt_19ThreadStateObserver:
	.long 0
	.long ___tf19ThreadStateObserver
	.long __dfRTTI__19ThreadStateObserver
	.long ___pure_virtual
	.long __$_19ThreadStateObserver
	.skip 4
.globl ___vt_17ThreadRunObserver
	.even
___vt_17ThreadRunObserver:
	.long 0
	.long ___tf17ThreadRunObserver
	.long __dfRTTI__17ThreadRunObserver
	.long ___pure_virtual
	.long ___pure_virtual
	.long __$_17ThreadRunObserver
	.skip 4
.globl ___vt_8Lockable
	.even
___vt_8Lockable:
	.long 0
	.long ___tf8Lockable
	.long __dfRTTI__8Lockable
	.long __$_8Lockable
	.skip 4
.globl ___vt_6Thread
	.even
___vt_6Thread:
	.long 0
	.long ___tf6Thread
	.long __dfRTTI__6Thread
	.long _run__6Thread
	.long __$_6Thread
	.skip 4
.comm ___ti6Thread,16
	.even
LC0:
	.long ___ti8Runnable
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x2
LC1:
	.ascii "6Thread\0"
.comm ___ti8Lockable,8
LC2:
	.ascii "8Lockable\0"
.comm ___ti17ThreadRunObserver,8
LC3:
	.ascii "17ThreadRunObserver\0"
.comm ___ti19ThreadStateObserver,8
LC4:
	.ascii "19ThreadStateObserver\0"
	.even
.globl ___tf6Thread
___tf6Thread:
	movel a2,sp@-
	lea ___ti6Thread,a2
	tstl a2@
	jne L323
	jbsr ___tf8Runnable
	pea 1:w
	pea LC0
	pea LC1
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L323:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf8Lockable
___tf8Lockable:
	movel a2,sp@-
	lea ___ti8Lockable,a2
	tstl a2@
	jne L325
	pea LC2
	movel a2,sp@-
	jbsr ___rtti_user
	addql #8,sp
L325:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf17ThreadRunObserver
___tf17ThreadRunObserver:
	movel a2,sp@-
	lea ___ti17ThreadRunObserver,a2
	tstl a2@
	jne L327
	pea LC3
	movel a2,sp@-
	jbsr ___rtti_user
	addql #8,sp
L327:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl __$_17ThreadRunObserver
__$_17ThreadRunObserver:
	movel sp@(4),a0
	movel #___vt_17ThreadRunObserver,a0@
	btst #0,sp@(11)
	jeq L183
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L183:
	rts
	nop
	.even
.globl ___tf19ThreadStateObserver
___tf19ThreadStateObserver:
	movel a2,sp@-
	lea ___ti19ThreadStateObserver,a2
	tstl a2@
	jne L329
	pea LC4
	movel a2,sp@-
	jbsr ___rtti_user
	addql #8,sp
L329:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl __$_19ThreadStateObserver
__$_19ThreadStateObserver:
	movel sp@(4),a0
	movel #___vt_19ThreadStateObserver,a0@
	btst #0,sp@(11)
	jeq L187
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L187:
	rts
	nop
