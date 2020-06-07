#NO_APP
.text
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
	movel #L435,a5@(-12)
	movel sp,a5@(-8)
	jra L434
	.even
L435:
	jra L445
	.even
L434:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___22MachineTestApplication
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L431
	.even
L445:
L432:
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L441,a5@(-36)
	movel sp,a5@(-32)
	jra L440
	.even
L441:
	jra L446
	.even
L440:
	lea a5@(-48),a1
	movel a1,a0@
	moveq #1,d0
	jeq L443
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L443:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L446:
L438:
	jbsr ___terminate
	.even
L431:
	moveml a5@(-168),#0x5cfc
	fmovem a5@(-128),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L455
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L455:
	rts
	nop
LC0:
	.ascii "Created MachineTestApplication\12\0"
	.even
.globl ___22MachineTestApplication
___22MachineTestApplication:
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
	movel #L461,a5@(-12)
	movel sp,a5@(-8)
L461:
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
	movel #L475,a5@(-60)
	movel sp,a5@(-56)
	jra L474
	.even
L475:
	jra L489
	.even
L474:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_22MachineTestApplication,a0@
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
	jra L488
	.even
L489:
L472:
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L480,a5@(-84)
	movel sp,a5@(-80)
	jra L479
	.even
L480:
	jra L490
	.even
L479:
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
L490:
L477:
	jbsr ___terminate
	.even
L488:
	moveml a5@(-212),#0x5cfc
	fmovem a5@(-172),#0x3f
	unlk a5
	rts
LC1:
	.ascii "Destroyed MachineTestApplication\12\0"
	.even
.globl __$_22MachineTestApplication
__$_22MachineTestApplication:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel sp@(16),d2
	movel #___vt_22MachineTestApplication,a2@
	movel a2@(14),sp@-
	jbsr _free__3MemPv
	pea LC1
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #12,sp
	movel #___vt_8Runnable,a2@
	btst #0,d2
	jeq L498
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L498:
	movel sp@+,d2
	movel sp@+,a2
	rts
LC2:
	.ascii "Usage: %s [-cpu] [-bit] [-set] [-swap]\12-cpu : report processor information\12-bit : verify bit operations\12-set : benchmark memory setting throughput\12-swap: benchmark memory swapping throughput\12\0"
LC3:
	.ascii "-cpu\0"
LC4:
	.ascii "-bit\0"
LC5:
	.ascii "-set\0"
LC6:
	.ascii "-swap\0"
	.even
.globl _run__22MachineTestApplication
_run__22MachineTestApplication:
	movel d2,sp@-
	movel sp@(8),d2
	moveq #1,d0
	cmpl __7Startup$numArgs,d0
	jlt L500
	clrl sp@-
	jbsr _getArg__7StartupUl
	movel d0,sp@
	pea LC2
	jbsr _printf
	addql #8,sp
L500:
	pea 1:w
	pea LC3
	jbsr _getArgSwitch__7StartupPCcUs
	addql #8,sp
	tstb d0
	jeq L504
	movel d2,sp@-
	jbsr _testProcessorInfo__22MachineTestApplication
	addql #4,sp
L504:
	pea 1:w
	pea LC4
	jbsr _getArgSwitch__7StartupPCcUs
	addql #8,sp
	tstb d0
	jeq L506
	movel d2,sp@-
	jbsr _testMachineBitOps__22MachineTestApplication
	addql #4,sp
L506:
	pea 1:w
	pea LC5
	jbsr _getArgSwitch__7StartupPCcUs
	addql #8,sp
	tstb d0
	jeq L508
	movel d2,sp@-
	jbsr _testMemoryBlockSet__22MachineTestApplication
	addql #4,sp
L508:
	pea 1:w
	pea LC6
	jbsr _getArgSwitch__7StartupPCcUs
	addql #8,sp
	tstb d0
	jeq L510
	movel d2,sp@-
	jbsr _testMemoryBlockSwap__22MachineTestApplication
	addql #4,sp
