#NO_APP
.text
LC0:
	.ascii "Map::Map() - allocated %d bytes data\12\0"
	.even
.globl ___3Map
___3Map:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel #___vt_3Map,a2@(4)
	clrl a2@
	moveq #1,d2
	swap d2
	clrl sp@-
	movel d2,sp@-
	jbsr _alloc__3MemUlUl
	addql #8,sp
	movel d0,a2@
	movel d2,sp@-
	pea LC0
	jbsr _printf
	addql #8,sp
	movel a2,d0
	movel sp@+,d2
	movel sp@+,a2
	rts
LC1:
	.ascii "Map::~Map() - freed data\12\0"
	.even
.globl __$_3Map
__$_3Map:
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(12),a2
	movel sp@(16),d2
	movel #___vt_3Map,a2@(4)
	movel a2@,sp@-
	jbsr _free__3MemPv
	pea LC1
	jbsr _printf
	addql #8,sp
	btst #0,d2
	jeq L219
	movel a2,sp@-
	jbsr ___builtin_delete
	addql #4,sp
L219:
	movel sp@+,d2
	movel sp@+,a2
	rts
	.even
.globl _point__9LinearMapUlUl
_point__9LinearMapUlUl:
	movel sp@(4),a0
	movel sp@(12),d0
	lsll #8,d0
	addl sp@(8),d0
	addl a0@,d0
	rts
	nop
	.even
.globl ___9LinearMap
___9LinearMap:
	link a5,#-52
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-52)
	movel a5@(8),sp@-
	jbsr ___3Map
	movel a5@(-52),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L225,a5@(-12)
	movel sp,a5@(-8)
	jra L224
	.even
L225:
	jra L233
	.even
L224:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_9LinearMap,a0@(4)
	addql #4,sp
	movel a5@(-52),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L232
	.even
L233:
L222:
	movel a5@(-52),a0
	addql #4,a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L230,a5@(-36)
	movel sp,a5@(-32)
	jra L229
	.even
L230:
	jra L234
	.even
L229:
	lea a5@(-48),a1
	movel a1,a0@
	clrl sp@-
	movel a5@(8),sp@-
	jbsr __$_3Map
	movel a5@(-52),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jbsr ___sjthrow
	.even
L234:
L227:
	jbsr ___terminate
	.even
L232:
	moveml a5@(-164),#0x5cfc
	fmovem a5@(-124),#0x3f
	unlk a5
	rts
	.even
.globl _point__13SubPatch16MapUlUl
_point__13SubPatch16MapUlUl:
	movel sp@(4),a0
	movel sp@(8),d0
	movel sp@(12),d1
#APP
	ror.l  #2,     d0
	ror.l  #2,     d1
	lsl.w  #2,     d0
	lsl.w  #6,     d1
	rol.l  #2,     d0
	rol.l  #4,     d1
	or.l   d1,     d0
	
#NO_APP
	addl a0@,d0
	rts
	nop
	.even
.globl ___13SubPatch16Map
___13SubPatch16Map:
	link a5,#-52
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-52)
	movel a5@(8),sp@-
	jbsr ___3Map
	movel a5@(-52),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L240,a5@(-12)
	movel sp,a5@(-8)
	jra L239
	.even
L240:
	jra L248
	.even
L239:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_13SubPatch16Map,a0@(4)
	addql #4,sp
	movel a5@(-52),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L247
	.even
L248:
L237:
	movel a5@(-52),a0
	addql #4,a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L245,a5@(-36)
	movel sp,a5@(-32)
	jra L244
	.even
L245:
	jra L249
	.even
L244:
	lea a5@(-48),a1
	movel a1,a0@
	clrl sp@-
	movel a5@(8),sp@-
	jbsr __$_3Map
	movel a5@(-52),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jbsr ___sjthrow
	.even
L249:
L242:
	jbsr ___terminate
	.even
L247:
	moveml a5@(-164),#0x5cfc
	fmovem a5@(-124),#0x3f
	unlk a5
	rts
	.even
___vt_13SubPatch16Map:
	.long 0
	.long ___tf13SubPatch16Map
	.long __$_13SubPatch16Map
	.skip 4
	.even
___vt_9LinearMap:
	.long 0
	.long ___tf9LinearMap
	.long __$_9LinearMap
	.skip 4
.globl ___vt_3Map
	.even
___vt_3Map:
	.long 0
	.long ___tf3Map
	.long __$_3Map
	.skip 4
.comm ___ti3Map,8
LC2:
	.ascii "3Map\0"
.comm ___ti9LinearMap,12
LC3:
	.ascii "9LinearMap\0"
.comm ___ti13SubPatch16Map,12
LC4:
	.ascii "13SubPatch16Map\0"
	.even
.globl ___tf3Map
___tf3Map:
	lea ___ti3Map,a0
	tstl a0@
	jne L251
	pea LC2
	movel a0,sp@-
	jbsr ___rtti_user
	addql #8,sp
L251:
	movel #___ti3Map,d0
	rts
	nop
	.even
__$_9LinearMap:
	movel sp@(8),sp@-
	movel sp@(8),sp@-
	jbsr __$_3Map
	addql #8,sp
	rts
	nop
	.even
___tf9LinearMap:
	tstl ___ti9LinearMap
	jne L255
	tstl ___ti3Map
	jne L257
	pea LC2
	pea ___ti3Map
	jbsr ___rtti_user
	addql #8,sp
L257:
	pea ___ti3Map
	pea LC3
	pea ___ti9LinearMap
	jbsr ___rtti_si
	addw #12,sp
L255:
	movel #___ti9LinearMap,d0
	rts
	nop
	.even
__$_13SubPatch16Map:
	movel sp@(8),sp@-
	movel sp@(8),sp@-
	jbsr __$_3Map
	addql #8,sp
	rts
	nop
	.even
___tf13SubPatch16Map:
	tstl ___ti13SubPatch16Map
	jne L261
	tstl ___ti3Map
	jne L263
	pea LC2
	pea ___ti3Map
	jbsr ___rtti_user
	addql #8,sp
L263:
	pea ___ti3Map
	pea LC4
	pea ___ti13SubPatch16Map
	jbsr ___rtti_si
	addw #12,sp
L261:
	movel #___ti13SubPatch16Map,d0
	rts
	nop
