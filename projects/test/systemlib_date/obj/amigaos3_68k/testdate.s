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
	movel #L241,a5@(-12)
	movel sp,a5@(-8)
	jra L240
	.even
L241:
	jra L251
	.even
L240:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___19DateTestApplication
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L237
	.even
L251:
L238:
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L247,a5@(-36)
	movel sp,a5@(-32)
	jra L246
	.even
L247:
	jra L252
	.even
L246:
	lea a5@(-48),a1
	movel a1,a0@
	moveq #1,d0
	jeq L249
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L249:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L252:
L244:
	jbsr ___terminate
	.even
L237:
	moveml a5@(-168),#0x5cfc
	fmovem a5@(-128),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L261
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L261:
	rts
	nop
LC0:
	.ascii "Created DateTestApplication\12\0"
	.even
.globl ___19DateTestApplication
___19DateTestApplication:
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
	movel #L267,a5@(-12)
	movel sp,a5@(-8)
L267:
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
	movel #L281,a5@(-60)
	movel sp,a5@(-56)
	jra L280
	.even
L281:
	jra L295
	.even
L280:
	lea a5@(-72),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_19DateTestApplication,a0@
	pea LC0
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L294
	.even
L295:
L278:
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L286,a5@(-84)
	movel sp,a5@(-80)
	jra L285
	.even
L286:
	jra L296
	.even
L285:
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
L296:
L283:
	jbsr ___terminate
	.even
L294:
	moveml a5@(-212),#0x5cfc
	fmovem a5@(-172),#0x3f
	unlk a5
	rts
LC1:
	.ascii "Destroyed DateTestApplication\12\0"
	.even
.globl __$_19DateTestApplication
__$_19DateTestApplication:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel sp@(16),d2
	movel #___vt_19DateTestApplication,a2@
	pea LC1
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel #___vt_8Runnable,a2@
	btst #0,d2
	jeq L304
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L304:
	movel sp@+,d2
	movel sp@+,a2
	rts
LC2:
	.ascii "Testing: %s %s\12\0"
LC3:
	.ascii "passed\0"
LC4:
	.ascii "failed\0"
LC5:
	.ascii "ds0: \0"
LC6:
	.ascii "ds1: \0"
LC7:
	.ascii "ds2: \0"
LC8:
	.ascii "ds0.leapYear()\0"
LC9:
	.ascii "ds0<ds1 \0"
LC10:
	.ascii "ds0<=ds1\0"
LC11:
	.ascii "ds0==ds1\0"
LC12:
	.ascii "ds0>=ds1\0"
LC13:
	.ascii "ds0>ds1 \0"
LC14:
	.ascii "ds0<ds2 \0"
LC15:
	.ascii "ds0<=ds2\0"
LC16:
	.ascii "ds0==ds2\0"
LC17:
	.ascii "ds0>=ds2\0"
LC18:
	.ascii "ds0>ds2\0"
LC19:
	.ascii "ds1<ds2 \0"
LC20:
	.ascii "ds1<=ds2\0"
LC21:
	.ascii "ds1==ds2\0"
LC22:
	.ascii "ds1>=ds2\0"
LC23:
	.ascii "ds1>ds2 \0"
LC24:
	.ascii "Testing ds1 += interval\12\0"
	.even