L510:
	clrl d0
	movel sp@+,d2
	rts
LC7:
	.ascii "Testing ProcessorInfo\12\11System reports %lu available processors\12\0"
LC8:
	.ascii "\11Processor [%lu] : %s @ %g MHz\12\0"
	.even
.globl _testProcessorInfo__22MachineTestApplication
_testProcessorInfo__22MachineTestApplication:
	movel a2,sp@-
	movel d2,sp@-
	pea 1:w
	pea LC7
	jbsr _printf
	clrl d2
	addql #8,sp
	lea __Q211EXNGPrivate3CPU$cpuNames,a2
	.even
L515:
	moveq #1,d0
	cmpl d2,d0
	jls L516
	movel d2,sp@-
	jbsr _getCPUSpeed__Q211EXNGPrivate3CPUUl
	addql #4,sp
	movel d1,sp@-
	movel d0,sp@-
	jbsr _cpuType__Q211EXNGPrivate3CPU
	movel a2@(d0:l:4),sp@-
	movel d2,sp@-
	pea LC8
	jbsr _printf
	addw #20,sp
	addql #1,d2
	jra L515
	.even
L516:
	movel sp@+,d2
	movel sp@+,a2
	rts
LC9:
	.ascii "Testing %d-bit set on %lu words (x4)\12\0"
LC10:
	.ascii "Took %.6f s (%.2f MB/s) [total bandwidth]\12\12\0"
LC11:
	.ascii "Testing Mem::setX() routines\12\0"
	.even
.globl _testMemoryBlockSet__22MachineTestApplication
_testMemoryBlockSet__22MachineTestApplication:
	addw #-36,sp
	fmovem #0x4,sp@-
	moveml #0x3e3a,sp@-
	movel sp@(88),a3
	movel #LC9,d4
	movel #LC10,d5
	pea LC11
	lea _printf,a2
	jbsr a2@
	movel #33554432,d6
	movel d6,sp@-
	pea 8:w
	movel d4,sp@-
	jbsr a2@
	movel a3,d3
	addql #6,d3
	movel d3,sp@-
	lea _set__Q24Time10MilliClock,a4
	jbsr a4@
	movel a3@(14),d2
	addw #20,sp
#APP
	
/*************************************/

	move.l d2, a0
	move.l #255, d0
	move.l d6, d1
	jsr _Mem_set

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l #0, d0
	move.l d6, d1
	jsr _Mem_set

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l #255, d0
	move.l d6, d1
	jsr _Mem_set

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l #0, d0
	move.l d6, d1
	jsr _Mem_set

/*************************************/


#NO_APP
	movel d3,sp@-
	lea _elapsedFrac__CQ24Time10MilliClock,a6
	jbsr a6@
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp0
	fmuld #0r0.001000000000000004,fp0
	fmoved #0r128.0000000000004,fp2
	fmovex fp2,fp1
	fdivx fp0,fp1
	fmoved fp1,sp@-
	fmoved fp0,sp@-
	movel d5,sp@-
	jbsr a2@
	movel #16777216,d6
	movel d6,sp@-
	pea 16:w
	movel d4,sp@-
	jbsr a2@
	addw #32,sp
	movel d3,sp@
	jbsr a4@
	movel a3@(14),d2
	addql #4,sp
#APP
	
/*************************************/

	move.l d2, a0
	move.l #4991, d0
	move.l d6, d1
	jsr _Mem_set16

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l #63281, d0
	move.l d6, d1
	jsr _Mem_set16

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l #4991, d0
	move.l d6, d1
	jsr _Mem_set16

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l #63281, d0
	move.l d6, d1
	jsr _Mem_set16

/*************************************/


