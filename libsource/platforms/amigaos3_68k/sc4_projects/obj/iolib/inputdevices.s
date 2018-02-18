#NO_APP
.text
	.even
.globl __dfRTTI__9EventMask
__dfRTTI__9EventMask:
	rts
	nop
	.even
.globl __dfRTTI__Q25Mouse6Filter
__dfRTTI__Q25Mouse6Filter:
	rts
	nop
	.even
.globl __dfRTTI__Q25Mouse10Dispatcher
__dfRTTI__Q25Mouse10Dispatcher:
	rts
	nop
	.even
.globl __dfRTTI__Q25Mouse8Observer
__dfRTTI__Q25Mouse8Observer:
	rts
	nop
	.even
.globl __dfRTTI__Q23Key6Filter
__dfRTTI__Q23Key6Filter:
	rts
	nop
	.even
.globl __dfRTTI__Q23Key10Dispatcher
__dfRTTI__Q23Key10Dispatcher:
	rts
	nop
	.even
.globl __dfRTTI__Q23Key8Observer
__dfRTTI__Q23Key8Observer:
	rts
	nop
	.even
.globl _setMaskBits__9EventMaskUl
_setMaskBits__9EventMaskUl:
	movel sp@(4),a0
	movel sp@(8),d0
	movel a0@,d1
	movel d0,a0@
	eorl d1,d0
	rts
	nop
	.even
.globl _toggleMaskBits__9EventMaskUl
_toggleMaskBits__9EventMaskUl:
	movel d2,sp@-
	movel sp@(8),a0
	movel a0@,d1
	movel d1,d0
	movel sp@(12),d2
	eorl d2,d0
	movel d0,a0@
	eorl d1,d0
	movel sp@+,d2
	rts
	.even
.globl _enableMaskBits__9EventMaskUl
_enableMaskBits__9EventMaskUl:
	movel sp@(4),a0
	movel a0@,d1
	movel d1,d0
	orl sp@(8),d0
	movel d0,a0@
	eorl d1,d0
	rts
	nop
	.even
.globl _disableMaskBits__9EventMaskUl
_disableMaskBits__9EventMaskUl:
	movel d2,sp@-
	movel sp@(8),a0
	movel a0@,d2
	movel sp@(12),d1
	notl d1
	movel d2,d0
	andl d1,d0
	movel d0,a0@
	eorl d2,d0
	movel sp@+,d2
	rts
	.even
.globl _enableMouseEvents__Q25Mouse6FilterUl
_enableMouseEvents__Q25Mouse6FilterUl:
	movel a2,sp@-
	movel sp@(8),a2
	movel sp@(12),sp@-
	movel a2,sp@-
	jbsr _enableMaskBits__9EventMaskUl
	addql #8,sp
	tstl d0
	jeq L180
	movel a2@(4),a0
	movel a2@,sp@-
	movel a2,sp@-
	movel a0@(12),a0
	jbsr a0@
	addql #8,sp
L180:
	movel a2@,d0
	movel sp@+,a2
	rts
	.even
.globl _disableMouseEvents__Q25Mouse6FilterUl
_disableMouseEvents__Q25Mouse6FilterUl:
	movel a2,sp@-
	movel sp@(8),a2
	movel sp@(12),sp@-
	movel a2,sp@-
	jbsr _disableMaskBits__9EventMaskUl
	addql #8,sp
	tstl d0
	jeq L184
	movel a2@(4),a0
	movel a2@,sp@-
	movel a2,sp@-
	movel a0@(12),a0
	jbsr a0@
	addql #8,sp
L184:
	movel a2@,d0
	movel sp@+,a2
	rts
	.even
.globl _enableKeyEvents__Q23Key6FilterUl
_enableKeyEvents__Q23Key6FilterUl:
	movel a2,sp@-
	movel sp@(8),a2
	movel sp@(12),sp@-
	movel a2,sp@-
	jbsr _enableMaskBits__9EventMaskUl
	addql #8,sp
	tstl d0
	jeq L188
	movel a2@(4),a0
	movel a2@,sp@-
	movel a2,sp@-
	movel a0@(12),a0
	jbsr a0@
	addql #8,sp
