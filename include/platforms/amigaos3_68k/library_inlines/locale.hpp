#ifndef _INLINE_AMIGA_LOCALE_HPP_
#define _INLINE_AMIGA_LOCALE_HPP_
inline VOID CloseCatalog(struct Catalog* catalog)
{
	// LVO: -36
	// catalog [a0]

	register struct Catalog* reg_a0 __asm("a0") = catalog;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# VOID CloseCatalog([a0] struct Catalog* catalog)\n\t"
		"jsr -36(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID CloseLocale(struct Locale* locale)
{
	// LVO: -42
	// locale [a0]

	register struct Locale* reg_a0 __asm("a0") = locale;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# VOID CloseLocale([a0] struct Locale* locale)\n\t"
		"jsr -42(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG ConvToLower(struct Locale* locale, ULONG character)
{
	// LVO: -48
	// locale [a0]
	// character [d0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# ULONG ConvToLower([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -48(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG ConvToUpper(struct Locale* locale, ULONG character)
{
	// LVO: -54
	// locale [a0]
	// character [d0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# ULONG ConvToUpper([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -54(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FormatDate(struct Locale* locale, STRPTR fmtTemplate, struct DateStamp* date, struct Hook* putCharFunc)
{
	// LVO: -60
	// locale [a0]
	// fmtTemplate [a1]
	// date [a2]
	// putCharFunc [a3]

	register struct Locale* reg_a0 __asm("a0") = locale;
	register STRPTR reg_a1 __asm("a1") = fmtTemplate;
	register struct DateStamp* reg_a2 __asm("a2") = date;
	register struct Hook* reg_a3 __asm("a3") = putCharFunc;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# VOID FormatDate([a0] struct Locale* locale, [a1] STRPTR fmtTemplate, [a2] struct DateStamp* date, [a3] struct Hook* putCharFunc)\n\t"
		"jsr -60(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "a3"
	);
}

inline APTR FormatString(struct Locale* locale, STRPTR fmtTemplate, APTR dataStream, struct Hook* putCharFunc)
{
	// LVO: -66
	// locale [a0]
	// fmtTemplate [a1]
	// dataStream [a2]
	// putCharFunc [a3]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register STRPTR reg_a1 __asm("a1") = fmtTemplate;
	register APTR reg_a2 __asm("a2") = dataStream;
	register struct Hook* reg_a3 __asm("a3") = putCharFunc;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# APTR FormatString([a0] struct Locale* locale, [a1] STRPTR fmtTemplate, [a2] APTR dataStream, [a3] struct Hook* putCharFunc)\n\t"
		"jsr -66(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "a3"
	);
	return retVal;
}

inline STRPTR GetCatalogStr(struct Catalog* catalog, LONG stringNum, STRPTR defaultString)
{
	// LVO: -72
	// catalog [a0]
	// stringNum [d0]
	// defaultString [a1]
	// ret: STRPTR [d0]

	register STRPTR retVal __asm("d0");

	register struct Catalog* reg_a0 __asm("a0") = catalog;
	register LONG reg_d0 __asm("d0") = stringNum;
	register STRPTR reg_a1 __asm("a1") = defaultString;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# STRPTR GetCatalogStr([a0] struct Catalog* catalog, [d0] LONG stringNum, [a1] STRPTR defaultString)\n\t"
		"jsr -72(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline STRPTR GetLocaleStr(struct Locale* locale, ULONG stringNum)
{
	// LVO: -78
	// locale [a0]
	// stringNum [d0]
	// ret: STRPTR [d0]

	register STRPTR retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = stringNum;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# STRPTR GetLocaleStr([a0] struct Locale* locale, [d0] ULONG stringNum)\n\t"
		"jsr -78(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL IsAlNum(struct Locale* locale, ULONG character)
{
	// LVO: -84
	// locale [a0]
	// character [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# BOOL IsAlNum([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -84(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL IsAlpha(struct Locale* locale, ULONG character)
{
	// LVO: -90
	// locale [a0]
	// character [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# BOOL IsAlpha([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -90(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL IsCntrl(struct Locale* locale, ULONG character)
{
	// LVO: -96
	// locale [a0]
	// character [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# BOOL IsCntrl([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -96(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL IsDigit(struct Locale* locale, ULONG character)
{
	// LVO: -102
	// locale [a0]
	// character [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# BOOL IsDigit([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -102(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL IsGraph(struct Locale* locale, ULONG character)
{
	// LVO: -108
	// locale [a0]
	// character [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# BOOL IsGraph([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -108(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL IsLower(struct Locale* locale, ULONG character)
{
	// LVO: -114
	// locale [a0]
	// character [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# BOOL IsLower([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -114(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL IsPrint(struct Locale* locale, ULONG character)
{
	// LVO: -120
	// locale [a0]
	// character [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# BOOL IsPrint([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -120(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL IsPunct(struct Locale* locale, ULONG character)
{
	// LVO: -126
	// locale [a0]
	// character [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# BOOL IsPunct([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -126(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL IsSpace(struct Locale* locale, ULONG character)
{
	// LVO: -132
	// locale [a0]
	// character [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# BOOL IsSpace([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -132(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL IsUpper(struct Locale* locale, ULONG character)
{
	// LVO: -138
	// locale [a0]
	// character [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# BOOL IsUpper([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -138(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL IsXDigit(struct Locale* locale, ULONG character)
{
	// LVO: -144
	// locale [a0]
	// character [d0]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register ULONG reg_d0 __asm("d0") = character;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# BOOL IsXDigit([a0] struct Locale* locale, [d0] ULONG character)\n\t"
		"jsr -144(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL ParseDate(struct Locale* locale, struct DateStamp* date, STRPTR fmtTemplate, struct Hook* getCharFunc)
{
	// LVO: -162
	// locale [a0]
	// date [a1]
	// fmtTemplate [a2]
	// getCharFunc [a3]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register struct DateStamp* reg_a1 __asm("a1") = date;
	register STRPTR reg_a2 __asm("a2") = fmtTemplate;
	register struct Hook* reg_a3 __asm("a3") = getCharFunc;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# BOOL ParseDate([a0] struct Locale* locale, [a1] struct DateStamp* date, [a2] STRPTR fmtTemplate, [a3] struct Hook* getCharFunc)\n\t"
		"jsr -162(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "a3"
	);
	return retVal;
}

inline ULONG StrConvert(struct Locale* locale, STRPTR string, APTR buffer, ULONG bufferSize, ULONG type)
{
	// LVO: -174
	// locale [a0]
	// string [a1]
	// buffer [a2]
	// bufferSize [d0]
	// type [d1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register STRPTR reg_a1 __asm("a1") = string;
	register APTR reg_a2 __asm("a2") = buffer;
	register ULONG reg_d0 __asm("d0") = bufferSize;
	register ULONG reg_d1 __asm("d1") = type;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# ULONG StrConvert([a0] struct Locale* locale, [a1] STRPTR string, [a2] APTR buffer, [d0] ULONG bufferSize, [d1] ULONG type)\n\t"
		"jsr -174(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
	return retVal;
}

inline LONG StrnCmp(struct Locale* locale, STRPTR string1, STRPTR string2, LONG length, ULONG type)
{
	// LVO: -180
	// locale [a0]
	// string1 [a1]
	// string2 [a2]
	// length [d0]
	// type [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct Locale* reg_a0 __asm("a0") = locale;
	register STRPTR reg_a1 __asm("a1") = string1;
	register STRPTR reg_a2 __asm("a2") = string2;
	register LONG reg_d0 __asm("d0") = length;
	register ULONG reg_d1 __asm("d1") = type;
	register void* reg_a6 __asm("a6") = LocaleBase;
	__asm volatile (
		"# LONG StrnCmp([a0] struct Locale* locale, [a1] STRPTR string1, [a2] STRPTR string2, [d0] LONG length, [d1] ULONG type)\n\t"
		"jsr -180(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
	return retVal;
}

#endif
