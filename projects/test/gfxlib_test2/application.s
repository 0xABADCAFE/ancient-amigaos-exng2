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
	jbsr _init__8Graphicsv
	pea 6:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L606,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L605
	.even
L606:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L603
	.even
L605:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___15GraphicsTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L602
	.even
L603:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L612,a5@(-36)
	movel sp,a5@(-32)
	jra L611
	.even
L612:
	jra L616
	.even
L611:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L614
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L614:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L616:
L609:
	jbsr ___terminate
	.even
L602:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L625
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L625:
	jbsr _done__8Graphicsv
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
	movel #L631,sp@(200)
	movel sp,sp@(204)
L631:
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
	movel #L644,sp@(152)
	movel sp,sp@(156)
	movel a0,a1
L644:
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
	jeq L666
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L666:
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
	.ascii "Testing Display::Unbuffered\12\0"
LC17:
	.ascii "Caught unexpected %s\12\0"
	.even
.globl _testFullscreenUnbuffered__15GraphicsTestApp
_testFullscreenUnbuffered__15GraphicsTestApp:
	link a5,#-88
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-84)
	pea LC16
	jbsr _printf
	pea 25:w
	jbsr _Delay
	clrl sp@-
	pea 32:w
	pea 480:w
	pea 640:w
	jbsr _findMode__7DisplayssUlUl
	addw #24,sp
	tstl d0
	jeq L692
	movel a5@(-84),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L673,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-88)
	jra L672
	.even
L673:
	jra L693
	.even
L672:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-88),a1
	movel a1@,a0
	movel a0@,a1@
	jra L692
	.even
L693:
L670:
	pea ___tfQ25Error7Runtime
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L683
	jbsr ___start_cp_handler
	movel d0,a5@(-80)
	movel a5@(-84),a0
	addql #4,a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L687,a5@(-36)
	movel sp,a5@(-32)
	movel a0,a5@(-88)
	jra L686
	.even
L687:
	movel a5@(-84),a0
	addql #4,a0
	movel a0,a5@(-88)
	jra L684
	.even
L686:
	lea a5@(-48),a1
	movel a1,a0@
	movel a5@(-80),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC17
	jbsr _printf
	movel a5@(-88),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a5@(-80),sp@
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L692
	.even
L683:
	jbsr ___sjthrow
	.even
L684:
	movel a5@(-88),a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L691,a5@(-60)
	movel sp,a5@(-56)
	jra L690
	.even
L691:
	jra L694
	.even
L690:
	lea a5@(-72),a0
	movel a5@(-88),a1
	movel a0,a1@
	movel a5@(-80),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-84),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L694:
L688:
	jbsr ___terminate
	.even
L692:
	moveml a5@(-200),#0x5cfc
	fmovem a5@(-160),#0x3f
	unlk a5
	rts
LC18:
	.ascii "Testing Display::FlibBuffered\12\0"
	.even
.globl _testFullscreenBuffered__15GraphicsTestApp
_testFullscreenBuffered__15GraphicsTestApp:
	link a5,#-88
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-84)
	pea LC18
	jbsr _printf
	pea 25:w
	jbsr _Delay
	clrl sp@-
	pea 32:w
	pea 480:w
	pea 640:w
	jbsr _findMode__7DisplayssUlUl
	addw #24,sp
	tstl d0
	jeq L719
	movel a5@(-84),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L700,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-88)
	jra L699
	.even
L700:
	jra L720
	.even
L699:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-88),a1
	movel a1@,a0
	movel a0@,a1@
	jra L719
	.even
L720:
L697:
	pea ___tfQ25Error7Runtime
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L710
	jbsr ___start_cp_handler
	movel d0,a5@(-80)
	movel a5@(-84),a0
	addql #4,a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L714,a5@(-36)
	movel sp,a5@(-32)
	movel a0,a5@(-88)
	jra L713
	.even
L714:
	movel a5@(-84),a0
	addql #4,a0
	movel a0,a5@(-88)
	jra L711
	.even
L713:
	lea a5@(-48),a1
	movel a1,a0@
	movel a5@(-80),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC17
	jbsr _printf
	movel a5@(-88),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a5@(-80),sp@
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L719
	.even
L710:
	jbsr ___sjthrow
	.even
L711:
	movel a5@(-88),a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L718,a5@(-60)
	movel sp,a5@(-56)
	jra L717
	.even
L718:
	jra L721
	.even
L717:
	lea a5@(-72),a0
	movel a5@(-88),a1
	movel a0,a1@
	movel a5@(-80),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-84),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L721:
L715:
	jbsr ___terminate
	.even
L719:
	moveml a5@(-200),#0x5cfc
	fmovem a5@(-160),#0x3f
	unlk a5
	rts
LC19:
	.ascii "Testing Display::Windowed\12\0"
LC20:
	.ascii "Got Host Display (before opening)\12Display Mode : %s\12Resolution   : %d x %d x %d [%s]\12Timing:      : %.2fkHz / %.2f Hz\12\12\0"
LC21:
	.ascii "Got Host Display (after opening)\12Display Mode : %s\12Resolution   : %hd x %hd x %d [%s]\12Timing:      : %.2fkHz / %.2f Hz\12\0"
LC22:
	.ascii "Window Geometry (in screen space)\0"
LC23:
	.ascii "ViewPort Geometry (in screen space)\0"
	.even
.globl _testWindowed__15GraphicsTestApp
_testWindowed__15GraphicsTestApp:
	link a5,#-88
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-84)
	pea LC19
	jbsr _printf
	pea 25:w
	jbsr _Delay
	addql #8,sp
	movel a5@(-84),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L732,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-88)
	jra L731
	.even
L732:
	movel a5@(-84),a0
	addql #4,a0
	movel a0,a5@(-88)
	jra L729
	.even
