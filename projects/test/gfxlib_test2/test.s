#NO_APP
.globl __15GraphicsTestApp$formatNames
.text
LC0:
	.ascii "LUT_8\0"
LC1:
	.ascii "RGB_555B\0"
LC2:
	.ascii "BGR_555B\0"
LC3:
	.ascii "RGB_555L\0"
LC4:
	.ascii "BGR_555L\0"
LC5:
	.ascii "RGB_565B\0"
LC6:
	.ascii "BGR_565B\0"
LC7:
	.ascii "RGB_565L\0"
LC8:
	.ascii "BGR_566L\0"
LC9:
	.ascii "RGB_888\0"
LC10:
	.ascii "BGR_888\0"
LC11:
	.ascii "ARGB_8888\0"
LC12:
	.ascii "ABGR_8888\0"
LC13:
	.ascii "BGRA_8888\0"
LC14:
	.ascii "RGBA_8888\0"
LC15:
	.ascii "CUSTOM_FB\0"
.data
	.even
__15GraphicsTestApp$formatNames:
	.long LC0
	.long LC1
	.long LC2
	.long LC3
	.long LC4
	.long LC5
	.long LC6
	.long LC7
	.long LC8
	.long LC9
	.long LC10
	.long LC11
	.long LC12
	.long LC13
	.long LC14
	.long LC15
.text
	.even
.globl _createInstance__11Application
_createInstance__11Application:
	link a5,#-60
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-56)
	jbsr _init__Q211EXNGPrivate11GfxResource
	pea 6:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L464,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L463
	.even
L464:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L461
	.even
L463:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___15GraphicsTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L459
	.even
L461:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L470,a5@(-36)
	movel sp,a5@(-32)
	jra L469
	.even
L470:
	jra L474
	.even
L469:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L472
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L472:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L474:
L467:
	jbsr ___terminate
	.even
L459:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L483
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L483:
	jbsr _done__Q211EXNGPrivate11GfxResource
	rts
	nop
	.even
.globl ___15GraphicsTestApp
___15GraphicsTestApp:
	addw #-100,sp
	fmovem #0xfc,sp@-
	moveml #0x3f3e,sp@-
	jbsr ___get_eh_context
	movel d0,d1
	movel sp@(220),a0
	movel #___vt_8Runnable,a0@
	movel d1,a0
	addql #4,a0
	movel a0@,sp@(188)
	clrl sp@(192)
	lea sp@(212),a1
	movel a1,sp@(196)
	movel #L490,sp@(200)
	movel sp,sp@(204)
L490:
	lea sp@(188),a2
	movel a2,a0@
	movel sp@(220),a0
	movel #___vt_11Application,a0@
	movel d1,a0
	addql #4,a0
	movel a0@,a1
	movel a1@,a0@
	movel a0@,sp@(140)
	clrl sp@(144)
	lea sp@(212),a1
	movel a1,sp@(148)
	movel #L503,sp@(152)
	movel sp,sp@(156)
	movel a0,a1
L503:
	lea sp@(140),a2
	movel a2,a0@
	movel sp@(220),a0
	movel #___vt_15GraphicsTestApp,a0@
	movel a1@,a0
	movel a0@,a1@
	movel sp@(220),d0
	moveml sp@+,#0x7cfc
	fmovem sp@+,#0x3f
	addw #100,sp
	rts
	.even
.globl __$_15GraphicsTestApp
__$_15GraphicsTestApp:
	movel sp@(4),a0
	movel #___vt_8Runnable,a0@
	btst #0,sp@(11)
	jeq L525
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L525:
	rts
	nop
	.even
.globl _run__15GraphicsTestApp
_run__15GraphicsTestApp:
	movel d2,sp@-
	movel sp@(8),d2
	movel d2,sp@-
	jbsr _testWindowed__15GraphicsTestApp
	movel d2,sp@-
	jbsr _testFullscreenUnbuffered__15GraphicsTestApp
	movel d2,sp@-
	jbsr _testFullscreenBuffered__15GraphicsTestApp
	clrl d0
	addw #12,sp
	movel sp@+,d2
	rts
LC16:
	.ascii "Listing available display modes\12\0"
LC17:
	.ascii "Windowed mode available:\12Max Size       :  %d x %d\12Depth          :  %d [%s]\12Timing:        :  %.2fkHz / %.2f Hz\12\0"
