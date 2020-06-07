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
	pea 14:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L298,a5@(-12)
	movel sp,a5@(-8)
	jra L297
	.even
L298:
	jra L308
	.even
L297:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___4Main
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L294
	.even
L308:
L295:
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L304,a5@(-36)
	movel sp,a5@(-32)
	jra L303
	.even
L304:
	jra L309
	.even
L303:
	lea a5@(-48),a1
	movel a1,a0@
	moveq #1,d0
	jeq L306
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L306:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L309:
L301:
	jbsr ___terminate
	.even
L294:
	moveml a5@(-168),#0x5cfc
	fmovem a5@(-128),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L318
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L318:
	rts
	nop
LC0:
	.ascii "Created Main\12\0"
	.even
.globl ___4Main
___4Main:
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
	movel #L324,a5@(-12)
	movel sp,a5@(-8)
L324:
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
	movel #L338,a5@(-60)
	movel sp,a5@(-56)
	jra L337
	.even
L338:
	jra L352
	.even
L337:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_4Main,a0@
	pea a0@(6)
	jbsr ___Q24Time10MilliClock
	movel #LC0,sp@
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L351
	.even
L352:
L335:
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L343,a5@(-84)
	movel sp,a5@(-80)
	jra L342
	.even
L343:
	jra L353
	.even
L342:
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
L353:
L340:
	jbsr ___terminate
	.even
L351:
	moveml a5@(-212),#0x5cfc
	fmovem a5@(-172),#0x3f
	unlk a5
	rts
LC1:
	.ascii "Destroyed Main\12\0"
	.even
.globl __$_4Main
__$_4Main:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel sp@(16),d2
	movel #___vt_4Main,a2@
	pea LC1
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel #___vt_8Runnable,a2@
	btst #0,d2
	jeq L361
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L361:
	movel sp@+,d2
	movel sp@+,a2
	rts
LC2:
	.ascii "Testing linear %lu x %lu\12\0"
LC3:
	.ascii "Elapsed time: %.3f ms\12\0"
LC4:
	.ascii "Testing subpatched %lu x %lu\12\0"
	.even
.globl _run__4Main
_run__4Main:
	link a5,#-68
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-44)
	movel a5,d2
	subql #8,d2
	movel d2,sp@-
	jbsr ___9LinearMap
	movel a5@(-44),a2
	addql #4,a2
	movel a2@,a0
	addql #4,a0
	movel a0@,a5@(-20)
	movel #__$_9LinearMap,a5@(-16)
	movel d2,a5@(-12)
	lea a5@(-20),a1
	movel a1,a0@
	moveq #-28,d2
	addl a5,d2
	movel d2,sp@-
	jbsr ___13SubPatch16Map
	movel a2@,a0
	addql #4,a0
	movel a0@,a5@(-40)
	movel #__$_13SubPatch16Map,a5@(-36)
	movel d2,a5@(-32)
	lea a5@(-40),a1
	movel a1,a0@
	addql #8,sp
	movel #256,d0
	movel d0,sp@-
	movel d0,sp@-
	pea LC2
	jbsr _printf
	movel a5@(8),a0
	pea a0@(6)
	jbsr _set__Q24Time10MilliClock
	moveq #1,d7
	addw #16,sp
	clrl a5@(-56)
	.even
L373:
	moveq #1,d6
	cmpl #255,d6
	jcc L372
	movel a5,d5
	subql #8,d5
	clrl a5@(-48)
	movel d7,a1
	subql #1,a1
	movel a1,a5@(-52)
	movel d7,a6
	addql #1,a6
	.even