#NO_APP
	movel d3,sp@-
	jbsr a6@
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp0
	fmuld #0r0.001000000000000004,fp0
	fmovex fp2,fp1
	fdivx fp0,fp1
	fmoved fp1,sp@-
	fmoved fp0,sp@-
	movel d5,sp@-
	jbsr a2@
	movel #8388608,d6
	movel d6,sp@-
	pea 32:w
	movel d4,sp@-
	jbsr a2@
	addw #32,sp
	movel d3,sp@
	jbsr a4@
	movel a3@(14),d2
	addql #4,sp
#APP
	
/*************************************/

	move.l d2, a0
	move.l #-147781426, d0
	move.l d6, d1
	jsr _Mem_set32

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l #147781425, d0
	move.l d6, d1
	jsr _Mem_set32

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l #-147781426, d0
	move.l d6, d1
	jsr _Mem_set32

/*************************************/


	
/*************************************/

	move.l d2, a0
	move.l #147781425, d0
	move.l d6, d1
	jsr _Mem_set32

/*************************************/


#NO_APP
	movel d3,sp@-
	jbsr a6@
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp0
	fmuld #0r0.001000000000000004,fp0
	fmovex fp2,fp1
	fdivx fp0,fp1
	fmoved fp1,sp@-
	fmoved fp0,sp@-
	movel d5,sp@-
	jbsr a2@
	moveq #64,d6
	swap d6
	movel d6,sp@-
	pea 64:w
	movel d4,sp@-
	jbsr a2@
	addw #32,sp
	movel d3,sp@
	jbsr a4@
	movel #1122867,sp@(76)
	movel #1146447479,sp@(80)
	moveq #76,d2
	addl sp,d2
	addql #4,sp
#APP
	
/*************************************/

	move.l a3@(14), a0
	move.l d2, a1
	move.l d6, d0
	jsr _Mem_set64

/*************************************/


#NO_APP
	movel #2003195204,sp@(64)
	movel #857870592,sp@(68)
	moveq #64,d2
	addl sp,d2
#APP
	
/*************************************/

	move.l a3@(14), a0
	move.l d2, a1
	move.l d6, d0
	jsr _Mem_set64

/*************************************/


#NO_APP
	movel #1122867,sp@(56)
	movel #1146447479,sp@(60)
	moveq #56,d2
	addl sp,d2
#APP
	
/*************************************/

	move.l a3@(14), a0
	move.l d2, a1
	move.l d6, d0
	jsr _Mem_set64

/*************************************/


#NO_APP
	movel #2003195204,sp@(48)
	movel #857870592,sp@(52)
	moveq #48,d2
	addl sp,d2
#APP
	
/*************************************/

	move.l a3@(14), a0
	move.l d2, a1
	move.l d6, d0
	jsr _Mem_set64

/*************************************/


#NO_APP
	movel d3,sp@-
	jbsr a6@
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp0
	fmuld #0r0.001000000000000004,fp0
	fdivx fp0,fp2
	fmoved fp2,sp@-
	fmoved fp0,sp@-
	movel d5,sp@-
	jbsr a2@
	addw #24,sp
	moveml sp@+,#0x5c7c
	fmovem sp@+,#0x20
	addw #36,sp
	rts
LC12:
	.ascii "Testing %d-bit byteswap on %lu words (x4)\12\0"
LC13:
	.ascii "Testing Mem::swapX() routines\12\0"
LC14:
	.ascii "Testing naiveSwapX() routines\12\0"
	.even
.globl _testMemoryBlockSwap__22MachineTestApplication
_testMemoryBlockSwap__22MachineTestApplication:
	fmovem #0x4,sp@-
	moveml #0x3f3a,sp@-
	movel sp@(56),a3
	movel #LC12,d4
	movel #LC10,d6
	movel a3@(14),d2
	movel d2,d3
	addl #16777216,d3
	pea LC13
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
	pea LC14
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
LC15:
	.ascii "%10s #%2d %08X -> %08X\12\0"
LC16:
	.ascii "%10s #%2d %04X -> %04X\12\0"
LC17:
	.ascii "%10s #%2d %02X -> %02X\12\0"
LC18:
	.ascii "Testing Machine rotate/swap routines with constant literal size\12\0"
