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
	movel #L225,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L224
	.even
L225:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L222
	.even
L224:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___10HelloWorld
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L221
	.even
L222:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L231,a5@(-36)
	movel sp,a5@(-32)
	jra L230
	.even
L231:
	jra L235
	.even
L230:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L233
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L233:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L235:
L228:
	jbsr ___terminate
	.even
L221:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L244
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L244:
	rts
	nop
	.even
.globl ___10HelloWorld
___10HelloWorld:
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
	movel #L250,sp@(200)
	movel sp,sp@(204)
L250:
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
	movel #L263,sp@(152)
	movel sp,sp@(156)
	movel a0,a1
L263:
	lea sp@(140),a2
	movel a2,a0@
	movel sp@(220),a0
	movel #___vt_10HelloWorld,a0@
	movel a1@,a0
	movel a0@,a1@
	movel sp@(220),d0
	moveml sp@+,#0x7cfc
	fmovem sp@+,#0x3f
	addw #100,sp
	rts
	.even
.globl __$_10HelloWorld
__$_10HelloWorld:
	movel sp@(4),a0
	movel #___vt_8Runnable,a0@
	btst #0,sp@(11)
	jeq L285
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L285:
	rts
	nop
LC0:
	.ascii "ram:dummy.bin\0"
	.even
.globl _run__10HelloWorld
_run__10HelloWorld:
	addw #-228,sp
	moveml #0x3020,sp@-
	jbsr ___get_eh_context
	movel d0,d1
	clrl sp@(12)
	clrl sp@(16)
	movel #305419896,sp@(12)
	lea sp@(12),a0
	movel #180017749,a0@(4)
	clrl sp@(94)
	clrl sp@(122)
	clrl sp@(110)
	movel d1,a1
	addql #4,a1
	movel a1@,sp@(56)
	clrl sp@(60)
	lea sp@(80),a2
	movel a2,sp@(64)
	movel #L291,sp@(68)
	movel sp,sp@(72)
	movel a0,d3
L291:
	lea sp@(56),a0
	movel a0,a1@
	clrl sp@(232)
	movel d1,a2
	addql #4,a2
	movel a2@,a0
	movel a0@,a2@
	movel a2@,a0
	addql #4,a0
	movel a0@,sp@(20)
	movel #__$_9StreamOut,sp@(24)
	moveq #80,d2
	addl sp,d2
	movel d2,sp@(28)
	lea sp@(20),a1
	movel a1,a0@
	pea 2048:w
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	pea LC0
	movel d2,sp@-
	jbsr _open__9StreamOutPCcbT2Ul
	addw #16,sp
	movel #8,sp@
	movel d3,sp@-
	movel d2,sp@-
	jbsr _writeBytes__9StreamOutPCvUl
	addqw #8,sp
	movel #8,sp@
	movel d3,sp@-
	movel d2,sp@-
	jbsr _writeBytes__9StreamOutPCvUl
	addqw #8,sp
	movel #4,sp@
	movel d3,sp@-
	movel d2,sp@-
	jbsr _write16Swap__9StreamOutPCvUl
	addqw #8,sp
	movel #8,sp@
	movel d3,sp@-
	movel d2,sp@-
	jbsr _writeBytes__9StreamOutPCvUl
	addqw #8,sp
	movel #2,sp@
	movel d3,sp@-
	movel d2,sp@-
	jbsr _write32Swap__9StreamOutPCvUl
	addqw #8,sp
	movel #8,sp@
	movel d3,sp@-
	movel d2,sp@-
	jbsr _writeBytes__9StreamOutPCvUl
	addqw #8,sp
	movel #1,sp@
	movel d3,sp@-
	movel d2,sp@-
	jbsr _write64Swap__9StreamOutPCvUl
	movel a2@,a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	pea 2:w
	movel d2,sp@-
	jbsr __$_9StreamOut
	addql #8,sp
	clrl d0
	addw #12,sp
	moveml sp@+,#0x40c
	addw #228,sp
	rts
.globl ___vt_10HelloWorld
	.even
___vt_10HelloWorld:
	.long 0
	.long ___tf10HelloWorld
	.long __dfRTTI__11Application
	.long _run__10HelloWorld
	.long __$_10HelloWorld
	.skip 4
.comm ___ti10HelloWorld,16
	.even
LC1:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC2:
	.ascii "10HelloWorld\0"
	.even
.globl ___tf10HelloWorld
___tf10HelloWorld:
	movel a2,sp@-
	lea ___ti10HelloWorld,a2
	tstl a2@
	jne L307
	jbsr ___tf11Application
	pea 1:w
	pea LC1
	pea LC2
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L307:
	movel a2,d0
	movel sp@+,a2
	rts
