#NO_APP
.text
	.even
.globl __dfRTTI__8Runnable
__dfRTTI__8Runnable:
	rts
	nop
.globl ___vt_8Runnable
	.even
___vt_8Runnable:
	.long 0
	.long ___tf8Runnable
	.long __dfRTTI__8Runnable
	.long ___pure_virtual
	.long __$_8Runnable
	.skip 4
.comm ___ti8Runnable,8
LC0:
	.ascii "8Runnable\0"
	.even
.globl ___tf8Runnable
___tf8Runnable:
	movel a2,sp@-
	lea ___ti8Runnable,a2
	tstl a2@
	jne L103
	pea LC0
	movel a2,sp@-
	jbsr ___rtti_user
	addql #8,sp
L103:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl __$_8Runnable
__$_8Runnable:
	movel sp@(4),a0
	movel #___vt_8Runnable,a0@
	btst #0,sp@(11)
	jeq L43
	movel a0,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L43:
	rts
	nop
