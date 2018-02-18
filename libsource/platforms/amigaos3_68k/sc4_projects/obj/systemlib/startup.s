#NO_APP
.text
LC0:
	.ascii "bad_alloc\0"
	.even
.globl __dfRTTI__11Application
__dfRTTI__11Application:
	rts
	nop
	.even
.globl __dfRTTI__Q211Application15TooFewArguments
__dfRTTI__Q211Application15TooFewArguments:
	rts
	nop
	.even
.globl __dfRTTI__Q211Application15InvalidArgument
__dfRTTI__Q211Application15InvalidArgument:
	rts
	nop
	.even
.globl __dfRTTI__Q211Application15MissingArgument
__dfRTTI__Q211Application15MissingArgument:
	rts
	nop
	.even
.globl _throwTooFewArgs__11EXNGPrivatev
_throwTooFewArgs__11EXNGPrivatev:
	link a5,#-36
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-36)
	movel #___vt_Q211Application15TooFewArguments,a5@(-4)
	pea 4:w
	jbsr ___eh_alloc
	movel d0,a5@(-32)
	movel a5@(-36),a0
	addql #4,a0
	movel a0@,a5@(-28)
	clrl a5@(-24)
	movel a5,a5@(-20)
	movel #L209,a5@(-16)
	movel sp,a5@(-12)
	movel a0,a1
	jra L208
	.even
L209:
	jra L215
	.even
L208:
	lea a5@(-28),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-32),a0
	movel #___vt_Q211Application15TooFewArguments,a0@
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-32),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-32),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L215:
L206:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwInvalidArg__11EXNGPrivatePCc
_throwInvalidArg__11EXNGPrivatePCc:
	link a5,#-40
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-40)
	movel #___vt_Q211Application15InvalidArgument,a5@(-8)
	movel a5@(8),a5@(-4)
	pea 8:w
	jbsr ___eh_alloc
	movel d0,a5@(-36)
	movel a5@(-40),a0
	addql #4,a0
	movel a0@,a5@(-32)
	clrl a5@(-28)
	movel a5,a5@(-24)
	movel #L228,a5@(-20)
	movel sp,a5@(-16)
	movel a0,a1
	jra L227
	.even
L228:
	jra L234
	.even
L227:
	lea a5@(-32),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-36),a0
	movel #___vt_Q211Application15InvalidArgument,a0@
	movel a5@(-4),a0@(4)
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-36),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-36),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L234:
L225:
	jbsr _terminate__Fv
	nop
	.even
.globl _throwMissingArg__11EXNGPrivatePCc
_throwMissingArg__11EXNGPrivatePCc:
	link a5,#-40
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-40)
	movel #___vt_Q211Application15MissingArgument,a5@(-8)
	movel a5@(8),a5@(-4)
	pea 8:w
	jbsr ___eh_alloc
	movel d0,a5@(-36)
	movel a5@(-40),a0
	addql #4,a0
	movel a0@,a5@(-32)
	clrl a5@(-28)
	movel a5,a5@(-24)
	movel #L247,a5@(-20)
	movel sp,a5@(-16)
	movel a0,a1
	jra L246
	.even
L247:
	jra L253
	.even
L246:
	lea a5@(-32),a2
	movel a2,a0@
	addql #4,sp
	movel a5@(-36),a0
	movel #___vt_Q211Application15MissingArgument,a0@
	movel a5@(-4),a0@(4)
	movel a1@,a0
	movel a0@,a1@
	clrl sp@-
	movel a5@(-36),a1
	movel a1@,a0
	movel a0@(4),a0
	jbsr a0@
	movel d0,sp@-
	movel a5@(-36),sp@-
	jbsr ___cp_push_exception
	jbsr ___sjthrow
	.even
L253:
L244:
	jbsr _terminate__Fv
	nop
.globl __7Startup$numArgs
.data
	.even
__7Startup$numArgs:
	.long 0
.globl __7Startup$argPtrs
	.even
