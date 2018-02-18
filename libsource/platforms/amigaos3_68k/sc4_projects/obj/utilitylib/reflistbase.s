#NO_APP
.globl __Q211EXNGPrivate8VoidList$linkCache
.data
	.even
__Q211EXNGPrivate8VoidList$linkCache:
	.long 0
.globl __Q211EXNGPrivate8VoidList$linkCacheSize
	.even
__Q211EXNGPrivate8VoidList$linkCacheSize:
	.long 0
.globl __Q211EXNGPrivate8VoidList$linkCacheDelta
	.even
__Q211EXNGPrivate8VoidList$linkCacheDelta:
	.long 256
.globl __Q211EXNGPrivate8VoidList$linkCacheCount
	.even
__Q211EXNGPrivate8VoidList$linkCacheCount:
	.long 0
.globl __Q211EXNGPrivate8VoidList$nextFreeLink
	.even
__Q211EXNGPrivate8VoidList$nextFreeLink:
	.long -1
.globl __Q211EXNGPrivate8VoidList$loggingClassName
.text
LC0:
	.ascii "VoidList\0"
.data
	.even
__Q211EXNGPrivate8VoidList$loggingClassName:
	.long LC0
.text
	.even
.globl _createLink__Q211EXNGPrivate8VoidList
_createLink__Q211EXNGPrivate8VoidList:
	pea a5@
	movel sp,a5
	movel __Q211EXNGPrivate8VoidList$linkCacheCount,d0
	movel d0,d1
	addql #1,d1
	movel d1,__Q211EXNGPrivate8VoidList$linkCacheCount
	addql #1,d0
	cmpl __Q211EXNGPrivate8VoidList$linkCacheSize,d0
	jlt L141
	jbsr _expandCache__Q211EXNGPrivate8VoidList
	tstb d0
	jne L141
	subql #1,__Q211EXNGPrivate8VoidList$linkCacheCount
	moveq #-1,d0
	jra L143
	.even
L141:
	movel __Q211EXNGPrivate8VoidList$nextFreeLink,d0
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	movel d0,d1
	lsll #4,d1
	movel a0@(8,d1:l),__Q211EXNGPrivate8VoidList$nextFreeLink
L143:
	unlk a5
	rts
	.even
.globl _destroyLink__Q211EXNGPrivate8VoidListl
_destroyLink__Q211EXNGPrivate8VoidListl:
	pea a5@
	movel sp,a5
	movel a5@(8),a1
	movel __Q211EXNGPrivate8VoidList$linkCacheCount,d1
	jle L145
	moveq #-1,d0
	cmpl a1,d0
	jeq L145
	cmpl __Q211EXNGPrivate8VoidList$linkCacheSize,a1
	jge L145
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	movel a1,d0
	lsll #4,d0
	tstl a0@(12,d0:l)
	jeq L145
	clrl a0@(12,d0:l)
	movel __Q211EXNGPrivate8VoidList$nextFreeLink,a0@(8,d0:l)
	movel a1,__Q211EXNGPrivate8VoidList$nextFreeLink
	movel d1,d0
	subql #1,d0
	movel d0,__Q211EXNGPrivate8VoidList$linkCacheCount
	moveq #1,d0
	cmpl d1,d0
	jne L145
	jbsr _releaseCache__Q211EXNGPrivate8VoidList
L145:
	unlk a5
	rts
LC1:
	.ascii "expandCache()\0"
.data
	.even
_loggingFuncName.174:
	.long LC1
.text
LC2:
	.ascii "%s::%s - failed to allocate %d bytes for link cache\12\0"
	.even
