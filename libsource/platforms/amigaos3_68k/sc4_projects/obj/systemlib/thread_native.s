#NO_APP
.globl __6Thread$nextId
.data
	.even
__6Thread$nextId:
	.long 0
.globl __6Thread$numThreads
	.even
__6Thread$numThreads:
	.long 0
.globl __6Thread$numActive
	.even
__6Thread$numActive:
	.long 0
.globl __6Thread$priTab
__6Thread$priTab:
	.byte 0
	.byte -127
	.byte -100
	.byte -10
	.byte -5
	.byte 5
	.byte 10
	.byte 20
	.byte 100
	.byte 0
.globl __6Thread$loggingClassName
.text
LC0:
	.ascii "Thread\0"
.data
	.even
__6Thread$loggingClassName:
	.long LC0
.text
	.even
.globl ___6Thread
___6Thread:
	link a5,#-52
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
	movel #L208,a5@(-12)
	movel sp,a5@(-8)
	jra L207
	.even
L208:
	jra L221
	.even
L207:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_6Thread,a0@
	movel #1481854036,a0@(4)
	clrl a0@(8)
	clrl a0@(12)
	clrl a0@(16)
	clrl a0@(24)
	clrl a0@(28)
	clrl a0@(32)
	pea a0@(36)
	movel d1,a1
	addql #4,a1
	movel a1,a5@(-52)
	jbsr ___Q26Thread7Sleeper
	movel a5@(8),a0
	pea a0@(56)
	jbsr ___5Clock
	movel a5@(8),a1
	clrb a1@(76)
	clrb a1@(77)
	clrb a1@(78)
	clrb a1@(79)
	addql #8,sp
	movel __6Thread$main,a1@(8)
	clrl sp@-
	movel a1,sp@-
	jbsr _sharedInit__6ThreadUl
	addql #8,sp
	movel a5@(8),a1
	movel a1@(8),a0
	movel a0@(62),d0
	subl a0@(58),d0
	subql #2,d0
	movel d0,a1@(72)
	movel a5@(-52),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L220
	.even
L221:
L205:
	movel a5@(-52),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L214,a5@(-36)
	movel sp,a5@(-32)
	jra L213
	.even
L214:
	jra L222
	.even
L213:
	lea a5@(-48),a0
	movel a5@(-52),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_8Runnable,a1@
	movel a5@(-52),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L222:
L211:
	jbsr ___terminate
	.even
L220:
	moveml a5@(-164),#0x5cfc
	fmovem a5@(-124),#0x3f
	unlk a5
	rts
	.even
.globl ___6ThreadQ26Thread8PriorityUl
___6ThreadQ26Thread8PriorityUl:
	link a5,#-52
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
	movel #L229,a5@(-12)
	movel sp,a5@(-8)
	jra L228
	.even
L229:
	jra L241
	.even
L228:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_6Thread,a0@
	movel #1481854036,a0@(4)
	clrl a0@(8)
	clrl a0@(12)
	clrl a0@(16)
	clrl a0@(24)
	clrl a0@(28)
	clrl a0@(32)
	pea a0@(36)
	movel d1,a1
	addql #4,a1
	movel a1,a5@(-52)
	jbsr ___Q26Thread7Sleeper
	movel a5@(8),a0
	pea a0@(56)
	jbsr ___5Clock
	movel a5@(8),a1
	moveb a5@(15),a1@(76)
	clrb a1@(77)
	clrb a1@(78)
	clrb a1@(79)
	addqw #4,sp
	movel a5@(16),sp@
	movel a1,sp@-
	jbsr _sharedInit__6ThreadUl
	addql #8,sp
	movel a5@(-52),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L240
	.even
L241:
L226:
	movel a5@(-52),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L234,a5@(-36)
	movel sp,a5@(-32)
	jra L233
	.even
L234:
	jra L242
	.even
L233:
	lea a5@(-48),a0
	movel a5@(-52),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_8Runnable,a1@
	movel a5@(-52),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L242:
L231:
	jbsr ___terminate
	.even
L240:
	moveml a5@(-164),#0x5cfc
	fmovem a5@(-124),#0x3f
	unlk a5
	rts
	.even
.globl ___6ThreadP8RunnableQ26Thread8PriorityUl
___6ThreadP8RunnableQ26Thread8PriorityUl:
	link a5,#-52
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
	movel #L249,a5@(-12)
	movel sp,a5@(-8)
	jra L248
	.even
L249:
	jra L261
	.even
L248:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_6Thread,a0@
	movel #1481854036,a0@(4)
	clrl a0@(8)
	clrl a0@(12)
	clrl a0@(16)
	movel a5@(12),a0@(24)
	clrl a0@(28)
	clrl a0@(32)
	pea a0@(36)
	movel d1,a1
	addql #4,a1
	movel a1,a5@(-52)
	jbsr ___Q26Thread7Sleeper
	movel a5@(8),a0
	pea a0@(56)
	jbsr ___5Clock
	movel a5@(8),a1
	moveb a5@(19),a1@(76)
	clrb a1@(77)
	clrb a1@(78)
	clrb a1@(79)
	addqw #4,sp
	movel a5@(20),sp@
	movel a1,sp@-
	jbsr _sharedInit__6ThreadUl
	addql #8,sp
	movel a5@(-52),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L260
	.even
