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
	movel #L168,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L167
	.even
L168:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L165
	.even
L167:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___15MainApplication
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L164
	.even
L165:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L174,a5@(-36)
	movel sp,a5@(-32)
	jra L173
	.even
L174:
	jra L178
	.even
L173:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L176
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L176:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L178:
L171:
	jbsr ___terminate
	.even
L164:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L187
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L187:
	rts
	nop
	.even
.globl ___15MainApplication
___15MainApplication:
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
	movel #L193,sp@(200)
	movel sp,sp@(204)
L193:
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
	movel #L206,sp@(152)
	movel sp,sp@(156)
	movel a0,a1
L206:
	lea sp@(140),a2
	movel a2,a0@
	movel sp@(220),a0
	movel #___vt_15MainApplication,a0@
	movel a1@,a0
	movel a0@,a1@
	movel sp@(220),d0
	moveml sp@+,#0x7cfc
	fmovem sp@+,#0x3f
	addw #100,sp
	rts
	.even
.globl __$_15MainApplication
__$_15MainApplication:
	movel sp@(4),a0
	movel #___vt_8Runnable,a0@
	btst #0,sp@(11)
	jeq L228
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L228:
	rts
	nop
	.even
.globl _run__15MainApplication
_run__15MainApplication:
	addw #-12,sp
	moveq #16,d0
	movel d0,sp@(4)
	movel #0xc1800000,sp@
	clrl d0
	addw #12,sp
	rts
.globl ___vt_15MainApplication
	.even
___vt_15MainApplication:
	.long 0
	.long ___tf15MainApplication
	.long __dfRTTI__11Application
	.long _run__15MainApplication
	.long __$_15MainApplication
	.skip 4
.comm ___ti15MainApplication,16
	.even
LC0:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC1:
	.ascii "15MainApplication\0"
	.even
.globl ___tf15MainApplication
___tf15MainApplication:
	movel a2,sp@-
	lea ___ti15MainApplication,a2
	tstl a2@
	jne L251
	jbsr ___tf11Application
	pea 1:w
	pea LC0
	pea LC1
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L251:
	movel a2,d0
	movel sp@+,a2
	rts