.globl _run__19DateTestApplication
_run__19DateTestApplication:
	link a5,#-32
	moveml #0x3f38,sp@-
	movel a5@(8),d7
	lea a5@(-16),a4
	movel a4,sp@-
	jbsr _now__Q24Time9Datestamp
	addql #4,sp
	movel a5@(-12),d0
	andl #-134217728,d0
	moveq #-24,d3
	addl a5,d3
	clrl sp@-
	clrl sp@-
	clrl sp@-
	clrl sp@-
	moveq #27,d1
	lsrl d1,d0
	movel d0,sp@-
	moveq #15,d0
	andl a4@,d0
	movel d0,sp@-
	bfextu a4@(1){#3:#17},d1
	movel d1,sp@-
	movel d3,sp@-
	jbsr _set__Q24Time9DatestampUlUsUsUsUsUsUs
	addw #28,sp
	clrl sp@
	movel d3,sp@-
	jbsr _setTimeZoneOffset__Q24Time9Datestamps
	addql #8,sp
	movel a5@(-12),d0
	andl #-134217728,d0
	moveq #-32,d2
	addl a5,d2
	clrl sp@-
	clrl sp@-
	clrl sp@-
	pea 1:w
	moveq #27,d1
	lsrl d1,d0
	movel d0,sp@-
	moveq #15,d0
	andl a4@,d0
	movel d0,sp@-
	bfextu a4@(1){#3:#17},d1
	movel d1,sp@-
	movel d2,sp@-
	jbsr _set__Q24Time9DatestampUlUsUsUsUsUsUs
	addw #28,sp
	movel #-60,sp@
	movel d2,sp@-
	jbsr _setTimeZoneOffset__Q24Time9Datestamps
	addql #8,sp
	clrl a5@(-8)
	movel #100,a5@(-4)
	movel #LC2,d6
	movel #LC3,d5
	movel #LC4,d4
	pea LC5
	lea _printf,a3
	jbsr a3@
	movel a4,sp@-
	movel d7,sp@-
	lea _printDatestamp__19DateTestApplicationRCQ24Time9Datestamp,a2
	jbsr a2@
	pea LC6
	jbsr a3@
	movel d3,sp@-
	movel d7,sp@-
	jbsr a2@
	pea LC7
	jbsr a3@
	movel d2,sp@-
	movel d7,sp@-
	jbsr a2@
	addw #36,sp
	bfextu a4@(1){#3:#17},d0
	movel d0,sp@-
	jbsr _leapYear__4Timel
	addql #4,sp
	movel d4,d1
	tstb d0
	jeq L322
	movel d5,d1
L322:
	movel d1,sp@-
	pea LC8
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-24)
	pea a5@(-16)
	jbsr ___lt__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	tstb d0
	jeq L326
	movel d5,d1
L326:
	movel d1,sp@-
	pea LC9
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-24)
	pea a5@(-16)
	jbsr ___le__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	tstb d0
	jeq L328
	movel d5,d1
L328:
	movel d1,sp@-
	pea LC10
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-24)
	pea a5@(-16)
	jbsr ___eq__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	tstb d0
	jeq L330
	movel d5,d1
L330:
	movel d1,sp@-
	pea LC11
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-24)
	pea a5@(-16)
	jbsr ___lt__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	cmpb #1,d0
	jeq L332
	movel d5,d1
L332:
	movel d1,sp@-
	pea LC12
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-24)
	pea a5@(-16)
	jbsr ___le__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	cmpb #1,d0
	jeq L335
	movel d5,d1
L335:
	movel d1,sp@-
	pea LC13
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-32)
	pea a5@(-16)
	jbsr ___lt__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	tstb d0
	jeq L338
	movel d5,d1
L338:
	movel d1,sp@-
	pea LC14
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-32)
	pea a5@(-16)
	jbsr ___le__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	tstb d0
	jeq L340
	movel d5,d1
L340:
	movel d1,sp@-
	pea LC15
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-32)
	pea a5@(-16)
	jbsr ___eq__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	tstb d0
	jeq L342
	movel d5,d1
L342:
	movel d1,sp@-
	pea LC16
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-32)
	pea a5@(-16)
	jbsr ___lt__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	cmpb #1,d0
	jeq L344
	movel d5,d1
L344:
	movel d1,sp@-
	pea LC17
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-32)
	pea a5@(-16)
	jbsr ___le__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	cmpb #1,d0
	jeq L347
	movel d5,d1
L347:
	movel d1,sp@-
	pea LC18
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-32)
	pea a5@(-24)
	jbsr ___lt__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	tstb d0
	jeq L350
	movel d5,d1
L350:
	movel d1,sp@-
	pea LC19
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-32)
	pea a5@(-24)
	jbsr ___le__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	tstb d0
	jeq L352
	movel d5,d1
L352:
	movel d1,sp@-
	pea LC20
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-32)
	pea a5@(-24)
	jbsr ___eq__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	tstb d0
	jeq L354
	movel d5,d1
L354:
	movel d1,sp@-
	pea LC21
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-32)
	pea a5@(-24)
	jbsr ___lt__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	cmpb #1,d0
	jeq L356
	movel d5,d1
L356:
	movel d1,sp@-
	pea LC22
	movel d6,sp@-
	jbsr _printf
	addw #12,sp
	pea a5@(-32)
	pea a5@(-24)
	jbsr ___le__CQ24Time9DatestampRCQ24Time9Datestamp
	addql #8,sp
	movel d4,d1
	cmpb #1,d0
	jeq L359
	movel d5,d1