LC19:
	.ascii "rol8\0"
LC20:
	.ascii "ror8\0"
LC21:
	.ascii "swap\0"
LC22:
	.ascii "rol16\0"
LC23:
	.ascii "ror16\0"
LC24:
	.ascii "rol32\0"
LC25:
	.ascii "ror32\0"
LC26:
	.ascii "Testing Machine rotate routines with variable size\12\0"
LC27:
	.ascii "Testing Machine MSB\12\0"
LC28:
	.ascii "MSB: %08X -> %u\12\0"
	.even
.globl _testMachineBitOps__22MachineTestApplication
_testMachineBitOps__22MachineTestApplication:
	subqw #8,sp
	moveml #0x3f30,sp@-
	movel #LC15,d3
	movel #LC16,d7
	lea LC17,a3
	movel #-1430532899,d4
	movew #43981,d6
	moveb #240,d5
	pea LC18
	jbsr _printf
	addql #4,sp
	moveq #15,d0
	notb d0
	andl d5,d0
	movel d0,sp@-
	moveq #15,d1
	notb d1
	andl d5,d1
	movel d1,sp@-
	clrl sp@-
	pea LC19
	movel a3,sp@-
	jbsr _printf
	addw #20,sp
	moveb d5,d0
#APP
	rol.b #2, d0
#NO_APP
	clrl sp@-
	moveb d0,sp@(3)
	moveq #15,d0
	notb d0
	andl d5,d0
	movel d0,sp@-
	pea 2:w
	pea LC19
	movel a3,sp@-
	jbsr _printf
	addw #20,sp
	moveb d5,d0
#APP
	rol.b #4, d0
#NO_APP
	clrl sp@-
	moveb d0,sp@(3)
	moveq #15,d1
	notb d1
	andl d5,d1
	movel d1,sp@-
	pea 4:w
	pea LC19
	movel a3,sp@-
	jbsr _printf
	addw #20,sp
	moveb d5,d0
#APP
	rol.b #6, d0
#NO_APP
	clrl sp@-
	moveb d0,sp@(3)
	moveq #15,d0
	notb d0
	andl d5,d0
	movel d0,sp@-
	pea 6:w
	pea LC19
	movel a3,sp@-
	jbsr _printf
	addw #20,sp
	moveq #15,d1
	notb d1
	andl d5,d1
	movel d1,sp@-
	moveq #15,d0
	notb d0
	andl d5,d0
	movel d0,sp@-
	pea 8:w
	pea LC19
	movel a3,sp@-
	jbsr _printf
	addw #20,sp
	moveq #15,d1
	notb d1
	andl d5,d1
	movel d1,sp@-
	moveq #15,d0
	notb d0
	andl d5,d0
	movel d0,sp@-
	clrl sp@-
	pea LC20
	movel a3,sp@-
	jbsr _printf
	addw #20,sp
	moveb d5,d0
#APP
	ror.b #2, d0
#NO_APP
	clrl sp@-
	moveb d0,sp@(3)
	moveq #15,d1
	notb d1
	andl d5,d1
	movel d1,sp@-
	pea 2:w
	pea LC20
	movel a3,sp@-
	jbsr _printf
	addw #20,sp
	moveb d5,d0
#APP
	ror.b #4, d0
#NO_APP
	clrl sp@-
	moveb d0,sp@(3)
	moveq #15,d0
	notb d0
	andl d5,d0
	movel d0,sp@-
	pea 4:w
	pea LC20
	movel a3,sp@-
	jbsr _printf
	addw #20,sp
	moveb d5,d0
#APP
	ror.b #6, d0
#NO_APP
	clrl sp@-
	moveb d0,sp@(3)
	moveq #15,d1
	notb d1
	andl d5,d1
	movel d1,sp@-
	pea 6:w
	pea LC20
	movel a3,sp@-
	jbsr _printf
	addw #20,sp
	moveq #15,d0
	notb d0
	andl d5,d0
	movel d0,sp@-
	moveq #15,d1
	notb d1
	andl d5,d1
	movel d1,sp@-
	pea 8:w
	pea LC20
	movel a3,sp@-
	jbsr _printf
	addw #20,sp
	movew d6,d0