LC18:
	.ascii "\12------------------------\12\0"
LC19:
	.ascii "Windowed mode not available\12\0"
LC20:
	.ascii "Display Mode   :  %s\12Resolution     :  %d x %d x %d [%s]\12Timing         :  %.2fkHz / %.2f Hz\12\0"
	.even
.globl _printDisplayProperties__15GraphicsTestApp
_printDisplayProperties__15GraphicsTestApp:
	addw #-12,sp
	moveml #0x2038,sp@-
	movel sp@(32),d2
	pea LC16
	lea _printf,a3
	jbsr a3@
	jbsr _getWindowedMode__Q27Display10Properties
	movel d0,a2
	addql #4,sp
	tstl a2
	jeq L528
	movel a2,sp@-
	jbsr _getVerticalRefreshRateHz__CQ27Display10Properties
	movel d1,sp@-
	movel d0,sp@-
	movel a2,sp@-
	jbsr _getHorizontalRefreshRatekHz__CQ27Display10Properties
	addql #4,sp
	movel d1,sp@-
	movel d0,sp@-
	movel a2@(24),d0
	lea __15GraphicsTestApp$formatNames,a0
	movel a0@(d0:l:4),sp@-
	movel a2@(20),sp@-
	movew a2@(2),a0
	movel a0,sp@-
	movew a2@,a0
	movel a0,sp@-
	pea LC17
	jbsr a3@
	addw #40,sp
	moveq #24,d0
	mulsl a2@(24),d0
	addl #__5Pixel$fbTypeLayout,d0
	movel d0,sp@-
	movel d2,sp@-
	jbsr _describePixelLayout__15GraphicsTestAppPCQ25Pixel6Layout
	pea LC18
	jbsr a3@
	addw #12,sp
	jra L535
	.even
L528:
	pea LC19
	jbsr _puts
	addql #4,sp
L535:
	jbsr _getAvailableModes__Q27Display10Properties
	movel d0,sp@(16)
	movel d1,sp@(20)
	lea sp@(16),a1
	movel a1@,a0
	movel a0@,sp@(20)
	movel sp@(20),d0
	movel a1,a4
	jlt L540
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),sp@(20)
	movel d1,d0
	jra L541
	.even
L540:
	clrl d0
L541:
	movel d0,a2
	tstl a2
	jeq L562
	lea _printf,a3
	.even
L547:
	movel a2,sp@-
	jbsr _getVerticalRefreshRateHz__CQ27Display10Properties
	movel d1,sp@-
	movel d0,sp@-
	movel a2,sp@-
	jbsr _getHorizontalRefreshRatekHz__CQ27Display10Properties
	addql #4,sp
	movel d1,sp@-
	movel d0,sp@-
	movel a2@(24),d0
	lea __15GraphicsTestApp$formatNames,a0
	movel a0@(d0:l:4),sp@-
	movel a2@(20),sp@-
	movew a2@(2),a0
	movel a0,sp@-
	movew a2@,a0
	movel a0,sp@-
	pea a2@(28)
	pea LC20
	jbsr a3@
	addw #44,sp
	moveq #24,d0
	mulsl a2@(24),d0
	addl #__5Pixel$fbTypeLayout,d0
	movel d0,sp@-
	movel d2,sp@-
	jbsr _describePixelLayout__15GraphicsTestAppPCQ25Pixel6Layout
	pea LC18
	jbsr a3@
	addw #12,sp
	movel a4@(4),d0
	jlt L558
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a4@(4)
	movel d1,d0
	jra L559
	.even
L558:
	clrl d0
L559:
	movel d0,a2
	tstl a2
	jne L547
L562:
	moveml sp@+,#0x1c04
	addw #12,sp
	rts
LC21:
	.ascii "Testing Display::Unbuffered\12\0"
LC22:
	.ascii "Caught unexpected %s\12\0"
	.even
