#NO_APP
.globl __3CPU$fpuPrecision
.data
	.even
__3CPU$fpuPrecision:
	.long 0
.globl __3CPU$cpuNames
.text
LC0:
	.ascii "MC680x0\0"
LC1:
	.ascii "MC68020\0"
LC2:
	.ascii "MC68030\0"
LC3:
	.ascii "MC68040\0"
LC4:
	.ascii "MC68060\0"
LC5:
	.ascii "ColdFire v4\0"
LC6:
	.ascii "ColdFire v5\0"
.data
	.even
__3CPU$cpuNames:
	.long LC0
	.long LC1
	.long LC2
	.long LC3
	.long LC4
	.long LC5
	.long LC6
.globl __3CPU$fpuNames
.text
LC7:
	.ascii "MC6888x\0"
LC8:
	.ascii "MC68881\0"
LC9:
	.ascii "MC68882\0"
LC10:
	.ascii "MC68040+68882emu\0"
LC11:
	.ascii "MC68060+68882emuSoftware\0"
.data
	.even
__3CPU$fpuNames:
	.long LC7
	.long LC8
	.long LC9
	.long LC3
	.long LC10
	.long LC4
	.long LC11
	.even
_cpu.93:
	.long -1
.text
	.even
.globl _cpuType__3CPU
_cpuType__3CPU:
	tstl _cpu.93
	jge L106
	movel _SysBase,a0
	movew a0@(296),d0
	tstb d0
	jge L107
	moveq #4,d0
	movel d0,_cpu.93
	jra L106
	.even
L107:
	btst #3,d0
	jeq L109
	moveq #3,d0
	movel d0,_cpu.93
	jra L106
	.even
L109:
	btst #2,d0
	jeq L111
	moveq #2,d0
	movel d0,_cpu.93
	jra L106
	.even
L111:
	btst #1,d0
	jeq L113
	moveq #1,d0
	movel d0,_cpu.93
	jra L106
	.even
L113:
	clrl _cpu.93
L106:
	movel _cpu.93,d0
	rts
	nop
.data
	.even
_fpu.97:
	.long -1
.text
	.even
.globl _fpuType__3CPU
_fpuType__3CPU:
	tstl _fpu.97
	jge L116
	movel _SysBase,a0
	movew a0@(296),d0
	tstb d0
	jge L117
	btst #6,d0
	jeq L116
	andw #48,d0
	jeq L119
	moveq #6,d0
	jra L130
	.even
L119:
	moveq #5,d0
	jra L130
	.even
L117:
	btst #6,d0
	jeq L122
	andw #48,d0
	jeq L123
	moveq #4,d0
	jra L130
	.even
L123:
	moveq #3,d0
	jra L130
	.even
L122:
	btst #5,d0
	jeq L126
	moveq #2,d0
	jra L130
	.even
L126:
	btst #4,d0
	jeq L128
	moveq #1,d0
	jra L130
	.even
L128:
	moveq #7,d0
L130:
	movel d0,_fpu.97
L116:
	movel _fpu.97,d0
	rts
	nop
	.even
.globl _flushDataCache__3CPUPvUl
_flushDataCache__3CPUPvUl:
	pea 2048:w
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	jbsr _CacheClearE
	addw #12,sp
	rts
	nop
	.even
.globl _flushInstCache__3CPUPvUl
_flushInstCache__3CPUPvUl:
	pea 8:w
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	jbsr _CacheClearE
	addw #12,sp
	rts
	nop
	.even
.globl _flushAllCaches__3CPUPvUl
_flushAllCaches__3CPUPvUl:
	pea 2056:w
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	jbsr _CacheClearE
	addw #12,sp
	rts
	nop
	.even
.globl _setPrecision__3CPUQ23CPU6FPPrec
_setPrecision__3CPUQ23CPU6FPPrec:
	rts
	nop
