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
	jbsr _init__8Graphicsv
	pea 14:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L297,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L296
	.even
L297:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L294
	.even
L296:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___14PixConvTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L293
	.even
L294:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L303,a5@(-36)
	movel sp,a5@(-32)
	jra L302
	.even
L303:
	jra L307
	.even
L302:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L305
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L305:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L307:
L300:
	jbsr ___terminate
	.even
L293:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L316
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L316:
	jbsr _done__8Graphicsv
	rts
	nop
	.even
.globl ___14PixConvTestApp
___14PixConvTestApp:
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
	movel #L322,a5@(-12)
	movel sp,a5@(-8)
L322:
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
	movel #L336,a5@(-60)
	movel sp,a5@(-56)
	movel a0,a5@(-100)
	jra L335
	.even
L336:
	jra L350
	.even
L335:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_14PixConvTestApp,a0@
	clrl a0@(6)
	clrl a0@(10)
	clrl sp@-
	pea 1024:w
	jbsr _alloc__3MemUlUl
	movel a5@(8),a1
	movel d0,a1@(6)
	clrl sp@-
	pea 1024:w
	jbsr _alloc__3MemUlUl
	movel a5@(8),a0
	movel d0,a0@(10)
	addw #16,sp
	movel a5@(-100),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L349
	.even
L350:
L333:
	movel a5@(-100),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L341,a5@(-84)
	movel sp,a5@(-80)
	jra L340
	.even
L341:
	jra L351
	.even
L340:
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
L351:
L338:
	jbsr ___terminate
	.even
L349:
	moveml a5@(-212),#0x5cfc
	fmovem a5@(-172),#0x3f
	unlk a5
	rts
	.even
.globl __$_14PixConvTestApp
__$_14PixConvTestApp:
	moveml #0x2030,sp@-
	movel sp@(16),a3
	movel sp@(20),d2
	movel #___vt_14PixConvTestApp,a3@
	movel a3@(10),sp@-
	lea _free__3MemPv,a2
	jbsr a2@
	movel a3@(6),sp@-
	jbsr a2@
	addql #8,sp
	movel #___vt_8Runnable,a3@
	btst #0,d2
	jeq L359
	movel a3,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L359:
	moveml sp@+,#0xc04
	rts
LC0:
	.ascii "Before\12\0"
LC1:
	.ascii "\12After\12\0"
	.even
.globl _run__14PixConvTestApp
_run__14PixConvTestApp:
	moveml #0x38,sp@-
	movel sp@(16),a2
#APP
	
/*************************************/

	move.l a2@(6), a0
	move.l #1144831, d0
	move.l #256, d1
	jsr _Mem_set32

/*************************************/


	
/*************************************/

	move.l a2@(10), a0
	move.l #-1430532899, d0
	move.l #256, d1
	jsr _Mem_set32

/*************************************/


#NO_APP
	pea LC0
	lea _printf,a4
	jbsr a4@
	pea 16:w
	pea 16:w
	clrl sp@-
	clrl sp@-
	movel a2@(6),sp@-
	movel a2,sp@-
	lea _printBuffer16__14PixConvTestAppPviiii,a3
	jbsr a3@
	pea 8:w
	pea 8:w
	pea 8:w
	pea 8:w
	movel a2@(10),sp@-
	movel a2@(6),sp@-
	jbsr _convSwap16
	addw #48,sp
	movel #LC1,sp@
	jbsr a4@
	pea 16:w
	pea 16:w
	clrl sp@-
	clrl sp@-
	movel a2@(6),sp@-
	movel a2,sp@-
	jbsr a3@
	clrl d0
	addw #28,sp
	moveml sp@+,#0x1c00
	rts
LC2:
	.ascii "%02X \0"
LC3:
	.ascii "\12\0"
	.even
