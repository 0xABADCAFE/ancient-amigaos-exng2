#NO_APP
.text
LC0:
	.ascii "w\0"
LC1:
	.ascii "CON:32/32/640/240/MyThread/CLOSE/WAIT\0"
LC2:
	.ascii "This console is used by the created thread for output\12\0"
	.even
.globl ___8MyThread
___8MyThread:
	link a5,#-104
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-100)
	pea 4096:w
	clrl sp@-
	movel a5@(8),sp@-
	jbsr ___6ThreadQ26Thread8PriorityUl
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L233,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-104)
	jra L232
	.even
L233:
	movel a5@(-100),a0
	addql #4,a0
	movel a0,a5@(-104)
	jra L230
	.even
L232:
	lea a5@(-24),a1
	movel a1,a0@
	addw #12,sp
	movel a5@(8),a0
	movel #___vt_Q26Thread11RunObserver,a0@(96)
	movel a5@(-104),a1
	movel a1@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L241,a5@(-36)
	movel sp,a5@(-32)
	jra L240
	.even
L241:
	movel a5@(-100),a0
	addql #4,a0
	movel a0,a5@(-104)
	jra L238
	.even
L240:
	lea a5@(-48),a0
	movel a5@(-104),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_8MyThread$Q26Thread11RunObserver,a1@(96)
	movel #___vt_8MyThread,a1@
	moveq #2,d0
	movel d0,a1@(104)
	clrl a1@(108)
	clrb a1@(112)
	pea LC0
	pea LC1
	jbsr _fopen
	movel a5@(8),a0
	movel d0,a0@(100)
	addql #8,sp
	jeq L242
	pea LC2
	movel d0,sp@-
	jbsr _fprintf
	movel a5@(8),a1
	movel a1@(100),sp@-
	jbsr _fflush
	addw #12,sp
L242:
	movel a5@(-104),a1
	movel a1@,a0
	movel a0@,a1@
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L257
	.even
L238:
	movel a5@(-104),a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L247,a5@(-60)
	movel sp,a5@(-56)
	jra L246
	.even
L247:
	jra L258
	.even
L246:
	lea a5@(-72),a0
	movel a5@(-104),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_Q26Thread11RunObserver,a1@(96)
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L230:
	movel a5@(-104),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L255,a5@(-84)
	movel sp,a5@(-80)
	jra L254
	.even
L255:
	jra L259
	.even
L254:
	lea a5@(-96),a0
	movel a5@(-104),a1
	movel a0,a1@
	clrl sp@-
	movel a5@(8),sp@-
	jbsr __$_6Thread
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jbsr ___sjthrow
	.even
L258:
L244:
	jbsr ___terminate
	.even
L259:
L252:
	jbsr ___terminate
	.even
L257:
	moveml a5@(-216),#0x5cfc
	fmovem a5@(-176),#0x3f
	unlk a5
	rts
LC3:
	.ascii "\12Bye!\12\0"
	.even
.globl __$_8MyThread
__$_8MyThread:
	movel a2,sp@-
	movel sp@(8),a2
	movel #___vt_8MyThread$Q26Thread11RunObserver,a2@(96)
	movel #___vt_8MyThread,a2@
	btst #0,a2@(78)
	jeq L261
	movel a2,sp@-
	jbsr _stop__6Thread
	addql #4,sp
L261:
	movel a2@(100),d0
	jeq L264
	pea LC3
	movel d0,sp@-
	jbsr _fprintf
	movel a2@(100),sp@-
	jbsr _fclose
	addw #12,sp
L264:
	movel #___vt_Q26Thread11RunObserver,a2@(96)
	movel sp@(12),sp@-
	movel a2,sp@-
	jbsr __$_6Thread
	addql #8,sp
	movel sp@+,a2
	rts
LC4:
	.ascii "MyThread::run() invoked OK\12\0"
LC5:
	.ascii "Sleeping for 500ms...\0"
LC6:
	.ascii "OK\12\0"
LC7:
	.ascii "interrupted by wake()\12\0"
LC8:
	.ascii "interrupted by stop()\12\0"
LC9:
	.ascii "interrupted by system break\12\0"
LC10:
	.ascii "interrupted by user signal\12\0"
LC11:
	.ascii "interrupted by ~Thread()\12\0"
LC12:
	.ascii "interrupted by unknown\12\0"
LC13:
	.ascii "\12MyThread::run() completed\12\0"
	.even
.globl _run__8MyThread
_run__8MyThread:
	moveml #0x38,sp@-
	movel sp@(16),a4
	lea a4@(96),a0
	movel a0,a4@(28)
	tstl a4@(100)
	jne L271
	jbsr _throwNullPointer
