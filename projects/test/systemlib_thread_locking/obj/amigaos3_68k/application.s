#NO_APP
.globl __32_GLOBAL_$N$application.cpp6QrUYc$doobrey
.data
	.even
__32_GLOBAL_$N$application.cpp6QrUYc$doobrey:
	.long 0
.globl __10UserThread$waitForLock
__10UserThread$waitForLock:
	.byte 0
.text
LC0:
	.ascii "CON:%hu/%hu/%hu/%hu/%s/CLOSE/WAIT\0"
LC1:
	.ascii "w\0"
LC2:
	.ascii "[console open]\12\0"
	.even
.globl ___10UserThreadUlUsUsUsUs
___10UserThreadUlUsUsUsUs:
	link a5,#-68
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	movew a5@(18),a5@(-50)
	movew a5@(22),a5@(-52)
	movew a5@(26),a5@(-54)
	movew a5@(30),a5@(-56)
	jbsr ___get_eh_context
	movel d0,a5@(-64)
	pea 4096:w
	clrl sp@-
	movel a5@(8),sp@-
	jbsr ___6ThreadQ26Thread8PriorityUl
	movel a5@(-64),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L309,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-68)
	jra L308
	.even
L309:
	movel a5@(-64),a0
	addql #4,a0
	movel a0,a5@(-68)
	jra L306
	.even
L308:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_10UserThread,a0@
	movel a5@(12),a0@(100)
	addw #12,sp
	pea a0@(80)
	movew a5@(-56),sp@-
	clrw sp@-
	movew a5@(-54),sp@-
	clrw sp@-
	movew a5@(-52),sp@-
	clrw sp@-
	movew a5@(-50),sp@-
	clrw sp@-
	pea LC0
	moveq #104,d0
	addl a0,d0
	movel d0,a5@(-60)
	movel d0,sp@-
	jbsr _sprintf
	pea LC1
	movel a5@(-60),sp@-
	jbsr _fopen
	movel a5@(8),a0
	movel d0,a0@(96)
	addw #32,sp
	movel #LC2,sp@
	movel d0,sp@-
	jbsr _fprintf
	addql #8,sp
	movel a5@(-68),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L317
	.even
L306:
	movel a5@(-68),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L315,a5@(-36)
	movel sp,a5@(-32)
	jra L314
	.even
L315:
	jra L318
	.even
L314:
	lea a5@(-48),a0
	movel a5@(-68),a1
	movel a0,a1@
	clrl sp@-
	movel a5@(8),sp@-
	jbsr __$_6Thread
	movel a5@(-64),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jbsr ___sjthrow
	.even
L318:
L312:
	jbsr ___terminate
	.even
L317:
	moveml a5@(-180),#0x5cfc
	fmovem a5@(-140),#0x3f
	unlk a5
	rts
	.even
.globl __$_10UserThread
__$_10UserThread:
	movel a2,sp@-
	movel sp@(8),a2
	movel #___vt_10UserThread,a2@
	btst #0,a2@(78)
	jeq L320
	movel a2,sp@-
	jbsr _stop__6Thread
	addql #4,sp
L320:
	movel a2@(96),d0
	jeq L323
	movel d0,sp@-
	jbsr _fclose
	addql #4,sp
L323:
	movel sp@(12),sp@-
	movel a2,sp@-
	jbsr __$_6Thread
	addql #8,sp
	movel sp@+,a2
	rts
LC3:
	.ascii "Hello World from %s, polling at %lu\12\0"
LC4:
	.ascii "I'm about to waitLock() the Doobrey...\12\0"
LC5:
	.ascii "Now it's mine for %lums\12\0"
LC6:
	.ascii "I'm about to tryLock() the Doobrey...\0"
LC7:
	.ascii "I win :) It's mine for %lums now\12\0"
LC8:
	.ascii "I failed :( Maybe next time?\12\0"
LC9:
	.ascii "I caught a %s when trying to lock Doobrey\12\0"
LC10:
	.ascii "Doobrey Info: pending=%ld, active=%ld\12\0"
LC11:
	.ascii "I relinquished the Doobrey\12\0"
LC12:
	.ascii "...\0"
LC13:
	.ascii "\12\0"
