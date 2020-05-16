#ifndef _INLINE_AMIGA_GRAPHICS_HPP_
#define _INLINE_AMIGA_GRAPHICS_HPP_
inline LONG BltBitMap(CONST struct BitMap* srcBitMap, LONG xSrc, LONG ySrc, struct BitMap* destBitMap, LONG xDest, LONG yDest, LONG xSize, LONG ySize, ULONG minterm, ULONG mask, PLANEPTR tempA)
{
	// LVO: -30
	// srcBitMap [a0]
	// xSrc [d0]
	// ySrc [d1]
	// destBitMap [a1]
	// xDest [d2]
	// yDest [d3]
	// xSize [d4]
	// ySize [d5]
	// minterm [d6]
	// mask [d7]
	// tempA [a2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST struct BitMap* reg_a0 __asm("a0") = srcBitMap;
	register LONG reg_d0 __asm("d0") = xSrc;
	register LONG reg_d1 __asm("d1") = ySrc;
	register struct BitMap* reg_a1 __asm("a1") = destBitMap;
	register LONG reg_d2 __asm("d2") = xDest;
	register LONG reg_d3 __asm("d3") = yDest;
	register LONG reg_d4 __asm("d4") = xSize;
	register LONG reg_d5 __asm("d5") = ySize;
	register ULONG reg_d6 __asm("d6") = minterm;
	register ULONG reg_d7 __asm("d7") = mask;
	register PLANEPTR reg_a2 __asm("a2") = tempA;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG BltBitMap([a0] CONST struct BitMap* srcBitMap, [d0] LONG xSrc, [d1] LONG ySrc, [a1] struct BitMap* destBitMap, [d2] LONG xDest, [d3] LONG yDest, [d4] LONG xSize, [d5] LONG ySize, [d6] ULONG minterm, [d7] ULONG mask, [a2] PLANEPTR tempA)\n\t"
		"jsr -30(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_d6),"r"(reg_d7),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5", "d6", "d7", "a2"
	);
	return retVal;
}

inline VOID BltTemplate(CONST PLANEPTR source, LONG xSrc, LONG srcMod, struct RastPort* destRP, LONG xDest, LONG yDest, LONG xSize, LONG ySize)
{
	// LVO: -36
	// source [a0]
	// xSrc [d0]
	// srcMod [d1]
	// destRP [a1]
	// xDest [d2]
	// yDest [d3]
	// xSize [d4]
	// ySize [d5]

	register CONST PLANEPTR reg_a0 __asm("a0") = source;
	register LONG reg_d0 __asm("d0") = xSrc;
	register LONG reg_d1 __asm("d1") = srcMod;
	register struct RastPort* reg_a1 __asm("a1") = destRP;
	register LONG reg_d2 __asm("d2") = xDest;
	register LONG reg_d3 __asm("d3") = yDest;
	register LONG reg_d4 __asm("d4") = xSize;
	register LONG reg_d5 __asm("d5") = ySize;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID BltTemplate([a0] CONST PLANEPTR source, [d0] LONG xSrc, [d1] LONG srcMod, [a1] struct RastPort* destRP, [d2] LONG xDest, [d3] LONG yDest, [d4] LONG xSize, [d5] LONG ySize)\n\t"
		"jsr -36(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5"
	);
}