__7Startup$argPtrs:
	.long 0
.text
	.even
.globl _init__7StartupiPPc
_init__7StartupiPPc:
	moveml #0x2030,sp@-
	movel sp@(16),d2
	movel d2,__7Startup$numArgs
	movel d2,d0
	lsll #2,d0
	movel d0,sp@-
	jbsr ___builtin_vec_new
	movel d0,__7Startup$argPtrs
	addql #4,sp
	tstl d2
	jle L256
	movel d0,a3
	movel sp@(20),a2
	movel d2,d0
	movel d0,d1
	negl d1
	moveq #3,d2
	andl d2,d1
	jeq L258
	cmpl d1,d2
	jle L262
	moveq #2,d2
	cmpl d1,d2
	jle L263
	movel a2@+,a3@+
	subql #1,d0
L263:
	movel a2@+,a3@+
	subql #1,d0
L262:
	movel a2@+,a3@+
	subql #1,d0
	jeq L256
	.even
L258:
	movel a3,a1
	movel a2,a0
	movel a0@+,a1@+
	movel a0@,a1@
	movel a2@(8),a3@(8)
	movel a2@(12),a3@(12)
	addw #16,a2
	addw #16,a3
	subql #4,d0
	jne L258
L256:
	jbsr _init__9SystemLog
	jbsr _init__3Mem
	moveml sp@+,#0xc04
	rts
	.even
.globl _done__7Startup
_done__7Startup:
	jbsr _done__3Mem
	jbsr _done__9SystemLog
	movel __7Startup$argPtrs,d0
	jeq L281
	movel d0,sp@-
	jbsr ___builtin_vec_delete
	addql #4,sp
L281:
	rts
	nop
	.even
.globl _getArg__7StartupUl
_getArg__7StartupUl:
	movel d2,sp@-
	movel sp@(8),d2
	cmpl __7Startup$numArgs,d2
	jls L283
	jbsr _throwTooFewArgs__11EXNGPrivatev
L283:
	movel __7Startup$argPtrs,a0
	movel a0@(d2:l:4),d0
	movel sp@+,d2
	rts
	.even
.globl _locateArgument__7StartupPCcUs
_locateArgument__7StartupPCcUs:
	moveml #0x3800,sp@-
	movel sp@(16),d4
	movew sp@(22),d3
	movel __7Startup$numArgs,d0
	moveq #1,d1
	cmpl d0,d1
	jge L285
	clrl d2
	cmpl d2,d0
	jle L285
	.even
L289:
	btst #0,d3
	jeq L290
	movel __7Startup$argPtrs,a0
	movel a0@(d2:l:4),sp@-
	movel d4,sp@-
	jbsr _strcmp
	jra L298
	.even
L290:
	movel __7Startup$argPtrs,a0
	movel a0@(d2:l:4),sp@-
	movel d4,sp@-
	jbsr _stricmp
L298:
	addql #8,sp
	tstl d0
	jne L288
	movel d2,d0
	jra L296
	.even
L288:
	addql #1,d2
	cmpl __7Startup$numArgs,d2
	jlt L289
L285:
	btst #1,d3
	jeq L295
	movel d4,sp@-
	jbsr _throwMissingArg__11EXNGPrivatePCc
	addql #4,sp
L295:
	moveq #-1,d0
L296:
	moveml sp@+,#0x1c
	rts
	.even
.globl _getArgString__7StartupPCcT1Us
_getArgString__7StartupPCcT1Us:
	movel d2,sp@-
	movel sp@(8),d2
	clrl d0
	movew sp@(18),d0
	movel d0,sp@-
	movel d2,sp@-
	jbsr _locateArgument__7StartupPCcUs
	addql #1,d0
	addql #8,sp
	jne L300
	movel sp@(12),d0
	jra L299
	.even
L300:
	cmpl __7Startup$numArgs,d0
	jlt L301
	movel d2,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	clrl d0
	addql #4,sp
	jra L299
	.even
