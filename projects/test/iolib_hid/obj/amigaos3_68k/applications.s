#NO_APP
.text
LC0:
	.ascii "Dispatcher: mask = 0x%08X\12\0"
	.even
.globl _applyKeyEventFilter__14TestDispatcherUl
_applyKeyEventFilter__14TestDispatcherUl:
	movel sp@(8),sp@-
	pea LC0
	jbsr _printf
	addql #8,sp
	rts
	nop
	.even
.globl ___14TestDispatcher
___14TestDispatcher:
	link a5,#-52
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-52)
	pea 15:w
	movel a5@(8),sp@-
	jbsr ___Q33HID3Key10DispatcherUl
	movel a5@(-52),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L251,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a1
	jra L250
	.even
L251:
	jra L259
	.even
L250:
	lea a5@(-24),a2
	movel a2,a0@
	movel a5@(8),a0
	movel #___vt_14TestDispatcher,a0@(4)
	addql #8,sp
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L258
	.even
L259:
L248:
	movel a5@(-52),a0
	addql #4,a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L256,a5@(-36)
	movel sp,a5@(-32)
	jra L255
	.even
L256:
	jra L260
	.even
L255:
	lea a5@(-48),a1
	movel a1,a0@
	clrl sp@-
	movel a5@(8),sp@-
	jbsr __$_Q33HID3Key10Dispatcher
	movel a5@(-52),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jbsr ___sjthrow
	.even
L260:
L253:
	jbsr ___terminate
	.even
L258:
	moveml a5@(-164),#0x5cfc
	fmovem a5@(-124),#0x3f
	unlk a5
	rts
	.even
.globl __$_14TestDispatcher
__$_14TestDispatcher:
	movel sp@(4),a0
	movel #___vt_14TestDispatcher,a0@(4)
	movel sp@(8),sp@-
	movel a0,sp@-
	jbsr __$_Q33HID3Key10Dispatcher
	addql #8,sp
	rts
	nop
LC1:
	.ascii "Observer [%lu] : pressed nonprintable 0x%08X\12\0"
	.even
.globl _nonPrintablePressed__12TestObserverPCQ33HID3Key10DispatcherQ33HID3Key7CtrlKey
_nonPrintablePressed__12TestObserverPCQ33HID3Key10DispatcherQ33HID3Key7CtrlKey:
	movel sp@(4),a0
	movel sp@(12),sp@-
	movel a0@(8),sp@-
	pea LC1
	jbsr _printf
	addw #12,sp
	rts
	nop
LC2:
	.ascii "Observer [%lu] : released nonprintable 0x%08X\12\0"
	.even
.globl _nonPrintableReleased__12TestObserverPCQ33HID3Key10DispatcherQ33HID3Key7CtrlKey
_nonPrintableReleased__12TestObserverPCQ33HID3Key10DispatcherQ33HID3Key7CtrlKey:
	movel sp@(4),a0
	movel sp@(12),sp@-
	movel a0@(8),sp@-
	pea LC2
	jbsr _printf
	addw #12,sp
	rts
	nop
LC3:
	.ascii "Observer [%lu] : pressed printable %c\12\0"
	.even
.globl _printablePressed__12TestObserverPCQ33HID3Key10Dispatcherl
_printablePressed__12TestObserverPCQ33HID3Key10Dispatcherl:
	movel sp@(4),a0
	movel sp@(12),sp@-
	movel a0@(8),sp@-
	pea LC3
	jbsr _printf
	addw #12,sp
	rts
	nop
LC4:
	.ascii "Observer [%lu] : released printable %c\12\0"
	.even
.globl _printableReleased__12TestObserverPCQ33HID3Key10Dispatcherl
_printableReleased__12TestObserverPCQ33HID3Key10Dispatcherl:
	movel sp@(4),a0
	movel sp@(12),sp@-
	movel a0@(8),sp@-
	pea LC4
	jbsr _printf
	addw #12,sp
	rts
	nop
	.even
.globl ___12TestObserver
___12TestObserver:
	link a5,#-52
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-52)
	pea 15:w
	movel a5@(8),sp@-
	jbsr ___Q33HID3Key8ObserverUl
	movel a5@(-52),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L275,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a1
	jra L274
	.even
L275:
	jra L283
	.even
L274:
	lea a5@(-24),a2
	movel a2,a0@
	movel a5@(8),a0
	movel #___vt_12TestObserver,a0@(4)
	addql #8,sp
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L282
	.even