L188:
	movel a2@,d0
	movel sp@+,a2
	rts
	.even
.globl _disableKeyEvents__Q23Key6FilterUl
_disableKeyEvents__Q23Key6FilterUl:
	movel a2,sp@-
	movel sp@(8),a2
	movel sp@(12),sp@-
	movel a2,sp@-
	jbsr _disableMaskBits__9EventMaskUl
	addql #8,sp
	tstl d0
	jeq L192
	movel a2@(4),a0
	movel a2@,sp@-
	movel a2,sp@-
	movel a0@(12),a0
	jbsr a0@
	addql #8,sp
L192:
	movel a2@,d0
	movel sp@+,a2
	rts
.globl __Q25Mouse8Observer$nextId
.data
	.even
__Q25Mouse8Observer$nextId:
	.long 0
.text
	.even
.globl ___Q25Mouse8Observer
___Q25Mouse8Observer:
	movel sp@(4),a0
	movel #459775,a0@
	movel #___vt_Q25Mouse8Observer,a0@(4)
	movel __Q25Mouse8Observer$nextId,a0@(8)
	addql #1,__Q25Mouse8Observer$nextId
	movel a0,d0
	rts
	nop
	.even
.globl ___Q25Mouse8ObserverUl
___Q25Mouse8ObserverUl:
	movel sp@(4),a0
	movel sp@(8),d0
	andl #459775,d0
	movel d0,a0@
	movel #___vt_Q25Mouse8Observer,a0@(4)
	movel __Q25Mouse8Observer$nextId,a0@(8)
	addql #1,__Q25Mouse8Observer$nextId
	movel a0,d0
	rts
	nop
	.even
.globl __$_Q25Mouse8Observer
__$_Q25Mouse8Observer:
	movel sp@(4),a0
	movel #___vt_Q25Mouse8Observer,a0@(4)
	btst #0,sp@(11)
	jeq L210
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L210:
	rts
	nop
	.even
.globl _applyMouseEventFilter__Q25Mouse8ObserverUl
_applyMouseEventFilter__Q25Mouse8ObserverUl:
	rts
	nop
.globl __Q23Key8Observer$nextId
.data
	.even
__Q23Key8Observer$nextId:
	.long 0
.text
	.even
.globl ___Q23Key8Observer
___Q23Key8Observer:
	movel sp@(4),a0
	moveq #15,d0
	movel d0,a0@
	movel #___vt_Q23Key8Observer,a0@(4)
	movel __Q23Key8Observer$nextId,a0@(8)
	addql #1,__Q23Key8Observer$nextId
	movel a0,d0
	rts
	nop
	.even
.globl ___Q23Key8ObserverUl
___Q23Key8ObserverUl:
	movel sp@(4),a0
	moveq #15,d0
	andl sp@(8),d0
	movel d0,a0@
	movel #___vt_Q23Key8Observer,a0@(4)
	movel __Q23Key8Observer$nextId,a0@(8)
	addql #1,__Q23Key8Observer$nextId
	movel a0,d0
	rts
	nop
	.even
.globl __$_Q23Key8Observer
__$_Q23Key8Observer:
	movel sp@(4),a0
	movel #___vt_Q23Key8Observer,a0@(4)
	btst #0,sp@(11)
	jeq L227
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L227:
	rts
	nop
	.even
.globl _applyKeyEventFilter__Q23Key8ObserverUl
_applyKeyEventFilter__Q23Key8ObserverUl:
	rts
	nop
.globl __Q25Mouse10Dispatcher$nextId
.data
	.even
__Q25Mouse10Dispatcher$nextId:
	.long 0
.text
	.even
.globl ___Q25Mouse10Dispatcher
___Q25Mouse10Dispatcher:
	link a5,#-100
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-100)
	movel a5@(8),a0
	movel #459775,a0@
	movel #___vt_Q25Mouse10Dispatcher,a0@(4)
	movel a5@(-100),d0
	pea a0@(8)
	jbsr ___Q211EXNGPrivate8VoidList
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L247,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a2
L247:
	lea a5@(-24),a1
	movel a1,a0@
	addql #4,sp
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	movel a2@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L259,a5@(-60)
	movel sp,a5@(-56)
	jra L258
	.even