.globl _expandCache__Q211EXNGPrivate8VoidList
_expandCache__Q211EXNGPrivate8VoidList:
	pea a5@
	movel sp,a5
	moveml #0x3820,sp@-
	movel __Q211EXNGPrivate8VoidList$linkCacheSize,d4
	addl __Q211EXNGPrivate8VoidList$linkCacheDelta,d4
	clrl sp@-
	subql #2,sp
	moveb #0,sp@(1)
	subql #2,sp
	movel d4,d2
	lsll #4,d2
	movel d2,sp@-
	jbsr _alloc__3MemUlbQ23Mem9AlignType
	movel d0,a2
	addw #12,sp
	tstl a2
	jne L148
	movel d2,sp@-
	movel _loggingFuncName.174,sp@-
	movel __Q211EXNGPrivate8VoidList$loggingClassName,sp@-
	pea LC2
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	clrb d0
	jra L156
	.even
L148:
	movel __Q211EXNGPrivate8VoidList$linkCache,d3
	jeq L149
	movel __Q211EXNGPrivate8VoidList$linkCacheSize,d2
	lsll #4,d2
#APP
	
/*************************************/

	move.l a2, a0
	move.l d3, a1
	move.l d2, d0
	jsr _Mem_copy

/*************************************/


#NO_APP
	movel d3,sp@-
	jbsr _free__3MemPv
L149:
	movel a2,__Q211EXNGPrivate8VoidList$linkCache
	movel __Q211EXNGPrivate8VoidList$linkCacheSize,d1
	movel d1,d0
	lsll #4,d0
	addl d0,a2
	movel d1,d0
	cmpl d0,d4
	jle L152
	movel d4,d2
	subl d0,d2
	moveq #3,d1
	andl d1,d2
	jeq L154
	moveq #1,d1
	cmpl d2,d1
	jge L159
	moveq #2,d1
	cmpl d2,d1
	jge L160
	addql #1,d0
	movel d0,a2@(8)
	clrl a2@(12)
	addw #16,a2
L160:
	addql #1,d0
	movel d0,a2@(8)
	clrl a2@(12)
	addw #16,a2
L159:
	addql #1,d0
	movel d0,a2@(8)
	clrl a2@(12)
	addw #16,a2
	cmpl d0,d4
	jle L152
	.even
L154:
	addql #1,d0
	movel d0,a2@(8)
	clrl a2@(12)
	lea a2@(16),a0
	addql #1,d0
	movel d0,a0@(8)
	clrl a0@(12)
	lea a2@(32),a0
	addql #1,d0
	movel d0,a0@(8)
	clrl a0@(12)
	lea a2@(48),a0
	addql #1,d0
	movel d0,a0@(8)
	clrl a0@(12)
	addw #64,a2
	cmpl d0,d4
	jgt L154
L152:
	movel __Q211EXNGPrivate8VoidList$linkCacheSize,__Q211EXNGPrivate8VoidList$nextFreeLink
	movel d4,__Q211EXNGPrivate8VoidList$linkCacheSize
	moveq #1,d0
L156:
	moveml a5@(-16),#0x41c
	unlk a5
	rts
LC3:
	.ascii "releaseCache()\0"
.data
	.even
_loggingFuncName.178:
	.long LC3
.text
LC4:
	.ascii "%s::%s - freed link cache\12\0"
	.even
.globl _releaseCache__Q211EXNGPrivate8VoidList
_releaseCache__Q211EXNGPrivate8VoidList:
	pea a5@
	movel sp,a5
	movel __Q211EXNGPrivate8VoidList$linkCache,d0
	jeq L177
	movel d0,sp@-
	jbsr _free__3MemPv
	clrl __Q211EXNGPrivate8VoidList$linkCache
	clrl __Q211EXNGPrivate8VoidList$linkCacheSize
	moveq #-1,d0
	movel d0,__Q211EXNGPrivate8VoidList$nextFreeLink
	movel _loggingFuncName.178,sp@-
	movel __Q211EXNGPrivate8VoidList$loggingClassName,sp@-
	pea LC4
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
L177:
	unlk a5
	rts
	.even
.globl ___Q211EXNGPrivate8VoidList
___Q211EXNGPrivate8VoidList:
	pea a5@
	movel sp,a5
	movel a5@(8),a0
	moveq #-1,d0
	movel d0,a0@
	movel d0,a0@(4)
	clrl a0@(8)
	clrl a0@(12)
	movel a0,d0
	unlk a5
	rts
	.even