.globl _testFullscreenUnbuffered__15GraphicsTestApp
_testFullscreenUnbuffered__15GraphicsTestApp:
	link a5,#-484
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-470)
	pea LC21
	lea a5@(-362),a0
	movel a0,a5@(-482)
	jbsr _printf
	pea 25:w
	jbsr _Delay
	movel a5@(-470),a1
	addql #4,a1
	movel a1,a5@(-454)
	movel a1@,a0
	addql #4,a0
	movel a0@,a5@(-374)
	movel #__$_Q27Display10Unbuffered,a5@(-370)
	movel a5@(-482),a5@(-366)
	lea a5@(-374),a1
	movel a1,a0@
	clrl sp@-
	pea 32:w
	pea 480:w
	pea 640:w
	movel a5@(-454),a5@(-474)
	jbsr _findMode__7DisplayssUlUl
	addw #24,sp
	tstl d0
	jeq L565
	movel a5@(-474),a0
	movel a0@,a5@(-398)
	clrl a5@(-394)
	lea a5@(-390),a0
	movel a5,a0@
	movel #L569,a0@(4)
	movel sp,a0@(8)
	jra L568
	.even
L569:
	movel a5@(-470),a1
	addql #4,a1
	movel a1,a5@(-474)
	jra L566
	.even
L568:
	lea a5@(-398),a1
	movel a5@(-454),a0
	movel a1,a0@
	movel d0,sp@-
	movel a5@(-482),sp@-
	jbsr _open__Q27Display10UnbufferedPCQ27Display10Properties
	addql #8,sp
	movel a5@(-340),a5@(-458)
	jeq L572
	clrl a5@(-462)
	lea a5@(-450),a0
	movel a0,a5@(-478)
	.even
L576:
	movel a5@(-478),a1
	movel a5@(-462),a1@
	movel a5@(-458),a1
	movel a1@(4),a0
	movel a5@(-450),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-482),sp@-
	jbsr _refresh__Q27Display10Unbuffered
	movel a5@(-482),sp@-
	jbsr _synchronize__Q27Display10Unbuffered
	addw #16,sp
	movel a5@(-462),a1
	addl #65793,a1
	movel a5@(-478),a0
	movel a1,a0@
	movel a5@(-458),a1
	movel a1@(4),a0
	movel a5@(-450),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-482),sp@-
	jbsr _refresh__Q27Display10Unbuffered
	movel a5@(-482),sp@-
	jbsr _synchronize__Q27Display10Unbuffered
	addw #16,sp
	movel a5@(-462),a1
	addl #131586,a1
	movel a5@(-478),a0
	movel a1,a0@
	movel a5@(-458),a1
	movel a1@(4),a0
	movel a5@(-450),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-482),sp@-
	jbsr _refresh__Q27Display10Unbuffered
	movel a5@(-482),sp@-
	jbsr _synchronize__Q27Display10Unbuffered
	addw #16,sp
	movel a5@(-462),a1
	addl #197379,a1
	movel a5@(-478),a0
	movel a1,a0@
	movel a5@(-458),a1
	movel a1@(4),a0
	movel a5@(-450),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-482),sp@-
	jbsr _refresh__Q27Display10Unbuffered
	movel a5@(-482),sp@-
	jbsr _synchronize__Q27Display10Unbuffered
	addw #16,sp
	movel a5@(-462),a1
	addl #263172,a1
	movel a5@(-478),a0
	movel a1,a0@
	movel a5@(-458),a1
	movel a1@(4),a0
	movel a5@(-450),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-482),sp@-
	jbsr _refresh__Q27Display10Unbuffered
	movel a5@(-482),sp@-
	jbsr _synchronize__Q27Display10Unbuffered
	addw #16,sp
	addl #328965,a5@(-462)
	cmpl #16777214,a5@(-462)
	jls L576
L572:
	movel a5@(-474),a1
	movel a1@,a0
	movel a0@,a1@
L565:
	movel a5@(-474),a0
	movel a0@,a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	pea 2:w
	movel a5@(-482),sp@-
	jbsr __$_Q27Display10Unbuffered
	addql #8,sp
	jra L590
	.even
L566:
	pea ___tfQ25Error7Runtime
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L581
	jbsr ___start_cp_handler
	movel d0,a5@(-466)
	movel a5@(-474),a1
	movel a1@,a5@(-422)
	clrl a5@(-418)
	lea a5@(-414),a0
	movel a5,a0@
	movel #L585,a0@(4)
	movel sp,a0@(8)
	jra L584
	.even
L585:
	movel a5@(-470),a0
	addql #4,a0
	movel a0,a5@(-474)
	jra L582
	.even
L584:
	lea a5@(-422),a0
	movel a5@(-474),a1
	movel a0,a1@
	movel a5@(-466),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC22
	jbsr _printf
	movel a5@(-474),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a5@(-466),sp@
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L565
	.even
