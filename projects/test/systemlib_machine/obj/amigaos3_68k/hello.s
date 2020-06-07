#NO_APP
.text
	.even
.globl _naiveSwap16__FPvPCvUl
_naiveSwap16__FPvPCvUl:
	moveml #0x2030,sp@-
	movel sp@(20),a3
	movel sp@(16),a2
	movel sp@(24),d1
	subql #1,d1
	moveq #-1,d0
	cmpl d1,d0
	jeq L433
	movel d1,d0
	notl d0
	moveq #3,d2
	andl d2,d0
	jeq L434
	cmpl d0,d2
	jle L441
	moveq #2,d2
	cmpl d0,d2
	jle L442
	movew a3@+,d0
#APP
	rol.w #8, d0
#NO_APP
	movew d0,a2@+
	subql #1,d1
L442:
	movew a3@+,d0
#APP
	rol.w #8, d0
#NO_APP
	movew d0,a2@+
	subql #1,d1
L441:
	movew a3@+,d0
#APP
	rol.w #8, d0
#NO_APP
	movew d0,a2@+
	subql #1,d1
	moveq #-1,d0
	cmpl d1,d0
	jeq L433
	.even
L434:
	movel a3,a1
	movew a1@+,d0
#APP
	rol.w #8, d0
#NO_APP
	movel a2,a0
	movew d0,a0@+
	movew a1@,d0
#APP
	rol.w #8, d0
#NO_APP
	movew d0,a0@
	movew a3@(4),d0
#APP
	rol.w #8, d0
#NO_APP
	movew d0,a2@(4)
	movew a3@(6),d0
	addql #8,a3
#APP
	rol.w #8, d0
#NO_APP
	movew d0,a2@(6)
	addql #8,a2
	subql #4,d1
	moveq #-1,d2
	cmpl d1,d2
	jne L434
L433:
	moveml sp@+,#0xc04
	rts
	.even
.globl _naiveSwap32__FPvPCvUl
_naiveSwap32__FPvPCvUl:
	moveml #0x2030,sp@-
	movel sp@(20),a3
	movel sp@(16),a2
	movel sp@(24),d1
	subql #1,d1
	moveq #-1,d0
	cmpl d1,d0
	jeq L460
	movel d1,d0
	notl d0
	moveq #3,d2
	andl d2,d0
	jeq L461
	cmpl d0,d2
	jle L468
	moveq #2,d2
	cmpl d0,d2
	jle L469
	movel a3@+,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d0,a2@+
	subql #1,d1
L469:
	movel a3@+,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d0,a2@+
	subql #1,d1
L468:
	movel a3@+,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d0,a2@+
	subql #1,d1
	moveq #-1,d0
	cmpl d1,d0
	jeq L460
	.even
L461:
	movel a3,a1
	movel a1@+,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel a2,a0
	movel d0,a0@+
	movel a1@,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d0,a0@
	movel a3@(8),d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d0,a2@(8)
	movel a3@(12),d0
	addw #16,a3
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d0,a2@(12)
	addw #16,a2
	subql #4,d1
	moveq #-1,d2
	cmpl d1,d2
	jne L461
L460:
	moveml sp@+,#0xc04
	rts
	.even
.globl _naiveSwap64__FPvPCvUl
_naiveSwap64__FPvPCvUl:
	moveml #0x3830,sp@-
	movel sp@(28),a3
	movel sp@(24),a2
	movel sp@(32),d4
	subql #1,d4
	moveq #-1,d0
	cmpl d4,d0
	jeq L487
	movel d4,d0
	notl d0
	moveq #3,d1
	andl d1,d0
	jeq L488
	cmpl d0,d1
	jle L501
	moveq #2,d1
	cmpl d0,d1
	jle L502
	movel a3@+,d2
	movel a3@+,d3
	movel d3,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d2,d1
#APP
	rol.w #8, d1
	swap d1
	rol.w #8, d1
#NO_APP
	movel d0,a2@+
	movel d1,a2@+
	subql #1,d4
L502:
	movel a3@+,d2
	movel a3@+,d3
	movel d3,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d2,d1
#APP
	rol.w #8, d1
	swap d1
	rol.w #8, d1
#NO_APP
	movel d0,a2@+
	movel d1,a2@+
	subql #1,d4
