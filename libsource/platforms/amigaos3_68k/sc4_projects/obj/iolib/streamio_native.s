#NO_APP
.globl __17AsyncStreamBuffer$loggingClassName
.text
LC0:
	.ascii "AsyncStreamBuffer\0"
.data
	.even
__17AsyncStreamBuffer$loggingClassName:
	.long LC0
.text
	.even
.globl _sendPacket__17AsyncStreamBufferPv
_sendPacket__17AsyncStreamBufferPv:
	movel a2,sp@-
	movel sp@(8),a2
	lea a2@(118),a0
	movel a0,a2@(74)
	movel sp@(12),a2@(94)
	pea a2@(50)
	movel a2@(46),sp@-
	jbsr _PutMsg
	moveq #1,d0
	orl d0,a2@(14)
	addql #8,sp
	movel sp@+,a2
	rts
LC1:
	.ascii "waitPacket()\0"
.data
	.even
_loggingFuncName.231:
	.long LC1
.text
LC2:
	.ascii "%s::%s - IO failure\12\0"
	.even
.globl _waitPacket__17AsyncStreamBuffer
_waitPacket__17AsyncStreamBuffer:
	movel a2,sp@-
	movel sp@(8),a2
	btst #0,a2@(17)
	jeq L234
	.even
L237:
	clrb a2@(132)
	pea a2@(118)
	jbsr _WaitPort
	movel d0,sp@-
	jbsr _Remove
	moveb #2,a2@(132)
	moveq #-2,d0
	andl d0,a2@(14)
	movel a2@(82),d0
	addql #8,sp
	jge L233
	clrl sp@-
	movel a2@(42),sp@-
	clrl sp@-
	movel a2@(86),sp@-
	jbsr _ErrorReport
	addw #16,sp
	tstl d0
	jne L245
	btst #4,a2@(17)
	jeq L240
	movel a2@(18),d0
	jra L247
	.even
L240:
	moveq #1,d0
	subl a2@(18),d0
L247:
	movel a2@(30,d0:l:4),sp@-
	movel a2,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	addql #8,sp
	jra L237
	.even
L234:
	movel a2@(86),sp@-
	jbsr _SetIoErr
	movel a2@(82),d0
	addql #4,sp
	jra L233
	.even
L245:
	moveq #-9,d0
	andl d0,a2@(14)
	movel _loggingFuncName.231,sp@-
	movel __17AsyncStreamBuffer$loggingClassName,sp@-
	pea LC2
	pea 2:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	moveq #-1,d0
	addw #16,sp
L233:
	movel sp@+,a2
	rts
	.even
.globl _requeuePacket__17AsyncStreamBuffer
_requeuePacket__17AsyncStreamBuffer:
	movel a2,sp@-
	movel sp@(8),a2
	pea a2@(50)
	pea a2@(138)
	jbsr _AddHead
	moveq #1,d0
	orl d0,a2@(14)
	addql #8,sp
	movel sp@+,a2
	rts
	.even
.globl _recordSyncFailure__17AsyncStreamBuffer
_recordSyncFailure__17AsyncStreamBuffer:
	movel a2,sp@-
	movel sp@(8),a2
	moveq #-1,d0
	movel d0,a2@(82)
	jbsr _IoErr
	movel d0,a2@(86)
	clrl a2@(26)
	moveq #-9,d0
	andl d0,a2@(14)
	movel sp@+,a2
	rts
LC3:
	.ascii "create()\0"
.data
	.even
_loggingFuncName.241:
	.long LC3
.text
LC4:
	.ascii "%s::%s - Failed to initialise buffer\12\0"
	.even
.globl _create__17AsyncStreamBufferUl
_create__17AsyncStreamBufferUl:
	moveml #0x3020,sp@-
	movel sp@(16),a2
	movel sp@(20),d3
	tstl a2@(42)
	jeq L251
	tstl a2@(30)
	jne L251
	pea 16:w
	subql #2,sp
	moveb #1,sp@(1)
	subql #2,sp
	movel d3,sp@-
	jbsr _alloc__3MemUlbQ23Mem9AlignType
	movel d0,d1
	movel d1,a2@(30)
	addw #12,sp
	jeq L251
	movel a2@(42),d2
	lsll #2,d2
	movel d2,a0
	movel a0@(8),a2@(46)
	movel d3,d0
	lsrl #1,d0
	movel d0,a2@(2)
	addl d1,d0
	movel d0,a2@(34)
	movel d1,a2@(38)
	clrl a2@(18)
	clrl a2@(22)
	moveq #-2,d0
	andl d0,a2@(14)
	lea a2@(142),a0
	movel a0,a2@(138)
	clrl a0@
	lea a2@(138),a0
	movel a0,a2@(146)
	moveb #4,a2@(126)
	clrl a2@(128)
	moveb #2,a2@(132)
	moveb #4,a2@(133)
	clrl sp@-
	jbsr _FindTask
	movel d0,a2@(134)
	lea a2@(50),a0
	movel a0,a2@(70)
	movel d2,a0
	movel a0@(36),a2@(90)
	movel a2@(2),a2@(98)
	clrl a2@(82)
	clrl a2@(86)
	lea a2@(70),a0
	movel a0,a2@(60)
	moveb #5,a2@(58)
	movew #68,a2@(68)
	moveq #1,d0
	addql #4,sp
	jra L250
	.even
L251:
	movel _loggingFuncName.241,sp@-
	movel __17AsyncStreamBuffer$loggingClassName,sp@-
	pea LC4
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	clrb d0
	addw #16,sp
L250:
	moveml sp@+,#0x40c
	rts
	.even
.globl _destroy__17AsyncStreamBuffer
_destroy__17AsyncStreamBuffer:
	movel a2,sp@-
	movel sp@(8),a2
	movel a2@(30),d0
	jeq L254
	movel d0,sp@-
	jbsr _free__3MemPv
	clrl a2@(30)
	addql #4,sp
L254:
	movel sp@+,a2
	rts
	.even