L581:
	jbsr ___sjthrow
	.even
L582:
	movel a5@(-474),a0
	movel a0@,a5@(-446)
	clrl a5@(-442)
	lea a5@(-438),a0
	movel a5,a0@
	movel #L589,a0@(4)
	movel sp,a0@(8)
	jra L588
	.even
L589:
	jra L601
	.even
L588:
	lea a5@(-446),a0
	movel a5@(-474),a1
	movel a0,a1@
	movel a5@(-466),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-470),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L601:
L586:
	jbsr ___terminate
	.even
L590:
	moveml a5@(-596),#0x5cfc
	fmovem a5@(-556),#0x3f
	unlk a5
	rts
LC23:
	.ascii "Testing Display::FlibBuffered\12\0"
	.even
.globl _testFullscreenBuffered__15GraphicsTestApp
_testFullscreenBuffered__15GraphicsTestApp:
	link a5,#-508
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-494)
	pea LC23
	lea a5@(-386),a0
	movel a0,a5@(-498)
	jbsr _printf
	pea 25:w
	jbsr _Delay
	movel a5@(-494),a1
	addql #4,a1
	movel a1,a5@(-478)
	movel a1@,a0
	addql #4,a0
	movel a0@,a5@(-398)
	movel #__$_Q27Display12FlipBuffered,a5@(-394)
	movel a5@(-498),a5@(-390)
	lea a5@(-398),a1
	movel a1,a0@
	clrl sp@-
	pea 32:w
	pea 480:w
	pea 640:w
	movel a5@(-478),a5@(-502)
	jbsr _findMode__7DisplayssUlUl
	addw #24,sp
	tstl d0
	jeq L603
	movel a5@(-502),a0
	movel a0@,a5@(-422)
	clrl a5@(-418)
	lea a5@(-414),a0
	movel a5,a0@
	movel #L607,a0@(4)
	movel sp,a0@(8)
	jra L606
	.even
L607:
	movel a5@(-494),a1
	addql #4,a1
	movel a1,a5@(-502)
	jra L604
	.even
L606:
	lea a5@(-422),a1
	movel a5@(-478),a0
	movel a1,a0@
	movel d0,sp@-
	movel a5@(-498),sp@-
	jbsr _open__Q27Display12FlipBufferedPCQ27Display10Properties
	addql #8,sp
	movel a5@(-364),a5@(-482)
	jeq L610
	clrl a5@(-486)
	lea a5@(-474),a0
	movel a0,a5@(-506)
	.even
L614:
	movel a5@(-506),a1
	movel a5@(-486),a1@
	movel a5@(-482),a1
	movel a1@(4),a0
	movel a5@(-474),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-498),sp@-
	jbsr _refresh__Q27Display12FlipBuffered
	movel a5@(-498),sp@-
	jbsr _synchronize__Q27Display12FlipBuffered
	addw #16,sp
	movel a5@(-486),a1
	addl #65793,a1
	movel a5@(-506),a0
	movel a1,a0@
	movel a5@(-482),a1
	movel a1@(4),a0
	movel a5@(-474),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-498),sp@-
	jbsr _refresh__Q27Display12FlipBuffered
	movel a5@(-498),sp@-
	jbsr _synchronize__Q27Display12FlipBuffered
	addw #16,sp
	movel a5@(-486),a1
	addl #131586,a1
	movel a5@(-506),a0
	movel a1,a0@
	movel a5@(-482),a1
	movel a1@(4),a0
	movel a5@(-474),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-498),sp@-
	jbsr _refresh__Q27Display12FlipBuffered
	movel a5@(-498),sp@-
	jbsr _synchronize__Q27Display12FlipBuffered
	addw #16,sp
	movel a5@(-486),a1
	addl #197379,a1
	movel a5@(-506),a0
	movel a1,a0@
	movel a5@(-482),a1
	movel a1@(4),a0
	movel a5@(-474),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-498),sp@-
	jbsr _refresh__Q27Display12FlipBuffered
	movel a5@(-498),sp@-
	jbsr _synchronize__Q27Display12FlipBuffered
	addw #16,sp
	movel a5@(-486),a1
	addl #263172,a1
	movel a5@(-506),a0
	movel a1,a0@
	movel a5@(-482),a1
	movel a1@(4),a0
	movel a5@(-474),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-498),sp@-
	jbsr _refresh__Q27Display12FlipBuffered
	movel a5@(-498),sp@-
	jbsr _synchronize__Q27Display12FlipBuffered
	addw #16,sp
	addl #328965,a5@(-486)
	cmpl #16777214,a5@(-486)
	jls L614