LC14:
	.ascii "[interrupted by wake()]\12\0"
LC15:
	.ascii "[interrupted by stop()]\12\0"
LC16:
	.ascii "[interrupted by system break]\12\0"
LC17:
	.ascii "[interrupted by user signal]\12\0"
LC18:
	.ascii "[interrupted by ~Thread()]\12\0"
LC19:
	.ascii "[interrupted by unknown]\12\0"
LC20:
	.ascii "I relinquished the doobrey on exit\12\0"
LC21:
	.ascii "Exception %s when trying to unlock doobrey on exit\12\0"
LC22:
	.ascii "\12Made %lu attempts of which %lu succeeded\12\0"
	.even
.globl _run__10UserThread
_run__10UserThread:
	link a5,#-172
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-166)
	clrl a5@(-148)
	clrl a5@(-152)
	clrb a5@(-153)
	movel a5@(8),a0
	movel a0@(100),sp@-
	pea a0@(80)
	pea LC3
	movel a0@(96),sp@-
	jbsr _fprintf
	addw #16,sp
	jra L326
	.even
L328:
	tstb a5@(-153)
	jne L330
	addql #1,a5@(-148)
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	jeq L346
	movel a5@(-166),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L335,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-170)
	jra L334
	.even
L335:
	movel a5@(-166),a0
	addql #4,a0
	movel a0,a5@(-170)
	jra L332
	.even
L334:
	lea a5@(-24),a1
	movel a1,a0@
	moveb __10UserThread$waitForLock,d0
	jeq L336
	pea LC4
	movel a5@(8),a0
	movel a0@(96),sp@-
	jbsr _fprintf
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	movel d0,sp@-
	jbsr _waitLock__Q26Thread8Lockable
	moveb #1,a5@(-153)
	addql #1,a5@(-152)
	movel a5@(8),a1
	movel a1@(100),sp@-
	pea LC5
	movel a1@(96),sp@-
	jbsr _fprintf
	addw #24,sp
	jra L337
	.even
L336:
	pea LC6
	movel a5@(8),a0
	movel a0@(96),sp@-
	jbsr _fprintf
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	movel d0,sp@-
	jbsr _tryLock__Q26Thread8Lockable
	moveb d0,a5@(-153)
	addw #12,sp
	jeq L338
	addql #1,a5@(-152)
	movel a5@(8),a1
	movel a1@(100),sp@-
	pea LC7
	movel a1@(96),sp@-
	jbsr _fprintf
	addw #12,sp
	jra L337
	.even
L338:
	pea LC8
	movel a5@(8),a0
	movel a0@(96),sp@-
	jbsr _fprintf
	addql #8,sp
L337:
	movel a5@(-170),a1
	movel a1@,a0
	movel a0@,a1@
	jra L346
	.even
L330:
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	jeq L346
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	movel d0,sp@-
	jbsr _active__Q26Thread8Lockable
	movel d0,sp@-
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	movel d0,sp@-
	jbsr _pending__Q26Thread8Lockable
	movel d0,sp@
	pea LC10
	movel a5@(8),a0
	movel a0@(96),sp@-
	jbsr _fprintf
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	movel d0,sp@-
	jbsr _freeLock__Q26Thread8Lockable
	pea LC11
	movel a5@(8),a1
	movel a1@(96),sp@-
	jbsr _fprintf
	clrb a5@(-153)
	addw #32,sp
L346:
	pea LC12
	movel a5@(8),a0
	movel a0@(96),sp@-
	jbsr _fprintf
	addqw #4,sp
	movel #12,sp@
	movel a5@(8),a1
	movel a1@(100),sp@-
	movel a1,sp@-
	jbsr _suspend__6ThreadUlUl
	addw #12,sp
	moveq #7,d1
	cmpl d0,d1
	jcs L326
LI357:
	movew pc@(L357-LI357-2:b,d0:l:2),d0
	jmp pc@(2,d0:w)
	.even
L357:
	.word L349-L357
	.word L350-L357
	.word L351-L357
	.word L354-L357
	.word L352-L357
	.word L353-L357
	.word L326-L357
	.word L355-L357
	.even
L349:
	pea LC13
	jra L382
	.even