L259:
	jra L269
	.even
L258:
	lea a5@(-72),a0
	movel a0,a2@
	movel a5@(8),a1
	clrl a1@(28)
	clrw a1@(32)
	clrw a1@(34)
	clrw a1@(36)
	clrw a1@(38)
	movel __Q25Mouse10Dispatcher$nextId,a1@(24)
	addql #1,__Q25Mouse10Dispatcher$nextId
	movel a2@,a0
	movel a0@,a2@
	movel a1,d0
	jra L268
	.even
L269:
L256:
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L264,a5@(-84)
	movel sp,a5@(-80)
	jra L263
	.even
L264:
	jra L270
	.even
L263:
	lea a5@(-96),a1
	movel a1,a0@
	clrl sp@-
	movel a5@(8),a0
	pea a0@(8)
	jbsr __$_Q211EXNGPrivate8VoidList
	addql #8,sp
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L270:
L261:
	jbsr ___terminate
	.even
L268:
	moveml a5@(-212),#0x5cfc
	fmovem a5@(-172),#0x3f
	unlk a5
	rts
	.even
.globl ___Q25Mouse10DispatcherUl
___Q25Mouse10DispatcherUl:
	link a5,#-100
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-100)
	movel a5@(12),d0
	andl #459775,d0
	movel a5@(8),a0
	movel d0,a0@
	movel #___vt_Q25Mouse10Dispatcher,a0@(4)
	movel a5@(-100),d0
	pea a0@(8)
	jbsr ___Q211EXNGPrivate8VoidList
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L278,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a2
L278:
	lea a5@(-24),a1
	movel a1,a0@
	addql #4,sp
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	movel a2@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L288,a5@(-60)
	movel sp,a5@(-56)
	jra L287
	.even
L288:
	jra L298
	.even
L287:
	lea a5@(-72),a0
	movel a0,a2@
	movel a5@(8),a1
	clrl a1@(28)
	clrw a1@(32)
	clrw a1@(34)
	clrw a1@(36)
	clrw a1@(38)
	movel __Q25Mouse10Dispatcher$nextId,a1@(24)
	addql #1,__Q25Mouse10Dispatcher$nextId
	movel a2@,a0
	movel a0@,a2@
	movel a1,d0
	jra L297
	.even
L298:
L285:
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L293,a5@(-84)
	movel sp,a5@(-80)
	jra L292
	.even
L293:
	jra L299
	.even
L292:
	lea a5@(-96),a1
	movel a1,a0@
	clrl sp@-
	movel a5@(8),a0
	pea a0@(8)
	jbsr __$_Q211EXNGPrivate8VoidList
	addql #8,sp
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L299:
L290:
	jbsr ___terminate
	.even
L297:
	moveml a5@(-212),#0x5cfc
	fmovem a5@(-172),#0x3f
	unlk a5
	rts
	.even
.globl __$_Q25Mouse10Dispatcher
__$_Q25Mouse10Dispatcher:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel sp@(16),d2
	movel #___vt_Q25Mouse10Dispatcher,a2@(4)
	pea 2:w
	pea a2@(8)
	jbsr __$_Q211EXNGPrivate8VoidList
	addql #8,sp
	btst #0,d2
	jeq L305
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L305:
	movel sp@+,d2
	movel sp@+,a2
	rts
	.even
.globl _dispatchMouseKey__Q25Mouse10DispatcherQ25Mouse6Buttonb
_dispatchMouseKey__Q25Mouse10DispatcherQ25Mouse6Buttonb:
	addw #-20,sp
	moveml #0x3030,sp@-
	movel sp@(40),a2
	movel sp@(44),d3
	tstb sp@(51)
	jeq L307
	orl d3,a2@(28)
	movel a2@,d0
	andl d3,d0
	jeq L341
	lea sp@(24),a1
	lea a2@(8),a0
	movel a0,a1@
	movel a0@,sp@(28)
	movel a0@,d0
	movel a1,a3
	jlt L323
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),sp@(28)
	jra L324
	.even
