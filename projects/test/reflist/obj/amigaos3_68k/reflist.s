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
	pea 10:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L193,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L192
	.even
L193:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L190
	.even
L192:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___14RefListTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L189
	.even
L190:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L199,a5@(-36)
	movel sp,a5@(-32)
	jra L198
	.even
L199:
	jra L203
	.even
L198:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L201
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L201:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L203:
L196:
	jbsr ___terminate
	.even
L189:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L212
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L212:
	rts
	nop
LC0:
	.ascii "Created RefListTestApp\12\0"
	.even
.globl ___14RefListTestApp
___14RefListTestApp:
	link a5,#-216
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-196)
	movel d0,a5@(-210)
	movel a5@(8),a0
	movel #___vt_8Runnable,a0@
	movel a5@(-196),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L218,a5@(-12)
	movel sp,a5@(-8)
L218:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a2
	movel #___vt_11Application,a2@
	movel a5@(-210),a0
	addql #4,a0
	movel a0@,a1
	movel a1@,a0@
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L232,a5@(-60)
	movel sp,a5@(-56)
	movel a0,a5@(-214)
	jra L231
	.even
L232:
	jra L278
	.even
L231:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a2
	movel #___vt_14RefListTestApp,a2@
	pea 16:w
	jbsr ___builtin_new
	movel d0,a5@(-200)
	moveb #1,a5@(-201)
	movel a5@(-214),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L247,a5@(-84)
	movel sp,a5@(-80)
	jra L246
	.even
L247:
	jra L279
	.even
L246:
	lea a5@(-96),a1
	movel a1,a5@(-206)
	movel a5@(-214),a2
	movel a1,a2@
	addql #4,sp
	movel a5@(-210),d0
	movel a5@(-200),sp@-
	jbsr ___Q211EXNGPrivate8VoidList
	movel a5@(-196),a0
	addql #4,a0
	movel a0@,a5@(-120)
	clrl a5@(-116)
	movel a5@(-206),a5@(-112)
	movel #L250,a5@(-108)
	movel sp,a5@(-104)
	movel a0,a1
L250:
	lea a5@(-120),a2
	movel a2,a0@
	addql #4,sp
	movel a1@,a0
	movel a0@,a1@
	clrb a5@(-201)
	movel a5@(8),a0
	movel a5@(-200),a0@(6)
	movel a5@(-214),a1
	movel a1@,a0
	movel a0@,a1@
	pea LC0
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel a5@(-214),a2
	movel a2@,a0
	movel a0@,a2@
	movel a5@(8),d0
	jra L277
	.even
L279:
L244:
	movel a5@(-214),a0
	movel a0@,a5@(-168)
	clrl a5@(-164)
	lea a5@(-160),a0
	movel a5,a0@
	movel #L263,a0@(4)
	movel sp,a0@(8)
	jra L262
	.even
L263:
	jra L280
	.even
L262:
	lea a5@(-168),a2
	movel a5@(-214),a1
	movel a2,a1@
	tstb a5@(-201)
	jeq L265
	movel a5@(-200),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L265:
	movel a5@(-214),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L278:
L229:
	movel a5@(-214),a2
	movel a2@,a5@(-192)
	clrl a5@(-188)
	lea a5@(-184),a0
	movel a5,a0@
	movel #L269,a0@(4)
	movel sp,a0@(8)
	jra L268
	.even
L269:
	jra L281
	.even
L268:
	lea a5@(-192),a1
	movel a5@(-214),a0
	movel a1,a0@
	movel a5@(8),a2
	movel #___vt_8Runnable,a2@
	movel a0@,a0
	movel a5@(-214),a1
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L280:
L260:
	jbsr ___terminate
	.even
L281:
L266:
	jbsr ___terminate
	.even
L277:
	moveml a5@(-328),#0x5cfc
	fmovem a5@(-288),#0x3f
	unlk a5
	rts
LC1:
	.ascii "Destroyed RefListTestApp\12\0"
	.even
.globl __$_14RefListTestApp
__$_14RefListTestApp:
	movel a2,sp@-
	movel sp@(8),a2
	movel #___vt_14RefListTestApp,a2@
	movel a2@(6),d0
	jeq L286
	pea 3:w
	movel d0,sp@-
	jbsr __$_Q211EXNGPrivate8VoidList
	addql #8,sp
L286:
	pea LC1
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel #___vt_8Runnable,a2@
	movel sp@(12),d0
	btst #0,d0
	jeq L295
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L295:
	movel sp@+,a2
	rts
