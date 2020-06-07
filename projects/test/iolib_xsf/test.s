#NO_APP
.text
LC0:
	.ascii "%04ld-%02ld-%02ld %02ld:%02ld:%02ld.%03ld%+ld:%02ld\12\0"
	.even
.globl _printDatestamp__FRCQ24Time9Datestamp
_printDatestamp__FRCQ24Time9Datestamp:
	movel d3,sp@-
	movel d2,sp@-
	movel sp@(12),a0
	movel a0@,d2
	movel d2,d0
	moveq #21,d1
	asrl d1,d0
	moveq #60,d3
	divsll d3,d1:d0
	movel d1,sp@-
	movel d0,sp@-
	movel a0@(4),d0
	movel d0,d1
	andl #1023,d1
	movel d1,sp@-
	bfextu d0{#16:#6},d3
	movel d3,sp@-
	bfextu d0{#10:#6},d1
	movel d1,sp@-
	bfextu d0{#5:#5},d3
	movel d3,sp@-
	moveq #27,d1
	lsrl d1,d0
	movel d0,sp@-
	moveq #15,d3
	andl d2,d3
	movel d3,sp@-
	bfextu d2{#11:#17},d2
	movel d2,sp@-
	pea LC0
	jbsr _printf
	addw #40,sp
	movel sp@+,d2
	movel sp@+,d3
	rts
	.even
.globl _createInstance__11Application
_createInstance__11Application:
	link a5,#-60
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-56)
	pea 8:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L506,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L505
	.even
L506:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L503
	.even
L505:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___10XSFTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L502
	.even
L503:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L512,a5@(-36)
	movel sp,a5@(-32)
	jra L511
	.even
L512:
	jra L516
	.even
L511:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L514
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L514:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L516:
L509:
	jbsr ___terminate
	.even
L502:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L525
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L525:
	rts
	nop
	.even
.globl ___10XSFTestApp
___10XSFTestApp:
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
	movel #L531,sp@(200)
	movel sp,sp@(204)
L531:
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
	movel #L544,sp@(152)
	movel sp,sp@(156)
	movel a0,a1
L544:
	lea sp@(140),a2
	movel a2,a0@
	movel sp@(220),a0
	movel #___vt_10XSFTestApp,a0@
	movel a1@,a0
	movel a0@,a1@
	movel sp@(220),d0
	moveml sp@+,#0x7cfc
	fmovem sp@+,#0x3f
	addw #100,sp
	rts
	.even
.globl __$_10XSFTestApp
__$_10XSFTestApp:
	movel sp@(4),a0
	movel #___vt_8Runnable,a0@
	btst #0,sp@(11)
	jeq L566
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L566:
	rts
	nop
	.even
.globl _run__10XSFTestApp
_run__10XSFTestApp:
	movel d2,sp@-
	movel sp@(8),d2
	movel d2,sp@-
	jbsr _testWrite__10XSFTestApp
	movel d2,sp@-
	jbsr _testRead1__10XSFTestApp
	movel d2,sp@-
	jbsr _testRead2__10XSFTestApp
	clrl d0
	addw #12,sp
	movel sp@+,d2
	rts
LC1:
	.ascii "32be\0"
LC2:
	.ascii "64be\0"
LC3:
	.ascii "32le\0"
LC4:
	.ascii "64le\0"
LC5:
	.ascii "Creating test_%s.xsf\12\0"
LC6:
	.ascii "test_%s.xsf\0"
LC7:
	.ascii "Test\0"
	.even
.globl _testWrite__10XSFTestApp
_testWrite__10XSFTestApp:
	link a5,#-332
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-330)
	movel #-1414673666,a5@(-16)
	movel #-559026163,a5@(-12)
	movel #1122867,a5@(-8)
	movel #1146447479,a5@(-4)
	movel #LC1,a5@(-48)
	moveq #2,d0
	movel d0,a5@(-44)
	movel #LC2,a5@(-40)
	moveq #11,d0
	movel d0,a5@(-36)
	movel #LC3,a5@(-32)
	moveq #34,d0
	movel d0,a5@(-28)
	movel #LC4,a5@(-24)
	moveq #43,d0
	movel d0,a5@(-20)
	movel a5,d2
	addl #-314,d2
	movel d2,sp@-
	jbsr ___Q33XSF6Stream3Out
	movel a5@(-330),a1
	movel a1@(4),a0
	addql #4,a0
	movel a0@,a5@(-326)
	movel #__$_Q33XSF6Stream3Out,a5@(-322)
	movel d2,a5@(-318)
	lea a5@(-326),a1
	movel a1,a0@
	clrl d3
	addql #4,sp
	movel d2,d7
	movel #_printf,d6
	movel #_sprintf,d5
	movel #_open__Q33XSF6Stream3OutPCcT1UsUsUcUl,d4
	lea _close__Q33XSF6Stream3Out,a6
	moveq #-80,d2
	addl a5,d2
	movel d7,a3
	lea a5@(-41),a4
	lea a5@(-48),a2
	.even
L572:
	movel a2@,sp@-
	pea LC5
	movel d6,a0
	jbsr a0@
	movel a2@,sp@-
	pea LC6
	movel d2,sp@-
	movel d5,a1
	jbsr a1@
	pea 2048:w
	clrl d0
	moveb a4@,d0
	addql #8,a4
	movel d0,sp@-
	clrl sp@-
	pea 1:w
	pea LC7
	movel d2,sp@-
	movel a3,sp@-
	movel d4,a0
	jbsr a0@
	addw #44,sp
	movel #16,sp@
	pea a5@(-16)
	movel a3,sp@-
	jbsr _writeBytes__Q32IO6Stream3OutPCvUl
	addqw #8,sp
	movel #8,sp@
	pea a5@(-16)
	movew a5@(-104),a0
	pea a0@(a3:l)
	movel a5@(-100),a0
	jbsr a0@
	addqw #8,sp
	movel #4,sp@
	pea a5@(-16)
	movew a5@(-96),a0
	pea a0@(a3:l)
	movel a5@(-92),a0
	jbsr a0@
	addqw #8,sp
	movel #2,sp@
	pea a5@(-16)
	movew a5@(-88),a0
	pea a0@(a3:l)
	movel a5@(-84),a0
	jbsr a0@
	addqw #8,sp
	movel a3,sp@
	jbsr a6@
	addql #4,sp
	addql #8,a2
	addql #1,d3
	moveq #3,d0
	cmpl d3,d0
	jcc L572
	movel a5@(-330),a0
	movel a0@(4),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	pea 2:w
	movel d7,sp@-
	jbsr __$_Q33XSF6Stream3Out
	addql #8,sp
	moveml a5@(-372),#0x5cfc
	unlk a5
	rts
LC8:
	.ascii "Opening test_%s.xsf\12\0"
LC9:
	.ascii "XSF     Version: %d.%d\12Payload Version: %d.%d\12\0"
LC10:
	.ascii "Created        : \0"
	.even
.globl _testRead1__10XSFTestApp
_testRead1__10XSFTestApp:
	link a5,#-292
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a4
	movel #LC1,a5@(-16)
	movel #LC2,a5@(-12)
	movel #LC3,a5@(-8)
	movel #LC2,a5@(-4)
	movel a5,d2
	addl #-278,d2
	movel d2,sp@-
	jbsr ___Q33XSF6Stream2In
	movel a4@(4),a0
	addql #4,a0
	movel a0@,a5@(-290)
	movel #__$_Q33XSF6Stream2In,a5@(-286)
	movel d2,a5@(-282)
	lea a5@(-290),a1
	movel a1,a0@
	clrl d7
	addql #4,sp
	moveq #-92,d6
	addl a5,d6
	lea _printDatestamp__FRCQ24Time9Datestamp,a6
	lea _printf,a3
	moveq #-48,d2
	addl a5,d2
	movel a5,d5
	addl #-278,d5
	clrl d4
	clrl d3
	lea a5@(-16),a2
	.even
L587:
	movel a2@,sp@-
	pea LC8
	jbsr a3@
	movel a2@,sp@-
	pea LC6
	movel d2,sp@-
	jbsr _sprintf
	pea 2048:w
	movel d2,sp@-
	movel d5,sp@-
	jbsr _open__Q33XSF6Stream2InPCcUl
	addw #32,sp
	movew a5@(-94),d4
	movel d4,sp@-
	movew a5@(-96),d3
	movel d3,sp@-
	clrl d0
	movew a5@(-98),d0
	movel d0,sp@-
	clrl d0
	movew a5@(-100),d0
	movel d0,sp@-
	pea LC9
	jbsr a3@
	pea LC10
	jbsr a3@
	addw #20,sp
	movel d6,sp@
	jbsr a6@
	movel d5,sp@-
	jbsr _close__Q33XSF6Stream2In
	addqw #4,sp
	movel a2@(4),sp@
	pea LC8
	jbsr a3@
	movel a2@(4),sp@-
	pea LC6
	movel d2,sp@-
	jbsr _sprintf
	pea 2048:w
	movel d2,sp@-
	movel d5,sp@-
	jbsr _open__Q33XSF6Stream2InPCcUl
	addw #32,sp
	movew a5@(-94),d4
	movel d4,sp@-
	movew a5@(-96),d3
	movel d3,sp@-
	clrl d0
	movew a5@(-98),d0
	movel d0,sp@-
	clrl d0
	movew a5@(-100),d0
	movel d0,sp@-
	pea LC9
	jbsr a3@
	pea LC10
	jbsr a3@
	addw #20,sp
	movel d6,sp@
	jbsr a6@
	movel d5,sp@-
	jbsr _close__Q33XSF6Stream2In
	addql #8,sp
	addql #8,a2
	addql #2,d7
	moveq #3,d0
	cmpl d7,d0
	jcc L587
	movel a4@(4),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	pea 2:w
	pea a5@(-278)
	jbsr __$_Q33XSF6Stream2In
	addql #8,sp
	moveml a5@(-332),#0x5cfc
	unlk a5
	rts
	.even
.globl _testRead2__10XSFTestApp
_testRead2__10XSFTestApp:
	rts
	nop
.globl ___vt_10XSFTestApp
	.even
___vt_10XSFTestApp:
	.long 0
	.long ___tf10XSFTestApp
	.long __dfRTTI__11Application
	.long _run__10XSFTestApp
	.long __$_10XSFTestApp
	.skip 4
.comm ___ti10XSFTestApp,16
	.even
LC11:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
	.long ___tiQ33XSF6Stream4User
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x33
LC12:
	.ascii "10XSFTestApp\0"
.comm ___tiQ33XSF6Stream4User,8
LC13:
	.ascii "Q33XSF6Stream4User\0"
	.even
.globl ___tf10XSFTestApp
___tf10XSFTestApp:
	movel a2,sp@-
	lea ___ti10XSFTestApp,a2
	tstl a2@
	jne L605
	jbsr ___tfQ33XSF6Stream4User
	jbsr ___tf11Application
	pea 2:w
	pea LC11
	pea LC12
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L605:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
___tfQ33XSF6Stream4User:
	movel a2,sp@-
	lea ___tiQ33XSF6Stream4User,a2
	tstl a2@
	jne L607
	pea LC13
	movel a2,sp@-
	jbsr ___rtti_user
	addql #8,sp
L607:
	movel a2,d0
	movel sp@+,a2
	rts
