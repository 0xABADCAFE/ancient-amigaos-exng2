
#; File:        platforms/amigaos41_ppc/systemlib/memory_native_asm.s
#; Description: Optimized memory routines
#; Library:     System

#; Field            Type        Used for:
#; R0               Volatile    Language Specific
#; R1               Dedicated   Stack Pointer (SP)
#; R2               Dedicated   Read-only small data area anchor
#; R3 - R4          Volatile    Parameter passing / return values
#; R5 - R10         Volatile    Parameter passing
#; R11 - R12        Volatile
#; R13              Dedicated   Read-write small data area anchor
#; R14 - R31        Nonvolatile
#; F0               Volatile    Language specific
#; F1               Volatile    Parameter passing / return values
#; F2 - F8          Volatile    Parameter passing
#; F9 - F13         Volatile
#; F14 - F31        Nonvolatile
#; Fields CR2 - CR4 Nonvolatile
#; Other CR fields  Volatile
#; Other registers  Volatile


  .section  ".text"
  .align 4

#; ////////////////////////////////////////////////////////////////////////////

#; void ASM_RawMemHandler_swap16_16([r3] void* dst, [r4] const void* src, [r5] size_t num)

  .globl ASM_RawMemHandler_swap16_16
  .type ASM_RawMemHandler_swap16_16, @function

ASM_RawMemHandler_swap16_16:

#; pre-decrement destnation since were using store with update
  addi    %r3,    %r3,    -2

.loop16:
  lhbrx   %r10,   %r0,    %r4 #; assume latencey here
  addic.  %r5,    %r5,    -1
  addi    %r4,    %r4,    2
  sthu    %r10,   2(%r3)
  bne+    %cr0,   .loop16
  blr

  .size ASM_RawMemHandler_swap16_16, .-ASM_RawMemHandler_swap16_16

#; ////////////////////////////////////////////////////////////////////////////

#; ASM_RawMemHandler_swap16_32([r3] void* dst, [r4] const void* src, [r5] size_t num)

  .globl ASM_RawMemHandler_swap16_32
  .type ASM_RawMemHandler_swap16_32, @function

ASM_RawMemHandler_swap16_32:

#; Source and destination are 32-bit aligned here
#; This allows us to optimize with a 32-bit loop
#; We make a note to see if there is an odd nbr
#; of words prior to entering the 32-bit loop
#; since we divide the loop counter by 2 for
#; the 32-bit block

  andi.   %r12,   %r5,    1
  srwi    %r5,    %r5,    1
  cmplwi  %cr0,   %r5,    0
  beq-    %cr0,  .odd_16_32

  addi    %r3,    %r3,    -4

.loop16_32:
  lwbrx   %r10,   %r0,    %r4           #; assume latency here
  addic.  %r5,    %r5,    -1            #; decrement counter, with cr0 update
  addi    %r4,    %r4,    4             #; increment source
  rlwinm  %r11,   %r10,   16,   0,  31  #; halfword swap r10 -> r11 (non destructive on r10 for pipeline)
  stwu    %r11,   4(%r3)
  bne+    %cr0,   .loop16_32            #; counter > 0 ?

#; Check to see if there is 1 remaining odd 16-bit word to do

.odd_16_32:
  cmplwi  %cr0,   %r12,   0
  beq     %cr0,   .done_16
  lhbrx   %r10,   %r0,    %r4
  sth     %r10,   0(%r3)

.done_16:
  blr

  .size ASM_RawMemHandler_swap16_32, .-ASM_RawMemHandler_swap16_32

#; ////////////////////////////////////////////////////////////////////////////

#; ASM_RawMemHandler_swap32([r3] void* dst, [r4] const void* src, [r5] size_t num)

  .globl ASM_RawMemHandler_swap32
  .type ASM_RawMemHandler_swap32, @function

ASM_RawMemHandler_swap32:
  cmplwi  %cr0,   %r5,    0
  beqlr-  %cr0