L350:
	pea LC14
	movel a5@(8),a1
	movel a1@(96),sp@-
	jra L383
	.even
L351:
	pea LC15
	jra L382
	.even
L352:
	pea LC16
	movel a5@(8),a1
	movel a1@(96),sp@-
	jra L383
	.even
L353:
	pea LC17
	jra L382
	.even
L354:
	pea LC18
	movel a5@(8),a1
	movel a1@(96),sp@-
	jra L383
	.even
L355:
	pea LC19
L382:
	movel a5@(8),a0
	movel a0@(96),sp@-
L383:
	jbsr _fprintf
	addql #8,sp
L326:
	movel a5@(8),a1
	moveb a1@(79),d0
	andb #132,d0
	jeq L328
	tstb a5@(-153)
	jeq L359
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	jeq L359
	movel a5@(-166),a0
	addql #4,a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L364,a5@(-60)
	movel sp,a5@(-56)
	movel a0,a5@(-170)
	jra L363
	.even
L364:
	movel a5@(-166),a0
	addql #4,a0
	movel a0,a5@(-170)
	jra L361
	.even
L363:
	lea a5@(-72),a1
	movel a1,a0@
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	movel d0,sp@-
	jbsr _freeLock__Q26Thread8Lockable
	pea LC20
	movel a5@(8),a0
	movel a0@(96),sp@-
	jbsr _fprintf
	movel a5@(-170),a1
	movel a1@,a0
	movel a0@,a1@
	addw #12,sp
L359:
	clrb a5@(-153)
	movel a5@(-152),sp@-
	movel a5@(-148),sp@-
	pea LC22
	movel a5@(8),a0
	movel a0@(96),sp@-
	jbsr _fprintf
	clrl d0
	addw #16,sp
	jra L324
	.even
L332:
	pea ___tfQ25Error7Runtime
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L341
	jbsr ___start_cp_handler
	movel d0,a5@(-158)
	movel a5@(-170),a1
	movel a1@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L345,a5@(-36)
	movel sp,a5@(-32)
	jra L344
	.even
L345:
	movel a5@(-166),a0
	addql #4,a0
	movel a0,a5@(-170)
	jra L342
	.even
L344:
	lea a5@(-48),a0
	movel a5@(-170),a1
	movel a0,a1@
	movel a5@(-158),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC9
	movel a5@(8),a0
	movel a0@(96),sp@-
	jbsr _fprintf
	movel a5@(-170),a1
	movel a1@,a0
	movel a0@,a1@
	addw #12,sp
	movel a5@(-158),sp@
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L346
	.even
L341:
	jbsr ___sjthrow
	.even
L342:
	movel a5@(-170),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L369,a5@(-84)
	movel sp,a5@(-80)
	jra L368
	.even
L369:
	jra L384
	.even
L368:
	lea a5@(-96),a0
	movel a5@(-170),a1
	movel a0,a1@
	movel a5@(-158),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-166),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L361:
	pea ___tfQ25Error7Runtime
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L370
	jbsr ___start_cp_handler
	movel d0,a5@(-162)
	movel a5@(-170),a1
	movel a1@,a5@(-120)
	clrl a5@(-116)
	movel a5,a5@(-112)
	movel #L374,a5@(-108)
	movel sp,a5@(-104)
	jra L373
	.even
L374:
	movel a5@(-166),a0
	addql #4,a0
	movel a0,a5@(-170)
	jra L371
	.even
L373:
	lea a5@(-120),a0
	movel a5@(-170),a1
	movel a0,a1@
	movel a5@(-162),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC21
	movel a5@(8),a0
	movel a0@(96),sp@-
	jbsr _fprintf
	movel a5@(-170),a1
	movel a1@,a0
	movel a0@,a1@
	addw #12,sp
	movel a5@(-162),sp@
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L359
	.even
L370:
	jbsr ___sjthrow
	.even
L384:
L366:
	jbsr ___terminate
	.even
L371:
	movel a5@(-170),a0
	movel a0@,a5@(-144)
	clrl a5@(-140)
	lea a5@(-136),a0
	movel a5,a0@
	movel #L378,a0@(4)
	movel sp,a5@(-128)
	jra L377
	.even