L323:
	clrl d1
L324:
	movel d1,a1
	tstl a1
	jeq L341
	.even
L330:
	movel a1@,d0
	andl d3,d0
	jeq L329
	movel a1@(4),a0
	movel d3,sp@-
	movel a2,sp@-
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addw #12,sp
L329:
	movel a3@(4),d0
	jlt L337
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a3@(4)
	jra L338
	.even
L337:
	clrl d1
L338:
	movel d1,a1
	tstl a1
	jne L330
	jra L341
	.even
L307:
	movel d3,d0
	notl d0
	andl d0,a2@(28)
	movel d3,d2
	lsll #5,d2
	movel a2@,d0
	andl d2,d0
	jeq L341
	lea sp@(16),a1
	lea a2@(8),a0
	movel a0,a1@
	movel a0@,sp@(20)
	movel a0@,d0
	movel a1,a3
	jlt L360
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),sp@(20)
	jra L361
	.even
L356:
	movel a1@,d0
	andl d2,d0
	jeq L355
	movel a1@(4),a0
	movel d3,sp@-
	movel a2,sp@-
	movel a1,sp@-
	movel a0@(20),a0
	jbsr a0@
	addw #12,sp
L355:
	movel a3@(4),d0
	jlt L360
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a3@(4)
	jra L361
	.even
L360:
	clrl d1
L361:
	movel d1,a1
	tstl a1
	jne L356
L341:
	moveml sp@+,#0xc0c
	addw #20,sp
	rts
	.even
.globl _dispatchMouseMove__Q25Mouse10Dispatcherssssss
_dispatchMouseMove__Q25Mouse10Dispatcherssssss:
	addw #-20,sp
	moveml #0x3c38,sp@-
	movel sp@(52),a2
	movel sp@(56),d0
	movel sp@(68),d1
	movew d0,d5
	movew d1,d4
	movew d5,d3
	subw a2@(32),d3
	movew d4,d2
	subw a2@(34),d2
	movew d0,a2@(32)
	movew d1,a2@(34)
	tstl a2@(28)
	jeq L368
	btst #1,a2@(1)
	jeq L391
	lea sp@(36),a1
	lea a2@(8),a0
	movel a0,a1@
	movel a0@,sp@(40)
	movel a0@,d0
	movel a1,a3
	jlt L376
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),sp@(40)
	jra L377
	.even
L376:
	clrl d1
L377:
	movel d1,a1
	tstl a1
	jeq L391
	.even
L383:
	btst #1,a1@(1)
	jeq L382
	movel a1@(4),a0
	movel a2@(28),sp@-
	movew d2,a4
	movel a4,sp@-
	movew d3,a4
	movel a4,sp@-
	movew d4,a4
	movel a4,sp@-
	movew d5,a4
	movel a4,sp@-
	movel a2,sp@-
	movel a1,sp@-
	movel a0@(32),a0
	jbsr a0@
	addw #28,sp
L382:
	movel a3@(4),d0
	jlt L387
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a3@(4)
	jra L388
	.even
L387:
	clrl d1
L388:
	movel d1,a1
	tstl a1
	jne L383
	jra L391
	.even
L368:
	btst #0,a2@(1)
	jeq L391
	lea sp@(28),a1
	lea a2@(8),a0
	movel a0,a1@
	movel a0@,sp@(32)
	movel a0@,d0
	movel a1,a3
	jlt L410
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),sp@(32)
	jra L411
	.even
L406:
	btst #0,a1@(1)
	jeq L405
	movel a1@(4),a0
	movew d2,a4
	movel a4,sp@-
	movew d3,a4
	movel a4,sp@-
	movew d4,a4
	movel a4,sp@-
	movew d5,a4
	movel a4,sp@-
	movel a2,sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	addw #24,sp
L405:
	movel a3@(4),d0
	jlt L410
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a3@(4)
	jra L411
	.even
L410:
	clrl d1
L411:
	movel d1,a1
	tstl a1
	jne L406