.globl _printBuffer8__14PixConvTestAppPviiii
_printBuffer8__14PixConvTestAppPviiii:
	moveml #0x3e38,sp@-
	movel sp@(48),d4
	movel sp@(52),d6
	lsll #4,d4
	movel sp@(40),d0
	addl d4,d0
	movel d0,a3
	addl sp@(44),a3
	moveq #16,d4
	subl d6,d4
	movel sp@(56),d0
	subql #1,d0
	moveq #-1,d1
	cmpl d0,d1
	jeq L367
	lea _printf,a4
	.even
L368:
	movel d6,d3
	subql #1,d3
	movel d0,d5
	subql #1,d5
	moveq #-1,d0
	cmpl d3,d0
	jeq L370
	clrl d2
	movel d3,d0
	notl d0
	moveq #3,d1
	andl d1,d0
	jeq L371
	cmpl d0,d1
	jle L376
	moveq #2,d1
	cmpl d0,d1
	jle L377
	moveb a3@+,d2
	movel d2,sp@-
	pea LC2
	jbsr a4@
	addql #8,sp
	subql #1,d3
L377:
	moveb a3@+,d2
	movel d2,sp@-
	pea LC2
	jbsr a4@
	addql #8,sp
	subql #1,d3
L376:
	moveb a3@+,d2
	movel d2,sp@-
	pea LC2
	jbsr a4@
	addql #8,sp
	subql #1,d3
	moveq #-1,d0
	cmpl d3,d0
	jeq L370
	.even
L371:
	movel a3,a2
	moveb a2@+,d2
	movel d2,sp@-
	pea LC2
	jbsr a4@
	addql #8,sp
	moveb a2@,d2
	movel d2,sp@-
	lea a3@(2),a2
	pea LC2
	jbsr a4@
	addql #8,sp
	moveb a2@,d2
	movel d2,sp@-
	lea a3@(3),a2
	pea LC2
	jbsr a4@
	addql #8,sp
	moveb a2@,d2
	movel d2,sp@-
	addql #4,a3
	pea LC2
	jbsr a4@
	addql #8,sp
	subql #4,d3
	moveq #-1,d1
	cmpl d3,d1
	jne L371
L370:
	pea LC3
	jbsr a4@
	addl d4,a3
	addql #4,sp
	movel d5,d0
	moveq #-1,d1
	cmpl d0,d1
	jne L368
L367:
	moveml sp@+,#0x1c7c
	rts
LC4:
	.ascii "%04X \0"
	.even
.globl _printBuffer16__14PixConvTestAppPviiii
_printBuffer16__14PixConvTestAppPviiii:
	moveml #0x3e38,sp@-
	movel sp@(44),d3
	movel sp@(48),d1
	movel sp@(52),d5
	lsll #5,d1
	movel sp@(40),a0
	addl d1,a0
	lea a0@(d3:l:2),a3
	moveq #16,d1
	subl d5,d1
	movel sp@(56),d0
	subql #1,d0
	moveq #-1,d2
	cmpl d0,d2
	jeq L395
	lea _printf,a4
	movel d1,d6
	addl d6,d6
	.even
L396:
	movel d5,d3
	subql #1,d3
	movel d0,d4
	subql #1,d4
	moveq #-1,d0
	cmpl d3,d0
	jeq L398
	clrl d2
	movel d3,d0
	notl d0
	moveq #3,d1
	andl d1,d0
	jeq L399
	cmpl d0,d1
	jle L404
	moveq #2,d1
	cmpl d0,d1
	jle L405
	movew a3@+,d2
	movel d2,sp@-
	pea LC4
	jbsr a4@
	addql #8,sp
	subql #1,d3
L405:
	movew a3@+,d2
	movel d2,sp@-
	pea LC4
	jbsr a4@
	addql #8,sp
	subql #1,d3
L404:
	movew a3@+,d2
	movel d2,sp@-
	pea LC4
	jbsr a4@
	addql #8,sp
	subql #1,d3
	moveq #-1,d0
	cmpl d3,d0
	jeq L398
	.even