L261:
L246:
	movel a5@(-52),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L254,a5@(-36)
	movel sp,a5@(-32)
	jra L253
	.even
L254:
	jra L262
	.even
L253:
	lea a5@(-48),a0
	movel a5@(-52),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_8Runnable,a1@
	movel a5@(-52),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L262:
L251:
	jbsr ___terminate
	.even
L260:
	moveml a5@(-164),#0x5cfc
	fmovem a5@(-124),#0x3f
	unlk a5
	rts
LC1:
	.ascii "exng2_%08X\0"
	.even
.globl _sharedInit__6ThreadUl
_sharedInit__6ThreadUl:
	movel a2,sp@-
	movel sp@(8),a2
	movel sp@(12),d0
	cmpl #4096,d0
	jcc L264
	movel #4096,d0
L264:
	movel d0,a2@(72)
	movel __6Thread$nextId,sp@-
	addql #1,__6Thread$nextId
	pea LC1
	pea a2@(80)
	jbsr _sprintf
	addql #1,__6Thread$numThreads
	addw #12,sp
	tstl a2@(8)
	jne L265
	movel _SysBase,a0
	movel a0@(276),sp@-
	jbsr _threadForTask__6ThreadPQ28OSNative4Task
	movel d0,a2@(20)
	addql #4,sp
	jra L267
	.even
L265:
	clrl a2@(20)
L267:
	movel sp@+,a2
	rts
LC2:
	.ascii "~Thread()\0"
.data
	.even
_loggingFuncName.264:
	.long LC2
.text
LC3:
	.ascii "%s::%s - %s manually terminated (Process crashed?)\12\0"
	.even
.globl __$_6Thread
__$_6Thread:
	movel a2,sp@-
	movel sp@(8),a2
	movel #___vt_6Thread,a2@
	tstl a2@(8)
	jeq L269
	btst #0,a2@(78)
	jeq L270
	movel a2,sp@-
	jbsr _stop__6Thread
	addql #4,sp
L270:
	movel _SysBase,a0
	movel a0@(276),a2@(12)
	orb #128,a2@(79)
	pea 8192:w
	movel a2,sp@-
	jbsr _signalInternal__6ThreadUl
	addql #8,sp
L284:
	tstb a2@(79)
	jge L269
	movel #36864,sp@-
	jbsr _Wait
	addql #4,sp
	cmpl #4096,d0
	jne L284
	andb #127,a2@(79)
	pea a2@(80)
	movel _loggingFuncName.264,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC3
	pea 2:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #20,sp
	jra L284
	.even
L269:
	subql #1,__6Thread$numThreads
	movel #___vt_8Runnable,a2@
	movel sp@(12),d0
	btst #0,d0
	jeq L282
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L282:
	movel sp@+,a2
	rts
	.even
.globl _threadForTask__6ThreadPQ28OSNative4Task
_threadForTask__6ThreadPQ28OSNative4Task:
	movel sp@(4),a0
	cmpl __6Thread$main,a0
	jne L286
	movel __6Thread$rootThread,d0
	rts
	.even
L286:
	tstl a0
	jeq L287
	movel a0@(88),a0
	tstl a0
	jeq L287
	cmpl #1481854036,a0@(4)
	jne L287
	movel a0,d0
	rts
	.even
L287:
	jbsr _throwThreadSecurityViolation
	clrl d0
	rts
	nop
	.even
.globl _getUptime__C6Thread
_getUptime__C6Thread:
	movel a2,sp@-
	movel a1,a2
	movel sp@(8),a0
	btst #0,a0@(78)
	jne L291
	movel a0@(64),d0
	movel a0@(68),d1
	jra L298
	.even
L291:
	pea a0@(56)
	jbsr _elapsed__C5Clock
	movel d0,a0
	addql #4,sp
	movel a0@,d0
	movel a0@(4),d1
L298:
	movel d0,a2@
	movel d1,a2@(4)
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl _setPriority__6ThreadQ26Thread8Priority
_setPriority__6ThreadQ26Thread8Priority:
	movel d2,sp@-
	movel sp@(8),a0
	movel sp@(12),d0
	clrl d2
	moveb a0@(76),d2
	cmpl d2,d0
	jeq L300
	moveb d0,a0@(76)
	movel a0@(8),d1
	jeq L300
	andl #0xFF,d0
	lea __6Thread$priTab,a0
	moveb a0@(d0:l),d0
	extbl d0
	movel d0,sp@-
	movel d1,sp@-
	jbsr _SetTaskPri
	addql #8,sp