.globl _exists__17AsyncStreamBufferPCc
_exists__17AsyncStreamBufferPCc:
	pea 1005:w
	movel sp@(8),sp@-
	jbsr _Open
	addql #8,sp
	tstl d0
	jeq L256
	movel d0,sp@-
	jbsr _Close
	moveq #1,d0
	addql #4,sp
	rts
	.even
L256:
	clrb d0
	rts
	nop
.globl __8StreamIn$loggingClassName
LC5:
	.ascii "StreamIn\0"
.data
	.even
__8StreamIn$loggingClassName:
	.long LC5
.text
	.even
.globl ___8StreamInPCcbUl
___8StreamInPCcbUl:
	link a5,#-52
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,d1
	movel a5@(8),a0
	clrl a0@(14)
	clrl a0@(42)
	clrl a0@(30)
	movel d1,a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L263,a5@(-12)
	movel sp,a5@(-8)
	jra L262
	.even
L263:
	jra L275
	.even
L262:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(20),sp@-
	subql #2,sp
	moveb a5@(19),sp@(1)
	subql #2,sp
	movel a5@(12),sp@-
	movel a5@(8),sp@-
	movel d1,a0
	addql #4,a0
	movel a0,a5@(-52)
	jbsr _open__8StreamInPCcbUl
	addw #16,sp
	movel a5@(-52),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L274
	.even
L275:
L260:
	movel a5@(-52),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L268,a5@(-36)
	movel sp,a5@(-32)
	jra L267
	.even
L268:
	jra L276
	.even
L267:
	lea a5@(-48),a0
	movel a5@(-52),a1
	movel a0,a1@
	movel a5@(8),sp@-
	jbsr _destroy__17AsyncStreamBuffer
	addql #4,sp
	movel a5@(-52),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L276:
L265:
	jbsr ___terminate
	.even
L274:
	moveml a5@(-164),#0x5cfc
	fmovem a5@(-124),#0x3f
	unlk a5
	rts
	.even
.globl __$_8StreamIn
__$_8StreamIn:
	movel d3,sp@-
	movel d2,sp@-
	movel sp@(12),d3
	movel sp@(16),d2
	movel d3,sp@-
	jbsr _close__8StreamIn
	movel d3,sp@
	jbsr _destroy__17AsyncStreamBuffer
	addql #4,sp
	btst #0,d2
	jeq L282
	movel d3,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L282:
	movel sp@+,d2
	movel sp@+,d3
	rts
	.even
.globl _getNextCharIO__8StreamIn
_getNextCharIO__8StreamIn:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	movel d0,d2
	addql #4,sp
	jgt L284
	jne L285
	moveq #2,d0
	orl d0,a2@(14)
	clrl sp@-
	jbsr _SetIoErr
	moveq #-1,d0
	addql #4,sp
	jra L283
	.even
L285:
	moveq #-9,d0
	andl d0,a2@(14)
	jbsr _throwStreamReadError
L284:
	movel a2@(18),d0
	eorw #1,d0
	movel a2@(30,d0:l:4),sp@-
	movel a2,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	addql #8,sp
	cmpl a2@(22),d2
	jcc L287
	movel d2,a2@(22)
L287:
	movel a2@(18),d0
	movel a2@(22),d1
	movel a2@(30,d0:l:4),a0
	addl d1,a0
	eorw #1,d0
	movel d0,a2@(18)
	subl d1,d2
	clrl a2@(22)
	subql #1,d2
	movel d2,a2@(26)
	lea a0@(1),a1
	movel a1,a2@(38)
	clrl d0
	moveb a0@,d0
L283:
	movel sp@+,d2
	movel sp@+,a2
	rts
LC6:
	.ascii "open()\0"
.data
	.even
_loggingFuncName.260:
	.long LC6
.text
LC7:
	.ascii "%s::%s - stream %s contains no data\12\0"
LC8:
	.ascii "%s::%s - unable to open %s\12\0"
	.even
.globl _open__8StreamInPCcbUl
_open__8StreamInPCcbUl:
	addw #-44,sp
	moveml #0x3030,sp@-
	movel sp@(64),a3
	movel sp@(68),d3
	jne L289
	jbsr _throwInvalidValue
L289:
	tstl a3@(42)
	jeq L290
	movel a3,sp@-
	jbsr _close__8StreamIn
	addql #4,sp
L290:
	pea 1005:w
	movel d3,sp@-
	jbsr _Open
	movel d0,a3@(42)
	addql #8,sp
	jeq L291
	pea 1:w
	clrl sp@-
	movel d0,sp@-
	lea _Seek,a2
	jbsr a2@
	addw #12,sp
	tstl d0
	jlt L292
	clrl sp@-
	clrl sp@-
	movel a3@(42),sp@-
	jbsr a2@
	movel d0,a3@(6)
	addw #12,sp
	jra L293
	.even
L292:
	movel a3@(42),sp@-
	jbsr _Close
	clrl a3@(6)
	clrl a3@(42)
	movel d3,sp@-
	movel _loggingFuncName.260,sp@-
	movel __8StreamIn$loggingClassName,sp@-
	pea LC7
	pea 2:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	jbsr _throwStreamOpenError
	addw #24,sp
L293:
	pea -1:w
	clrl sp@-
	movel a3@(42),sp@-
	jbsr a2@
	moveq #16,d0
	orl d0,a3@(14)
	movel #512,a3@(10)
	pea -2:w
	movel d3,sp@-
	jbsr _Lock
	movel d0,a2
	addw #20,sp
	tstl a2
	jeq L294
	moveq #19,d2
	addl sp,d2
	moveq #-4,d1
	andl d1,d2
	movel d2,sp@-
	movel a2,sp@-
	jbsr _Info
	addql #8,sp
	tstl d0
	jeq L295
	movel d2,a0
	movel a0@(20),a3@(10)
L295:
	movel a2,sp@-
	jbsr _UnLock
	addql #4,sp
