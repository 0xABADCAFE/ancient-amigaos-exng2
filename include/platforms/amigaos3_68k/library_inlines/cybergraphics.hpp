#ifndef _INLINE_AMIGA_CYBERGRAPHICS_HPP_
#define _INLINE_AMIGA_CYBERGRAPHICS_HPP_
inline BOOL IsCyberModeID( displayID)
{
	// LVO: -54
	// displayID [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register  reg_d0 __asm("d0") = displayID;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# BOOL IsCyberModeID([d0]  displayID)\n\t"
		"jsr -54(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG BestCModeIDTagList(struct TagItem* BestModeIDTags)
{
	// LVO: -60
	// BestModeIDTags [a0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct TagItem* reg_a0 __asm("a0") = BestModeIDTags;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# ULONG BestCModeIDTagList([a0] struct TagItem* BestModeIDTags)\n\t"
		"jsr -60(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG CModeRequestTagList( ModeRequest, struct TagItem* ModeRequestTags)
{
	// LVO: -66
	// ModeRequest [a0]
	// ModeRequestTags [a1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register  reg_a0 __asm("a0") = ModeRequest;
	register struct TagItem* reg_a1 __asm("a1") = ModeRequestTags;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# ULONG CModeRequestTagList([a0]  ModeRequest, [a1] struct TagItem* ModeRequestTags)\n\t"
		"jsr -66(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline void FreeCModeList(struct List* ModeList)
{
	// LVO: -78
	// ModeList [a0]
	// ret: void [d0]

	register void retVal __asm("d0");

	register struct List* reg_a0 __asm("a0") = ModeList;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# void FreeCModeList([a0] struct List* ModeList)\n\t"
		"jsr -78(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG ScalePixelArray( srcRect,  SrcW,  SrcH,  SrcMod, struct RastPort* RastPort,  DestX,  DestY,  DestW,  DestH,  SrcFormat)
{
	// LVO: -90
	// srcRect [a0]
	// SrcW [d0]
	// SrcH [d1]
	// SrcMod [d2]
	// RastPort [a1]
	// DestX [d3]
	// DestY [d4]
	// DestW [d5]
	// DestH [d6]
	// SrcFormat [d7]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register  reg_a0 __asm("a0") = srcRect;
	register  reg_d0 __asm("d0") = SrcW;
	register  reg_d1 __asm("d1") = SrcH;
	register  reg_d2 __asm("d2") = SrcMod;
	register struct RastPort* reg_a1 __asm("a1") = RastPort;
	register  reg_d3 __asm("d3") = DestX;
	register  reg_d4 __asm("d4") = DestY;
	register  reg_d5 __asm("d5") = DestW;
	register  reg_d6 __asm("d6") = DestH;
	register  reg_d7 __asm("d7") = SrcFormat;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# LONG ScalePixelArray([a0]  srcRect, [d0]  SrcW, [d1]  SrcH, [d2]  SrcMod, [a1] struct RastPort* RastPort, [d3]  DestX, [d4]  DestY, [d5]  DestW, [d6]  DestH, [d7]  SrcFormat)\n\t"
		"jsr -90(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a1),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_d6),"r"(reg_d7),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5", "d6", "d7"
	);
	return retVal;
}

inline ULONG GetCyberMapAttr(struct BitMap* CyberGfxBitmap,  CyberAttrTag)
{
	// LVO: -96
	// CyberGfxBitmap [a0]
	// CyberAttrTag [d0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct BitMap* reg_a0 __asm("a0") = CyberGfxBitmap;
	register  reg_d0 __asm("d0") = CyberAttrTag;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# ULONG GetCyberMapAttr([a0] struct BitMap* CyberGfxBitmap, [d0]  CyberAttrTag)\n\t"
		"jsr -96(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG GetCyberIDAttr( CyberIDAttr,  CyberDisplayModeID)
{
	// LVO: -102
	// CyberIDAttr [d0]
	// CyberDisplayModeID [d1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register  reg_d0 __asm("d0") = CyberIDAttr;
	register  reg_d1 __asm("d1") = CyberDisplayModeID;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# ULONG GetCyberIDAttr([d0]  CyberIDAttr, [d1]  CyberDisplayModeID)\n\t"
		"jsr -102(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG ReadRGBPixel(struct RastPort* RastPort,  x,  y)
{
	// LVO: -108
	// RastPort [a1]
	// x [d0]
	// y [d1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = RastPort;
	register  reg_d0 __asm("d0") = x;
	register  reg_d1 __asm("d1") = y;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# ULONG ReadRGBPixel([a1] struct RastPort* RastPort, [d0]  x, [d1]  y)\n\t"
		"jsr -108(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG WriteRGBPixel(struct RastPort* RastPort,  x,  y,  argb)
{
	// LVO: -114
	// RastPort [a1]
	// x [d0]
	// y [d1]
	// argb [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = RastPort;
	register  reg_d0 __asm("d0") = x;
	register  reg_d1 __asm("d1") = y;
	register  reg_d2 __asm("d2") = argb;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# LONG WriteRGBPixel([a1] struct RastPort* RastPort, [d0]  x, [d1]  y, [d2]  argb)\n\t"
		"jsr -114(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline ULONG ReadPixelArray( destRect,  destX,  destY,  destMod, struct RastPort* RastPort,  SrcX,  SrcY,  SizeX,  SizeY,  DestFormat)
{
	// LVO: -120
	// destRect [a0]
	// destX [d0]
	// destY [d1]
	// destMod [d2]
	// RastPort [a1]
	// SrcX [d3]
	// SrcY [d4]
	// SizeX [d5]
	// SizeY [d6]
	// DestFormat [d7]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register  reg_a0 __asm("a0") = destRect;
	register  reg_d0 __asm("d0") = destX;
	register  reg_d1 __asm("d1") = destY;
	register  reg_d2 __asm("d2") = destMod;
	register struct RastPort* reg_a1 __asm("a1") = RastPort;
	register  reg_d3 __asm("d3") = SrcX;
	register  reg_d4 __asm("d4") = SrcY;
	register  reg_d5 __asm("d5") = SizeX;
	register  reg_d6 __asm("d6") = SizeY;
	register  reg_d7 __asm("d7") = DestFormat;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# ULONG ReadPixelArray([a0]  destRect, [d0]  destX, [d1]  destY, [d2]  destMod, [a1] struct RastPort* RastPort, [d3]  SrcX, [d4]  SrcY, [d5]  SizeX, [d6]  SizeY, [d7]  DestFormat)\n\t"
		"jsr -120(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a1),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_d6),"r"(reg_d7),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5", "d6", "d7"
	);
	return retVal;
}

inline ULONG WritePixelArray( srcRect,  SrcX,  SrcY,  SrcMod, struct RastPort* RastPort,  DestX,  DestY,  SizeX,  SizeY,  SrcFormat)
{
	// LVO: -126
	// srcRect [a0]
	// SrcX [d0]
	// SrcY [d1]
	// SrcMod [d2]
	// RastPort [a1]
	// DestX [d3]
	// DestY [d4]
	// SizeX [d5]
	// SizeY [d6]
	// SrcFormat [d7]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register  reg_a0 __asm("a0") = srcRect;
	register  reg_d0 __asm("d0") = SrcX;
	register  reg_d1 __asm("d1") = SrcY;
	register  reg_d2 __asm("d2") = SrcMod;
	register struct RastPort* reg_a1 __asm("a1") = RastPort;
	register  reg_d3 __asm("d3") = DestX;
	register  reg_d4 __asm("d4") = DestY;
	register  reg_d5 __asm("d5") = SizeX;
	register  reg_d6 __asm("d6") = SizeY;
	register  reg_d7 __asm("d7") = SrcFormat;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# ULONG WritePixelArray([a0]  srcRect, [d0]  SrcX, [d1]  SrcY, [d2]  SrcMod, [a1] struct RastPort* RastPort, [d3]  DestX, [d4]  DestY, [d5]  SizeX, [d6]  SizeY, [d7]  SrcFormat)\n\t"
		"jsr -126(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a1),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_d6),"r"(reg_d7),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5", "d6", "d7"
	);
	return retVal;
}

inline ULONG MovePixelArray( SrcX,  SrcY, struct RastPort* RastPort,  DestX,  DestY,  SizeX,  SizeY)
{
	// LVO: -132
	// SrcX [d0]
	// SrcY [d1]
	// RastPort [a1]
	// DestX [d2]
	// DestY [d3]
	// SizeX [d4]
	// SizeY [d5]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register  reg_d0 __asm("d0") = SrcX;
	register  reg_d1 __asm("d1") = SrcY;
	register struct RastPort* reg_a1 __asm("a1") = RastPort;
	register  reg_d2 __asm("d2") = DestX;
	register  reg_d3 __asm("d3") = DestY;
	register  reg_d4 __asm("d4") = SizeX;
	register  reg_d5 __asm("d5") = SizeY;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# ULONG MovePixelArray([d0]  SrcX, [d1]  SrcY, [a1] struct RastPort* RastPort, [d2]  DestX, [d3]  DestY, [d4]  SizeX, [d5]  SizeY)\n\t"
		"jsr -132(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_a1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5"
	);
	return retVal;
}

inline ULONG InvertPixelArray(struct RastPort* RastPort,  DestX,  DestY,  SizeX,  SizeY)
{
	// LVO: -144
	// RastPort [a1]
	// DestX [d0]
	// DestY [d1]
	// SizeX [d2]
	// SizeY [d3]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = RastPort;
	register  reg_d0 __asm("d0") = DestX;
	register  reg_d1 __asm("d1") = DestY;
	register  reg_d2 __asm("d2") = SizeX;
	register  reg_d3 __asm("d3") = SizeY;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# ULONG InvertPixelArray([a1] struct RastPort* RastPort, [d0]  DestX, [d1]  DestY, [d2]  SizeX, [d3]  SizeY)\n\t"
		"jsr -144(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline ULONG FillPixelArray(struct RastPort* RastPort,  DestX,  DestY,  SizeX,  SizeY,  ARGB)
{
	// LVO: -150
	// RastPort [a1]
	// DestX [d0]
	// DestY [d1]
	// SizeX [d2]
	// SizeY [d3]
	// ARGB [d4]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = RastPort;
	register  reg_d0 __asm("d0") = DestX;
	register  reg_d1 __asm("d1") = DestY;
	register  reg_d2 __asm("d2") = SizeX;
	register  reg_d3 __asm("d3") = SizeY;
	register  reg_d4 __asm("d4") = ARGB;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# ULONG FillPixelArray([a1] struct RastPort* RastPort, [d0]  DestX, [d1]  DestY, [d2]  SizeX, [d3]  SizeY, [d4]  ARGB)\n\t"
		"jsr -150(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4"
	);
	return retVal;
}

inline void DoCDrawMethodTagList(struct Hook* Hook, struct RastPort* RastPort, struct TagItem* TagList)
{
	// LVO: -156
	// Hook [a0]
	// RastPort [a1]
	// TagList [a2]
	// ret: void [d0]

	register void retVal __asm("d0");

	register struct Hook* reg_a0 __asm("a0") = Hook;
	register struct RastPort* reg_a1 __asm("a1") = RastPort;
	register struct TagItem* reg_a2 __asm("a2") = TagList;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# void DoCDrawMethodTagList([a0] struct Hook* Hook, [a1] struct RastPort* RastPort, [a2] struct TagItem* TagList)\n\t"
		"jsr -156(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
	return retVal;
}

inline void CVideoCtrlTagList(struct ViewPort* ViewPort, struct TagItem* TagList)
{
	// LVO: -162
	// ViewPort [a0]
	// TagList [a1]
	// ret: void [d0]

	register void retVal __asm("d0");

	register struct ViewPort* reg_a0 __asm("a0") = ViewPort;
	register struct TagItem* reg_a1 __asm("a1") = TagList;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# void CVideoCtrlTagList([a0] struct ViewPort* ViewPort, [a1] struct TagItem* TagList)\n\t"
		"jsr -162(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline APTR LockBitMapTagList( BitMap, struct TagItem* TagList)
{
	// LVO: -168
	// BitMap [a0]
	// TagList [a1]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register  reg_a0 __asm("a0") = BitMap;
	register struct TagItem* reg_a1 __asm("a1") = TagList;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# APTR LockBitMapTagList([a0]  BitMap, [a1] struct TagItem* TagList)\n\t"
		"jsr -168(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline void UnLockBitMap( Handle)
{
	// LVO: -174
	// Handle [a0]
	// ret: void [d0]

	register void retVal __asm("d0");

	register  reg_a0 __asm("a0") = Handle;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# void UnLockBitMap([a0]  Handle)\n\t"
		"jsr -174(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline void UnLockBitMapTagList( Handle, struct TagItem* TagList)
{
	// LVO: -180
	// Handle [a0]
	// TagList [a1]
	// ret: void [d0]

	register void retVal __asm("d0");

	register  reg_a0 __asm("a0") = Handle;
	register struct TagItem* reg_a1 __asm("a1") = TagList;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# void UnLockBitMapTagList([a0]  Handle, [a1] struct TagItem* TagList)\n\t"
		"jsr -180(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG ExtractColor(struct RastPort* RastPort, struct BitMap* BitMap,  Colour,  SrcX,  SrcY,  Width,  Height)
{
	// LVO: -186
	// RastPort [A0]
	// BitMap [A1]
	// Colour [D0]
	// SrcX [D1]
	// SrcY [D2]
	// Width [D3]
	// Height [D4]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_A0 __asm("A0") = RastPort;
	register struct BitMap* reg_A1 __asm("A1") = BitMap;
	register  reg_D0 __asm("D0") = Colour;
	register  reg_D1 __asm("D1") = SrcX;
	register  reg_D2 __asm("D2") = SrcY;
	register  reg_D3 __asm("D3") = Width;
	register  reg_D4 __asm("D4") = Height;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# ULONG ExtractColor([A0] struct RastPort* RastPort, [A1] struct BitMap* BitMap, [D0]  Colour, [D1]  SrcX, [D2]  SrcY, [D3]  Width, [D4]  Height)\n\t"
		"jsr -186(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_A0),"r"(reg_A1),"r"(reg_D0),"r"(reg_D1),"r"(reg_D2),"r"(reg_D3),"r"(reg_D4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "A0", "A1", "D0", "D1", "D2", "D3", "D4"
	);
	return retVal;
}

inline ULONG WriteLUTPixelArray( srcRect,  SrcX,  SrcY,  SrcMod, struct RastPort* RastPort,  ColorTab,  DestX,  DestY,  SizeX,  SizeY,  CTFormat)
{
	// LVO: -198
	// srcRect [a0]
	// SrcX [d0]
	// SrcY [d1]
	// SrcMod [d2]
	// RastPort [a1]
	// ColorTab [a2]
	// DestX [d3]
	// DestY [d4]
	// SizeX [d5]
	// SizeY [d6]
	// CTFormat [d7]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register  reg_a0 __asm("a0") = srcRect;
	register  reg_d0 __asm("d0") = SrcX;
	register  reg_d1 __asm("d1") = SrcY;
	register  reg_d2 __asm("d2") = SrcMod;
	register struct RastPort* reg_a1 __asm("a1") = RastPort;
	register  reg_a2 __asm("a2") = ColorTab;
	register  reg_d3 __asm("d3") = DestX;
	register  reg_d4 __asm("d4") = DestY;
	register  reg_d5 __asm("d5") = SizeX;
	register  reg_d6 __asm("d6") = SizeY;
	register  reg_d7 __asm("d7") = CTFormat;
	register void* reg_a6 __asm("a6") = CyberGfxBase;
	__asm volatile (
		"# ULONG WriteLUTPixelArray([a0]  srcRect, [d0]  SrcX, [d1]  SrcY, [d2]  SrcMod, [a1] struct RastPort* RastPort, [a2]  ColorTab, [d3]  DestX, [d4]  DestY, [d5]  SizeX, [d6]  SizeY, [d7]  CTFormat)\n\t"
		"jsr -198(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a1),"r"(reg_a2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_d6),"r"(reg_d7),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "a2", "d3", "d4", "d5", "d6", "d7"
	);
	return retVal;
}

#endif