L610:
	movel a5@(-502),a1
	movel a1@,a0
	movel a0@,a1@
L603:
	movel a5@(-502),a0
	movel a0@,a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	pea 2:w
	movel a5@(-498),sp@-
	jbsr __$_Q27Display12FlipBuffered
	addql #8,sp
	jra L628
	.even
L604:
	pea ___tfQ25Error7Runtime
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L619
	jbsr ___start_cp_handler
	movel d0,a5@(-490)
	movel a5@(-502),a1
	movel a1@,a5@(-446)
	clrl a5@(-442)
	lea a5@(-438),a0
	movel a5,a0@
	movel #L623,a0@(4)
	movel sp,a0@(8)
	jra L622
	.even
L623:
	movel a5@(-494),a0
	addql #4,a0
	movel a0,a5@(-502)
	jra L620
	.even
L622:
	lea a5@(-446),a0
	movel a5@(-502),a1
	movel a0,a1@
	movel a5@(-490),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC22
	jbsr _printf
	movel a5@(-502),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a5@(-490),sp@
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L603
	.even
L619:
	jbsr ___sjthrow
	.even
L620:
	movel a5@(-502),a0
	movel a0@,a5@(-470)
	clrl a5@(-466)
	lea a5@(-462),a0
	movel a5,a0@
	movel #L627,a0@(4)
	movel sp,a0@(8)
	jra L626
	.even
L627:
	jra L639
	.even
L626:
	lea a5@(-470),a0
	movel a5@(-502),a1
	movel a0,a1@
	movel a5@(-490),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-494),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L639:
L624:
	jbsr ___terminate
	.even
L628:
	moveml a5@(-620),#0x5cfc
	fmovem a5@(-580),#0x3f
	unlk a5
	rts
LC24:
	.ascii "Testing Display::Windowed\12\0"
LC25:
	.ascii "Got Host Display (before opening)\12Display Mode : %s\12Resolution   : %d x %d x %d [%s]\12Timing:      : %.2fkHz / %.2f Hz\12\12\0"
LC26:
	.ascii "Display::Windowed test instance - drag me a bit\0"
LC27:
	.ascii "Got Host Display (after opening)\12Display Mode : %s\12Resolution   : %hd x %hd x %d [%s]\12Timing:      : %.2fkHz / %.2f Hz\12\0"
LC28:
	.ascii "Window Geometry (in screen space)\0"
LC29:
	.ascii "ViewPort Geometry (in screen space)\0"
	.even
.globl _testWindowed__15GraphicsTestApp
_testWindowed__15GraphicsTestApp:
	link a5,#-668
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-654)
	pea LC24
	lea a5@(-542),a0
	movel a0,a5@(-666)
	jbsr _printf
	pea 25:w
	jbsr _Delay
	movel a5@(-654),a1
	addql #4,a1
	movel a1,a5@(-634)
	movel a1@,a0
	addql #4,a0
	movel a0@,a5@(-554)
	movel #__$_Q27Display8Windowed,a5@(-550)
	movel a5@(-666),a5@(-546)
	lea a5@(-554),a1
	movel a1,a0@
	addql #8,sp
	pea a5@(-530)
	movel a5@(-634),a5@(-658)
	jbsr _getDisplayProperties__Q211EXNGPrivate10OSWindowed
	movel d0,a5@(-638)
	addql #4,sp
	jeq L642
	movel d0,sp@-
	jbsr _getVerticalRefreshRateHz__CQ27Display10Properties
	movel d1,sp@-
	movel d0,sp@-
	movel a5@(-638),sp@-
	jbsr _getHorizontalRefreshRatekHz__CQ27Display10Properties
	addql #4,sp
	movel d1,sp@-
	movel d0,sp@-
	movel a5@(-638),a0
	movel a0@(24),d0
	lea __15GraphicsTestApp$formatNames,a0
	movel a0@(d0:l:4),sp@-
	movel a5@(-638),a1
	movel a1@(20),sp@-
	movew a1@(2),a0
	movel a0,sp@-
	movew a1@,a1
	movel a1,sp@-
	movel a5@(-638),a0
	pea a0@(28)
	pea LC25
	jbsr _printf
	addw #44,sp
