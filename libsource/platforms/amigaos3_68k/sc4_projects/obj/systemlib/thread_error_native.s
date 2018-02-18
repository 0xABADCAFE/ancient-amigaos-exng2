#NO_APP
.text
	.even
.globl __dfRTTI__Q26Thread11ThreadError
__dfRTTI__Q26Thread11ThreadError:
	rts
	nop
	.even
.globl __dfRTTI__Q26Thread23ThreadSecurityViolation
__dfRTTI__Q26Thread23ThreadSecurityViolation:
	rts
	nop
	.even
.globl __dfRTTI__Q26Thread20ThreadStateViolation
__dfRTTI__Q26Thread20ThreadStateViolation:
	rts
	nop
	.even
.globl __dfRTTI__Q26Thread20ThreadStartupFailure
__dfRTTI__Q26Thread20ThreadStartupFailure:
	rts
	nop
	.even
.globl __dfRTTI__Q211EXNGPrivate16Unhandled68KTrap
__dfRTTI__Q211EXNGPrivate16Unhandled68KTrap:
	rts
	nop
	.even
.globl _throw68K
_throw68K:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q211EXNGPrivate16Unhandled68KTrap,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L225,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L224
	.even
L225:
	jra L231
	.even
L224:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q211EXNGPrivate16Unhandled68KTrap,a0@
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
L231:
L222:
	jbsr _terminate__Fv
	nop
.globl ___vt_Q211EXNGPrivate16Unhandled68KTrap
	.even
___vt_Q211EXNGPrivate16Unhandled68KTrap:
	.long 0
	.long ___tfQ211EXNGPrivate16Unhandled68KTrap
	.long __dfRTTI__Q211EXNGPrivate16Unhandled68KTrap
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q26Thread20ThreadStartupFailure
	.even
___vt_Q26Thread20ThreadStartupFailure:
	.long 0
	.long ___tfQ26Thread20ThreadStartupFailure
	.long __dfRTTI__Q26Thread20ThreadStartupFailure
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q26Thread20ThreadStateViolation
	.even
___vt_Q26Thread20ThreadStateViolation:
	.long 0
	.long ___tfQ26Thread20ThreadStateViolation
	.long __dfRTTI__Q26Thread20ThreadStateViolation
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q26Thread23ThreadSecurityViolation
	.even
___vt_Q26Thread23ThreadSecurityViolation:
	.long 0
	.long ___tfQ26Thread23ThreadSecurityViolation
	.long __dfRTTI__Q26Thread23ThreadSecurityViolation
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q26Thread11ThreadError
	.even
___vt_Q26Thread11ThreadError:
	.long 0
	.long ___tfQ26Thread11ThreadError
	.long __dfRTTI__Q26Thread11ThreadError
	.long _getClass__C12RuntimeError
	.skip 4
.comm ___tiQ26Thread11ThreadError,12
LC0:
	.ascii "Q26Thread11ThreadError\0"
.comm ___tiQ26Thread23ThreadSecurityViolation,12
LC1:
	.ascii "Q26Thread23ThreadSecurityViolation\0"
.comm ___tiQ26Thread20ThreadStateViolation,12
LC2:
	.ascii "Q26Thread20ThreadStateViolation\0"
.comm ___tiQ26Thread20ThreadStartupFailure,12
LC3:
	.ascii "Q26Thread20ThreadStartupFailure\0"
.comm ___tiQ211EXNGPrivate16Unhandled68KTrap,12
LC4:
	.ascii "Q211EXNGPrivate16Unhandled68KTrap\0"
	.even
.globl ___tfQ26Thread11ThreadError
___tfQ26Thread11ThreadError:
	movel a2,sp@-
	lea ___tiQ26Thread11ThreadError,a2
	tstl a2@
	jne L233
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L233:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ26Thread23ThreadSecurityViolation
___tfQ26Thread23ThreadSecurityViolation:
	movel a2,sp@-
	lea ___tiQ26Thread23ThreadSecurityViolation,a2
	tstl a2@
	jne L235
	tstl ___tiQ26Thread11ThreadError
	jne L237
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ26Thread11ThreadError
	jbsr ___rtti_si
	addw #12,sp
L237:
	pea ___tiQ26Thread11ThreadError
	pea LC1
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L235:
	movel #___tiQ26Thread23ThreadSecurityViolation,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ26Thread20ThreadStateViolation
___tfQ26Thread20ThreadStateViolation:
	movel a2,sp@-
	lea ___tiQ26Thread20ThreadStateViolation,a2
	tstl a2@
	jne L239
	tstl ___tiQ26Thread11ThreadError
	jne L241
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ26Thread11ThreadError
	jbsr ___rtti_si
	addw #12,sp
L241:
	pea ___tiQ26Thread11ThreadError
	pea LC2
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L239:
	movel #___tiQ26Thread20ThreadStateViolation,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ26Thread20ThreadStartupFailure
___tfQ26Thread20ThreadStartupFailure:
	movel a2,sp@-
	lea ___tiQ26Thread20ThreadStartupFailure,a2
	tstl a2@
	jne L243
	tstl ___tiQ26Thread11ThreadError
	jne L245
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ26Thread11ThreadError
	jbsr ___rtti_si
	addw #12,sp
L245:
	pea ___tiQ26Thread11ThreadError
	pea LC3
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L243:
	movel #___tiQ26Thread20ThreadStartupFailure,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ211EXNGPrivate16Unhandled68KTrap
___tfQ211EXNGPrivate16Unhandled68KTrap:
	movel a2,sp@-
	lea ___tiQ211EXNGPrivate16Unhandled68KTrap,a2
	tstl a2@
	jne L247
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC4
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L247:
	movel a2,d0
	movel sp@+,a2
	rts