L501:
	movel a3@+,d2
	movel a3@+,d3
	movel d3,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d2,d1
#APP
	rol.w #8, d1
	swap d1
	rol.w #8, d1
#NO_APP
	movel d0,a2@+
	movel d1,a2@+
	subql #1,d4
	moveq #-1,d0
	cmpl d4,d0
	jeq L487
	.even
L488:
	movel a3,a1
	movel a1@+,d2
	movel a1@+,d3
	movel d3,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d2,d1
#APP
	rol.w #8, d1
	swap d1
	rol.w #8, d1
#NO_APP
	movel a2,a0
	movel d0,a0@+
	movel d1,a0@+
	movel a1@,d2
	movel a1@(4),d3
	movel d3,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d2,d1
#APP
	rol.w #8, d1
	swap d1
	rol.w #8, d1
#NO_APP
	movel d0,a0@
	movel d1,a0@(4)
	movel a3@(16),d2
	movel a3@(20),d3
	movel d3,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d2,d1
#APP
	rol.w #8, d1
	swap d1
	rol.w #8, d1
#NO_APP
	movel d0,a2@(16)
	movel d1,a2@(20)
	movel a3@(24),d2
	movel a3@(28),d3
	addw #32,a3
	movel d3,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d2,d1
#APP
	rol.w #8, d1
	swap d1
	rol.w #8, d1
#NO_APP
	movel d0,a2@(24)
	movel d1,a2@(28)
	addw #32,a2
	subql #4,d4
	moveq #-1,d1
	cmpl d4,d1
	jne L488
L487:
	moveml sp@+,#0xc1c
	rts
	.even
.globl _createInstance__11Application
_createInstance__11Application:
	link a5,#-56
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-56)
	pea 18:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L522,a5@(-12)
	movel sp,a5@(-8)
	jra L521
	.even
L522:
	jra L532
	.even
L521:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___10HelloWorld
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L518
	.even
L532:
L519:
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L528,a5@(-36)
	movel sp,a5@(-32)
	jra L527
	.even
L528:
	jra L533
	.even
L527:
	lea a5@(-48),a1
	movel a1,a0@
	moveq #1,d0
	jeq L530
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L530:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L533:
L525:
	jbsr ___terminate
	.even
L518:
	moveml a5@(-168),#0x5cfc
	fmovem a5@(-128),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L542
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L542:
	rts
	nop
LC0:
	.ascii "Created HelloWorld\12\0"
	.even
.globl ___10HelloWorld
___10HelloWorld:
	link a5,#-100
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-100)
	movel a5@(8),a0
	movel #___vt_8Runnable,a0@
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L548,a5@(-12)
	movel sp,a5@(-8)
L548:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_11Application,a0@
	movel d0,a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L562,a5@(-60)
	movel sp,a5@(-56)
	jra L561
	.even
L562:
	jra L576
	.even
L561:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_10HelloWorld,a0@
	pea a0@(6)
	jbsr ___Q24Time10MilliClock
	clrl sp@
	movel #33554432,sp@-
	jbsr _alloc__3MemUlUl
	movel a5@(8),a1
	movel d0,a1@(14)
	pea LC0
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #16,sp
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L575
	.even
L576:
L559:
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L567,a5@(-84)
	movel sp,a5@(-80)
	jra L566
	.even
L567:
	jra L577
	.even
L566:
	lea a5@(-96),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_8Runnable,a0@
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L577:
L564:
	jbsr ___terminate
	.even
L575:
	moveml a5@(-212),#0x5cfc
	fmovem a5@(-172),#0x3f
	unlk a5
	rts
LC1:
	.ascii "Destroyed HelloWorld\12\0"
	.even
.globl __$_10HelloWorld
__$_10HelloWorld:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel sp@(16),d2
	movel #___vt_10HelloWorld,a2@
	movel a2@(14),sp@-
	jbsr _free__3MemPv
	pea LC1
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #12,sp
	movel #___vt_8Runnable,a2@
	btst #0,d2
	jeq L585
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L585:
	movel sp@+,d2
	movel sp@+,a2
	rts
	.even