L283:
L272:
	movel a5@(-52),a0
	addql #4,a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L280,a5@(-36)
	movel sp,a5@(-32)
	jra L279
	.even
L280:
	jra L284
	.even
L279:
	lea a5@(-48),a1
	movel a1,a0@
	clrl sp@-
	movel a5@(8),sp@-
	jbsr __$_Q33HID3Key8Observer
	movel a5@(-52),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jbsr ___sjthrow
	.even
L284:
L277:
	jbsr ___terminate
	.even
L282:
	moveml a5@(-164),#0x5cfc
	fmovem a5@(-124),#0x3f
	unlk a5
	rts
	.even
.globl __$_12TestObserver
__$_12TestObserver:
	movel sp@(4),a0
	movel #___vt_12TestObserver,a0@(4)
	movel sp@(8),sp@-
	movel a0,sp@-
	jbsr __$_Q33HID3Key8Observer
	addql #8,sp
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
	pea 14:w
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
	jbsr ___12InputTestApp
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
	.even
.globl ___12InputTestApp
___12InputTestApp:
	link a5,#-276
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
	movel a0,a5@(-274)
	jra L329
	.even
L330:
	jra L407
	.even
L329:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_12InputTestApp,a0@
	pea 28:w
	jbsr ___builtin_new
	movel d0,a5@(-244)
	moveb #1,a5@(-245)
	movel a5@(-274),a1
	movel a1@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L334,a5@(-84)
	movel sp,a5@(-80)
	jra L333
	.even
L334:
	jra L408
	.even
L333:
	lea a5@(-96),a1
	movel a5@(-274),a0
	movel a1,a0@
	movel a5@(-244),sp@-
	jbsr ___14TestDispatcher
	clrb a5@(-245)
	movel a5@(8),a0
	movel d0,a0@(6)
	movel a5@(-274),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #4,sp
	movel #52,sp@
	jbsr ___builtin_vec_new
	movel d0,a5@(-250)
	movel a5@(-274),a0
	movel a0@,a5@(-120)
	clrl a5@(-116)
	movel a5,a5@(-112)
	movel #L340,a5@(-108)
	movel sp,a5@(-104)
	jra L339
	.even
L340:
	jra L409
	.even
L339:
	lea a5@(-120),a0
	movel a5@(-274),a1
	movel a0,a1@
	movel a5@(-250),a1
	addql #4,a1
	movel a1,a5@(-258)
	moveq #4,d0
	movel a5@(-250),a0
	movel d0,a0@
	movel a1,a5@(-254)
	movel a1,a5@(-262)
	movew #3,a1
	movel a1,a5@(-266)
	movel a5@(-274),a0
	movel a0@,a5@(-144)
	clrl a5@(-140)
	lea a5@(-136),a0
	movel a5,a0@
	movel #L344,a0@(4)
	movel sp,a5@(-128)
	jra L343
	.even
L344:
	jra L410
	.even
L343:
	lea a5@(-144),a0
	movel a5@(-274),a1
	movel a0,a1@
	addql #4,sp
	moveq #-1,d0
	cmpl a5@(-266),d0
	jeq L345
	movel a5@(-266),d0
	notl d0
	moveq #3,d1
	andl d1,d0
	jeq L349
	cmpl d0,d1
	jle L390
	moveq #2,d1
	cmpl d0,d1
	jle L391
	movel a5@(-262),sp@-
	jbsr ___12TestObserver
	moveq #12,d0
	addl d0,a5@(-262)
	addql #4,sp
	subql #1,a5@(-266)
L391:
	movel a5@(-262),sp@-
	jbsr ___12TestObserver
	moveq #12,d1
	addl d1,a5@(-262)
	addql #4,sp
	subql #1,a5@(-266)
L390:
	movel a5@(-262),sp@-
	jbsr ___12TestObserver
	moveq #12,d0
	addl d0,a5@(-262)
	addql #4,sp
	subql #1,a5@(-266)
	jra L411
	.even
L349:
	movel a5@(-262),sp@-
	jbsr ___12TestObserver
	addql #4,sp
	movel a5@(-262),a0
	pea a0@(12)
	jbsr ___12TestObserver
	addql #4,sp
	movel a5@(-262),a1
	pea a1@(24)
	jbsr ___12TestObserver
	addql #4,sp
	movel a5@(-262),a0
	pea a0@(36)
	jbsr ___12TestObserver
	moveq #48,d0
	addl d0,a5@(-262)
	addql #4,sp
	subql #4,a5@(-266)