L271:
	pea LC4
	movel a4@(100),sp@-
	lea _fprintf,a3
	jbsr a3@
	movel a4@(100),sp@-
	lea _fflush,a2
	jbsr a2@
	movel a4,sp@-
	jbsr _enableLowLevelExceptions__6Thread
	addw #16,sp
	jra L272
	.even
L274:
	pea LC5
	movel a4@(100),sp@-
	jbsr a3@
	movel a4@(100),sp@-
	jbsr a2@
	addqw #8,sp
	movel #12,sp@
	pea 500:w
	movel a4,sp@-
	jbsr _suspend__6ThreadUlUl
	addw #12,sp
	moveq #7,d1
	cmpl d0,d1
	jcs L276
LI285:
	movew pc@(L285-LI285-2:b,d0:l:2),d0
	jmp pc@(2,d0:w)
	.even
L285:
	.word L277-L285
	.word L278-L285
	.word L279-L285
	.word L282-L285
	.word L280-L285
	.word L281-L285
	.word L276-L285
	.word L283-L285
	.even
L277:
	pea LC6
	jra L290
	.even
L278:
	pea LC7
	jra L290
	.even
L279:
	pea LC8
	jra L290
	.even
L280:
	pea LC9
	jra L290
	.even
L281:
	pea LC10
	jra L290
	.even
L282:
	pea LC11
	jra L290
	.even
L283:
	pea LC12
L290:
	movel a4@(100),sp@-
	jbsr a3@
	addql #8,sp
L276:
	movel a4@(100),sp@-
	jbsr a2@
	addql #4,sp
	tstb a4@(112)
	jeq L272
	clrb a4@(112)
	movel a4@(104),d1
	divsl a4@(108),d1
	movel d1,a4@(104)
L272:
	moveb a4@(79),d0
	andb #132,d0
	jeq L274
	pea LC13
	movel a4@(100),sp@-
	jbsr a3@
	clrl d0
	addql #8,sp
	moveml sp@+,#0x1c00
	rts
LC14:
	.ascii "*** Observer: Thread %s returned %d\12\0"
	.even
.globl _notifyReturned__8MyThreadP6Threadl
_notifyReturned__8MyThreadP6Threadl:
	movel sp@(12),sp@-
	moveq #80,d0
	addl sp@(12),d0
	movel d0,sp@-
	pea LC14
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #16,sp
	rts
	nop
LC15:
	.ascii "exception\0"
LC16:
	.ascii "*** Observer: Thread %s threw uncaught %s\12\0"
	.even
.globl _notifyThrown__8MyThreadP6ThreadPC12RuntimeError
_notifyThrown__8MyThreadP6ThreadPC12RuntimeError:
	movel sp@(12),a1
	tstl a1
	jeq L295
	movel a1@,a0
	movel a1,sp@-
	movel a0@(12),a0
	jbsr a0@
	addql #4,sp
	jra L296
	.even
L295:
	movel #LC15,d0
L296:
	movel d0,sp@-
	moveq #80,d0
	addl sp@(12),d0
	movel d0,sp@-
	pea LC16
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #16,sp
	rts
	nop
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
	movel #L303,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L302
	.even
L303:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L300
	.even
L302:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___13ThreadTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L299
	.even
L300:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L309,a5@(-36)
	movel sp,a5@(-32)
	jra L308
	.even
L309:
	jra L314
	.even
L308:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L311
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L311:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L314:
L306:
	jbsr ___terminate
	.even
L299:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L324
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L324:
	rts
	nop
LC17:
	.ascii "Created ThreadTestApp\12\0"
	.even
.globl ___13ThreadTestApp
___13ThreadTestApp:
	link a5,#-156
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
	movel #L330,a5@(-12)
	movel sp,a5@(-8)
L330:
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
	movel #L344,a5@(-60)
	movel sp,a5@(-56)
	movel a0,a5@(-154)
	jra L343
	.even
L344:
	jra L370
	.even
L343:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_13ThreadTestApp,a0@
	clrl a0@(6)
	pea 114:w
	jbsr ___builtin_new
	movel d0,a5@(-148)
	moveb #1,a5@(-149)
	movel a5@(-154),a1
	movel a1@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L348,a5@(-84)
	movel sp,a5@(-80)
	jra L347
	.even
L348:
	jra L371
	.even
L347:
	lea a5@(-96),a1
	movel a5@(-154),a0
	movel a1,a0@
	movel a5@(-148),sp@-
	jbsr ___8MyThread
	clrb a5@(-149)
	movel a5@(8),a0
	movel d0,a0@(6)
	movel a5@(-154),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #4,sp
	movel #LC17,sp@
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel a5@(-154),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L369
	.even