L301:
	movel __7Startup$argPtrs,a0
	movel a0@(d0:l:4),d0
L299:
	movel sp@+,d2
	rts
	.even
.globl _getArgInteger__7StartupPCclUs
_getArgInteger__7StartupPCclUs:
	moveml #0x3f38,sp@-
	movel sp@(40),d7
	clrl d0
	movew sp@(50),d0
	movel d0,sp@-
	movel d7,sp@-
	jbsr _locateArgument__7StartupPCcUs
	addql #1,d0
	addql #8,sp
	jne L305
	movel sp@(44),d0
	jra L304
	.even
L305:
	cmpl __7Startup$numArgs,d0
	jge L306
	movel __7Startup$argPtrs,a0
	movel a0@(d0:l:4),a4
	movel a4,sp@-
	jbsr _strlen
	clrl d6
	moveq #1,d4
	addql #4,sp
	movel d0,d5
	subql #1,d5
	tstl d5
	jle L309
	clrl d3
	lea a4@(0,d5:l),a2
	movel d5,d0
	negl d0
	moveq #3,d1
	andl d1,d0
	jeq L310
	cmpl d0,d1
	jle L319
	moveq #2,d1
	cmpl d0,d1
	jle L320
	moveb a2@,d3
	subql #1,a2
	moveq #-48,d2
	addl d3,d2
	moveq #9,d0
	cmpl d2,d0
	jcc L323
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L323:
	movel d2,d6
	moveq #10,d4
	subql #1,d5
L320:
	moveb a2@,d3
	subql #1,a2
	moveq #-48,d2
	addl d3,d2
	moveq #9,d1
	cmpl d2,d1
	jcc L326
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L326:
	mulsl d4,d2
	addl d2,d6
	moveq #10,d0
	mulsl d0,d4
	subql #1,d5
L319:
	moveb a2@,d3
	subql #1,a2
	moveq #-48,d2
	addl d3,d2
	moveq #9,d1
	cmpl d2,d1
	jcc L329
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L329:
	mulsl d4,d2
	addl d2,d6
	moveq #10,d0
	mulsl d0,d4
	subql #1,d5
	tstl d5
	jle L309
	.even
L310:
	moveb a2@,d3
	lea a2@(-1),a3
	moveq #-48,d2
	addl d3,d2
	moveq #9,d1
	cmpl d2,d1
	jcc L332
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L332:
	mulsl d4,d2
	addl d2,d6
	moveq #10,d0
	mulsl d0,d4
	moveb a3@,d3
	lea a2@(-2),a3
	moveq #-48,d2
	addl d3,d2
	moveq #9,d1
	cmpl d2,d1
	jcc L335
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L335:
	mulsl d4,d2
	addl d2,d6
	moveq #10,d0
	mulsl d0,d4
	moveb a3@,d3
	lea a2@(-3),a3
	moveq #-48,d2
	addl d3,d2
	moveq #9,d1
	cmpl d2,d1
	jcc L338
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L338:
	mulsl d4,d2
	addl d2,d6
	moveq #10,d0
	mulsl d0,d4
	moveb a3@,d3
	subql #4,a2
	moveq #-48,d2
	addl d3,d2
	moveq #9,d1
	cmpl d2,d1
	jcc L341
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L341:
	mulsl d4,d2
	addl d2,d6
	moveq #10,d0
	mulsl d0,d4
	subql #4,d5
	tstl d5
	jgt L310
L309:
	moveb a4@,d0
	cmpb #45,d0
	jne L313
	negl d6
	jra L314
	.even
L313:
	andl #0xFF,d0
	moveq #-48,d2
	addl d0,d2
	moveq #9,d1
	cmpl d2,d1
	jcc L315
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L315:
	mulsl d4,d2
	addl d2,d6
L314:
	movel d6,d0
	jra L304
	.even
L306:
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	clrl d0
	addql #4,sp
L304:
	moveml sp@+,#0x1cfc
	rts
	.even