L378:
	jra L385
	.even
L377:
	lea a5@(-144),a0
	movel a5@(-170),a1
	movel a0,a1@
	movel a5@(-162),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-166),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L385:
L375:
	jbsr ___terminate
	.even
L324:
	moveml a5@(-284),#0x5cfc
	fmovem a5@(-244),#0x3f
	unlk a5
	rts
	.even
.globl _createInstance__11Application
_createInstance__11Application:
	link a5,#-60
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-56)
	pea 22:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L390,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L389
	.even
L390:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L387
	.even
L389:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___13ThreadTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L386
	.even
L387:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L396,a5@(-36)
	movel sp,a5@(-32)
	jra L395
	.even
L396:
	jra L401
	.even
L395:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L398
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L398:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L401:
L393:
	jbsr ___terminate
	.even
L386:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L411
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L411:
	rts
	nop
LC23:
	.ascii "Created ThreadTestApp\12\0"
	.even
.globl ___13ThreadTestApp
___13ThreadTestApp:
	link a5,#-180
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
	movel #L417,a5@(-12)
	movel sp,a5@(-8)
L417:
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
	movel #L431,a5@(-60)
	movel sp,a5@(-56)
	movel a0,a5@(-170)
	jra L430
	.even
L431:
	jra L467
	.even
L430:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_13ThreadTestApp,a0@
	clrl a5@(-148)
	movel #500,a5@(-152)
	movew #24,a5@(-154)
	lea a5@(-88),a1
	movel a1,a5@(-178)
	lea a5@(-96),a0
	movel a0,a5@(-174)
	.even
L435:
	movew #24,a5@(-156)
	movew a5@(-154),a5@(-180)
	addw #240,a5@(-180)
	.even
L439:
	movel a5@(-148),a5@(-160)
	movel a5@(-160),d0
	lsll #2,d0
	movel d0,a5@(-160)
	pea 232:w
	addql #1,a5@(-148)
	jbsr ___builtin_new
	movel d0,a5@(-164)
	moveb #1,a5@(-165)
	movel a5@(-170),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5@(-178),a1
	movel a5,a1@
	movel #L443,a5@(-84)
	movel sp,a5@(-80)
	jra L442
	.even
L443:
	jra L468
	.even
L442:
	movel a5@(-170),a0
	movel a5@(-174),a0@
	pea 240:w
	pea 320:w
	movew a5@(-154),sp@-
	clrw sp@-
	movew a5@(-156),sp@-
	clrw sp@-
	movel a5@(-152),sp@-
	movel a5@(-164),sp@-
	jbsr ___10UserThreadUlUsUsUsUs
	clrb a5@(-165)
	movel a5@(8),d1
	movel a5@(-160),a1
	movel d0,a1@(6,d1:l)
	movel a5@(-170),a1
	movel a1@,a0
	movel a0@,a1@
	addw #28,sp
	moveq #100,d0
	addl d0,a5@(-152)
	addw #320,a5@(-156)
	cmpw #639,a5@(-156)
	jls L439
	movew a5@(-180),a5@(-154)
	cmpw #479,a5@(-154)
	jls L435
	pea LC23
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel a5@(-170),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L466
	.even
L468:
L440:
	movel a5@(-170),a0
	movel a0@,a5@(-120)
	clrl a5@(-116)
	movel a5,a5@(-112)
	movel #L452,a5@(-108)
	movel sp,a5@(-104)
	jra L451
	.even
L452:
	jra L469
	.even
L451:
	lea a5@(-120),a0
	movel a5@(-170),a1
	movel a0,a1@
	tstb a5@(-165)
	jeq L454
	movel a5@(-164),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L454:
	movel a5@(-170),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L467:
L428:
	movel a5@(-170),a0
	movel a0@,a5@(-144)
	clrl a5@(-140)
	lea a5@(-136),a0
	movel a5,a0@
	movel #L458,a0@(4)
	movel sp,a5@(-128)
	jra L457
	.even
L458:
	jra L470
	.even
L457:
	lea a5@(-144),a0
	movel a5@(-170),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_8Runnable,a1@
	movel a5@(-170),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L469:
L449:
	jbsr ___terminate
	.even
