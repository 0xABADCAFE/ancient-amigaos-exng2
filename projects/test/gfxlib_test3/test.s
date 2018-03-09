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
	pea 60:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L700,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L699
	.even
L700:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L697
	.even
L699:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___15GraphicsTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L696
	.even
L697:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L706,a5@(-36)
	movel sp,a5@(-32)
	jra L705
	.even
L706:
	jra L710
	.even
L705:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L708
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L708:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L710:
L703:
	jbsr ___terminate
	.even
L696:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L719
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L719:
	jbsr _done__8Graphics
	rts
	nop
LC0:
	.ascii "-depth\0"
LC1:
	.ascii "-width\0"
LC2:
	.ascii "-height\0"
LC3:
	.ascii "-window\0"
LC4:
	.ascii "Windowed mode specified\12\0"
LC5:
	.ascii "Fullscreen mode\12\0"
	.even
.globl ___15GraphicsTestApp
___15GraphicsTestApp:
	link a5,#-260
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
	movel #L725,a5@(-12)
	movel sp,a5@(-8)
L725:
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
	movel #L739,a5@(-60)
	movel sp,a5@(-56)
	movel a0,a5@(-260)
	jra L738
	.even
L739:
	jra L791
	.even
L738:
	lea a5@(-72),a1
	movel a1,a0@
	movel #459775,sp@-
	pea 3:w
	pea 63:w
	movel a5@(8),d0
	addql #6,d0
	movel d0,sp@-
	movel d0,a5@(-256)
	jbsr ___Q26HostUI8ObserverUlUlUl
	movel a5@(-260),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L743,a5@(-84)
	movel sp,a5@(-80)
	jra L742
	.even
L743:
	jra L792
	.even
L742:
	lea a5@(-96),a0
	movel a5@(-260),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_15GraphicsTestApp$Q23Key8Observer,a1@(18)
	movel #___vt_15GraphicsTestApp$Q25Mouse8Observer,a1@(30)
	movel #___vt_15GraphicsTestApp$Q26HostUI8Observer,a1@(10)
	movel #___vt_15GraphicsTestApp,a1@
	clrl a1@(42)
	clrb a1@(58)
	addw #12,sp
	movel #1,sp@
	pea 10:w
	pea 32:w
	clrl sp@-
	pea LC0
	jbsr _getArgInteger__7StartupPCcxUsUs
	addw #20,sp
	movel a5@(8),a0
	movel d1,a0@(50)
	pea 1:w
	pea 10:w
	pea 640:w
	clrl sp@-
	pea LC1
	jbsr _getArgInteger__7StartupPCcxUsUs
	addw #20,sp
	movel a5@(8),a1
	movew d1,a1@(54)
	pea 1:w
	pea 10:w
	pea 480:w
	clrl sp@-
	pea LC2
	jbsr _getArgInteger__7StartupPCcxUsUs
	addw #20,sp
	movel a5@(8),a0
	movew d1,a0@(56)
	pea 1:w
	pea LC3
	jbsr _getArgSwitch__7StartupPCcUs
	addql #8,sp
	tstb d0
	jeq L747
	pea LC4
	jbsr _printf
	pea 570:w
	jbsr ___builtin_new
	movel d0,a5@(-244)
	moveb #1,a5@(-245)
	movel a5@(-260),a1
	movel a1@,a5@(-120)
	clrl a5@(-116)
	movel a5,a5@(-112)
	movel #L752,a5@(-108)
	movel sp,a5@(-104)
	jra L751
	.even
L752:
	jra L793
	.even
L751:
	lea a5@(-120),a1
	movel a5@(-260),a0
	movel a1,a0@
	clrl sp@-
	clrl sp@-
	pea 15:w
	movel #132095,sp@-
	pea 3:w
	pea 63:w
	pea 1:w
	movel a5@(-244),sp@-
	jbsr ___Q27Display8WindowediUlUlUlUlss
	clrb a5@(-245)
	movel a5@(8),a0
	movel d0,a0@(42)
	movel a5@(-260),a1
	movel a1@,a0
	movel a0@,a1@
	addw #40,sp
	jra L755
	.even
L747:
	pea LC5
	jbsr _printf
	pea 390:w
	jbsr ___builtin_new
	movel d0,a5@(-250)
	moveb #1,a5@(-251)
	movel a5@(-260),a0
	movel a0@,a5@(-144)
	clrl a5@(-140)
	lea a5@(-136),a0
	movel a5,a0@
	movel #L759,a0@(4)
	movel sp,a5@(-128)
	jra L758
	.even
L759:
	jra L794
	.even