L411:
	moveq #-1,d1
	cmpl a5@(-266),d1
	jne L349
L345:
	movel a5@(-274),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),a0
	movel a5@(-258),a0@(10)
	movel a1@,a0
	movel a0@,a1@
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L386
	.even
L408:
L331:
	movel a5@(-274),a1
	movel a1@,a5@(-168)
	clrl a5@(-164)
	lea a5@(-160),a0
	movel a5,a0@
	movel #L362,a0@(4)
	movel sp,a0@(8)
	jra L361
	.even
L362:
	jra L412
	.even
L361:
	lea a5@(-168),a1
	movel a5@(-274),a0
	movel a1,a0@
	tstb a5@(-245)
	jeq L364
	movel a5@(-244),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L364:
	movel a5@(-274),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L410:
L341:
	movel a5@(-274),a0
	movel a0@,a5@(-192)
	clrl a5@(-188)
	lea a5@(-184),a0
	movel a5,a0@
	movel #L368,a0@(4)
	movel sp,a0@(8)
	jra L367
	.even
L368:
	jra L413
	.even
L367:
	lea a5@(-192),a0
	movel a5@(-274),a1
	movel a0,a1@
	tstl a5@(-254)
	jeq L351
	moveq #3,d0
	subl a5@(-266),d0
	moveq #12,d1
	mulsl d1,d0
	movel a5@(-254),a0
	addl d0,a0
	movel a0,a5@(-270)
	movel a5@(-254),a1
	cmpl a1,a0
	jeq L351
	.even
L354:
	moveq #-12,d0
	addl d0,a5@(-270)
	movel a5@(-270),a1
	movel a1@(4),a0
	clrl sp@-
	movel a1,sp@-
	movel a0@(32),a0
	jbsr a0@
	addql #8,sp
	movel a5@(-254),d0
	cmpl a5@(-270),d0
	jne L354
L351:
	movel a5@(-274),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L409:
L337:
	movel a5@(-274),a0
	movel a0@,a5@(-216)
	clrl a5@(-212)
	lea a5@(-208),a0
	movel a5,a0@
	movel #L372,a0@(4)
	movel sp,a0@(8)
	jra L371
	.even
L372:
	jra L414
	.even
L371:
	lea a5@(-216),a0
	movel a5@(-274),a1
	movel a0,a1@
	moveq #1,d0
	jeq L374
	movel a5@(-250),sp@-
	jbsr ___builtin_vec_delete
	addql #4,sp
L374:
	movel a5@(-274),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L407:
L327:
	movel a5@(-274),a0
	movel a0@,a5@(-240)
	clrl a5@(-236)
	lea a5@(-232),a0
	movel a5,a0@
	movel #L378,a0@(4)
	movel sp,a0@(8)
	jra L377
	.even
L378:
	jra L415
	.even
L377:
	lea a5@(-240),a0
	movel a5@(-274),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_8Runnable,a1@
	movel a5@(-274),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L412:
L359:
	jbsr ___terminate
	.even
L413:
L365:
	jbsr ___terminate
	.even
L414:
L369:
	jbsr ___terminate
	.even
L415:
L375:
	jbsr ___terminate
	.even
L386:
	moveml a5@(-388),#0x5cfc
	fmovem a5@(-348),#0x3f
	unlk a5
	rts
	.even
.globl __$_12InputTestApp
__$_12InputTestApp:
	movel a3,sp@-
	movel a2,sp@-
	movel sp@(12),a3
	movel #___vt_12InputTestApp,a3@
	movel a3@(10),a0
	tstl a0
	jeq L418
	moveq #12,d0
	mulsl a0@(-4),d0
	lea a0@(0,d0:l),a2
	cmpl a0,a2
	jeq L420
	.even
L421:
	addw #-12,a2
	movel a2@(4),a0
	clrl sp@-
	movel a2,sp@-
	movel a0@(32),a0
	jbsr a0@
	addql #8,sp
	cmpl a3@(10),a2
	jne L421
L420:
	movel a3@(10),d0
	subql #4,d0
	movel d0,sp@-
	jbsr ___builtin_vec_delete
	addql #4,sp
L418:
	movel a3@(6),a1
	tstl a1
	jeq L425
	movel a1@(4),a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L425:
	movel #___vt_8Runnable,a3@
	movel sp@(16),d0
	btst #0,d0
	jeq L431
	movel a3,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L431:
	movel sp@+,a2
	movel sp@+,a3
	rts
	.even