L294:
	movel a3@(10),d2
	movel d2,d1
	addl d1,d1
	movel sp@(76),a0
	lea a0@(-1,d1:l),a0
	movel a0,d0
	divul d1,d0
	addl d0,d0
	mulsl d2,d0
	movel d0,sp@-
	movel a3,sp@-
	jbsr _create__17AsyncStreamBufferUl
	addql #8,sp
	tstb d0
	jeq L296
	moveq #82,d0
	movel d0,a3@(78)
	clrl a3@(26)
	movel a3@(34),a3@(38)
	tstl a3@(46)
	jeq L297
	movel a3@(30),sp@-
	movel a3,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	addql #8,sp
L297:
	movel a3@(14),d0
	moveq #8,d1
	orl d0,d1
	movel d1,a3@(14)
	tstb sp@(75)
	jeq L288
	moveq #119,d1
	notb d1
	orl d0,d1
	movel d1,a3@(14)
	jra L288
	.even
L296:
	andw #65287,a3@(16)
	movel a3@(42),sp@-
	jbsr _Close
	clrl a3@(42)
	addql #4,sp
L291:
	movel d3,sp@-
	movel _loggingFuncName.260,sp@-
	movel __8StreamIn$loggingClassName,sp@-
	pea LC8
	pea 2:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	jbsr _throwStreamOpenError
	addw #20,sp
L288:
	moveml sp@+,#0xc0c
	addw #44,sp
	rts
	.even
.globl _close__8StreamIn
_close__8StreamIn:
	movel a2,sp@-
	movel sp@(8),a2
	tstl a2@(42)
	jeq L301
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	movel a2@(42),sp@-
	jbsr _Close
	movel a2,sp@-
	jbsr _destroy__17AsyncStreamBuffer
	clrl a2@(42)
	andw #65287,a2@(16)
	addw #12,sp
L301:
	movel sp@+,a2
	rts
	.even
.globl _flush__8StreamIn
_flush__8StreamIn:
	movel sp@(4),a0
	tstl a0@(42)
	jeq L303
	movel a0,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	addql #4,sp
L303:
	rts
	nop
	.even
.globl _tell__8StreamIn
_tell__8StreamIn:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	tstl a2@(42)
	jne L305
	jbsr _throwStreamSeekError
L305:
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	movel d0,d2
	addql #4,sp
	jge L306
	jbsr _throwStreamSeekError
L306:
	clrl sp@-
	clrl sp@-
	movel a2@(42),sp@-
	jbsr _Seek
	movel a2@(26),d1
	addl d2,d1
	subl d1,d0
	addl a2@(22),d0
	addw #12,sp
	movel sp@+,d2
	movel sp@+,a2
	rts
	.even
.globl _seek__8StreamInlQ22IO8SeekMode
_seek__8StreamInlQ22IO8SeekMode:
	addw #-268,sp
	moveml #0x3f30,sp@-
	movel sp@(304),a3
	movel sp@(308),d7
	movel sp@(312),d2
	tstl a3@(42)
	jne L308
	jbsr _throwStreamSeekError
L308:
	movel a3,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	movel d0,d6
	addql #4,sp
	jge L309
	jbsr _throwStreamSeekError
L309:
	clrl sp@-
	clrl sp@-
	movel a3@(42),sp@-
	lea _Seek,a2
	jbsr a2@
	movel d0,d5
	addw #12,sp
	jge L310
	movel a3,sp@-
	jbsr _recordSyncFailure__17AsyncStreamBuffer
	jbsr _throwStreamSeekError
	addql #4,sp
L310:
	movel a3@(26),d1
	addl d6,d1
	movel d5,d0
	subl d1,d0
	movel d0,d4
	addl a3@(22),d4
	clrl d3
	moveq #1,d0
	cmpl d2,d0
	jeq L313
	jlt L318
	tstl d2
	jeq L312
	jra L316
	.even
L318:
	moveq #2,d1
	cmpl d2,d1
	jeq L314
	jra L316
	.even
L312:
	movel d7,d3
	jra L311
	.even
L313:
	movel d4,d3
	addl d7,d3
	jra L311
	.even
L314:
	moveq #35,d2
	addl sp,d2
	moveq #-4,d0
	andl d0,d2
	movel d2,sp@-
	movel a3@(42),sp@-
	jbsr _ExamineFH
	addql #8,sp
	tstw d0
	jne L315
	movel a3,sp@-
	jbsr _recordSyncFailure__17AsyncStreamBuffer
	jbsr _throwStreamSeekError
	addql #4,sp
L315:
	movel d2,a0
	movel a0@(124),d3
	addl d7,d3
	jra L311
	.even
L316:
	jbsr _throwStreamSeekError
L311:
	movel a3@(18),d0
	eorw #1,d0
	movel a3@(30,d0:l:4),a1
	movel a3@(38),d0
	subl a1,d0
	movel d4,d1
	subl d0,d1
	movel a3@(26),a0
	movel d4,d0
	addl a0,d0
	addl d6,d0
	movel d3,d2
	subl d4,d2
	cmpl d3,d1
	jgt L320
	cmpl d3,d0
	jgt L319
L320:
	movel a3@(10),d0
	movel d3,d2
	divsl d0,d2
	mulsl d0,d2
	clrl sp@-
	movel d2,d0
	subl d5,d0
	movel d0,sp@-
	movel a3@(42),sp@-
	jbsr a2@
	addw #12,sp
	tstl d0
	jge L321
	movel a3,sp@-
	jbsr _recordSyncFailure__17AsyncStreamBuffer
	jbsr _throwStreamSeekError
	addql #4,sp
L321:
	movel a3@(30),sp@-
	movel a3,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	subl d2,d3
	movel d3,a3@(22)
	clrl a3@(26)
	clrl a3@(18)
	movel a3@(34),a3@(38)
	jra L326
	.even
L319:
	cmpl d3,d4
	jgt L324
	cmpl d2,a0
	jlt L323
L324:
	movel a3,sp@-
	jbsr _requeuePacket__17AsyncStreamBuffer
	subl d2,a3@(26)
	addl d2,a3@(38)
	addql #4,sp
	jra L322
	.even
