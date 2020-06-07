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
	movel #L645,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L644
	.even
L645:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L642
	.even
L644:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___15GraphicsTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L641
	.even
L642:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L651,a5@(-36)
	movel sp,a5@(-32)
	jra L650
	.even
L651:
	jra L655
	.even
L650:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L653
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L653:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L655:
L648:
	jbsr ___terminate
	.even
L641:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L664
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L664:
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
	movel #L670,sp@(200)
	movel sp,sp@(204)
L670:
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
	movel #L683,sp@(152)
	movel sp,sp@(156)
	movel a0,a1
L683:
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
	jeq L705
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L705:
	rts
	nop
	.even
.globl _run__15GraphicsTestApp
_run__15GraphicsTestApp:
	movel sp@(4),sp@-
	jbsr _testWindowed__15GraphicsTestApp
	clrl d0
	addql #4,sp
	rts
	nop
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
LC16:
	.ascii "Got Host Display (before opening)\12Display Mode : %s\12Resolution   : %d x %d x %d [%s]\12Timing:      : %.2fkHz / %.2f Hz\12\12\0"
LC17:
	.ascii "Display::Windowed test instance - drag me a bit\0"
LC18:
	.ascii "Got Host Display (after opening)\12Display Mode : %s\12Resolution   : %hd x %hd x %d [%s]\12Timing:      : %.2fkHz / %.2f Hz\12\0"
LC19:
	.ascii "Window Geometry (in screen space)\0"
LC20:
	.ascii "ViewPort Geometry (in screen space)\0"
LC21:
	.ascii "Caught unexpected %s\12\0"
	.even
.globl _testWindowed__15GraphicsTestApp
_testWindowed__15GraphicsTestApp:
	link a5,#-676
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-670)
	clrl sp@-
	clrl sp@-
	pea 15:w
	movel #132095,sp@-
	pea 3:w
	pea 63:w
	pea 1:w
	movel a5,d0
	addl #-570,d0
	movel d0,sp@-
	jbsr ___Q27Display8WindowediUlUlUlUlss
	movel a5@(-670),a0
	addql #4,a0
	movel a0,a5@(-658)
	movel a0@,a0
	addql #4,a0
	movel a0@,a5@(-582)
	movel #__$_Q27Display8Windowed,a5@(-578)
	lea a5@(-570),a1
	movel a1,a5@(-574)
	lea a5@(-582),a1
	movel a1,a0@
	addw #32,sp
	pea a5@(-562)
	movel a5@(-658),a5@(-674)
	jbsr _getDisplayProperties__Q211EXNGPrivate10OSWindowed
	movel d0,a5@(-662)
	addql #4,sp
	jeq L711
	movel d0,sp@-
	jbsr _getVerticalRefreshRateHz__CQ27Display10Properties
	movel d1,sp@-
	movel d0,sp@-
	movel a5@(-662),sp@-
	jbsr _getHorizontalRefreshRatekHz__CQ27Display10Properties
	addql #4,sp
	movel d1,sp@-
	movel d0,sp@-
	movel a5@(-662),a0
	movel a0@(24),d0
	lea __15GraphicsTestApp$formatNames,a0
	movel a0@(d0:l:4),sp@-
	movel a5@(-662),a1
	movel a1@(20),sp@-
	movew a1@(2),a0
	movel a0,sp@-
	movew a1@,a1
	movel a1,sp@-
	movel a5@(-662),a0
	pea a0@(28)
	pea LC16
	jbsr _printf
	addw #44,sp
L711:
	movel a5@(-674),a1
	movel a1@,a5@(-606)
	clrl a5@(-602)
	lea a5@(-598),a0
	movel a5,a0@
	movel #L720,a0@(4)
	movel sp,a0@(8)
	jra L719
	.even
L720:
	movel a5@(-670),a0
	addql #4,a0
	movel a0,a5@(-674)
	jra L717
	.even
L719:
	lea a5@(-606),a0
	movel a5@(-658),a1
	movel a0,a1@
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	pea LC17
	pea a5@(-562)
	jbsr _setDisplayTitle__Q211EXNGPrivate9OSDisplayPCcb
	addqw #8,sp
	movel #480,sp@
	pea 640:w
	clrl sp@-
	clrl sp@-
	pea a5@(-570)
	jbsr _openWindow__Q27Display8Windowedssss
	addw #20,sp
	pea a5@(-562)
	jbsr _getDisplayProperties__Q211EXNGPrivate10OSWindowed
	movel d0,a5@(-662)
	addql #4,sp
	jeq L723
	movel d0,sp@-
	jbsr _getVerticalRefreshRateHz__CQ27Display10Properties
	movel d1,sp@-
	movel d0,sp@-
	movel a5@(-662),sp@-
	jbsr _getHorizontalRefreshRatekHz__CQ27Display10Properties
	addql #4,sp
	movel d1,sp@-
	movel d0,sp@-
	movel a5@(-662),a1
	movel a1@(24),d0
	lea __15GraphicsTestApp$formatNames,a0
	movel a0@(d0:l:4),sp@-
	movel a1@(20),sp@-
	movew a1@(2),a0
	movel a0,sp@-
	movew a1@,a1
	movel a1,sp@-
	movel a5@(-662),a0
	pea a0@(28)
	pea LC18
	jbsr _printf
	addw #40,sp
	movel #LC19,sp@
	jbsr _puts
	pea a5@(-570)
	jbsr _getFrameRect__Q27Display8Windowed
	movel d0,sp@-
	movel a5@(8),sp@-
	jbsr _printGfxRect__15GraphicsTestAppRC7GfxRect
	pea LC20
	jbsr _puts
	pea a5@(-570)
	jbsr _getViewPortRect__Q27Display8Windowed
	movel d0,sp@-
	movel a5@(8),sp@-
	jbsr _printGfxRect__15GraphicsTestAppRC7GfxRect
	addw #28,sp
	movel #300,sp@
	jbsr _Delay
	pea LC19
	jbsr _puts
	pea a5@(-570)
	jbsr _getFrameRect__Q27Display8Windowed
	movel d0,sp@-
	movel a5@(8),sp@-
	jbsr _printGfxRect__15GraphicsTestAppRC7GfxRect
	pea LC20
	jbsr _puts
	pea a5@(-570)
	jbsr _getViewPortRect__Q27Display8Windowed
	movel d0,sp@-
	movel a5@(8),sp@-
	jbsr _printGfxRect__15GraphicsTestAppRC7GfxRect
	addw #36,sp
