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
	pea 6:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L291,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L290
	.even
L291:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L288
	.even
L290:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___14RefTrieTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L287
	.even
L288:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L297,a5@(-36)
	movel sp,a5@(-32)
	jra L296
	.even
L297:
	jra L301
	.even
L296:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L299
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L299:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L301:
L294:
	jbsr ___terminate
	.even
L287:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L310
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L310:
	rts
	nop
LC0:
	.ascii "Created RefTrieTestApp\12\0"
	.even
.globl ___14RefTrieTestApp
___14RefTrieTestApp:
	link a5,#-100
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
	movel #L316,a5@(-12)
	movel sp,a5@(-8)
L316:
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
	movel #L330,a5@(-60)
	movel sp,a5@(-56)
	movel a0,a5@(-100)
	jra L329
	.even
L330:
	jra L344
	.even
L329:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_14RefTrieTestApp,a0@
	pea LC0
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel a5@(-100),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L343
	.even
L344:
L327:
	movel a5@(-100),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L335,a5@(-84)
	movel sp,a5@(-80)
	jra L334
	.even
L335:
	jra L345
	.even
L334:
	lea a5@(-96),a0
	movel a5@(-100),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_8Runnable,a1@
	movel a5@(-100),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L345:
L332:
	jbsr ___terminate
	.even
L343:
	moveml a5@(-212),#0x5cfc
	fmovem a5@(-172),#0x3f
	unlk a5
	rts
LC1:
	.ascii "Destroyed RefTrieTestApp\12\0"
	.even
.globl __$_14RefTrieTestApp
__$_14RefTrieTestApp:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel sp@(16),d2
	movel #___vt_14RefTrieTestApp,a2@
	pea LC1
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel #___vt_8Runnable,a2@
	btst #0,d2
	jeq L353
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L353:
	movel sp@+,d2
	movel sp@+,a2
	rts
LC2:
	.ascii "Usage: %s -file <filename>\12\0"
LC3:
	.ascii "-file\0"
LC4:
	.ascii "Testing KeyRefTrie\12\0"
LC5:
	.ascii "%u nodes allocated, max key length %u\12\0"
	.even
.globl _run__14RefTrieTestApp
_run__14RefTrieTestApp:
	link a5,#-528
	moveml #0x3e3a,sp@-
	movel a5@(8),d5
	jbsr ___get_eh_context
	movel d0,d3
	movel d3,d1
	moveq #1,d0
	cmpl __7Startup$numArgs,d0
	jlt L355
	clrl sp@-
	jbsr _getArg__7StartupUl
	movel d0,sp@
	pea LC2
	jbsr _printf
	clrl d0
	addql #8,sp
	jra L354
	.even
L355:
	clrb a5@(-1)
	movel d3,d0
	clrl a5@(-394)
	clrl a5@(-366)
	clrl a5@(-378)
	movel d3,a0
	addql #4,a0
	movel a0@,a5@(-430)
	clrl a5@(-426)
	lea a5@(-406),a1
	movel a1,a5@(-422)
	movel #L363,a5@(-418)
	movel sp,a5@(-414)
	movel a0,a4
L363:
	lea a5@(-430),a1
	movel a1,a0@
	movel d1,a2
	addql #4,a2
	movel a2@,a0
	movel a0@,a2@
	movel a4@,a0
	addql #4,a0
	movel a0@,a5@(-466)
	movel #__$_Q32IO6Stream2In,a5@(-462)
	movel a5,d2
	addl #-406,d2
	movel d2,a5@(-458)
	lea a5@(-466),a1
	movel a1,a0@
	movel d1,d0
	pea a5@(-454)
	jbsr ___Q211EXNGPrivate8VoidTrie
	movel a2@,a5@(-490)
	clrl a5@(-486)
	lea a5@(-466),a0
	movel a0,a5@(-482)
	movel #L389,a5@(-478)
	movel sp,a5@(-474)
L389:
	lea a5@(-490),a1
	movel a1,a2@
	addql #4,sp
	movel d3,a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	movel a4@,a0
	addql #4,a0
	movel a0@,a5@(-526)
	movel #__$_t10KeyRefTrie2ZPCcZ11Application,a5@(-522)
	lea a5@(-454),a1
	movel a1,a5@(-518)
	lea a5@(-526),a1
	movel a1,a0@
	pea 2048:w
	clrl sp@-
	pea 1:w
	clrl sp@-
	pea LC3
	jbsr _getArgString__7StartupPCcT1Us
	addqw #8,sp
	movel d0,sp@
	movel d2,sp@-
	jbsr _open__Q32IO6Stream2InPCcQ32IO6Stream8ReadModeUl
	pea LC4
	lea _printf,a2
	jbsr a2@
	movel #1000,d3
	addw #20,sp
	movel a2,a6
	lea a5@(-256),a2
	lea _readText__Q32IO6Stream2InPclcl,a3
	movel #_close__Q32IO6Stream2In,d6
	movel #__$_Q32IO6Stream2In,d4
	jra L397
	.even
L399:
	subql #1,d0
	jeq L397
	cmpb #10,a2@(d0:l)
	jne L402
	clrb a2@(d0:l)
L402:
	movel d5,sp@-
	movel a2,sp@-
	pea a5@(-454)
	jbsr _addItem__Q211EXNGPrivate8VoidTriePCcPv
	addw #12,sp
L397:
	pea 1:w
	pea 10:w
	pea 255:w
	movel a2,sp@-
	movel d2,sp@-
	jbsr a3@
	addw #20,sp
	tstl d0
	jeq L398
	dbra d3,L399
	clrw d3
	subql #1,d3
	jcc L399
L398:
	movel d2,sp@-
	movel d6,a0
	jbsr a0@
	movel a5@(-438),sp@
	movel a5@(-442),sp@-
	pea LC5
	jbsr a6@
	movel a4@,a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	pea 2:w
	pea a5@(-454)
	jbsr __$_Q211EXNGPrivate8VoidTrie
	addql #8,sp
	movel a4@,a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	pea 2:w
	movel d2,sp@-
	movel d4,a1
	jbsr a1@
	addql #8,sp
	clrl d0
	addw #12,sp
L354:
	moveml a5@(-564),#0x5c7c
	unlk a5
	rts
.globl ___vt_14RefTrieTestApp
	.even
___vt_14RefTrieTestApp:
	.long 0
	.long ___tf14RefTrieTestApp
	.long __dfRTTI__11Application
	.long _run__14RefTrieTestApp
	.long __$_14RefTrieTestApp
	.skip 4
.comm ___ti14RefTrieTestApp,16
	.even
LC6:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC7:
	.ascii "14RefTrieTestApp\0"
	.even
.globl ___tf14RefTrieTestApp
___tf14RefTrieTestApp:
	movel a2,sp@-
	lea ___ti14RefTrieTestApp,a2
	tstl a2@
	jne L417
	jbsr ___tf11Application
	pea 1:w
	pea LC6
	pea LC7
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L417:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
__$_t10KeyRefTrie2ZPCcZ11Application:
	movel sp@(8),sp@-
	movel sp@(8),sp@-
	jbsr __$_Q211EXNGPrivate8VoidTrie
	addql #8,sp
	rts
	nop