L758:
	lea a5@(-144),a0
	movel a5@(-260),a1
	movel a0,a1@
	movel #132095,sp@-
	pea 3:w
	pea 63:w
	pea 1:w
	movel a5@(-250),sp@-
	jbsr ___Q27Display10UnbufferediUlUlUl
	clrb a5@(-251)
	movel a5@(8),a1
	movel d0,a1@(42)
	movel a5@(-260),a1
	movel a1@,a0
	movel a0@,a1@
	addw #28,sp
L755:
	movel a5@(-256),sp@-
	movel a5@(8),a1
	movel a1@(42),a0
	movel a0@,sp@-
	jbsr _addHostUIObserver__Q26HostUI10DispatcherPQ26HostUI8Observer
	jbsr _createInstance__6Draw2D
	movel a5@(8),a0
	movel d0,a0@(46)
	addql #8,sp
	movel a5@(-260),a1
	movel a1@,a0
	movel a0@,a1@
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L790
	.even
L793:
L749:
	movel a5@(-260),a0
	movel a0@,a5@(-168)
	clrl a5@(-164)
	lea a5@(-160),a0
	movel a5,a0@
	movel #L766,a0@(4)
	movel sp,a0@(8)
	jra L765
	.even
L766:
	jra L795
	.even
L765:
	lea a5@(-168),a0
	movel a5@(-260),a1
	movel a0,a1@
	tstb a5@(-245)
	jeq L768
	movel a5@(-244),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L768:
	movel a5@(-260),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L794:
L756:
	movel a5@(-260),a0
	movel a0@,a5@(-192)
	clrl a5@(-188)
	lea a5@(-184),a0
	movel a5,a0@
	movel #L772,a0@(4)
	movel sp,a0@(8)
	jra L771
	.even
L772:
	jra L796
	.even
L771:
	lea a5@(-192),a0
	movel a5@(-260),a1
	movel a0,a1@
	tstb a5@(-251)
	jeq L774
	movel a5@(-250),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L774:
	movel a5@(-260),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L792:
L740:
	movel a5@(-260),a0
	movel a0@,a5@(-216)
	clrl a5@(-212)
	lea a5@(-208),a0
	movel a5,a0@
	movel #L778,a0@(4)
	movel sp,a0@(8)
	jra L777
	.even
L778:
	jra L797
	.even
L777:
	lea a5@(-216),a0
	movel a5@(-260),a1
	movel a0,a1@
	clrl sp@-
	movel a5@(-256),sp@-
	jbsr __$_Q26HostUI8Observer
	movel a5@(-260),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jbsr ___sjthrow
	.even
L791:
L736:
	movel a5@(-260),a0
	movel a0@,a5@(-240)
	clrl a5@(-236)
	lea a5@(-232),a0
	movel a5,a0@
	movel #L782,a0@(4)
	movel sp,a0@(8)
	jra L781
	.even
L782:
	jra L798
	.even
L781:
	lea a5@(-240),a0
	movel a5@(-260),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_8Runnable,a1@
	movel a5@(-260),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L795:
L763:
	jbsr ___terminate
	.even
L796:
L769:
	jbsr ___terminate
	.even
L797:
L775:
	jbsr ___terminate
	.even
L798:
L779:
	jbsr ___terminate
	.even
L790:
	moveml a5@(-372),#0x5cfc
	fmovem a5@(-332),#0x3f
	unlk a5
	rts
	.even
.globl __$_15GraphicsTestApp
__$_15GraphicsTestApp:
	movel a2,sp@-
	movel sp@(8),a2
	movel #___vt_15GraphicsTestApp$Q23Key8Observer,a2@(18)
	movel #___vt_15GraphicsTestApp$Q25Mouse8Observer,a2@(30)
	movel #___vt_15GraphicsTestApp$Q26HostUI8Observer,a2@(10)
	movel #___vt_15GraphicsTestApp,a2@
	movel a2@(46),a1
	tstl a1
	jeq L801
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(116),a0
	jbsr a0@
	addql #8,sp
L801:
	movel a2@(42),a1
	tstl a1
	jeq L804
	movel a1@,a0
	movel a0@(12),a0
	pea 3:w
	movel a1@,a1
	addql #8,a1
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L804:
	clrl sp@-
	pea a2@(6)
	jbsr __$_Q26HostUI8Observer
	addql #8,sp
	movel #___vt_8Runnable,a2@
	movel sp@(12),d0
	btst #0,d0
	jeq L810
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L810:
	movel sp@+,a2
	rts
LC6:
	.ascii "GraphicsTestApp\0"
LC7:
	.ascii "-pal\0"
LC8:
	.ascii "Caught unexpected %s [%s]\12\0"
LC9:
	.ascii "Caught unexpected %s\12\0"
	.even