L391:
	moveml sp@+,#0x1c3c
	addw #20,sp
	rts
	.even
.globl _dispatchMouseScroll__Q25Mouse10Dispatcherss
_dispatchMouseScroll__Q25Mouse10Dispatcherss:
	addw #-12,sp
	moveml #0x3038,sp@-
	movel sp@(36),a3
	movew sp@(42),d3
	movew sp@(46),d2
	btst #2,a3@(1)
	jeq L418
	lea sp@(20),a1
	lea a3@(8),a0
	movel a0,a1@
	movel a0@,sp@(24)
	movel a0@,d0
	movel a1,a2
	jlt L436
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),sp@(24)
	jra L437
	.even
L432:
	btst #2,a1@(1)
	jeq L431
	movel a1@(4),a0
	movew d2,a4
	movel a4,sp@-
	movew d3,a4
	movel a4,sp@-
	movel a3,sp@-
	movel a1,sp@-
	movel a0@(24),a0
	jbsr a0@
	addw #16,sp
L431:
	movel a2@(4),d0
	jlt L436
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a2@(4)
	jra L437
	.even
L436:
	clrl d1
L437:
	movel d1,a1
	tstl a1
	jne L432
L418:
	moveml sp@+,#0x1c0c
	addw #12,sp
	rts
	.even
.globl ___Q23Key10Dispatcher
___Q23Key10Dispatcher:
	link a5,#-100
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-100)
	moveq #15,d0
	movel a5@(8),a0
	movel d0,a0@
	movel #___vt_Q23Key10Dispatcher,a0@(4)
	movel a5@(-100),d0
	pea a0@(8)
	jbsr ___Q211EXNGPrivate8VoidList
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L459,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a2
L459:
	lea a5@(-24),a1
	movel a1,a0@
	addql #4,sp
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	movel a2@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L471,a5@(-60)
	movel sp,a5@(-56)
	jra L470
	.even
L471:
	jra L481
	.even
L470:
	lea a5@(-72),a0
	movel a0,a2@
	movel a0@,a2@
	movel a5@(8),d0
	jra L480
	.even
L481:
L468:
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L476,a5@(-84)
	movel sp,a5@(-80)
	jra L475
	.even
L476:
	jra L482
	.even
L475:
	lea a5@(-96),a1
	movel a1,a0@
	clrl sp@-
	movel a5@(8),a0
	pea a0@(8)
	jbsr __$_Q211EXNGPrivate8VoidList
	addql #8,sp
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L482:
L473:
	jbsr ___terminate
	.even
L480:
	moveml a5@(-212),#0x5cfc
	fmovem a5@(-172),#0x3f
	unlk a5
	rts
	.even
.globl ___Q23Key10DispatcherUl
___Q23Key10DispatcherUl:
	link a5,#-100
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-100)
	moveq #15,d0
	andl a5@(12),d0
	movel a5@(8),a0
	movel d0,a0@
	movel #___vt_Q23Key10Dispatcher,a0@(4)
	movel a5@(-100),d0
	pea a0@(8)
	jbsr ___Q211EXNGPrivate8VoidList
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L490,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a2
L490:
	lea a5@(-24),a1
	movel a1,a0@
	addql #4,sp
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	movel a2@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L500,a5@(-60)
	movel sp,a5@(-56)
	jra L499
	.even
L500:
	jra L510
	.even
L499:
	lea a5@(-72),a0
	movel a0,a2@
	movel a0@,a2@
	movel a5@(8),d0
	jra L509
	.even
L510:
L497:
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L505,a5@(-84)
	movel sp,a5@(-80)
	jra L504
	.even
L505:
	jra L511
	.even
L504:
	lea a5@(-96),a1
	movel a1,a0@
	clrl sp@-
	movel a5@(8),a0
	pea a0@(8)
	jbsr __$_Q211EXNGPrivate8VoidList
	addql #8,sp
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L511:
L502:
	jbsr ___terminate
	.even
L509:
	moveml a5@(-212),#0x5cfc
	fmovem a5@(-172),#0x3f
	unlk a5
	rts
	.even