.globl _run__10HelloWorld
_run__10HelloWorld:
	movel d2,sp@-
	movel sp@(8),d2
	movel d2,sp@-
	jbsr _testProcessorClass__10HelloWorld
	movel d2,sp@-
	jbsr _testMemSwap__10HelloWorld
	clrl d0
	addql #8,sp
	movel sp@+,d2
	rts
LC2:
	.ascii "Testing ProcessorInfo\12\11System reports %lu available processors\12\0"
LC3:
	.ascii "\11Processor [%lu] : %s @ %g MHz\12\0"
	.even
.globl _testProcessorClass__10HelloWorld
_testProcessorClass__10HelloWorld:
	movel a2,sp@-
	movel d2,sp@-
	pea 1:w
	pea LC2
	jbsr _printf
	clrl d2
	addql #8,sp
	lea __Q211EXNGPrivate3CPU$cpuNames,a2
	.even
L590:
	moveq #1,d0
	cmpl d2,d0
	jls L591
	movel d2,sp@-
	jbsr _getCPUSpeed__Q211EXNGPrivate3CPUUl
	addql #4,sp
	movel d1,sp@-
	movel d0,sp@-
	jbsr _cpuType__Q211EXNGPrivate3CPU
	movel a2@(d0:l:4),sp@-
	movel d2,sp@-
	pea LC3
	jbsr _printf
	addw #20,sp
	addql #1,d2
	jra L590
	.even
L591:
	movel sp@+,d2
	movel sp@+,a2
	rts
LC4:
	.ascii "Testing %d-bit byteswap on %lu words (x4)\12\0"
LC5:
	.ascii "Took %.6f s (%.2f MB/s) [total bandwidth]\12\0"
LC6:
	.ascii "Testing Mem::swapX() routines\12\0"
LC7:
	.ascii "Testing naiveSwapX() routines\12\0"
	.even
.globl _testMemSwap__10HelloWorld
_testMemSwap__10HelloWorld:
	fmovem #0x4,sp@-
	moveml #0x3f3a,sp@-
	movel sp@(56),a3
	movel #LC4,d4
	movel #LC5,d6
	movel a3@(14),d2
	movel d2,d3
	addl #16777216,d3
	pea LC6
	lea _printf,a4
	jbsr a4@
	movel #8388608,d7
	movel d7,sp@-
	pea 16:w
	movel d4,sp@-
	jbsr a4@
	addql #6,a3
	movel a3,sp@-
	lea _set__Q24Time10MilliClock,a6
	jbsr a6@
	addw #20,sp
#APP
	
/*************************************/

	move.l d3, a0
	move.l d2, a1
	move.l d7, d0
	jsr _Mem_swap16

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l d3, a1
	move.l d7, d0
	jsr _Mem_swap16

/*************************************/


	
/*************************************/

	move.l d3, a0
	move.l d2, a1
	move.l d7, d0
	jsr _Mem_swap16

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l d3, a1
	move.l d7, d0
	jsr _Mem_swap16

/*************************************/


#NO_APP
	movel a3,sp@-
	movel #_elapsedFrac__CQ24Time10MilliClock,d5
	movel d5,a0
	jbsr a0@
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp0
	fmuld #0r0.001000000000000004,fp0
	fmoved #0r128.0000000000004,fp2
	fmovex fp2,fp1
	fdivx fp0,fp1
	fmoved fp1,sp@-
	fmoved fp0,sp@-
	movel d6,sp@-
	jbsr a4@
	moveq #64,d7
	swap d7
	movel d7,sp@-
	pea 32:w
	movel d4,sp@-
	jbsr a4@
	addw #32,sp
	movel a3,sp@
	jbsr a6@
	addql #4,sp
#APP
	
/*************************************/

	move.l d3, a0
	move.l d2, a1
	move.l d7, d0
	jsr _Mem_swap32

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l d3, a1
	move.l d7, d0
	jsr _Mem_swap32

/*************************************/


	
/*************************************/

	move.l d3, a0
	move.l d2, a1
	move.l d7, d0
	jsr _Mem_swap32

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l d3, a1
	move.l d7, d0
	jsr _Mem_swap32

/*************************************/