.globl _run__15GraphicsTestApp
_run__15GraphicsTestApp:
	link a5,#-168
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-164)
	movel a5@(8),a0
	clrb a0@(58)
	movel a5@(-164),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L815,a5@(-12)
	movel sp,a5@(-8)
	jra L814
	.even
L815:
	jra L884
	.even
L814:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a2
	movel a2@(42),a0
	movel a0@(4),a1
	pea LC6
	movel a0,sp@-
	movel a1@(12),a0
	movel a5@(-164),a1
	addql #4,a1
	movel a1,a5@(-168)
	jbsr a0@
	movel a2@(42),a0
	movel a0@(4),a1
	pea 273:w
	movel a2@(50),sp@-
	movew a2@(56),a2
	movel a2,sp@-
	movel a5@(8),a2
	movew a2@(54),a2
	movel a2,sp@-
	movel a0,sp@-
	movel a1@(48),a0
	jbsr a0@
	addw #28,sp
	moveq #8,d0
	movel a5@(8),a0
	cmpl a0@(50),d0
	jcs L816
	pea 1:w
	pea 10:w
	clrl sp@-
	clrl sp@-
	pea LC7
	jbsr _getArgInteger__7StartupPCcxUsUs
	addw #20,sp
	movel a5@(8),a1
	movel a1@(42),a0
	movel a0@(4),a5@(-140)
	movel d1,sp@-
	jbsr _getPresetPalette__7PaletteQ27Palette6Preset
	movel d0,sp@-
	movel a5@(8),a2
	movel a2@(42),sp@-
	movel a5@(-140),a1
	movel a1@(40),a0
	jbsr a0@
	addw #12,sp
L816:
	movel a5@(8),a2
	movel a2@(42),a0
	movel a0@(4),a1
	movel a0,sp@-
	movel a1@(44),a0
	movel a5@(-164),a1
	addql #4,a1
	movel a1,a5@(-168)
	jbsr a0@
	movel d0,a5@(-144)
	addql #4,sp
	jeq L818
	movel a2@(46),a0
	movel a0@,a1
	movel d0,sp@-
	movel a0,sp@-
	movel a1@(16),a0
	jbsr a0@
	movel a2@(46),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(52),a0
	jbsr a0@
	addw #12,sp
	movel #-6710887,a5@(-124)
	movel a2@(46),a0
	movel a0@,a1
	movel a5@(-124),sp@-
	movel a5@(-144),a2
	movew a2@(2),a2
	movel a2,sp@-
	movel a5@(-144),a2
	movew a2@,a2
	movel a2,sp@-
	clrl sp@-
	clrl sp@-
	movel a0,sp@-
	movel a1@(96),a0
	jbsr a0@
	movel #-16777216,a5@(-148)
	clrw a5@(-150)
	addw #24,sp
	jra L885
	.even
L826:
	movel a5@(-148),a5@(-128)
	movel a5@(8),a2
	movel a2@(46),a0
	movel a0@,a1
	movel a5@(-148),sp@-
	movel a5@(-144),a2
	movew a2@(2),d0
	subw a5@(-150),d0
	movew d0,a2
	movel a2,sp@-
	movel a5@(-144),a2
	movew a2@,a2
	movel a2,sp@-
	movew a5@(-150),a2
	movel a2,sp@-
	clrl sp@-
	movel a0,sp@-
	movel a1@(64),a0
	jbsr a0@
	addl #196608,a5@(-148)
	addw #24,sp
	addqw #4,a5@(-150)
L885:
	movel a5@(-144),a1
	movew a1@(2),a0
	movel a0,d0
	cmpw a5@(-150),d0
	jge L826
	movel a5@(8),a2
	movel a2@(46),a0
	movel a0@,a1
	addw #-64,d0
	movew d0,a2
	movel a2,sp@-
	movel a5@(-144),a2
	movew a2@,d0
	addw #-64,d0
	movew d0,a2
	movel a2,sp@-
	pea 64:w
	pea 64:w
	movel a0,sp@-
	movel a1@(24),a0
	jbsr a0@
	addw #20,sp
	movel #-16777089,a5@(-132)
	movel a5@(8),a1
	movel a1@(46),a0
	movel a0@,a1
	movel a5@(-132),sp@-
	movel a5@(-144),a2
	movew a2@(2),a2
	movel a2,sp@-
	movel a5@(-144),a2
	movew a2@,a2
	movel a2,sp@-
	clrl sp@-
	clrl sp@-
	movel a0,sp@-
	movel a1@(96),a0
	jbsr a0@
	movel #-16777216,a5@(-148)
	clrw a5@(-152)
	addw #24,sp
	jra L886
	.even