.globl _run__12InputTestApp
_run__12InputTestApp:
	movel a2,sp@-
	movel sp@(8),a2
	movel a2@(10),sp@-
	movel a2@(6),d0
	addql #8,d0
	movel d0,sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	moveq #12,d0
	addl a2@(10),d0
	movel d0,sp@-
	movel a2@(6),d0
	addql #8,d0
	movel d0,sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	moveq #24,d0
	addl a2@(10),d0
	movel d0,sp@-
	movel a2@(6),d0
	addql #8,d0
	movel d0,sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	moveq #36,d0
	addl a2@(10),d0
	movel d0,sp@-
	movel a2@(6),d0
	addql #8,d0
	movel d0,sp@-
	jbsr _pushBack__Q211EXNGPrivate8VoidListPv
	addql #8,sp
	subql #2,sp
	moveb #1,sp@(1)
	subql #2,sp
	pea 33:w
	movel a2@(6),sp@-
	jbsr _dispatchKeyPrintable__Q33HID3Key10Dispatcherlb
	addw #12,sp
	subql #2,sp
	moveb #1,sp@(1)
	subql #2,sp
	pea 25:w
	movel a2@(6),sp@-
	jbsr _dispatchKeyNonPrintable__Q33HID3Key10DispatcherQ33HID3Key7CtrlKeyb
	addw #12,sp
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	pea 33:w
	movel a2@(6),sp@-
	jbsr _dispatchKeyPrintable__Q33HID3Key10Dispatcherlb
	addw #12,sp
	clrl d0
	movel sp@+,a2
	rts
.globl ___vt_12InputTestApp
	.even
___vt_12InputTestApp:
	.long 0
	.long ___tf12InputTestApp
	.long __dfRTTI__11Application
	.long _run__12InputTestApp
	.long __$_12InputTestApp
	.skip 4
.globl ___vt_12TestObserver
	.even
___vt_12TestObserver:
	.long 0
	.long ___tf12TestObserver
	.long __dfRTTI__Q33HID3Key8Observer
	.long _applyKeyEventFilter__Q33HID3Key8ObserverUl
	.long _nonPrintablePressed__12TestObserverPCQ33HID3Key10DispatcherQ33HID3Key7CtrlKey
	.long _nonPrintableReleased__12TestObserverPCQ33HID3Key10DispatcherQ33HID3Key7CtrlKey
	.long _printablePressed__12TestObserverPCQ33HID3Key10Dispatcherl
	.long _printableReleased__12TestObserverPCQ33HID3Key10Dispatcherl
	.long __$_12TestObserver
	.skip 4
.globl ___vt_14TestDispatcher
	.even
___vt_14TestDispatcher:
	.long 0
	.long ___tf14TestDispatcher
	.long __dfRTTI__Q33HID3Key10Dispatcher
	.long _applyKeyEventFilter__14TestDispatcherUl
	.long __$_14TestDispatcher
	.skip 4
.comm ___ti14TestDispatcher,12
LC5:
	.ascii "14TestDispatcher\0"
.comm ___ti12TestObserver,12
LC6:
	.ascii "12TestObserver\0"
.comm ___ti12InputTestApp,16
	.even
LC7:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC8:
	.ascii "12InputTestApp\0"
	.even
.globl ___tf14TestDispatcher
___tf14TestDispatcher:
	movel a2,sp@-
	lea ___ti14TestDispatcher,a2
	tstl a2@
	jne L453
	jbsr ___tfQ33HID3Key10Dispatcher
	pea ___tiQ33HID3Key10Dispatcher
	pea LC5
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L453:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf12TestObserver
___tf12TestObserver:
	movel a2,sp@-
	lea ___ti12TestObserver,a2
	tstl a2@
	jne L455
	jbsr ___tfQ33HID3Key8Observer
	pea ___tiQ33HID3Key8Observer
	pea LC6
	movel a2,sp@-
	jbsr ___rtti_si
	addw #12,sp
L455:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tf12InputTestApp
___tf12InputTestApp:
	movel a2,sp@-
	lea ___ti12InputTestApp,a2
	tstl a2@
	jne L457
	jbsr ___tf11Application
	pea 1:w
	pea LC7
	pea LC8
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L457:
	movel a2,d0
	movel sp@+,a2
	rts