#NO_APP
	movel a3,sp@-
	movel d5,a0
	jbsr a0@
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp0
	fmuld #0r0.001000000000000004,fp0
	fmovex fp2,fp1
	fdivx fp0,fp1
	fmoved fp1,sp@-
	fmoved fp0,sp@-
	movel d6,sp@-
	jbsr a4@
	moveq #32,d7
	swap d7
	movel d7,sp@-
	pea 64:w
	movel d4,sp@-
	jbsr a4@
	addw #32,sp
	movel a3,sp@
	jbsr a6@
	addql #4,sp
#APP
	
/*************************************/

	move.l d3, a0
	move.l d2, a1
	move.l d7, d0
	jsr _Mem_swap64

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l d3, a1
	move.l d7, d0
	jsr _Mem_swap64

/*************************************/


	
/*************************************/

	move.l d3, a0
	move.l d2, a1
	move.l d7, d0
	jsr _Mem_swap64

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l d3, a1
	move.l d7, d0
	jsr _Mem_swap64

/*************************************/


#NO_APP
	movel a3,sp@-
	movel d5,a0
	jbsr a0@
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp0
	fmuld #0r0.001000000000000004,fp0
	fmovex fp2,fp1
	fdivx fp0,fp1
	fmoved fp1,sp@-
	fmoved fp0,sp@-
	movel d6,sp@-
	jbsr a4@
	pea LC7
	jbsr a4@
	addl #6291456,d7
	movel d7,sp@-
	pea 16:w
	movel d4,sp@-
	jbsr a4@
	addw #36,sp
	movel a3,sp@
	jbsr a6@
	movel d7,sp@-
	movel d2,sp@-
	movel d3,sp@-
	lea _naiveSwap16__FPvPCvUl,a2
	jbsr a2@
	movel d7,sp@-
	movel d3,sp@-
	movel d2,sp@-
	jbsr a2@
	movel d7,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #36,sp
	movel d7,sp@
	movel d3,sp@-
	movel d2,sp@-
	jbsr a2@
	movel a3,sp@-
	movel d5,a0
	jbsr a0@
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp0
	fmuld #0r0.001000000000000004,fp0
	fmovex fp2,fp1
	fdivx fp0,fp1
	fmoved fp1,sp@-
	fmoved fp0,sp@-
	movel d6,sp@-
	jbsr a4@
	moveq #64,d7
	swap d7
	addw #32,sp
	movel d7,sp@
	pea 32:w
	movel d4,sp@-
	jbsr a4@
	movel a3,sp@-
	jbsr a6@
	movel d7,sp@-
	movel d2,sp@-
	movel d3,sp@-
	lea _naiveSwap32__FPvPCvUl,a2
	jbsr a2@
	movel d7,sp@-
	movel d3,sp@-
	movel d2,sp@-
	jbsr a2@
	addw #36,sp
	movel d7,sp@
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	movel d7,sp@-
	movel d3,sp@-
	movel d2,sp@-
	jbsr a2@
	movel a3,sp@-
	movel d5,a0
	jbsr a0@
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp0
	fmuld #0r0.001000000000000004,fp0
	fmovex fp2,fp1
	fdivx fp0,fp1
	fmoved fp1,sp@-
	fmoved fp0,sp@-
	movel d6,sp@-
	jbsr a4@
	moveq #32,d7
	swap d7
	addw #44,sp
	movel d7,sp@
	pea 64:w
	movel d4,sp@-
	jbsr a4@
	movel a3,sp@-
	jbsr a6@
	movel d7,sp@-
	movel d2,sp@-
	movel d3,sp@-
	lea _naiveSwap64__FPvPCvUl,a2
	jbsr a2@
	movel d7,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #36,sp
	movel d7,sp@
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	movel d7,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	movel a3,sp@-
	movel d5,a0
	jbsr a0@
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp0
	fmuld #0r0.001000000000000004,fp0
	fdivx fp0,fp2
	fmoved fp2,sp@-
	fmoved fp0,sp@-
	movel d6,sp@-
	jbsr a4@
	addw #48,sp
	moveml sp@+,#0x5cfc
	fmovem sp@+,#0x20
	rts
LC8:
	.ascii "%08X -> %08X\12\0"
LC9:
	.ascii "%02X \0"
LC10:
	.ascii "\12\0"
	.even