L842:
	movel a5@(-148),a5@(-136)
	movel a5@(8),a1
	movel a1@(46),a0
	movel a0@,a1
	movel a5@(-148),sp@-
	movel a5@(-144),a2
	movew a2@(2),a2
	movel a2,sp@-
	movel a5@(-144),a2
	movew a2@,d0
	subw a5@(-152),d0
	movew d0,a2
	movel a2,sp@-
	clrl sp@-
	movew a5@(-152),a2
	movel a2,sp@-
	movel a0,sp@-
	movel a1@(64),a0
	jbsr a0@
	addl #768,a5@(-148)
	addw #24,sp
	addqw #4,a5@(-152)
L886:
	movew a5@(-152),d0
	movel a5@(-144),a0
	cmpw a0@,d0
	jle L842
	movel a5@(8),a1
	movel a1@(46),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(56),a0
	jbsr a0@
	movel a5@(8),a2
	movel a2@(42),a0
	movel a0@(4),a1
	movel a0,sp@-
	movel a1@(32),a0
	jbsr a0@
	addql #8,sp
L818:
	movel a5@(8),a0
	tstb a0@(58)
	jne L850
	.even
L851:
	movel a5@(8),a1
	movel a1@(42),a0
	movel a0@(4),a1
	movel a0,sp@-
	movel a1@(52),a0
	jbsr a0@
	addql #4,sp
	moveq #4,d1
	cmpl d0,d1
	jne L852
	movel a5@(8),a0
	moveb #1,a0@(58)
	jra L849
	.even
L852:
	movel a5@(8),a1
	movel a1@(42),a0
	movel a0@(4),a1
	movel a0,sp@-
	movel a1@(56),a0
	jbsr a0@
	addql #4,sp
L849:
	movel a5@(8),a2
	tstb a2@(58)
	jeq L851
L850:
	movel a5@(-168),a1
	movel a1@,a0
	movel a0@,a1@
L855:
	clrl d0
	jra L878
	.even
L884:
L812:
	pea ___tfQ25Error8Resource
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L863
	jbsr ___start_cp_handler
	movel d0,a5@(-156)
	movel a5@(-168),a2
	movel a2@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L860,a5@(-36)
	movel sp,a5@(-32)
	jra L859
	.even
L860:
	jra L887
	.even
L859:
	lea a5@(-48),a1
	movel a5@(-168),a0
	movel a1,a0@
	movel a5@(-156),a2
	movel a2@(8),a0
	movel a0@(4),sp@-
	movel a0@,a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@
	pea LC8
	jbsr _printf
	jra L888
	.even
L863:
	pea ___tfQ25Error7Runtime
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L864
	jbsr ___start_cp_handler
	movel d0,a5@(-160)
	movel a5@(-168),a2
	movel a2@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L868,a5@(-60)
	movel sp,a5@(-56)
	jra L867
	.even
L868:
	jra L889
	.even
L867:
	lea a5@(-72),a1
	movel a5@(-168),a0
	movel a1,a0@
	movel a5@(-160),a2
	movel a2@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC9
	jbsr _printf
L888:
	movel a5@(-168),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a2,sp@
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L855
	.even
L864:
	jbsr ___sjthrow
	.even
L887:
L857:
	movel a5@(-168),a2
	movel a2@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L872,a5@(-84)
	movel sp,a5@(-80)
	jra L871
	.even
L872:
	jra L890
	.even
L871:
	lea a5@(-96),a1
	movel a5@(-168),a0
	movel a1,a0@
	movel a5@(-156),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-168),a2
	movel a2@,a0
	movel a0@,a2@
	addql #4,sp
	jbsr ___sjthrow
	.even
L889:
L865:
	movel a5@(-168),a0
	movel a0@,a5@(-120)
	clrl a5@(-116)
	movel a5,a5@(-112)
	movel #L876,a5@(-108)
	movel sp,a5@(-104)
	jra L875
	.even
L876:
	jra L891
	.even
L875:
	lea a5@(-120),a2
	movel a5@(-168),a1
	movel a2,a1@
	movel a5@(-160),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-168),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L890:
L869:
	jbsr ___terminate
	.even
L891:
L873:
	jbsr ___terminate
	.even
L878:
	moveml a5@(-280),#0x5cfc
	fmovem a5@(-240),#0x3f
	unlk a5
	rts
LC10:
	.ascii "HostUI::Observer::displayClosed(%p)\12\0"
	.even
.globl _displayClosed__15GraphicsTestAppPCQ26HostUI10Dispatcher
_displayClosed__15GraphicsTestAppPCQ26HostUI10Dispatcher:
	movel sp@(8),sp@-
	pea LC10
	jbsr _printf
	addql #8,sp
	rts
	nop
