;//****************************************************************************//
;//**                                                                        **//
;//** File:         libsrc/plat/amigaos3_68k/gfxlib/pixel_native_asm.i       **//
;//** Description:  Optimised pixel translation                              **//
;//** Comment(s):                                                            **//
;//** Library:      gfxlib                                                   **//
;//** Created:      2003-02-09                                               **//
;//** Updated:      2003-02-09                                               **//
;//** Author(s):    Karl Churchill                                           **//
;//** Note(s):                                                               **//
;//** Copyright:    (C)1996+ eXtropia Studios                                **//
;//**               Karl Churchill                                           **//
;//**               All Rights Reserved.                                     **//
;//**                                                                        **//
;//****************************************************************************//

  mc68040


  XREF _Mem_copy
  XREF _Mem_swap16
  XREF _Mem_swap32

; PIXCONV_ARGS  void* dst, const void* src, uint32 w, uint32 h, uint32 dMod, uint32 sMod
; PIXCONV_ARGS2 void* dst, const void* src, const uint32* sPal, int w, int h, int dstMod, int srcMod

; GCC 32-bit aligned stack
rts_addr      EQU 0
arg1_dst      EQU 4
arg1_src      EQU 8
arg1_w        EQU 12
arg1_h        EQU 16
arg1_dMod     EQU 20
arg1_sMod     EQU 24

arg1_base_l   EQU 0 ; register pair used for initial arguments
arg1_base_w   EQU 2
arg1_base_b   EQU 3

;////////////////////////////////////////////////////////////////////////////////
;//
;//  INIT
;//
;//  a0 dst
;//  a1 src
;//  d0 w[16]    : h[16]
;//  d1 dMod[16] : sMod[16]
;//
;////////////////////////////////////////////////////////////////////////////////

  MACRO INIT
  move.l  arg1_base_l + arg1_dst(a7),  a0
  move.l  arg1_base_l + arg1_src(a7),  a1
  move.w  arg1_base_w + arg1_w(a7),    d0
  swap    d0
  move.w  arg1_base_w + arg1_h(a7),    d0
  move.w  arg1_base_w + arg1_dMod(a7), d1
  swap    d1
  move.w  arg1_base_w + arg1_sMod(a7), d1
  ENDM

  MACRO DONE

  ENDM





;////////////////////////////////////////////////////////////////////////////////
;//
;//  COPY_PIXELS size=1/2/3/4
;//
;//  a0 dst/scratch
;//  a1 src/scratch
;//  a2 dst
;//  a3 src
;//  d0 scratch
;//  d1 scratch
;//  d2 w
;//  d3 h
;//  d4 dstMod (pixels)
;//  d4 srcMod (pixels)
;//
;////////////////////////////////////////////////////////////////////////////////

  MACRO COPY_PIXELS
  move.l  arg1_dst(a7), a0
  move.l  arg1_src(a7), a1

; unlikely but no point overwriting self
  cmp.l a0, a1
  bne.b .proceed
  rts

.proceed
  movem.l d2/d3/d4/d5, -(a7)
  move.l  16+arg1_w(a7),    d2
  move.l  16+arg1_h(a7),    d3
  move.l  16+arg1_dMod(a7), d4
  move.l  16+arg1_sMod(a7), d5

; srcMod == dstMod == 0 -> .copyBlock
  move.l  d4, d0
  or.l    d5, d0
  bne.b  .copyScanlines