L323:
	movel a1,sp@-
	movel a3,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	movel a3@(26),d0
	subl a3@(22),d0
	subl d0,d2
	movel a3@(18),d0
	movel a3@(30,d0:l:4),d1
	addl d2,d1
	movel d1,a3@(38)
	subl d2,d6
	movel d6,a3@(26)
	clrl a3@(22)
	eorw #1,d0
	movel d0,a3@(18)
L326:
	addql #8,sp
L322:
	movel d4,d0
	moveml sp@+,#0xcfc
	addw #268,sp
	rts
	.even
.globl _readBytes__8StreamInPvUl
_readBytes__8StreamInPvUl:
	moveml #0x3c20,sp@-
	movel sp@(24),a2
	movel sp@(28),d4
	movel sp@(32),d3
	tstl a2@(42)
	jne L328
	jbsr _throwStreamReadError
L328:
	clrl d5
	movel a2@(26),d2
	cmpl d3,d2
	jcc L330
	.even
L331:
#APP
	
/*************************************/

	move.l d4, a0
	move.l a2@(38), a1
	move.l d2, d0
	jsr _Mem_copy

/*************************************/


#NO_APP
	subl d2,d3
	addl d2,d4
	addl d2,d5
	clrl a2@(26)
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	movel d0,d2
	addql #4,sp
	jgt L333
	jne L334
	moveq #2,d0
	orl d0,a2@(14)
	clrl sp@-
	jbsr _SetIoErr
	movel d5,d0
	addql #4,sp
	jra L327
	.even
L334:
	jbsr _throwStreamReadError
L333:
	movel a2@(18),d0
	eorw #1,d0
	movel a2@(30,d0:l:4),sp@-
	movel a2,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	addql #8,sp
	cmpl a2@(22),d2
	jcc L335
	movel d2,a2@(22)
L335:
	movel a2@(18),d0
	movel a2@(22),d1
	movel a2@(30,d0:l:4),a0
	addl d1,a0
	movel a0,a2@(38)
	eorw #1,d0
	movel d0,a2@(18)
	movel d2,d0
	subl d1,d0
	movel d0,a2@(26)
	clrl a2@(22)
	movel d0,d2
	cmpl d3,d2
	jcs L331
L330:
	movel a2@(38),d2
#APP
	
/*************************************/

	move.l d4, a0
	move.l d2, a1
	move.l d3, d0
	jsr _Mem_copy

/*************************************/


#NO_APP
	subl d3,a2@(26)
	addl d3,d2
	movel d2,a2@(38)
	movel d5,d0
	addl d3,d0
L327:
	moveml sp@+,#0x43c
	rts
	.even
.globl _read16Swap__8StreamInPvUl
_read16Swap__8StreamInPvUl:
	moveml #0x3e20,sp@-
	movel sp@(28),a2
	movel sp@(32),d5
	movel sp@(36),d4
	tstl a2@(42)
	jne L339
	jbsr _throwStreamReadError
L339:
	movel d5,d0
	orl a2@(38),d0
	btst #0,d0
	jeq L340
	jbsr _throwBadAlignment
L340:
	addl d4,d4
	clrl d6
	movel a2@(26),d3
	cmpl d4,d3
	jcc L342
	.even
L343:
	movel d3,d2
	asrl #1,d2
#APP
	
/*************************************/

	move.l d5, a0
	move.l a2@(38), a1
	move.l d2, d0
	jsr _Mem_swap16

/*************************************/


#NO_APP
	subl d3,d4
	addl d3,d5
	addl d3,d6
	clrl a2@(26)
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	movel d0,d2
	addql #4,sp
	jgt L345
	jne L346
	moveq #2,d0
	orl d0,a2@(14)
	clrl sp@-
	jbsr _SetIoErr
	movel d6,d0
	asrl #1,d0
	addql #4,sp
	jra L338
	.even
L346:
	jbsr _throwStreamReadError
L345:
	movel a2@(18),d0
	eorw #1,d0
	movel a2@(30,d0:l:4),sp@-
	movel a2,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	addql #8,sp
	cmpl a2@(22),d2
	jcc L347
	movel d2,a2@(22)
L347:
	movel a2@(18),d0
	movel a2@(22),d1
	movel a2@(30,d0:l:4),a0
	addl d1,a0
	movel a0,a2@(38)
	eorw #1,d0
	movel d0,a2@(18)
	movel d2,d0
	subl d1,d0
	movel d0,a2@(26)
	clrl a2@(22)
	movel d0,d3
	cmpl d4,d3
	jcs L343
L342:
	movel a2@(38),d2
	movel d4,d3
	lsrl #1,d3
#APP
	
/*************************************/

	move.l d5, a0
	move.l d2, a1
	move.l d3, d0
	jsr _Mem_swap16

/*************************************/


#NO_APP
	subl d4,a2@(26)
	addl d4,d2
	movel d2,a2@(38)
	movel d6,d0
	addl d4,d0
	lsrl #1,d0
L338:
	moveml sp@+,#0x47c
	rts
	.even
.globl _read32Swap__8StreamInPvUl
_read32Swap__8StreamInPvUl:
	moveml #0x3e20,sp@-
	movel sp@(28),a2
	movel sp@(32),d5
	movel sp@(36),d4
	tstl a2@(42)
	jne L351
	jbsr _throwStreamReadError
L351:
	movel d5,d0
	orl a2@(38),d0
	btst #0,d0
	jeq L352
	jbsr _throwBadAlignment
L352:
	lsll #2,d4
	clrl d6
	movel a2@(26),d3
	cmpl d4,d3
	jcc L354
	.even
L355:
	movel d3,d2
	asrl #2,d2
#APP
	
/*************************************/

	move.l d5, a0
	move.l a2@(38), a1
	move.l d2, d0
	jsr _Mem_swap32

/*************************************/