LC11:
	.ascii "HostUI::Observer::displayMoved(%p)\12\0"
	.even
.globl _displayMoved__15GraphicsTestAppPCQ26HostUI10Dispatcher
_displayMoved__15GraphicsTestAppPCQ26HostUI10Dispatcher:
	movel sp@(8),sp@-
	pea LC11
	jbsr _printf
	addql #8,sp
	rts
	nop
LC12:
	.ascii "HostUI::Observer::displayResized(%p)\12\0"
	.even
.globl _displayResized__15GraphicsTestAppPCQ26HostUI10Dispatcher
_displayResized__15GraphicsTestAppPCQ26HostUI10Dispatcher:
	movel sp@(8),sp@-
	pea LC12
	jbsr _printf
	addql #8,sp
	rts
	nop
LC13:
	.ascii "HostUI::Observer::displayMinimized(%p)\12\0"
	.even
.globl _displayMinimized__15GraphicsTestAppPCQ26HostUI10Dispatcher
_displayMinimized__15GraphicsTestAppPCQ26HostUI10Dispatcher:
	movel sp@(8),sp@-
	pea LC13
	jbsr _printf
	addql #8,sp
	rts
	nop
LC14:
	.ascii "HostUI::Observer::displayFocus(%p)\12\0"
	.even
.globl _displayFocus__15GraphicsTestAppPCQ26HostUI10Dispatcher
_displayFocus__15GraphicsTestAppPCQ26HostUI10Dispatcher:
	movel sp@(8),sp@-
	pea LC14
	jbsr _printf
	addql #8,sp
	rts
	nop
LC15:
	.ascii "HostUI::Observer::displayBlur(%p)\12\0"
	.even
.globl _displayBlur__15GraphicsTestAppPCQ26HostUI10Dispatcher
_displayBlur__15GraphicsTestAppPCQ26HostUI10Dispatcher:
	movel sp@(8),sp@-
	pea LC15
	jbsr _printf
	addql #8,sp
	rts
	nop
LC16:
	.ascii "Mouse::Observer::buttonPressed(%p, 0x%08X)\12\0"
	.even
.globl _buttonPressed__15GraphicsTestAppPCQ25Mouse10DispatcherQ25Mouse6Button
_buttonPressed__15GraphicsTestAppPCQ25Mouse10DispatcherQ25Mouse6Button:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	pea LC16
	jbsr _printf
	addw #12,sp
	rts
	nop
LC17:
	.ascii "Mouse::Observer::buttonReleased(%p, 0x%08X)\12\0"
	.even
.globl _buttonReleased__15GraphicsTestAppPCQ25Mouse10DispatcherQ25Mouse6Button
_buttonReleased__15GraphicsTestAppPCQ25Mouse10DispatcherQ25Mouse6Button:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	pea LC17
	jbsr _printf
	addw #12,sp
	rts
	nop
LC18:
	.ascii "Mouse::Observer::drag(%p, %hd, %hd, %hd, %hd, 0x%08X)\12\0"
	.even
.globl _drag__15GraphicsTestAppPCQ25Mouse10DispatcherssssUl
_drag__15GraphicsTestAppPCQ25Mouse10DispatcherssssUl:
	movel sp@(28),sp@-
	movew sp@(30),a0
	movel a0,sp@-
	movew sp@(30),a0
	movel a0,sp@-
	movew sp@(30),a0
	movel a0,sp@-
	movew sp@(30),a0
	movel a0,sp@-
	movel sp@(28),sp@-
	pea LC18
	jbsr _printf
	addw #28,sp
	rts
	nop
LC19:
	.ascii "Mouse events mask = 0x%08X\12\0"
LC20:
	.ascii "Got Host Display (before opening)\12Display Mode : %s\12Resolution   : %d x %d x %d\12Timing:      : %.2fkHz / %.2f Hz\12\12\0"
LC21:
	.ascii "Key::Observer::nonPrintablePressed(%p, 0x%02X)\12\0"
	.even
.globl _nonPrintablePressed__15GraphicsTestAppPCQ23Key10DispatcherQ23Key7CtrlKey
_nonPrintablePressed__15GraphicsTestAppPCQ23Key10DispatcherQ23Key7CtrlKey:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a0
	movel sp@(20),d1
	moveq #-10,d0
	addl d1,d0
	moveq #9,d2
	cmpl d0,d2
	jcs L920
LI921:
	movew pc@(L921-LI921-2:b,d0:l:2),d0
	jmp pc@(2,d0:w)
	.even
L921:
	.word L903-L921
	.word L904-L921
	.word L905-L921
	.word L906-L921
	.word L907-L921
	.word L908-L921
	.word L909-L921
	.word L910-L921
	.word L911-L921
	.word L914-L921
	.even