LC2:
	.ascii "sizeof(RefList<uint8>) = %d\12\0"
LC3:
	.ascii "sizeof(RefList<uint8>::Iterator>) = %d\12\0"
LC4:
	.ascii "sizeof(RefList<uint8>::RevIterator) = %d\12\0"
LC5:
	.ascii "Pushing 0x%08X to back of list\12\0"
LC6:
	.ascii "Created forward iterator\12\0"
LC7:
	.ascii "0x%08X\12\0"
LC8:
	.ascii "Iterator broke!\12\0"
LC9:
	.ascii "Created reverse iterator\12\0"
	.even
.globl _run__14RefListTestApp
_run__14RefListTestApp:
	addw #-20,sp
	moveml #0x303e,sp@-
	movel sp@(52),a5
	pea 16:w
	pea LC2
	lea _printf,a2
	jbsr a2@
	pea 8:w
	pea LC3
	jbsr a2@
	pea 8:w
	pea LC4
	jbsr a2@
	addw #24,sp
	movel a2,a4
	tstl a5@(6)
	jeq L297
	clrl d3
	lea sp@(36),a2
	lea _puts,a6
	lea sp@(28),a3
	.even
L301:
	movel d3,d2
	orl #-267583488,d2
	movel d2,sp@-
	pea LC5
	jbsr a4@
	addqw #4,sp
	movel d2,sp@
	movel a5@(6),sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	movel d3,d2
	addql #1,d2
	orl #-267583488,d2
	movel d2,sp@-
	pea LC5
	jbsr a4@
	addqw #4,sp
	movel d2,sp@
	movel a5@(6),sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	movel d3,d2
	addql #2,d2
	orl #-267583488,d2
	movel d2,sp@-
	pea LC5
	jbsr a4@
	addqw #4,sp
	movel d2,sp@
	movel a5@(6),sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	movel d3,d2
	addql #3,d2
	orl #-267583488,d2
	movel d2,sp@-
	pea LC5
	jbsr a4@
	addqw #4,sp
	movel d2,sp@
	movel a5@(6),sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	addql #4,d3
	moveq #15,d0
	cmpl d3,d0
	jge L301
	clrl d2
	movel a5@(6),a2@
	moveq #-1,d0
	movel d0,a2@(4)
	pea LC6
	jbsr a6@
	addql #4,sp
	movel a2@,a0
	movel a0@,a2@(4)
	movel a2@(4),d0
	jge L369
	jra L329
	.even
L323:
	movel a2@(4),d0
	jlt L329
L369:
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a2@(4)
	jra L321
	.even
L329:
	clrl d1
L321:
	tstl d1
	jeq L322
	movel d1,sp@-
	pea LC7
	jbsr a4@
	addql #1,d2
	addql #8,sp
	moveq #16,d0
	cmpl d2,d0
	jge L323
	pea LC8
	jbsr a4@
	addql #4,sp
L322:
	clrl d2
	movel a5@(6),a3@
	moveq #-1,d0
	movel d0,a3@(4)
	pea LC9
	jbsr a6@
	addql #4,sp
	movel a3@,a0
	movel a0@(4),a3@(4)
	movel a3@(4),d0
	jge L370
	jra L357
	.even
L351:
	movel a3@(4),d0
	jlt L357
L370:
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(d0:l),a3@(4)
	jra L349
	.even
L357:
	clrl d1
L349:
	tstl d1
	jeq L297
	movel d1,sp@-
	pea LC7
	jbsr a4@
	addql #1,d2
	addql #8,sp
	moveq #16,d0
	cmpl d2,d0
	jge L351
	pea LC8
	jbsr a4@
	addql #4,sp
L297:
	clrl d0
	moveml sp@+,#0x7c0c
	addw #20,sp
	rts
.globl ___vt_14RefListTestApp
	.even
___vt_14RefListTestApp:
	.long 0
	.long ___tf14RefListTestApp
	.long __dfRTTI__11Application
	.long _run__14RefListTestApp
	.long __$_14RefListTestApp
	.skip 4
.comm ___ti14RefListTestApp,16
	.even
LC10:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC11:
	.ascii "14RefListTestApp\0"
	.even
.globl ___tf14RefListTestApp
___tf14RefListTestApp:
	movel a2,sp@-
	lea ___ti14RefListTestApp,a2
	tstl a2@
	jne L372
	jbsr ___tf11Application
	pea 1:w
	pea LC10
	pea LC11
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L372:
	movel a2,d0
	movel sp@+,a2
	rts
