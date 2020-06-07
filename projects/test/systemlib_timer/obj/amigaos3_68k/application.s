#NO_APP
.text
	.even
.globl _createInstance__11Application
_createInstance__11Application:
	link a5,#-60
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-56)
	pea 14:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L299,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L298
	.even
L299:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L296
	.even
L298:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___15MainApplication
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L295
	.even
L296:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L305,a5@(-36)
	movel sp,a5@(-32)
	jra L304
	.even
L305:
	jra L309
	.even
L304:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L307
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L307:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L309:
L302:
	jbsr ___terminate
	.even
L295:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L318
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L318:
	rts
	nop
	.even
.globl ___15MainApplication
___15MainApplication:
	link a5,#-100
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,d1
	movel a5@(8),a0
	movel #___vt_8Runnable,a0@
	movel d1,a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L324,a5@(-12)
	movel sp,a5@(-8)
L324:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_11Application,a0@
	movel d1,a0
	addql #4,a0
	movel a0@,a1
	movel a1@,a0@
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L338,a5@(-60)
	movel sp,a5@(-56)
	movel a0,a5@(-100)
	jra L337
	.even
L338:
	jra L352
	.even
L337:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_15MainApplication,a0@
	pea a0@(6)
	jbsr ___Q24Time10MilliClock
	addql #4,sp
	movel a5@(-100),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L351
	.even
L352:
L335:
	movel a5@(-100),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L343,a5@(-84)
	movel sp,a5@(-80)
	jra L342
	.even
L343:
	jra L353
	.even
L342:
	lea a5@(-96),a0
	movel a5@(-100),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_8Runnable,a1@
	movel a5@(-100),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L353:
L340:
	jbsr ___terminate
	.even
L351:
	moveml a5@(-212),#0x5cfc
	fmovem a5@(-172),#0x3f
	unlk a5
	rts
	.even
.globl __$_15MainApplication
__$_15MainApplication:
	movel sp@(4),a0
	movel #___vt_8Runnable,a0@
	btst #0,sp@(11)
	jeq L361
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L361:
	rts
	nop
LC0:
	.ascii "time1 = { %lu, %lu } [%llu] @ %luHz\12time2 = { %lu, %lu } [%llu] @ %luHz\12diff %llu\12\0"
LC1:
	.ascii "Elapsed %f ms\12\0"
	.even
.globl _run__15MainApplication
_run__15MainApplication:
	addw #-20,sp
	moveml #0x3f22,sp@-
	movel sp@(56),d7
	addql #6,d7
	movel d7,sp@-
	jbsr _set__Q24Time10MilliClock
	addql #4,sp
	lea sp@(40),a0
	movel _TimerBase,a6
#APP
	# ULONG ReadEClock(struct EClockVal* dest)
	jsr -60(a6)
	
#NO_APP
	movel d0,a2
	pea 8:w
	pea 1000:w
	jbsr _sleep__6ThreadUlUl
	addql #8,sp
	lea sp@(32),a0
	movel _TimerBase,a6
#APP
	# ULONG ReadEClock(struct EClockVal* dest)
	jsr -60(a6)
	
#NO_APP
	movel sp@(32),d1
	movel sp@(36),d2
	movel sp@(40),d3
	movel sp@(44),d4
	movel d1,d5
	movel d2,d6
	subl d4,d6
	subxl d3,d5
	movel d6,sp@-
	movel d5,sp@-
	movel d0,sp@-
	movel d2,sp@-
	movel d1,sp@-
	movel sp@(56),sp@-
	movel sp@(56),sp@-
	movel a2,sp@-
	movel d4,sp@-
	movel d3,sp@-
	movel sp@(84),sp@-
	movel sp@(84),sp@-
	pea LC0
	lea _printf,a2
	jbsr a2@
	addw #48,sp
	movel d7,sp@
	jbsr _elapsedFrac__CQ24Time10MilliClock
	movel d1,sp@-
	movel d0,sp@-
	pea LC1
	jbsr a2@
	clrl d0
	addw #16,sp
	moveml sp@+,#0x44fc
	addw #20,sp
	rts
.globl ___vt_15MainApplication
	.even
___vt_15MainApplication:
	.long 0
	.long ___tf15MainApplication
	.long __dfRTTI__11Application
	.long _run__15MainApplication
	.long __$_15MainApplication
	.skip 4
.comm ___ti15MainApplication,16
	.even
LC2:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC3:
	.ascii "15MainApplication\0"
	.even
.globl ___tf15MainApplication
___tf15MainApplication:
	movel a2,sp@-
	lea ___ti15MainApplication,a2
	tstl a2@
	jne L366
	jbsr ___tf11Application
	pea 1:w
	pea LC2
	pea LC3
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L366:
	movel a2,d0
	movel sp@+,a2
	rts