L470:
L455:
	jbsr ___terminate
	.even
L466:
	moveml a5@(-292),#0x5cfc
	fmovem a5@(-252),#0x3f
	unlk a5
	rts
LC24:
	.ascii "Main Program Uptime:%3lu days %02lu hours %02lu mins %02lu secs %03lu millis\12\0"
LC25:
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
	pea LC24
	jbsr _printf
	addw #24,sp
	lea a2@(6),a1
	movel a1@,a0
	tstl a0
	jeq L496
	movel a0@,a0
	pea 3:w
	movel a1@,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
	.even
L496:
	lea a2@(10),a1
	movel a1@,a0
	tstl a0
	jeq L499
	movel a0@,a0
	pea 3:w
	movel a1@,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L499:
	lea a2@(14),a1
	movel a1@,a0
	tstl a0
	jeq L502
	movel a0@,a0
	pea 3:w
	movel a1@,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L502:
	lea a2@(18),a1
	movel a1@,a0
	tstl a0
	jeq L505
	movel a0@,a0
	pea 3:w
	movel a1@,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L505:
	pea LC25
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel #___vt_8Runnable,a2@
	movel sp@(24),d0
	btst #0,d0
	jeq L495
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L495:
	movel sp@+,a2
	addw #12,sp
	rts
LC26:
	.ascii "Choose method\12"
	.ascii "1) Start all threads\12"
	.ascii "2) Stop all threads\12"
	.ascii "3) Create Doobrey - threads each try to lock Doobrey for their specific interval\12"
	.ascii "4) Destroy Doobrey\12"
	.ascii "5) Set all threads to tryLock() mode (only when no Doobrey currently exists)\12"
	.ascii "6) Set all threads to waitLock() mode (only when no Doobrey currently exists)\12Q) Quit\0"
LC27:
	.ascii "Starting threads...\0"
LC28:
	.ascii "Stopping threads...\0"
LC29:
	.ascii "Created Doobrey\0"
LC30:
	.ascii "Destroyed Doobrey\0"
LC31:
	.ascii "Setting mode to tryLock()...\0"
LC32:
	.ascii "Setting mode to waitLock()...\0"
LC33:
	.ascii "Unable to complete operation, caught %s\12\0"
LC34:
	.ascii "Unable to complete operation, caught an exception\12\0"
LC35:
	.ascii "Bye!\0"
	.even
.globl _run__13ThreadTestApp
_run__13ThreadTestApp:
	link a5,#-256
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-222)
	movel d0,a5@(-244)
	moveb #1,a5@(-217)
	clrb a5@(-218)
	.even
L511:
	tstb a5@(-217)
	jeq L512
	pea LC26
	movel a5@(-244),a0
	addql #4,a0
	movel a0,a5@(-248)
	jbsr _puts
	addql #4,sp
L512:
	clrb a5@(-217)
	movel a5@(-244),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L516,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-248)
	jra L515
	.even
L516:
	jra L605
	.even
L515:
	lea a5@(-24),a1
	movel a1,a0@
	jbsr _getchar
	moveq #-49,d1
	addl d1,d0
	moveq #64,d1
	cmpl d0,d1
	jcs L517
LI560:
	movew pc@(L560-LI560-2:b,d0:l:2),d0
	jmp pc@(2,d0:w)
	.even
L560:
	.word L518-L560
	.word L524-L560
	.word L530-L560
	.word L547-L560
	.word L551-L560
	.word L553-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L556-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L558-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L556-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L517-L560
	.word L558-L560
	.even
L518:
	pea LC27
	jbsr _puts
	addql #4,sp
	movel a5@(8),a0
	movel a0@(6),sp@-
	movew #10,a1
	addl a0,a1
	movel a1,a5@(-256)
	jbsr _start__6Thread
	addql #4,sp
	movel a5@(-256),a2
	movel a2@,sp@-
	movew #14,a0
	addl a5@(8),a0
	movel a0,a5@(-256)
	jbsr _start__6Thread
	addql #4,sp
	movel a5@(-256),a1
	movel a1@,sp@-
	movew #18,a2
	addl a5@(8),a2
	jbsr _start__6Thread
	movel a2@,sp@
	jbsr _start__6Thread
	addql #4,sp
	jra L517
	.even
