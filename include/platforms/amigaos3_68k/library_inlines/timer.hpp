#ifndef _INLINE_AMIGA_TIMER_HPP_
#define _INLINE_AMIGA_TIMER_HPP_
inline VOID AddTime(struct timeval* dest, CONST struct timeval* src)
{
	// LVO: -42
	// dest [a0]
	// src [a1]

	register struct timeval* reg_a0 __asm("a0") = dest;
	register CONST struct timeval* reg_a1 __asm("a1") = src;
	register void* reg_a6 __asm("a6") = TimerBase;
	__asm volatile (
		"# VOID AddTime([a0] struct timeval* dest, [a1] CONST struct timeval* src)\n\t"
		"jsr -42(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID SubTime(struct timeval* dest, CONST struct timeval* src)
{
	// LVO: -48
	// dest [a0]
	// src [a1]

	register struct timeval* reg_a0 __asm("a0") = dest;
	register CONST struct timeval* reg_a1 __asm("a1") = src;
	register void* reg_a6 __asm("a6") = TimerBase;
	__asm volatile (
		"# VOID SubTime([a0] struct timeval* dest, [a1] CONST struct timeval* src)\n\t"
		"jsr -48(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG CmpTime(CONST struct timeval* dest, CONST struct timeval* src)
{
	// LVO: -54
	// dest [a0]
	// src [a1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST struct timeval* reg_a0 __asm("a0") = dest;
	register CONST struct timeval* reg_a1 __asm("a1") = src;
	register void* reg_a6 __asm("a6") = TimerBase;
	__asm volatile (
		"# LONG CmpTime([a0] CONST struct timeval* dest, [a1] CONST struct timeval* src)\n\t"
		"jsr -54(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG ReadEClock(struct EClockVal* dest)
{
	// LVO: -60
	// dest [a0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct EClockVal* reg_a0 __asm("a0") = dest;
	register void* reg_a6 __asm("a6") = TimerBase;
	__asm volatile (
		"# ULONG ReadEClock([a0] struct EClockVal* dest)\n\t"
		"jsr -60(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID GetSysTime(struct timeval* dest)
{
	// LVO: -66
	// dest [a0]

	register struct timeval* reg_a0 __asm("a0") = dest;
	register void* reg_a6 __asm("a6") = TimerBase;
	__asm volatile (
		"# VOID GetSysTime([a0] struct timeval* dest)\n\t"
		"jsr -66(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

#endif
