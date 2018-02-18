#NO_APP
.globl __Q26Thread7Sleeper$loggingClassName
.text
LC0:
	.ascii "Thread::Sleeper\0"
.data
	.even
__Q26Thread7Sleeper$loggingClassName:
	.long LC0
.text
	.even
.globl ___Q26Thread7Sleeper
___Q26Thread7Sleeper:
	movel sp@(4),a0
	clrl a0@
	clrl a0@(8)
	clrl a0@(12)
	clrl a0@(16)
	clrl a0@(4)
	movel a0,d0
	rts
	nop
LC1:
	.ascii "init()\0"
.data
	.even
_loggingFuncName.255:
	.long LC1
.text
LC2:
	.ascii "%s::%s - failed to create MsgPort\12\0"
LC3:
	.ascii "%s::%s - failed to create IORequest\12\0"
LC4:
	.ascii "timer.device\0"
LC5:
	.ascii "%s::%s - failed to open %s\12\0"
	.even
.globl _init__Q26Thread7Sleeper
_init__Q26Thread7Sleeper:
	movel a2,sp@-
	movel sp@(8),a2
	jbsr _CreateMsgPort
	movel d0,a0
	movel a0,a2@
	jne L205
	moveq #1,d0
	orl d0,a2@(16)
	movel _loggingFuncName.255,sp@-
	movel __Q26Thread7Sleeper$loggingClassName,sp@-
	pea LC2
	jra L208
	.even
L205:
	clrl d1
	moveb a0@(15),d1
	moveq #1,d0
	lsll d1,d0
	movel d0,a2@(8)
	pea 40:w
	movel a0,sp@-
	jbsr _CreateExtIO
	movel d0,a2@(4)
	addql #8,sp
	jne L206
	moveq #2,d0
	orl d0,a2@(16)
	movel _loggingFuncName.255,sp@-
	movel __Q26Thread7Sleeper$loggingClassName,sp@-
	pea LC3
L208:
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	clrb d0
	addw #16,sp
	jra L204
	.even
L206:
	clrl sp@-
	movel d0,sp@-
	clrl sp@-
	pea LC4
	jbsr _OpenDevice
	addw #16,sp
	tstb d0
	jeq L207
	moveq #4,d0
	orl d0,a2@(16)
	pea LC4
	movel _loggingFuncName.255,sp@-
	movel __Q26Thread7Sleeper$loggingClassName,sp@-
	pea LC5
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	clrb d0
	addw #20,sp
	jra L204
	.even
L207:
	moveq #1,d0
L204:
	movel sp@+,a2
	rts
	.even
.globl _done__Q26Thread7Sleeper
_done__Q26Thread7Sleeper:
	movel a2,sp@-
	movel sp@(8),a2
	movel a2@(4),d0
	jeq L210
	btst #3,a2@(19)
	jeq L211
	movel d0,sp@-
	jbsr _AbortIO
	movel a2@(4),sp@-
	jbsr _WaitIO
	movel a2@(8),sp@-
	clrl sp@-
	jbsr _SetSignal
	addw #16,sp
L211:
	movel a2@(4),sp@-
	jbsr _CloseDevice
	movel a2@(4),sp@-
	jbsr _DeleteExtIO
	addql #8,sp
L210:
	movel a2@,d0
	jeq L212
	movel d0,sp@-
	jbsr _DeleteMsgPort
	addql #4,sp
L212:
	clrl a2@
	clrl a2@(4)
	clrl a2@(8)
	clrl a2@(16)
	movel sp@+,a2
	rts
	.even
.globl _abortDelay__Q26Thread7Sleeper
_abortDelay__Q26Thread7Sleeper:
	movel a2,sp@-
	movel sp@(8),a2
	movel a2@(4),d0
	jeq L214
	btst #3,a2@(19)
	jeq L214
	movel d0,sp@-
	jbsr _AbortIO
	movel a2@(4),sp@-
	jbsr _WaitIO
	movel a2@(8),sp@-
	clrl sp@-
	jbsr _SetSignal
	moveq #-9,d0
	andl d0,a2@(16)
	addw #16,sp
L214:
	movel sp@+,a2
	rts
	.even
.globl _suspend__Q26Thread7SleeperUlUl
_suspend__Q26Thread7SleeperUlUl:
	moveml #0x3020,sp@-
	movel sp@(16),a2
	movel sp@(20),d2
	movel sp@(24),d3
	movel d3,a2@(12)
	movel d2,d0
	orl d3,d0
	jne L216
	clrl d0
	jra L215
	.even
L216:
	movel a2,sp@-
	jbsr _abortDelay__Q26Thread7Sleeper
	addql #4,sp
	tstl d2
	jeq L217
	movel a2@(4),a0
	movew #9,a0@(28)
	movel a2@(4),a0
	divull #1000,d0:d2
	movel d2,a0@(32)
	movel a2@(4),a0
	mulsl #1000,d0
	movel d0,a0@(36)
	movel a2@(4),sp@-
	jbsr _SendIO
	moveq #8,d0
	orl a2@(16),d0
	moveq #-17,d1
	andl d0,d1
	movel d1,a2@(16)
	addql #4,sp
	jra L218
	.even
L217:
	moveq #16,d0
	orl d0,a2@(16)
L218:
	orl a2@(8),d3
	movel d3,sp@-
	jbsr _Wait
	addql #4,sp
L215:
	moveml sp@+,#0x40c
	rts
	.even
.globl _suspend__Q26Thread7Sleeper
_suspend__Q26Thread7Sleeper:
	movel a2,sp@-
	movel sp@(8),a2
	tstl a2@(12)
	jeq L221
	movel a2@(4),d0
	jeq L221
	btst #3,a2@(19)
	jeq L221
	movel d0,sp@-
	jbsr _CheckIO
	addql #4,sp
	tstl d0
	jne L223
	movel a2@(12),d0
	orl a2@(8),d0
	movel d0,sp@-
	jbsr _Wait
	addql #4,sp
	jra L220
	.even
L223:
	movel a2@(8),d0
	jra L220
	.even
L221:
	clrl d0
L220:
	movel sp@+,a2
	rts
