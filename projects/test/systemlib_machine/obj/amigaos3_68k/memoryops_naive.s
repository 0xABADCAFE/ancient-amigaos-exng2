#NO_APP
.text
	.even
.globl _naiveSwap16__FPvPCvUl
_naiveSwap16__FPvPCvUl:
	movel sp@(8),a1
	movel sp@(4),a0
	movel sp@(12),d1
	subql #1,d1
	moveq #-1,d0
	cmpl d1,d0
	jeq L304
	.even
L305:
	movew a1@+,d0
#APP
	rol.w #8, d0

#NO_APP
	movew d0,a0@+
	dbra d1,L305
	clrw d1
	subql #1,d1
	jcc L305
L304:
	rts
	nop
	.even
.globl _naiveSwap32__FPvPCvUl
_naiveSwap32__FPvPCvUl:
	movel sp@(8),a1
	movel sp@(4),a0
	movel sp@(12),d1
	subql #1,d1
	moveq #-1,d0
	cmpl d1,d0
	jeq L312
	.even
L313:
	movel a1@+,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0

#NO_APP
	movel d0,a0@+
	dbra d1,L313
	clrw d1
	subql #1,d1
	jcc L313
L312:
	rts
	nop
	.even
.globl _naiveSwap64__FPvPCvUl
_naiveSwap64__FPvPCvUl:
	movel d3,sp@-
	movel d2,sp@-
	movel sp@(16),a1
	movel sp@(12),a0
	movel sp@(20),d3
	subql #1,d3
	moveq #-1,d0
	cmpl d3,d0
	jeq L320
	.even
L321:
	movel a1@+,d0
	movel a1@+,d1
	movel d0,d2
#APP
	rol.w #8, d2
	swap d2
	rol.w #8, d2

#NO_APP
	movel d1,d0
#APP
	rol.w #8, d0
	swap d0
	rol.w #8, d0

#NO_APP
	movel d2,d1
	movel d0,a0@+
	movel d1,a0@+
	dbra d3,L321
	clrw d3
	subql #1,d3
	jcc L321
L320:
	movel sp@+,d2
	movel sp@+,d3
	rts
