#NO_APP
.text
	.even
.globl ___8Lockable
___8Lockable:
	movel a2,sp@-
	movel sp@(8),a2
	movel #___vt_8Lockable,a2@(48)
	clrb a2@(46)
	movel a2,sp@-
	jbsr _InitSemaphore
	addql #4,sp
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl __$_8Lockable
__$_8Lockable:
	moveml #0x38,sp@-
	movel sp@(16),a4
	movel #___vt_8Lockable,a4@(48)
	tstb a4@(46)
	jne L204
	movel a4,sp@-
	lea _ObtainSemaphore,a3
	jbsr a3@
	moveb #1,a4@(46)
	movel a4,sp@-
	lea _ReleaseSemaphore,a2
	jbsr a2@
	movel a4,sp@-
	jbsr a3@
	movel a4,sp@-
	jbsr a2@
	addw #16,sp
L204:
	movel sp@(20),d0
	btst #0,d0
	jeq L206
	movel a4,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L206:
	moveml sp@+,#0x1c00
	rts
	.even
.globl _tryLock__8Lockable
_tryLock__8Lockable:
	movel a2,sp@-
	movel sp@(8),a2
	tstb a2@(46)
	jeq L208
	jbsr _throwObjectDestroyed
L208:
	movel a2,sp@-
	jbsr _AttemptSemaphore
	addql #4,sp
	tstl d0
	jeq L209
	tstb a2@(46)
	jeq L210
	movel a2,sp@-
	jbsr _ReleaseSemaphore
	jbsr _throwObjectDestroyed
	addql #4,sp
L210:
	moveq #1,d0
	jra L211
	.even
L209:
	clrb d0
L211:
	movel sp@+,a2
	rts
	.even
.globl _waitLock__8Lockable
_waitLock__8Lockable:
	movel a2,sp@-
	movel sp@(8),a2
	tstb a2@(46)
	jeq L213
	jbsr _throwObjectDestroyed
L213:
	movel a2,sp@-
	jbsr _ObtainSemaphore
	addql #4,sp
	tstb a2@(46)
	jeq L214
	movel a2,sp@-
	jbsr _ReleaseSemaphore
	jbsr _throwObjectDestroyed
	addql #4,sp
L214:
	movel sp@+,a2
	rts
	.even
.globl _tryReadOnlyLock__8Lockable
_tryReadOnlyLock__8Lockable:
	movel a2,sp@-
	movel sp@(8),a2
	tstb a2@(46)
	jeq L216
	jbsr _throwObjectDestroyed
L216:
	movel a2,sp@-
	jbsr _AttemptSemaphoreShared
	addql #4,sp
	tstl d0
	jeq L217
	tstb a2@(46)
	jeq L218
	movel a2,sp@-
	jbsr _ReleaseSemaphore
	jbsr _throwObjectDestroyed
	addql #4,sp
L218:
	moveq #1,d0
	jra L219
	.even
L217:
	clrb d0
L219:
	movel sp@+,a2
	rts
	.even
.globl _waitReadOnlyLock__8Lockable
_waitReadOnlyLock__8Lockable:
	movel a2,sp@-
	movel sp@(8),a2
	tstb a2@(46)
	jeq L221
	jbsr _throwObjectDestroyed
L221:
	movel a2,sp@-
	jbsr _ObtainSemaphoreShared
	addql #4,sp
	tstb a2@(46)
	jeq L222
	movel a2,sp@-
	jbsr _ReleaseSemaphore
	jbsr _throwObjectDestroyed
	addql #4,sp
L222:
	movel sp@+,a2
	rts
	.even
.globl _pending__8Lockable
_pending__8Lockable:
	movel a2,sp@-
	movel sp@(8),a2
	tstb a2@(46)
	jeq L224
	jbsr _throwObjectDestroyed
L224:
	movew a2@(14),a0
	subw a2@(44),a0
	movel a0,d0
	subql #1,d0
	movel sp@+,a2
	rts
	.even
.globl _freeLock__8Lockable
_freeLock__8Lockable:
	movel sp@(4),a0
	tstb a0@(46)
	jne L226
	movel a0,sp@-
	jbsr _ReleaseSemaphore
	addql #4,sp
L226:
	rts
	nop
	.even
.globl _active__8Lockable
_active__8Lockable:
	movel a2,sp@-
	movel sp@(8),a2
	tstb a2@(46)
	jeq L228
	jbsr _throwObjectDestroyed
L228:
	movew a2@(14),d0
	extl d0
	movel sp@+,a2
	rts
	.even
.globl _getExclusiveOwner__8Lockable
_getExclusiveOwner__8Lockable:
	movel a2,sp@-
	movel sp@(8),a2
	tstb a2@(46)
	jeq L230
	jbsr _throwObjectDestroyed
L230:
	movel a2@(40),d0
	jeq L231
	movel d0,sp@-
	jbsr _threadForTask__6ThreadPQ28OSNative4Task
	addql #4,sp
	jra L229
	.even
L231:
	clrl d0
L229:
	movel sp@+,a2
	rts