L300:
	movel d2,d0
	movel sp@+,d2
	rts
LC4:
	.ascii "setStackSize()\0"
.data
	.even
_loggingFuncName.277:
	.long LC4
.text
LC5:
	.ascii "%s::%s - %s manually interrupted (Process crashed?)\12\0"
	.even
.globl _setStackSize__6ThreadUl
_setStackSize__6ThreadUl:
	moveml #0x3020,sp@-
	movel sp@(16),a2
	movel sp@(20),d2
	movel _SysBase,a0
	movel a0@(276),a0
	cmpl a2@(8),a0
	jne L305
	jbsr _throwThreadSecurityViolation
L305:
	btst #0,a2@(78)
	jeq L308
	jbsr _throwThreadStateViolation
L308:
	movel a2@(72),d3
	cmpl #4096,d2
	jcc L309
	movel #4096,d2
L309:
	cmpl d2,d3
	jeq L310
	tstl a2@(8)
	jeq L311
	movel _SysBase,a0
	movel a0@(276),a2@(12)
	orb #128,a2@(79)
	pea 8192:w
	movel a2,sp@-
	jbsr _signalInternal__6ThreadUl
	addql #8,sp
L319:
	tstb a2@(79)
	jge L314
	movel #36864,sp@-
	jbsr _Wait
	addql #4,sp
	cmpl #4096,d0
	jne L319
	andb #127,a2@(79)
	pea a2@(80)
	movel _loggingFuncName.277,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC5
	pea 2:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #20,sp
	jra L319
	.even
L314:
	clrl a2@(8)
L311:
	movel d2,a2@(72)
L310:
	movel d3,d0
	moveml sp@+,#0x40c
	rts
	.even
.globl _start__6Thread
_start__6Thread:
	movel a2,sp@-
	movel sp@(8),a2
	movel _SysBase,a0
	movel a0@(276),a0
	cmpl a2@(8),a0
	jne L323
	jbsr _throwThreadSecurityViolation
L323:
	btst #0,a2@(78)
	jeq L326
	jbsr _throwThreadStateViolation
L326:
	tstl a2@(8)
	jeq L327
	andb #254,a2@(79)
	movel #32768,sp@-
	movel a2,sp@-
	jbsr _signalInternal__6ThreadUl
	addql #8,sp
	jra L328
	.even
L327:
	movel a2,sp@-
	jbsr _spawn__6Thread
	addql #4,sp
L328:
	movel sp@+,a2
	rts
	.even
.globl _stop__6Thread
_stop__6Thread:
	movel a2,sp@-
	movel sp@(8),a2
	movel _SysBase,a0
	movel a0@(276),a0
	cmpl a2@(8),a0
	jne L332
	jbsr _throwThreadSecurityViolation
L332:
	btst #0,a2@(78)
	jne L335
	jbsr _throwThreadStateViolation
L335:
	movel _SysBase,a0
	movel a0@(276),a2@(12)
	orb #4,a2@(79)
	pea 8192:w
	movel a2,sp@-
	jbsr _signalInternal__6ThreadUl
	addql #8,sp
	btst #2,a2@(79)
	jeq L338
	.even
L339:
	movel #32768,sp@-
	jbsr _Wait
	addql #4,sp
	btst #2,a2@(79)
	jne L339
L338:
	movel sp@+,a2
	rts
	.even
.globl _wake__6Thread
_wake__6Thread:
	movel a2,sp@-
	movel sp@(8),a2
	movel _SysBase,a0
	movel a0@(276),a0
	cmpl a2@(8),a0
	jne L345
	jbsr _throwThreadSecurityViolation
L345:
	btst #0,a2@(78)
	jne L348
	jbsr _throwThreadStateViolation
L348:
	pea 16384:w
	movel a2,sp@-
	jbsr _signalInternal__6ThreadUl
	addql #8,sp
	movel sp@+,a2
	rts
	.even
.globl _signalInternal__6ThreadUl
_signalInternal__6ThreadUl:
	movel sp@(4),a0
	movel sp@(8),sp@-
	movel a0@(8),sp@-
	jbsr _Signal
	addql #8,sp
	rts
	nop
	.even
.globl _signalExternal__6ThreadUl
_signalExternal__6ThreadUl:
	movel sp@(4),a0
	movel sp@(8),sp@-
	movel a0@(12),sp@-
	jbsr _Signal
	addql #8,sp
	rts
	nop
LC6:
	.ascii "spawn()\0"
.data
	.even
_loggingFuncName.296:
	.long LC6
.text
LC7:
	.ascii "%s::%s - %s failed to create Process\12\0"
LC8:
	.ascii "%s::%s - %s failed to initialise\12\0"
	.even
