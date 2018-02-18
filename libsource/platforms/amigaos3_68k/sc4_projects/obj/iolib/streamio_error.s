#NO_APP
.text
	.even
.globl __dfRTTI__Q22IO7IOError
__dfRTTI__Q22IO7IOError:
	rts
	nop
	.even
.globl __dfRTTI__Q22IO15StreamOpenError
__dfRTTI__Q22IO15StreamOpenError:
	rts
	nop
	.even
.globl __dfRTTI__Q22IO17StreamCreateError
__dfRTTI__Q22IO17StreamCreateError:
	rts
	nop
	.even
.globl __dfRTTI__Q22IO15StreamReadError
__dfRTTI__Q22IO15StreamReadError:
	rts
	nop
	.even
.globl __dfRTTI__Q22IO16StreamWriteError
__dfRTTI__Q22IO16StreamWriteError:
	rts
	nop
	.even
.globl __dfRTTI__Q22IO15StreamSeekError
__dfRTTI__Q22IO15StreamSeekError:
	rts
	nop
	.even
.globl _throwIOError
_throwIOError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q22IO7IOError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L239,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L238
	.even
L239:
	jra L245
	.even
L238:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q22IO7IOError,a0@
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
L245:
L236:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwStreamOpenError
_throwStreamOpenError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q22IO15StreamOpenError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L268,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L267
	.even
L268:
	jra L276
	.even
L267:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q22IO15StreamOpenError,a0@
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
L276:
L265:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwStreamCreateError
_throwStreamCreateError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q22IO17StreamCreateError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L299,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L298
	.even
L299:
	jra L307
	.even
L298:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q22IO17StreamCreateError,a0@
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
L307:
L296:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwStreamReadError
_throwStreamReadError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q22IO15StreamReadError,a5@(-4)
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
	jra L338
	.even
L329:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q22IO15StreamReadError,a0@
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
L338:
L327:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwStreamWriteError
_throwStreamWriteError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q22IO16StreamWriteError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L361,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L360
	.even
L361:
	jra L369
	.even
L360:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q22IO16StreamWriteError,a0@
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
L369:
L358:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwStreamSeekError
_throwStreamSeekError:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q22IO15StreamSeekError,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L392,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L391
	.even
L392:
	jra L400
	.even
L391:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q22IO15StreamSeekError,a0@
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
L400:
L389:
	jbsr _terminate__Fv
	nop
.globl ___vt_Q22IO15StreamSeekError
	.even
___vt_Q22IO15StreamSeekError:
	.long 0
	.long ___tfQ22IO15StreamSeekError
	.long __dfRTTI__Q22IO15StreamSeekError
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q22IO16StreamWriteError
	.even
___vt_Q22IO16StreamWriteError:
	.long 0
	.long ___tfQ22IO16StreamWriteError
	.long __dfRTTI__Q22IO16StreamWriteError
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q22IO15StreamReadError
	.even
___vt_Q22IO15StreamReadError:
	.long 0
	.long ___tfQ22IO15StreamReadError
	.long __dfRTTI__Q22IO15StreamReadError
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q22IO17StreamCreateError
	.even
___vt_Q22IO17StreamCreateError:
	.long 0
	.long ___tfQ22IO17StreamCreateError
	.long __dfRTTI__Q22IO17StreamCreateError
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q22IO15StreamOpenError
	.even
___vt_Q22IO15StreamOpenError:
	.long 0
	.long ___tfQ22IO15StreamOpenError
	.long __dfRTTI__Q22IO15StreamOpenError
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q22IO7IOError
	.even
___vt_Q22IO7IOError:
	.long 0
	.long ___tfQ22IO7IOError
	.long __dfRTTI__Q22IO7IOError
	.long _getClass__C12RuntimeError
	.skip 4
.comm ___tiQ22IO7IOError,12
LC0:
	.ascii "Q22IO7IOError\0"
.comm ___tiQ22IO15StreamOpenError,12
LC1:
	.ascii "Q22IO15StreamOpenError\0"
.comm ___tiQ22IO17StreamCreateError,12
LC2:
	.ascii "Q22IO17StreamCreateError\0"
.comm ___tiQ22IO15StreamReadError,12
LC3:
	.ascii "Q22IO15StreamReadError\0"
.comm ___tiQ22IO16StreamWriteError,12
LC4:
	.ascii "Q22IO16StreamWriteError\0"
.comm ___tiQ22IO15StreamSeekError,12
LC5:
	.ascii "Q22IO15StreamSeekError\0"
	.even
.globl ___tfQ22IO7IOError
___tfQ22IO7IOError:
	movel a2,sp@-
	lea ___tiQ22IO7IOError,a2
	tstl a2@
	jne L402
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L402:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ22IO15StreamOpenError
___tfQ22IO15StreamOpenError:
	movel a2,sp@-
	lea ___tiQ22IO15StreamOpenError,a2
	tstl a2@
	jne L404
	tstl ___tiQ22IO7IOError
	jne L406
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ22IO7IOError
	jbsr ___rtti_si
	addw #12,sp
L406:
	pea ___tiQ22IO7IOError
	pea LC1
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L404:
	movel #___tiQ22IO15StreamOpenError,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ22IO17StreamCreateError
___tfQ22IO17StreamCreateError:
	movel a2,sp@-
	lea ___tiQ22IO17StreamCreateError,a2
	tstl a2@
	jne L408
	tstl ___tiQ22IO7IOError
	jne L410
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ22IO7IOError
	jbsr ___rtti_si
	addw #12,sp
L410:
	pea ___tiQ22IO7IOError
	pea LC2
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L408:
	movel #___tiQ22IO17StreamCreateError,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ22IO15StreamReadError
___tfQ22IO15StreamReadError:
	movel a2,sp@-
	lea ___tiQ22IO15StreamReadError,a2
	tstl a2@
	jne L412
	tstl ___tiQ22IO7IOError
	jne L414
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ22IO7IOError
	jbsr ___rtti_si
	addw #12,sp
L414:
	pea ___tiQ22IO7IOError
	pea LC3
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L412:
	movel #___tiQ22IO15StreamReadError,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ22IO16StreamWriteError
___tfQ22IO16StreamWriteError:
	movel a2,sp@-
	lea ___tiQ22IO16StreamWriteError,a2
	tstl a2@
	jne L416
	tstl ___tiQ22IO7IOError
	jne L418
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ22IO7IOError
	jbsr ___rtti_si
	addw #12,sp
L418:
	pea ___tiQ22IO7IOError
	pea LC4
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L416:
	movel #___tiQ22IO16StreamWriteError,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ22IO15StreamSeekError
___tfQ22IO15StreamSeekError:
	movel a2,sp@-
	lea ___tiQ22IO15StreamSeekError,a2
	tstl a2@
	jne L420
	tstl ___tiQ22IO7IOError
	jne L422
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC0
	pea ___tiQ22IO7IOError
	jbsr ___rtti_si
	addw #12,sp
L422:
	pea ___tiQ22IO7IOError
	pea LC5
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L420:
	movel #___tiQ22IO15StreamSeekError,d0
	movel sp@+,a2
	rts