L903:
	movel #1048576,sp@-
	jra L923
	.even
L904:
	movel #1048576,sp@-
	jra L924
	.even
L905:
	movel #2097152,sp@-
	jra L923
	.even
L906:
	movel #2097152,sp@-
	jra L924
	.even
L907:
	movel #4194304,sp@-
	jra L923
	.even
L908:
	movel #4194304,sp@-
	jra L924
	.even
L909:
	movel #8388608,sp@-
L923:
	movel a0@(42),a0
	moveq #36,d0
	addl a0@,d0
	movel d0,sp@-
	jbsr _enableMouseEvents__Q25Mouse6FilterUl
	addql #8,sp
	jra L922
	.even
L910:
	movel #8388608,sp@-
L924:
	movel a0@(42),a0
	moveq #36,d2
	addl a0@,d2
	movel d2,sp@-
	jbsr _disableMouseEvents__Q25Mouse6FilterUl
	addql #8,sp
	jra L922
	.even
L911:
	movel a0@(42),a0
	movel a0@,a0
	addw #36,a0
	movel a0@,sp@-
	pea LC19
	jbsr _printf
	addql #8,sp
	jra L922
	.even
L914:
	movel a0@(42),a0
	movel a0@(4),a1
	movel a0,sp@-
	movel a1@(8),a0
	jbsr a0@
	movel d0,a2
	addql #4,sp
	tstl a2
	jeq L922
	movel a2,sp@-
	jbsr _getVerticalRefreshRateHz__CQ27Display10Properties
	movel d1,sp@-
	movel d0,sp@-
	movel a2,sp@-
	jbsr _getHorizontalRefreshRatekHz__CQ27Display10Properties
	addql #4,sp
	movel d1,sp@-
	movel d0,sp@-
	movel a2@(20),sp@-
	movew a2@(2),a0
	movel a0,sp@-
	movew a2@,a0
	movel a0,sp@-
	pea a2@(28)
	pea LC20
	jbsr _printf
	addw #40,sp
	jra L922
	.even
L920:
	movel d1,sp@-
	movel sp@(20),sp@-
	pea LC21
	jbsr _printf
	addw #12,sp
L922:
	movel sp@+,d2
	movel sp@+,a2
	rts
LC22:
	.ascii "Key::Observer::printablePressed(%p, '%c')\12\0"
	.even
.globl _printablePressed__15GraphicsTestAppPCQ23Key10Dispatcherl
_printablePressed__15GraphicsTestAppPCQ23Key10Dispatcherl:
	movel d2,sp@-
	movel sp@(16),d2
	movel d2,sp@-
	movel sp@(16),sp@-
	pea LC22
	jbsr _printf
	addw #12,sp
	moveq #113,d0
	cmpl d2,d0
	jeq L927
	moveq #81,d0
	cmpl d2,d0
	jne L928
L927:
	movel sp@(8),a0
	moveb #1,a0@(58)
L928:
	movel sp@+,d2
	rts
	.even
___thunk_20__dfRTTI__Q26HostUI8Observer:
	moveq #-20,d0
	addl sp@(4),d0
	movel d0,sp@-
	jbsr __dfRTTI__Q26HostUI8Observer
	addql #4,sp
	rts
	nop
	.even
___thunk_26_buttonPressed__15GraphicsTestAppPCQ25Mouse10DispatcherQ25Mouse6Button:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	moveq #-26,d0
	addl sp@(12),d0
	movel d0,sp@-
	jbsr _buttonPressed__15GraphicsTestAppPCQ25Mouse10DispatcherQ25Mouse6Button
	addw #12,sp
	rts
	nop
	.even
___thunk_26_buttonReleased__15GraphicsTestAppPCQ25Mouse10DispatcherQ25Mouse6Button:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	moveq #-26,d0
	addl sp@(12),d0
	movel d0,sp@-
	jbsr _buttonReleased__15GraphicsTestAppPCQ25Mouse10DispatcherQ25Mouse6Button
	addw #12,sp
	rts
	nop
	.even
___thunk_20_scroll__Q26HostUI8ObserverPCQ25Mouse10Dispatcherss:
	movew sp@(18),sp@-
	subql #2,sp
	movew sp@(18),sp@-
	subql #2,sp
	movel sp@(16),sp@-
	moveq #-20,d0
	addl sp@(16),d0
	movel d0,sp@-
	jbsr _scroll__Q26HostUI8ObserverPCQ25Mouse10Dispatcherss
	addw #16,sp
	rts
	nop
	.even