.globl _spawn__6Thread
_spawn__6Thread:
	link a5,#-80
	movel a2,sp@-
	movel d2,sp@-
	movel a5@(8),a2
	movel #-2147482645,a5@(-80)
	movel #_entryPoint__6Thread,a5@(-76)
	movel #-2147482637,a5@(-72)
	movel a2@(72),a5@(-68)
	movel #-2147482635,a5@(-64)
	clrl d0
	moveb a2@(76),d0
	lea __6Thread$priTab,a0
	moveb a0@(d0:l),d0
	extbl d0
	movel d0,a5@(-60)
	movel #-2147482636,a5@(-56)
	moveq #80,d2
	addl a2,d2
	movel d2,a5@(-52)
	clrl a5@(-48)
	clrl a5@(-44)
	movel a5@(-80),a5@(-40)
	movel a5@(-76),a5@(-36)
	movel a5@(-72),a5@(-32)
	movel a5@(-68),a5@(-28)
	movel a5@(-64),a5@(-24)
	movel d0,a5@(-20)
	movel a5@(-56),a5@(-16)
	movel d2,a5@(-12)
	movel a5@(-48),a5@(-8)
	movel a5@(-44),a5@(-4)
	moveb #2,a2@(79)
	movel _SysBase,a0
	movel a0@(276),a2@(12)
	pea a5@(-40)
	jbsr _CreateNewProc
	movel d0,a2@(8)
	addql #4,sp
	jne L353
	clrb a2@(79)
	movel d2,sp@-
	movel _loggingFuncName.296,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC7
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	jbsr _throwThreadStartupFailure
	addw #20,sp
L353:
	movel a2@(8),a0
	movel a2,a0@(88)
	movel #32768,sp@-
	movel a2,sp@-
	jbsr _signalInternal__6ThreadUl
	movel #32768,sp@-
	jbsr _Wait
	addw #12,sp
	btst #1,a2@(79)
	jeq L354
	clrb a2@(79)
	clrl a2@(8)
	movel d2,sp@-
	movel _loggingFuncName.296,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC8
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	jbsr _throwThreadStartupFailure
	addw #20,sp
L354:
	movel a5@(-88),d2
	movel a5@(-84),a2
	unlk a5
	rts
	.even
.globl _enableLowLevelExceptions__6Thread
_enableLowLevelExceptions__6Thread:
	movel sp@(4),a0
	orb #8,a0@(79)
	movel a0@(8),a0
	tstl a0
	jeq L356
	movel #_trapCPU68K,a0@(50)
L356:
	rts
	nop
	.even
.globl _disableLowLevelExceptions__6Thread
_disableLowLevelExceptions__6Thread:
	movel sp@(4),a1
	andb #247,a1@(79)
	movel a1@(8),a0
	tstl a0
	jeq L358
	movel a1@(16),a0@(50)
L358:
	rts
	nop
	.even
.globl _sleep__6ThreadUlUl
_sleep__6ThreadUlUl:
	movel sp@(8),sp@-
	movel sp@(8),sp@-
	clrl sp@-
	jbsr _FindTask
	movel d0,sp@-
	jbsr _threadForTask__6ThreadPQ28OSNative4Task
	addqw #4,sp
	movel d0,sp@
	jbsr _suspend__6ThreadUlUl
	addw #12,sp
	rts
	nop
	.even
.globl _resumeSleep__6Thread
_resumeSleep__6Thread:
	clrl sp@-
	jbsr _FindTask
	movel d0,sp@-
	jbsr _threadForTask__6ThreadPQ28OSNative4Task
	addqw #4,sp
	movel d0,sp@
	jbsr _resumeSuspension__6Thread
	addql #4,sp
	rts
	nop
	.even
.globl _abortSleep__6Thread
_abortSleep__6Thread:
	clrl sp@-
	jbsr _FindTask
	movel d0,sp@-
	jbsr _threadForTask__6ThreadPQ28OSNative4Task
	addqw #4,sp
	movel d0,sp@
	jbsr _abortSuspension__6Thread
	addql #4,sp
	rts
	nop
LC9:
	.ascii "entryPoint()\0"
.data
	.even
_loggingFuncName.315:
	.long LC9
.text
LC10:
	.ascii "%s::%s - Unknown Task 0x%08X\12\0"
	.even
.globl _entryPoint__6Thread
_entryPoint__6Thread:
	link a5,#-84
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-80)
	movel #32768,sp@-
	jbsr _Wait
	movel a5@(-80),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L369,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-84)
	jra L368
	.even
L369:
	movel a5@(-80),a0
	addql #4,a0
	movel a0,a5@(-84)
	jra L366
	.even
L368:
	lea a5@(-24),a1
	movel a1,a0@
	clrl sp@
	jbsr _FindTask
	movel d0,sp@-
	jbsr _threadForTask__6ThreadPQ28OSNative4Task
	addqw #4,sp
	movel d0,sp@
	jbsr _process__6Thread
	movel a5@(-84),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jra L381
	.even
L366:
	jbsr ___start_cp_handler
	movel d0,a5@(-76)
	movel a5@(-84),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L375,a5@(-36)
	movel sp,a5@(-32)
	jra L374
	.even