.globl __$_Q23Key10Dispatcher
__$_Q23Key10Dispatcher:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel sp@(16),d2
	movel #___vt_Q23Key10Dispatcher,a2@(4)
	pea 2:w
	pea a2@(8)
	jbsr __$_Q211EXNGPrivate8VoidList
	addql #8,sp
	btst #0,d2
	jeq L517
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L517:
	movel sp@+,d2
	movel sp@+,a2
	rts
	.even
.globl _dispatchKeyNonPrintable__Q23Key10DispatcherQ23Key7CtrlKeyb
_dispatchKeyNonPrintable__Q23Key10DispatcherQ23Key7CtrlKeyb:
	addw #-20,sp
	moveml #0x2030,sp@-
	movel sp@(36),a2
	movel sp@(40),d2
	tstb sp@(47)
	jeq L519
	btst #0,a2@(3)
	jeq L553
	lea sp@(20),a1
	lea a2@(8),a0
	movel a0,a1@
	movel a0@,sp@(24)
	movel a0@,d0
	movel a1,a3
	jlt L535
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),sp@(24)
	jra L536
	.even
L535:
	clrl d1
L536:
	movel d1,a1
	tstl a1
	jeq L553
	.even
L542:
	btst #0,a1@(3)
	jeq L541
	movel a1@(4),a0
	movel d2,sp@-
	movel a2,sp@-
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addw #12,sp
L541:
	movel a3@(4),d0
	jlt L549
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a3@(4)
	jra L550
	.even
L549:
	clrl d1
L550:
	movel d1,a1
	tstl a1
	jne L542
	jra L553
	.even
L519:
	btst #2,a2@(3)
	jeq L553
	lea sp@(12),a1
	lea a2@(8),a0
	movel a0,a1@
	movel a0@,sp@(16)
	movel a0@,d0
	movel a1,a3
	jlt L572
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),sp@(16)
	jra L573
	.even
L568:
	btst #2,a1@(3)
	jeq L567
	movel a1@(4),a0
	movel d2,sp@-
	movel a2,sp@-
	movel a1,sp@-
	movel a0@(20),a0
	jbsr a0@
	addw #12,sp
L567:
	movel a3@(4),d0
	jlt L572
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a3@(4)
	jra L573
	.even
L572:
	clrl d1
L573:
	movel d1,a1
	tstl a1
	jne L568
L553:
	moveml sp@+,#0xc04
	addw #20,sp
	rts
	.even
.globl _dispatchKeyPrintable__Q23Key10Dispatcherlb
_dispatchKeyPrintable__Q23Key10Dispatcherlb:
	addw #-20,sp
	moveml #0x2030,sp@-
	movel sp@(36),a2
	movel sp@(40),d2
	tstb sp@(47)
	jeq L580
	btst #1,a2@(3)
	jeq L603
	lea sp@(20),a1
	lea a2@(8),a0
	movel a0,a1@
	movel a0@,sp@(24)
	movel a0@,d0
	movel a1,a3
	jlt L588
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),sp@(24)
	jra L589
	.even
L588:
	clrl d1
L589:
	movel d1,a1
	tstl a1
	jeq L603
	.even
L595:
	btst #1,a1@(3)
	jeq L594
	movel a1@(4),a0
	movel d2,sp@-
	movel a2,sp@-
	movel a1,sp@-
	movel a0@(24),a0
	jbsr a0@
	addw #12,sp
L594:
	movel a3@(4),d0
	jlt L599
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a3@(4)
	jra L600
	.even
L599:
	clrl d1
L600:
	movel d1,a1
	tstl a1
	jne L595
	jra L603
	.even
L580:
	btst #3,a2@(3)
	jeq L603
	lea sp@(12),a1
	lea a2@(8),a0
	movel a0,a1@
	movel a0@,sp@(16)
	movel a0@,d0
	movel a1,a3
	jlt L622
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),sp@(16)
	jra L623
	.even
L618:
	btst #3,a1@(3)
	jeq L617
	movel a1@(4),a0
	movel d2,sp@-
	movel a2,sp@-
	movel a1,sp@-
	movel a0@(28),a0
	jbsr a0@
	addw #12,sp