L359:
	movel d1,sp@-
	pea LC23
	movel d6,sp@-
	lea _printf,a2
	jbsr a2@
	pea LC24
	jbsr a2@
	addw #16,sp
	moveq #19,d2
	.even
L365:
	pea a5@(-24)
	movel d7,sp@-
	jbsr _printDatestamp__19DateTestApplicationRCQ24Time9Datestamp
	pea a5@(-8)
	pea a5@(-24)
	jbsr ___apl__Q24Time9DatestampRCQ24Time8Interval
	addw #16,sp
	pea a5@(-24)
	movel d7,sp@-
	jbsr _printDatestamp__19DateTestApplicationRCQ24Time9Datestamp
	pea a5@(-8)
	pea a5@(-24)
	jbsr ___apl__Q24Time9DatestampRCQ24Time8Interval
	addw #16,sp
	pea a5@(-24)
	movel d7,sp@-
	jbsr _printDatestamp__19DateTestApplicationRCQ24Time9Datestamp
	pea a5@(-8)
	pea a5@(-24)
	jbsr ___apl__Q24Time9DatestampRCQ24Time8Interval
	addw #16,sp
	pea a5@(-24)
	movel d7,sp@-
	jbsr _printDatestamp__19DateTestApplicationRCQ24Time9Datestamp
	pea a5@(-8)
	pea a5@(-24)
	jbsr ___apl__Q24Time9DatestampRCQ24Time8Interval
	addw #16,sp
	pea a5@(-24)
	movel d7,sp@-
	jbsr _printDatestamp__19DateTestApplicationRCQ24Time9Datestamp
	pea a5@(-8)
	pea a5@(-24)
	jbsr ___apl__Q24Time9DatestampRCQ24Time8Interval
	addw #16,sp
	subql #5,d2
	jpl L365
	clrl d0
	moveml a5@(-68),#0x1cfc
	unlk a5
	rts
LC25:
	.ascii "%04ld-%02ld-%02ld %02ld:%02ld:%02ld.%03ld%+ld:%02ld\12\0"
	.even
.globl _printDatestamp__19DateTestApplicationRCQ24Time9Datestamp
_printDatestamp__19DateTestApplicationRCQ24Time9Datestamp:
	movel d2,sp@-
	movel sp@(12),a0
	movel a0@,d0
	andl #-2097152,d0
	moveq #21,d1
	asrl d1,d0
	moveq #60,d2
	divsll d2,d1:d0
	movel d1,sp@-
	movel a0@,d0
	andl #-2097152,d0
	moveq #21,d1
	asrl d1,d0
	divsl d2,d0
	movel d0,sp@-
	movel a0@(4),d2
	andl #1023,d2
	movel d2,sp@-
	bfextu a0@(6){#0:#6},d0
	movel d0,sp@-
	movew a0@(4),d1
	moveq #63,d2
	andl d2,d1
	movel d1,sp@-
	bfextu a0@(4){#5:#5},d0
	movel d0,sp@-
	movel a0@(4),d0
	andl #-134217728,d0
	moveq #27,d1
	lsrl d1,d0
	movel d0,sp@-
	moveq #15,d2
	andl a0@,d2
	movel d2,sp@-
	bfextu a0@(1){#3:#17},d0
	movel d0,sp@-
	pea LC25
	jbsr _printf
	addw #40,sp
	movel sp@+,d2
	rts
.globl ___vt_19DateTestApplication
	.even
___vt_19DateTestApplication:
	.long 0
	.long ___tf19DateTestApplication
	.long __dfRTTI__11Application
	.long _run__19DateTestApplication
	.long __$_19DateTestApplication
	.skip 4
.comm ___ti19DateTestApplication,16
	.even
LC26:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC27:
	.ascii "19DateTestApplication\0"
	.even
.globl ___tf19DateTestApplication
___tf19DateTestApplication:
	movel a2,sp@-
	lea ___ti19DateTestApplication,a2
	tstl a2@
	jne L388
	jbsr ___tf11Application
	pea 1:w
	pea LC26
	pea LC27
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L388:
	movel #___ti19DateTestApplication,d0
	movel sp@+,a2
	rts
