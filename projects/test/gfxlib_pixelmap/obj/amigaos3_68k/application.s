#NO_APP
.globl __7TestApp$formatNames
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
__7TestApp$formatNames:
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
	pea 10:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L557,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L556
	.even
L557:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L554
	.even
L556:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___7TestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L553
	.even
L554:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L563,a5@(-36)
	movel sp,a5@(-32)
	jra L562
	.even
L563:
	jra L567
	.even
L562:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L565
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L565:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L567:
L560:
	jbsr ___terminate
	.even
L553:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L576
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L576:
	jbsr _done__8Graphicsv
	rts
	nop
	.even
.globl ___7TestApp
___7TestApp:
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
	movel #L582,sp@(200)
	movel sp,sp@(204)
L582:
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
	movel #L595,sp@(152)
	movel sp,sp@(156)
	movel a0,a1
L595:
	lea sp@(140),a2
	movel a2,a0@
	movel sp@(220),a0
	movel #___vt_7TestApp,a0@
	clrl a0@(6)
	movel a1@,a0
	movel a0@,a1@
	movel sp@(220),d0
	moveml sp@+,#0x7cfc
	fmovem sp@+,#0x3f
	addw #100,sp
	rts
	.even
.globl __$_7TestApp
__$_7TestApp:
	movel a2,sp@-
	movel sp@(8),a2
	movel #___vt_7TestApp,a2@
	movel a2@(6),a1
	tstl a1
	jeq L613
	movel a1@(4),a0
	pea 3:w
	movel a1,sp@-
	movel a0@(32),a0
	jbsr a0@
	addql #8,sp
L613:
	movel #___vt_8Runnable,a2@
	movel sp@(12),d0
	btst #0,d0
	jeq L619
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L619:
	movel sp@+,a2
	rts
LC16:
	.ascii "-img\0"
LC17:
	.ascii "ImageBuffer instance located at %p width %hd, height: %hd\12\0"
LC18:
	.ascii "Writing PPM\12\0"
LC19:
	.ascii "ram:test.ppm\0"
LC20:
	.ascii "P6\12%hd\12%hd\12"
	.ascii "255\12\0"
	.even
.globl _run__7TestApp
_run__7TestApp:
	addw #-220,sp
	moveml #0x3f3e,sp@-
	movel sp@(268),a6
	jbsr ___get_eh_context
	movel d0,d2
	pea 3:w
	clrl sp@-
	pea LC16
	jbsr _getArgString__7StartupPCcT1Us
	addw #12,sp
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	movel d0,sp@-
	jbsr _loadImage__11ImageLoaderPCcb
	movel d0,a0
	movel a0,a6@(6)
	addql #8,sp
	movew a0@(2),a1
	movel a1,sp@-
	movew a0@,a1
	movel a1,sp@-
	movel a0,sp@-
	pea LC17
	lea _printf,a2
	jbsr a2@
	movel a6@(6),a0
	movel a0@(4),a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	movel a6,sp@-
	jbsr _describePixelLayout__7TestAppPCQ25Pixel6Layout
	pea LC18
	jbsr a2@
	addw #32,sp
	movel d2,d0
	clrl sp@(118)
	clrl sp@(146)
	clrl sp@(134)
	movel d2,a0
	addql #4,a0
	movel a0@,sp@(82)
	clrl sp@(86)
	lea sp@(106),a1
	movel a1,sp@(90)
	movel #L628,sp@(94)
	movel sp,sp@(98)