L375:
	movel a5@(-80),a1
	addql #4,a1
	movel a1,a5@(-84)
	jra L372
	.even
L374:
	lea a5@(-48),a1
	movel a5@(-84),a0
	movel a1,a0@
	movel _SysBase,a0
	movel a0@(276),sp@-
	movel _loggingFuncName.315,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC10
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel a5@(-84),a1
	movel a1@,a0
	movel a0@,a1@
	addw #16,sp
	movel a5@(-76),sp@
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L381
	.even
L372:
	movel a5@(-84),a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L380,a5@(-60)
	movel sp,a5@(-56)
	jra L379
	.even
L380:
	jra L382
	.even
L379:
	lea a5@(-72),a0
	movel a5@(-84),a1
	movel a0,a1@
	movel a5@(-76),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-80),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L382:
L377:
	jbsr ___terminate
	.even
L381:
	moveml a5@(-196),#0x5cfc
	fmovem a5@(-156),#0x3f
	unlk a5
	rts
LC11:
	.ascii "handleWakeup()\0"
.data
	.even
_loggingFuncName.319:
	.long LC11
.text
LC12:
	.ascii "%s::%s - %s [i] woken by termination request\12\0"
LC13:
	.ascii "%s::%s - %s [i] woken by stop() call\12\0"
LC14:
	.ascii "%s::%s - %s [i] woken by wake request\12\0"
LC15:
	.ascii "%s::%s - %s [i] woken by system break signal\12\0"
LC16:
	.ascii "%s::%s - %s [i] woken on timeout\12\0"
LC17:
	.ascii "%s::%s - %s [i] woken by unknown or unexpected signal\12\0"
	.even
.globl _handleWakeup__6ThreadUl
_handleWakeup__6ThreadUl:
	moveml #0x3020,sp@-
	movel sp@(16),a2
	movel sp@(20),d2
	moveq #7,d3
	movel a2@(76),d0
	andl #524416,d0
	jeq L384
	movel a2,sp@-
	jbsr _abortSuspension__6Thread
	addql #4,sp
L384:
	btst #13,d2
	jeq L385
	tstb a2@(79)
	jge L386
	pea a2@(80)
	movel _loggingFuncName.319,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC12
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	moveq #3,d3
	jra L397
	.even
L386:
	pea a2@(80)
	movel _loggingFuncName.319,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC13
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	moveq #2,d3
	jra L397
	.even
L385:
	btst #14,d2
	jeq L389
	moveb a2@(77),d0
	eorb #1,d0
	btst #0,d0
	jeq L389
	pea a2@(80)
	movel _loggingFuncName.319,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC14
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	moveq #1,d3
	jra L397
	.even
L389:
	btst #12,d2
	jeq L391
	btst #1,a2@(77)
	jne L391
	pea a2@(80)
	movel _loggingFuncName.319,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC15
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	moveq #4,d3
	jra L397
	.even
L391:
	andl a2@(44),d2
	jeq L393
	pea a2@(80)
	movel _loggingFuncName.319,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC16
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	clrl d3
	jra L397
	.even
L393:
	pea a2@(80)
	movel _loggingFuncName.319,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC17
	pea 2:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
L397:
	addw #20,sp
	movel a2@(32),a1
	tstl a1
	jeq L396
	movel a1@,a0
	movel d3,sp@-
	movel a2,sp@-
	movel a1,sp@-
	movel a0@(12),a0
	jbsr a0@
	addw #12,sp
L396:
	movel d3,d0
	moveml sp@+,#0x40c
	rts
LC18:
	.ascii "suspend()\0"
.data
	.even
_loggingFuncName.323:
	.long LC18
.text
LC19:
	.ascii "%s::%s - %s [i] sleeping for %lu ms, interruptable on signals: 0x%08X\12\0"
	.even
.globl _suspend__6ThreadUlUl
_suspend__6ThreadUlUl:
	moveml #0x3830,sp@-
	movel sp@(24),a3
	movel sp@(28),d4
	movel sp@(32),d3
	movel _SysBase,a0
	movel a0@(276),a0
	cmpl a3@(8),a0
	jeq L401
	jbsr _throwThreadSecurityViolation
L401:
	movel #28672,d2
	btst #0,d3
	jeq L402
	movel #12288,d2
L402:
	btst #1,d3
	jeq L403
	andw #61439,d2
L403:
	moveb d3,a3@(77)
	lea a3@(36),a2
	movel d2,d0
	orl a2@(8),d0
	movel d0,sp@-
	movel d4,sp@-
	pea a3@(80)
	movel _loggingFuncName.323,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC19
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel d2,sp@-
	movel d4,sp@-
	movel a2,sp@-
	jbsr _suspend__Q26Thread7SleeperUlUl
	movel d0,sp@-
	movel a3,sp@-
	jbsr _handleWakeup__6ThreadUl
	addw #48,sp
	moveml sp@+,#0xc1c
	rts
	.even
