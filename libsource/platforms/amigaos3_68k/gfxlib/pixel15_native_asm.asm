;//****************************************************************************//
;//**                                                                        **//
;//** File:         libsrc/plat/amigaos3_68k/gfxlib/pixel15_native_asm.asm   **//
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

  INCDIR  "exng2:libsource/platforms/amigaos3_68k/gfxlib/"
  INCLUDE "pixel_native_asm.i"

  XDEF _convCopy16
  XDEF _convSwap16

  XDEF _convXGY_555B_To_YGX_555B
  XDEF _convXGY_555B_To_YGX_555L
  XDEF _convXGY_555L_To_YGX_555B
  XDEF _convXGY_555L_To_YGX_555L

  XDEF _convXGY_555B_To_XGY_565B
  XDEF _convXGY_555B_To_XGY_565L
  XDEF _convXGY_555L_To_XGY_565B
  XDEF _convXGY_555L_To_XGY_565L

  XDEF _convXGY_555B_To_YGX_565B
  XDEF _convXGY_555B_To_YGX_565L
  XDEF _convXGY_555L_To_YGX_565B
  XDEF _convXGY_555L_To_YGX_565L

  XDEF _convXGY_555B_To_XGY_888
  XDEF _convXGY_555L_To_XGY_888
  XDEF _convXGY_555B_To_YGX_888
  XDEF _convXGY_555L_To_YGX_888


  XDEF _convXGY_555B_To_AXGY_8888
  XDEF _convXGY_555B_To_AYGX_8888
  XDEF _convXGY_555B_To_YGXA_8888
  XDEF _convXGY_555B_To_XGYA_8888
  XDEF _convXGY_555L_To_AXGY_8888
  XDEF _convXGY_555L_To_AYGX_8888
  XDEF _convXGY_555L_To_YGXA_8888
  XDEF _convXGY_555L_To_XGYA_8888

;////////////////////////////////////////////////////////////////////////////////
;//
;//  a0 dst
;//  a1 src
;//  d0 w[16]    : h[16]
;//  d1 dMod[16] : sMod[16]
;//
;////////////////////////////////////////////////////////////////////////////////


  SECTION "15to15bit:0",CODE

;////////////////////////////////////////////////////////////////////////////////

_convCopy16
  COPY_PIXELS 2
  rts

;////////////////////////////////////////////////////////////////////////////////

_convSwap16
  BSWAP_PIXELS 2
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_555B_To_YGX_555B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_555B_To_YGX_555L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_555L_To_YGX_555B
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_555L_To_YGX_555L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////;
;//
;//
;//
;////////////////////////////////////////////////////////////////////////////////

  SECTION "15to16bit:0",CODE

_convXGY_555B_To_XGY_565B
  INIT

  DONE
  rts

_convXGY_555B_To_XGY_565L
  INIT

  DONE
  rts

_convXGY_555L_To_XGY_565B
  INIT

  DONE
  rts

_convXGY_555L_To_XGY_565L
  INIT

  DONE
  rts

_convXGY_555B_To_YGX_565B
  INIT

  DONE
  rts

_convXGY_555B_To_YGX_565L
  INIT

  DONE
  rts

_convXGY_555L_To_YGX_565B
  INIT

  DONE
  rts

_convXGY_555L_To_YGX_565L
  INIT

  DONE
  rts

  SECTION "15to24bit:0",CODE

_convXGY_555B_To_XGY_888
  INIT

  DONE
  rts

_convXGY_555L_To_XGY_888
  INIT

  DONE
  rts

_convXGY_555B_To_YGX_888
  INIT

  DONE
  rts

_convXGY_555L_To_YGX_888
  INIT

  DONE
  rts

  SECTION "15to32bit:0",CODE

_convXGY_555B_To_AXGY_8888
  INIT

  DONE
  rts

_convXGY_555B_To_AYGX_8888
  INIT

  DONE
  rts

_convXGY_555B_To_YGXA_8888
  INIT

  DONE
  rts

_convXGY_555B_To_XGYA_8888
  INIT

  DONE
  rts

_convXGY_555L_To_AXGY_8888
  INIT

  DONE
  rts

_convXGY_555L_To_AYGX_8888
  INIT

  DONE
  rts

_convXGY_555L_To_YGXA_8888
  INIT

  DONE
  rts

_convXGY_555L_To_XGYA_8888
  INIT

  DONE
  rts

  END