.globl __$_Q211EXNGPrivate8VoidList
__$_Q211EXNGPrivate8VoidList:
	pea a5@
	movel sp,a5
	movel a2,sp@-
	movel d2,sp@-
	movel a5@(8),a2
	movel a2@,d1
	jlt L185
	.even
L183:
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	movel d1,d0
	lsll #4,d0
	movel a0@(4,d0:l),d2
	movel d1,sp@-
	jbsr _destroyLink__Q211EXNGPrivate8VoidListl
	movel d2,d1
	addql #4,sp
	jge L183
L185:
	movel a5@(12),d0
	btst #0,d0
	jeq L187
	movel a2,sp@-
	jbsr ___builtin_delete
L187:
	movel a5@(-8),d2
	movel a5@(-4),a2
	unlk a5
	rts
	.even
.globl _pushFront__Q211EXNGPrivate8VoidListPv
_pushFront__Q211EXNGPrivate8VoidListPv:
	pea a5@
	movel sp,a5
	movel a2,sp@-
	movel d2,sp@-
	movel a5@(8),a2
	movel a5@(12),d2
	jeq L190
	jbsr _createLink__Q211EXNGPrivate8VoidList
	movel d0,d1
	jlt L190
	lsll #4,d0
	movel __Q211EXNGPrivate8VoidList$linkCache,a1
	lea a1@(0,d0:l),a0
	movel d2,a0@(12)
	moveq #-1,d0
	movel d0,a0@
	movel a2@,a0@(4)
	movel a2@,d0
	jge L192
	movel d1,a2@(4)
	jra L193
	.even
L192:
	lsll #4,d0
	movel d1,a1@(d0:l)
L193:
	movel d1,a2@
	addql #1,a2@(8)
	addql #1,a2@(12)
	moveq #1,d0
	jra L194
	.even
L190:
	clrb d0
L194:
	movel a5@(-8),d2
	movel a5@(-4),a2
	unlk a5
	rts
	.even
.globl _pushBack__Q211EXNGPrivate8VoidListPv
_pushBack__Q211EXNGPrivate8VoidListPv:
	pea a5@
	movel sp,a5
	movel a2,sp@-
	movel d2,sp@-
	movel a5@(8),a2
	movel a5@(12),d2
	jeq L196
	jbsr _createLink__Q211EXNGPrivate8VoidList
	movel d0,d1
	jlt L196
	lsll #4,d0
	movel __Q211EXNGPrivate8VoidList$linkCache,a1
	lea a1@(0,d0:l),a0
	movel d2,a0@(12)
	movel a2@(4),a0@
	moveq #-1,d0
	movel d0,a0@(4)
	movel a2@(4),d0
	jge L198
	movel d1,a2@
	jra L199
	.even
L198:
	lsll #4,d0
	movel d1,a1@(4,d0:l)
L199:
	movel d1,a2@(4)
	addql #1,a2@(8)
	addql #1,a2@(12)
	moveq #1,d0
	jra L200
	.even
L196:
	clrb d0
L200:
	movel a5@(-8),d2
	movel a5@(-4),a2
	unlk a5
	rts
	.even
.globl _popFront__Q211EXNGPrivate8VoidList
_popFront__Q211EXNGPrivate8VoidList:
	pea a5@
	movel sp,a5
	movel a2,sp@-
	movel d2,sp@-
	movel a5@(8),a2
	movel a2@,d1
	jlt L202
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	movel d1,d0
	lsll #4,d0
	movel a0@(12,d0:l),d2
	movel a0@(4,d0:l),a2@
	movel d1,sp@-
	jbsr _destroyLink__Q211EXNGPrivate8VoidListl
	movel a2@,d0
	jge L203
	moveq #-1,d0
	movel d0,a2@(4)
	jra L204
	.even
L203:
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	moveq #-1,d1
	movel d1,a0@(d0:l)
L204:
	subql #1,a2@(8)
	addql #1,a2@(12)
	movel d2,d0
	jra L205
	.even
L202:
	clrl d0