.globl _abortSuspension__6Thread
_abortSuspension__6Thread:
	movel a2,sp@-
	movel sp@(8),a2
	movel _SysBase,a0
	movel a0@(276),a0
	cmpl a2@(8),a0
	jeq L408
	jbsr _throwThreadSecurityViolation
L408:
	orb #8,a2@(77)
	pea a2@(36)
	jbsr _abortDelay__Q26Thread7Sleeper
	addql #4,sp
	movel sp@+,a2
	rts
	.even
.globl _resumeSuspension__6Thread
_resumeSuspension__6Thread:
	movel a2,sp@-
	movel sp@(8),a2
	movel _SysBase,a0
	movel a0@(276),a0
	cmpl a2@(8),a0
	jeq L412
	jbsr _throwThreadSecurityViolation
L412:
	btst #3,a2@(77)
	jne L413
	pea a2@(36)
	jbsr _suspend__Q26Thread7Sleeper
	movel d0,sp@-
	movel a2,sp@-
	jbsr _handleWakeup__6ThreadUl
	addw #12,sp
	jra L409
	.even
L413:
	moveq #6,d0
L409:
	movel sp@+,a2
	rts
	.even
.globl _run__6Thread
_run__6Thread:
	movel sp@(4),a0
	movel a0@(24),a1
	tstl a1
	jeq L416
	movel a1@,a0
	movel a1,sp@-
	movel a0@(12),a0
	jbsr a0@
	addql #4,sp
	rts
	.even
L416:
	jbsr _throwThreadStartupFailure
	clrl d0
	rts
	nop
LC20:
	.ascii "process()\0"
.data
	.even
_loggingFuncName.336:
	.long LC20
.text
LC21:
	.ascii "%s::%s - %s [i] starting\12\0"
LC22:
	.ascii "%s::%s - %s [i] completed with returncode %d\12\0"
LC23:
	.ascii "%s::%s - %s [i] threw %s\12\0"
LC24:
	.ascii "%s::%s - %s [i] threw exception\12\0"
LC25:
	.ascii "%s::%s - %s [i] parking\12\0"
LC26:
	.ascii "%s::%s - %s [i] terminating\12\0"
	.even
.globl _process__6Thread
_process__6Thread:
	link a5,#-160
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-148)
	moveq #36,d0
	addl a5@(8),d0
	movel d0,a5@(-124)
	movel d0,sp@-
	jbsr _init__Q26Thread7Sleeper
	addql #4,sp
	tstb d0
	jeq L418
	movel a5@(8),a1
	movel a1@(8),a0
	movel a0@(62),d0
	subl a0@(58),d0
	subql #2,d0
	movel d0,a1@(72)
	btst #3,a1@(79)
	jeq L420
	movel #_trapCPU68K,a0@(50)
L420:
	movel a5@(8),a0
	clrb a0@(79)
	movel #32768,sp@-
	movel a0,sp@-
	jbsr _signalExternal__6ThreadUl
	addql #8,sp
	movel a5@(-124),a5@(-160)
	moveq #80,d0
	addl a5@(8),d0
	movel d0,a5@(-152)
	movel a5@(8),a0
	tstb a0@(79)
	jlt L422
	.even
L423:
	movel a5@(-152),sp@-
	movel _loggingFuncName.336,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC21
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #1,__6Thread$numActive
	movel a5@(-148),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L427,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-156)
	jra L426
	.even
L427:
	moveq #36,d0
	addl a5@(8),d0
	movel d0,a5@(-160)
	moveq #80,d0
	addl a5@(8),d0
	movel d0,a5@(-152)
	movel a5@(-148),a0
	addql #4,a0
	movel a0,a5@(-156)
	jra L424
	.even
L426:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	moveb #1,a0@(78)
	moveq #56,d0
	addl a0,d0
	movel d0,a5@(-132)
	movel d0,sp@-
	jbsr _set__5Clock
	movel a5@(8),a1
	movel a1@,a0
	movel a1,sp@-
	movel a0@(12),a0
	jbsr a0@
	movel d0,a5@(-128)
	movel a5@(-132),sp@-
	jbsr _elapsed__C5Clock
	movel a5@(8),a0
	moveb a0@(78),d0
	andb #254,d0
	orb #2,d0
	moveb d0,a0@(78)
	addw #28,sp
	movel a5@(-128),sp@
	movel a5@(-152),sp@-
	movel _loggingFuncName.336,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC22
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #24,sp
	movel a5@(8),a0
	movel a0@(28),a1
	tstl a1
	jeq L428
	movel a1@,a0
	movel a5@(-128),sp@-
	movel a5@(8),sp@-
	movel a1,sp@-
	movel a0@(12),a0
	jbsr a0@
	addw #12,sp
L428:
	movel a5@(-156),a1
	movel a1@,a0
	movel a0@,a1@
