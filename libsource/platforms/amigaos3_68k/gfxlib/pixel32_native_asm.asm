;//****************************************************************************//
;//**                                                                        **//
;//** File:         libsrc/plat/amigaos3_68k/gfxlib/pixel16_native_asm.asm   **//
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

  XDEF _convAXGY_8888_To_XGY_555B
  XDEF _convAXGY_8888_To_XGY_555L
  XDEF _convAXGY_8888_To_YGX_555B
  XDEF _convAXGY_8888_To_YGX_555L
  XDEF _convXGYA_8888_To_XGY_555B
  XDEF _convXGYA_8888_To_XGY_555L
  XDEF _convXGYA_8888_To_YGX_555B
  XDEF _convXGYA_8888_To_YGX_555L

  XDEF _convAXGY_8888_To_XGY_565B
  XDEF _convAXGY_8888_To_XGY_565L
  XDEF _convAXGY_8888_To_YGX_565B
  XDEF _convAXGY_8888_To_YGX_565L
  XDEF _convXGYA_8888_To_XGY_565B
  XDEF _convXGYA_8888_To_XGY_565L
  XDEF _convXGYA_8888_To_YGX_565B
  XDEF _convXGYA_8888_To_YGX_565L

  XDEF _convAXGY_8888_To_XGY_888
  XDEF _convAXGY_8888_To_YGX_888
  XDEF _convXGYA_8888_To_XGY_888
  XDEF _convXGYA_8888_To_YGX_888

  XDEF _convCopy32
  XDEF _convSwap32

  XDEF _convAXGY_8888_To_AYGX_8888
  XDEF _convAXGY_8888_To_XGYA_8888
  XDEF _convXGYA_8888_To_AXGY_8888
  XDEF _convXGYA_8888_To_YGXA_8888


;////////////////////////////////////////////////////////////////////////////////
;//
;//  a0 dst
;//  a1 src
;//  d0 w[16]    : h[16]
;//  d1 dMod[16] : sMod[16]
;//
;////////////////////////////////////////////////////////////////////////////////


  SECTION "32to15bit:0",CODE

_convAXGY_8888_To_XGY_555B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convAXGY_8888_To_XGY_555L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convAXGY_8888_To_YGX_555B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convAXGY_8888_To_YGX_555L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGYA_8888_To_XGY_555B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGYA_8888_To_XGY_555L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGYA_8888_To_YGX_555B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGYA_8888_To_YGX_555L
  INIT

  DONE
  rts

  SECTION "32to16bit:0",CODE

;////////////////////////////////////////////////////////////////////////////////

_convAXGY_8888_To_XGY_565B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convAXGY_8888_To_XGY_565L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convAXGY_8888_To_YGX_565B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convAXGY_8888_To_YGX_565L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGYA_8888_To_XGY_565B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGYA_8888_To_XGY_565L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGYA_8888_To_YGX_565B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGYA_8888_To_YGX_565L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

  SECTION "32to24bit:0",CODE

_convAXGY_8888_To_XGY_888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convAXGY_8888_To_YGX_888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGYA_8888_To_XGY_888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGYA_8888_To_YGX_888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

  SECTION "32to32bit:0",CODE

_convCopy32
  COPY_PIXELS 4
  rts

;////////////////////////////////////////////////////////////////////////////////

_convSwap32
  BSWAP_PIXELS 4
  rts

;////////////////////////////////////////////////////////////////////////////////

_convAXGY_8888_To_AYGX_8888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convAXGY_8888_To_XGYA_8888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGYA_8888_To_AXGY_8888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGYA_8888_To_YGXA_8888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

  END