.globl _testMachineClass__10HelloWorld
_testMachineClass__10HelloWorld:
	addw #-68,sp
	moveml #0x3e20,sp@-
	movel #19088743,sp@(56)
	movel #-1985229329,sp@(60)
	movel sp@(56),sp@(64)
	movel sp@(60),sp@(68)
	movel sp@(56),sp@(72)
	movel sp@(60),sp@(76)
	movel sp@(56),sp@(80)
	movel sp@(60),sp@(84)
	clrl sp@(24)
	clrl sp@(28)
	clrl sp@(32)
	clrl sp@(36)
	clrl sp@(40)
	clrl sp@(44)
	clrl sp@(48)
	clrl sp@(52)
	moveq #56,d6
	addl sp,d6
	movel #-1430532899,d2
	movel #LC8,d3
	movel #-573785174,sp@-
	movel d2,sp@-
	movel d3,sp@-
	lea _printf,a2
	jbsr a2@
	addqw #8,sp
	movel d2,sp@
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #12,sp
	movel d2,d0
#APP
	rol.l #4, d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #12,sp
	movel d2,d0
#APP
	rol.l #8, d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	moveq #12,d5
	addw #12,sp
	movel d2,d0
#APP
	rol.l d5, d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #12,sp
	movel d2,d0
#APP
	swap d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	moveq #20,d4
	addw #12,sp
	movel d2,d0
#APP
	rol.l d4, d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #12,sp
	movel d2,d0
#APP
	ror.l #8, d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #12,sp
	movel d2,d0
#APP
	ror.l #4, d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addqw #8,sp
	movel d2,sp@
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addqw #8,sp
	movel d2,sp@
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #12,sp
	movel d2,d0
#APP
	ror.l #4, d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #12,sp
	movel d2,d0
#APP
	ror.l #8, d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #12,sp
	movel d2,d0
#APP
	ror.l d5, d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #12,sp
	movel d2,d0
#APP
	swap d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #12,sp
	movel d2,d0
#APP
	ror.l d4, d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #12,sp
	movel d2,d0
#APP
	rol.l #8, d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addw #12,sp
	movel d2,d0
#APP
	rol.l #4, d0
#NO_APP
	movel d0,sp@-
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	addqw #8,sp
	movel d2,sp@
	movel d2,sp@-
	movel d3,sp@-
	jbsr a2@
	moveq #36,d5
	addl sp,d5
	addw #12,sp
#APP
	
/*************************************/

	move.l d5, a0
	move.l d6, a1
	move.l #16, d0
	jsr _Mem_swap16

/*************************************/


#NO_APP
	clrl d2
	movel d6,d3
	moveq #87,d4
	addl sp,d4
	movel d6,a2
	.even
L814:
	moveb a2@,d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(1),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(2),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(3),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(4),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(5),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(6),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(7),d2
	addql #8,a2
	addql #8,d3
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	cmpl d3,d4
	jcc L814
	pea LC10
	jbsr _printf
	addql #4,sp
	clrl d2
	movel d5,d3
	moveq #31,d4
	addl d5,d4
	movel d5,a2
	.even
L819:
	moveb a2@,d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(1),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(2),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(3),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(4),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(5),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(6),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(7),d2
	addql #8,a2
	addql #8,d3
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	cmpl d3,d4
	jcc L819
	pea LC10
	jbsr _printf
	moveq #28,d3
	addl sp,d3
	moveq #60,d2
	addl sp,d2
	addql #4,sp
#APP
	
/*************************************/

	move.l d3, a0
	move.l d2, a1
	move.l #8, d0
	jsr _Mem_swap32

/*************************************/


#NO_APP
	clrl d2
	movel d6,d3
	moveq #31,d4
	addl d6,d4
	movel d6,a2
	.even
L826:
	moveb a2@,d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(1),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(2),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(3),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(4),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(5),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(6),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(7),d2
	addql #8,a2
	addql #8,d3
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	cmpl d3,d4
	jcc L826
	pea LC10
	jbsr _printf
	addql #4,sp
	clrl d2
	movel d5,d3
	moveq #31,d4
	addl d5,d4
	movel d5,a2
	.even
L831:
	moveb a2@,d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(1),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(2),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(3),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(4),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(5),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(6),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(7),d2
	addql #8,a2
	addql #8,d3
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	cmpl d3,d4
	jcc L831
	pea LC10
	jbsr _printf
	moveq #28,d3
	addl sp,d3
	moveq #60,d2
	addl sp,d2
	addql #4,sp