L628:
	lea sp@(82),a1
	movel a1,a0@
	clrl sp@(256)
	movel d2,a2
	addql #4,a2
	movel a2@,a0
	movel a0@,a2@
	movel a2@,a0
	addql #4,a0
	movel a0@,sp@(46)
	movel #__$_Q32IO6Stream3Out,sp@(50)
	moveq #106,d2
	addl sp,d2
	movel d2,sp@(54)
	lea sp@(46),a1
	movel a1,a0@
	pea 2048:w
	clrl sp@-
	pea LC19
	movel d2,sp@-
	jbsr _open__Q32IO6Stream3OutPCcQ32IO6Stream9WriteModeUl
	movel a6@(6),a0
	addw #16,sp
	movew a0@(2),a1
	movel a1,sp@-
	movew a0@,a0
	movel a0,sp@-
	pea LC20
	movel d2,sp@-
	jbsr _writeText__Q32IO6Stream3OutPCce
	movel a6@(6),a0
	movel a0@(4),a1
	movel a0,sp@-
	movel a1@(20),a0
	jbsr a0@
	movel d0,a5
	movel a6@(6),a0
	movel a0@(4),a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,a0
	addw #24,sp
	clrl d0
	moveb a0@(11),d0
	movel a2,d5
	movel d2,d4
	moveq #1,d1
	cmpl d0,d1
	jne L642
	movel a5,a3
	movel a6@(6),sp@-
	jbsr _getPalette__11ImageBuffer
	movel d0,a4
	addql #4,sp
	movel a6@(6),a0
	movew a0@,d3
	muls a0@(2),d3
	subql #1,d3
	movel #_close__Q32IO6Stream3Out,d6
	movel #__$_Q32IO6Stream3Out,d7
	moveq #-1,d0
	cmpl d3,d0
	jeq L650
	clrl d2
	movel d3,d0
	notl d0
	moveq #3,d1
	andl d1,d0
	jeq L648
	cmpl d0,d1
	jle L683
	moveq #2,d1
	cmpl d0,d1
	jle L684
	pea 3:w
	moveb a5@+,d2
	pea a4@(1,d2:l:4)
	movel a5,a3
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addw #12,sp
	subql #1,d3
L684:
	pea 3:w
	moveb a3@+,d2
	pea a4@(1,d2:l:4)
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addw #12,sp
	subql #1,d3
L683:
	pea 3:w
	moveb a3@+,d2
	pea a4@(1,d2:l:4)
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addw #12,sp
	subql #1,d3
	moveq #-1,d0
	cmpl d3,d0
	jeq L650
	.even
L648:
	pea 3:w
	movel a3,a2
	moveb a2@+,d2
	pea a4@(1,d2:l:4)
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addqw #8,sp
	movel #3,sp@
	moveb a2@,d2
	pea a4@(1,d2:l:4)
	lea a3@(2),a2
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addqw #8,sp
	movel #3,sp@
	moveb a2@,d2
	pea a4@(1,d2:l:4)
	lea a3@(3),a2
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addqw #8,sp
	movel #3,sp@
	moveb a2@,d2
	pea a4@(1,d2:l:4)
	addql #4,a3
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addw #12,sp
	subql #4,d3
	moveq #-1,d1
	cmpl d3,d1
	jne L648
	jra L650
	.even
L642:
	moveq #3,d1
	cmpl d0,d1
	jne L651
	movel a6@(6),a0
	movew a0@,d0
	muls a0@(2),d0
	mulsl d0,d1
	movel d1,sp@-
	movel a5,sp@-
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addw #12,sp
	movel #_close__Q32IO6Stream3Out,d6
	movel #__$_Q32IO6Stream3Out,d7
	jra L650
	.even
L651:
	movel #_close__Q32IO6Stream3Out,d6
	movel #__$_Q32IO6Stream3Out,d7
	moveq #4,d1
	cmpl d0,d1
	jne L650
	lea a5@(1),a2
	movel a6@(6),a0
	movew a0@,d2
	muls a0@(2),d2
	subql #1,d2
	moveq #-1,d0
	cmpl d2,d0
	jeq L650
	movel d2,d0
	notl d0
	moveq #3,d1
	andl d1,d0
	jeq L660
	cmpl d0,d1
	jle L664
	moveq #2,d1
	cmpl d0,d1
	jle L665
	pea 3:w
	movel a2,sp@-
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	lea a5@(5),a2
	addw #12,sp
	subql #1,d2
L665:
	pea 3:w
	movel a2,sp@-
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addql #4,a2
	addw #12,sp
	subql #1,d2
L664:
	pea 3:w
	movel a2,sp@-
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addql #4,a2
	addw #12,sp
	subql #1,d2
	moveq #-1,d0
	cmpl d2,d0
	jeq L650
	.even
