#NO_APP
.globl __10MilliClock$clockFreq
.data
	.even
__10MilliClock$clockFreq:
	.long 0
.text
	.even
.globl _elapsed__C10MilliClock
_elapsed__C10MilliClock:
	link a5,#-8
	movel a2,sp@-
	movel a5@(8),a2
	pea a5@(-8)
	jbsr _ReadEClock
	addql #4,sp
	movel a5@(-8),d0
	cmpl a2@,d0
	jne L148
	movel a5@(-4),d0
	jra L150
	.even
L148:
	movel a5@(-4),d0
	subql #1,d0
L150:
	subl a2@(4),d0
	mulsl #1000,d0
	divul __10MilliClock$clockFreq,d0
	movel a5@(-12),a2
	unlk a5
	rts
.lcomm _cF.156,8
.lcomm __$tmp_0.157,4
	.even
.globl _elapsedFrac__C10MilliClock
_elapsedFrac__C10MilliClock:
	link a5,#-8
	movel a2,sp@-
	movel a5@(8),a2
	pea a5@(-8)
	jbsr _ReadEClock
	addql #4,sp
	tstl __$tmp_0.157
	jne L152
	movel __10MilliClock$clockFreq,d0
	fmovel d0,fp0
	tstl d0
	jge L153
	faddd #0r4294967296.000005,fp0
L153:
	fmoved #0r1000.000000000005,fp1
	fdivx fp0,fp1
	fmoved fp1,_cF.156
	moveq #1,d0
	movel d0,__$tmp_0.157
L152:
	movel a5@(-8),d0
	cmpl a2@,d0
	jne L154
	movel a5@(-4),d0
	jra L158
	.even
L154:
	movel a5@(-4),d0
	subql #1,d0
L158:
	subl a2@(4),d0
	fmovel d0,fp0
	tstl d0
	jge L156
	faddd #0r4294967296.000005,fp0
L156:
	fmuld _cF.156,fp0
	fmoved fp0,sp@-
	movel sp@+,d0
	movel sp@+,d1
	movel a5@(-12),a2
	unlk a5
	rts
	.even
.globl ___10MilliClock
___10MilliClock:
	movel d2,sp@-
	movel sp@(8),d2
	movel d2,sp@-
	jbsr _ReadEClock
	movel d0,__10MilliClock$clockFreq
	addql #4,sp
	movel d2,d0
	movel sp@+,d2
	rts
	.even
.globl _set__10MilliClock
_set__10MilliClock:
	movel sp@(4),sp@-
	jbsr _ReadEClock
	addql #4,sp
	rts
	nop
	.even
.globl _elapsed__C5Clock
_elapsed__C5Clock:
	link a5,#-8
	movel a2,sp@-
	movel d2,sp@-
	movel a5@(8),a2
	pea a5@(-8)
	jbsr _GetSysTime
	movel a2,sp@-
	pea a5@(-8)
	jbsr _SubTime
	movel a5@(-8),d0
	mulsl #1000,d0
	movel a5@(-4),d1
	divul #1000,d1
	addl d1,d0
	movel d0,a2@(12)
	clrl a2@(8)
	movel a2,d0
	addql #8,d0
	addw #12,sp
	movel a5@(-16),d2
	movel a5@(-12),a2
	unlk a5
	rts
	.even
.globl _set__5Clock
_set__5Clock:
	movel a2,sp@-
	movel sp@(8),a2
	movel a2,sp@-
	jbsr _GetSysTime
	clrl a2@(8)
	clrl a2@(12)
	addql #4,sp
	movel sp@+,a2
	rts
	.even
.globl ___5Clock
___5Clock:
	movel a2,sp@-
	movel sp@(8),a2
	clrl a2@(8)
	clrl a2@(12)
	movel a2,sp@-
	jbsr _set__5Clock
	addql #4,sp
	movel a2,d0
	movel sp@+,a2
	rts