#APP
	
/*************************************/

	move.l d3, a0
	move.l d2, a1
	move.l #4, d0
	jsr _Mem_swap64

/*************************************/


#NO_APP
	clrl d2
	moveq #31,d3
	addl d6,d3
	movel d6,a2
	.even
L838:
	moveb a2@,d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(1),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(2),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(3),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(4),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(5),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(6),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(7),d2
	addql #8,a2
	addql #8,d6
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	cmpl d6,d3
	jcc L838
	pea LC10
	jbsr _printf
	addql #4,sp
	clrl d2
	movel d5,d3
	moveq #31,d4
	addl d3,d4
	movel d3,a2
	.even
L843:
	moveb a2@,d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(1),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(2),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(3),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(4),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(5),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(6),d2
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	moveb a2@(7),d2
	addql #8,a2
	addql #8,d3
	movel d2,sp@-
	pea LC9
	jbsr _printf
	addql #8,sp
	cmpl d3,d4
	jcc L843
	pea LC10
	jbsr _printf
	addql #4,sp
	moveml sp@+,#0x47c
	addw #68,sp
	rts
LC11:
	.ascii "ds0: \0"
LC12:
	.ascii "ds1: \0"
LC13:
	.ascii "ds2: \0"
LC14:
	.ascii "Testing: ds0<ds1 \0"
LC15:
	.ascii "passed\0"
LC16:
	.ascii "failed\0"
LC17:
	.ascii "Testing: ds0<=ds1 \0"
LC18:
	.ascii "Testing: ds0==ds1 \0"
LC19:
	.ascii "Testing: ds1<ds2 \0"
LC20:
	.ascii "Testing: ds1<=ds2 \0"
LC21:
	.ascii "Testing: ds1==ds2 \0"
	.even