L524:
	pea LC28
	jbsr _puts
	addql #4,sp
	movel a5@(8),a0
	movel a0@(6),sp@-
	movew #10,a1
	addl a0,a1
	movel a1,a5@(-252)
	jbsr _stop__6Thread
	addql #4,sp
	movel a5@(-252),a2
	movel a2@,sp@-
	movew #14,a0
	addl a5@(8),a0
	movel a0,a5@(-252)
	jbsr _stop__6Thread
	addql #4,sp
	movel a5@(-252),a1
	movel a1@,sp@-
	movew #18,a2
	addl a5@(8),a2
	jbsr _stop__6Thread
	movel a2@,sp@
	jbsr _stop__6Thread
	addql #4,sp
	jra L517
	.even
L530:
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	jne L517
	pea 52:w
	jbsr ___builtin_new
	movel d0,a5@(-226)
	moveb #1,a5@(-227)
	movel a5@(-248),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L535,a5@(-36)
	movel sp,a5@(-32)
	jra L534
	.even
L535:
	jra L606
	.even
L534:
	lea a5@(-48),a1
	movel a1,a5@(-232)
	movel a5@(-248),a2
	movel a1,a2@
	addql #4,sp
	movel a5@(-244),d0
	movel a5@(-226),sp@-
	jbsr ___Q26Thread8Lockable
	movel a5@(-222),a0
	addql #4,a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5@(-232),a5@(-64)
	movel #L538,a5@(-60)
	movel sp,a5@(-56)
	movel a0,a1
L538:
	lea a5@(-72),a2
	movel a2,a0@
	movel a5@(-226),a0
	movel #___vt_7Doobrey,a0@(48)
	addql #4,sp
	movel a1@,a0
	movel a0@,a1@
	clrb a5@(-227)
	movel a5@(-226),__32_GLOBAL_$N$application.cpp6QrUYc$doobrey
	movel a5@(-248),a1
	movel a1@,a0
	movel a0@,a1@
	pea LC29
	jra L607
	.even
L547:
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	jeq L517
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,a1
	tstl a1
	jeq L550
	movel a1@(48),a0
	pea 3:w
	movel a1,sp@-
	movel a0@(12),a0
	jbsr a0@
	addql #8,sp
L550:
	clrl __32_GLOBAL_$N$application.cpp6QrUYc$doobrey
	pea LC30
L607:
	jbsr _puts
	addql #4,sp
	jra L517
	.even
L551:
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	jne L517
	pea LC31
	jbsr _puts
	clrb __10UserThread$waitForLock
	addql #4,sp
	jra L517
	.even
L553:
	movel __32_GLOBAL_$N$application.cpp6QrUYc$doobrey,d0
	jne L517
	pea LC32
	jbsr _puts
	moveb #1,__10UserThread$waitForLock
	addql #4,sp
	jra L517
	.even
L556:
	moveb #1,a5@(-217)
	jra L517
	.even
L558:
	moveb #1,a5@(-218)
L517:
	movel a5@(-248),a2
	movel a2@,a0
	movel a0@,a2@
L509:
	tstb a5@(-218)
	jeq L511
	pea LC35
	jbsr _puts
	clrl d0
	addql #4,sp
	jra L508
	.even
L606:
L532:
	movel a5@(-248),a0
	movel a0@,a5@(-120)
	clrl a5@(-116)
	movel a5,a5@(-112)
	movel #L565,a5@(-108)
	movel sp,a5@(-104)
	jra L564
	.even
L565:
	jra L608
	.even
L564:
	lea a5@(-120),a2
	movel a5@(-248),a1
	movel a2,a1@
	tstb a5@(-227)
	jeq L567
	movel a5@(-226),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L567:
	movel a5@(-248),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L605:
L513:
	pea ___tfQ25Error7Runtime
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L573
	jbsr ___start_cp_handler
	movel d0,a5@(-236)
	movel a5@(-248),a2
	movel a2@,a5@(-144)
	clrl a5@(-140)
	lea a5@(-136),a0
	movel a5,a0@
	movel #L572,a0@(4)
	movel sp,a5@(-128)
	jra L571
	.even