inline VOID ClearEOL(struct RastPort* rp)
{
	// LVO: -42
	// rp [a1]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID ClearEOL([a1] struct RastPort* rp)\n\t"
		"jsr -42(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ClearScreen(struct RastPort* rp)
{
	// LVO: -48
	// rp [a1]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID ClearScreen([a1] struct RastPort* rp)\n\t"
		"jsr -48(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline WORD TextLength(struct RastPort* rp, CONST_STRPTR string, ULONG count)
{
	// LVO: -54
	// rp [a1]
	// string [a0]
	// count [d0]
	// ret: WORD [d0]

	register WORD retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register CONST_STRPTR reg_a0 __asm("a0") = string;
	register ULONG reg_d0 __asm("d0") = count;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# WORD TextLength([a1] struct RastPort* rp, [a0] CONST_STRPTR string, [d0] ULONG count)\n\t"
		"jsr -54(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG Text(struct RastPort* rp, CONST_STRPTR string, ULONG count)
{
	// LVO: -60
	// rp [a1]
	// string [a0]
	// count [d0]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register CONST_STRPTR reg_a0 __asm("a0") = string;
	register ULONG reg_d0 __asm("d0") = count;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG Text([a1] struct RastPort* rp, [a0] CONST_STRPTR string, [d0] ULONG count)\n\t"
		"jsr -60(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG SetFont(struct RastPort* rp, CONST struct TextFont* textFont)
{
	// LVO: -66
	// rp [a1]
	// textFont [a0]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register CONST struct TextFont* reg_a0 __asm("a0") = textFont;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG SetFont([a1] struct RastPort* rp, [a0] CONST struct TextFont* textFont)\n\t"
		"jsr -66(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID CloseFont(struct TextFont* textFont)
{
	// LVO: -78
	// textFont [a1]

	register struct TextFont* reg_a1 __asm("a1") = textFont;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID CloseFont([a1] struct TextFont* textFont)\n\t"
		"jsr -78(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG AskSoftStyle(struct RastPort* rp)
{
	// LVO: -84
	// rp [a1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG AskSoftStyle([a1] struct RastPort* rp)\n\t"
		"jsr -84(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG SetSoftStyle(struct RastPort* rp, ULONG style, ULONG enable)
{
	// LVO: -90
	// rp [a1]
	// style [d0]
	// enable [d1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register ULONG reg_d0 __asm("d0") = style;
	register ULONG reg_d1 __asm("d1") = enable;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG SetSoftStyle([a1] struct RastPort* rp, [d0] ULONG style, [d1] ULONG enable)\n\t"
		"jsr -90(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID AddBob(struct Bob* bob, struct RastPort* rp)
{
	// LVO: -96
	// bob [a0]
	// rp [a1]

	register struct Bob* reg_a0 __asm("a0") = bob;
	register struct RastPort* reg_a1 __asm("a1") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID AddBob([a0] struct Bob* bob, [a1] struct RastPort* rp)\n\t"
		"jsr -96(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AddVSprite(struct VSprite* vSprite, struct RastPort* rp)
{
	// LVO: -102
	// vSprite [a0]
	// rp [a1]

	register struct VSprite* reg_a0 __asm("a0") = vSprite;
	register struct RastPort* reg_a1 __asm("a1") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID AddVSprite([a0] struct VSprite* vSprite, [a1] struct RastPort* rp)\n\t"
		"jsr -102(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID DoCollision(struct RastPort* rp)
{
	// LVO: -108
	// rp [a1]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID DoCollision([a1] struct RastPort* rp)\n\t"
		"jsr -108(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID DrawGList(struct RastPort* rp, struct ViewPort* vp)
{
	// LVO: -114
	// rp [a1]
	// vp [a0]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID DrawGList([a1] struct RastPort* rp, [a0] struct ViewPort* vp)\n\t"
		"jsr -114(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID InitGels(struct VSprite* head, struct VSprite* tail, struct GelsInfo* gelsInfo)
{
	// LVO: -120
	// head [a0]
	// tail [a1]
	// gelsInfo [a2]

	register struct VSprite* reg_a0 __asm("a0") = head;
	register struct VSprite* reg_a1 __asm("a1") = tail;
	register struct GelsInfo* reg_a2 __asm("a2") = gelsInfo;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID InitGels([a0] struct VSprite* head, [a1] struct VSprite* tail, [a2] struct GelsInfo* gelsInfo)\n\t"
		"jsr -120(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline VOID InitMasks(struct VSprite* vSprite)
{
	// LVO: -126
	// vSprite [a0]

	register struct VSprite* reg_a0 __asm("a0") = vSprite;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID InitMasks([a0] struct VSprite* vSprite)\n\t"
		"jsr -126(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID RemIBob(struct Bob* bob, struct RastPort* rp, struct ViewPort* vp)
{
	// LVO: -132
	// bob [a0]
	// rp [a1]
	// vp [a2]

	register struct Bob* reg_a0 __asm("a0") = bob;
	register struct RastPort* reg_a1 __asm("a1") = rp;
	register struct ViewPort* reg_a2 __asm("a2") = vp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID RemIBob([a0] struct Bob* bob, [a1] struct RastPort* rp, [a2] struct ViewPort* vp)\n\t"
		"jsr -132(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline VOID RemVSprite(struct VSprite* vSprite)
{
	// LVO: -138
	// vSprite [a0]

	register struct VSprite* reg_a0 __asm("a0") = vSprite;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID RemVSprite([a0] struct VSprite* vSprite)\n\t"
		"jsr -138(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID SetCollision(ULONG num, VOID (*routine)(struct VSprite *gelA, struct VSprite* gelsInfo)
{
	// LVO: -144
	// num [d0]
	// routine [a0]
	// gelsInfo [a1]

	register ULONG reg_d0 __asm("d0") = num;
	register void* reg_a0 __asm("a0") = routine;
	register struct VSprite* reg_a1 __asm("a1") = gelsInfo;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SetCollision([d0] ULONG num, [a0] VOID (*routine)(struct VSprite *gelA, [a1] struct VSprite* gelsInfo)\n\t"
		"jsr -144(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID SortGList(struct RastPort* rp)
{
	// LVO: -150
	// rp [a1]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SortGList([a1] struct RastPort* rp)\n\t"
		"jsr -150(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AddAnimOb(struct AnimOb* anOb, struct AnimOb* anKey, struct RastPort* rp)
{
	// LVO: -156
	// anOb [a0]
	// anKey [a1]
	// rp [a2]

	register struct AnimOb* reg_a0 __asm("a0") = anOb;
	register struct AnimOb* reg_a1 __asm("a1") = anKey;
	register struct RastPort* reg_a2 __asm("a2") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID AddAnimOb([a0] struct AnimOb* anOb, [a1] struct AnimOb* anKey, [a2] struct RastPort* rp)\n\t"
		"jsr -156(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline VOID Animate(struct AnimOb* anKey, struct RastPort* rp)
{
	// LVO: -162
	// anKey [a0]
	// rp [a1]

	register struct AnimOb* reg_a0 __asm("a0") = anKey;
	register struct RastPort* reg_a1 __asm("a1") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID Animate([a0] struct AnimOb* anKey, [a1] struct RastPort* rp)\n\t"
		"jsr -162(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL GetGBuffers(struct AnimOb* anOb, struct RastPort* rp, LONG flag)
{
	// LVO: -168
	// anOb [a0]
	// rp [a1]
	// flag [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct AnimOb* reg_a0 __asm("a0") = anOb;
	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = flag;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# BOOL GetGBuffers([a0] struct AnimOb* anOb, [a1] struct RastPort* rp, [d0] LONG flag)\n\t"
		"jsr -168(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID InitGMasks(struct AnimOb* anOb)
{
	// LVO: -174
	// anOb [a0]

	register struct AnimOb* reg_a0 __asm("a0") = anOb;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID InitGMasks([a0] struct AnimOb* anOb)\n\t"
		"jsr -174(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID DrawEllipse(struct RastPort* rp, LONG xCenter, LONG yCenter, LONG a, LONG b)
{
	// LVO: -180
	// rp [a1]
	// xCenter [d0]
	// yCenter [d1]
	// a [d2]
	// b [d3]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = xCenter;
	register LONG reg_d1 __asm("d1") = yCenter;
	register LONG reg_d2 __asm("d2") = a;
	register LONG reg_d3 __asm("d3") = b;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID DrawEllipse([a1] struct RastPort* rp, [d0] LONG xCenter, [d1] LONG yCenter, [d2] LONG a, [d3] LONG b)\n\t"
		"jsr -180(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
}

inline LONG AreaEllipse(struct RastPort* rp, LONG xCenter, LONG yCenter, LONG a, LONG b)
{
	// LVO: -186
	// rp [a1]
	// xCenter [d0]
	// yCenter [d1]
	// a [d2]
	// b [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = xCenter;
	register LONG reg_d1 __asm("d1") = yCenter;
	register LONG reg_d2 __asm("d2") = a;
	register LONG reg_d3 __asm("d3") = b;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG AreaEllipse([a1] struct RastPort* rp, [d0] LONG xCenter, [d1] LONG yCenter, [d2] LONG a, [d3] LONG b)\n\t"
		"jsr -186(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline VOID LoadRGB4(struct ViewPort* vp, CONST UWORD* colors, LONG count)
{
	// LVO: -192
	// vp [a0]
	// colors [a1]
	// count [d0]

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register CONST UWORD* reg_a1 __asm("a1") = colors;
	register LONG reg_d0 __asm("d0") = count;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID LoadRGB4([a0] struct ViewPort* vp, [a1] CONST UWORD* colors, [d0] LONG count)\n\t"
		"jsr -192(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID InitRastPort(struct RastPort* rp)
{
	// LVO: -198
	// rp [a1]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID InitRastPort([a1] struct RastPort* rp)\n\t"
		"jsr -198(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID InitVPort(struct ViewPort* vp)
{
	// LVO: -204
	// vp [a0]

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID InitVPort([a0] struct ViewPort* vp)\n\t"
		"jsr -204(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG MrgCop(struct View* view)
{
	// LVO: -210
	// view [a1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct View* reg_a1 __asm("a1") = view;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG MrgCop([a1] struct View* view)\n\t"
		"jsr -210(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG MakeVPort(struct View* view, struct ViewPort* vp)
{
	// LVO: -216
	// view [a0]
	// vp [a1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct View* reg_a0 __asm("a0") = view;
	register struct ViewPort* reg_a1 __asm("a1") = vp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG MakeVPort([a0] struct View* view, [a1] struct ViewPort* vp)\n\t"
		"jsr -216(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID LoadView(struct View* view)
{
	// LVO: -222
	// view [a1]

	register struct View* reg_a1 __asm("a1") = view;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID LoadView([a1] struct View* view)\n\t"
		"jsr -222(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID WaitBlit()
{
	// LVO: -228

	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID WaitBlit()\n\t"
		"jsr -228(a6)\n\t"
		: 
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID SetRast(struct RastPort* rp, ULONG pen)
{
	// LVO: -234
	// rp [a1]
	// pen [d0]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register ULONG reg_d0 __asm("d0") = pen;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SetRast([a1] struct RastPort* rp, [d0] ULONG pen)\n\t"
		"jsr -234(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID Move(struct RastPort* rp, LONG x, LONG y)
{
	// LVO: -240
	// rp [a1]
	// x [d0]
	// y [d1]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = x;
	register LONG reg_d1 __asm("d1") = y;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID Move([a1] struct RastPort* rp, [d0] LONG x, [d1] LONG y)\n\t"
		"jsr -240(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID Draw(struct RastPort* rp, LONG x, LONG y)
{
	// LVO: -246
	// rp [a1]
	// x [d0]
	// y [d1]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = x;
	register LONG reg_d1 __asm("d1") = y;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID Draw([a1] struct RastPort* rp, [d0] LONG x, [d1] LONG y)\n\t"
		"jsr -246(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG AreaMove(struct RastPort* rp, LONG x, LONG y)
{
	// LVO: -252
	// rp [a1]
	// x [d0]
	// y [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = x;
	register LONG reg_d1 __asm("d1") = y;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG AreaMove([a1] struct RastPort* rp, [d0] LONG x, [d1] LONG y)\n\t"
		"jsr -252(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG AreaDraw(struct RastPort* rp, LONG x, LONG y)
{
	// LVO: -258
	// rp [a1]
	// x [d0]
	// y [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = x;
	register LONG reg_d1 __asm("d1") = y;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG AreaDraw([a1] struct RastPort* rp, [d0] LONG x, [d1] LONG y)\n\t"
		"jsr -258(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG AreaEnd(struct RastPort* rp)
{
	// LVO: -264
	// rp [a1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG AreaEnd([a1] struct RastPort* rp)\n\t"
		"jsr -264(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID WaitTOF()
{
	// LVO: -270

	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID WaitTOF()\n\t"
		"jsr -270(a6)\n\t"
		: 
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID QBlit(struct bltnode* blit)
{
	// LVO: -276
	// blit [a1]

	register struct bltnode* reg_a1 __asm("a1") = blit;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID QBlit([a1] struct bltnode* blit)\n\t"
		"jsr -276(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID InitArea(struct AreaInfo* areaInfo, APTR vectorBuffer, LONG maxVectors)
{
	// LVO: -282
	// areaInfo [a0]
	// vectorBuffer [a1]
	// maxVectors [d0]

	register struct AreaInfo* reg_a0 __asm("a0") = areaInfo;
	register APTR reg_a1 __asm("a1") = vectorBuffer;
	register LONG reg_d0 __asm("d0") = maxVectors;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID InitArea([a0] struct AreaInfo* areaInfo, [a1] APTR vectorBuffer, [d0] LONG maxVectors)\n\t"
		"jsr -282(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID SetRGB4(struct ViewPort* vp, LONG index, ULONG red, ULONG green, ULONG blue)
{
	// LVO: -288
	// vp [a0]
	// index [d0]
	// red [d1]
	// green [d2]
	// blue [d3]

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register LONG reg_d0 __asm("d0") = index;
	register ULONG reg_d1 __asm("d1") = red;
	register ULONG reg_d2 __asm("d2") = green;
	register ULONG reg_d3 __asm("d3") = blue;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SetRGB4([a0] struct ViewPort* vp, [d0] LONG index, [d1] ULONG red, [d2] ULONG green, [d3] ULONG blue)\n\t"
		"jsr -288(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
}

inline VOID QBSBlit(struct bltnode* blit)
{
	// LVO: -294
	// blit [a1]

	register struct bltnode* reg_a1 __asm("a1") = blit;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID QBSBlit([a1] struct bltnode* blit)\n\t"
		"jsr -294(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID BltClear(PLANEPTR memBlock, ULONG byteCount, ULONG flags)
{
	// LVO: -300
	// memBlock [a1]
	// byteCount [d0]
	// flags [d1]

	register PLANEPTR reg_a1 __asm("a1") = memBlock;
	register ULONG reg_d0 __asm("d0") = byteCount;
	register ULONG reg_d1 __asm("d1") = flags;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID BltClear([a1] PLANEPTR memBlock, [d0] ULONG byteCount, [d1] ULONG flags)\n\t"
		"jsr -300(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID RectFill(struct RastPort* rp, LONG xMin, LONG yMin, LONG xMax, LONG yMax)
{
	// LVO: -306
	// rp [a1]
	// xMin [d0]
	// yMin [d1]
	// xMax [d2]
	// yMax [d3]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = xMin;
	register LONG reg_d1 __asm("d1") = yMin;
	register LONG reg_d2 __asm("d2") = xMax;
	register LONG reg_d3 __asm("d3") = yMax;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID RectFill([a1] struct RastPort* rp, [d0] LONG xMin, [d1] LONG yMin, [d2] LONG xMax, [d3] LONG yMax)\n\t"
		"jsr -306(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
}

inline VOID BltPattern(struct RastPort* rp, CONST PLANEPTR mask, LONG xMin, LONG yMin, LONG xMax, LONG yMax, ULONG maskBPR)
{
	// LVO: -312
	// rp [a1]
	// mask [a0]
	// xMin [d0]
	// yMin [d1]
	// xMax [d2]
	// yMax [d3]
	// maskBPR [d4]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register CONST PLANEPTR reg_a0 __asm("a0") = mask;
	register LONG reg_d0 __asm("d0") = xMin;
	register LONG reg_d1 __asm("d1") = yMin;
	register LONG reg_d2 __asm("d2") = xMax;
	register LONG reg_d3 __asm("d3") = yMax;
	register ULONG reg_d4 __asm("d4") = maskBPR;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID BltPattern([a1] struct RastPort* rp, [a0] CONST PLANEPTR mask, [d0] LONG xMin, [d1] LONG yMin, [d2] LONG xMax, [d3] LONG yMax, [d4] ULONG maskBPR)\n\t"
		"jsr -312(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4"
	);
}

inline ULONG ReadPixel(struct RastPort* rp, LONG x, LONG y)
{
	// LVO: -318
	// rp [a1]
	// x [d0]
	// y [d1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = x;
	register LONG reg_d1 __asm("d1") = y;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG ReadPixel([a1] struct RastPort* rp, [d0] LONG x, [d1] LONG y)\n\t"
		"jsr -318(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG WritePixel(struct RastPort* rp, LONG x, LONG y)
{
	// LVO: -324
	// rp [a1]
	// x [d0]
	// y [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = x;
	register LONG reg_d1 __asm("d1") = y;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG WritePixel([a1] struct RastPort* rp, [d0] LONG x, [d1] LONG y)\n\t"
		"jsr -324(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL Flood(struct RastPort* rp, ULONG mode, LONG x, LONG y)
{
	// LVO: -330
	// rp [a1]
	// mode [d2]
	// x [d0]
	// y [d1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register ULONG reg_d2 __asm("d2") = mode;
	register LONG reg_d0 __asm("d0") = x;
	register LONG reg_d1 __asm("d1") = y;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# BOOL Flood([a1] struct RastPort* rp, [d2] ULONG mode, [d0] LONG x, [d1] LONG y)\n\t"
		"jsr -330(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d2),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline VOID PolyDraw(struct RastPort* rp, LONG count, CONST WORD* polyTable)
{
	// LVO: -336
	// rp [a1]
	// count [d0]
	// polyTable [a0]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = count;
	register CONST WORD* reg_a0 __asm("a0") = polyTable;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID PolyDraw([a1] struct RastPort* rp, [d0] LONG count, [a0] CONST WORD* polyTable)\n\t"
		"jsr -336(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID SetAPen(struct RastPort* rp, ULONG pen)
{
	// LVO: -342
	// rp [a1]
	// pen [d0]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register ULONG reg_d0 __asm("d0") = pen;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SetAPen([a1] struct RastPort* rp, [d0] ULONG pen)\n\t"
		"jsr -342(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID SetBPen(struct RastPort* rp, ULONG pen)
{
	// LVO: -348
	// rp [a1]
	// pen [d0]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register ULONG reg_d0 __asm("d0") = pen;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SetBPen([a1] struct RastPort* rp, [d0] ULONG pen)\n\t"
		"jsr -348(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID SetDrMd(struct RastPort* rp, ULONG drawMode)
{
	// LVO: -354
	// rp [a1]
	// drawMode [d0]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register ULONG reg_d0 __asm("d0") = drawMode;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SetDrMd([a1] struct RastPort* rp, [d0] ULONG drawMode)\n\t"
		"jsr -354(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID InitView(struct View* view)
{
	// LVO: -360
	// view [a1]

	register struct View* reg_a1 __asm("a1") = view;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID InitView([a1] struct View* view)\n\t"
		"jsr -360(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID CBump(struct UCopList* copList)
{
	// LVO: -366
	// copList [a1]

	register struct UCopList* reg_a1 __asm("a1") = copList;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID CBump([a1] struct UCopList* copList)\n\t"
		"jsr -366(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID CMove(struct UCopList* copList, APTR destination, LONG data)
{
	// LVO: -372
	// copList [a1]
	// destination [d0]
	// data [d1]

	register struct UCopList* reg_a1 __asm("a1") = copList;
	register APTR reg_d0 __asm("d0") = destination;
	register LONG reg_d1 __asm("d1") = data;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID CMove([a1] struct UCopList* copList, [d0] APTR destination, [d1] LONG data)\n\t"
		"jsr -372(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID CWait(struct UCopList* copList, LONG v, LONG h)
{
	// LVO: -378
	// copList [a1]
	// v [d0]
	// h [d1]

	register struct UCopList* reg_a1 __asm("a1") = copList;
	register LONG reg_d0 __asm("d0") = v;
	register LONG reg_d1 __asm("d1") = h;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID CWait([a1] struct UCopList* copList, [d0] LONG v, [d1] LONG h)\n\t"
		"jsr -378(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG VBeamPos()
{
	// LVO: -384
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG VBeamPos()\n\t"
		"jsr -384(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID InitBitMap(struct BitMap* bitMap, LONG depth, LONG width, LONG height)
{
	// LVO: -390
	// bitMap [a0]
	// depth [d0]
	// width [d1]
	// height [d2]

	register struct BitMap* reg_a0 __asm("a0") = bitMap;
	register LONG reg_d0 __asm("d0") = depth;
	register LONG reg_d1 __asm("d1") = width;
	register LONG reg_d2 __asm("d2") = height;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID InitBitMap([a0] struct BitMap* bitMap, [d0] LONG depth, [d1] LONG width, [d2] LONG height)\n\t"
		"jsr -390(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
}

inline VOID ScrollRaster(struct RastPort* rp, LONG dx, LONG dy, LONG xMin, LONG yMin, LONG xMax, LONG yMax)
{
	// LVO: -396
	// rp [a1]
	// dx [d0]
	// dy [d1]
	// xMin [d2]
	// yMin [d3]
	// xMax [d4]
	// yMax [d5]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = dx;
	register LONG reg_d1 __asm("d1") = dy;
	register LONG reg_d2 __asm("d2") = xMin;
	register LONG reg_d3 __asm("d3") = yMin;
	register LONG reg_d4 __asm("d4") = xMax;
	register LONG reg_d5 __asm("d5") = yMax;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID ScrollRaster([a1] struct RastPort* rp, [d0] LONG dx, [d1] LONG dy, [d2] LONG xMin, [d3] LONG yMin, [d4] LONG xMax, [d5] LONG yMax)\n\t"
		"jsr -396(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5"
	);
}

inline VOID WaitBOVP(struct ViewPort* vp)
{
	// LVO: -402
	// vp [a0]

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID WaitBOVP([a0] struct ViewPort* vp)\n\t"
		"jsr -402(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline WORD GetSprite(struct SimpleSprite* sprite, LONG num)
{
	// LVO: -408
	// sprite [a0]
	// num [d0]
	// ret: WORD [d0]

	register WORD retVal __asm("d0");

	register struct SimpleSprite* reg_a0 __asm("a0") = sprite;
	register LONG reg_d0 __asm("d0") = num;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# WORD GetSprite([a0] struct SimpleSprite* sprite, [d0] LONG num)\n\t"
		"jsr -408(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreeSprite(LONG num)
{
	// LVO: -414
	// num [d0]

	register LONG reg_d0 __asm("d0") = num;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID FreeSprite([d0] LONG num)\n\t"
		"jsr -414(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ChangeSprite(struct ViewPort* vp, struct SimpleSprite* sprite, UWORD* newData)
{
	// LVO: -420
	// vp [a0]
	// sprite [a1]
	// newData [a2]

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register struct SimpleSprite* reg_a1 __asm("a1") = sprite;
	register UWORD* reg_a2 __asm("a2") = newData;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID ChangeSprite([a0] struct ViewPort* vp, [a1] struct SimpleSprite* sprite, [a2] UWORD* newData)\n\t"
		"jsr -420(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline VOID MoveSprite(struct ViewPort* vp, struct SimpleSprite* sprite, LONG x, LONG y)
{
	// LVO: -426
	// vp [a0]
	// sprite [a1]
	// x [d0]
	// y [d1]

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register struct SimpleSprite* reg_a1 __asm("a1") = sprite;
	register LONG reg_d0 __asm("d0") = x;
	register LONG reg_d1 __asm("d1") = y;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID MoveSprite([a0] struct ViewPort* vp, [a1] struct SimpleSprite* sprite, [d0] LONG x, [d1] LONG y)\n\t"
		"jsr -426(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID LockLayerRom(struct Layer* layer)
{
	// LVO: -432
	// layer [a5]

	register struct Layer* reg_a5 __asm("a5") = layer;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID LockLayerRom([a5] struct Layer* layer)\n\t"
		"jsr -432(a6)\n\t"
		: 
		: "r"(reg_a5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a5"
	);
}

inline VOID UnlockLayerRom(struct Layer* layer)
{
	// LVO: -438
	// layer [a5]

	register struct Layer* reg_a5 __asm("a5") = layer;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID UnlockLayerRom([a5] struct Layer* layer)\n\t"
		"jsr -438(a6)\n\t"
		: 
		: "r"(reg_a5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a5"
	);
}

inline VOID SyncSBitMap(struct Layer* layer)
{
	// LVO: -444
	// layer [a0]

	register struct Layer* reg_a0 __asm("a0") = layer;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SyncSBitMap([a0] struct Layer* layer)\n\t"
		"jsr -444(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID CopySBitMap(struct Layer* layer)
{
	// LVO: -450
	// layer [a0]

	register struct Layer* reg_a0 __asm("a0") = layer;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID CopySBitMap([a0] struct Layer* layer)\n\t"
		"jsr -450(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID OwnBlitter()
{
	// LVO: -456

	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID OwnBlitter()\n\t"
		"jsr -456(a6)\n\t"
		: 
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID DisownBlitter()
{
	// LVO: -462

	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID DisownBlitter()\n\t"
		"jsr -462(a6)\n\t"
		: 
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AskFont(struct RastPort* rp, struct TextAttr* textAttr)
{
	// LVO: -474
	// rp [a1]
	// textAttr [a0]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register struct TextAttr* reg_a0 __asm("a0") = textAttr;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID AskFont([a1] struct RastPort* rp, [a0] struct TextAttr* textAttr)\n\t"
		"jsr -474(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AddFont(struct TextFont* textFont)
{
	// LVO: -480
	// textFont [a1]

	register struct TextFont* reg_a1 __asm("a1") = textFont;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID AddFont([a1] struct TextFont* textFont)\n\t"
		"jsr -480(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID RemFont(struct TextFont* textFont)
{
	// LVO: -486
	// textFont [a1]

	register struct TextFont* reg_a1 __asm("a1") = textFont;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID RemFont([a1] struct TextFont* textFont)\n\t"
		"jsr -486(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline PLANEPTR AllocRaster(ULONG width, ULONG height)
{
	// LVO: -492
	// width [d0]
	// height [d1]
	// ret: PLANEPTR [d0]

	register PLANEPTR retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = width;
	register ULONG reg_d1 __asm("d1") = height;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# PLANEPTR AllocRaster([d0] ULONG width, [d1] ULONG height)\n\t"
		"jsr -492(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreeRaster(PLANEPTR p, ULONG width, ULONG height)
{
	// LVO: -498
	// p [a0]
	// width [d0]
	// height [d1]

	register PLANEPTR reg_a0 __asm("a0") = p;
	register ULONG reg_d0 __asm("d0") = width;
	register ULONG reg_d1 __asm("d1") = height;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID FreeRaster([a0] PLANEPTR p, [d0] ULONG width, [d1] ULONG height)\n\t"
		"jsr -498(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AndRectRegion(struct Region* region, CONST struct Rectangle* rectangle)
{
	// LVO: -504
	// region [a0]
	// rectangle [a1]

	register struct Region* reg_a0 __asm("a0") = region;
	register CONST struct Rectangle* reg_a1 __asm("a1") = rectangle;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID AndRectRegion([a0] struct Region* region, [a1] CONST struct Rectangle* rectangle)\n\t"
		"jsr -504(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL OrRectRegion(struct Region* region, CONST struct Rectangle* rectangle)
{
	// LVO: -510
	// region [a0]
	// rectangle [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Region* reg_a0 __asm("a0") = region;
	register CONST struct Rectangle* reg_a1 __asm("a1") = rectangle;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# BOOL OrRectRegion([a0] struct Region* region, [a1] CONST struct Rectangle* rectangle)\n\t"
		"jsr -510(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL ClearRectRegion(struct Region* region, CONST struct Rectangle* rectangle)
{
	// LVO: -522
	// region [a0]
	// rectangle [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Region* reg_a0 __asm("a0") = region;
	register CONST struct Rectangle* reg_a1 __asm("a1") = rectangle;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# BOOL ClearRectRegion([a0] struct Region* region, [a1] CONST struct Rectangle* rectangle)\n\t"
		"jsr -522(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ClearRegion(struct Region* region)
{
	// LVO: -528
	// region [a0]

	register struct Region* reg_a0 __asm("a0") = region;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID ClearRegion([a0] struct Region* region)\n\t"
		"jsr -528(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID DisposeRegion(struct Region* region)
{
	// LVO: -534
	// region [a0]

	register struct Region* reg_a0 __asm("a0") = region;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID DisposeRegion([a0] struct Region* region)\n\t"
		"jsr -534(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID FreeVPortCopLists(struct ViewPort* vp)
{
	// LVO: -540
	// vp [a0]

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID FreeVPortCopLists([a0] struct ViewPort* vp)\n\t"
		"jsr -540(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID FreeCopList(struct CopList* copList)
{
	// LVO: -546
	// copList [a0]

	register struct CopList* reg_a0 __asm("a0") = copList;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID FreeCopList([a0] struct CopList* copList)\n\t"
		"jsr -546(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ClipBlit(struct RastPort* srcRP, LONG xSrc, LONG ySrc, struct RastPort* destRP, LONG xDest, LONG yDest, LONG xSize, LONG ySize, ULONG minterm)
{
	// LVO: -552
	// srcRP [a0]
	// xSrc [d0]
	// ySrc [d1]
	// destRP [a1]
	// xDest [d2]
	// yDest [d3]
	// xSize [d4]
	// ySize [d5]
	// minterm [d6]

	register struct RastPort* reg_a0 __asm("a0") = srcRP;
	register LONG reg_d0 __asm("d0") = xSrc;
	register LONG reg_d1 __asm("d1") = ySrc;
	register struct RastPort* reg_a1 __asm("a1") = destRP;
	register LONG reg_d2 __asm("d2") = xDest;
	register LONG reg_d3 __asm("d3") = yDest;
	register LONG reg_d4 __asm("d4") = xSize;
	register LONG reg_d5 __asm("d5") = ySize;
	register ULONG reg_d6 __asm("d6") = minterm;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID ClipBlit([a0] struct RastPort* srcRP, [d0] LONG xSrc, [d1] LONG ySrc, [a1] struct RastPort* destRP, [d2] LONG xDest, [d3] LONG yDest, [d4] LONG xSize, [d5] LONG ySize, [d6] ULONG minterm)\n\t"
		"jsr -552(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_d6),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5", "d6"
	);
}

inline BOOL XorRectRegion(struct Region* region, CONST struct Rectangle* rectangle)
{
	// LVO: -558
	// region [a0]
	// rectangle [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Region* reg_a0 __asm("a0") = region;
	register CONST struct Rectangle* reg_a1 __asm("a1") = rectangle;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# BOOL XorRectRegion([a0] struct Region* region, [a1] CONST struct Rectangle* rectangle)\n\t"
		"jsr -558(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreeCprList(struct cprlist* cprList)
{
	// LVO: -564
	// cprList [a0]

	register struct cprlist* reg_a0 __asm("a0") = cprList;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID FreeCprList([a0] struct cprlist* cprList)\n\t"
		"jsr -564(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID FreeColorMap(struct ColorMap* colorMap)
{
	// LVO: -576
	// colorMap [a0]

	register struct ColorMap* reg_a0 __asm("a0") = colorMap;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID FreeColorMap([a0] struct ColorMap* colorMap)\n\t"
		"jsr -576(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG GetRGB4(struct ColorMap* colorMap, LONG entry)
{
	// LVO: -582
	// colorMap [a0]
	// entry [d0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct ColorMap* reg_a0 __asm("a0") = colorMap;
	register LONG reg_d0 __asm("d0") = entry;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG GetRGB4([a0] struct ColorMap* colorMap, [d0] LONG entry)\n\t"
		"jsr -582(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ScrollVPort(struct ViewPort* vp)
{
	// LVO: -588
	// vp [a0]

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID ScrollVPort([a0] struct ViewPort* vp)\n\t"
		"jsr -588(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID FreeGBuffers(struct AnimOb* anOb, struct RastPort* rp, LONG flag)
{
	// LVO: -600
	// anOb [a0]
	// rp [a1]
	// flag [d0]

	register struct AnimOb* reg_a0 __asm("a0") = anOb;
	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = flag;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID FreeGBuffers([a0] struct AnimOb* anOb, [a1] struct RastPort* rp, [d0] LONG flag)\n\t"
		"jsr -600(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID BltBitMapRastPort(CONST struct BitMap* srcBitMap, LONG xSrc, LONG ySrc, struct RastPort* destRP, LONG xDest, LONG yDest, LONG xSize, LONG ySize, ULONG minterm)
{
	// LVO: -606
	// srcBitMap [a0]
	// xSrc [d0]
	// ySrc [d1]
	// destRP [a1]
	// xDest [d2]
	// yDest [d3]
	// xSize [d4]
	// ySize [d5]
	// minterm [d6]

	register CONST struct BitMap* reg_a0 __asm("a0") = srcBitMap;
	register LONG reg_d0 __asm("d0") = xSrc;
	register LONG reg_d1 __asm("d1") = ySrc;
	register struct RastPort* reg_a1 __asm("a1") = destRP;
	register LONG reg_d2 __asm("d2") = xDest;
	register LONG reg_d3 __asm("d3") = yDest;
	register LONG reg_d4 __asm("d4") = xSize;
	register LONG reg_d5 __asm("d5") = ySize;
	register ULONG reg_d6 __asm("d6") = minterm;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID BltBitMapRastPort([a0] CONST struct BitMap* srcBitMap, [d0] LONG xSrc, [d1] LONG ySrc, [a1] struct RastPort* destRP, [d2] LONG xDest, [d3] LONG yDest, [d4] LONG xSize, [d5] LONG ySize, [d6] ULONG minterm)\n\t"
		"jsr -606(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_d6),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5", "d6"
	);
}

inline BOOL OrRegionRegion(CONST struct Region* srcRegion, struct Region* destRegion)
{
	// LVO: -612
	// srcRegion [a0]
	// destRegion [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST struct Region* reg_a0 __asm("a0") = srcRegion;
	register struct Region* reg_a1 __asm("a1") = destRegion;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# BOOL OrRegionRegion([a0] CONST struct Region* srcRegion, [a1] struct Region* destRegion)\n\t"
		"jsr -612(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL XorRegionRegion(CONST struct Region* srcRegion, struct Region* destRegion)
{
	// LVO: -618
	// srcRegion [a0]
	// destRegion [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST struct Region* reg_a0 __asm("a0") = srcRegion;
	register struct Region* reg_a1 __asm("a1") = destRegion;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# BOOL XorRegionRegion([a0] CONST struct Region* srcRegion, [a1] struct Region* destRegion)\n\t"
		"jsr -618(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL AndRegionRegion(CONST struct Region* srcRegion, struct Region* destRegion)
{
	// LVO: -624
	// srcRegion [a0]
	// destRegion [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST struct Region* reg_a0 __asm("a0") = srcRegion;
	register struct Region* reg_a1 __asm("a1") = destRegion;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# BOOL AndRegionRegion([a0] CONST struct Region* srcRegion, [a1] struct Region* destRegion)\n\t"
		"jsr -624(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID SetRGB4CM(struct ColorMap* colorMap, LONG index, ULONG red, ULONG green, ULONG blue)
{
	// LVO: -630
	// colorMap [a0]
	// index [d0]
	// red [d1]
	// green [d2]
	// blue [d3]

	register struct ColorMap* reg_a0 __asm("a0") = colorMap;
	register LONG reg_d0 __asm("d0") = index;
	register ULONG reg_d1 __asm("d1") = red;
	register ULONG reg_d2 __asm("d2") = green;
	register ULONG reg_d3 __asm("d3") = blue;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SetRGB4CM([a0] struct ColorMap* colorMap, [d0] LONG index, [d1] ULONG red, [d2] ULONG green, [d3] ULONG blue)\n\t"
		"jsr -630(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
}

inline VOID BltMaskBitMapRastPort(CONST struct BitMap* srcBitMap, LONG xSrc, LONG ySrc, struct RastPort* destRP, LONG xDest, LONG yDest, LONG xSize, LONG ySize, ULONG minterm, CONST PLANEPTR bltMask)
{
	// LVO: -636
	// srcBitMap [a0]
	// xSrc [d0]
	// ySrc [d1]
	// destRP [a1]
	// xDest [d2]
	// yDest [d3]
	// xSize [d4]
	// ySize [d5]
	// minterm [d6]
	// bltMask [a2]

	register CONST struct BitMap* reg_a0 __asm("a0") = srcBitMap;
	register LONG reg_d0 __asm("d0") = xSrc;
	register LONG reg_d1 __asm("d1") = ySrc;
	register struct RastPort* reg_a1 __asm("a1") = destRP;
	register LONG reg_d2 __asm("d2") = xDest;
	register LONG reg_d3 __asm("d3") = yDest;
	register LONG reg_d4 __asm("d4") = xSize;
	register LONG reg_d5 __asm("d5") = ySize;
	register ULONG reg_d6 __asm("d6") = minterm;
	register CONST PLANEPTR reg_a2 __asm("a2") = bltMask;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID BltMaskBitMapRastPort([a0] CONST struct BitMap* srcBitMap, [d0] LONG xSrc, [d1] LONG ySrc, [a1] struct RastPort* destRP, [d2] LONG xDest, [d3] LONG yDest, [d4] LONG xSize, [d5] LONG ySize, [d6] ULONG minterm, [a2] CONST PLANEPTR bltMask)\n\t"
		"jsr -636(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_d6),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5", "d6", "a2"
	);
}

inline BOOL AttemptLockLayerRom(struct Layer* layer)
{
	// LVO: -654
	// layer [a5]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Layer* reg_a5 __asm("a5") = layer;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# BOOL AttemptLockLayerRom([a5] struct Layer* layer)\n\t"
		"jsr -654(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a5"
	);
	return retVal;
}

inline APTR GfxNew(ULONG gfxNodeType)
{
	// LVO: -660
	// gfxNodeType [d0]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = gfxNodeType;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# APTR GfxNew([d0] ULONG gfxNodeType)\n\t"
		"jsr -660(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID GfxFree(APTR gfxNodePtr)
{
	// LVO: -666
	// gfxNodePtr [a0]

	register APTR reg_a0 __asm("a0") = gfxNodePtr;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID GfxFree([a0] APTR gfxNodePtr)\n\t"
		"jsr -666(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID GfxAssociate(CONST APTR associateNode, APTR gfxNodePtr)
{
	// LVO: -672
	// associateNode [a0]
	// gfxNodePtr [a1]

	register CONST APTR reg_a0 __asm("a0") = associateNode;
	register APTR reg_a1 __asm("a1") = gfxNodePtr;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID GfxAssociate([a0] CONST APTR associateNode, [a1] APTR gfxNodePtr)\n\t"
		"jsr -672(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID BitMapScale(struct BitScaleArgs* bitScaleArgs)
{
	// LVO: -678
	// bitScaleArgs [a0]

	register struct BitScaleArgs* reg_a0 __asm("a0") = bitScaleArgs;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID BitMapScale([a0] struct BitScaleArgs* bitScaleArgs)\n\t"
		"jsr -678(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline UWORD ScalerDiv(ULONG factor, ULONG numerator, ULONG denominator)
{
	// LVO: -684
	// factor [d0]
	// numerator [d1]
	// denominator [d2]
	// ret: UWORD [d0]

	register UWORD retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = factor;
	register ULONG reg_d1 __asm("d1") = numerator;
	register ULONG reg_d2 __asm("d2") = denominator;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# UWORD ScalerDiv([d0] ULONG factor, [d1] ULONG numerator, [d2] ULONG denominator)\n\t"
		"jsr -684(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline WORD TextExtent(struct RastPort* rp, CONST_STRPTR string, LONG count, struct TextExtent* textExtent)
{
	// LVO: -690
	// rp [a1]
	// string [a0]
	// count [d0]
	// textExtent [a2]
	// ret: WORD [d0]

	register WORD retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register CONST_STRPTR reg_a0 __asm("a0") = string;
	register LONG reg_d0 __asm("d0") = count;
	register struct TextExtent* reg_a2 __asm("a2") = textExtent;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# WORD TextExtent([a1] struct RastPort* rp, [a0] CONST_STRPTR string, [d0] LONG count, [a2] struct TextExtent* textExtent)\n\t"
		"jsr -690(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a0),"r"(reg_d0),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
	return retVal;
}

inline ULONG TextFit(struct RastPort* rp, CONST_STRPTR string, ULONG strLen, CONST struct TextExtent* textExtent, CONST struct TextExtent* constrainingExtent, LONG strDirection, ULONG constrainingBitWidth, ULONG constrainingBitHeight)
{
	// LVO: -696
	// rp [a1]
	// string [a0]
	// strLen [d0]
	// textExtent [a2]
	// constrainingExtent [a3]
	// strDirection [d1]
	// constrainingBitWidth [d2]
	// constrainingBitHeight [d3]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register CONST_STRPTR reg_a0 __asm("a0") = string;
	register ULONG reg_d0 __asm("d0") = strLen;
	register CONST struct TextExtent* reg_a2 __asm("a2") = textExtent;
	register CONST struct TextExtent* reg_a3 __asm("a3") = constrainingExtent;
	register LONG reg_d1 __asm("d1") = strDirection;
	register ULONG reg_d2 __asm("d2") = constrainingBitWidth;
	register ULONG reg_d3 __asm("d3") = constrainingBitHeight;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG TextFit([a1] struct RastPort* rp, [a0] CONST_STRPTR string, [d0] ULONG strLen, [a2] CONST struct TextExtent* textExtent, [a3] CONST struct TextExtent* constrainingExtent, [d1] LONG strDirection, [d2] ULONG constrainingBitWidth, [d3] ULONG constrainingBitHeight)\n\t"
		"jsr -696(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a0),"r"(reg_d0),"r"(reg_a2),"r"(reg_a3),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "a3", "d2", "d3"
	);
	return retVal;
}

inline APTR GfxLookUp(CONST APTR associateNode)
{
	// LVO: -702
	// associateNode [a0]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register CONST APTR reg_a0 __asm("a0") = associateNode;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# APTR GfxLookUp([a0] CONST APTR associateNode)\n\t"
		"jsr -702(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL VideoControl(struct ColorMap* colorMap, struct TagItem* tagarray)
{
	// LVO: -708
	// colorMap [a0]
	// tagarray [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct ColorMap* reg_a0 __asm("a0") = colorMap;
	register struct TagItem* reg_a1 __asm("a1") = tagarray;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# BOOL VideoControl([a0] struct ColorMap* colorMap, [a1] struct TagItem* tagarray)\n\t"
		"jsr -708(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL CloseMonitor(struct MonitorSpec* monitorSpec)
{
	// LVO: -720
	// monitorSpec [a0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct MonitorSpec* reg_a0 __asm("a0") = monitorSpec;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# BOOL CloseMonitor([a0] struct MonitorSpec* monitorSpec)\n\t"
		"jsr -720(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline DisplayInfoHandle FindDisplayInfo(ULONG displayID)
{
	// LVO: -726
	// displayID [d0]
	// ret: DisplayInfoHandle [d0]

	register DisplayInfoHandle retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = displayID;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# DisplayInfoHandle FindDisplayInfo([d0] ULONG displayID)\n\t"
		"jsr -726(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG NextDisplayInfo(ULONG displayID)
{
	// LVO: -732
	// displayID [d0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = displayID;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG NextDisplayInfo([d0] ULONG displayID)\n\t"
		"jsr -732(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG GetDisplayInfoData(CONST DisplayInfoHandle handle, APTR buf, ULONG size, ULONG tagID, ULONG displayID)
{
	// LVO: -756
	// handle [a0]
	// buf [a1]
	// size [d0]
	// tagID [d1]
	// displayID [d2]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register CONST DisplayInfoHandle reg_a0 __asm("a0") = handle;
	register APTR reg_a1 __asm("a1") = buf;
	register ULONG reg_d0 __asm("d0") = size;
	register ULONG reg_d1 __asm("d1") = tagID;
	register ULONG reg_d2 __asm("d2") = displayID;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG GetDisplayInfoData([a0] CONST DisplayInfoHandle handle, [a1] APTR buf, [d0] ULONG size, [d1] ULONG tagID, [d2] ULONG displayID)\n\t"
		"jsr -756(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline VOID FontExtent(CONST struct TextFont* font, struct TextExtent* fontExtent)
{
	// LVO: -762
	// font [a0]
	// fontExtent [a1]

	register CONST struct TextFont* reg_a0 __asm("a0") = font;
	register struct TextExtent* reg_a1 __asm("a1") = fontExtent;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID FontExtent([a0] CONST struct TextFont* font, [a1] struct TextExtent* fontExtent)\n\t"
		"jsr -762(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG ReadPixelLine8(struct RastPort* rp, ULONG xstart, ULONG ystart, ULONG width, UBYTE* array, struct RastPort* tempRP)
{
	// LVO: -768
	// rp [a0]
	// xstart [d0]
	// ystart [d1]
	// width [d2]
	// array [a2]
	// tempRP [a1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register ULONG reg_d0 __asm("d0") = xstart;
	register ULONG reg_d1 __asm("d1") = ystart;
	register ULONG reg_d2 __asm("d2") = width;
	register UBYTE* reg_a2 __asm("a2") = array;
	register struct RastPort* reg_a1 __asm("a1") = tempRP;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG ReadPixelLine8([a0] struct RastPort* rp, [d0] ULONG xstart, [d1] ULONG ystart, [d2] ULONG width, [a2] UBYTE* array, [a1] struct RastPort* tempRP)\n\t"
		"jsr -768(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a2),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "a2"
	);
	return retVal;
}

inline LONG WritePixelLine8(struct RastPort* rp, ULONG xstart, ULONG ystart, ULONG width, UBYTE* array, struct RastPort* tempRP)
{
	// LVO: -774
	// rp [a0]
	// xstart [d0]
	// ystart [d1]
	// width [d2]
	// array [a2]
	// tempRP [a1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register ULONG reg_d0 __asm("d0") = xstart;
	register ULONG reg_d1 __asm("d1") = ystart;
	register ULONG reg_d2 __asm("d2") = width;
	register UBYTE* reg_a2 __asm("a2") = array;
	register struct RastPort* reg_a1 __asm("a1") = tempRP;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG WritePixelLine8([a0] struct RastPort* rp, [d0] ULONG xstart, [d1] ULONG ystart, [d2] ULONG width, [a2] UBYTE* array, [a1] struct RastPort* tempRP)\n\t"
		"jsr -774(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a2),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "a2"
	);
	return retVal;
}

inline LONG ReadPixelArray8(struct RastPort* rp, ULONG xstart, ULONG ystart, ULONG xstop, ULONG ystop, UBYTE* array, struct RastPort* temprp)
{
	// LVO: -780
	// rp [a0]
	// xstart [d0]
	// ystart [d1]
	// xstop [d2]
	// ystop [d3]
	// array [a2]
	// temprp [a1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register ULONG reg_d0 __asm("d0") = xstart;
	register ULONG reg_d1 __asm("d1") = ystart;
	register ULONG reg_d2 __asm("d2") = xstop;
	register ULONG reg_d3 __asm("d3") = ystop;
	register UBYTE* reg_a2 __asm("a2") = array;
	register struct RastPort* reg_a1 __asm("a1") = temprp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG ReadPixelArray8([a0] struct RastPort* rp, [d0] ULONG xstart, [d1] ULONG ystart, [d2] ULONG xstop, [d3] ULONG ystop, [a2] UBYTE* array, [a1] struct RastPort* temprp)\n\t"
		"jsr -780(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a2),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "a2"
	);
	return retVal;
}

inline LONG WritePixelArray8(struct RastPort* rp, ULONG xstart, ULONG ystart, ULONG xstop, ULONG ystop, UBYTE* array, struct RastPort* temprp)
{
	// LVO: -786
	// rp [a0]
	// xstart [d0]
	// ystart [d1]
	// xstop [d2]
	// ystop [d3]
	// array [a2]
	// temprp [a1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register ULONG reg_d0 __asm("d0") = xstart;
	register ULONG reg_d1 __asm("d1") = ystart;
	register ULONG reg_d2 __asm("d2") = xstop;
	register ULONG reg_d3 __asm("d3") = ystop;
	register UBYTE* reg_a2 __asm("a2") = array;
	register struct RastPort* reg_a1 __asm("a1") = temprp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG WritePixelArray8([a0] struct RastPort* rp, [d0] ULONG xstart, [d1] ULONG ystart, [d2] ULONG xstop, [d3] ULONG ystop, [a2] UBYTE* array, [a1] struct RastPort* temprp)\n\t"
		"jsr -786(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a2),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "a2"
	);
	return retVal;
}

inline LONG GetVPModeID(CONST struct ViewPort* vp)
{
	// LVO: -792
	// vp [a0]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST struct ViewPort* reg_a0 __asm("a0") = vp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG GetVPModeID([a0] CONST struct ViewPort* vp)\n\t"
		"jsr -792(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG ModeNotAvailable(ULONG modeID)
{
	// LVO: -798
	// modeID [d0]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = modeID;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG ModeNotAvailable([d0] ULONG modeID)\n\t"
		"jsr -798(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID EraseRect(struct RastPort* rp, LONG xMin, LONG yMin, LONG xMax, LONG yMax)
{
	// LVO: -810
	// rp [a1]
	// xMin [d0]
	// yMin [d1]
	// xMax [d2]
	// yMax [d3]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = xMin;
	register LONG reg_d1 __asm("d1") = yMin;
	register LONG reg_d2 __asm("d2") = xMax;
	register LONG reg_d3 __asm("d3") = yMax;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID EraseRect([a1] struct RastPort* rp, [d0] LONG xMin, [d1] LONG yMin, [d2] LONG xMax, [d3] LONG yMax)\n\t"
		"jsr -810(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
}

inline ULONG ExtendFont(struct TextFont* font, CONST struct TagItem* fontTags)
{
	// LVO: -816
	// font [a0]
	// fontTags [a1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct TextFont* reg_a0 __asm("a0") = font;
	register CONST struct TagItem* reg_a1 __asm("a1") = fontTags;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG ExtendFont([a0] struct TextFont* font, [a1] CONST struct TagItem* fontTags)\n\t"
		"jsr -816(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID StripFont(struct TextFont* font)
{
	// LVO: -822
	// font [a0]

	register struct TextFont* reg_a0 __asm("a0") = font;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID StripFont([a0] struct TextFont* font)\n\t"
		"jsr -822(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline UWORD CalcIVG(struct View* v, struct ViewPort* vp)
{
	// LVO: -828
	// v [a0]
	// vp [a1]
	// ret: UWORD [d0]

	register UWORD retVal __asm("d0");

	register struct View* reg_a0 __asm("a0") = v;
	register struct ViewPort* reg_a1 __asm("a1") = vp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# UWORD CalcIVG([a0] struct View* v, [a1] struct ViewPort* vp)\n\t"
		"jsr -828(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG AttachPalExtra(struct ColorMap* cm, struct ViewPort* vp)
{
	// LVO: -834
	// cm [a0]
	// vp [a1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct ColorMap* reg_a0 __asm("a0") = cm;
	register struct ViewPort* reg_a1 __asm("a1") = vp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG AttachPalExtra([a0] struct ColorMap* cm, [a1] struct ViewPort* vp)\n\t"
		"jsr -834(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG ObtainBestPenA(struct ColorMap* cm, ULONG r, ULONG g, ULONG b, CONST struct TagItem* tags)
{
	// LVO: -840
	// cm [a0]
	// r [d1]
	// g [d2]
	// b [d3]
	// tags [a1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct ColorMap* reg_a0 __asm("a0") = cm;
	register ULONG reg_d1 __asm("d1") = r;
	register ULONG reg_d2 __asm("d2") = g;
	register ULONG reg_d3 __asm("d3") = b;
	register CONST struct TagItem* reg_a1 __asm("a1") = tags;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG ObtainBestPenA([a0] struct ColorMap* cm, [d1] ULONG r, [d2] ULONG g, [d3] ULONG b, [a1] CONST struct TagItem* tags)\n\t"
		"jsr -840(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline VOID SetRGB32(struct ViewPort* vp, ULONG n, ULONG r, ULONG g, ULONG b)
{
	// LVO: -852
	// vp [a0]
	// n [d0]
	// r [d1]
	// g [d2]
	// b [d3]

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register ULONG reg_d0 __asm("d0") = n;
	register ULONG reg_d1 __asm("d1") = r;
	register ULONG reg_d2 __asm("d2") = g;
	register ULONG reg_d3 __asm("d3") = b;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SetRGB32([a0] struct ViewPort* vp, [d0] ULONG n, [d1] ULONG r, [d2] ULONG g, [d3] ULONG b)\n\t"
		"jsr -852(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
}

inline ULONG GetAPen(struct RastPort* rp)
{
	// LVO: -858
	// rp [a0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG GetAPen([a0] struct RastPort* rp)\n\t"
		"jsr -858(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG GetBPen(struct RastPort* rp)
{
	// LVO: -864
	// rp [a0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG GetBPen([a0] struct RastPort* rp)\n\t"
		"jsr -864(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG GetDrMd(struct RastPort* rp)
{
	// LVO: -870
	// rp [a0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG GetDrMd([a0] struct RastPort* rp)\n\t"
		"jsr -870(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG GetOutlinePen(struct RastPort* rp)
{
	// LVO: -876
	// rp [a0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG GetOutlinePen([a0] struct RastPort* rp)\n\t"
		"jsr -876(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID LoadRGB32(struct ViewPort* vp, CONST ULONG* table)
{
	// LVO: -882
	// vp [a0]
	// table [a1]

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register CONST ULONG* reg_a1 __asm("a1") = table;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID LoadRGB32([a0] struct ViewPort* vp, [a1] CONST ULONG* table)\n\t"
		"jsr -882(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG SetChipRev(ULONG want)
{
	// LVO: -888
	// want [d0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = want;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG SetChipRev([d0] ULONG want)\n\t"
		"jsr -888(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID SetABPenDrMd(struct RastPort* rp, ULONG apen, ULONG bpen, ULONG drawmode)
{
	// LVO: -894
	// rp [a1]
	// apen [d0]
	// bpen [d1]
	// drawmode [d2]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register ULONG reg_d0 __asm("d0") = apen;
	register ULONG reg_d1 __asm("d1") = bpen;
	register ULONG reg_d2 __asm("d2") = drawmode;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SetABPenDrMd([a1] struct RastPort* rp, [d0] ULONG apen, [d1] ULONG bpen, [d2] ULONG drawmode)\n\t"
		"jsr -894(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
}

inline VOID GetRGB32(CONST struct ColorMap* cm, ULONG firstcolor, ULONG ncolors, ULONG* table)
{
	// LVO: -900
	// cm [a0]
	// firstcolor [d0]
	// ncolors [d1]
	// table [a1]

	register CONST struct ColorMap* reg_a0 __asm("a0") = cm;
	register ULONG reg_d0 __asm("d0") = firstcolor;
	register ULONG reg_d1 __asm("d1") = ncolors;
	register ULONG* reg_a1 __asm("a1") = table;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID GetRGB32([a0] CONST struct ColorMap* cm, [d0] ULONG firstcolor, [d1] ULONG ncolors, [a1] ULONG* table)\n\t"
		"jsr -900(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID FreeBitMap(struct BitMap* bm)
{
	// LVO: -924
	// bm [a0]

	register struct BitMap* reg_a0 __asm("a0") = bm;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID FreeBitMap([a0] struct BitMap* bm)\n\t"
		"jsr -924(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG GetExtSpriteA(struct ExtSprite* ss, CONST struct TagItem* tags)
{
	// LVO: -930
	// ss [a2]
	// tags [a1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct ExtSprite* reg_a2 __asm("a2") = ss;
	register CONST struct TagItem* reg_a1 __asm("a1") = tags;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG GetExtSpriteA([a2] struct ExtSprite* ss, [a1] CONST struct TagItem* tags)\n\t"
		"jsr -930(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a2),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
	return retVal;
}

inline ULONG CoerceMode(struct ViewPort* vp, ULONG monitorid, ULONG flags)
{
	// LVO: -936
	// vp [a0]
	// monitorid [d0]
	// flags [d1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register ULONG reg_d0 __asm("d0") = monitorid;
	register ULONG reg_d1 __asm("d1") = flags;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG CoerceMode([a0] struct ViewPort* vp, [d0] ULONG monitorid, [d1] ULONG flags)\n\t"
		"jsr -936(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ChangeVPBitMap(struct ViewPort* vp, struct BitMap* bm, struct DBufInfo* db)
{
	// LVO: -942
	// vp [a0]
	// bm [a1]
	// db [a2]

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register struct BitMap* reg_a1 __asm("a1") = bm;
	register struct DBufInfo* reg_a2 __asm("a2") = db;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID ChangeVPBitMap([a0] struct ViewPort* vp, [a1] struct BitMap* bm, [a2] struct DBufInfo* db)\n\t"
		"jsr -942(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline VOID ReleasePen(struct ColorMap* cm, ULONG n)
{
	// LVO: -948
	// cm [a0]
	// n [d0]

	register struct ColorMap* reg_a0 __asm("a0") = cm;
	register ULONG reg_d0 __asm("d0") = n;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID ReleasePen([a0] struct ColorMap* cm, [d0] ULONG n)\n\t"
		"jsr -948(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG ObtainPen(struct ColorMap* cm, ULONG n, ULONG r, ULONG g, ULONG b, LONG f)
{
	// LVO: -954
	// cm [a0]
	// n [d0]
	// r [d1]
	// g [d2]
	// b [d3]
	// f [d4]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct ColorMap* reg_a0 __asm("a0") = cm;
	register ULONG reg_d0 __asm("d0") = n;
	register ULONG reg_d1 __asm("d1") = r;
	register ULONG reg_d2 __asm("d2") = g;
	register ULONG reg_d3 __asm("d3") = b;
	register LONG reg_d4 __asm("d4") = f;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG ObtainPen([a0] struct ColorMap* cm, [d0] ULONG n, [d1] ULONG r, [d2] ULONG g, [d3] ULONG b, [d4] LONG f)\n\t"
		"jsr -954(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4"
	);
	return retVal;
}

inline ULONG GetBitMapAttr(CONST struct BitMap* bm, ULONG attrnum)
{
	// LVO: -960
	// bm [a0]
	// attrnum [d1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register CONST struct BitMap* reg_a0 __asm("a0") = bm;
	register ULONG reg_d1 __asm("d1") = attrnum;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG GetBitMapAttr([a0] CONST struct BitMap* bm, [d1] ULONG attrnum)\n\t"
		"jsr -960(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreeDBufInfo(struct DBufInfo* dbi)
{
	// LVO: -972
	// dbi [a1]

	register struct DBufInfo* reg_a1 __asm("a1") = dbi;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID FreeDBufInfo([a1] struct DBufInfo* dbi)\n\t"
		"jsr -972(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG SetOutlinePen(struct RastPort* rp, ULONG pen)
{
	// LVO: -978
	// rp [a0]
	// pen [d0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register ULONG reg_d0 __asm("d0") = pen;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG SetOutlinePen([a0] struct RastPort* rp, [d0] ULONG pen)\n\t"
		"jsr -978(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG SetWriteMask(struct RastPort* rp, ULONG msk)
{
	// LVO: -984
	// rp [a0]
	// msk [d0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register ULONG reg_d0 __asm("d0") = msk;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG SetWriteMask([a0] struct RastPort* rp, [d0] ULONG msk)\n\t"
		"jsr -984(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID SetMaxPen(struct RastPort* rp, ULONG maxpen)
{
	// LVO: -990
	// rp [a0]
	// maxpen [d0]

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register ULONG reg_d0 __asm("d0") = maxpen;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SetMaxPen([a0] struct RastPort* rp, [d0] ULONG maxpen)\n\t"
		"jsr -990(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID SetRGB32CM(struct ColorMap* cm, ULONG n, ULONG r, ULONG g, ULONG b)
{
	// LVO: -996
	// cm [a0]
	// n [d0]
	// r [d1]
	// g [d2]
	// b [d3]

	register struct ColorMap* reg_a0 __asm("a0") = cm;
	register ULONG reg_d0 __asm("d0") = n;
	register ULONG reg_d1 __asm("d1") = r;
	register ULONG reg_d2 __asm("d2") = g;
	register ULONG reg_d3 __asm("d3") = b;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SetRGB32CM([a0] struct ColorMap* cm, [d0] ULONG n, [d1] ULONG r, [d2] ULONG g, [d3] ULONG b)\n\t"
		"jsr -996(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
}

inline VOID ScrollRasterBF(struct RastPort* rp, LONG dx, LONG dy, LONG xMin, LONG yMin, LONG xMax, LONG yMax)
{
	// LVO: -1002
	// rp [a1]
	// dx [d0]
	// dy [d1]
	// xMin [d2]
	// yMin [d3]
	// xMax [d4]
	// yMax [d5]

	register struct RastPort* reg_a1 __asm("a1") = rp;
	register LONG reg_d0 __asm("d0") = dx;
	register LONG reg_d1 __asm("d1") = dy;
	register LONG reg_d2 __asm("d2") = xMin;
	register LONG reg_d3 __asm("d3") = yMin;
	register LONG reg_d4 __asm("d4") = xMax;
	register LONG reg_d5 __asm("d5") = yMax;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID ScrollRasterBF([a1] struct RastPort* rp, [d0] LONG dx, [d1] LONG dy, [d2] LONG xMin, [d3] LONG yMin, [d4] LONG xMax, [d5] LONG yMax)\n\t"
		"jsr -1002(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5"
	);
}

inline LONG FindColor(struct ColorMap* cm, ULONG r, ULONG g, ULONG b, LONG maxcolor)
{
	// LVO: -1008
	// cm [a3]
	// r [d1]
	// g [d2]
	// b [d3]
	// maxcolor [d4]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct ColorMap* reg_a3 __asm("a3") = cm;
	register ULONG reg_d1 __asm("d1") = r;
	register ULONG reg_d2 __asm("d2") = g;
	register ULONG reg_d3 __asm("d3") = b;
	register LONG reg_d4 __asm("d4") = maxcolor;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG FindColor([a3] struct ColorMap* cm, [d1] ULONG r, [d2] ULONG g, [d3] ULONG b, [d4] LONG maxcolor)\n\t"
		"jsr -1008(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a3),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a3", "d2", "d3", "d4"
	);
	return retVal;
}

inline LONG ChangeExtSpriteA(struct ViewPort* vp, struct ExtSprite* oldsprite, struct ExtSprite* newsprite, CONST struct TagItem* tags)
{
	// LVO: -1026
	// vp [a0]
	// oldsprite [a1]
	// newsprite [a2]
	// tags [a3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct ViewPort* reg_a0 __asm("a0") = vp;
	register struct ExtSprite* reg_a1 __asm("a1") = oldsprite;
	register struct ExtSprite* reg_a2 __asm("a2") = newsprite;
	register CONST struct TagItem* reg_a3 __asm("a3") = tags;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# LONG ChangeExtSpriteA([a0] struct ViewPort* vp, [a1] struct ExtSprite* oldsprite, [a2] struct ExtSprite* newsprite, [a3] CONST struct TagItem* tags)\n\t"
		"jsr -1026(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "a3"
	);
	return retVal;
}

inline VOID FreeSpriteData(struct ExtSprite* sp)
{
	// LVO: -1032
	// sp [a2]

	register struct ExtSprite* reg_a2 __asm("a2") = sp;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID FreeSpriteData([a2] struct ExtSprite* sp)\n\t"
		"jsr -1032(a6)\n\t"
		: 
		: "r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline VOID SetRPAttrsA(struct RastPort* rp, CONST struct TagItem* tags)
{
	// LVO: -1038
	// rp [a0]
	// tags [a1]

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register CONST struct TagItem* reg_a1 __asm("a1") = tags;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID SetRPAttrsA([a0] struct RastPort* rp, [a1] CONST struct TagItem* tags)\n\t"
		"jsr -1038(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID GetRPAttrsA(CONST struct RastPort* rp, CONST struct TagItem* tags)
{
	// LVO: -1044
	// rp [a0]
	// tags [a1]

	register CONST struct RastPort* reg_a0 __asm("a0") = rp;
	register CONST struct TagItem* reg_a1 __asm("a1") = tags;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID GetRPAttrsA([a0] CONST struct RastPort* rp, [a1] CONST struct TagItem* tags)\n\t"
		"jsr -1044(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG BestModeIDA(CONST struct TagItem* tags)
{
	// LVO: -1050
	// tags [a0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register CONST struct TagItem* reg_a0 __asm("a0") = tags;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# ULONG BestModeIDA([a0] CONST struct TagItem* tags)\n\t"
		"jsr -1050(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID WriteChunkyPixels(struct RastPort* rp, ULONG xstart, ULONG ystart, ULONG xstop, ULONG ystop, CONST UBYTE* array, LONG bytesperrow)
{
	// LVO: -1056
	// rp [a0]
	// xstart [d0]
	// ystart [d1]
	// xstop [d2]
	// ystop [d3]
	// array [a2]
	// bytesperrow [d4]

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register ULONG reg_d0 __asm("d0") = xstart;
	register ULONG reg_d1 __asm("d1") = ystart;
	register ULONG reg_d2 __asm("d2") = xstop;
	register ULONG reg_d3 __asm("d3") = ystop;
	register CONST UBYTE* reg_a2 __asm("a2") = array;
	register LONG reg_d4 __asm("d4") = bytesperrow;
	register void* reg_a6 __asm("a6") = GfxBase;
	__asm volatile (
		"# VOID WriteChunkyPixels([a0] struct RastPort* rp, [d0] ULONG xstart, [d1] ULONG ystart, [d2] ULONG xstop, [d3] ULONG ystop, [a2] CONST UBYTE* array, [d4] LONG bytesperrow)\n\t"
		"jsr -1056(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a2),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "a2", "d4"
	);
}

#endif