.globl _getArgHex__7StartupPCclUs
_getArgHex__7StartupPCclUs:
	moveml #0x3f30,sp@-
	movel sp@(36),d7
	clrl d0
	movew sp@(46),d0
	movel d0,sp@-
	movel d7,sp@-
	jbsr _locateArgument__7StartupPCcUs
	addql #1,d0
	addql #8,sp
	jne L344
	movel sp@(40),d0
	jra L343
	.even
L344:
	cmpl __7Startup$numArgs,d0
	jge L345
	movel __7Startup$argPtrs,a0
	movel a0@(d0:l:4),d2
	movel d2,sp@-
	jbsr _strlen
	clrl d6
	clrl d5
	addql #4,sp
	movel d0,d3
	subql #1,d3
	jmi L348
	movel d3,a2
	addl d2,a2
	movel d3,d0
	notl d0
	moveq #1,d1
	andl d1,d0
	moveq #-1,d1
	cmpl d3,d1
	jge L360
	tstl d0
	jeq L349
L360:
	clrl d2
	moveb a2@,d2
	subql #1,a2
	moveq #-48,d0
	addl d2,d0
	moveq #9,d1
	cmpl d0,d1
	jcs L362
	movel d0,d2
	jra L363
	.even
L362:
	moveq #-97,d0
	addl d2,d0
	moveq #5,d1
	cmpl d0,d1
	jcs L364
	moveq #-87,d0
	addl d0,d2
	jra L363
	.even
L364:
	moveq #-65,d0
	addl d2,d0
	moveq #5,d1
	cmpl d0,d1
	jcs L365
	moveq #-55,d0
	addl d0,d2
	jra L363
	.even
L365:
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L363:
	lsll d5,d2
	addl d2,d6
	addql #4,d5
	subql #1,d3
	jmi L348
	.even
L349:
	clrl d2
	moveb a2@,d2
	lea a2@(-1),a3
	moveq #-48,d0
	addl d2,d0
	moveq #9,d1
	cmpl d0,d1
	jcs L368
	movel d0,d2
	jra L369
	.even
L368:
	moveq #-97,d0
	addl d2,d0
	moveq #5,d1
	cmpl d0,d1
	jcs L370
	moveq #-87,d0
	addl d0,d2
	jra L369
	.even
L370:
	moveq #-65,d0
	addl d2,d0
	moveq #5,d1
	cmpl d0,d1
	jcs L371
	moveq #-55,d0
	addl d0,d2
	jra L369
	.even
L371:
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L369:
	lsll d5,d2
	addl d2,d6
	movel d5,d4
	addql #4,d4
	clrl d2
	moveb a3@,d2
	subql #2,a2
	moveq #-48,d0
	addl d2,d0
	moveq #9,d1
	cmpl d0,d1
	jcs L374
	movel d0,d2
	jra L375
	.even
L374:
	moveq #-97,d0
	addl d2,d0
	moveq #5,d1
	cmpl d0,d1
	jcs L376
	moveq #-87,d0
	addl d0,d2
	jra L375
	.even
L376:
	moveq #-65,d0
	addl d2,d0
	moveq #5,d1
	cmpl d0,d1
	jcs L377
	moveq #-55,d0
	addl d0,d2
	jra L375
	.even
L377:
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L375:
	lsll d4,d2
	addl d2,d6
	addql #8,d5
	subql #2,d3
	jpl L349
L348:
	movel d6,d0
	jra L343
	.even
L345:
	movel d7,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	clrl d0
	addql #4,sp
L343:
	moveml sp@+,#0xcfc
	rts
	.even
.globl _getArgOct__7StartupPCclUs
_getArgOct__7StartupPCclUs:
	moveml #0x3f38,sp@-
	movel sp@(40),a4
	clrl d0
	movew sp@(50),d0
	movel d0,sp@-
	movel a4,sp@-
	jbsr _locateArgument__7StartupPCcUs
	addql #1,d0
	addql #8,sp
	jne L380
	movel sp@(44),d0
	jra L379
	.even