#NO_APP
	subl d3,d4
	addl d3,d5
	addl d3,d6
	clrl a2@(26)
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	movel d0,d2
	addql #4,sp
	jgt L357
	jne L358
	moveq #2,d0
	orl d0,a2@(14)
	clrl sp@-
	jbsr _SetIoErr
	movel d6,d0
	asrl #2,d0
	addql #4,sp
	jra L350
	.even
L358:
	jbsr _throwStreamReadError
L357:
	movel a2@(18),d0
	eorw #1,d0
	movel a2@(30,d0:l:4),sp@-
	movel a2,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	addql #8,sp
	cmpl a2@(22),d2
	jcc L359
	movel d2,a2@(22)
L359:
	movel a2@(18),d0
	movel a2@(22),d1
	movel a2@(30,d0:l:4),a0
	addl d1,a0
	movel a0,a2@(38)
	eorw #1,d0
	movel d0,a2@(18)
	movel d2,d0
	subl d1,d0
	movel d0,a2@(26)
	clrl a2@(22)
	movel d0,d3
	cmpl d4,d3
	jcs L355
L354:
	movel a2@(38),d2
	movel d4,d3
	lsrl #2,d3
#APP
	
/*************************************/

	move.l d5, a0
	move.l d2, a1
	move.l d3, d0
	jsr _Mem_swap32

/*************************************/


#NO_APP
	subl d4,a2@(26)
	addl d4,d2
	movel d2,a2@(38)
	movel d6,d0
	addl d4,d0
	lsrl #2,d0
L350:
	moveml sp@+,#0x47c
	rts
	.even
.globl _read64Swap__8StreamInPvUl
_read64Swap__8StreamInPvUl:
	moveml #0x3e20,sp@-
	movel sp@(28),a2
	movel sp@(32),d5
	movel sp@(36),d4
	tstl a2@(42)
	jne L363
	jbsr _throwStreamReadError
L363:
	movel d5,d0
	orl a2@(38),d0
	btst #0,d0
	jeq L364
	jbsr _throwBadAlignment
L364:
	lsll #3,d4
	clrl d6
	movel a2@(26),d3
	cmpl d4,d3
	jcc L366
	.even
L367:
	movel d3,d2
	asrl #3,d2
#APP
	
/*************************************/

	move.l d5, a0
	move.l a2@(38), a1
	move.l d2, d0
	jsr _Mem_swap64

/*************************************/


#NO_APP
	subl d3,d4
	addl d3,d5
	addl d3,d6
	clrl a2@(26)
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	movel d0,d2
	addql #4,sp
	jgt L369
	jne L370
	moveq #2,d0
	orl d0,a2@(14)
	clrl sp@-
	jbsr _SetIoErr
	movel d6,d0
	asrl #3,d0
	addql #4,sp
	jra L362
	.even
L370:
	jbsr _throwStreamReadError
L369:
	movel a2@(18),d0
	eorw #1,d0
	movel a2@(30,d0:l:4),sp@-
	movel a2,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	addql #8,sp
	cmpl a2@(22),d2
	jcc L371
	movel d2,a2@(22)
L371:
	movel a2@(18),d0
	movel a2@(22),d1
	movel a2@(30,d0:l:4),a0
	addl d1,a0
	movel a0,a2@(38)
	eorw #1,d0
	movel d0,a2@(18)
	movel d2,d0
	subl d1,d0
	movel d0,a2@(26)
	clrl a2@(22)
	movel d0,d3
	cmpl d4,d3
	jcs L367
L366:
	movel a2@(38),d2
	movel d4,d3
	lsrl #3,d3
#APP
	
/*************************************/

	move.l d5, a0
	move.l d2, a1
	move.l d3, d0
	jsr _Mem_swap64

/*************************************/


#NO_APP
	subl d4,a2@(26)
	addl d4,d2
	movel d2,a2@(38)
	movel d6,d0
	addl d4,d0
	lsrl #3,d0
L362:
	moveml sp@+,#0x47c
	rts
	.even
.globl _readText__8StreamInPclcl
_readText__8StreamInPclcl:
	moveml #0x3f30,sp@-
	movel sp@(36),a2
	movel sp@(44),d7
	movel sp@(52),d3
	moveb sp@(51),d6
	tstl a2@(42)
	jne L375
	jbsr _throwStreamReadError
L375:
	movel sp@(40),a3
	movel d7,d2
	clrl d5
	clrl d4
	jra L376
	.even
L382:
	moveb d6,d4
	cmpl d0,d4
	jne L383
	subql #1,d3
L383:
	moveb d0,a3@+
L376:
	subql #1,d2
	jeq L377
	tstl d3
	jeq L377
	movel a2@(26),d0
	jne L380
	movel a2,sp@-
	jbsr _getNextCharIO__8StreamIn
	addql #4,sp
	jra L381
	.even
L380:
	subql #1,d0
	movel d0,a2@(26)
	movel a2@(38),a0
	lea a0@(1),a1
	movel a1,a2@(38)
	moveb a0@,d5
	movel d5,d0
L381:
	moveq #-1,d1
	cmpl d0,d1
	jne L382
L377:
	clrb a3@
	movel d7,d0
	subl d2,d0
	moveml sp@+,#0xcfc
	rts
	.even
.globl _rawWriteBytes__8StreamInPCvUll
_rawWriteBytes__8StreamInPCvUll:
	clrl d0
	rts
	nop
.globl __9StreamOut$loggingClassName
LC9:
	.ascii "StreamOut\0"
.data
	.even
__9StreamOut$loggingClassName:
	.long LC9
.text
	.even
.globl ___9StreamOutPCcbT2Ul
___9StreamOutPCcbT2Ul:
	link a5,#-52
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,d1
	movel a5@(8),a0
	clrl a0@(14)
	clrl a0@(42)
	clrl a0@(30)
	movel d1,a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L393,a5@(-12)
	movel sp,a5@(-8)
	jra L392
	.even
L393:
	jra L405
	.even