L371:
L345:
	movel a5@(-154),a0
	movel a0@,a5@(-120)
	clrl a5@(-116)
	movel a5,a5@(-112)
	movel #L355,a5@(-108)
	movel sp,a5@(-104)
	jra L354
	.even
L355:
	jra L372
	.even
L354:
	lea a5@(-120),a0
	movel a5@(-154),a1
	movel a0,a1@
	tstb a5@(-149)
	jeq L357
	movel a5@(-148),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L357:
	movel a5@(-154),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L370:
L341:
	movel a5@(-154),a0
	movel a0@,a5@(-144)
	clrl a5@(-140)
	lea a5@(-136),a0
	movel a5,a0@
	movel #L361,a0@(4)
	movel sp,a5@(-128)
	jra L360
	.even
L361:
	jra L373
	.even
L360:
	lea a5@(-144),a0
	movel a5@(-154),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_8Runnable,a1@
	movel a5@(-154),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L372:
L352:
	jbsr ___terminate
	.even
L373:
L358:
	jbsr ___terminate
	.even
L369:
	moveml a5@(-268),#0x5cfc
	fmovem a5@(-228),#0x3f
	unlk a5
	rts
LC18:
	.ascii "Main Program Uptime:%3lu days %02lu hours %02lu mins %02lu secs %03lu millis\12\0"
LC19:
	.ascii "Destroyed ThreadTestApp\12\0"
	.even
.globl __$_13ThreadTestApp
__$_13ThreadTestApp:
	addw #-12,sp
	movel a2,sp@-
	movel sp@(20),a2
	movel #___vt_13ThreadTestApp,a2@
	clrl sp@-
	jbsr _FindTask
	movel d0,sp@-
	jbsr _threadForTask__6ThreadPQ28OSNative4Task
	addqw #4,sp
	movel d0,sp@
	lea sp@(8),a1
	jbsr _getUptime__C6Thread
	addql #4,sp
	pea 1000:w
	clrl sp@-
	movel sp@(16),sp@-
	movel sp@(16),sp@-
	jbsr ___moddi3
	addw #12,sp
	movel d1,sp@
	pea 1000:w
	clrl sp@-
	movel sp@(20),sp@-
	movel sp@(20),sp@-
	jbsr ___divdi3
	addw #16,sp
	pea 60:w
	clrl sp@-
	movel d1,sp@-
	movel d0,sp@-
	jbsr ___moddi3
	addw #12,sp
	movel d1,sp@
	movel #60000,sp@-
	clrl sp@-
	movel sp@(24),sp@-
	movel sp@(24),sp@-
	jbsr ___divdi3
	addw #16,sp
	pea 60:w
	clrl sp@-
	movel d1,sp@-
	movel d0,sp@-
	jbsr ___moddi3
	addw #12,sp
	movel d1,sp@
	movel #3600000,sp@-
	clrl sp@-
	movel sp@(28),sp@-
	movel sp@(28),sp@-
	jbsr ___divdi3
	addw #16,sp
	pea 24:w
	clrl sp@-
	movel d1,sp@-
	movel d0,sp@-
	jbsr ___moddi3
	addw #12,sp
	movel d1,sp@
	movel #86400000,sp@-
	clrl sp@-
	movel sp@(32),sp@-
	movel sp@(32),sp@-
	jbsr ___divdi3
	addw #12,sp
	movel d1,sp@
	pea LC18
	jbsr _printf
	addw #24,sp
	movel a2@(6),a1
	tstl a1
	jeq L386
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L386:
	pea LC19
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel #___vt_8Runnable,a2@
	movel sp@(24),d0
	btst #0,d0
	jeq L393
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L393:
	movel sp@+,a2
	addw #12,sp
	rts
LC20:
	.ascii "\12Created Thread %s, child of %s\12\12\0"
LC21:
	.ascii "Choose method\12"
	.ascii "1 start()\12"
	.ascii "2 stop()\12"
	.ascii "3 wake()\12"
	.ascii "4 getUpTime()\12"
	.ascii "5 set boobytrap\12Q Quit\0"
LC22:
	.ascii "Unable to complete operation, caught %s\12\0"
LC23:
	.ascii "Unable to complete operation, caught an exception\12\0"
LC24:
	.ascii "Bye!\0"
	.even
