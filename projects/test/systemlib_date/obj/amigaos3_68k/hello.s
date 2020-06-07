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
	pea 6:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L170,a5@(-12)
	movel sp,a5@(-8)
	jra L169
	.even
L170:
	jra L180
	.even
L169:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___10HelloWorld
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L166
	.even
L180:
L167:
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L176,a5@(-36)
	movel sp,a5@(-32)
	jra L175
	.even
L176:
	jra L181
	.even
L175:
	lea a5@(-48),a1
	movel a1,a0@
	moveq #1,d0
	jeq L178
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L178:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L181:
L173:
	jbsr ___terminate
	.even
L166:
	moveml a5@(-168),#0x5cfc
	fmovem a5@(-128),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L190
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L190:
	rts
	nop
LC0:
	.ascii "Created HelloWorld\12\0"
	.even
.globl ___10HelloWorld
___10HelloWorld:
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
	movel #L196,a5@(-12)
	movel sp,a5@(-8)
L196:
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
	movel #L210,a5@(-60)
	movel sp,a5@(-56)
	jra L209
	.even
L210:
	jra L224
	.even
L209:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_10HelloWorld,a0@
	pea LC0
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L223
	.even
L224:
L207:
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L215,a5@(-84)
	movel sp,a5@(-80)
	jra L214
	.even
L215:
	jra L225
	.even
L214:
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
L225:
L212:
	jbsr ___terminate
	.even
L223:
	moveml a5@(-212),#0x5cfc
	fmovem a5@(-172),#0x3f
	unlk a5
	rts
LC1:
	.ascii "Destroyed HelloWorld\12\0"
	.even
.globl __$_10HelloWorld
__$_10HelloWorld:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel sp@(16),d2
	movel #___vt_10HelloWorld,a2@
	pea LC1
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel #___vt_8Runnable,a2@
	btst #0,d2
	jeq L233
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L233:
	movel sp@+,d2
	movel sp@+,a2
	rts
LC2:
	.ascii "Hello World!\12\0"
	.even
.globl _run__10HelloWorld
_run__10HelloWorld:
	pea LC2
	jbsr _printf
	clrl d0
	addql #4,sp
	rts
	nop
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
LC3:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC4:
	.ascii "10HelloWorld\0"
	.even
.globl ___tf10HelloWorld
___tf10HelloWorld:
	movel a2,sp@-
	lea ___ti10HelloWorld,a2
	tstl a2@
	jne L236
	jbsr ___tf11Application
	pea 1:w
	pea LC3
	pea LC4
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L236:
	movel #___ti10HelloWorld,d0
	movel sp@+,a2
	rts