L380:
	cmpl __7Startup$numArgs,d0
	jge L381
	movel __7Startup$argPtrs,a0
	movel a0@(d0:l:4),d2
	movel d2,sp@-
	jbsr _strlen
	clrl d6
	clrl d7
	addql #4,sp
	movel d0,d5
	subql #1,d5
	jmi L384
	clrl d3
	movel d5,a2
	addl d2,a2
	movel d5,d0
	notl d0
	moveq #3,d1
	andl d1,d0
	moveq #-1,d1
	cmpl d5,d1
	jge L391
	tstl d0
	jeq L385
	moveq #3,d1
	cmpl d0,d1
	jle L391
	moveq #2,d1
	cmpl d0,d1
	jle L392
	moveb a2@,d3
	subql #1,a2
	moveq #-48,d2
	addl d3,d2
	moveq #7,d0
	cmpl d2,d0
	jcc L395
	movel a4,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L395:
	movel d2,d6
	moveq #3,d7
	subql #1,d5
L392:
	moveb a2@,d3
	subql #1,a2
	moveq #-48,d2
	addl d3,d2
	moveq #7,d1
	cmpl d2,d1
	jcc L398
	movel a4,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L398:
	lsll d7,d2
	addl d2,d6
	addql #3,d7
	subql #1,d5
L391:
	moveb a2@,d3
	subql #1,a2
	moveq #-48,d2
	addl d3,d2
	moveq #7,d0
	cmpl d2,d0
	jcc L401
	movel a4,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L401:
	lsll d7,d2
	addl d2,d6
	addql #3,d7
	subql #1,d5
	jmi L384
	.even
L385:
	moveb a2@,d3
	lea a2@(-1),a3
	moveq #-48,d2
	addl d3,d2
	moveq #7,d1
	cmpl d2,d1
	jcc L404
	movel a4,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L404:
	lsll d7,d2
	addl d2,d6
	movel d7,d4
	addql #3,d4
	moveb a3@,d3
	lea a2@(-2),a3
	moveq #-48,d2
	addl d3,d2
	moveq #7,d0
	cmpl d2,d0
	jcc L407
	movel a4,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L407:
	lsll d4,d2
	addl d2,d6
	movel d7,d4
	addql #6,d4
	moveb a3@,d3
	lea a2@(-3),a3
	moveq #-48,d2
	addl d3,d2
	moveq #7,d1
	cmpl d2,d1
	jcc L410
	movel a4,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L410:
	lsll d4,d2
	addl d2,d6
	moveq #9,d4
	addl d7,d4
	moveb a3@,d3
	subql #4,a2
	moveq #-48,d2
	addl d3,d2
	moveq #7,d0
	cmpl d2,d0
	jcc L413
	movel a4,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L413:
	lsll d4,d2
	addl d2,d6
	moveq #12,d1
	addl d1,d7
	subql #4,d5
	jpl L385
L384:
	movel d6,d0
	jra L379
	.even
L381:
	movel a4,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	clrl d0
	addql #4,sp
L379:
	moveml sp@+,#0x1cfc
	rts
	.even
.globl _getArgReal__7StartupPCcdUs
_getArgReal__7StartupPCcdUs:
	fmovem #0x4,sp@-
	movel d2,sp@-
	movel sp@(20),d2
	clrl d0
	movew sp@(34),d0
	movel d0,sp@-
	movel d2,sp@-
	jbsr _locateArgument__7StartupPCcUs
	addql #1,d0
	addql #8,sp
	jne L416
	movel sp@(24),d0
	movel sp@(28),d1
	jra L415
	.even
L416:
	cmpl __7Startup$numArgs,d0
	jge L417
	clrl _errno
	clrl sp@-
	movel __7Startup$argPtrs,a0
	movel a0@(d0:l:4),sp@-
	jbsr _strtod
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp2
	addql #8,sp
	tstl _errno
	jeq L419
	clrl _errno
	movel d2,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	addql #4,sp