.copyBlock
; _Mem_copy(dst, src, (w*h*size)
  mulu    d2,   d3
  move.l  d3,   d0

;
  IFC "\1", "1"
  ENDC

  IFC "\1", "2"
  lsl.l   #1,   d0
  ENDC

  IFC "\1", "3"
  move.l  d0,   d1
  lsl.l   #1,   d0
  add.l   d1,   d0
  ENDC

  IFC "\1", "4"
  lsl.l   #2,   d0
  ENDC

  jsr     _Mem_copy
  movem.l (a7)+, d2/d3/d4/d5
  rts

.copyScanlines
; a0/a1 volatile within _Mem_copy. Scale w/srcSpan/dstSpan to match ptr size
; interleave operations to improve throughput
  movem.l a2/a3, -(a7)

  add.l   d2,   d4
  add.l   d2,   d5

  ;lsl.l   #1, d2
  IFC "\1", "1"
  ENDC

  IFC "\1", "2"
  lsl.l   #1,   d2
  ENDC

  IFC "\1", "3"
  move.l  d2,   d0
  lsl.l   #1,   d2
  add.l   d0,   d2
  ENDC

  IFC "\1", "4"
  lsl.l   #2,   d2
  ENDC

  move.l  a0, a2

  ;lsl.l   #1, d4
  IFC "\1", "1"
  ENDC

  IFC "\1", "2"
  lsl.l   #1,   d4
  ENDC

  IFC "\1", "3"
  move.l  d4,   d0
  lsl.l   #1,   d4
  add.l   d0,   d4
  ENDC

  IFC "\1", "4"
  lsl.l   #2,   d4
  ENDC

  move.l  a1, a3

  ;lsl.l   #1, d5
  IFC "\1", "1"
  ENDC

  IFC "\1", "2"
  lsl.l   #1,   d5
  ENDC

  IFC "\1", "3"
  move.l  d5,   d0
  lsl.l   #1,   d5
  add.l   d0,   d5
  ENDC

  IFC "\1", "4"
  lsl.l   #2,   d5
  ENDC

  bra.b   .scanlineLoopTest

  CNOP    0, 8
.scanlineLoop
  move.l  d2,   d0
  jsr     _Mem_copy

  add.l   d4,   a2
  add.l   d5,   a3
  move.l  a2,   a0
  move.l  a3,   a1

.scanlineLoopTest
  subq    #1,   d3
  bgt.b   .scanlineLoop

  movem.l (a7)+, a2/a3
  movem.l (a7)+, d2/d3/d4/d5
  ENDM

;////////////////////////////////////////////////////////////////////////////////
;//
;//  BSWAP_PIXELS pixel_size=2/4
;//
;//  a0 dst/scratch
;//  a1 src/scratch
;//  a2 dst
;//  a3 src
;//  d0 scratch
;//  d1 scratch
;//  d2 w
;//  d3 h
;//  d4 dstMod (pixels)
;//  d4 srcMod (pixels)
;//
;////////////////////////////////////////////////////////////////////////////////

  MACRO BSWAP_PIXELS

  movem.l d2/d3/d4/d5, -(a7)

  move.l  16+arg1_dst(a7),   a0
  move.l  16+arg1_src(a7),   a1
  move.l  16+arg1_w(a7),     d2
  move.l  16+arg1_h(a7),     d3
  move.l  16+arg1_dMod(a7),  d4
  move.l  16+arg1_sMod(a7),  d5

; srcMod == dstMod == 0 -> .copyBlock
  move.l  d4, d0
  or.l    d5, d0
  bne.b  .copyScanlines

.copyBlock
; _Mem_swap (dst, src, (w*h*size)
  mulu    d2,   d3
  move.l  d3,   d0

  IFC "\1", "2"
  jsr     _Mem_swap16
  ENDC
  IFC "\1", "4"
  jsr     _Mem_swap32
  ENDC

  movem.l (a7)+, d2/d3/d4/d5
  rts

.copyScanlines
; a0/a1 volatile within _Mem_copy. Scale srcSpan/dstSpan to match ptr size
; interleave operations to improve throughput
  movem.l a2/a3, -(a7)

  add.l   d2,   d4
  add.l   d2,   d5

  ;lsl.l   #1, d4
  IFC "\1", "2"
  lsl.l   #1,   d4
  ENDC
  IFC "\1", "4"
  lsl.l   #2,   d4
  ENDC

  move.l  a0, a2

  ;lsl.l   #1, d5
  IFC "\1", "2"
  lsl.l   #1,   d5
  ENDC
  IFC "\1", "4"
  lsl.l   #2,   d5
  ENDC

  move.l  a1, a3

  bra.b   .scanlineLoopTest

  CNOP    0, 8
.scanlineLoop
  move.l  d2,   d0

  IFC "\1", "2"
  jsr     _Mem_swap16
  ENDC

  IFC "\1", "4"
  jsr     _Mem_swap32
  ENDC

  add.l   d4,   a2
  add.l   d5,   a3
  move.l  a2,   a0
  move.l  a3,   a1

.scanlineLoopTest
  subq    #1,   d3
  bgt.b   .scanlineLoop

  movem.l (a7)+, a2/a3
  movem.l (a7)+, d2/d3/d4/d5
  ENDM
