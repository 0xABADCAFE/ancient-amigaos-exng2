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
	movel sp@(4),sp@-
	jbsr _printDisplayProperties__15GraphicsTestApp
	clrl d0
	addql #4,sp
	rts
	nop
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
	jeq L669
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
	jra L676
	.even
L669:
	pea LC19
	jbsr _puts
	addql #4,sp
L676:
	jbsr _getAvailableModes__Q27Display10Properties
	movel d0,sp@(16)
	movel d1,sp@(20)
	lea sp@(16),a1
	movel a1@,a0
	movel a0@,sp@(20)
	movel sp@(20),d0
	movel a1,a4
	jlt L681
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),sp@(20)
	movel d1,d0
	jra L682
	.even
L681:
	clrl d0
L682:
	movel d0,a2
	tstl a2
	jeq L703
	lea _printf,a3
	.even
L688:
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
	jlt L699
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a4@(4)
	movel d1,d0
	jra L700
	.even
L699:
	clrl d0
L700:
	movel d0,a2
	tstl a2
	jne L688
L703:
	moveml sp@+,#0x1c04
	addw #12,sp
	rts
	.even
.globl _testFullscreenUnbuffered__15GraphicsTestApp
_testFullscreenUnbuffered__15GraphicsTestApp:
	rts
	nop
	.even
.globl _testFullscreenBuffered__15GraphicsTestApp
_testFullscreenBuffered__15GraphicsTestApp:
	rts
	nop
LC21:
	.ascii "Got Host Display (before opening)\12Display Mode : %s\12Resolution   : %d x %d x %d [%s]\12Timing:      : %.2fkHz / %.2f Hz\12\12\0"
LC22:
	.ascii "Got Host Display (after opening)\12Display Mode : %s\12Resolution   : %hd x %hd x %d [%s]\12Timing:      : %.2fkHz / %.2f Hz\12\0"
LC23:
	.ascii "Window Geometry (in screen space)\0"
LC24:
	.ascii "ViewPort Geometry (in screen space)\0"
LC25:
	.ascii "Caught unexpected %s\12\0"
	.even
.globl _testWindowed__15GraphicsTestApp
_testWindowed__15GraphicsTestApp:
	link a5,#-84
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-80)
	movel d0,a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L717,a5@(-12)
	movel sp,a5@(-8)
	jra L716
	.even
L717:
	jra L735
	.even
L716:
	lea a5@(-24),a1
	movel a1,a0@
	clrl d0
	jeq L718
	clrl sp@-
	movel a5@(-80),a0
	addql #4,a0
	movel a0,a5@(-84)
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
	movew 2:w,a1
	movel a1,sp@-
	movew 0:w,a0
	movel a0,sp@-
	pea 28:w
	pea LC22
	jbsr _printf
	addw #40,sp
	movel #LC23,sp@
	jbsr _puts
	pea LC24
	jbsr _puts
	pea 300:w
	jbsr _Delay
	pea LC23
	jbsr _puts
	pea LC24
	jbsr _puts
	addw #20,sp
L718:
	movel a5@(-80),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jra L734
	.even
L735:
L714:
	pea ___tfQ25Error7Runtime
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L725
	jbsr ___start_cp_handler
	movel d0,a5@(-76)
	movel a5@(-84),a1
	movel a1@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L729,a5@(-36)
	movel sp,a5@(-32)
	jra L728
	.even
L729:
	jra L736
	.even
L728:
	lea a5@(-48),a1
	movel a5@(-84),a0
	movel a1,a0@
	movel a5@(-76),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC25
	jbsr _printf
	movel a5@(-84),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a5@(-76),sp@
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L734
	.even
L725:
	jbsr ___sjthrow
	.even
L736:
L726:
	movel a5@(-84),a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L733,a5@(-60)
	movel sp,a5@(-56)
	jra L732
	.even
L733:
	jra L737
	.even
L732:
	lea a5@(-72),a0
	movel a5@(-84),a1
	movel a0,a1@
	movel a5@(-76),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-84),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L737:
L730:
	jbsr ___terminate
	.even
L734:
	moveml a5@(-196),#0x5cfc
	fmovem a5@(-156),#0x3f
	unlk a5
	rts
LC26:
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
	pea LC26
	jbsr _printf
	addw #20,sp
	rts
	nop
LC27:
	.ascii "Unknown\0"
LC28:
	.ascii "Bit\0"
LC29:
	.ascii "Bitfield\0"
LC30:
	.ascii "Byte\0"
LC31:
	.ascii "Word16\0"
LC32:
	.ascii "Word32\0"
LC33:
	.ascii "Word64\0"
LC34:
	.ascii "Word128\0"
.data
	.even
_wordTypes.936:
	.long LC27
	.long LC28
	.long LC29
	.long LC30
	.long LC31
	.long LC32
	.long LC33
	.long LC34
.text
LC35:
	.ascii "Red\0"
LC36:
	.ascii "Green\0"
LC37:
	.ascii "Blue\0"
LC38:
	.ascii "Alpha\0"
LC39:
	.ascii "Cyan\0"
LC40:
	.ascii "Yellow\0"
LC41:
	.ascii "Magenta\0"
LC42:
	.ascii "Black\0"
LC43:
	.ascii "Hue\0"
LC44:
	.ascii "Saturation\0"
LC45:
	.ascii "Value\0"
LC46:
	.ascii "Luminance\0"
LC47:
	.ascii "Custom_0\0"
LC48:
	.ascii "Custom_1\0"
LC49:
	.ascii "Custom_2\0"
LC50:
	.ascii "Custom_3\0"
.data
	.even
_componentNames.937:
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
	.long LC49
	.long LC50
.text
LC51:
	.ascii " byteswapped\0"
LC52:
	.ascii "\0"
LC53:
	.ascii " float\0"
LC54:
	.ascii "Pixel Layout\12Total size     :  %u bytes\12Access Type    :  %s%s%s\12Component Type :  %s\12Num Components :  %u\12\0"
LC55:
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
	lea _wordTypes.936,a0
	movel a0@(d0:l:4),sp@-
	movel a3@,d0
	movel #LC52,d2
	movel d2,d1
	btst #16,d0
	jeq L746
	movel #LC51,d1
L746:
	movel d1,sp@-
	movel d2,d1
	btst #17,d0
	jeq L749
	movel #LC53,d1
L749:
	movel d1,sp@-
	clrl d0
	moveb a3@(9),d0
	movel a0@(d0:l:4),sp@-
	clrl d0
	moveb a3@(11),d0
	movel d0,sp@-
	pea LC54
	lea _printf,a2
	jbsr a2@
	addw #28,sp
	clrl d2
	tstb a3@(10)
	jeq L760
	clrl d3
	.even
L757:
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
	lea _componentNames.937,a0
	movel a0@(d0:l:4),sp@-
	pea LC55
	jbsr a2@
	addw #32,sp
	addql #1,d2
	moveb a3@(10),d3
	cmpl d2,d3
	jhi L757
L760:
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
LC56:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC57:
	.ascii "15GraphicsTestApp\0"
	.even
.globl ___tf15GraphicsTestApp
___tf15GraphicsTestApp:
	movel a2,sp@-
	lea ___ti15GraphicsTestApp,a2
	tstl a2@
	jne L763
	jbsr ___tf11Application
	pea 1:w
	pea LC56
	pea LC57
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L763:
	movel a2,d0
	movel sp@+,a2
	rts