L399:
	movel a3,a2
	movew a2@+,d2
	movel d2,sp@-
	pea LC4
	jbsr a4@
	addql #8,sp
	movew a2@,d2
	movel d2,sp@-
	lea a3@(4),a2
	pea LC4
	jbsr a4@
	addql #8,sp
	movew a2@,d2
	movel d2,sp@-
	lea a3@(6),a2
	pea LC4
	jbsr a4@
	addql #8,sp
	movew a2@,d2
	movel d2,sp@-
	addql #8,a3
	pea LC4
	jbsr a4@
	addql #8,sp
	subql #4,d3
	moveq #-1,d1
	cmpl d3,d1
	jne L399
L398:
	pea LC3
	jbsr a4@
	addl d6,a3
	addql #4,sp
	movel d4,d0
	moveq #-1,d2
	cmpl d0,d2
	jne L396
L395:
	moveml sp@+,#0x1c7c
	rts
LC5:
	.ascii "%02X%02X%02X \0"
	.even
.globl _printBuffer24__14PixConvTestAppPviiii
_printBuffer24__14PixConvTestAppPviiii:
	moveml #0x3f3e,sp@-
	movel sp@(60),d6
	lsll #4,d6
	movel d6,d0
	addl sp@(56),d0
	moveq #3,d1
	mulsl d1,d0
	movel sp@(52),a5
	addl d0,a5
	moveq #16,d6
	subl sp@(64),d6
	mulsl d1,d6
	movel sp@(68),d0
	subql #1,d0
	moveq #-1,d1
	cmpl d0,d1
	jeq L423
	lea _printf,a6
	clrl d4
	.even
L424:
	movel sp@(64),d5
	subql #1,d5
	movel d0,d7
	subql #1,d7
	moveq #-1,d0
	cmpl d5,d0
	jeq L426
	clrl d3
	clrl d2
	movel a5,a2
	movel d5,d0
	notl d0
	moveq #3,d1
	andl d1,d0
	jeq L431
	cmpl d0,d1
	jle L432
	moveq #2,d1
	cmpl d0,d1
	jle L433
	moveb a5@(2),d3
	movel d3,sp@-
	moveb a5@(1),d4
	movel d4,sp@-
	moveb a5@,d2
	movel d2,sp@-
	pea LC5
	jbsr a6@
	movel a5,d0
	addql #3,d0
	movel d0,a2
	movel a2,a5
	addw #16,sp
	subql #1,d5
L433:
	moveb a2@(2),d3
	movel d3,sp@-
	moveb a2@(1),d4
	movel d4,sp@-
	moveb a2@,d2
	movel d2,sp@-
	pea LC5
	jbsr a6@
	addql #3,a2
	addql #3,a5
	addw #16,sp
	subql #1,d5
L432:
	moveb a2@(2),d3
	movel d3,sp@-
	moveb a2@(1),d4
	movel d4,sp@-
	moveb a2@,d2
	movel d2,sp@-
	pea LC5
	jbsr a6@
	addql #3,a2
	addql #3,a5
	addw #16,sp
	subql #1,d5
	moveq #-1,d0
	cmpl d5,d0
	jeq L426
L431:
	movel a2,a4
	movel a2,a3
	.even
L427:
	moveb a3@(2),d3
	movel d3,sp@-
	moveb a4@(1),d4
	movel d4,sp@-
	moveb a2@,d2
	movel d2,sp@-
	pea LC5
	jbsr a6@
	addw #16,sp
	moveb a3@(5),d3
	movel d3,sp@-
	moveb a4@(4),d4
	movel d4,sp@-
	moveb a2@(3),d2
	movel d2,sp@-
	pea LC5
	jbsr a6@
	addw #16,sp
	moveb a3@(8),d3
	movel d3,sp@-
	moveb a4@(7),d4
	movel d4,sp@-
	moveb a2@(6),d2
	movel d2,sp@-
	pea LC5
	jbsr a6@
	addw #16,sp
	moveb a3@(11),d3
	movel d3,sp@-
	moveb a4@(10),d4
	movel d4,sp@-
	moveb a2@(9),d2
	movel d2,sp@-
	pea LC5
	jbsr a6@
	addw #12,a2
	addw #12,a4
	addw #12,a3
	addw #12,a5
	addw #16,sp
	subql #4,d5
	moveq #-1,d1
	cmpl d5,d1
	jne L427