L617:
	movel a3@(4),d0
	jlt L622
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	movel a0@(12,d0:l),d1
	movel a0@(4,d0:l),a3@(4)
	jra L623
	.even
L622:
	clrl d1
L623:
	movel d1,a1
	tstl a1
	jne L618
L603:
	moveml sp@+,#0xc04
	addw #20,sp
	rts
.globl ___vt_Q23Key10Dispatcher
	.even
___vt_Q23Key10Dispatcher:
	.long 0
	.long ___tfQ23Key10Dispatcher
	.long __dfRTTI__Q23Key10Dispatcher
	.long ___pure_virtual
	.long __$_Q23Key10Dispatcher
	.skip 4
.globl ___vt_Q23Key8Observer
	.even
___vt_Q23Key8Observer:
	.long 0
	.long ___tfQ23Key8Observer
	.long __dfRTTI__Q23Key8Observer
	.long _applyKeyEventFilter__Q23Key8ObserverUl
	.long ___pure_virtual
	.long ___pure_virtual
	.long ___pure_virtual
	.long ___pure_virtual
	.long __$_Q23Key8Observer
	.skip 4
.globl ___vt_Q23Key6Filter
	.even
___vt_Q23Key6Filter:
	.long 0
	.long ___tfQ23Key6Filter
	.long __dfRTTI__Q23Key6Filter
	.long ___pure_virtual
	.skip 4
.globl ___vt_Q25Mouse10Dispatcher
	.even
___vt_Q25Mouse10Dispatcher:
	.long 0
	.long ___tfQ25Mouse10Dispatcher
	.long __dfRTTI__Q25Mouse10Dispatcher
	.long ___pure_virtual
	.long __$_Q25Mouse10Dispatcher
	.skip 4
.globl ___vt_Q25Mouse8Observer
	.even
___vt_Q25Mouse8Observer:
	.long 0
	.long ___tfQ25Mouse8Observer
	.long __dfRTTI__Q25Mouse8Observer
	.long _applyMouseEventFilter__Q25Mouse8ObserverUl
	.long ___pure_virtual
	.long ___pure_virtual
	.long ___pure_virtual
	.long ___pure_virtual
	.long ___pure_virtual
	.long __$_Q25Mouse8Observer
	.skip 4
.globl ___vt_Q25Mouse6Filter
	.even
___vt_Q25Mouse6Filter:
	.long 0
	.long ___tfQ25Mouse6Filter
	.long __dfRTTI__Q25Mouse6Filter
	.long ___pure_virtual
	.skip 4
.globl ___vt_9EventMask
	.even
___vt_9EventMask:
	.long 0
	.long ___tf9EventMask
	.long __dfRTTI__9EventMask
	.skip 4
.comm ___ti9EventMask,8
LC0:
	.ascii "9EventMask\0"
.comm ___tiQ25Mouse6Filter,16
	.even
LC1:
	.long ___ti9EventMask
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x2
LC2:
	.ascii "Q25Mouse6Filter\0"
.comm ___tiQ25Mouse8Observer,12
LC3:
	.ascii "Q25Mouse8Observer\0"
.comm ___tiQ25Mouse10Dispatcher,12
LC4:
	.ascii "Q25Mouse10Dispatcher\0"
.comm ___tiQ23Key6Filter,16
LC5:
	.ascii "Q23Key6Filter\0"
.comm ___tiQ23Key8Observer,12
LC6:
	.ascii "Q23Key8Observer\0"
.comm ___tiQ23Key10Dispatcher,12
LC7:
	.ascii "Q23Key10Dispatcher\0"
	.even
.globl ___tf9EventMask
___tf9EventMask:
	movel a2,sp@-
	lea ___ti9EventMask,a2
	tstl a2@
	jne L630
	pea LC0
	movel a2,sp@-
	jbsr ___rtti_user
	addql #8,sp
