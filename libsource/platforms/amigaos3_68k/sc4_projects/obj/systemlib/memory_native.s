#NO_APP
.globl __3Mem$puddleSize
.data
	.even
__3Mem$puddleSize:
	.long 4096
.globl __3Mem$threshSize
	.even
__3Mem$threshSize:
	.long 0
.globl __3Mem$memIdentifier
	.even
__3Mem$memIdentifier:
	.long 1481788737
.globl __3Mem$numAlloc
	.even
__3Mem$numAlloc:
	.long 0
.globl __3Mem$peakAlloc
	.even
__3Mem$peakAlloc:
	.long 0
.globl __3Mem$totSize
	.even
__3Mem$totSize:
	.long 0
.globl __3Mem$peakSize
	.even
__3Mem$peakSize:
	.long 0
.globl __3Mem$totRequested
	.even
__3Mem$totRequested:
	.long 0
.globl __3Mem$peakRequested
	.even
__3Mem$peakRequested:
	.long 0
.globl __3Mem$head
	.even
__3Mem$head:
	.long 0
.globl __3Mem$memPool
	.even
__3Mem$memPool:
	.long 0
.globl __3Mem$poolSemaphore
	.even
__3Mem$poolSemaphore:
	.long 0
.globl __3Mem$loggingClassName
.text
LC0:
	.ascii "Mem\0"
.data
	.even
__3Mem$loggingClassName:
	.long LC0
.text
LC1:
	.ascii "init()\0"
.data
	.even
_loggingFuncName.132:
	.long LC1
.text
LC2:
	.ascii "-amigapuddlesize\0"
LC3:
	.ascii "memory [semaphore]\0"
LC4:
	.ascii "memory [pool]\0"
LC5:
	.ascii "%s::%s - OK [puddle: %d, threshold %d]\12\0"
	.even
.globl _init__3Mem
_init__3Mem:
	clrl sp@-
	movel __3Mem$puddleSize,sp@-
	pea LC2
	jbsr _getArgInteger__7StartupPCclUs
	addw #12,sp
	movel d0,__3Mem$puddleSize
	addl #-2048,d0
	cmpl #63488,d0
	jls L120
	jbsr _throwRangeError
L120:
	moveq #-64,d0
	addl __3Mem$puddleSize,d0
	movel d0,__3Mem$threshSize
	pea 1:w
	pea 46:w
	jbsr _AllocMem
	movel d0,__3Mem$poolSemaphore
	addql #8,sp
	jne L121
	pea LC3
	jbsr _throwResourceExhausted
	addql #4,sp
L121:
	movel __3Mem$threshSize,sp@-
	movel __3Mem$puddleSize,sp@-
	pea 1:w
	jbsr _CreatePool
	movel d0,__3Mem$memPool
	addw #12,sp
	jne L122
	pea LC4
	jbsr _throwResourceExhausted
	addql #4,sp
L122:
	movel __3Mem$poolSemaphore,sp@-
	jbsr _InitSemaphore
	movel __3Mem$threshSize,sp@-
	movel __3Mem$puddleSize,sp@-
	movel _loggingFuncName.132,sp@-
	movel __3Mem$loggingClassName,sp@-
	pea LC5
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #28,sp
	rts
	nop
LC6:
	.ascii "done()\0"
.data
	.even
_loggingFuncName.136:
	.long LC6
.text
LC7:
	.ascii "%s::%s - %lu unfreed chunks, totalling %lu bytes\12\0"
LC8:
	.ascii "%s::%s - OK\12\0"
	.even
.globl _done__3Mem
_done__3Mem:
	movel a2,sp@-
	lea _write__9SystemLogQ29SystemLog5LevelPCce,a2
	tstl __3Mem$memPool
	jeq L124
	movel __3Mem$numAlloc,d0
	jeq L125
	movel __3Mem$totSize,sp@-
	movel d0,sp@-
	movel _loggingFuncName.136,sp@-
	movel __3Mem$loggingClassName,sp@-
	pea LC7
	pea 2:w
	jbsr a2@
	jbsr _debug__3Mem
	addw #24,sp
