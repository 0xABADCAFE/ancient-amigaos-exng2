#NO_APP
.text
	.even
.globl _evalHash__5Key32PCc
_evalHash__5Key32PCc:
	pea a5@
	movel sp,a5
	movel d2,sp@-
	movel a5@(8),d2
	jne L120
	jbsr _throwNullPointer
L120:
	clrl d0
	movel d2,a0
	tstb a0@
	jeq L122
	clrl d2
	.even
L123:
	movel d0,d1
	addl d1,d1
	tstl d0
	jge L124
	moveq #1,d0
	orl d0,d1
L124:
	moveb a0@+,d2
	movel d2,d0
	eorl d1,d0
	tstb a0@
	jne L123
L122:
	movel a5@(-4),d2
	unlk a5
	rts
	.even
.globl _evalHash__5Key64PCc
_evalHash__5Key64PCc:
	pea a5@
	movel sp,a5
	moveml #0x3800,sp@-
	movel a5@(8),d4
	jne L128
	jbsr _throwNullPointer
L128:
	clrl d2
	clrl d3
	movel d4,a0
	tstb a0@
	jeq L130
	.even
L131:
	movel d2,d0
	movel d3,d1
	addl d1,d1
	addxl d0,d0
	addl d2,d2
	clrl d2
	clrl d3
	addxl d3,d3
	orl d0,d2
	orl d1,d3
	moveq #0,d0
	moveq #0,d1
	moveb a0@+,d1
	eorl d0,d2
	eorl d1,d3
	tstb a0@
	jne L131
L130:
	movel d2,d0
	movel d3,d1
	moveml a5@(-12),#0x1c
	unlk a5
	rts