L377:
	movel d7,sp@-
	movel d6,sp@-
	movel d5,sp@-
	jbsr _point__9LinearMapUlUl
	movel d0,a0
	moveb a0@,a5@(-45)
	movel a5@(-48),d2
	lsll #2,d2
	movel d7,sp@-
	movel d6,d3
	subql #1,d3
	movel d3,sp@-
	movel d5,sp@-
	jbsr _point__9LinearMapUlUl
	movel d0,a4
	movel d7,sp@-
	movel d6,d4
	addql #1,d4
	movel d4,sp@-
	movel d5,sp@-
	jbsr _point__9LinearMapUlUl
	movel d0,a3
	addw #32,sp
	movel a5@(-52),sp@
	movel d6,sp@-
	movel d5,sp@-
	jbsr _point__9LinearMapUlUl
	movel d0,a2
	movel a6,sp@-
	movel d6,sp@-
	movel d5,sp@-
	jbsr _point__9LinearMapUlUl
	movel d0,a0
	moveb a4@,a5@(-53)
	clrl d0
	moveb a3@,d0
	addl a5@(-56),d0
	clrl d1
	moveb a2@,d1
	addl d1,d0
	clrl d1
	moveb a0@,d1
	addl d1,d0
	movel d2,a0
	lea a0@(d0:l:2),a0
	movel a0,d2
	movel a5@(-52),sp@-
	movel d3,sp@-
	movel d5,sp@-
	jbsr _point__9LinearMapUlUl
	movel d0,a4
	addw #32,sp
	movel a5@(-52),sp@
	movel d4,sp@-
	movel d5,sp@-
	jbsr _point__9LinearMapUlUl
	movel d0,a3
	movel a6,sp@-
	movel d3,sp@-
	movel d5,sp@-
	jbsr _point__9LinearMapUlUl
	movel d0,a2
	movel a6,sp@-
	movel d4,sp@-
	movel d5,sp@-
	jbsr _point__9LinearMapUlUl
	movel d0,a0
	clrl d0
	moveb a4@,d0
	clrl d1
	moveb a3@,d1
	addl d1,d0
	clrl d1
	moveb a2@,d1
	addl d1,d0
	clrl d1
	moveb a0@,d1
	addl d1,d0
	addl d0,d2
	addw #32,sp
	movel d7,sp@
	movel d6,sp@-
	movel d5,sp@-
	jbsr _point__9LinearMapUlUl
	movel d0,a0
	lsrl #4,d2
	moveb d2,a0@
	addw #12,sp
	movel d4,d6
	cmpl #255,d6
	jcs L377
L372:
	addql #1,d7
	cmpl #255,d7
	jcs L373
	movel a5@(8),d2
	addql #6,d2
	movel d2,sp@-
	jbsr _elapsedFrac__CQ24Time10MilliClock
	movel d1,sp@-
	movel d0,sp@-
	pea LC3
	lea _printf,a2
	jbsr a2@
	addw #16,sp
	movel #256,d0
	movel d0,sp@-
	movel d0,sp@-
	pea LC4
	jbsr a2@
	movel d2,sp@-
	jbsr _set__Q24Time10MilliClock
	clrl d7
	addw #16,sp
	movel d7,a5@(-68)
	.even
L386:
	clrl d6
	cmpl #255,d6
	jcc L385
	moveq #-28,d5
	addl a5,d5
	movel d6,a5@(-60)
	movel d7,a1
	subql #1,a1
	movel a1,a5@(-64)
	movel d7,a6
	addql #1,a6
	.even