L630:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ25Mouse6Filter
___tfQ25Mouse6Filter:
	movel a2,sp@-
	lea ___tiQ25Mouse6Filter,a2
	tstl a2@
	jne L632
	tstl ___ti9EventMask
	jne L634
	pea LC0
	pea ___ti9EventMask
	jbsr ___rtti_user
	addql #8,sp
L634:
	pea 1:w
	pea LC1
	pea LC2
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L632:
	movel #___tiQ25Mouse6Filter,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ25Mouse8Observer
___tfQ25Mouse8Observer:
	tstl ___tiQ25Mouse8Observer
	jne L636
	tstl ___tiQ25Mouse6Filter
	jne L640
	tstl ___ti9EventMask
	jne L639
	pea LC0
	pea ___ti9EventMask
	jbsr ___rtti_user
	addql #8,sp
L639:
	pea 1:w
	pea LC1
	pea LC2
	pea ___tiQ25Mouse6Filter
	jbsr ___rtti_class
	addw #16,sp
L640:
	pea ___tiQ25Mouse6Filter
	pea LC3
	pea ___tiQ25Mouse8Observer
	jbsr ___rtti_si
	addw #12,sp
L636:
	movel #___tiQ25Mouse8Observer,d0
	rts
	nop
	.even
.globl ___tfQ25Mouse10Dispatcher
___tfQ25Mouse10Dispatcher:
	tstl ___tiQ25Mouse10Dispatcher
	jne L642
	tstl ___tiQ25Mouse6Filter
	jne L646
	tstl ___ti9EventMask
	jne L645
	pea LC0
	pea ___ti9EventMask
	jbsr ___rtti_user
	addql #8,sp
L645:
	pea 1:w
	pea LC1
	pea LC2
	pea ___tiQ25Mouse6Filter
	jbsr ___rtti_class
	addw #16,sp
L646:
	pea ___tiQ25Mouse6Filter
	pea LC4
	pea ___tiQ25Mouse10Dispatcher
	jbsr ___rtti_si
	addw #12,sp
L642:
	movel #___tiQ25Mouse10Dispatcher,d0
	rts
	nop
	.even
.globl ___tfQ23Key6Filter
___tfQ23Key6Filter:
	movel a2,sp@-
	lea ___tiQ23Key6Filter,a2
	tstl a2@
	jne L648
	tstl ___ti9EventMask
	jne L650
	pea LC0
	pea ___ti9EventMask
	jbsr ___rtti_user
	addql #8,sp
L650:
	pea 1:w
	pea LC1
	pea LC5
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L648:
	movel #___tiQ23Key6Filter,d0
	movel sp@+,a2
	rts
	.even
.globl ___tfQ23Key8Observer
___tfQ23Key8Observer:
	tstl ___tiQ23Key8Observer
	jne L652
	tstl ___tiQ23Key6Filter
	jne L656
	tstl ___ti9EventMask
	jne L655
	pea LC0
	pea ___ti9EventMask
	jbsr ___rtti_user
	addql #8,sp
L655:
	pea 1:w
	pea LC1
	pea LC5
	pea ___tiQ23Key6Filter
	jbsr ___rtti_class
	addw #16,sp
L656:
	pea ___tiQ23Key6Filter
	pea LC6
	pea ___tiQ23Key8Observer
	jbsr ___rtti_si
	addw #12,sp
L652:
	movel #___tiQ23Key8Observer,d0
	rts
	nop
	.even
.globl ___tfQ23Key10Dispatcher
___tfQ23Key10Dispatcher:
	tstl ___tiQ23Key10Dispatcher
	jne L658
	tstl ___tiQ23Key6Filter
	jne L662
	tstl ___ti9EventMask
	jne L661
	pea LC0
	pea ___ti9EventMask
	jbsr ___rtti_user
	addql #8,sp
L661:
	pea 1:w
	pea LC1
	pea LC5
	pea ___tiQ23Key6Filter
	jbsr ___rtti_class
	addw #16,sp
L662:
	pea ___tiQ23Key6Filter
	pea LC7
	pea ___tiQ23Key10Dispatcher
	jbsr ___rtti_si
	addw #12,sp
L658:
	movel #___tiQ23Key10Dispatcher,d0
	rts
	nop