L125:
	movel __3Mem$memPool,sp@-
	jbsr _DeletePool
	clrl __3Mem$memPool
	addql #4,sp
L124:
	movel __3Mem$poolSemaphore,d0
	jeq L126
	pea 46:w
	movel d0,sp@-
	jbsr _FreeMem
	clrl __3Mem$poolSemaphore
	addql #8,sp
L126:
	movel _loggingFuncName.136,sp@-
	movel __3Mem$loggingClassName,sp@-
	pea LC8
	pea 3:w
	jbsr a2@
	addw #16,sp
	movel sp@+,a2
	rts
LC9:
	.ascii "alloc()\0"
.data
	.even
_loggingFuncName.140:
	.long LC9
.text
LC10:
	.ascii "%s::%s - requested %lu bytes, allocated %lu at 0x%08X, info at 0x%08X\12\0"
LC11:
	.ascii "memory [alloc]\0"
	.even
.globl _alloc__3MemUlbQ23Mem9AlignType
_alloc__3MemUlbQ23Mem9AlignType:
	moveml #0x3800,sp@-
	movel sp@(16),d3
	moveq #64,d2
	addl d3,d2
	movel __3Mem$poolSemaphore,sp@-
	jbsr _ObtainSemaphore
	movel d2,sp@-
	movel __3Mem$memPool,sp@-
	jbsr _AllocPooled
	movel d0,d1
	clrl d4
	addw #12,sp
	tstl d1
	jeq L128
	movel d1,a1
	lea a1@(15),a0
	movel a0,d0
	moveq #-16,d4
	andl d4,d0
	movel d0,a0
	movel __3Mem$memIdentifier,a0@
	clrl a0@(4)
	movel d2,a0@(8)
	movel d3,a0@(12)
	movel d1,a0@(24)
	moveq #32,d4
	addl a0,d4
	movel __3Mem$numAlloc,d0
	movel d0,a1
	addql #1,a1
	movel a1,__3Mem$numAlloc
	addql #1,d0
	cmpl __3Mem$peakAlloc,d0
	jls L129
	movel d0,__3Mem$peakAlloc
L129:
	movel __3Mem$totSize,d0
	addl d2,d0
	movel d0,__3Mem$totSize
	cmpl __3Mem$peakSize,d0
	jls L130
	movel d0,__3Mem$peakSize
L130:
	movel __3Mem$totRequested,d0
	addl d3,d0
	movel d0,__3Mem$totRequested
	cmpl __3Mem$peakRequested,d0
	jls L131
	movel d0,__3Mem$peakRequested
L131:
	movel __3Mem$head,a1
	tstl a1
	jne L132
	clrl a0@(16)
	clrl a0@(20)
	jra L138
	.even
L132:
	movel a1,a0@(20)
	clrl a0@(16)
	movel a0,a1@(16)
L138:
	movel a0,__3Mem$head
	movel a0,sp@-
	movel d1,sp@-
	movel d2,sp@-
	movel d3,sp@-
	movel _loggingFuncName.140,sp@-
	movel __3Mem$loggingClassName,sp@-
	pea LC10
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #32,sp
L128:
	movel __3Mem$poolSemaphore,sp@-
	jbsr _ReleaseSemaphore
	addql #4,sp
	tstl d4
	jeq L134
	tstb sp@(23)
	jeq L137
#APP
	
/*************************************/

	move.l d4, a0
	move.l d3, d0
	jsr _Mem_zero

/*************************************/


#NO_APP
	jra L137
	.even
L134:
	pea LC11
	jbsr _throwResourceExhausted
	addql #4,sp
L137:
	movel d4,d0
	moveml sp@+,#0x1c
	rts