#APP
	rol.w #8, d0
#NO_APP
	movew d0,sp@-
	clrw sp@-
	movel d6,d0
	andl #43981,d0
	movel d0,sp@-
	pea 16:w
	pea LC21
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
	movel d6,d1
	andl #43981,d1
	movel d1,sp@-
	movel d6,d0
	andl #43981,d0
	movel d0,sp@-
	clrl sp@-
	pea LC22
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
	movew d6,d0
#APP
	rol.w #4, d0
#NO_APP
	movew d0,sp@-
	clrw sp@-
	movel d6,d1
	andl #43981,d1
	movel d1,sp@-
	pea 4:w
	pea LC22
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
	movew d6,d0
#APP
	rol.w #8, d0
#NO_APP
	movew d0,sp@-
	clrw sp@-
	movel d6,d0
	andl #43981,d0
	movel d0,sp@-
	pea 8:w
	pea LC22
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
	movew d6,d0
#APP
	ror.w #4, d0
#NO_APP
	movew d0,sp@-
	clrw sp@-
	movel d6,d1
	andl #43981,d1
	movel d1,sp@-
	pea 12:w
	pea LC22
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
	movel d6,d0
	andl #43981,d0
	movel d0,sp@-
	movel d6,d2
	andl #43981,d2
	movel d2,sp@-
	pea 16:w
	pea LC22
	movel d7,sp@-
	jbsr _printf
	addw #16,sp
	movel d2,sp@
	movel d6,d2
	andl #43981,d2
	movel d2,sp@-
	clrl sp@-
	pea LC23
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
#APP
	ror.w #4, d2
#NO_APP
	movew d2,sp@-
	clrw sp@-
	movel d6,d2
	andl #43981,d2
	movel d2,sp@-
	pea 4:w
	pea LC23
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
#APP
	ror.w #8, d2
#NO_APP
	movew d2,sp@-
	clrw sp@-
	movel d6,d2
	andl #43981,d2
	movel d2,sp@-
	pea 8:w
	pea LC23
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
#APP
	rol.w #4, d2
#NO_APP
	movew d2,sp@-
	clrw sp@-
	movel d6,d2
	andl #43981,d2
	movel d2,sp@-
	pea 12:w
	pea LC23
	movel d7,sp@-
	jbsr _printf
	addw #16,sp
	movel d2,sp@
	movel d6,d1
	andl #43981,d1
	movel d1,sp@-
	pea 16:w
	pea LC23
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
	movel d4,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0
#NO_APP
	movel d0,sp@-
	movel d4,sp@-
	pea 32:w
	pea LC21
	movel d3,sp@-
	jbsr _printf
	addw #16,sp
	movel d4,sp@
	movel d4,sp@-
	clrl sp@-
	pea LC24
	movel d3,sp@-
	jbsr _printf
	addw #20,sp
	movel d4,d0
#APP
	rol.l #4, d0
#NO_APP
	movel d0,sp@-
	movel d4,sp@-
	pea 4:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	addw #20,sp
	movel d4,d0
#APP
	rol.l #8, d0
#NO_APP
	movel d0,sp@-
	movel d4,sp@-
	pea 8:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	moveq #12,d0
	addw #20,sp
	movel d4,d1
#APP
	rol.l d0, d1
#NO_APP
	movel d1,d0
	movel d0,sp@-
	movel d4,sp@-
	pea 12:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	addw #20,sp
	movel d4,d0
#APP
	swap d0
#NO_APP
	movel d0,sp@-
	movel d4,sp@-
	pea 16:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	moveq #20,d0
	addw #20,sp
	movel d4,d1
#APP
	rol.l d0, d1