L426:
	pea LC3
	jbsr a6@
	addl d6,a5
	addql #4,sp
	movel d7,d0
	moveq #-1,d1
	cmpl d0,d1
	jne L424
L423:
	moveml sp@+,#0x7cfc
	rts
LC6:
	.ascii "%08X \0"
	.even
.globl _printBuffer32__14PixConvTestAppPviiii
_printBuffer32__14PixConvTestAppPviiii:
	moveml #0x3c38,sp@-
	movel sp@(40),d2
	movel sp@(44),d1
	movel sp@(48),d4
	lsll #6,d1
	movel sp@(36),a0
	addl d1,a0
	lea a0@(d2:l:4),a3
	moveq #16,d1
	subl d4,d1
	movel sp@(52),d0
	subql #1,d0
	moveq #-1,d2
	cmpl d0,d2
	jeq L451
	lea _printf,a4
	movel d1,d5
	lsll #2,d5
	.even
L452:
	movel d4,d2
	subql #1,d2
	movel d0,d3
	subql #1,d3
	moveq #-1,d0
	cmpl d2,d0
	jeq L454
	movel d2,d0
	notl d0
	moveq #3,d1
	andl d1,d0
	jeq L455
	cmpl d0,d1
	jle L460
	moveq #2,d1
	cmpl d0,d1
	jle L461
	movel a3@+,sp@-
	pea LC6
	jbsr a4@
	addql #8,sp
	subql #1,d2
L461:
	movel a3@+,sp@-
	pea LC6
	jbsr a4@
	addql #8,sp
	subql #1,d2
L460:
	movel a3@+,sp@-
	pea LC6
	jbsr a4@
	addql #8,sp
	subql #1,d2
	moveq #-1,d0
	cmpl d2,d0
	jeq L454
	.even
L455:
	movel a3,a2
	movel a2@+,sp@-
	pea LC6
	jbsr a4@
	addqw #4,sp
	movel a2@,sp@
	lea a3@(8),a2
	pea LC6
	jbsr a4@
	addqw #4,sp
	movel a2@,sp@
	lea a3@(12),a2
	pea LC6
	jbsr a4@
	addqw #4,sp
	movel a2@,sp@
	addw #16,a3
	pea LC6
	jbsr a4@
	addql #8,sp
	subql #4,d2
	moveq #-1,d1
	cmpl d2,d1
	jne L455
L454:
	pea LC3
	jbsr a4@
	addl d5,a3
	addql #4,sp
	movel d3,d0
	moveq #-1,d2
	cmpl d0,d2
	jne L452
L451:
	moveml sp@+,#0x1c3c
	rts
.globl ___vt_14PixConvTestApp
	.even
___vt_14PixConvTestApp:
	.long 0
	.long ___tf14PixConvTestApp
	.long __dfRTTI__11Application
	.long _run__14PixConvTestApp
	.long __$_14PixConvTestApp
	.skip 4
.comm ___ti14PixConvTestApp,16
	.even
LC7:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC8:
	.ascii "14PixConvTestApp\0"
	.even
.globl ___tf14PixConvTestApp
___tf14PixConvTestApp:
	movel a2,sp@-
	lea ___ti14PixConvTestApp,a2
	tstl a2@
	jne L478
	jbsr ___tf11Application
	pea 1:w
	pea LC7
	pea LC8
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L478:
	movel a2,d0
	movel sp@+,a2
	rts