.globl _run__13ThreadTestApp
_run__13ThreadTestApp:
	link a5,#-140
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-134)
	movel a5@(8),a0
	tstl a0@(6)
	jne L395
	movel d0,a1
	addql #4,a1
	movel a1,a5@(-138)
	jbsr _throwNullPointer
L395:
	movel a5@(8),a1
	movel a1@(6),a0
	moveq #80,d0
	addl a0@(20),d0
	movel d0,sp@-
	pea a0@(80)
	pea LC20
	movel a5@(-134),a0
	addql #4,a0
	movel a0,a5@(-138)
	jbsr _printf
	pea LC21
	jbsr _puts
	clrb a5@(-121)
	addw #16,sp
	.even
L401:
	movel a5@(-138),a1
	movel a1@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L405,a5@(-12)
	movel sp,a5@(-8)
	jra L404
	.even
L405:
	jra L439
	.even
L404:
	lea a5@(-24),a1
	movel a5@(-138),a0
	movel a1,a0@
	jbsr _getchar
	moveq #-49,d1
	addl d1,d0
	moveq #64,d1
	cmpl d0,d1
	jcs L406
LI416:
	movew pc@(L416-LI416-2:b,d0:l:2),d0
	jmp pc@(2,d0:w)
	.even
L416:
	.word L407-L416
	.word L408-L416
	.word L409-L416
	.word L410-L416
	.word L411-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L414-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L406-L416
	.word L414-L416
	.even
L407:
	movel a5@(8),a0
	movel a0@(6),sp@-
	jbsr _start__6Thread
	addql #4,sp
	jra L406
	.even
L408:
	movel a5@(8),a1
	movel a1@(6),sp@-
	jbsr _stop__6Thread
	addql #4,sp
	jra L406
	.even
L409:
	movel a5@(8),a0
	movel a0@(6),sp@-
	jbsr _wake__6Thread
	addql #4,sp
	jra L406
	.even
L410:
	movel a5@(8),sp@-
	jbsr _showUptime__13ThreadTestApp
	addql #4,sp
	jra L406
	.even
L411:
	movel a5@(8),a1
	movel a1@(6),a0
	moveb #1,a0@(112)
	jra L406
	.even
L414:
	moveb #1,a5@(-121)
L406:
	movel a5@(-138),a1
	movel a1@,a0
	movel a0@,a1@
L399:
	tstb a5@(-121)
	jeq L401
	pea LC24
	jbsr _puts
	clrl d0
	addql #4,sp
	jra L394
	.even
L439:
L402:
	pea ___tf12RuntimeError
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L423
	jbsr ___start_cp_handler
	movel d0,a5@(-126)
	movel a5@(-138),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L422,a5@(-36)
	movel sp,a5@(-32)
	jra L421
	.even
L422:
	jra L440
	.even
L421:
	lea a5@(-48),a0
	movel a5@(-138),a1
	movel a0,a1@
	movel a5@(-126),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC22
	jbsr _printf
	movel a5@(-138),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a5@(-126),sp@
	jra L441
	.even
L423:
	jbsr ___start_cp_handler
	movel d0,a5@(-130)
	movel a5@(-138),a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L427,a5@(-60)
	movel sp,a5@(-56)
	jra L426
	.even
L427:
	jra L442
	.even
L426:
	lea a5@(-72),a0
	movel a5@(-138),a1
	movel a0,a1@
	pea LC23
	jbsr _printf
	movel a5@(-138),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(-130),sp@
L441:
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L399
	.even
L440:
L419:
	movel a5@(-138),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L432,a5@(-84)
	movel sp,a5@(-80)
	jra L431
	.even
L432:
	jra L443
	.even
L431:
	lea a5@(-96),a0
	movel a5@(-138),a1
	movel a0,a1@
	movel a5@(-126),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-138),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L442:
L424:
	movel a5@(-138),a0
	movel a0@,a5@(-120)
	clrl a5@(-116)
	movel a5,a5@(-112)
	movel #L436,a5@(-108)
	movel sp,a5@(-104)
	jra L435
	.even
L436:
	jra L444
	.even
L435:
	lea a5@(-120),a0
	movel a5@(-138),a1
	movel a0,a1@
	movel a5@(-130),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-138),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L443:
L429:
	jbsr ___terminate
	.even
L444:
L433:
	jbsr ___terminate
	.even
L394:
	moveml a5@(-252),#0x5cfc
	fmovem a5@(-212),#0x3f
	unlk a5
	rts
LC25:
	.ascii "Uptime:%3lu days %02lu hours %02lu mins %02lu secs %03lu millis\12\0"
	.even