#NO_APP
	movel d1,d0
	movel d0,sp@-
	movel d4,sp@-
	pea 20:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	addw #20,sp
	movel d4,d0
#APP
	ror.l #8, d0
#NO_APP
	movel d0,sp@-
	movel d4,sp@-
	pea 24:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	addw #20,sp
	movel d4,d0
#APP
	ror.l #4, d0
#NO_APP
	movel d0,sp@-
	movel d4,sp@-
	pea 28:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	addw #16,sp
	movel d4,sp@
	movel d4,sp@-
	pea 32:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	addw #16,sp
	movel d4,sp@
	movel d4,sp@-
	clrl sp@-
	pea LC25
	movel d3,sp@-
	jbsr _printf
	addw #20,sp
	movel d4,d0
#APP
	ror.l #4, d0
#NO_APP
	movel d0,sp@-
	movel d4,sp@-
	pea 4:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	addw #20,sp
	movel d4,d0
#APP
	ror.l #8, d0
#NO_APP
	movel d0,sp@-
	movel d4,sp@-
	pea 8:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	moveq #12,d0
	addw #20,sp
	movel d4,d1
#APP
	ror.l d0, d1
#NO_APP
	movel d1,d0
	movel d0,sp@-
	movel d4,sp@-
	pea 12:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	addw #20,sp
	movel d4,d0
#APP
	swap d0
#NO_APP
	movel d0,sp@-
	movel d4,sp@-
	pea 16:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	moveq #20,d0
	addw #20,sp
	movel d4,d1
#APP
	ror.l d0, d1
#NO_APP
	movel d1,d0
	movel d0,sp@-
	movel d4,sp@-
	pea 20:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	addw #20,sp
	movel d4,d0
#APP
	rol.l #8, d0
#NO_APP
	movel d0,sp@-
	movel d4,sp@-
	pea 24:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	addw #20,sp
	movel d4,d0
#APP
	rol.l #4, d0
#NO_APP
	movel d0,sp@-
	movel d4,sp@-
	pea 28:w
	pea LC24
	movel d3,sp@-
	jbsr _printf
	addw #16,sp
	movel d4,sp@
	movel d4,sp@-
	pea 32:w
	pea LC24
	movel d3,sp@-
	lea _printf,a2
	jbsr a2@
	pea LC26
	jbsr a2@
	clrl sp@(56)
	addw #24,sp
	movel sp@(32),d0
	moveq #8,d1
	cmpl d0,d1
	jlt L890
	clrl d3
	clrl d2
	.even
L892:
	movel sp@(32),d0
	moveb d5,d1
#APP
	rol.b d0, d1
#NO_APP
	moveb d1,d0
	moveb d0,d3
	moveb d3,d2
	movel d2,sp@-
	moveq #15,d0
	notb d0
	andl d5,d0
	movel d0,sp@-
	movel sp@(40),sp@-
	pea LC19
	movel a3,sp@-
	jbsr _printf
	addw #20,sp
	movel sp@(32),d0
	addql #2,d0
	movel d0,sp@(32)
	movel sp@(32),d0
	moveq #8,d1
	cmpl d0,d1
	jge L892
L890:
	clrl sp@(32)
	movel sp@(32),d0
	moveq #8,d1
	cmpl d0,d1
	jlt L900
	clrl d3
	clrl d2
	.even
L902:
	movel sp@(32),d0
	moveb d5,d1
#APP
	ror.b d0, d1
#NO_APP
	moveb d1,d0
	moveb d0,d3
	moveb d3,d2
	movel d2,sp@-
	moveq #15,d0
	notb d0
	andl d5,d0
	movel d0,sp@-
	movel sp@(40),sp@-
	pea LC20
	movel a3,sp@-
	jbsr _printf
	addw #20,sp
	movel sp@(32),d0
	addql #2,d0
	movel d0,sp@(32)
	movel sp@(32),d0
	moveq #8,d1
	cmpl d0,d1
	jge L902
