  mc68040

; GCC 32-bit aligned stack
rts_addr      EQU 0
arg_dst       EQU 4
arg_val       EQU 8
arg_num       EQU 12

  XDEF  _set32_move16
  XDEF  _set32_move16_v2

  SECTION "read:0",CODE

  XDEF _set32_move16

_set32_move16
  move.l  arg_dst(a7), a0
  move.l  arg_val(a7), d0
  move.l  arg_num(a7), d1

  ;// allocate a cache aligned area (4 cache lines) on the stack and ref into a1
  move.l  d2, -(a7)
  link    a2, #-48
  move.l  a7, d2
  add.l   #15,d2
  and.l   #$FFFFFFF0, d2
  move.l  d2, a1

  ; // each set overwrites 32 longwords
  lsr.l   #5, d1

  ;// pre fill the cache lines
  move.l  d0, (a1)+
  move.l  d0, (a1)+
  move.l  d0, (a1)+
  move.l  d0, (a1)+
  move.l  d0, (a1)+
  move.l  d0, (a1)+
  move.l  d0, (a1)+
  move.l  d0, (a1)+

  ; // warm up the cache
  move.l  d2,  a1
  tst.l   (a1)
  tst.l   16(a1)

  bra.b .loop

  CNOP 0,8
.loop
  move.l   d2, a1
  move16  (a1)+, (a0)+
  move16  (a1)+, (a0)+

  move.l   d2, a1
  move16  (a1)+, (a0)+
  move16  (a1)+, (a0)+

  move.l   d2, a1
  move16  (a1)+, (a0)+
  move16  (a1)+, (a0)+

  move.l   d2, a1
  subq.l   #1, d1,
  move16  (a1)+, (a0)+
  move16  (a1)+, (a0)+

  bgt.b   .loop

  ;// restore stack
  unlk    a2
  move.l  (a7)+,    d2
.end
  rts

; ////////////////////////////////////////////

  XDEF _set32_move16_v2

_set32_move16_v2
  move.l  arg_dst(a7), a0
  move.l  arg_val(a7), d0
  move.l  arg_num(a7), d1

  move.l  a0,  a1
  move.l  d0, (a1)+
  move.l  d0, (a1)+
  move.l  d0, (a1)+
  move.l  d0, (a1)+

  ; // each set overwrites 4 longwords
  lsr.l   #2, d1
  subq.l  #1, d1 ; we've already written 1

  bra.b .loop

  CNOP 0,8
.loop
  subq.l   #1, d1
  move16  (a0)+, (a1)+
  bgt.b   .loop

.end
  rts

  END