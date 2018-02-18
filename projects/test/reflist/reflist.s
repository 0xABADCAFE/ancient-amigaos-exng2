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
	movel #L130,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L129
	.even
L130:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L127
	.even
L129:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___14RefListTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L126
	.even
L127:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L136,a5@(-36)
	movel sp,a5@(-32)
	jra L135
	.even
L136:
	jra L140
	.even
L135:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L138
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L138:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L140:
L133:
	jbsr ___terminate
	.even
L126:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L149
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L149:
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
	movel #L155,a5@(-12)
	movel sp,a5@(-8)
L155:
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
	movel #L169,a5@(-60)
	movel sp,a5@(-56)
	movel a0,a5@(-214)
	jra L168
	.even
L169:
	jra L215
	.even
L168:
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
	movel #L184,a5@(-84)
	movel sp,a5@(-80)
	jra L183
	.even
L184:
	jra L216
	.even
L183:
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
	movel #L187,a5@(-108)
	movel sp,a5@(-104)
	movel a0,a1
L187:
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
	jra L214
	.even
L216:
L181:
	movel a5@(-214),a0
	movel a0@,a5@(-168)
	clrl a5@(-164)
	lea a5@(-160),a0
	movel a5,a0@
	movel #L200,a0@(4)
	movel sp,a0@(8)
	jra L199
	.even
L200:
	jra L217
	.even
L199:
	lea a5@(-168),a2
	movel a5@(-214),a1
	movel a2,a1@
	tstb a5@(-201)
	jeq L202
	movel a5@(-200),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L202:
	movel a5@(-214),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L215:
L166:
	movel a5@(-214),a2
	movel a2@,a5@(-192)
	clrl a5@(-188)
	lea a5@(-184),a0
	movel a5,a0@
	movel #L206,a0@(4)
	movel sp,a0@(8)
	jra L205
	.even
L206:
	jra L218
	.even
L205:
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
L217:
L197:
	jbsr ___terminate
	.even
L218:
L203:
	jbsr ___terminate
	.even
L214:
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
	jeq L223
	pea 3:w
	movel d0,sp@-
	jbsr __$_Q211EXNGPrivate8VoidList
	addql #8,sp
L223:
	pea LC1
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel #___vt_8Runnable,a2@
	movel sp@(12),d0
	btst #0,d0
	jeq L232
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L232:
	movel sp@+,a2
	rts
LC2:
	.ascii "sizeof(RefList<uint8>) = %d\12\0"
LC3:
	.ascii "sizeof(RefListFwdIterator<uint8>) = %d\12\0"
LC4:
	.ascii "sizeof(RefListEevIterator<uint8>) = %d\12\0"
LC5:
	.ascii "Created forward iterator\12\0"
LC6:
	.ascii "0x%08X\12\0"
LC7:
	.ascii "Created reverse iterator\12\0"
	.even
.globl _run__14RefListTestApp
_run__14RefListTestApp:
	addw #-20,sp
	moveml #0x203e,sp@-
	movel sp@(48),a3
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
	movel a2,a5
	tstl a3@(6)
	jeq L234
	clrl d2
	lea sp@(32),a2
	lea _puts,a6
	lea sp@(24),a4
	.even
L238:
	movel d2,d0
	orl #-267583488,d0
	movel d0,sp@-
	movel a3@(6),sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	movel d2,d0
	addql #1,d0
	orl #-267583488,d0
	movel d0,sp@-
	movel a3@(6),sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	movel d2,d0
	addql #2,d0
	orl #-267583488,d0
	movel d0,sp@-
	movel a3@(6),sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	movel d2,d0
	addql #3,d0
	orl #-267583488,d0
	movel d0,sp@-
	movel a3@(6),sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	movel d2,d0
	addql #4,d0
	orl #-267583488,d0
	movel d0,sp@-
	movel a3@(6),sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	movel d2,d0
	addql #5,d0
	orl #-267583488,d0
	movel d0,sp@-
	movel a3@(6),sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	movel d2,d0
	addql #6,d0
	orl #-267583488,d0
	movel d0,sp@-
	movel a3@(6),sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	movel d2,d0
	addql #7,d0
	orl #-267583488,d0
	movel d0,sp@-
	movel a3@(6),sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	addql #8,d2
	moveq #15,d0
	cmpl d2,d0
	jge L238
	movel a3@(6),a2@
	moveq #-1,d0
	movel d0,a2@(4)
	pea LC5
	jbsr a6@
	addql #4,sp
	movel a2@,a0
	movel a0@,a2@(4)
	movel a2@(4),d0
	jge L315
	jra L265
	.even
L261:
	movel d1,sp@-
	pea LC6
	jbsr a5@
	addql #8,sp
	movel a2@(4),d0
	jlt L265
L315:
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a2@(4)
	jra L266
	.even
L265:
	clrl d1
L266:
	tstl d1
	jne L261
	movel a3@(6),a4@
	moveq #-1,d0
	movel d0,a4@(4)
	pea LC7
	jbsr a6@
	addql #4,sp
	movel a4@,a0
	movel a0@(4),a4@(4)
	movel a4@(4),d0
	jge L316
	jra L292
	.even
L288:
	movel d1,sp@-
	pea LC6
	jbsr a5@
	addql #8,sp
	movel a4@(4),d0
	jlt L292
L316:
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(d0:l),a4@(4)
	jra L293
	.even
L292:
	clrl d1
L293:
	tstl d1
	jne L288
L234:
	clrl d0
	moveml sp@+,#0x7c04
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
LC8:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC9:
	.ascii "14RefListTestApp\0"
	.even
.globl ___tf14RefListTestApp
___tf14RefListTestApp:
	movel a2,sp@-
	lea ___ti14RefListTestApp,a2
	tstl a2@
	jne L318
	jbsr ___tf11Application
	pea 1:w
	pea LC8
	pea LC9
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L318:
	movel a2,d0
	movel sp@+,a2
	rts