L642:
	movel a5@(-658),a1
	movel a1@,a5@(-578)
	clrl a5@(-574)
	lea a5@(-570),a0
	movel a5,a0@
	movel #L651,a0@(4)
	movel sp,a0@(8)
	jra L650
	.even
L651:
	movel a5@(-654),a0
	addql #4,a0
	movel a0,a5@(-658)
	jra L648
	.even
L650:
	lea a5@(-578),a0
	movel a5@(-634),a1
	movel a0,a1@
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	pea LC26
	pea a5@(-530)
	jbsr _setDisplayTitle__Q211EXNGPrivate9OSDisplayPCcb
	addqw #8,sp
	movel #480,sp@
	pea 640:w
	clrl sp@-
	clrl sp@-
	movel a5@(-666),sp@-
	jbsr _open__Q27Display8Windowedssss
	addw #20,sp
	movel a5@(-520),a5@(-642)
	jeq L655
	clrl a5@(-646)
	lea a5@(-630),a1
	movel a1,a5@(-662)
	.even
L659:
	movel a5@(-662),a0
	movel a5@(-646),a0@
	movel a5@(-642),a1
	movel a1@(4),a0
	movel a5@(-630),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-666),sp@-
	jbsr _refresh__Q27Display8Windowed
	movel a5@(-666),sp@-
	jbsr _synchronize__Q27Display8Windowed
	addw #16,sp
	movel a5@(-646),a1
	addl #65793,a1
	movel a5@(-662),a0
	movel a1,a0@
	movel a5@(-642),a1
	movel a1@(4),a0
	movel a5@(-630),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-666),sp@-
	jbsr _refresh__Q27Display8Windowed
	movel a5@(-666),sp@-
	jbsr _synchronize__Q27Display8Windowed
	addw #16,sp
	movel a5@(-646),a1
	addl #131586,a1
	movel a5@(-662),a0
	movel a1,a0@
	movel a5@(-642),a1
	movel a1@(4),a0
	movel a5@(-630),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-666),sp@-
	jbsr _refresh__Q27Display8Windowed
	movel a5@(-666),sp@-
	jbsr _synchronize__Q27Display8Windowed
	addw #16,sp
	movel a5@(-646),a1
	addl #197379,a1
	movel a5@(-662),a0
	movel a1,a0@
	movel a5@(-642),a1
	movel a1@(4),a0
	movel a5@(-630),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-666),sp@-
	jbsr _refresh__Q27Display8Windowed
	movel a5@(-666),sp@-
	jbsr _synchronize__Q27Display8Windowed
	addw #16,sp
	movel a5@(-646),a1
	addl #263172,a1
	movel a5@(-662),a0
	movel a1,a0@
	movel a5@(-642),a1
	movel a1@(4),a0
	movel a5@(-630),sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	movel a5@(-666),sp@-
	jbsr _refresh__Q27Display8Windowed
	movel a5@(-666),sp@-
	jbsr _synchronize__Q27Display8Windowed
	addw #16,sp
	addl #328965,a5@(-646)
	cmpl #16777214,a5@(-646)
	jls L659