L392:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	clrl a0@(152)
	movel a5@(24),sp@-
	subql #2,sp
	moveb a5@(23),sp@(1)
	subql #2,sp
	subql #2,sp
	moveb a5@(19),sp@(1)
	subql #2,sp
	movel a5@(12),sp@-
	movel a0,sp@-
	movel d1,a1
	addql #4,a1
	movel a1,a5@(-52)
	jbsr _open__9StreamOutPCcbT2Ul
	addw #20,sp
	movel a5@(-52),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L404
	.even
L405:
L390:
	movel a5@(-52),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L398,a5@(-36)
	movel sp,a5@(-32)
	jra L397
	.even
L398:
	jra L406
	.even
L397:
	lea a5@(-48),a0
	movel a5@(-52),a1
	movel a0,a1@
	movel a5@(8),sp@-
	jbsr _destroy__17AsyncStreamBuffer
	addql #4,sp
	movel a5@(-52),a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L406:
L395:
	jbsr ___terminate
	.even
L404:
	moveml a5@(-164),#0x5cfc
	fmovem a5@(-124),#0x3f
	unlk a5
	rts
	.even
.globl __$_9StreamOut
__$_9StreamOut:
	movel a2,sp@-
	movel sp@(8),a2
	movel a2,sp@-
	jbsr _close__9StreamOut
	addql #4,sp
	movel a2@(152),d0
	jeq L409
	movel d0,sp@-
	jbsr _free__3MemPv
	addql #4,sp
L409:
	movel a2,sp@-
	jbsr _destroy__17AsyncStreamBuffer
	addql #4,sp
	movel sp@(12),d0
	btst #0,d0
	jeq L413
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L413:
	movel sp@+,a2
	rts
.data
	.even
_loggingFuncName.300:
	.long LC6
.text
	.even
.globl _open__9StreamOutPCcbT2Ul
_open__9StreamOutPCcbT2Ul:
	addw #-44,sp
	moveml #0x3830,sp@-
	movel sp@(68),a2
	movel sp@(72),d4
	jne L415
	jbsr _throwInvalidValue
L415:
	tstl a2@(42)
	jeq L416
	movel a2,sp@-
	jbsr _close__9StreamOut
	addql #4,sp
L416:
	lea _Open,a3
	cmpb #1,sp@(83)
	jne L417
	pea 1004:w
	movel d4,sp@-
	jbsr a3@
	movel d0,a2@(42)
	addql #8,sp
	jeq L417
	moveq #64,d1
	orl d1,a2@(14)
	pea 1:w
	clrl sp@-
	movel d0,sp@-
	lea _Seek,a3
	jbsr a3@
	addw #12,sp
	tstl d0
	jlt L418
	clrl sp@-
	clrl sp@-
	movel a2@(42),sp@-
	jbsr a3@
	movel d0,a2@(6)
	addw #12,sp
	jra L420
	.even
L418:
	movel a2@(42),sp@-
	jbsr _Close
	clrl a2@(6)
	clrl a2@(42)
	addql #4,sp
	jra L420
	.even
L417:
	pea 1006:w
	movel d4,sp@-
	jbsr a3@
	movel d0,a2@(42)
	addql #8,sp
	jeq L420
	clrl a2@(6)
	moveq #32,d0
	orl d0,a2@(14)
L420:
	movel a2@(42),d0
	jeq L422
	movel #512,a2@(10)
	movel d0,sp@-
	jbsr _ParentOfFH
	movel d0,d3
	addql #4,sp
	jeq L423
	moveq #23,d2
	addl sp,d2
	moveq #-4,d1
	andl d1,d2
	movel d2,sp@-
	movel d3,sp@-
	jbsr _Info
	addql #8,sp
	tstl d0
	jeq L424
	movel d2,a0
	movel a0@(20),a2@(10)
L424:
	movel d3,sp@-
	jbsr _UnLock
	addql #4,sp
L423:
	movel a2@(10),d2
	movel d2,d1
	addl d1,d1
	movel sp@(84),a0
	lea a0@(-1,d1:l),a0
	movel a0,d0
	divul d1,d0
	addl d0,d0
	mulsl d2,d0
	movel d0,sp@-
	movel a2,sp@-
	jbsr _create__17AsyncStreamBufferUl
	addql #8,sp
	tstb d0
	jeq L425
	moveq #87,d0
	movel d0,a2@(78)
	movel a2@(2),a2@(26)
	moveq #8,d1
	orl d1,a2@(14)
	jra L414
	.even
L425:
	andw #65287,a2@(16)
	movel a2@(42),sp@-
	jbsr _Close
	clrl a2@(42)
	addql #4,sp
L422:
	movel d4,sp@-
	movel _loggingFuncName.300,sp@-
	movel __9StreamOut$loggingClassName,sp@-
	pea LC8
	pea 2:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	jbsr _throwStreamOpenError
	addw #20,sp
L414:
	moveml sp@+,#0xc1c
	addw #44,sp
	rts
	.even
.globl _close__9StreamOut
_close__9StreamOut:
	movel a2,sp@-
	movel sp@(8),a2
	movel a2,sp@-
	jbsr _flush__9StreamOut
	addql #4,sp
	movel a2@(42),d0
	jeq L428
	movel d0,sp@-
	jbsr _Close
	clrl a2@(42)
	movel a2,sp@-
	jbsr _destroy__17AsyncStreamBuffer
	addql #8,sp
L428:
	andw #65287,a2@(16)
	movel sp@+,a2
	rts
	.even
.globl _flush__9StreamOut
_flush__9StreamOut:
	movel a2,sp@-
	movel sp@(8),a2
	tstl a2@(42)
	jeq L430
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	addql #4,sp
	tstl d0
	jlt L430
	movel a2@(2),d1
	movel a2@(26),d0
	cmpl d1,d0
	jge L430
	subl d0,d1
	movel d1,sp@-
	movel a2@(18),d0
	movel a2@(30,d0:l:4),sp@-
	movel a2@(42),sp@-
	jbsr _Write
	addw #12,sp
	tstl d0
	jge L430
	jbsr _throwStreamWriteError