L419:
	fmoved fp2,sp@-
	movel sp@+,d0
	movel sp@+,d1
	jra L415
	.even
L417:
	movel d2,sp@-
	jbsr _throwInvalidArg__11EXNGPrivatePCc
	clrl d0
	clrl d1
	addql #4,sp
L415:
	movel sp@+,d2
	fmovem sp@+,#0x20
	rts
	.even
.globl _getArgSwitch__7StartupPCcUs
_getArgSwitch__7StartupPCcUs:
	clrl d0
	movew sp@(10),d0
	movel d0,sp@-
	movel sp@(8),sp@-
	jbsr _locateArgument__7StartupPCcUs
	addql #8,sp
	moveq #-1,d1
	cmpl d0,d1
	sne d0
	negb d0
	rts
	nop
.globl ___vt_Q211Application15InvalidArgument
	.even
___vt_Q211Application15InvalidArgument:
	.long 0
	.long ___tfQ211Application15InvalidArgument
	.long __dfRTTI__Q211Application15InvalidArgument
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q211Application15MissingArgument
	.even
___vt_Q211Application15MissingArgument:
	.long 0
	.long ___tfQ211Application15MissingArgument
	.long __dfRTTI__Q211Application15MissingArgument
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_Q211Application15TooFewArguments
	.even
___vt_Q211Application15TooFewArguments:
	.long 0
	.long ___tfQ211Application15TooFewArguments
	.long __dfRTTI__Q211Application15TooFewArguments
	.long _getClass__C12RuntimeError
	.skip 4
.globl ___vt_11Application
	.even
___vt_11Application:
	.long 0
	.long ___tf11Application
	.long __dfRTTI__11Application
	.long ___pure_virtual
	.long __$_11Application
	.skip 4
.comm ___ti11Application,16
	.even
LC1:
	.long ___ti8Runnable
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
	.long ___ti7Startup
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x23
LC2:
	.ascii "11Application\0"
.comm ___tiQ211Application15TooFewArguments,12
LC3:
	.ascii "Q211Application15TooFewArguments\0"
.comm ___tiQ211Application15MissingArgument,12
LC4:
	.ascii "Q211Application15MissingArgument\0"
.comm ___tiQ211Application15InvalidArgument,12
LC5:
	.ascii "Q211Application15InvalidArgument\0"
.comm ___ti7Startup,8
LC6:
	.ascii "7Startup\0"
	.even
.globl __$_11Application
__$_11Application:
	movel sp@(4),a0
	movel #___vt_8Runnable,a0@
	btst #0,sp@(11)
	jeq L429
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L429:
	rts
	nop
	.even
.globl ___tf11Application
___tf11Application:
	movel a2,sp@-
	lea ___ti11Application,a2
	tstl a2@
	jne L431
	jbsr ___tf7Startup
	jbsr ___tf8Runnable
	pea 2:w
	pea LC1
	pea LC2
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L431:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ211Application15TooFewArguments
___tfQ211Application15TooFewArguments:
	movel a2,sp@-
	lea ___tiQ211Application15TooFewArguments,a2
	tstl a2@
	jne L433
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC3
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L433:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ211Application15MissingArgument
___tfQ211Application15MissingArgument:
	movel a2,sp@-
	lea ___tiQ211Application15MissingArgument,a2
	tstl a2@
	jne L435
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC4
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L435:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ211Application15InvalidArgument
___tfQ211Application15InvalidArgument:
	movel a2,sp@-
	lea ___tiQ211Application15InvalidArgument,a2
	tstl a2@
	jne L437
	jbsr ___tf12RuntimeError
	pea ___ti12RuntimeError
	pea LC5
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L437:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
___tf7Startup:
	movel a2,sp@-
	lea ___ti7Startup,a2
	tstl a2@
	jne L439
	pea LC6
	movel a2,sp@-
	jbsr ___rtti_user
	addql #8,sp
L439:
	movel a2,d0
	movel sp@+,a2
	rts