.loop32:
  addic.  %r5,    %r5,    -1
  lwbrx   %r10,   %r0,    %r4
  addi    %r4,    %r4,    4
  stw     %r10,   0(%r3)
  addi    %r3,    %r3,    4
  bne+    %cr0,   .loop32

  blr

  .size ASM_RawMemHandler_swap32, .-ASM_RawMemHandler_swap32

#; ////////////////////////////////////////////////////////////////////////////

#; ASM_RawMemHandler_swap64([r3] void* dst, [r4] const void* src, [r5] size_t num)

  .globl ASM_RawMemHandler_swap64
  .type ASM_RawMemHandler_swap64, @function

ASM_RawMemHandler_swap64:

  addi    %r3,    %r3,    -4
  cmplwi  %cr0,   %r5,      0
  beqlr-  %cr0

.loop64:
  addic.  %r5,    %r5,    -1
#; read msw with swap
  lwbrx   %r10,   %r0,    %r4
  addi    %r4,    %r4,    4
  lwbrx   %r9,    %r0,    %r4
#; read lsw with swap
  addi    %r4,    %r4,    4
#; write lsw 1st
  stwu    %r9,    4(%r3)
#; write msw 2nd
  stwu    %r10,   4(%r3)
  bne+    %cr0,   .loop64

  blr

  .size ASM_RawMemHandler_swap64, .-ASM_RawMemHandler_swap64

#; ////////////////////////////////////////////////////////////////////////////

#; ASM_RawMemHandler_set64([r3] void* dst, [r4] const void* src, [r5] size_t num)

  .globl ASM_RawMemHandler_set64
  .type ASM_RawMemHandler_set64, @function

ASM_RawMemHandler_set64:

  addi    %r3,    %r3,    -8
  rlwinm  %r0,    %r5,    31,28,31
  addi    %r5,    %r5,    30
  lfd     %f0,    0(%r4)
  cmplwi  %cr7,   %r0,    15
  srwi    %r10,   %r5,    5
  bgtlr-  %cr7
  lis     %r9,    .jumpTab@ha
  slwi    %r0,    %r0,2
  la      %r9,    .jumpTab@l(%r9)
  lwzx    %r11,   %r9,    %r0
  add     %r11,   %r11,   %r9
  mtctr   %r11
  bctr
  .section  .rodata
  .align 2
  .align 2
.jumpTab:
  .long .case15-.jumpTab
  .long .case14-.jumpTab
  .long .case13-.jumpTab
  .long .case12-.jumpTab
  .long .case11-.jumpTab
  .long .case10-.jumpTab
  .long .case9-.jumpTab
  .long .case8-.jumpTab
  .long .case7-.jumpTab
  .long .case6-.jumpTab
  .long .case5-.jumpTab
  .long .case4-.jumpTab
  .long .case3-.jumpTab
  .long .case2-.jumpTab
  .long .case1-.jumpTab
  .long .case0-.jumpTab
  .section  ".text"
.case0:
  stfdu %f0,8(%r3)
.case1:
  stfdu %f0,8(%r3)
.case2:
  stfdu %f0,8(%r3)
.case3:
  stfdu %f0,8(%r3)
.case4:
  stfdu %f0,8(%r3)
.case5:
  stfdu %f0,8(%r3)
.case6:
  stfdu %f0,8(%r3)
.case7:
  stfdu %f0,8(%r3)
.case8:
  stfdu %f0,8(%r3)
.case9:
  stfdu %f0,8(%r3)
.case10:
  stfdu %f0,8(%r3)
.case11:
  stfdu %f0,8(%r3)
.case12:
  stfdu %f0,8(%r3)
.case13:
  stfdu %f0,8(%r3)
.case14:
  addic. %r10,%r10,-1 #; decremebt block counter
  stfdu %f0,8(%r3)
  beqlr- %cr0
.case15:
  stfdu %f0,8(%r3)
  b .case0

  .size ASM_RawMemHandler_set64, .-ASM_RawMemHandler_set64