___thunk_20_move__Q26HostUI8ObserverPCQ25Mouse10DispatcherssssUl:
	movel sp@(28),sp@-
	movew sp@(30),sp@-
	subql #2,sp
	movew sp@(30),sp@-
	subql #2,sp
	movew sp@(30),sp@-
	subql #2,sp
	movew sp@(30),sp@-
	subql #2,sp
	movel sp@(28),sp@-
	moveq #-20,d0
	addl sp@(28),d0
	movel d0,sp@-
	jbsr _move__Q26HostUI8ObserverPCQ25Mouse10DispatcherssssUl
	addw #28,sp
	rts
	nop
	.even
___thunk_26_drag__15GraphicsTestAppPCQ25Mouse10DispatcherssssUl:
	movel sp@(28),sp@-
	movew sp@(30),sp@-
	subql #2,sp
	movew sp@(30),sp@-
	subql #2,sp
	movew sp@(30),sp@-
	subql #2,sp
	movew sp@(30),sp@-
	subql #2,sp
	movel sp@(28),sp@-
	moveq #-26,d0
	addl sp@(28),d0
	movel d0,sp@-
	jbsr _drag__15GraphicsTestAppPCQ25Mouse10DispatcherssssUl
	addw #28,sp
	rts
	nop
	.even
___thunk_26__$_15GraphicsTestApp:
	movel sp@(8),sp@-
	moveq #-26,d0
	addl sp@(8),d0
	movel d0,sp@-
	jbsr __$_15GraphicsTestApp
	addql #8,sp
	rts
	nop
.globl ___vt_15GraphicsTestApp$Q25Mouse8Observer
	.even
___vt_15GraphicsTestApp$Q25Mouse8Observer:
	.long -26
	.long ___tf15GraphicsTestApp
	.long ___thunk_20__dfRTTI__Q26HostUI8Observer
	.long _applyMouseEventFilter__Q25Mouse8ObserverUl
	.long ___thunk_26_buttonPressed__15GraphicsTestAppPCQ25Mouse10DispatcherQ25Mouse6Button
	.long ___thunk_26_buttonReleased__15GraphicsTestAppPCQ25Mouse10DispatcherQ25Mouse6Button
	.long ___thunk_20_scroll__Q26HostUI8ObserverPCQ25Mouse10Dispatcherss
	.long ___thunk_20_move__Q26HostUI8ObserverPCQ25Mouse10DispatcherssssUl
	.long ___thunk_26_drag__15GraphicsTestAppPCQ25Mouse10DispatcherssssUl
	.long ___thunk_26__$_15GraphicsTestApp
	.skip 4
	.even
___thunk_8__dfRTTI__Q26HostUI8Observer:
	movel sp@(4),d0
	subql #8,d0
	movel d0,sp@-
	jbsr __dfRTTI__Q26HostUI8Observer
	addql #4,sp
	rts
	nop
	.even
___thunk_14_nonPrintablePressed__15GraphicsTestAppPCQ23Key10DispatcherQ23Key7CtrlKey:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	moveq #-14,d0
	addl sp@(12),d0
	movel d0,sp@-
	jbsr _nonPrintablePressed__15GraphicsTestAppPCQ23Key10DispatcherQ23Key7CtrlKey
	addw #12,sp
	rts
	nop
	.even
___thunk_8_nonPrintableReleased__Q26HostUI8ObserverPCQ23Key10DispatcherQ23Key7CtrlKey:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	movel sp@(12),d0
	subql #8,d0
	movel d0,sp@-
	jbsr _nonPrintableReleased__Q26HostUI8ObserverPCQ23Key10DispatcherQ23Key7CtrlKey
	addw #12,sp
	rts
	nop
	.even
___thunk_14_printablePressed__15GraphicsTestAppPCQ23Key10Dispatcherl:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	moveq #-14,d0
	addl sp@(12),d0
	movel d0,sp@-
	jbsr _printablePressed__15GraphicsTestAppPCQ23Key10Dispatcherl
	addw #12,sp
	rts
	nop
	.even
___thunk_8_printableReleased__Q26HostUI8ObserverPCQ23Key10Dispatcherl:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	movel sp@(12),d0
	subql #8,d0
	movel d0,sp@-
	jbsr _printableReleased__Q26HostUI8ObserverPCQ23Key10Dispatcherl
	addw #12,sp
	rts
	nop
	.even
___thunk_14__$_15GraphicsTestApp:
	movel sp@(8),sp@-
	moveq #-14,d0
	addl sp@(8),d0
	movel d0,sp@-
	jbsr __$_15GraphicsTestApp
	addql #8,sp
	rts
	nop
.globl ___vt_15GraphicsTestApp$Q23Key8Observer
	.even