.globl _showUptime__13ThreadTestApp
_showUptime__13ThreadTestApp:
	addw #-12,sp
	movel sp@(16),a0
	movel a0@(6),sp@-
	lea sp@(4),a1
	jbsr _getUptime__C6Thread
	addql #4,sp
	pea 1000:w
	clrl sp@-
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	jbsr ___moddi3
	addw #12,sp
	movel d1,sp@
	pea 1000:w
	clrl sp@-
	movel sp@(16),sp@-
	movel sp@(16),sp@-
	jbsr ___divdi3
	addw #16,sp
	pea 60:w
	clrl sp@-
	movel d1,sp@-
	movel d0,sp@-
	jbsr ___moddi3
	addw #12,sp
	movel d1,sp@
	movel #60000,sp@-
	clrl sp@-
	movel sp@(20),sp@-
	movel sp@(20),sp@-
	jbsr ___divdi3
	addw #16,sp
	pea 60:w
	clrl sp@-
	movel d1,sp@-
	movel d0,sp@-
	jbsr ___moddi3
	addw #12,sp
	movel d1,sp@
	movel #3600000,sp@-
	clrl sp@-
	movel sp@(24),sp@-
	movel sp@(24),sp@-
	jbsr ___divdi3
	addw #16,sp
	pea 24:w
	clrl sp@-
	movel d1,sp@-
	movel d0,sp@-
	jbsr ___moddi3
	addw #12,sp
	movel d1,sp@
	movel #86400000,sp@-
	clrl sp@-
	movel sp@(28),sp@-
	movel sp@(28),sp@-
	jbsr ___divdi3
	addw #12,sp
	movel d1,sp@
	pea LC25
	jbsr _printf
	addw #24,sp
	addw #12,sp
	rts
.globl ___vt_13ThreadTestApp
	.even
___vt_13ThreadTestApp:
	.long 0
	.long ___tf13ThreadTestApp
	.long __dfRTTI__11Application
	.long _run__13ThreadTestApp
	.long __$_13ThreadTestApp
	.skip 4
	.even
___thunk_96_notifyReturned__8MyThreadP6Threadl:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	moveq #-96,d0
	addl sp@(12),d0
	movel d0,sp@-
	jbsr _notifyReturned__8MyThreadP6Threadl
	addw #12,sp
	rts
	nop
	.even
___thunk_96_notifyThrown__8MyThreadP6ThreadPC12RuntimeError:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	moveq #-96,d0
	addl sp@(12),d0
	movel d0,sp@-
	jbsr _notifyThrown__8MyThreadP6ThreadPC12RuntimeError
	addw #12,sp
	rts
	nop
	.even
___thunk_96__$_8MyThread:
	movel sp@(8),sp@-
	moveq #-96,d0
	addl sp@(8),d0
	movel d0,sp@-
	jbsr __$_8MyThread
	addql #8,sp
	rts
	nop
.globl ___vt_8MyThread$Q26Thread11RunObserver
	.even
___vt_8MyThread$Q26Thread11RunObserver:
	.long -96
	.long ___tf8MyThread
	.long __dfRTTI__Q26Thread11RunObserver
	.long ___thunk_96_notifyReturned__8MyThreadP6Threadl
	.long ___thunk_96_notifyThrown__8MyThreadP6ThreadPC12RuntimeError
	.long ___thunk_96__$_8MyThread
	.skip 4
.globl ___vt_8MyThread
	.even
___vt_8MyThread:
	.long 0
	.long ___tf8MyThread
	.long __dfRTTI__6Thread
	.long _run__8MyThread
	.long __$_8MyThread
	.skip 4
.comm ___ti8MyThread,16
	.even
LC26:
	.long ___ti6Thread
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
	.long ___tiQ26Thread11RunObserver
	.byte 0x0
	.byte 0x0
	.byte 0x3
	.byte 0x1
LC27:
	.ascii "8MyThread\0"
.comm ___ti13ThreadTestApp,16
	.even
LC28:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC29:
	.ascii "13ThreadTestApp\0"
	.even
.globl ___tf8MyThread
___tf8MyThread:
	movel a2,sp@-
	lea ___ti8MyThread,a2
	tstl a2@
	jne L463
	jbsr ___tfQ26Thread11RunObserver
	jbsr ___tf6Thread
	pea 2:w
	pea LC26
	pea LC27
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L463:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf13ThreadTestApp
___tf13ThreadTestApp:
	movel a2,sp@-
	lea ___ti13ThreadTestApp,a2
	tstl a2@
	jne L466
	jbsr ___tf11Application
	pea 1:w
	pea LC28
	pea LC29
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L466:
	movel a2,d0
	movel sp@+,a2
	rts