L430:
	movel sp@+,a2
	rts
	.even
.globl _tell__9StreamOut
_tell__9StreamOut:
	movel a2,sp@-
	movel sp@(8),a2
	tstl a2@(42)
	jne L434
	jbsr _throwStreamSeekError
L434:
	pea 1:w
	clrl sp@-
	movel a2,sp@-
	jbsr _seek__9StreamOutlQ22IO8SeekMode
	addw #12,sp
	movel sp@+,a2
	rts
	.even
.globl _seek__9StreamOutlQ22IO8SeekMode
_seek__9StreamOutlQ22IO8SeekMode:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	tstl a2@(42)
	jne L436
	jbsr _throwStreamSeekError
L436:
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	addql #4,sp
	tstl d0
	jge L437
	jbsr _throwStreamSeekError
L437:
	movel a2@(2),d1
	movel a2@(26),d0
	cmpl d1,d0
	jge L438
	subl d0,d1
	movel d1,sp@-
	movel a2@(18),d0
	movel a2@(30,d0:l:4),sp@-
	movel a2@(42),sp@-
	jbsr _Write
	addw #12,sp
	tstl d0
	jge L438
	movel a2,sp@-
	jbsr _recordSyncFailure__17AsyncStreamBuffer
	jbsr _throwStreamSeekError
	addql #4,sp
L438:
	movel sp@(20),sp@-
	movel sp@(20),sp@-
	movel a2@(42),sp@-
	jbsr _Seek
	movel d0,d2
	addw #12,sp
	jge L440
	movel a2,sp@-
	jbsr _recordSyncFailure__17AsyncStreamBuffer
	jbsr _throwStreamSeekError
	addql #4,sp
L440:
	movel a2@(2),a2@(26)
	clrl a2@(18)
	movel a2@(30),a2@(38)
	movel d2,d0
	movel sp@+,d2
	movel sp@+,a2
	rts
	.even
.globl _writeBytes__9StreamOutPCvUl
_writeBytes__9StreamOutPCvUl:
	moveml #0x3c20,sp@-
	movel sp@(24),a2
	movel sp@(28),d4
	movel sp@(32),d3
	tstl a2@(42)
	jne L442
	jbsr _throwStreamWriteError
L442:
	clrl d5
	cmpl a2@(26),d3
	jls L444
	.even
L445:
	tstl a2@(46)
	jne L446
	movel a2@(30),a2@(38)
	movel a2@(2),a2@(26)
	movel d3,d0
	jra L452
	.even
L446:
	movel a2@(26),d2
	jeq L447
#APP
	
/*************************************/

	move.l a2@(38), a0
	move.l d4, a1
	move.l d2, d0
	jsr _Mem_copy

/*************************************/


#NO_APP
	subl d2,d3
	addl d2,d4
	addl d2,d5
L447:
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	addql #4,sp
	tstl d0
	jge L449
	jbsr _throwStreamWriteError
L449:
	movel a2@(18),d0
	movel a2@(30,d0:l:4),sp@-
	movel a2,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	movel a2@(18),d0
	eorw #1,d0
	movel d0,a2@(18)
	movel a2@(30,d0:l:4),a2@(38)
	movel a2@(2),a2@(26)
	addql #8,sp
	cmpl a2@(2),d3
	jhi L445
L444:
	movel a2@(38),d2
#APP
	
/*************************************/

	move.l d2, a0
	move.l d4, a1
	move.l d3, d0
	jsr _Mem_copy

/*************************************/


#NO_APP
	subl d3,a2@(26)
	addl d3,d2
	movel d2,a2@(38)
	movel d5,d0
	addl d3,d0
L452:
	moveml sp@+,#0x43c
	rts
	.even
.globl _write16Swap__9StreamOutPCvUl
_write16Swap__9StreamOutPCvUl:
	moveml #0x3e20,sp@-
	movel sp@(28),a2
	movel sp@(32),d5
	movel sp@(36),d4
	tstl a2@(42)
	jne L455
	jbsr _throwStreamWriteError
L455:
	movel d5,d0
	orl a2@(38),d0
	btst #0,d0
	jeq L456
	jbsr _throwBadAlignment
L456:
	addl d4,d4
	clrl d6
	cmpl a2@(26),d4
	jls L458
	.even
L459:
	tstl a2@(46)
	jne L460
	movel a2@(30),a2@(38)
	movel a2@(2),a2@(26)
	movel d4,d0
	jra L466
	.even
L460:
	movel a2@(26),d3
	jeq L461
	movel d3,d2
	asrl #1,d2
#APP
	
/*************************************/

	move.l a2@(38), a0
	move.l d5, a1
	move.l d2, d0
	jsr _Mem_swap16

/*************************************/


#NO_APP
	subl d3,d4
	addl d3,d5
	addl d3,d6
L461:
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	addql #4,sp
	tstl d0
	jge L463
	jbsr _throwStreamWriteError
L463:
	movel a2@(18),d0
	movel a2@(30,d0:l:4),sp@-
	movel a2,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	movel a2@(18),d0
	eorw #1,d0
	movel d0,a2@(18)
	movel a2@(30,d0:l:4),a2@(38)
	movel a2@(2),a2@(26)
	addql #8,sp
	cmpl a2@(2),d4
	jhi L459
L458:
	movel a2@(38),d2
	movel d4,d3
	lsrl #1,d3
#APP
	
/*************************************/

	move.l d2, a0
	move.l d5, a1
	move.l d3, d0
	jsr _Mem_swap16

/*************************************/


#NO_APP
	subl d4,a2@(26)
	addl d4,d2
	movel d2,a2@(38)
	movel d6,d0
	addl d4,d0
	lsrl #1,d0
L466:
	moveml sp@+,#0x47c
	rts
	.even
.globl _write32Swap__9StreamOutPCvUl
_write32Swap__9StreamOutPCvUl:
	moveml #0x3e20,sp@-
	movel sp@(28),a2
	movel sp@(32),d5
	movel sp@(36),d4
	tstl a2@(42)
	jne L469
	jbsr _throwStreamWriteError