L429:
	movel a5@(8),a0
	moveb a0@(79),d0
	btst #2,d0
	jeq L442
	andb #251,d0
	moveb d0,a0@(79)
	movel #32768,sp@-
	movel a0,sp@-
	jbsr _signalExternal__6ThreadUl
	addql #8,sp
L442:
	subql #1,__6Thread$numActive
	movel a5@(8),a1
	moveb a1@(79),d0
	orb #1,d0
	moveb d0,a1@(79)
	jra L459
	.even
L445:
	movel a5@(-152),sp@-
	movel _loggingFuncName.336,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC25
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel #40960,sp@-
	jbsr _Wait
	addw #24,sp
	movel a5@(8),a0
	moveb a0@(79),d0
L459:
	andb #129,d0
	cmpb #1,d0
	jeq L445
	movel a5@(8),a1
	tstb a1@(79)
	jge L423
L422:
	movel a5@(-152),sp@-
	movel _loggingFuncName.336,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC26
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel a5@(8),a1
	movel a1@(8),a0
	movel a1@(16),a0@(50)
	movel a5@(-160),sp@-
	jbsr _done__Q26Thread7Sleeper
	movel a5@(8),a0
	andb #127,a0@(79)
	addw #24,sp
	jra L448
	.even
L418:
	movel a5@(8),a1
	moveb #2,a1@(79)
L448:
	movel #32768,sp@-
	movel a5@(8),sp@-
	jbsr _signalExternal__6ThreadUl
	addql #8,sp
	jra L457
	.even
L424:
	pea ___tf12RuntimeError
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L436
	jbsr ___start_cp_handler
	movel d0,a5@(-136)
	movel a5@(-156),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L434,a5@(-36)
	movel sp,a5@(-32)
	jra L433
	.even
L434:
	movel a5@(-148),a1
	addql #4,a1
	movel a1,a5@(-156)
	jra L431
	.even
L433:
	lea a5@(-48),a1
	movel a5@(-156),a0
	movel a1,a0@
	movel a5@(-136),a0
	movel a0@(8),a5@(-140)
	movel a5@(8),a1
	moveb a1@(78),d0
	andb #254,d0
	orb #8,d0
	moveb d0,a1@(78)
	movel a5@(-140),a1
	movel a1@,a0
	movel a1,sp@-
	movel a0@(12),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-152),sp@-
	movel _loggingFuncName.336,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC23
	pea 2:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #28,sp
	movel a5@(8),a0
	movel a0@(28),a1
	tstl a1
	jeq L435
	movel a1@,a0
	movel a5@(-140),sp@-
	movel a5@(8),sp@-
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addw #12,sp
L435:
	movel a5@(-156),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(-136),sp@-
	jra L460
	.even
L436:
	jbsr ___start_cp_handler
	movel d0,a5@(-144)
	movel a5@(-156),a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L440,a5@(-60)
	movel sp,a5@(-56)
	jra L439
	.even
L440:
	movel a5@(-148),a1
	addql #4,a1
	movel a1,a5@(-156)
	jra L437
	.even
L439:
	lea a5@(-72),a1
	movel a5@(-156),a0
	movel a1,a0@
	movel a5@(8),a0
	moveb a0@(78),d0
	andb #254,d0
	orb #8,d0
	moveb d0,a0@(78)
	movel a5@(-152),sp@-
	movel _loggingFuncName.336,sp@-
	movel __6Thread$loggingClassName,sp@-
	pea LC24
	pea 2:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #20,sp
	movel a5@(8),a0
	movel a0@(28),a1
	tstl a1
	jeq L441
	movel a1@,a0
	clrl sp@-
	movel a5@(8),sp@-
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addw #12,sp
L441:
	movel a5@(-156),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(-144),sp@-
L460:
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L429
	.even
L431:
	movel a5@(-156),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L452,a5@(-84)
	movel sp,a5@(-80)
	jra L451
	.even
L452:
	jra L461
	.even
L451:
	lea a5@(-96),a0
	movel a5@(-156),a1
	movel a0,a1@
	movel a5@(-136),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-148),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L437:
	movel a5@(-156),a1
	movel a1@,a5@(-120)
	clrl a5@(-116)
	movel a5,a5@(-112)
	movel #L456,a5@(-108)
	movel sp,a5@(-104)
	jra L455
	.even
L456:
	jra L462
	.even
L455:
	lea a5@(-120),a1
	movel a5@(-156),a0
	movel a1,a0@
	movel a5@(-144),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-148),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L461:
L449:
	jbsr ___terminate
	.even
L462:
L453:
	jbsr ___terminate
	.even
L457:
	moveml a5@(-272),#0x5cfc
	fmovem a5@(-232),#0x3f
	unlk a5
	rts
	.even
.globl ___Q211EXNGPrivate17RootThreadWrapper
___Q211EXNGPrivate17RootThreadWrapper:
	link a5,#-56
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-52)
	movel a5@(8),sp@-
	jbsr ___6Thread
	movel a5@(-52),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L467,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-56)
	jra L466
	.even
