#NO_APP
.text
	.even
.globl __dfRTTI__Q23XSF8XSFError
__dfRTTI__Q23XSF8XSFError:
	rts
	nop
	.even
.globl __dfRTTI__Q23XSF24IncompatibleVersionError
__dfRTTI__Q23XSF24IncompatibleVersionError:
	rts
	nop
	.even
.globl __dfRTTI__Q23XSF23IncompatibleFormatError
__dfRTTI__Q23XSF23IncompatibleFormatError:
	rts
	nop
	.even
.globl __dfRTTI__Q23XSF26IncompatibleSubformatError
__dfRTTI__Q23XSF26IncompatibleSubformatError:
	rts
	nop
	.even
.globl __dfRTTI__Q23XSF16BadStorableError
__dfRTTI__Q23XSF16BadStorableError:
	rts
	nop
	.even
.globl __dfRTTI__Q23XSF20UnreadyStorableError
__dfRTTI__Q23XSF20UnreadyStorableError:
	rts
	nop
	.even
.globl _throwXSFError
_throwXSFError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q23XSF8XSFError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L245,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L244
	.even
L245:
	jra L251
	.even
L244:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q23XSF8XSFError,a0@
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
L251:
L242:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwIncompatibleVersionError
_throwIncompatibleVersionError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q23XSF24IncompatibleVersionError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L274,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L273
	.even
L274:
	jra L282
	.even
L273:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q23XSF24IncompatibleVersionError,a0@
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
L282:
L271:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwIncompatibleFormatError
_throwIncompatibleFormatError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q23XSF23IncompatibleFormatError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L305,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L304
	.even
L305:
	jra L313
	.even
L304:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q23XSF23IncompatibleFormatError,a0@
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
L302:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwIncompatibleSubformatError
_throwIncompatibleSubformatError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q23XSF26IncompatibleSubformatError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L336,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L335
	.even
L336:
	jra L344
	.even
L335:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q23XSF26IncompatibleSubformatError,a0@
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
L344:
L333:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwBadStorableError
_throwBadStorableError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q23XSF16BadStorableError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L367,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L366
	.even
L367:
	jra L375
	.even
L366:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q23XSF16BadStorableError,a0@
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
L375:
L364:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwUnreadyStorableError
_throwUnreadyStorableError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q23XSF20UnreadyStorableError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L398,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L397
	.even
L398:
	jra L406
	.even
L397:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q23XSF20UnreadyStorableError,a0@
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
L406:
L395:
	jbsr _terminate__Fv
	nop
.globl ___vt_Q23XSF20UnreadyStorableError
	.even
___vt_Q23XSF20UnreadyStorableError:
	.long 0
	.long ___tfQ23XSF20UnreadyStorableError
	.long __dfRTTI__Q23XSF20UnreadyStorableError
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q23XSF16BadStorableError
	.even
___vt_Q23XSF16BadStorableError:
	.long 0
	.long ___tfQ23XSF16BadStorableError
	.long __dfRTTI__Q23XSF16BadStorableError
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q23XSF26IncompatibleSubformatError
	.even
___vt_Q23XSF26IncompatibleSubformatError:
	.long 0
	.long ___tfQ23XSF26IncompatibleSubformatError
	.long __dfRTTI__Q23XSF26IncompatibleSubformatError
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q23XSF23IncompatibleFormatError
	.even
___vt_Q23XSF23IncompatibleFormatError:
	.long 0
	.long ___tfQ23XSF23IncompatibleFormatError
	.long __dfRTTI__Q23XSF23IncompatibleFormatError
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q23XSF24IncompatibleVersionError
	.even
___vt_Q23XSF24IncompatibleVersionError:
	.long 0
	.long ___tfQ23XSF24IncompatibleVersionError
	.long __dfRTTI__Q23XSF24IncompatibleVersionError
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q23XSF8XSFError
	.even