L469:
	movel d5,d0
	orl a2@(38),d0
	btst #0,d0
	jeq L470
	jbsr _throwBadAlignment
L470:
	lsll #2,d4
	clrl d6
	cmpl a2@(26),d4
	jls L472
	.even
L473:
	tstl a2@(46)
	jne L474
	movel a2@(30),a2@(38)
	movel a2@(2),a2@(26)
	movel d4,d0
	jra L480
	.even
L474:
	movel a2@(26),d3
	jeq L475
	movel d3,d2
	asrl #2,d2
#APP
	
/*************************************/

	move.l a2@(38), a0
	move.l d5, a1
	move.l d2, d0
	jsr _Mem_swap32

/*************************************/


#NO_APP
	subl d3,d4
	addl d3,d5
	addl d3,d6
L475:
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	addql #4,sp
	tstl d0
	jge L477
	jbsr _throwStreamWriteError
L477:
	movel a2@(18),d0
	movel a2@(30,d0:l:4),sp@-
	movel a2,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	movel a2@(18),d0
	eorw #1,d0
	movel d0,a2@(18)
	movel a2@(30,d0:l:4),a2@(38)
	movel a2@(2),a2@(26)
	addql #8,sp
	cmpl a2@(2),d4
	jhi L473
L472:
	movel a2@(38),d2
	movel d4,d3
	lsrl #2,d3
#APP
	
/*************************************/

	move.l d2, a0
	move.l d5, a1
	move.l d3, d0
	jsr _Mem_swap32

/*************************************/


#NO_APP
	subl d4,a2@(26)
	addl d4,d2
	movel d2,a2@(38)
	movel d6,d0
	addl d4,d0
	lsrl #2,d0
L480:
	moveml sp@+,#0x47c
	rts
	.even
.globl _write64Swap__9StreamOutPCvUl
_write64Swap__9StreamOutPCvUl:
	moveml #0x3e20,sp@-
	movel sp@(28),a2
	movel sp@(32),d5
	movel sp@(36),d4
	tstl a2@(42)
	jne L483
	jbsr _throwStreamWriteError
L483:
	movel d5,d0
	orl a2@(38),d0
	btst #0,d0
	jeq L484
	jbsr _throwBadAlignment
L484:
	lsll #3,d4
	clrl d6
	cmpl a2@(26),d4
	jls L486
	.even
L487:
	tstl a2@(46)
	jne L488
	movel a2@(30),a2@(38)
	movel a2@(2),a2@(26)
	movel d4,d0
	jra L494
	.even
L488:
	movel a2@(26),d3
	jeq L489
	movel d3,d2
	asrl #3,d2
#APP
	
/*************************************/

	move.l a2@(38), a0
	move.l d5, a1
	move.l d2, d0
	jsr _Mem_swap64

/*************************************/


#NO_APP
	subl d3,d4
	addl d3,d5
	addl d3,d6
L489:
	movel a2,sp@-
	jbsr _waitPacket__17AsyncStreamBuffer
	addql #4,sp
	tstl d0
	jge L491
	jbsr _throwStreamWriteError
L491:
	movel a2@(18),d0
	movel a2@(30,d0:l:4),sp@-
	movel a2,sp@-
	jbsr _sendPacket__17AsyncStreamBufferPv
	movel a2@(18),d0
	eorw #1,d0
	movel d0,a2@(18)
	movel a2@(30,d0:l:4),a2@(38)
	movel a2@(2),a2@(26)
	addql #8,sp
	cmpl a2@(2),d4
	jhi L487
L486:
	movel a2@(38),d2
	movel d4,d3
	lsrl #3,d3
#APP
	
/*************************************/

	move.l d2, a0
	move.l d5, a1
	move.l d3, d0
	jsr _Mem_swap64

/*************************************/


#NO_APP
	subl d4,a2@(26)
	addl d4,d2
	movel d2,a2@(38)
	movel d6,d0
	addl d4,d0
	lsrl #3,d0
L494:
	moveml sp@+,#0x47c
	rts
	.even
.globl _writeText__9StreamOutPCce
_writeText__9StreamOutPCce:
	pea a5@
	movel sp,a5
	movel a2,sp@-
	movel a5@(8),a2
	tstl a2@(42)
	jne L497
	jbsr _throwStreamWriteError
L497:
	tstl a2@(152)
	jne L498
	clrl sp@-
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	pea 2048:w
	jbsr _alloc__3MemUlbQ23Mem9AlignType
	movel d0,a2@(152)
	addw #12,sp
	jne L498
	jbsr _throwStreamWriteError
L498:
	pea a5@(16)
	movel a5@(12),sp@-
	movel a2@(152),sp@-
	jbsr _vsprintf
	movel d0,sp@-
	movel a2@(152),sp@-
	movel a2,sp@-
	jbsr _writeBytes__9StreamOutPCvUl
	addw #24,sp
	movel a5@(-4),a2
	unlk a5
	rts
	.even
.globl _rawReadBytes__9StreamOutPvUll
_rawReadBytes__9StreamOutPvUll:
	moveml #0x3c30,sp@-
	movel sp@(28),a3
	movel sp@(32),d5
	movel sp@(36),d3
	movel sp@(40),d2
	clrl sp@-
	clrl sp@-
	movel a3@(42),sp@-
	lea _Seek,a2
	jbsr a2@
	movel d0,d4
	pea -1:w
	movel d2,sp@-
	movel a3@(42),sp@-
	jbsr a2@
	movel d3,sp@-
	movel d5,sp@-
	movel a3@(42),sp@-
	jbsr _Read
	movel d0,d2
	addw #32,sp
	movel #-1,sp@
	movel d4,sp@-
	movel a3@(42),sp@-
	jbsr a2@
	addw #12,sp
	tstl d2
	jge L501
	jbsr _throwStreamReadError
L501:
	movel d2,d0
	moveml sp@+,#0xc3c
	rts