L660:
	pea 3:w
	movel a2,sp@-
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addqw #8,sp
	movel #3,sp@
	pea a2@(4)
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addqw #8,sp
	movel #3,sp@
	pea a2@(8)
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addqw #8,sp
	movel #3,sp@
	pea a2@(12)
	movel d4,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addw #16,a2
	addw #12,sp
	subql #4,d2
	moveq #-1,d1
	cmpl d2,d1
	jne L660
L650:
	movel a6@(6),a0
	movel a0@(4),a1
	movel a0,sp@-
	movel a1@(24),a0
	jbsr a0@
	movel d4,sp@-
	movel d6,a0
	jbsr a0@
	movel d5,a0
	movel a0@,a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	pea 2:w
	movel d4,sp@-
	movel d7,a1
	jbsr a1@
	addql #8,sp
	clrl d0
	addql #8,sp
	moveml sp@+,#0x7cfc
	addw #220,sp
	rts
LC21:
	.ascii "Unknown\0"
LC22:
	.ascii "Bit\0"
LC23:
	.ascii "Unsigned Bitfield\0"
LC24:
	.ascii "Signed Bitfield\0"
LC25:
	.ascii "Unsigned Byte\0"
LC26:
	.ascii "Signed Byte\0"
LC27:
	.ascii "Unsigned 16-bit Word\0"
LC28:
	.ascii "Signed 16-bit Word\0"
LC29:
	.ascii "Float 16-bit Word (half precision)\0"
LC30:
	.ascii "Unsigned 32-bit Word\0"
LC31:
	.ascii "Signed 32-bit Word\0"
LC32:
	.ascii "Float 32-bit Word\0"
LC33:
	.ascii "Unsigned 64-bit Word\0"
LC34:
	.ascii "Signed 64-bit Word\0"
LC35:
	.ascii "Float 64-bit Word (double precision)\0"
LC36:
	.ascii "Unsigned 128-bit Word\0"
LC37:
	.ascii "Signed 128-bit Word\0"
LC38:
	.ascii "Float 128-bit Word (quad precision)\0"
.data
	.even
_wordTypes.729:
	.long LC21
	.long LC22
	.long LC23
	.long LC24
	.long LC25
	.long LC26
	.long LC27
	.long LC28
	.long LC29
	.long LC30
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
_componentNames.730:
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
.globl _describePixelLayout__7TestAppPCQ25Pixel6Layout
_describePixelLayout__7TestAppPCQ25Pixel6Layout:
	moveml #0x3030,sp@-
	movel sp@(24),a3
	clrl d0
	moveb a3@(10),d0
	movel d0,sp@-
	clrl d0
	moveb a3@(8),d0
	lea _wordTypes.729,a0
	movel a0@(d0:l:4),sp@-
	movel a3@,d0
	movel #LC56,d2
	movel d2,d1
	btst #16,d0
	jeq L703
	movel #LC55,d1
L703:
	movel d1,sp@-
	movel d2,d1
	btst #17,d0
	jeq L706
	movel #LC57,d1
L706:
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
	jeq L717
	clrl d3
	.even
L714:
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
	lea _componentNames.730,a0
	movel a0@(d0:l:4),sp@-
	pea LC59
	jbsr a2@
	addw #32,sp
	addql #1,d2
	moveb a3@(10),d3
	cmpl d2,d3
	jhi L714
L717:
	moveml sp@+,#0xc0c
	rts
.globl ___vt_7TestApp
	.even
___vt_7TestApp:
	.long 0
	.long ___tf7TestApp
	.long __dfRTTI__11Application
	.long _run__7TestApp
	.long __$_7TestApp
	.skip 4
.comm ___ti7TestApp,16
	.even
LC60:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC61:
	.ascii "7TestApp\0"
	.even
.globl ___tf7TestApp
___tf7TestApp:
	movel a2,sp@-
	lea ___ti7TestApp,a2
	tstl a2@
	jne L720
	jbsr ___tf11Application
	pea 1:w
	pea LC60
	pea LC61
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L720:
	movel a2,d0
	movel sp@+,a2
	rts