L900:
	clrl sp@(32)
	movel sp@(32),d0
	moveq #16,d1
	cmpl d0,d1
	jlt L910
	clrl d3
	clrl d2
	.even
L912:
	movel sp@(32),d0
	movew d6,d1
#APP
	rol.w d0, d1
#NO_APP
	movew d1,d0
	movew d0,d3
	movew d3,d2
	movel d2,sp@-
	movel d6,d0
	andl #43981,d0
	movel d0,sp@-
	movel sp@(40),sp@-
	pea LC22
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
	movel sp@(32),d0
	addql #4,d0
	movel d0,sp@(32)
	movel sp@(32),d0
	moveq #16,d1
	cmpl d0,d1
	jge L912
L910:
	clrl sp@(32)
	movel sp@(32),d0
	moveq #16,d1
	cmpl d0,d1
	jlt L922
	clrl d3
	clrl d2
	.even
L924:
	movel sp@(32),d0
	movew d6,d3
	movel d3,d1
#APP
	ror.w d0, d1
#NO_APP
	movel d1,d0
	movew d0,d2
	movel d2,sp@-
	movel d6,d0
	andl #43981,d0
	movel d0,sp@-
	movel sp@(40),sp@-
	pea LC23
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
	movel sp@(32),d0
	addql #4,d0
	movel d0,sp@(32)
	movel sp@(32),d0
	moveq #16,d1
	cmpl d0,d1
	jge L924
L922:
	clrl sp@(32)
	jra L969
	.even
L936:
	movel sp@(32),d0
	movel d4,d1
#APP
	rol.l d0, d1
#NO_APP
	movel d1,d0
	movel d0,sp@-
	movel d4,sp@-
	movel sp@(40),sp@-
	pea LC24
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
	movel sp@(32),d0
	addql #4,d0
	movel d0,sp@(32)
L969:
	movel sp@(32),d0
	moveq #32,d1
	cmpl d0,d1
	jge L936
	clrl sp@(32)
	jra L970
	.even
L951:
	movel sp@(32),d0
	movel d4,d1
#APP
	ror.l d0, d1
#NO_APP
	movel d1,d0
	movel d0,sp@-
	movel d4,sp@-
	movel sp@(40),sp@-
	pea LC25
	movel d7,sp@-
	jbsr _printf
	addw #20,sp
	movel sp@(32),d0
	addql #4,d0
	movel d0,sp@(32)
L970:
	movel sp@(32),d0
	moveq #32,d1
	cmpl d0,d1
	jge L951
	pea LC27
	jbsr _printf
	moveq #1,d2
	addql #4,sp
	moveq #1,d3
	.even
L966:
	movel d3,d0
	lsll d2,d0
	movel d0,d4
	subql #1,d4
	movel d4,d0
#APP
	bfffo d0 {#0:#32}, d0
	neg.w d0
	add.w #31,d0
#NO_APP
	movel d0,sp@-
	movel d4,sp@-
	pea LC28
	jbsr _printf
	addw #12,sp
	addql #1,d2
	moveq #32,d0
	cmpl d2,d0
	jcc L966
	moveml sp@+,#0xcfc
	addqw #8,sp
	rts
.globl ___vt_22MachineTestApplication
	.even
___vt_22MachineTestApplication:
	.long 0
	.long ___tf22MachineTestApplication
	.long __dfRTTI__11Application
	.long _run__22MachineTestApplication
	.long __$_22MachineTestApplication
	.skip 4
.comm ___ti22MachineTestApplication,16
	.even
LC29:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC30:
	.ascii "22MachineTestApplication\0"
	.even
.globl ___tf22MachineTestApplication
___tf22MachineTestApplication:
	movel a2,sp@-
	lea ___ti22MachineTestApplication,a2
	tstl a2@
	jne L972
	jbsr ___tf11Application
	pea 1:w
	pea LC29
	pea LC30
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L972:
	movel #___ti22MachineTestApplication,d0
	movel sp@+,a2
	rts
