#ifndef _INLINE_AMIGA_INTUITION_HPP_
#define _INLINE_AMIGA_INTUITION_HPP_
inline VOID OpenIntuition()
{
	// LVO: -30

	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID OpenIntuition()\n\t"
		"jsr -30(a6)\n\t"
		: 
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID Intuition(struct InputEvent* iEvent)
{
	// LVO: -36
	// iEvent [a0]

	register struct InputEvent* reg_a0 __asm("a0") = iEvent;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID Intuition([a0] struct InputEvent* iEvent)\n\t"
		"jsr -36(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline UWORD AddGadget(struct Window* window, struct Gadget* gadget, ULONG position)
{
	// LVO: -42
	// window [a0]
	// gadget [a1]
	// position [d0]
	// ret: UWORD [d0]

	register UWORD retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register struct Gadget* reg_a1 __asm("a1") = gadget;
	register ULONG reg_d0 __asm("d0") = position;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# UWORD AddGadget([a0] struct Window* window, [a1] struct Gadget* gadget, [d0] ULONG position)\n\t"
		"jsr -42(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL ClearDMRequest(struct Window* window)
{
	// LVO: -48
	// window [a0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL ClearDMRequest([a0] struct Window* window)\n\t"
		"jsr -48(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ClearMenuStrip(struct Window* window)
{
	// LVO: -54
	// window [a0]

	register struct Window* reg_a0 __asm("a0") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ClearMenuStrip([a0] struct Window* window)\n\t"
		"jsr -54(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ClearPointer(struct Window* window)
{
	// LVO: -60
	// window [a0]

	register struct Window* reg_a0 __asm("a0") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ClearPointer([a0] struct Window* window)\n\t"
		"jsr -60(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL CloseScreen(struct Screen* screen)
{
	// LVO: -66
	// screen [a0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Screen* reg_a0 __asm("a0") = screen;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL CloseScreen([a0] struct Screen* screen)\n\t"
		"jsr -66(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID CloseWindow(struct Window* window)
{
	// LVO: -72
	// window [a0]

	register struct Window* reg_a0 __asm("a0") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID CloseWindow([a0] struct Window* window)\n\t"
		"jsr -72(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG CloseWorkBench()
{
	// LVO: -78
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# LONG CloseWorkBench()\n\t"
		"jsr -78(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID CurrentTime(ULONG* seconds, ULONG* micros)
{
	// LVO: -84
	// seconds [a0]
	// micros [a1]

	register ULONG* reg_a0 __asm("a0") = seconds;
	register ULONG* reg_a1 __asm("a1") = micros;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID CurrentTime([a0] ULONG* seconds, [a1] ULONG* micros)\n\t"
		"jsr -84(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL DisplayAlert(ULONG alertNumber, CONST_STRPTR string, ULONG height)
{
	// LVO: -90
	// alertNumber [d0]
	// string [a0]
	// height [d1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = alertNumber;
	register CONST_STRPTR reg_a0 __asm("a0") = string;
	register ULONG reg_d1 __asm("d1") = height;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL DisplayAlert([d0] ULONG alertNumber, [a0] CONST_STRPTR string, [d1] ULONG height)\n\t"
		"jsr -90(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID DisplayBeep(struct Screen* screen)
{
	// LVO: -96
	// screen [a0]

	register struct Screen* reg_a0 __asm("a0") = screen;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID DisplayBeep([a0] struct Screen* screen)\n\t"
		"jsr -96(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL DoubleClick(ULONG sSeconds, ULONG sMicros, ULONG cSeconds, ULONG cMicros)
{
	// LVO: -102
	// sSeconds [d0]
	// sMicros [d1]
	// cSeconds [d2]
	// cMicros [d3]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = sSeconds;
	register ULONG reg_d1 __asm("d1") = sMicros;
	register ULONG reg_d2 __asm("d2") = cSeconds;
	register ULONG reg_d3 __asm("d3") = cMicros;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL DoubleClick([d0] ULONG sSeconds, [d1] ULONG sMicros, [d2] ULONG cSeconds, [d3] ULONG cMicros)\n\t"
		"jsr -102(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline VOID DrawBorder(struct RastPort* rp, CONST struct Border* border, LONG leftOffset, LONG topOffset)
{
	// LVO: -108
	// rp [a0]
	// border [a1]
	// leftOffset [d0]
	// topOffset [d1]

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register CONST struct Border* reg_a1 __asm("a1") = border;
	register LONG reg_d0 __asm("d0") = leftOffset;
	register LONG reg_d1 __asm("d1") = topOffset;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID DrawBorder([a0] struct RastPort* rp, [a1] CONST struct Border* border, [d0] LONG leftOffset, [d1] LONG topOffset)\n\t"
		"jsr -108(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID DrawImage(struct RastPort* rp, struct Image* image, LONG leftOffset, LONG topOffset)
{
	// LVO: -114
	// rp [a0]
	// image [a1]
	// leftOffset [d0]
	// topOffset [d1]

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register struct Image* reg_a1 __asm("a1") = image;
	register LONG reg_d0 __asm("d0") = leftOffset;
	register LONG reg_d1 __asm("d1") = topOffset;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID DrawImage([a0] struct RastPort* rp, [a1] struct Image* image, [d0] LONG leftOffset, [d1] LONG topOffset)\n\t"
		"jsr -114(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID EndRequest(struct Requester* requester, struct Window* window)
{
	// LVO: -120
	// requester [a0]
	// window [a1]

	register struct Requester* reg_a0 __asm("a0") = requester;
	register struct Window* reg_a1 __asm("a1") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID EndRequest([a0] struct Requester* requester, [a1] struct Window* window)\n\t"
		"jsr -120(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID InitRequester(struct Requester* requester)
{
	// LVO: -138
	// requester [a0]

	register struct Requester* reg_a0 __asm("a0") = requester;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID InitRequester([a0] struct Requester* requester)\n\t"
		"jsr -138(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL ModifyIDCMP(struct Window* window, ULONG flags)
{
	// LVO: -150
	// window [a0]
	// flags [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register ULONG reg_d0 __asm("d0") = flags;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL ModifyIDCMP([a0] struct Window* window, [d0] ULONG flags)\n\t"
		"jsr -150(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ModifyProp(struct Gadget* gadget, struct Window* window, struct Requester* requester, ULONG flags, ULONG horizPot, ULONG vertPot, ULONG horizBody, ULONG vertBody)
{
	// LVO: -156
	// gadget [a0]
	// window [a1]
	// requester [a2]
	// flags [d0]
	// horizPot [d1]
	// vertPot [d2]
	// horizBody [d3]
	// vertBody [d4]

	register struct Gadget* reg_a0 __asm("a0") = gadget;
	register struct Window* reg_a1 __asm("a1") = window;
	register struct Requester* reg_a2 __asm("a2") = requester;
	register ULONG reg_d0 __asm("d0") = flags;
	register ULONG reg_d1 __asm("d1") = horizPot;
	register ULONG reg_d2 __asm("d2") = vertPot;
	register ULONG reg_d3 __asm("d3") = horizBody;
	register ULONG reg_d4 __asm("d4") = vertBody;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ModifyProp([a0] struct Gadget* gadget, [a1] struct Window* window, [a2] struct Requester* requester, [d0] ULONG flags, [d1] ULONG horizPot, [d2] ULONG vertPot, [d3] ULONG horizBody, [d4] ULONG vertBody)\n\t"
		"jsr -156(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "d2", "d3", "d4"
	);
}

inline VOID MoveScreen(struct Screen* screen, LONG dx, LONG dy)
{
	// LVO: -162
	// screen [a0]
	// dx [d0]
	// dy [d1]

	register struct Screen* reg_a0 __asm("a0") = screen;
	register LONG reg_d0 __asm("d0") = dx;
	register LONG reg_d1 __asm("d1") = dy;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID MoveScreen([a0] struct Screen* screen, [d0] LONG dx, [d1] LONG dy)\n\t"
		"jsr -162(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID MoveWindow(struct Window* window, LONG dx, LONG dy)
{
	// LVO: -168
	// window [a0]
	// dx [d0]
	// dy [d1]

	register struct Window* reg_a0 __asm("a0") = window;
	register LONG reg_d0 __asm("d0") = dx;
	register LONG reg_d1 __asm("d1") = dy;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID MoveWindow([a0] struct Window* window, [d0] LONG dx, [d1] LONG dy)\n\t"
		"jsr -168(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID OffGadget(struct Gadget* gadget, struct Window* window, struct Requester* requester)
{
	// LVO: -174
	// gadget [a0]
	// window [a1]
	// requester [a2]

	register struct Gadget* reg_a0 __asm("a0") = gadget;
	register struct Window* reg_a1 __asm("a1") = window;
	register struct Requester* reg_a2 __asm("a2") = requester;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID OffGadget([a0] struct Gadget* gadget, [a1] struct Window* window, [a2] struct Requester* requester)\n\t"
		"jsr -174(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline VOID OffMenu(struct Window* window, ULONG menuNumber)
{
	// LVO: -180
	// window [a0]
	// menuNumber [d0]

	register struct Window* reg_a0 __asm("a0") = window;
	register ULONG reg_d0 __asm("d0") = menuNumber;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID OffMenu([a0] struct Window* window, [d0] ULONG menuNumber)\n\t"
		"jsr -180(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID OnGadget(struct Gadget* gadget, struct Window* window, struct Requester* requester)
{
	// LVO: -186
	// gadget [a0]
	// window [a1]
	// requester [a2]

	register struct Gadget* reg_a0 __asm("a0") = gadget;
	register struct Window* reg_a1 __asm("a1") = window;
	register struct Requester* reg_a2 __asm("a2") = requester;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID OnGadget([a0] struct Gadget* gadget, [a1] struct Window* window, [a2] struct Requester* requester)\n\t"
		"jsr -186(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline VOID OnMenu(struct Window* window, ULONG menuNumber)
{
	// LVO: -192
	// window [a0]
	// menuNumber [d0]

	register struct Window* reg_a0 __asm("a0") = window;
	register ULONG reg_d0 __asm("d0") = menuNumber;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID OnMenu([a0] struct Window* window, [d0] ULONG menuNumber)\n\t"
		"jsr -192(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG OpenWorkBench()
{
	// LVO: -210
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# ULONG OpenWorkBench()\n\t"
		"jsr -210(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID PrintIText(struct RastPort* rp, CONST struct IntuiText* iText, LONG left, LONG top)
{
	// LVO: -216
	// rp [a0]
	// iText [a1]
	// left [d0]
	// top [d1]

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register CONST struct IntuiText* reg_a1 __asm("a1") = iText;
	register LONG reg_d0 __asm("d0") = left;
	register LONG reg_d1 __asm("d1") = top;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID PrintIText([a0] struct RastPort* rp, [a1] CONST struct IntuiText* iText, [d0] LONG left, [d1] LONG top)\n\t"
		"jsr -216(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID RefreshGadgets(struct Gadget* gadgets, struct Window* window, struct Requester* requester)
{
	// LVO: -222
	// gadgets [a0]
	// window [a1]
	// requester [a2]

	register struct Gadget* reg_a0 __asm("a0") = gadgets;
	register struct Window* reg_a1 __asm("a1") = window;
	register struct Requester* reg_a2 __asm("a2") = requester;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID RefreshGadgets([a0] struct Gadget* gadgets, [a1] struct Window* window, [a2] struct Requester* requester)\n\t"
		"jsr -222(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline UWORD RemoveGadget(struct Window* window, struct Gadget* gadget)
{
	// LVO: -228
	// window [a0]
	// gadget [a1]
	// ret: UWORD [d0]

	register UWORD retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register struct Gadget* reg_a1 __asm("a1") = gadget;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# UWORD RemoveGadget([a0] struct Window* window, [a1] struct Gadget* gadget)\n\t"
		"jsr -228(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ReportMouse(LONG flag, struct Window* window)
{
	// LVO: -234
	// flag [d0]
	// window [a0]

	register LONG reg_d0 __asm("d0") = flag;
	register struct Window* reg_a0 __asm("a0") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ReportMouse([d0] LONG flag, [a0] struct Window* window)\n\t"
		"jsr -234(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL Request(struct Requester* requester, struct Window* window)
{
	// LVO: -240
	// requester [a0]
	// window [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Requester* reg_a0 __asm("a0") = requester;
	register struct Window* reg_a1 __asm("a1") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL Request([a0] struct Requester* requester, [a1] struct Window* window)\n\t"
		"jsr -240(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ScreenToBack(struct Screen* screen)
{
	// LVO: -246
	// screen [a0]

	register struct Screen* reg_a0 __asm("a0") = screen;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ScreenToBack([a0] struct Screen* screen)\n\t"
		"jsr -246(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ScreenToFront(struct Screen* screen)
{
	// LVO: -252
	// screen [a0]

	register struct Screen* reg_a0 __asm("a0") = screen;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ScreenToFront([a0] struct Screen* screen)\n\t"
		"jsr -252(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL SetDMRequest(struct Window* window, struct Requester* requester)
{
	// LVO: -258
	// window [a0]
	// requester [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register struct Requester* reg_a1 __asm("a1") = requester;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL SetDMRequest([a0] struct Window* window, [a1] struct Requester* requester)\n\t"
		"jsr -258(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL SetMenuStrip(struct Window* window, struct Menu* menu)
{
	// LVO: -264
	// window [a0]
	// menu [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register struct Menu* reg_a1 __asm("a1") = menu;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL SetMenuStrip([a0] struct Window* window, [a1] struct Menu* menu)\n\t"
		"jsr -264(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID SetPointer(struct Window* window, UWORD* pointer, LONG height, LONG width, LONG xOffset, LONG yOffset)
{
	// LVO: -270
	// window [a0]
	// pointer [a1]
	// height [d0]
	// width [d1]
	// xOffset [d2]
	// yOffset [d3]

	register struct Window* reg_a0 __asm("a0") = window;
	register UWORD* reg_a1 __asm("a1") = pointer;
	register LONG reg_d0 __asm("d0") = height;
	register LONG reg_d1 __asm("d1") = width;
	register LONG reg_d2 __asm("d2") = xOffset;
	register LONG reg_d3 __asm("d3") = yOffset;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID SetPointer([a0] struct Window* window, [a1] UWORD* pointer, [d0] LONG height, [d1] LONG width, [d2] LONG xOffset, [d3] LONG yOffset)\n\t"
		"jsr -270(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
}

inline VOID SetWindowTitles(struct Window* window, CONST_STRPTR windowTitle, CONST_STRPTR screenTitle)
{
	// LVO: -276
	// window [a0]
	// windowTitle [a1]
	// screenTitle [a2]

	register struct Window* reg_a0 __asm("a0") = window;
	register CONST_STRPTR reg_a1 __asm("a1") = windowTitle;
	register CONST_STRPTR reg_a2 __asm("a2") = screenTitle;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID SetWindowTitles([a0] struct Window* window, [a1] CONST_STRPTR windowTitle, [a2] CONST_STRPTR screenTitle)\n\t"
		"jsr -276(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline VOID ShowTitle(struct Screen* screen, LONG showIt)
{
	// LVO: -282
	// screen [a0]
	// showIt [d0]

	register struct Screen* reg_a0 __asm("a0") = screen;
	register LONG reg_d0 __asm("d0") = showIt;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ShowTitle([a0] struct Screen* screen, [d0] LONG showIt)\n\t"
		"jsr -282(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID SizeWindow(struct Window* window, LONG dx, LONG dy)
{
	// LVO: -288
	// window [a0]
	// dx [d0]
	// dy [d1]

	register struct Window* reg_a0 __asm("a0") = window;
	register LONG reg_d0 __asm("d0") = dx;
	register LONG reg_d1 __asm("d1") = dy;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID SizeWindow([a0] struct Window* window, [d0] LONG dx, [d1] LONG dy)\n\t"
		"jsr -288(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID WindowToBack(struct Window* window)
{
	// LVO: -306
	// window [a0]

	register struct Window* reg_a0 __asm("a0") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID WindowToBack([a0] struct Window* window)\n\t"
		"jsr -306(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID WindowToFront(struct Window* window)
{
	// LVO: -312
	// window [a0]

	register struct Window* reg_a0 __asm("a0") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID WindowToFront([a0] struct Window* window)\n\t"
		"jsr -312(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL WindowLimits(struct Window* window, LONG widthMin, LONG heightMin, ULONG widthMax, ULONG heightMax)
{
	// LVO: -318
	// window [a0]
	// widthMin [d0]
	// heightMin [d1]
	// widthMax [d2]
	// heightMax [d3]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register LONG reg_d0 __asm("d0") = widthMin;
	register LONG reg_d1 __asm("d1") = heightMin;
	register ULONG reg_d2 __asm("d2") = widthMax;
	register ULONG reg_d3 __asm("d3") = heightMax;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL WindowLimits([a0] struct Window* window, [d0] LONG widthMin, [d1] LONG heightMin, [d2] ULONG widthMax, [d3] ULONG heightMax)\n\t"
		"jsr -318(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline LONG IntuiTextLength(CONST struct IntuiText* iText)
{
	// LVO: -330
	// iText [a0]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST struct IntuiText* reg_a0 __asm("a0") = iText;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# LONG IntuiTextLength([a0] CONST struct IntuiText* iText)\n\t"
		"jsr -330(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL WBenchToBack()
{
	// LVO: -336
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL WBenchToBack()\n\t"
		"jsr -336(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL WBenchToFront()
{
	// LVO: -342
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL WBenchToFront()\n\t"
		"jsr -342(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL AutoRequest(struct Window* window, CONST struct IntuiText* body, CONST struct IntuiText* posText, CONST struct IntuiText* negText, ULONG pFlag, ULONG nFlag, ULONG width, ULONG height)
{
	// LVO: -348
	// window [a0]
	// body [a1]
	// posText [a2]
	// negText [a3]
	// pFlag [d0]
	// nFlag [d1]
	// width [d2]
	// height [d3]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register CONST struct IntuiText* reg_a1 __asm("a1") = body;
	register CONST struct IntuiText* reg_a2 __asm("a2") = posText;
	register CONST struct IntuiText* reg_a3 __asm("a3") = negText;
	register ULONG reg_d0 __asm("d0") = pFlag;
	register ULONG reg_d1 __asm("d1") = nFlag;
	register ULONG reg_d2 __asm("d2") = width;
	register ULONG reg_d3 __asm("d3") = height;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL AutoRequest([a0] struct Window* window, [a1] CONST struct IntuiText* body, [a2] CONST struct IntuiText* posText, [a3] CONST struct IntuiText* negText, [d0] ULONG pFlag, [d1] ULONG nFlag, [d2] ULONG width, [d3] ULONG height)\n\t"
		"jsr -348(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a3),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "a3", "d2", "d3"
	);
	return retVal;
}

inline VOID BeginRefresh(struct Window* window)
{
	// LVO: -354
	// window [a0]

	register struct Window* reg_a0 __asm("a0") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID BeginRefresh([a0] struct Window* window)\n\t"
		"jsr -354(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID EndRefresh(struct Window* window, LONG complete)
{
	// LVO: -366
	// window [a0]
	// complete [d0]

	register struct Window* reg_a0 __asm("a0") = window;
	register LONG reg_d0 __asm("d0") = complete;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID EndRefresh([a0] struct Window* window, [d0] LONG complete)\n\t"
		"jsr -366(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID FreeSysRequest(struct Window* window)
{
	// LVO: -372
	// window [a0]

	register struct Window* reg_a0 __asm("a0") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID FreeSysRequest([a0] struct Window* window)\n\t"
		"jsr -372(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG MakeScreen(struct Screen* screen)
{
	// LVO: -378
	// screen [a0]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct Screen* reg_a0 __asm("a0") = screen;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# LONG MakeScreen([a0] struct Screen* screen)\n\t"
		"jsr -378(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG RemakeDisplay()
{
	// LVO: -384
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# LONG RemakeDisplay()\n\t"
		"jsr -384(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG RethinkDisplay()
{
	// LVO: -390
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# LONG RethinkDisplay()\n\t"
		"jsr -390(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline APTR AllocRemember(struct Remember* rememberKey, ULONG size, ULONG flags)
{
	// LVO: -396
	// rememberKey [a0]
	// size [d0]
	// flags [d1]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register struct Remember* reg_a0 __asm("a0") = rememberKey;
	register ULONG reg_d0 __asm("d0") = size;
	register ULONG reg_d1 __asm("d1") = flags;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# APTR AllocRemember([a0] struct Remember* rememberKey, [d0] ULONG size, [d1] ULONG flags)\n\t"
		"jsr -396(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreeRemember(struct Remember* rememberKey, LONG reallyForget)
{
	// LVO: -408
	// rememberKey [a0]
	// reallyForget [d0]

	register struct Remember* reg_a0 __asm("a0") = rememberKey;
	register LONG reg_d0 __asm("d0") = reallyForget;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID FreeRemember([a0] struct Remember* rememberKey, [d0] LONG reallyForget)\n\t"
		"jsr -408(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG LockIBase(ULONG dontknow)
{
	// LVO: -414
	// dontknow [d0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = dontknow;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# ULONG LockIBase([d0] ULONG dontknow)\n\t"
		"jsr -414(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID UnlockIBase(ULONG ibLock)
{
	// LVO: -420
	// ibLock [a0]

	register ULONG reg_a0 __asm("a0") = ibLock;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID UnlockIBase([a0] ULONG ibLock)\n\t"
		"jsr -420(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG GetScreenData(APTR buffer, ULONG size, ULONG type, CONST struct Screen* screen)
{
	// LVO: -426
	// buffer [a0]
	// size [d0]
	// type [d1]
	// screen [a1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register APTR reg_a0 __asm("a0") = buffer;
	register ULONG reg_d0 __asm("d0") = size;
	register ULONG reg_d1 __asm("d1") = type;
	register CONST struct Screen* reg_a1 __asm("a1") = screen;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# LONG GetScreenData([a0] APTR buffer, [d0] ULONG size, [d1] ULONG type, [a1] CONST struct Screen* screen)\n\t"
		"jsr -426(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID RefreshGList(struct Gadget* gadgets, struct Window* window, struct Requester* requester, LONG numGad)
{
	// LVO: -432
	// gadgets [a0]
	// window [a1]
	// requester [a2]
	// numGad [d0]

	register struct Gadget* reg_a0 __asm("a0") = gadgets;
	register struct Window* reg_a1 __asm("a1") = window;
	register struct Requester* reg_a2 __asm("a2") = requester;
	register LONG reg_d0 __asm("d0") = numGad;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID RefreshGList([a0] struct Gadget* gadgets, [a1] struct Window* window, [a2] struct Requester* requester, [d0] LONG numGad)\n\t"
		"jsr -432(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline UWORD AddGList(struct Window* window, struct Gadget* gadget, ULONG position, LONG numGad, struct Requester* requester)
{
	// LVO: -438
	// window [a0]
	// gadget [a1]
	// position [d0]
	// numGad [d1]
	// requester [a2]
	// ret: UWORD [d0]

	register UWORD retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register struct Gadget* reg_a1 __asm("a1") = gadget;
	register ULONG reg_d0 __asm("d0") = position;
	register LONG reg_d1 __asm("d1") = numGad;
	register struct Requester* reg_a2 __asm("a2") = requester;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# UWORD AddGList([a0] struct Window* window, [a1] struct Gadget* gadget, [d0] ULONG position, [d1] LONG numGad, [a2] struct Requester* requester)\n\t"
		"jsr -438(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
	return retVal;
}

inline UWORD RemoveGList(struct Window* remPtr, struct Gadget* gadget, LONG numGad)
{
	// LVO: -444
	// remPtr [a0]
	// gadget [a1]
	// numGad [d0]
	// ret: UWORD [d0]

	register UWORD retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = remPtr;
	register struct Gadget* reg_a1 __asm("a1") = gadget;
	register LONG reg_d0 __asm("d0") = numGad;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# UWORD RemoveGList([a0] struct Window* remPtr, [a1] struct Gadget* gadget, [d0] LONG numGad)\n\t"
		"jsr -444(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ActivateWindow(struct Window* window)
{
	// LVO: -450
	// window [a0]

	register struct Window* reg_a0 __asm("a0") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ActivateWindow([a0] struct Window* window)\n\t"
		"jsr -450(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID RefreshWindowFrame(struct Window* window)
{
	// LVO: -456
	// window [a0]

	register struct Window* reg_a0 __asm("a0") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID RefreshWindowFrame([a0] struct Window* window)\n\t"
		"jsr -456(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL ActivateGadget(struct Gadget* gadgets, struct Window* window, struct Requester* requester)
{
	// LVO: -462
	// gadgets [a0]
	// window [a1]
	// requester [a2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Gadget* reg_a0 __asm("a0") = gadgets;
	register struct Window* reg_a1 __asm("a1") = window;
	register struct Requester* reg_a2 __asm("a2") = requester;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL ActivateGadget([a0] struct Gadget* gadgets, [a1] struct Window* window, [a2] struct Requester* requester)\n\t"
		"jsr -462(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
	return retVal;
}

inline VOID NewModifyProp(struct Gadget* gadget, struct Window* window, struct Requester* requester, ULONG flags, ULONG horizPot, ULONG vertPot, ULONG horizBody, ULONG vertBody, LONG numGad)
{
	// LVO: -468
	// gadget [a0]
	// window [a1]
	// requester [a2]
	// flags [d0]
	// horizPot [d1]
	// vertPot [d2]
	// horizBody [d3]
	// vertBody [d4]
	// numGad [d5]

	register struct Gadget* reg_a0 __asm("a0") = gadget;
	register struct Window* reg_a1 __asm("a1") = window;
	register struct Requester* reg_a2 __asm("a2") = requester;
	register ULONG reg_d0 __asm("d0") = flags;
	register ULONG reg_d1 __asm("d1") = horizPot;
	register ULONG reg_d2 __asm("d2") = vertPot;
	register ULONG reg_d3 __asm("d3") = horizBody;
	register ULONG reg_d4 __asm("d4") = vertBody;
	register LONG reg_d5 __asm("d5") = numGad;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID NewModifyProp([a0] struct Gadget* gadget, [a1] struct Window* window, [a2] struct Requester* requester, [d0] ULONG flags, [d1] ULONG horizPot, [d2] ULONG vertPot, [d3] ULONG horizBody, [d4] ULONG vertBody, [d5] LONG numGad)\n\t"
		"jsr -468(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "d2", "d3", "d4", "d5"
	);
}

inline LONG QueryOverscan(ULONG displayID, struct Rectangle* rect, LONG oScanType)
{
	// LVO: -474
	// displayID [a0]
	// rect [a1]
	// oScanType [d0]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register ULONG reg_a0 __asm("a0") = displayID;
	register struct Rectangle* reg_a1 __asm("a1") = rect;
	register LONG reg_d0 __asm("d0") = oScanType;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# LONG QueryOverscan([a0] ULONG displayID, [a1] struct Rectangle* rect, [d0] LONG oScanType)\n\t"
		"jsr -474(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID MoveWindowInFrontOf(struct Window* window, struct Window* behindWindow)
{
	// LVO: -480
	// window [a0]
	// behindWindow [a1]

	register struct Window* reg_a0 __asm("a0") = window;
	register struct Window* reg_a1 __asm("a1") = behindWindow;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID MoveWindowInFrontOf([a0] struct Window* window, [a1] struct Window* behindWindow)\n\t"
		"jsr -480(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ChangeWindowBox(struct Window* window, LONG left, LONG top, LONG width, LONG height)
{
	// LVO: -486
	// window [a0]
	// left [d0]
	// top [d1]
	// width [d2]
	// height [d3]

	register struct Window* reg_a0 __asm("a0") = window;
	register LONG reg_d0 __asm("d0") = left;
	register LONG reg_d1 __asm("d1") = top;
	register LONG reg_d2 __asm("d2") = width;
	register LONG reg_d3 __asm("d3") = height;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ChangeWindowBox([a0] struct Window* window, [d0] LONG left, [d1] LONG top, [d2] LONG width, [d3] LONG height)\n\t"
		"jsr -486(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
}

inline LONG SetMouseQueue(struct Window* window, ULONG queueLength)
{
	// LVO: -498
	// window [a0]
	// queueLength [d0]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register ULONG reg_d0 __asm("d0") = queueLength;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# LONG SetMouseQueue([a0] struct Window* window, [d0] ULONG queueLength)\n\t"
		"jsr -498(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ZipWindow(struct Window* window)
{
	// LVO: -504
	// window [a0]

	register struct Window* reg_a0 __asm("a0") = window;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ZipWindow([a0] struct Window* window)\n\t"
		"jsr -504(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID UnlockPubScreen(CONST_STRPTR name, struct Screen* screen)
{
	// LVO: -516
	// name [a0]
	// screen [a1]

	register CONST_STRPTR reg_a0 __asm("a0") = name;
	register struct Screen* reg_a1 __asm("a1") = screen;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID UnlockPubScreen([a0] CONST_STRPTR name, [a1] struct Screen* screen)\n\t"
		"jsr -516(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID UnlockPubScreenList()
{
	// LVO: -528

	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID UnlockPubScreenList()\n\t"
		"jsr -528(a6)\n\t"
		: 
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline STRPTR NextPubScreen(CONST struct Screen* screen, STRPTR namebuf)
{
	// LVO: -534
	// screen [a0]
	// namebuf [a1]
	// ret: STRPTR [d0]

	register STRPTR retVal __asm("d0");

	register CONST struct Screen* reg_a0 __asm("a0") = screen;
	register STRPTR reg_a1 __asm("a1") = namebuf;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# STRPTR NextPubScreen([a0] CONST struct Screen* screen, [a1] STRPTR namebuf)\n\t"
		"jsr -534(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID SetDefaultPubScreen(CONST_STRPTR name)
{
	// LVO: -540
	// name [a0]

	register CONST_STRPTR reg_a0 __asm("a0") = name;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID SetDefaultPubScreen([a0] CONST_STRPTR name)\n\t"
		"jsr -540(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline UWORD SetPubScreenModes(ULONG modes)
{
	// LVO: -546
	// modes [d0]
	// ret: UWORD [d0]

	register UWORD retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = modes;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# UWORD SetPubScreenModes([d0] ULONG modes)\n\t"
		"jsr -546(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline UWORD PubScreenStatus(struct Screen* screen, ULONG statusFlags)
{
	// LVO: -552
	// screen [a0]
	// statusFlags [d0]
	// ret: UWORD [d0]

	register UWORD retVal __asm("d0");

	register struct Screen* reg_a0 __asm("a0") = screen;
	register ULONG reg_d0 __asm("d0") = statusFlags;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# UWORD PubScreenStatus([a0] struct Screen* screen, [d0] ULONG statusFlags)\n\t"
		"jsr -552(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ReleaseGIRPort(struct RastPort* rp)
{
	// LVO: -564
	// rp [a0]

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ReleaseGIRPort([a0] struct RastPort* rp)\n\t"
		"jsr -564(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID GadgetMouse(struct Gadget* gadget, struct GadgetInfo* gInfo, WORD* mousePoint)
{
	// LVO: -570
	// gadget [a0]
	// gInfo [a1]
	// mousePoint [a2]

	register struct Gadget* reg_a0 __asm("a0") = gadget;
	register struct GadgetInfo* reg_a1 __asm("a1") = gInfo;
	register WORD* reg_a2 __asm("a2") = mousePoint;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID GadgetMouse([a0] struct Gadget* gadget, [a1] struct GadgetInfo* gInfo, [a2] WORD* mousePoint)\n\t"
		"jsr -570(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline VOID GetDefaultPubScreen(STRPTR nameBuffer)
{
	// LVO: -582
	// nameBuffer [a0]

	register STRPTR reg_a0 __asm("a0") = nameBuffer;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID GetDefaultPubScreen([a0] STRPTR nameBuffer)\n\t"
		"jsr -582(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG EasyRequestArgs(struct Window* window, CONST struct EasyStruct* easyStruct, ULONG* idcmpPtr, CONST APTR args)
{
	// LVO: -588
	// window [a0]
	// easyStruct [a1]
	// idcmpPtr [a2]
	// args [a3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register CONST struct EasyStruct* reg_a1 __asm("a1") = easyStruct;
	register ULONG* reg_a2 __asm("a2") = idcmpPtr;
	register CONST APTR reg_a3 __asm("a3") = args;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# LONG EasyRequestArgs([a0] struct Window* window, [a1] CONST struct EasyStruct* easyStruct, [a2] ULONG* idcmpPtr, [a3] CONST APTR args)\n\t"
		"jsr -588(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "a3"
	);
	return retVal;
}

inline LONG SysReqHandler(struct Window* window, ULONG* idcmpPtr, LONG waitInput)
{
	// LVO: -600
	// window [a0]
	// idcmpPtr [a1]
	// waitInput [d0]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register ULONG* reg_a1 __asm("a1") = idcmpPtr;
	register LONG reg_d0 __asm("d0") = waitInput;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# LONG SysReqHandler([a0] struct Window* window, [a1] ULONG* idcmpPtr, [d0] LONG waitInput)\n\t"
		"jsr -600(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID DrawImageState(struct RastPort* rp, struct Image* image, LONG leftOffset, LONG topOffset, ULONG state, CONST struct DrawInfo* drawInfo)
{
	// LVO: -618
	// rp [a0]
	// image [a1]
	// leftOffset [d0]
	// topOffset [d1]
	// state [d2]
	// drawInfo [a2]

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register struct Image* reg_a1 __asm("a1") = image;
	register LONG reg_d0 __asm("d0") = leftOffset;
	register LONG reg_d1 __asm("d1") = topOffset;
	register ULONG reg_d2 __asm("d2") = state;
	register CONST struct DrawInfo* reg_a2 __asm("a2") = drawInfo;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID DrawImageState([a0] struct RastPort* rp, [a1] struct Image* image, [d0] LONG leftOffset, [d1] LONG topOffset, [d2] ULONG state, [a2] CONST struct DrawInfo* drawInfo)\n\t"
		"jsr -618(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "a2"
	);
}

inline BOOL PointInImage(ULONG point, struct Image* image)
{
	// LVO: -624
	// point [d0]
	// image [a0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = point;
	register struct Image* reg_a0 __asm("a0") = image;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL PointInImage([d0] ULONG point, [a0] struct Image* image)\n\t"
		"jsr -624(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID EraseImage(struct RastPort* rp, struct Image* image, LONG leftOffset, LONG topOffset)
{
	// LVO: -630
	// rp [a0]
	// image [a1]
	// leftOffset [d0]
	// topOffset [d1]

	register struct RastPort* reg_a0 __asm("a0") = rp;
	register struct Image* reg_a1 __asm("a1") = image;
	register LONG reg_d0 __asm("d0") = leftOffset;
	register LONG reg_d1 __asm("d1") = topOffset;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID EraseImage([a0] struct RastPort* rp, [a1] struct Image* image, [d0] LONG leftOffset, [d1] LONG topOffset)\n\t"
		"jsr -630(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline APTR NewObjectA(struct IClass* classPtr, CONST_STRPTR classID, CONST struct TagItem* tagList)
{
	// LVO: -636
	// classPtr [a0]
	// classID [a1]
	// tagList [a2]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register struct IClass* reg_a0 __asm("a0") = classPtr;
	register CONST_STRPTR reg_a1 __asm("a1") = classID;
	register CONST struct TagItem* reg_a2 __asm("a2") = tagList;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# APTR NewObjectA([a0] struct IClass* classPtr, [a1] CONST_STRPTR classID, [a2] CONST struct TagItem* tagList)\n\t"
		"jsr -636(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
	return retVal;
}

inline VOID DisposeObject(APTR object)
{
	// LVO: -642
	// object [a0]

	register APTR reg_a0 __asm("a0") = object;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID DisposeObject([a0] APTR object)\n\t"
		"jsr -642(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG SetAttrsA(APTR object, CONST struct TagItem* tagList)
{
	// LVO: -648
	// object [a0]
	// tagList [a1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register APTR reg_a0 __asm("a0") = object;
	register CONST struct TagItem* reg_a1 __asm("a1") = tagList;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# ULONG SetAttrsA([a0] APTR object, [a1] CONST struct TagItem* tagList)\n\t"
		"jsr -648(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG GetAttr(ULONG attrID, APTR object, ULONG* storagePtr)
{
	// LVO: -654
	// attrID [d0]
	// object [a0]
	// storagePtr [a1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = attrID;
	register APTR reg_a0 __asm("a0") = object;
	register ULONG* reg_a1 __asm("a1") = storagePtr;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# ULONG GetAttr([d0] ULONG attrID, [a0] APTR object, [a1] ULONG* storagePtr)\n\t"
		"jsr -654(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG SetGadgetAttrsA(struct Gadget* gadget, struct Window* window, struct Requester* requester, CONST struct TagItem* tagList)
{
	// LVO: -660
	// gadget [a0]
	// window [a1]
	// requester [a2]
	// tagList [a3]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct Gadget* reg_a0 __asm("a0") = gadget;
	register struct Window* reg_a1 __asm("a1") = window;
	register struct Requester* reg_a2 __asm("a2") = requester;
	register CONST struct TagItem* reg_a3 __asm("a3") = tagList;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# ULONG SetGadgetAttrsA([a0] struct Gadget* gadget, [a1] struct Window* window, [a2] struct Requester* requester, [a3] CONST struct TagItem* tagList)\n\t"
		"jsr -660(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "a3"
	);
	return retVal;
}

inline APTR NextObject(APTR objectPtrPtr)
{
	// LVO: -666
	// objectPtrPtr [a0]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register APTR reg_a0 __asm("a0") = objectPtrPtr;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# APTR NextObject([a0] APTR objectPtrPtr)\n\t"
		"jsr -666(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID AddClass(struct IClass* classPtr)
{
	// LVO: -684
	// classPtr [a0]

	register struct IClass* reg_a0 __asm("a0") = classPtr;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID AddClass([a0] struct IClass* classPtr)\n\t"
		"jsr -684(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID FreeScreenDrawInfo(struct Screen* screen, struct DrawInfo* drawInfo)
{
	// LVO: -696
	// screen [a0]
	// drawInfo [a1]

	register struct Screen* reg_a0 __asm("a0") = screen;
	register struct DrawInfo* reg_a1 __asm("a1") = drawInfo;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID FreeScreenDrawInfo([a0] struct Screen* screen, [a1] struct DrawInfo* drawInfo)\n\t"
		"jsr -696(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL ResetMenuStrip(struct Window* window, struct Menu* menu)
{
	// LVO: -702
	// window [a0]
	// menu [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Window* reg_a0 __asm("a0") = window;
	register struct Menu* reg_a1 __asm("a1") = menu;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL ResetMenuStrip([a0] struct Window* window, [a1] struct Menu* menu)\n\t"
		"jsr -702(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID RemoveClass(struct IClass* classPtr)
{
	// LVO: -708
	// classPtr [a0]

	register struct IClass* reg_a0 __asm("a0") = classPtr;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID RemoveClass([a0] struct IClass* classPtr)\n\t"
		"jsr -708(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL FreeClass(struct IClass* classPtr)
{
	// LVO: -714
	// classPtr [a0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct IClass* reg_a0 __asm("a0") = classPtr;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL FreeClass([a0] struct IClass* classPtr)\n\t"
		"jsr -714(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreeScreenBuffer(struct Screen* sc, struct ScreenBuffer* sb)
{
	// LVO: -774
	// sc [a0]
	// sb [a1]

	register struct Screen* reg_a0 __asm("a0") = sc;
	register struct ScreenBuffer* reg_a1 __asm("a1") = sb;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID FreeScreenBuffer([a0] struct Screen* sc, [a1] struct ScreenBuffer* sb)\n\t"
		"jsr -774(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG ChangeScreenBuffer(struct Screen* sc, struct ScreenBuffer* sb)
{
	// LVO: -780
	// sc [a0]
	// sb [a1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct Screen* reg_a0 __asm("a0") = sc;
	register struct ScreenBuffer* reg_a1 __asm("a1") = sb;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# ULONG ChangeScreenBuffer([a0] struct Screen* sc, [a1] struct ScreenBuffer* sb)\n\t"
		"jsr -780(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ScreenDepth(struct Screen* screen, ULONG flags, APTR reserved)
{
	// LVO: -786
	// screen [a0]
	// flags [d0]
	// reserved [a1]

	register struct Screen* reg_a0 __asm("a0") = screen;
	register ULONG reg_d0 __asm("d0") = flags;
	register APTR reg_a1 __asm("a1") = reserved;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ScreenDepth([a0] struct Screen* screen, [d0] ULONG flags, [a1] APTR reserved)\n\t"
		"jsr -786(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ScreenPosition(struct Screen* screen, ULONG flags, LONG x1, LONG y1, LONG x2, LONG y2)
{
	// LVO: -792
	// screen [a0]
	// flags [d0]
	// x1 [d1]
	// y1 [d2]
	// x2 [d3]
	// y2 [d4]

	register struct Screen* reg_a0 __asm("a0") = screen;
	register ULONG reg_d0 __asm("d0") = flags;
	register LONG reg_d1 __asm("d1") = x1;
	register LONG reg_d2 __asm("d2") = y1;
	register LONG reg_d3 __asm("d3") = x2;
	register LONG reg_d4 __asm("d4") = y2;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ScreenPosition([a0] struct Screen* screen, [d0] ULONG flags, [d1] LONG x1, [d2] LONG y1, [d3] LONG x2, [d4] LONG y2)\n\t"
		"jsr -792(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4"
	);
}

inline VOID ScrollWindowRaster(struct Window* win, LONG dx, LONG dy, LONG xMin, LONG yMin, LONG xMax, LONG yMax)
{
	// LVO: -798
	// win [a1]
	// dx [d0]
	// dy [d1]
	// xMin [d2]
	// yMin [d3]
	// xMax [d4]
	// yMax [d5]

	register struct Window* reg_a1 __asm("a1") = win;
	register LONG reg_d0 __asm("d0") = dx;
	register LONG reg_d1 __asm("d1") = dy;
	register LONG reg_d2 __asm("d2") = xMin;
	register LONG reg_d3 __asm("d3") = yMin;
	register LONG reg_d4 __asm("d4") = xMax;
	register LONG reg_d5 __asm("d5") = yMax;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID ScrollWindowRaster([a1] struct Window* win, [d0] LONG dx, [d1] LONG dy, [d2] LONG xMin, [d3] LONG yMin, [d4] LONG xMax, [d5] LONG yMax)\n\t"
		"jsr -798(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5"
	);
}

inline VOID LendMenus(struct Window* fromwindow, struct Window* towindow)
{
	// LVO: -804
	// fromwindow [a0]
	// towindow [a1]

	register struct Window* reg_a0 __asm("a0") = fromwindow;
	register struct Window* reg_a1 __asm("a1") = towindow;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID LendMenus([a0] struct Window* fromwindow, [a1] struct Window* towindow)\n\t"
		"jsr -804(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG DoGadgetMethodA(struct Gadget* gad, struct Window* win, struct Requester* req, Msg message)
{
	// LVO: -810
	// gad [a0]
	// win [a1]
	// req [a2]
	// message [a3]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct Gadget* reg_a0 __asm("a0") = gad;
	register struct Window* reg_a1 __asm("a1") = win;
	register struct Requester* reg_a2 __asm("a2") = req;
	register Msg reg_a3 __asm("a3") = message;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# ULONG DoGadgetMethodA([a0] struct Gadget* gad, [a1] struct Window* win, [a2] struct Requester* req, [a3] Msg message)\n\t"
		"jsr -810(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "a3"
	);
	return retVal;
}

inline VOID SetWindowPointerA(struct Window* win, CONST struct TagItem* taglist)
{
	// LVO: -816
	// win [a0]
	// taglist [a1]

	register struct Window* reg_a0 __asm("a0") = win;
	register CONST struct TagItem* reg_a1 __asm("a1") = taglist;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID SetWindowPointerA([a0] struct Window* win, [a1] CONST struct TagItem* taglist)\n\t"
		"jsr -816(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL TimedDisplayAlert(ULONG alertNumber, CONST_STRPTR string, ULONG height, ULONG time)
{
	// LVO: -822
	// alertNumber [d0]
	// string [a0]
	// height [d1]
	// time [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = alertNumber;
	register CONST_STRPTR reg_a0 __asm("a0") = string;
	register ULONG reg_d1 __asm("d1") = height;
	register ULONG reg_a1 __asm("a1") = time;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# BOOL TimedDisplayAlert([d0] ULONG alertNumber, [a0] CONST_STRPTR string, [d1] ULONG height, [a1] ULONG time)\n\t"
		"jsr -822(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a0),"r"(reg_d1),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID HelpControl(struct Window* win, ULONG flags)
{
	// LVO: -828
	// win [a0]
	// flags [d0]

	register struct Window* reg_a0 __asm("a0") = win;
	register ULONG reg_d0 __asm("d0") = flags;
	register void* reg_a6 __asm("a6") = IntuitionBase;
	__asm volatile (
		"# VOID HelpControl([a0] struct Window* win, [d0] ULONG flags)\n\t"
		"jsr -828(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

#endif
