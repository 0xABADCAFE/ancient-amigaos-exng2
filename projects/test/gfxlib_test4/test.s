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
	jbsr _init__8Graphics
	pea 10:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L385,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L384
	.even
L385:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L382
	.even
L384:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___14PaletteTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L381
	.even
L382:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L391,a5@(-36)
	movel sp,a5@(-32)
	jra L390
	.even
L391:
	jra L395
	.even
L390:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L393
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L393:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L395:
L388:
	jbsr ___terminate
	.even
L381:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L404
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L404:
	jbsr _done__8Graphics
	rts
	nop
LC0:
	.ascii "Creating %d arbitrary colours...\0"
LC1:
	.ascii "done\12\0"
	.even
.globl ___14PaletteTestApp
___14PaletteTestApp:
	link a5,#-120
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
	movel #L410,a5@(-12)
	movel sp,a5@(-8)
L410:
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
	movel #L424,a5@(-60)
	movel sp,a5@(-56)
	movel a0,a5@(-108)
	jra L423
	.even
L424:
	jra L457
	.even
L423:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_14PaletteTestApp,a0@
	movel #307200,a5@(-100)
	clrl sp@-
	movel #1228800,sp@-
	jbsr _alloc__3MemUlUl
	movel d0,a5@(-104)
	addql #8,sp
	movel a5@(8),a1
	movel d0,a1@(6)
	movel a5@(-100),sp@-
	pea LC0
	jbsr _printf
	movel ___sF,a0
	movel a0@(4),sp@-
	jbsr _fflush
	addw #12,sp
	movel #307199,a5@(-100)
	movel a5@(-104),d0
	addql #3,d0
	movel d0,a5@(-112)
	movel d0,a5@(-116)
	movel d0,a5@(-120)
	.even
L429:
	jbsr _rand
	movel a5@(-120),a0
	moveb d0,a0@(-2)
	jbsr _rand
	movel a5@(-116),a1
	moveb d0,a1@(-1)
	jbsr _rand
	movel a5@(-112),a0
	moveb d0,a0@
	jbsr _rand
	movel a5@(-120),a1
	moveb d0,a1@(2)
	jbsr _rand
	movel a5@(-116),a0
	moveb d0,a0@(3)
	jbsr _rand
	movel a5@(-112),a1
	moveb d0,a1@(4)
	jbsr _rand
	movel a5@(-120),a0
	moveb d0,a0@(6)
	jbsr _rand
	movel a5@(-116),a1
	moveb d0,a1@(7)
	jbsr _rand
	movel a5@(-112),a0
	moveb d0,a0@(8)
	jbsr _rand
	movel a5@(-120),a1
	moveb d0,a1@(10)
	jbsr _rand
	movel a5@(-116),a0
	moveb d0,a0@(11)
	jbsr _rand
	movel a5@(-112),a1
	moveb d0,a1@(12)
	jbsr _rand
	movel a5@(-120),a0
	moveb d0,a0@(14)
	jbsr _rand
	movel a5@(-116),a1
	moveb d0,a1@(15)
	jbsr _rand
	movel a5@(-112),a0
	moveb d0,a0@(16)
	moveq #20,d0
	addl d0,a5@(-112)
	addl d0,a5@(-116)
	addl d0,a5@(-120)
	subql #5,a5@(-100)
	moveq #-1,d0
	cmpl a5@(-100),d0
	jne L429
	pea LC1
	jbsr _printf
	addql #4,sp
	movel a5@(-108),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L446
	.even
L457:
L421:
	movel a5@(-108),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L438,a5@(-84)
	movel sp,a5@(-80)
	jra L437
	.even
L438:
	jra L458
	.even
L437:
	lea a5@(-96),a0
	movel a5@(-108),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_8Runnable,a1@
	movel a5@(-108),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L458:
L435:
	jbsr ___terminate
	.even
L446:
	moveml a5@(-232),#0x5cfc
	fmovem a5@(-192),#0x3f
	unlk a5
	rts
	.even
.globl __$_14PaletteTestApp
__$_14PaletteTestApp:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel sp@(16),d2
	movel #___vt_14PaletteTestApp,a2@
	movel a2@(6),sp@-
	jbsr _free__3MemPv
	addql #4,sp
	movel #___vt_8Runnable,a2@
	btst #0,d2
	jeq L466
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L466:
	movel sp@+,d2
	movel sp@+,a2
	rts
LC2:
	.ascii "Testing Palette::PAL_FAKERGB_666...\0"
LC3:
	.ascii "%.3f ms\12\0"
	.even
.globl _run__14PaletteTestApp
_run__14PaletteTestApp:
	link a5,#-8
	moveml #0x3838,sp@-
	pea a5@(-8)
	jbsr ___Q24Time10MilliClock
	clrl sp@-
	jbsr _getPresetPalette__7PaletteQ27Palette6Preset
	movel d0,d3
	addql #8,sp
	jeq L468
	pea LC2
	lea _printf,a2
	jbsr a2@
	movel ___sF,a0
	movel a0@(4),sp@-
	jbsr _fflush
	movel a5@(8),a0
	movel a0@(6),d2
	pea a5@(-8)
	jbsr _set__Q24Time10MilliClock
	addw #12,sp
	movel #307199,d4
	movel a2,a4
	lea _findBestMatch__C7PaletteG8Colour32b,a3
	.even
L471:
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	movel d2,a2
	movel a2@+,sp@-
	movel d3,sp@-
	jbsr a3@
	addw #12,sp
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	movel a2@,sp@-
	movel d2,a2
	addql #8,a2
	movel d3,sp@-
	jbsr a3@
	addw #12,sp
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	movel a2@,sp@-
	movel d2,a0
	lea a0@(12),a2
	movel d3,sp@-
	jbsr a3@
	addw #12,sp
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	movel a2@,sp@-
	movel d2,a0
	lea a0@(16),a2
	movel d3,sp@-
	jbsr a3@
	addw #12,sp
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	movel a2@,sp@-
	moveq #20,d0
	addl d0,d2
	movel d3,sp@-
	jbsr a3@
	addw #12,sp
	subql #5,d4
	moveq #-1,d0
	cmpl d4,d0
	jne L471
	pea a5@(-8)
	jbsr _elapsedFrac__CQ24Time10MilliClock
	movel d1,sp@-
	movel d0,sp@-
	pea LC3
	jbsr a4@
	addw #16,sp
L468:
	clrl d0
	moveml a5@(-32),#0x1c1c
	unlk a5
	rts
.globl ___vt_14PaletteTestApp
	.even
___vt_14PaletteTestApp:
	.long 0
	.long ___tf14PaletteTestApp
	.long __dfRTTI__11Application
	.long _run__14PaletteTestApp
	.long __$_14PaletteTestApp
	.skip 4
.comm ___ti14PaletteTestApp,16
	.even
LC4:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC5:
	.ascii "14PaletteTestApp\0"
	.even
.globl ___tf14PaletteTestApp
___tf14PaletteTestApp:
	movel a2,sp@-
	lea ___ti14PaletteTestApp,a2
	tstl a2@
	jne L484
	jbsr ___tf11Application
	pea 1:w
	pea LC4
	pea LC5
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L484:
	movel a2,d0
	movel sp@+,a2
	rts
