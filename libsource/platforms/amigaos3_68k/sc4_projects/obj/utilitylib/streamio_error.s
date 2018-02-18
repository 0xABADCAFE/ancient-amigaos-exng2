#NO_APP
.text
	.even
.globl _throwIOError__Q211EXNGPrivate6IOPriv
_throwIOError__Q211EXNGPrivate6IOPriv:
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
	movel #L237,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L236
	.even
L237:
	jra L243
	.even
L236:
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
L243:
L234:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwStreamOpenError__Q211EXNGPrivate6IOPriv
_throwStreamOpenError__Q211EXNGPrivate6IOPriv:
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
	movel #L266,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L265
	.even
L266:
	jra L274
	.even
L265:
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
L274:
L263:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwStreamCreateError__Q211EXNGPrivate6IOPriv
_throwStreamCreateError__Q211EXNGPrivate6IOPriv:
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
	movel #L297,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L296
	.even
L297:
	jra L305
	.even
L296:
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
L305:
L294:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwStreamReadError__Q211EXNGPrivate6IOPriv
_throwStreamReadError__Q211EXNGPrivate6IOPriv:
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
	movel #L328,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L327
	.even
L328:
	jra L336
	.even
L327:
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
L336:
L325:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwStreamWriteError__Q211EXNGPrivate6IOPriv
_throwStreamWriteError__Q211EXNGPrivate6IOPriv:
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
	movel #L359,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L358
	.even
L359:
	jra L367
	.even
L358:
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
L367:
L356:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwStreamSeekError__Q211EXNGPrivate6IOPriv
_throwStreamSeekError__Q211EXNGPrivate6IOPriv:
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
	movel #L390,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L389
	.even
L390:
	jra L398
	.even
L389:
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
L398:
L387:
	jbsr _terminate__Fv
	nop
LC0:
	.ascii "IOError\0"
	.even
.globl _getClass__CQ22IO7IOError
_getClass__CQ22IO7IOError:
	pea a5@
	movel sp,a5
	movel #LC0,d0
	unlk a5
	rts
.globl ___vt_Q22IO7IOError
	.even
___vt_Q22IO7IOError:
	.long 0
	.long ___tfQ22IO7IOError
	.long _getClass__CQ22IO7IOError
	.skip 4
.comm ___ti12RuntimeError,8
LC1:
	.ascii "12RuntimeError\0"
.comm ___ti8Runnable,8
LC2:
	.ascii "8Runnable\0"
.comm ___ti11Application,16
	.even
LC3:
	.long ___ti8Runnable
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
	.long ___ti7Startup
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x23
LC4:
	.ascii "11Application\0"
.comm ___tiQ22IO7IOError,12
LC5:
	.ascii "Q22IO7IOError\0"
.comm ___ti7Startup,8
LC6:
	.ascii "7Startup\0"
	.even
.globl ___tfQ22IO7IOError
___tfQ22IO7IOError:
	pea a5@
	movel sp,a5
	movel a2,sp@-
	lea ___tiQ22IO7IOError,a2
	tstl a2@
	jne L409
	tstl ___ti12RuntimeError
	jne L411
	pea LC1
	pea ___ti12RuntimeError
	jbsr ___rtti_user
	addql #8,sp
L411:
	pea ___ti12RuntimeError
	pea LC5
	movel a2,sp@-
	jbsr ___rtti_si
L409:
	movel #___tiQ22IO7IOError,d0
	movel a5@(-4),a2
	unlk a5
	rts