L655:
	pea a5@(-530)
	jbsr _getDisplayProperties__Q211EXNGPrivate10OSWindowed
	movel d0,a5@(-638)
	addql #4,sp
	jeq L664
	movel d0,sp@-
	jbsr _getVerticalRefreshRateHz__CQ27Display10Properties
	movel d1,sp@-
	movel d0,sp@-
	movel a5@(-638),sp@-
	jbsr _getHorizontalRefreshRatekHz__CQ27Display10Properties
	addql #4,sp
	movel d1,sp@-
	movel d0,sp@-
	movel a5@(-638),a0
	movel a0@(24),d0
	lea __15GraphicsTestApp$formatNames,a0
	movel a0@(d0:l:4),sp@-
	movel a5@(-638),a1
	movel a1@(20),sp@-
	movew a1@(2),a0
	movel a0,sp@-
	movew a1@,a1
	movel a1,sp@-
	movel a5@(-638),a0
	pea a0@(28)
	pea LC27
	jbsr _printf
	addw #40,sp
	movel #LC28,sp@
	jbsr _puts
	movel a5@(-666),sp@-
	jbsr _getFrameRect__Q27Display8Windowed
	movel d0,sp@-
	movel a5@(8),sp@-
	jbsr _printGfxRect__15GraphicsTestAppRC7GfxRect
	pea LC29
	jbsr _puts
	movel a5@(-666),sp@-
	jbsr _getViewPortRect__Q27Display8Windowed
	movel d0,sp@-
	movel a5@(8),sp@-
	jbsr _printGfxRect__15GraphicsTestAppRC7GfxRect
	addw #28,sp
	movel #300,sp@
	jbsr _Delay
	pea LC28
	jbsr _puts
	movel a5@(-666),sp@-
	jbsr _getFrameRect__Q27Display8Windowed
	movel d0,sp@-
	movel a5@(8),sp@-
	jbsr _printGfxRect__15GraphicsTestAppRC7GfxRect
	pea LC29
	jbsr _puts
	movel a5@(-666),sp@-
	jbsr _getViewPortRect__Q27Display8Windowed
	movel d0,sp@-
	movel a5@(8),sp@-
	jbsr _printGfxRect__15GraphicsTestAppRC7GfxRect
	addw #36,sp
L664:
	movel a5@(-658),a1
	movel a1@,a0
	movel a0@,a1@
L670:
	movel a5@(-658),a0
	movel a0@,a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	pea 2:w
	movel a5@(-666),sp@-
	jbsr __$_Q27Display8Windowed
	addql #8,sp
	jra L680
	.even
L648:
	pea ___tfQ25Error7Runtime
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L671
	jbsr ___start_cp_handler
	movel d0,a5@(-650)
	movel a5@(-658),a1
	movel a1@,a5@(-602)
	clrl a5@(-598)
	lea a5@(-594),a0
	movel a5,a0@
	movel #L675,a0@(4)
	movel sp,a0@(8)
	jra L674
	.even
L675:
	movel a5@(-654),a0
	addql #4,a0
	movel a0,a5@(-658)
	jra L672
	.even
L674:
	lea a5@(-602),a0
	movel a5@(-658),a1
	movel a0,a1@
	movel a5@(-650),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC22
	jbsr _printf
	movel a5@(-658),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a5@(-650),sp@
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L670
	.even
L671:
	jbsr ___sjthrow
	.even
L672:
	movel a5@(-658),a0
	movel a0@,a5@(-626)
	clrl a5@(-622)
	lea a5@(-618),a0
	movel a5,a0@
	movel #L679,a0@(4)
	movel sp,a0@(8)
	jra L678
	.even
L679:
	jra L691
	.even
L678:
	lea a5@(-626),a0
	movel a5@(-658),a1
	movel a0,a1@
	movel a5@(-650),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-654),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L691:
L676:
	jbsr ___terminate
	.even
L680:
	moveml a5@(-780),#0x5cfc
	fmovem a5@(-740),#0x3f
	unlk a5
	rts
LC30:
	.ascii "X:%hd, Y:%hd\12W:%hd, H:%hd\12\0"
	.even
.globl _printGfxRect__15GraphicsTestAppRC7GfxRect
_printGfxRect__15GraphicsTestAppRC7GfxRect:
	movel sp@(8),a0
	movew a0@(2),a1
	movel a1,sp@-
	movew a0@,a1
	movel a1,sp@-
	movew a0@(6),a1
	movel a1,sp@-
	movew a0@(4),a0
	movel a0,sp@-
	pea LC30
	jbsr _printf
	addw #20,sp
	rts
	nop
LC31:
	.ascii "Unknown\0"
LC32:
	.ascii "Bit\0"
LC33:
	.ascii "Bitfield\0"
LC34:
	.ascii "Byte\0"
LC35:
	.ascii "Word16\0"
LC36:
	.ascii "Word32\0"
LC37:
	.ascii "Word64\0"
LC38:
	.ascii "Word128\0"
.data
	.even
_wordTypes.666:
	.long LC31
	.long LC32
	.long LC33
	.long LC34
	.long LC35
	.long LC36
	.long LC37
	.long LC38
.text
LC39:
	.ascii "Red\0"
LC40:
	.ascii "Green\0"
LC41:
	.ascii "Blue\0"
LC42:
	.ascii "Alpha\0"
LC43:
	.ascii "Cyan\0"
LC44:
	.ascii "Yellow\0"