L467:
	movel a5@(-52),a0
	addql #4,a0
	movel a0,a5@(-56)
	jra L464
	.even
L466:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_Q211EXNGPrivate17RootThreadWrapper,a0@
	addql #4,sp
	pea a0@(36)
	jbsr _init__Q26Thread7Sleeper
	movel a5@(8),a1
	pea a1@(56)
	jbsr _set__5Clock
	movel a5@(8),a0
	moveb #1,a0@(78)
	movel a0@(8),a0
	movel a5@(8),a1
	movel a0@(50),a1@(16)
	addql #8,sp
	movel a5@(-56),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L474
	.even
L464:
	movel a5@(-56),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L472,a5@(-36)
	movel sp,a5@(-32)
	jra L471
	.even
L472:
	jra L475
	.even
L471:
	lea a5@(-48),a0
	movel a5@(-56),a1
	movel a0,a1@
	clrl sp@-
	movel a5@(8),sp@-
	jbsr __$_6Thread
	movel a5@(-52),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jbsr ___sjthrow
	.even
L475:
L469:
	jbsr ___terminate
	.even
L474:
	moveml a5@(-168),#0x5cfc
	fmovem a5@(-128),#0x3f
	unlk a5
	rts
	.even
.globl __$_Q211EXNGPrivate17RootThreadWrapper
__$_Q211EXNGPrivate17RootThreadWrapper:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel sp@(16),d2
	movel #___vt_Q211EXNGPrivate17RootThreadWrapper,a2@
	pea a2@(36)
	jbsr _done__Q26Thread7Sleeper
	movel a2@(8),a0
	movel a2@(16),a0@(50)
	clrl a2@(8)
	movel d2,sp@
	movel a2,sp@-
	jbsr __$_6Thread
	addql #8,sp
	movel sp@+,d2
	movel sp@+,a2
	rts
	.even
.globl _run__Q211EXNGPrivate17RootThreadWrapper
_run__Q211EXNGPrivate17RootThreadWrapper:
	jbsr _throwThreadStateViolation
	clrl d0
	rts
	nop
.lcomm _root.349,96
.lcomm __$tmp_0.350,4
	.even
___tcf_0:
	pea 2:w
	pea _root.349
	jbsr __$_Q211EXNGPrivate17RootThreadWrapper
	addql #8,sp
	rts
	nop
	.even
.globl _bind__Q211EXNGPrivate17RootThreadWrapper
_bind__Q211EXNGPrivate17RootThreadWrapper:
	tstl __$tmp_0.350
	jne L480
	pea _root.349
	jbsr ___Q211EXNGPrivate17RootThreadWrapper
	addql #4,sp
	moveq #1,d0
	movel d0,__$tmp_0.350
	pea ___tcf_0
	jbsr _atexit
	addql #4,sp
L480:
	movel #_root.349,d0
	rts
	nop
.globl ___vt_Q211EXNGPrivate17RootThreadWrapper
	.even
___vt_Q211EXNGPrivate17RootThreadWrapper:
	.long 0
	.long ___tfQ211EXNGPrivate17RootThreadWrapper
	.long __dfRTTI__6Thread
	.long _run__Q211EXNGPrivate17RootThreadWrapper
	.long __$_Q211EXNGPrivate17RootThreadWrapper
	.skip 4
.globl __6Thread$main
	.bss
__6Thread$main:
	.skip 4
.globl __6Thread$rootThread
__6Thread$rootThread:
	.skip 4
.text
	.even
___static_initialization_and_destruction_0:
	cmpl #65535,sp@(8)
	jne L484
	tstl sp@(4)
	jeq L484
	movel _SysBase,a0
	movel a0@(276),__6Thread$main
	jbsr _bind__Q211EXNGPrivate17RootThreadWrapper
	movel d0,__6Thread$rootThread
L484:
	rts
	nop
.comm ___tiQ211EXNGPrivate17RootThreadWrapper,12
LC27:
	.ascii "Q211EXNGPrivate17RootThreadWrapper\0"
	.even
.globl ___tfQ211EXNGPrivate17RootThreadWrapper
___tfQ211EXNGPrivate17RootThreadWrapper:
	movel a2,sp@-
	lea ___tiQ211EXNGPrivate17RootThreadWrapper,a2
	tstl a2@
	jne L488
	jbsr ___tf6Thread
	pea ___ti6Thread
	pea LC27
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L488:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl _INIT_8__6Thread$nextIdthread_native_cpp
_INIT_8__6Thread$nextIdthread_native_cpp:
	movel #65535,sp@-
	pea 1:w
	jbsr ___static_initialization_and_destruction_0
	addql #8,sp
	rts
	nop
.stabs "___CTOR_LIST__",22,0,0,_INIT_8__6Thread$nextIdthread_native_cpp