L205:
	movel a5@(-8),d2
	movel a5@(-4),a2
	unlk a5
	rts
	.even
.globl _popBack__Q211EXNGPrivate8VoidList
_popBack__Q211EXNGPrivate8VoidList:
	pea a5@
	movel sp,a5
	movel a2,sp@-
	movel d2,sp@-
	movel a5@(8),a2
	movel a2@(4),d1
	jlt L207
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	movel d1,d0
	lsll #4,d0
	movel a0@(12,d0:l),d2
	movel a0@(d0:l),a2@(4)
	movel d1,sp@-
	jbsr _destroyLink__Q211EXNGPrivate8VoidListl
	movel a2@(4),d0
	jge L208
	moveq #-1,d0
	movel d0,a2@
	jra L209
	.even
L208:
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d0
	moveq #-1,d1
	movel d1,a0@(4,d0:l)
L209:
	subql #1,a2@(8)
	addql #1,a2@(12)
	movel d2,d0
	jra L210
	.even
L207:
	clrl d0
L210:
	movel a5@(-8),d2
	movel a5@(-4),a2
	unlk a5
	rts
	.even
.globl _contains__Q211EXNGPrivate8VoidListPCv
_contains__Q211EXNGPrivate8VoidListPCv:
	pea a5@
	movel sp,a5
	movel a5@(8),a0
	movel a5@(12),d1
	movel a0@,d0
	jlt L213
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	.even
L215:
	lsll #4,d0
	cmpl a0@(12,d0:l),d1
	jne L214
	moveq #1,d0
	jra L218
	.even
L214:
	movel a0@(4,d0:l),d0
	jge L215
L213:
	clrb d0
L218:
	unlk a5
	rts
	.even
.globl _next__Q211EXNGPrivate11VLChkFwdItr
_next__Q211EXNGPrivate11VLChkFwdItr:
	pea a5@
	movel sp,a5
	movel a2,sp@-
	movel a5@(8),a2
	tstl a2@(4)
	jlt L221
	movel a2@,a0
	movel a2@(8),d0
	cmpl a0@(12),d0
	jeq L222
	jbsr _throwObjectModified
L222:
	movel a2@(4),d1
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d1
	movel a0@(12,d1:l),d0
	movel a0@(4,d1:l),a2@(4)
	jra L223
	.even
L221:
	clrl d0
L223:
	movel a5@(-4),a2
	unlk a5
	rts
	.even
.globl _first__Q211EXNGPrivate11VLChkFwdItr
_first__Q211EXNGPrivate11VLChkFwdItr:
	pea a5@
	movel sp,a5
	movel a5@(8),a0
	movel a0@,a1
	movel a1@(12),a0@(8)
	movel a1@,a0@(4)
	movel a0,sp@-
	jbsr _next__Q211EXNGPrivate11VLChkFwdItr
	unlk a5
	rts
	.even
.globl _next__Q211EXNGPrivate11VLChkRevItr
_next__Q211EXNGPrivate11VLChkRevItr:
	pea a5@
	movel sp,a5
	movel a2,sp@-
	movel a5@(8),a2
	tstl a2@(4)
	jlt L226
	movel a2@,a0
	movel a2@(8),d0
	cmpl a0@(12),d0
	jeq L227
	jbsr _throwObjectModified
L227:
	movel a2@(4),d1
	movel __Q211EXNGPrivate8VoidList$linkCache,a0
	lsll #4,d1
	movel a0@(12,d1:l),d0
	movel a0@(d1:l),a2@(4)
	jra L228
	.even
L226:
	clrl d0
L228:
	movel a5@(-4),a2
	unlk a5
	rts
	.even
.globl _first__Q211EXNGPrivate11VLChkRevItr
_first__Q211EXNGPrivate11VLChkRevItr:
	pea a5@
	movel sp,a5
	movel a5@(8),a0
	movel a0@,a1
	movel a1@(12),a0@(8)
	movel a1@(4),a0@(4)
	movel a0,sp@-
	jbsr _next__Q211EXNGPrivate11VLChkRevItr
	unlk a5
	rts