L731:
	lea a5@(-24),a1
	movel a1,a0@
	clrl d0
	jeq L741
	clrl sp@-
	jbsr _getVerticalRefreshRateHz__CQ27Display10Properties
	movel d1,sp@-
	movel d0,sp@-
	clrl sp@-
	jbsr _getHorizontalRefreshRatekHz__CQ27Display10Properties
	addql #4,sp
	movel d1,sp@-
	movel d0,sp@-
	movel 24:w,d0
	lea __15GraphicsTestApp$formatNames,a0
	movel a0@(d0:l:4),sp@-
	movel 20:w,sp@-
	movew 2:w,a0
	movel a0,sp@-
	movew 0:w,a1
	movel a1,sp@-
	pea 28:w
	pea LC21
	jbsr _printf
	addw #40,sp
	movel #LC22,sp@
	jbsr _puts
	pea LC23
	jbsr _puts
	pea 300:w
	jbsr _Delay
	pea LC22
	jbsr _puts
	pea LC23
	jbsr _puts
	addw #20,sp
	.even
L741:
	movel a5@(-88),a1
	movel a1@,a0
	movel a0@,a1@
	jra L757
	.even
L729:
	pea ___tfQ25Error7Runtime
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L748
	jbsr ___start_cp_handler
	movel d0,a5@(-80)
	movel a5@(-88),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L752,a5@(-36)
	movel sp,a5@(-32)
	jra L751
	.even
L752:
	movel a5@(-84),a1
	addql #4,a1
	movel a1,a5@(-88)
	jra L749
	.even
L751:
	lea a5@(-48),a1
	movel a5@(-88),a0
	movel a1,a0@
	movel a5@(-80),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC17
	jbsr _printf
	movel a5@(-88),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a5@(-80),sp@
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L757
	.even
L748:
	jbsr ___sjthrow
	.even
L749:
	movel a5@(-88),a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L756,a5@(-60)
	movel sp,a5@(-56)
	jra L755
	.even
L756:
	jra L758
	.even
L755:
	lea a5@(-72),a0
	movel a5@(-88),a1
	movel a0,a1@
	movel a5@(-80),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-84),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L758:
L753:
	jbsr ___terminate
	.even
L757:
	moveml a5@(-200),#0x5cfc
	fmovem a5@(-160),#0x3f
	unlk a5
	rts
LC24:
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
	pea LC24
	jbsr _printf
	addw #20,sp
	rts
	nop
LC25:
	.ascii "Unknown\0"
LC26:
	.ascii "Bit\0"
LC27:
	.ascii "Bitfield\0"
LC28:
	.ascii "Byte\0"
LC29:
	.ascii "Word16\0"
LC30:
	.ascii "Word32\0"
LC31:
	.ascii "Word64\0"
LC32:
	.ascii "Word128\0"
.data
	.even
_wordTypes.927:
	.long LC25
	.long LC26
	.long LC27
	.long LC28
	.long LC29
	.long LC30
	.long LC31
	.long LC32
.text
LC33:
	.ascii "Red\0"
LC34:
	.ascii "Green\0"
LC35:
	.ascii "Blue\0"
LC36:
	.ascii "Alpha\0"
LC37:
	.ascii "Cyan\0"
LC38:
	.ascii "Yellow\0"
LC39:
	.ascii "Magenta\0"
LC40:
	.ascii "Black\0"
LC41:
	.ascii "Hue\0"
LC42:
	.ascii "Saturation\0"
LC43:
	.ascii "Value\0"
LC44:
	.ascii "Luminance\0"
LC45:
	.ascii "Custom_0\0"
LC46:
	.ascii "Custom_1\0"
LC47:
	.ascii "Custom_2\0"
LC48:
	.ascii "Custom_3\0"
.data
	.even
_componentNames.928:
	.long LC33
	.long LC34
	.long LC35
	.long LC36
	.long LC37
	.long LC38
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
.text
LC49:
	.ascii " byteswapped\0"
LC50:
	.ascii "\0"
LC51:
	.ascii " float\0"
LC52:
	.ascii "Pixel Layout\12Total size     :  %u bytes\12Access Type    :  %s%s%s\12Component Type :  %s\12Num Components :  %u\12\0"
LC53:
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
	lea _wordTypes.927,a0
	movel a0@(d0:l:4),sp@-
	movel a3@,d0
	movel #LC50,d2
	movel d2,d1
	btst #16,d0
	jeq L767
	movel #LC49,d1
L767:
	movel d1,sp@-
	movel d2,d1
	btst #17,d0
	jeq L770
	movel #LC51,d1
L770:
	movel d1,sp@-
	clrl d0
	moveb a3@(9),d0
	movel a0@(d0:l:4),sp@-
	clrl d0
	moveb a3@(11),d0
	movel d0,sp@-
	pea LC52
	lea _printf,a2
	jbsr a2@
	addw #28,sp
	clrl d2
	tstb a3@(10)
	jeq L781
	clrl d3
	.even
L778:
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
	lea _componentNames.928,a0
	movel a0@(d0:l:4),sp@-
	pea LC53
	jbsr a2@
	addw #32,sp
	addql #1,d2
	moveb a3@(10),d3
	cmpl d2,d3
	jhi L778
L781:
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
LC54:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC55:
	.ascii "15GraphicsTestApp\0"
	.even
.globl ___tf15GraphicsTestApp
___tf15GraphicsTestApp:
	movel a2,sp@-
	lea ___ti15GraphicsTestApp,a2
	tstl a2@
	jne L784
	jbsr ___tf11Application
	pea 1:w
	pea LC54
	pea LC55
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L784:
	movel a2,d0
	movel sp@+,a2
	rts
