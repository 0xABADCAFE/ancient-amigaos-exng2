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

  XDEF _convXGY_565B_To_XGY_555B
  XDEF _convXGY_565B_To_XGY_555L
  XDEF _convXGY_565L_To_XGY_555B
  XDEF _convXGY_565L_To_XGY_555L
  XDEF _convXGY_565B_To_YGX_555B
  XDEF _convXGY_565B_To_YGX_555L
  XDEF _convXGY_565L_To_YGX_555B
  XDEF _convXGY_565L_To_YGX_555L

  XDEF _convXGY_565B_To_YGX_565B
  XDEF _convXGY_565B_To_YGX_565L
  XDEF _convXGY_565L_To_YGX_565B
  XDEF _convXGY_565L_To_YGX_565L

  XDEF _convXGY_565B_To_XGY_888
  XDEF _convXGY_565L_To_XGY_888
  XDEF _convXGY_565B_To_YGX_888
  XDEF _convXGY_565L_To_YGX_888

  XDEF _convXGY_565B_To_AXGY_8888
  XDEF _convXGY_565B_To_AYGX_8888
  XDEF _convXGY_565B_To_YGXA_8888
  XDEF _convXGY_565B_To_XGYA_8888
  XDEF _convXGY_565L_To_AXGY_8888
  XDEF _convXGY_565L_To_AYGX_8888
  XDEF _convXGY_565L_To_YGXA_8888
  XDEF _convXGY_565L_To_XGYA_8888


;////////////////////////////////////////////////////////////////////////////////
;//
;//  a0 dst
;//  a1 src
;//  d0 w[16]    : h[16]
;//  d1 dMod[16] : sMod[16]
;//
;////////////////////////////////////////////////////////////////////////////////


  SECTION "16to15bit:0",CODE

_convXGY_565B_To_XGY_555B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565B_To_XGY_555L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565L_To_XGY_555B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565L_To_XGY_555L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565B_To_YGX_555B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565B_To_YGX_555L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565L_To_YGX_555B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565L_To_YGX_555L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

  SECTION "16to16bit:0",CODE

_convXGY_565B_To_YGX_565B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565B_To_YGX_565L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565L_To_YGX_565B
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565L_To_YGX_565L
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

  SECTION "16to24bit:0",CODE

_convXGY_565B_To_XGY_888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565L_To_XGY_888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565B_To_YGX_888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565L_To_YGX_888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

  SECTION "16to32bit:0",CODE

_convXGY_565B_To_AXGY_8888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565B_To_AYGX_8888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565B_To_YGXA_8888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565B_To_XGYA_8888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565L_To_AXGY_8888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565L_To_AYGX_8888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565L_To_YGXA_8888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

_convXGY_565L_To_XGYA_8888
  INIT

  DONE
  rts

;////////////////////////////////////////////////////////////////////////////////

  END