___vt_Q23XSF8XSFError:
	.long 0
	.long ___tfQ23XSF8XSFError
	.long __dfRTTI__Q23XSF8XSFError
	.long _getClass__C12RuntimeError
	.skip 4
.comm ___tiQ23XSF8XSFError,12
LC0:
	.ascii "Q23XSF8XSFError\0"
.comm ___tiQ23XSF24IncompatibleVersionError,12
LC1:
	.ascii "Q23XSF24IncompatibleVersionError\0"
.comm ___tiQ23XSF23IncompatibleFormatError,12
LC2:
	.ascii "Q23XSF23IncompatibleFormatError\0"
.comm ___tiQ23XSF26IncompatibleSubformatError,12
LC3:
	.ascii "Q23XSF26IncompatibleSubformatError\0"
.comm ___tiQ23XSF16BadStorableError,12
LC4:
	.ascii "Q23XSF16BadStorableError\0"
.comm ___tiQ23XSF20UnreadyStorableError,12
LC5:
	.ascii "Q23XSF20UnreadyStorableError\0"
	.even
.globl ___tfQ23XSF8XSFError
___tfQ23XSF8XSFError:
	movel a2,sp@-
	lea ___tiQ23XSF8XSFError,a2
	tstl a2@
	jne L408
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L408:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ23XSF24IncompatibleVersionError
___tfQ23XSF24IncompatibleVersionError:
	movel a2,sp@-
	lea ___tiQ23XSF24IncompatibleVersionError,a2
	tstl a2@
	jne L410
	tstl ___tiQ23XSF8XSFError
	jne L412
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ23XSF8XSFError
	jbsr ___rtti_si
	addw #12,sp
L412:
	pea ___tiQ23XSF8XSFError
	pea LC1
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L410:
	movel #___tiQ23XSF24IncompatibleVersionError,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ23XSF23IncompatibleFormatError
___tfQ23XSF23IncompatibleFormatError:
	movel a2,sp@-
	lea ___tiQ23XSF23IncompatibleFormatError,a2
	tstl a2@
	jne L414
	tstl ___tiQ23XSF8XSFError
	jne L416
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ23XSF8XSFError
	jbsr ___rtti_si
	addw #12,sp
L416:
	pea ___tiQ23XSF8XSFError
	pea LC2
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L414:
	movel #___tiQ23XSF23IncompatibleFormatError,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ23XSF26IncompatibleSubformatError
___tfQ23XSF26IncompatibleSubformatError:
	movel a2,sp@-
	lea ___tiQ23XSF26IncompatibleSubformatError,a2
	tstl a2@
	jne L418
	tstl ___tiQ23XSF8XSFError
	jne L420
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ23XSF8XSFError
	jbsr ___rtti_si
	addw #12,sp
L420:
	pea ___tiQ23XSF8XSFError
	pea LC3
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L418:
	movel #___tiQ23XSF26IncompatibleSubformatError,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ23XSF16BadStorableError
___tfQ23XSF16BadStorableError:
	movel a2,sp@-
	lea ___tiQ23XSF16BadStorableError,a2
	tstl a2@
	jne L422
	tstl ___tiQ23XSF8XSFError
	jne L424
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ23XSF8XSFError
	jbsr ___rtti_si
	addw #12,sp
L424:
	pea ___tiQ23XSF8XSFError
	pea LC4
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L422:
	movel #___tiQ23XSF16BadStorableError,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ23XSF20UnreadyStorableError
___tfQ23XSF20UnreadyStorableError:
	movel a2,sp@-
	lea ___tiQ23XSF20UnreadyStorableError,a2
	tstl a2@
	jne L426
	tstl ___tiQ23XSF8XSFError
	jne L428
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ23XSF8XSFError
	jbsr ___rtti_si
	addw #12,sp
L428:
	pea ___tiQ23XSF8XSFError
	pea LC5
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L426:
	movel #___tiQ23XSF20UnreadyStorableError,d0
	movel sp@+,a2
	rts