L390:
	movel d7,sp@-
	movel d6,sp@-
	movel d5,sp@-
	jbsr _point__13SubPatch16MapUlUl
	movel d0,a0
	moveb a0@,a5@(-57)
	movel a5@(-60),d2
	lsll #2,d2
	movel d7,sp@-
	movel d6,d3
	subql #1,d3
	movel d3,sp@-
	movel d5,sp@-
	jbsr _point__13SubPatch16MapUlUl
	movel d0,a4
	movel d7,sp@-
	movel d6,d4
	addql #1,d4
	movel d4,sp@-
	movel d5,sp@-
	jbsr _point__13SubPatch16MapUlUl
	movel d0,a3
	addw #32,sp
	movel a5@(-64),sp@
	movel d6,sp@-
	movel d5,sp@-
	jbsr _point__13SubPatch16MapUlUl
	movel d0,a2
	movel a6,sp@-
	movel d6,sp@-
	movel d5,sp@-
	jbsr _point__13SubPatch16MapUlUl
	movel d0,a0
	moveb a4@,a5@(-65)
	clrl d0
	moveb a3@,d0
	addl a5@(-68),d0
	clrl d1
	moveb a2@,d1
	addl d1,d0
	clrl d1
	moveb a0@,d1
	addl d1,d0
	movel d2,a0
	lea a0@(d0:l:2),a0
	movel a0,d2
	movel a5@(-64),sp@-
	movel d3,sp@-
	movel d5,sp@-
	jbsr _point__13SubPatch16MapUlUl
	movel d0,a4
	addw #32,sp
	movel a5@(-64),sp@
	movel d4,sp@-
	movel d5,sp@-
	jbsr _point__13SubPatch16MapUlUl
	movel d0,a3
	movel a6,sp@-
	movel d3,sp@-
	movel d5,sp@-
	jbsr _point__13SubPatch16MapUlUl
	movel d0,a2
	movel a6,sp@-
	movel d4,sp@-
	movel d5,sp@-
	jbsr _point__13SubPatch16MapUlUl
	movel d0,a0
	clrl d0
	moveb a4@,d0
	clrl d1
	moveb a3@,d1
	addl d1,d0
	clrl d1
	moveb a2@,d1
	addl d1,d0
	clrl d1
	moveb a0@,d1
	addl d1,d0
	addl d0,d2
	addw #32,sp
	movel d7,sp@
	movel d6,sp@-
	movel d5,sp@-
	jbsr _point__13SubPatch16MapUlUl
	movel d0,a0
	lsrl #4,d2
	moveb d2,a0@
	addw #12,sp
	movel d4,d6
	cmpl #255,d6
	jcs L390
L385:
	addql #1,d7
	cmpl #255,d7
	jcs L386
	movel a5@(8),a1
	pea a1@(6)
	jbsr _elapsedFrac__CQ24Time10MilliClock
	movel d1,sp@-
	movel d0,sp@-
	pea LC3
	jbsr _printf
	movel a5@(-44),a2
	addql #4,a2
	movel a2@,a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	pea 2:w
	pea a5@(-28)
	jbsr __$_3Map
	addql #8,sp
	movel a2@,a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	pea 2:w
	pea a5@(-8)
	jbsr __$_3Map
	addql #8,sp
	clrl d0
	addw #16,sp
	moveml a5@(-108),#0x5cfc
	unlk a5
	rts
.globl ___vt_4Main
	.even
___vt_4Main:
	.long 0
	.long ___tf4Main
	.long __dfRTTI__11Application
	.long _run__4Main
	.long __$_4Main
	.skip 4
.comm ___ti9LinearMap,12
LC5:
	.ascii "9LinearMap\0"
.comm ___ti13SubPatch16Map,12
LC6:
	.ascii "13SubPatch16Map\0"
.comm ___ti4Main,16
	.even
LC7:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC8:
	.ascii "4Main\0"
	.even
__$_9LinearMap:
	movel sp@(8),sp@-
	movel sp@(8),sp@-
	jbsr __$_3Map
	addql #8,sp
	rts
	nop
	.even
__$_13SubPatch16Map:
	movel sp@(8),sp@-
	movel sp@(8),sp@-
	jbsr __$_3Map
	addql #8,sp
	rts
	nop
	.even
.globl ___tf4Main
___tf4Main:
	movel a2,sp@-
	lea ___ti4Main,a2
	tstl a2@
	jne L402
	jbsr ___tf11Application
	pea 1:w
	pea LC7
	pea LC8
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L402:
	movel #___ti4Main,d0
	movel sp@+,a2
	rts