LC12:
	.ascii "free()\0"
.data
	.even
_loggingFuncName.144:
	.long LC12
.text
LC13:
	.ascii "%s::%s - freed %lu [%lu] bytes, allocated at 0x%08X\12\0"
LC14:
	.ascii "%s::%s - attempt to free unknown allocation at 0x%08X\12\0"
	.even
.globl _free__3MemPv
_free__3MemPv:
	moveml #0x3820,sp@-
	movel sp@(20),d0
	jeq L139
	tstl __3Mem$memPool
	jeq L139
	movel d0,a0
	lea a0@(-32),a2
	movel a2@,d1
	cmpl __3Mem$memIdentifier,d1
	jne L142
	movel __3Mem$poolSemaphore,sp@-
	jbsr _ObtainSemaphore
	clrl a2@
	movel a2@(24),d3
	movel a2@(8),d4
	movel a2@(12),d2
	addql #4,sp
	cmpl __3Mem$head,a2
	jne L143
	movel a2@(20),a0
	tstl a0
	jeq L144
	movel a0,__3Mem$head
	clrl a0@(16)
	jra L146
	.even
L144:
	clrl __3Mem$head
	jra L146
	.even
L143:
	movel a2@(20),a0
	tstl a0
	jeq L147
	movel a2@(16),a0@(16)
L147:
	movel a2@(16),a0
	tstl a0
	jeq L146
	movel a2@(20),a0@(20)
L146:
	movel a2@(8),d0
	subl d0,__3Mem$totSize
	movel a2@(12),d1
	subl d1,__3Mem$totRequested
	movel d0,sp@-
	movel a2@(24),sp@-
	movel __3Mem$memPool,sp@-
	jbsr _FreePooled
	movel __3Mem$poolSemaphore,sp@-
	jbsr _ReleaseSemaphore
	subql #1,__3Mem$numAlloc
	movel d3,sp@-
	movel d2,sp@-
	movel d4,sp@-
	movel _loggingFuncName.144,sp@-
	movel __3Mem$loggingClassName,sp@-
	pea LC13
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #44,sp
	jra L139
	.even
L142:
	movel d0,sp@-
	movel _loggingFuncName.144,sp@-
	movel __3Mem$loggingClassName,sp@-
	pea LC14
	pea 2:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #20,sp
L139:
	moveml sp@+,#0x41c
	rts
LC15:
	.ascii "Mem::debug() - chunk list, %lu chunks totalling %lu bytes\12\0"
LC16:
	.ascii "%lu [%lu] bytes allocated at 0x%08X\12\0"
	.even
.globl _debug__3Mem
_debug__3Mem:
	movel a3,sp@-
	movel a2,sp@-
	movel __9SystemLog$logSemaphore,sp@-
	jbsr _ObtainSemaphore
	movel __3Mem$poolSemaphore,sp@
	jbsr _ObtainSemaphore
	movel __3Mem$totSize,sp@-
	movel __3Mem$numAlloc,sp@-
	pea LC15
	pea 3:w
	lea _printf__9SystemLogQ29SystemLog5LevelPCce,a2
	jbsr a2@
	movel __3Mem$head,a3
	addw #20,sp
	tstl a3
	jeq L153
	.even
L155:
	movel a3@(24),sp@-
	movel a3@(12),sp@-
	movel a3@(8),sp@-
	pea LC16
	pea 3:w
	jbsr a2@
	addw #20,sp
	movel a3@(20),a3
	tstl a3
	jne L155
L153:
	movel __3Mem$poolSemaphore,sp@-
	jbsr _ReleaseSemaphore
	movel __9SystemLog$logFile,sp@
	jbsr _fflush
	movel __9SystemLog$logSemaphore,sp@-
	jbsr _ReleaseSemaphore
	addql #8,sp
	movel sp@+,a2
	movel sp@+,a3
	rts
