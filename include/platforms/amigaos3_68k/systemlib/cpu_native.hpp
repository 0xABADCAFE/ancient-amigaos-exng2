///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/cpu.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Processor query, native implementation
//  Comment(s):
//  Library:      System
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifndef _EXNG2_SYSTEMLIB_CPU_NATIVE_HPP_
#	define _EXNG2_SYSTEMLIB_CPU_NATIVE_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  CPU
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class CPU {
	public:
		typedef enum {
			FP_DEFAULT,
			FP_HIGH,
			FP_LOW
		} FPPrec;

	public:
		static const char*	getCPUName() 			{ return cpuNames[cpuType()]; }
		static const char*	getFPUName() 			{ return fpuNames[fpuType()]; }
		static FPPrec				getPrecision()		{ return fpuPrecision; }
		static void					synchronise()			{ asm("\n\tnop\n"); }

		static void					flushDataCache(void* adr, uint32 l=0xFFFFFFFF);
		static void 				flushInstCache(void* adr, uint32 l=0xFFFFFFFF);
		static void 				flushAllCaches(void* adr, uint32 l=0xFFFFFFFF);
		static void 				setPrecision(FPPrec p);

	protected:
		// processor definitions are not public to discourage casual use
		enum {
			MC680x0			= 0,
			MC68020			= 1,
			MC68030			= 2,
			MC68040			= 3,
			MC68060			= 4
		};
		enum {
			MC6888x			= 0,
			MC68881			= 1,
			MC68882			= 2,
			MC68040FP		= 3,
			MC68040FPEM	= 4,
			MC68060FP		= 5,
			MC68060FPEM	= 6,
			SOFTFP			= 7
		};
		static sint32	cpuType();
		static sint32	fpuType();

	private:
		static FPPrec	fpuPrecision;
		static char*	cpuNames[];
		static char*	fpuNames[];

};


#endif