.globl _testDatestampClass__10HelloWorld
_testDatestampClass__10HelloWorld:
	link a5,#-24
	moveml #0x3838,sp@-
	movel a5@(8),d4
	lea a5@(-8),a4
	movel a4,sp@-
	jbsr _now__Q24Time9Datestamp
	addql #4,sp
	movel a5@(-4),d0
	andl #-134217728,d0
	moveq #-16,d3
	addl a5,d3
	clrl sp@-
	clrl sp@-
	clrl sp@-
	clrl sp@-
	moveq #27,d1
	lsrl d1,d0
	movel d0,sp@-
	moveq #15,d0
	andl a4@,d0
	movel d0,sp@-
	bfextu a4@(1){#3:#17},d1
	movel d1,sp@-
	movel d3,sp@-
	jbsr _set__Q24Time9DatestampUlUsUsUsUsUsUs
	addw #28,sp
	clrl sp@
	movel d3,sp@-
	jbsr _setTimeZoneOffset__Q24Time9Datestamps
	addql #8,sp
	movel a5@(-4),d0
	andl #-134217728,d0
	moveq #-24,d2
	addl a5,d2
	clrl sp@-
	clrl sp@-
	clrl sp@-
	pea 1:w
	moveq #27,d1
	lsrl d1,d0
	movel d0,sp@-
	moveq #15,d0
	andl a4@,d0
	movel d0,sp@-
	bfextu a4@(1){#3:#17},d1
	movel d1,sp@-
	movel d2,sp@-
	jbsr _set__Q24Time9DatestampUlUsUsUsUsUsUs
	addw #28,sp
	movel #-60,sp@
	movel d2,sp@-
	jbsr _setTimeZoneOffset__Q24Time9Datestamps
	addqw #4,sp
	movel #LC11,sp@
	lea _printf,a3
	jbsr a3@
	movel a4,sp@-
	movel d4,sp@-
	lea _printDatestamp__10HelloWorldRCQ24Time9Datestamp,a2
	jbsr a2@
	pea LC12
	jbsr a3@
	movel d3,sp@-
	movel d4,sp@-
	jbsr a2@
	pea LC13
	jbsr a3@
	movel d2,sp@-
	movel d4,sp@-
	jbsr a2@
	addw #32,sp
	movel #LC14,sp@
	jbsr a3@
	movel d3,sp@-
	movel a4,sp@-
	jbsr ___lt__CQ24Time9DatestampRCQ24Time9Datestamp
	addw #12,sp
	tstb d0
	jeq L956
	pea LC15
	jra L968
	.even
L956:
	pea LC16
L968:
	jbsr _puts
	movel #LC17,sp@
	jbsr _printf
	pea a5@(-16)
	pea a5@(-8)
	jbsr ___lt__CQ24Time9DatestampRCQ24Time9Datestamp
	addw #12,sp
	tstb d0
	jeq L958
	pea LC15
	jra L969
	.even
L958:
	pea LC16
L969:
	jbsr _puts
	movel #LC18,sp@
	jbsr _printf
	pea a5@(-16)
	pea a5@(-8)
	jbsr ___eq__CQ24Time9DatestampRCQ24Time9Datestamp
	addw #12,sp
	tstb d0
	jeq L960
	pea LC15
	jra L970
	.even
L960:
	pea LC16
L970:
	jbsr _puts
	movel #LC19,sp@
	jbsr _printf
	pea a5@(-24)
	pea a5@(-16)
	jbsr ___lt__CQ24Time9DatestampRCQ24Time9Datestamp
	addw #12,sp
	tstb d0
	jeq L962
	pea LC15
	jra L971
	.even
L962:
	pea LC16
L971:
	jbsr _puts
	movel #LC20,sp@
	jbsr _printf
	pea a5@(-24)
	pea a5@(-16)
	jbsr ___lt__CQ24Time9DatestampRCQ24Time9Datestamp
	addw #12,sp
	tstb d0
	jeq L964
	pea LC15
	jra L972
	.even
L964:
	pea LC16
L972:
	jbsr _puts
	movel #LC21,sp@
	jbsr _printf
	pea a5@(-24)
	pea a5@(-16)
	jbsr ___eq__CQ24Time9DatestampRCQ24Time9Datestamp
	addw #12,sp
	tstb d0
	jeq L966
	pea LC15
	jra L973
	.even
L966:
	pea LC16
L973:
	jbsr _puts
	addql #4,sp
	moveml a5@(-48),#0x1c1c
	unlk a5
	rts
LC22:
	.ascii "%04ld-%02ld-%02ld %02ld:%02ld:%02ld.%03ld%+ld:%02ld\12\0"
	.even
.globl _printDatestamp__10HelloWorldRCQ24Time9Datestamp
_printDatestamp__10HelloWorldRCQ24Time9Datestamp:
	movel d2,sp@-
	movel sp@(12),a0
	movel a0@,d0
	andl #-2097152,d0
	moveq #21,d1
	asrl d1,d0
	moveq #60,d2
	divsll d2,d1:d0
	movel d1,sp@-
	movel a0@,d0
	andl #-2097152,d0
	moveq #21,d1
	asrl d1,d0
	divsl d2,d0
	movel d0,sp@-
	movel a0@(4),d2
	andl #1023,d2
	movel d2,sp@-
	bfextu a0@(6){#0:#6},d0
	movel d0,sp@-
	movew a0@(4),d1
	moveq #63,d2
	andl d2,d1
	movel d1,sp@-
	bfextu a0@(4){#5:#5},d0
	movel d0,sp@-
	movel a0@(4),d0
	andl #-134217728,d0
	moveq #27,d1
	lsrl d1,d0
	movel d0,sp@-
	moveq #15,d2
	andl a0@,d2
	movel d2,sp@-
	bfextu a0@(1){#3:#17},d0
	movel d0,sp@-
	pea LC22
	jbsr _printf
	addw #40,sp
	movel sp@+,d2
	rts
.globl ___vt_10HelloWorld
	.even
___vt_10HelloWorld:
	.long 0
	.long ___tf10HelloWorld
	.long __dfRTTI__11Application
	.long _run__10HelloWorld
	.long __$_10HelloWorld
	.skip 4
.comm ___ti10HelloWorld,16
	.even
LC23:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC24:
	.ascii "10HelloWorld\0"
	.even
.globl ___tf10HelloWorld
___tf10HelloWorld:
	movel a2,sp@-
	lea ___ti10HelloWorld,a2
	tstl a2@
	jne L985
	jbsr ___tf11Application
	pea 1:w
	pea LC23
	pea LC24
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L985:
	movel #___ti10HelloWorld,d0
	movel sp@+,a2
	rts