L723:
	movel a5@(-674),a1
	movel a1@,a0
	movel a0@,a1@
L729:
	movel a5@(-674),a0
	movel a0@,a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	pea 2:w
	pea a5@(-570)
	jbsr __$_Q27Display8Windowed
	addql #8,sp
	jra L739
	.even
L717:
	pea ___tfQ25Error7Runtime
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L730
	jbsr ___start_cp_handler
	movel d0,a5@(-666)
	movel a5@(-674),a1
	movel a1@,a5@(-630)
	clrl a5@(-626)
	lea a5@(-622),a0
	movel a5,a0@
	movel #L734,a0@(4)
	movel sp,a0@(8)
	jra L733
	.even
L734:
	movel a5@(-670),a0
	addql #4,a0
	movel a0,a5@(-674)
	jra L731
	.even
L733:
	lea a5@(-630),a0
	movel a5@(-674),a1
	movel a0,a1@
	movel a5@(-666),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC21
	jbsr _printf
	movel a5@(-674),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a5@(-666),sp@
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L729
	.even
L730:
	jbsr ___sjthrow
	.even
L731:
	movel a5@(-674),a0
	movel a0@,a5@(-654)
	clrl a5@(-650)
	lea a5@(-646),a0
	movel a5,a0@
	movel #L738,a0@(4)
	movel sp,a0@(8)
	jra L737
	.even
L738:
	jra L740
	.even
L737:
	lea a5@(-654),a0
	movel a5@(-674),a1
	movel a0,a1@
	movel a5@(-666),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-670),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L740:
L735:
	jbsr ___terminate
	.even
L739:
	moveml a5@(-788),#0x5cfc
	fmovem a5@(-748),#0x3f
	unlk a5
	rts
LC22:
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
	pea LC22
	jbsr _printf
	addw #20,sp
	rts
	nop
LC23:
	.ascii "Unknown\0"
LC24:
	.ascii "Bit\0"
LC25:
	.ascii "Bitfield\0"
LC26:
	.ascii "Byte\0"
LC27:
	.ascii "Word16\0"
LC28:
	.ascii "Word32\0"
LC29:
	.ascii "Word64\0"
LC30:
	.ascii "Word128\0"
.data
	.even
_wordTypes.993:
	.long LC23
	.long LC24
	.long LC25
	.long LC26
	.long LC27
	.long LC28
	.long LC29
	.long LC30
.text
LC31:
	.ascii "Red\0"
LC32:
	.ascii "Green\0"
LC33:
	.ascii "Blue\0"
LC34:
	.ascii "Alpha\0"
LC35:
	.ascii "Cyan\0"
LC36:
	.ascii "Yellow\0"
LC37:
	.ascii "Magenta\0"
LC38:
	.ascii "Black\0"
LC39:
	.ascii "Hue\0"
LC40:
	.ascii "Saturation\0"
LC41:
	.ascii "Value\0"
LC42:
	.ascii "Luminance\0"
LC43:
	.ascii "Custom_0\0"
LC44:
	.ascii "Custom_1\0"
LC45:
	.ascii "Custom_2\0"
LC46:
	.ascii "Custom_3\0"
.data
	.even
_componentNames.994:
	.long LC31
	.long LC32
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
.text
LC47:
	.ascii " byteswapped\0"
LC48:
	.ascii "\0"
LC49:
	.ascii " float\0"
LC50:
	.ascii "Pixel Layout\12Total size     :  %u bytes\12Access Type    :  %s%s%s\12Component Type :  %s\12Num Components :  %u\12\0"
LC51:
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
	lea _wordTypes.993,a0
	movel a0@(d0:l:4),sp@-
	movel a3@,d0
	movel #LC48,d2
	movel d2,d1
	btst #16,d0
	jeq L749
	movel #LC47,d1
L749:
	movel d1,sp@-
	movel d2,d1
	btst #17,d0
	jeq L752
	movel #LC49,d1
L752:
	movel d1,sp@-
	clrl d0
	moveb a3@(9),d0
	movel a0@(d0:l:4),sp@-
	clrl d0
	moveb a3@(11),d0
	movel d0,sp@-
	pea LC50
	lea _printf,a2
	jbsr a2@
	addw #28,sp
	clrl d2
	tstb a3@(10)
	jeq L763
	clrl d3
	.even
L760:
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
	lea _componentNames.994,a0
	movel a0@(d0:l:4),sp@-
	pea LC51
	jbsr a2@
	addw #32,sp
	addql #1,d2
	moveb a3@(10),d3
	cmpl d2,d3
	jhi L760
L763:
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
LC52:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC53:
	.ascii "15GraphicsTestApp\0"
	.even
.globl ___tf15GraphicsTestApp
___tf15GraphicsTestApp:
	movel a2,sp@-
	lea ___ti15GraphicsTestApp,a2
	tstl a2@
	jne L766
	jbsr ___tf11Application
	pea 1:w
	pea LC52
	pea LC53
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L766:
	movel a2,d0
	movel sp@+,a2
	rts