L572:
	jra L609
	.even
L571:
	lea a5@(-144),a1
	movel a5@(-248),a0
	movel a1,a0@
	movel a5@(-236),a2
	movel a2@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC33
	jbsr _printf
	movel a5@(-248),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a2,sp@
	jra L610
	.even
L573:
	jbsr ___start_cp_handler
	movel d0,a5@(-240)
	movel a5@(-248),a2
	movel a2@,a5@(-168)
	clrl a5@(-164)
	lea a5@(-160),a0
	movel a5,a0@
	movel #L577,a0@(4)
	movel sp,a0@(8)
	jra L576
	.even
L577:
	jra L611
	.even
L576:
	lea a5@(-168),a1
	movel a5@(-248),a0
	movel a1,a0@
	pea LC34
	jbsr _printf
	movel a5@(-248),a2
	movel a2@,a0
	movel a0@,a2@
	movel a5@(-240),sp@
L610:
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L509
	.even
L608:
L562:
	jbsr ___terminate
	.even
L609:
L569:
	movel a5@(-248),a0
	movel a0@,a5@(-192)
	clrl a5@(-188)
	lea a5@(-184),a0
	movel a5,a0@
	movel #L582,a0@(4)
	movel sp,a0@(8)
	jra L581
	.even
L582:
	jra L612
	.even
L581:
	lea a5@(-192),a2
	movel a5@(-248),a1
	movel a2,a1@
	movel a5@(-236),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-248),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L611:
L574:
	movel a5@(-248),a2
	movel a2@,a5@(-216)
	clrl a5@(-212)
	lea a5@(-208),a0
	movel a5,a0@
	movel #L586,a0@(4)
	movel sp,a0@(8)
	jra L585
	.even
L586:
	jra L613
	.even
L585:
	lea a5@(-216),a1
	movel a5@(-248),a0
	movel a1,a0@
	movel a5@(-240),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-248),a2
	movel a2@,a0
	movel a0@,a2@
	addql #4,sp
	jbsr ___sjthrow
	.even
L612:
L579:
	jbsr ___terminate
	.even
L613:
L583:
	jbsr ___terminate
	.even
L508:
	moveml a5@(-368),#0x5cfc
	fmovem a5@(-328),#0x3f
	unlk a5
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
.globl ___vt_10UserThread
	.even
___vt_10UserThread:
	.long 0
	.long ___tf10UserThread
	.long __dfRTTI__6Thread
	.long _run__10UserThread
	.long __$_10UserThread
	.skip 4
	.even
___vt_7Doobrey:
	.long 0
	.long ___tf7Doobrey
	.long __dfRTTI__Q26Thread8Lockable
	.long __$_7Doobrey
	.skip 4
.comm ___ti7Doobrey,12
LC36:
	.ascii "7Doobrey\0"
.comm ___ti10UserThread,12
LC37:
	.ascii "10UserThread\0"
.comm ___ti13ThreadTestApp,16
	.even
LC38:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC39:
	.ascii "13ThreadTestApp\0"
	.even
___tf7Doobrey:
	movel a2,sp@-
	lea ___ti7Doobrey,a2
	tstl a2@
	jne L615
	jbsr ___tfQ26Thread8Lockable
	pea ___tiQ26Thread8Lockable
	pea LC36
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L615:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
__$_7Doobrey:
	movel sp@(4),a0
	movel #___vt_7Doobrey,a0@(48)
	movel sp@(8),sp@-
	movel a0,sp@-
	jbsr __$_Q26Thread8Lockable
	addql #8,sp
	rts
	nop
	.even
.globl ___tf10UserThread
___tf10UserThread:
	movel a2,sp@-
	lea ___ti10UserThread,a2
	tstl a2@
	jne L618
	jbsr ___tf6Thread
	pea ___ti6Thread
	pea LC37
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L618:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf13ThreadTestApp
___tf13ThreadTestApp:
	movel a2,sp@-
	lea ___ti13ThreadTestApp,a2
	tstl a2@
	jne L621
	jbsr ___tf11Application
	pea 1:w
	pea LC38
	pea LC39
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L621:
	movel a2,d0
	movel sp@+,a2
	rts