LC45:
	.ascii "Magenta\0"
LC46:
	.ascii "Black\0"
LC47:
	.ascii "Hue\0"
LC48:
	.ascii "Saturation\0"
LC49:
	.ascii "Value\0"
LC50:
	.ascii "Luminance\0"
LC51:
	.ascii "Custom_0\0"
LC52:
	.ascii "Custom_1\0"
LC53:
	.ascii "Custom_2\0"
LC54:
	.ascii "Custom_3\0"
.data
	.even
_componentNames.667:
	.long LC39
	.long LC40
	.long LC41
	.long LC42
	.long LC43
	.long LC44
	.long LC45
	.long LC46
	.long LC47
	.long LC48
	.long LC49
	.long LC50
	.long LC51
	.long LC52
	.long LC53
	.long LC54
.text
LC55:
	.ascii " byteswapped\0"
LC56:
	.ascii "\0"
LC57:
	.ascii " float\0"
LC58:
	.ascii "Pixel Layout\12Total size     :  %u bytes\12Access Type    :  %s%s%s\12Component Type :  %s\12Num Components :  %u\12\0"
LC59:
	.ascii "[%12s] : %2u : %2u Range:0-%u [%08X]\12\0"
	.even
.globl _describePixelLayout__15GraphicsTestAppPCQ25Pixel6Layout
_describePixelLayout__15GraphicsTestAppPCQ25Pixel6Layout:
	moveml #0x3030,sp@-
	movel sp@(24),a3
	clrl d0
	moveb a3@(10),d0
	movel d0,sp@-
	clrl d0
	moveb a3@(8),d0
	lea _wordTypes.666,a0
	movel a0@(d0:l:4),sp@-
	movel a3@,d0
	movel #LC56,d2
	movel d2,d1
	btst #16,d0
	jeq L700
	movel #LC55,d1
L700:
	movel d1,sp@-
	movel d2,d1
	btst #17,d0
	jeq L703
	movel #LC57,d1
L703:
	movel d1,sp@-
	clrl d0
	moveb a3@(9),d0
	movel a0@(d0:l:4),sp@-
	clrl d0
	moveb a3@(11),d0
	movel d0,sp@-
	pea LC58
	lea _printf,a2
	jbsr a2@
	addw #28,sp
	clrl d2
	tstb a3@(10)
	jeq L714
	clrl d3
	.even
L711:
	movel d2,sp@-
	movel a3,sp@-
	jbsr _getComponentMask__CQ25Pixel6LayoutUl
	movel d0,sp@-
	movel d2,sp@-
	movel a3,sp@-
	jbsr _getComponentMax__CQ25Pixel6LayoutUl
	addqw #4,sp
	movel d0,sp@
	movel d2,sp@-
	movel a3,sp@-
	jbsr _getComponentPosition__CQ25Pixel6LayoutUl
	addqw #4,sp
	movel d0,sp@
	movel d2,sp@-
	movel a3,sp@-
	jbsr _getComponentWidth__CQ25Pixel6LayoutUl
	addqw #4,sp
	movel d0,sp@
	movel d2,sp@-
	movel a3,sp@-
	jbsr _getComponentType__CQ25Pixel6LayoutUl
	addql #8,sp
	lea _componentNames.667,a0
	movel a0@(d0:l:4),sp@-
	pea LC59
	jbsr a2@
	addw #32,sp
	addql #1,d2
	moveb a3@(10),d3
	cmpl d2,d3
	jhi L711
L714:
	moveml sp@+,#0xc0c
	rts
.globl ___vt_15GraphicsTestApp
	.even
___vt_15GraphicsTestApp:
	.long 0
	.long ___tf15GraphicsTestApp
	.long __dfRTTI__11Application
	.long _run__15GraphicsTestApp
	.long __$_15GraphicsTestApp
	.skip 4
.comm ___ti15GraphicsTestApp,16
	.even
LC60:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC61:
	.ascii "15GraphicsTestApp\0"
	.even
.globl ___tf15GraphicsTestApp
___tf15GraphicsTestApp:
	movel a2,sp@-
	lea ___ti15GraphicsTestApp,a2
	tstl a2@
	jne L717
	jbsr ___tf11Application
	pea 1:w
	pea LC60
	pea LC61
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L717:
	movel a2,d0
	movel sp@+,a2
	rts
