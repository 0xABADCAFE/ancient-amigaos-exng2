#NO_APP
.text
	.even
.globl _foo__FRUxRd
_foo__FRUxRd:
	movel d3,sp@-
	movel d2,sp@-
	movel sp@(12),a0
	movel a0@,d2
	movel a0@(4),d3
	tstl d2
	jmi L297
	movel d3,sp@-
	movel d2,sp@-
	jbsr ___floatdidf
	addql #8,sp
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp0
	jra L296
	.even
L297:
	movel d2,d0
	movel d3,d1
	lsrl #1,d0
	roxrl #1,d1
	clrl d2
	andl #1,d3
	orl d0,d2
	orl d1,d3
	movel d3,sp@-
	movel d2,sp@-
	jbsr ___floatdidf
	addql #8,sp
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp0
	movel d1,sp@-
	movel d0,sp@-
	fmoved sp@+,fp1
	faddx fp1,fp0
L296:
	movel sp@(16),a0
	fmoved fp0,a0@
	movel sp@+,d2
	movel sp@+,d3
	rts