___vt_15GraphicsTestApp$Q23Key8Observer:
	.long -14
	.long ___tf15GraphicsTestApp
	.long ___thunk_8__dfRTTI__Q26HostUI8Observer
	.long _applyKeyEventFilter__Q23Key8ObserverUl
	.long ___thunk_14_nonPrintablePressed__15GraphicsTestAppPCQ23Key10DispatcherQ23Key7CtrlKey
	.long ___thunk_8_nonPrintableReleased__Q26HostUI8ObserverPCQ23Key10DispatcherQ23Key7CtrlKey
	.long ___thunk_14_printablePressed__15GraphicsTestAppPCQ23Key10Dispatcherl
	.long ___thunk_8_printableReleased__Q26HostUI8ObserverPCQ23Key10Dispatcherl
	.long ___thunk_14__$_15GraphicsTestApp
	.skip 4
	.even
___thunk_6_displayClosed__15GraphicsTestAppPCQ26HostUI10Dispatcher:
	movel sp@(8),sp@-
	movel sp@(8),d0
	subql #6,d0
	movel d0,sp@-
	jbsr _displayClosed__15GraphicsTestAppPCQ26HostUI10Dispatcher
	addql #8,sp
	rts
	nop
	.even
___thunk_6_displayMoved__15GraphicsTestAppPCQ26HostUI10Dispatcher:
	movel sp@(8),sp@-
	movel sp@(8),d0
	subql #6,d0
	movel d0,sp@-
	jbsr _displayMoved__15GraphicsTestAppPCQ26HostUI10Dispatcher
	addql #8,sp
	rts
	nop
	.even
___thunk_6_displayResized__15GraphicsTestAppPCQ26HostUI10Dispatcher:
	movel sp@(8),sp@-
	movel sp@(8),d0
	subql #6,d0
	movel d0,sp@-
	jbsr _displayResized__15GraphicsTestAppPCQ26HostUI10Dispatcher
	addql #8,sp
	rts
	nop
	.even
___thunk_6_displayMinimized__15GraphicsTestAppPCQ26HostUI10Dispatcher:
	movel sp@(8),sp@-
	movel sp@(8),d0
	subql #6,d0
	movel d0,sp@-
	jbsr _displayMinimized__15GraphicsTestAppPCQ26HostUI10Dispatcher
	addql #8,sp
	rts
	nop
	.even
___thunk_6_displayFocus__15GraphicsTestAppPCQ26HostUI10Dispatcher:
	movel sp@(8),sp@-
	movel sp@(8),d0
	subql #6,d0
	movel d0,sp@-
	jbsr _displayFocus__15GraphicsTestAppPCQ26HostUI10Dispatcher
	addql #8,sp
	rts
	nop
	.even
___thunk_6_displayBlur__15GraphicsTestAppPCQ26HostUI10Dispatcher:
	movel sp@(8),sp@-
	movel sp@(8),d0
	subql #6,d0
	movel d0,sp@-
	jbsr _displayBlur__15GraphicsTestAppPCQ26HostUI10Dispatcher
	addql #8,sp
	rts
	nop
.globl ___vt_15GraphicsTestApp$Q26HostUI8Observer
	.even
___vt_15GraphicsTestApp$Q26HostUI8Observer:
	.long -6
	.long ___tf15GraphicsTestApp
	.long __dfRTTI__Q26HostUI8Observer
	.long _applyDisplayEventFilter__Q26HostUI8ObserverUl
	.long ___thunk_6_displayClosed__15GraphicsTestAppPCQ26HostUI10Dispatcher
	.long ___thunk_6_displayMoved__15GraphicsTestAppPCQ26HostUI10Dispatcher
	.long ___thunk_6_displayResized__15GraphicsTestAppPCQ26HostUI10Dispatcher
	.long ___thunk_6_displayMinimized__15GraphicsTestAppPCQ26HostUI10Dispatcher
	.long ___thunk_6_displayFocus__15GraphicsTestAppPCQ26HostUI10Dispatcher
	.long ___thunk_6_displayBlur__15GraphicsTestAppPCQ26HostUI10Dispatcher
	.skip 4
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
LC23:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
	.long ___tiQ26HostUI8Observer
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x31
LC24:
	.ascii "15GraphicsTestApp\0"
	.even
.globl ___tf15GraphicsTestApp
___tf15GraphicsTestApp:
	movel a2,sp@-
	lea ___ti15GraphicsTestApp,a2
	tstl a2@
	jne L968
	jbsr ___tfQ26HostUI8Observer
	jbsr ___tf11Application
	pea 2:w
	pea LC23
	pea LC24
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L968:
	movel a2,d0
	movel sp@+,a2
	rts
