#ifndef _INLINE_AMIGA_DOS_HPP_
#define _INLINE_AMIGA_DOS_HPP_
inline BPTR Open(CONST_STRPTR name, LONG accessMode)
{
	// LVO: -30
	// name [d1]
	// accessMode [d2]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register LONG reg_d2 __asm("d2") = accessMode;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR Open([d1] CONST_STRPTR name, [d2] LONG accessMode)\n\t"
		"jsr -30(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG Close(BPTR file)
{
	// LVO: -36
	// file [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = file;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG Close([d1] BPTR file)\n\t"
		"jsr -36(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG Read(BPTR file, APTR buffer, LONG length)
{
	// LVO: -42
	// file [d1]
	// buffer [d2]
	// length [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = file;
	register APTR reg_d2 __asm("d2") = buffer;
	register LONG reg_d3 __asm("d3") = length;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG Read([d1] BPTR file, [d2] APTR buffer, [d3] LONG length)\n\t"
		"jsr -42(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline LONG Write(BPTR file, CONST APTR buffer, LONG length)
{
	// LVO: -48
	// file [d1]
	// buffer [d2]
	// length [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = file;
	register CONST APTR reg_d2 __asm("d2") = buffer;
	register LONG reg_d3 __asm("d3") = length;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG Write([d1] BPTR file, [d2] CONST APTR buffer, [d3] LONG length)\n\t"
		"jsr -48(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline BPTR Input()
{
	// LVO: -54
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR Input()\n\t"
		"jsr -54(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BPTR Output()
{
	// LVO: -60
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR Output()\n\t"
		"jsr -60(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG Seek(BPTR file, LONG position, LONG offset)
{
	// LVO: -66
	// file [d1]
	// position [d2]
	// offset [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = file;
	register LONG reg_d2 __asm("d2") = position;
	register LONG reg_d3 __asm("d3") = offset;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG Seek([d1] BPTR file, [d2] LONG position, [d3] LONG offset)\n\t"
		"jsr -66(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline LONG DeleteFile(CONST_STRPTR name)
{
	// LVO: -72
	// name [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG DeleteFile([d1] CONST_STRPTR name)\n\t"
		"jsr -72(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG Rename(CONST_STRPTR oldName, CONST_STRPTR newName)
{
	// LVO: -78
	// oldName [d1]
	// newName [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = oldName;
	register CONST_STRPTR reg_d2 __asm("d2") = newName;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG Rename([d1] CONST_STRPTR oldName, [d2] CONST_STRPTR newName)\n\t"
		"jsr -78(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline BPTR Lock(CONST_STRPTR name, LONG type)
{
	// LVO: -84
	// name [d1]
	// type [d2]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register LONG reg_d2 __asm("d2") = type;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR Lock([d1] CONST_STRPTR name, [d2] LONG type)\n\t"
		"jsr -84(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline VOID UnLock(BPTR lock)
{
	// LVO: -90
	// lock [d1]

	register BPTR reg_d1 __asm("d1") = lock;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID UnLock([d1] BPTR lock)\n\t"
		"jsr -90(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BPTR DupLock(BPTR lock)
{
	// LVO: -96
	// lock [d1]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = lock;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR DupLock([d1] BPTR lock)\n\t"
		"jsr -96(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG Examine(BPTR lock, struct FileInfoBlock* fileInfoBlock)
{
	// LVO: -102
	// lock [d1]
	// fileInfoBlock [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = lock;
	register struct FileInfoBlock* reg_d2 __asm("d2") = fileInfoBlock;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG Examine([d1] BPTR lock, [d2] struct FileInfoBlock* fileInfoBlock)\n\t"
		"jsr -102(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG ExNext(BPTR lock, struct FileInfoBlock* fileInfoBlock)
{
	// LVO: -108
	// lock [d1]
	// fileInfoBlock [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = lock;
	register struct FileInfoBlock* reg_d2 __asm("d2") = fileInfoBlock;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG ExNext([d1] BPTR lock, [d2] struct FileInfoBlock* fileInfoBlock)\n\t"
		"jsr -108(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG Info(BPTR lock, struct InfoData* parameterBlock)
{
	// LVO: -114
	// lock [d1]
	// parameterBlock [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = lock;
	register struct InfoData* reg_d2 __asm("d2") = parameterBlock;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG Info([d1] BPTR lock, [d2] struct InfoData* parameterBlock)\n\t"
		"jsr -114(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline BPTR CreateDir(CONST_STRPTR name)
{
	// LVO: -120
	// name [d1]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR CreateDir([d1] CONST_STRPTR name)\n\t"
		"jsr -120(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BPTR CurrentDir(BPTR lock)
{
	// LVO: -126
	// lock [d1]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = lock;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR CurrentDir([d1] BPTR lock)\n\t"
		"jsr -126(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG IoErr()
{
	// LVO: -132
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG IoErr()\n\t"
		"jsr -132(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID Exit(LONG returnCode)
{
	// LVO: -144
	// returnCode [d1]

	register LONG reg_d1 __asm("d1") = returnCode;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID Exit([d1] LONG returnCode)\n\t"
		"jsr -144(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BPTR LoadSeg(CONST_STRPTR name)
{
	// LVO: -150
	// name [d1]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR LoadSeg([d1] CONST_STRPTR name)\n\t"
		"jsr -150(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID UnLoadSeg(BPTR seglist)
{
	// LVO: -156
	// seglist [d1]

	register BPTR reg_d1 __asm("d1") = seglist;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID UnLoadSeg([d1] BPTR seglist)\n\t"
		"jsr -156(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG SetComment(CONST_STRPTR name, CONST_STRPTR comment)
{
	// LVO: -180
	// name [d1]
	// comment [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register CONST_STRPTR reg_d2 __asm("d2") = comment;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG SetComment([d1] CONST_STRPTR name, [d2] CONST_STRPTR comment)\n\t"
		"jsr -180(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG SetProtection(CONST_STRPTR name, LONG protect)
{
	// LVO: -186
	// name [d1]
	// protect [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register LONG reg_d2 __asm("d2") = protect;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG SetProtection([d1] CONST_STRPTR name, [d2] LONG protect)\n\t"
		"jsr -186(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline VOID Delay(LONG timeout)
{
	// LVO: -198
	// timeout [d1]

	register LONG reg_d1 __asm("d1") = timeout;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID Delay([d1] LONG timeout)\n\t"
		"jsr -198(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG WaitForChar(BPTR file, LONG timeout)
{
	// LVO: -204
	// file [d1]
	// timeout [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = file;
	register LONG reg_d2 __asm("d2") = timeout;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG WaitForChar([d1] BPTR file, [d2] LONG timeout)\n\t"
		"jsr -204(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline BPTR ParentDir(BPTR lock)
{
	// LVO: -210
	// lock [d1]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = lock;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR ParentDir([d1] BPTR lock)\n\t"
		"jsr -210(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG IsInteractive(BPTR file)
{
	// LVO: -216
	// file [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = file;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG IsInteractive([d1] BPTR file)\n\t"
		"jsr -216(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG Execute(CONST_STRPTR string, BPTR file, BPTR file2)
{
	// LVO: -222
	// string [d1]
	// file [d2]
	// file2 [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = string;
	register BPTR reg_d2 __asm("d2") = file;
	register BPTR reg_d3 __asm("d3") = file2;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG Execute([d1] CONST_STRPTR string, [d2] BPTR file, [d3] BPTR file2)\n\t"
		"jsr -222(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline APTR AllocDosObject(ULONG type, CONST struct TagItem* tags)
{
	// LVO: -228
	// type [d1]
	// tags [d2]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register ULONG reg_d1 __asm("d1") = type;
	register CONST struct TagItem* reg_d2 __asm("d2") = tags;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# APTR AllocDosObject([d1] ULONG type, [d2] CONST struct TagItem* tags)\n\t"
		"jsr -228(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline VOID FreeDosObject(ULONG type, APTR ptr)
{
	// LVO: -234
	// type [d1]
	// ptr [d2]

	register ULONG reg_d1 __asm("d1") = type;
	register APTR reg_d2 __asm("d2") = ptr;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID FreeDosObject([d1] ULONG type, [d2] APTR ptr)\n\t"
		"jsr -234(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
}

inline LONG DoPkt(struct MsgPort* port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4, LONG arg5)
{
	// LVO: -240
	// port [d1]
	// action [d2]
	// arg1 [d3]
	// arg2 [d4]
	// arg3 [d5]
	// arg4 [d6]
	// arg5 [d7]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct MsgPort* reg_d1 __asm("d1") = port;
	register LONG reg_d2 __asm("d2") = action;
	register LONG reg_d3 __asm("d3") = arg1;
	register LONG reg_d4 __asm("d4") = arg2;
	register LONG reg_d5 __asm("d5") = arg3;
	register LONG reg_d6 __asm("d6") = arg4;
	register LONG reg_d7 __asm("d7") = arg5;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG DoPkt([d1] struct MsgPort* port, [d2] LONG action, [d3] LONG arg1, [d4] LONG arg2, [d5] LONG arg3, [d6] LONG arg4, [d7] LONG arg5)\n\t"
		"jsr -240(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_d6),"r"(reg_d7),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5", "d6", "d7"
	);
	return retVal;
}

inline VOID SendPkt(struct DosPacket* dp, struct MsgPort* port, struct MsgPort* replyport)
{
	// LVO: -246
	// dp [d1]
	// port [d2]
	// replyport [d3]

	register struct DosPacket* reg_d1 __asm("d1") = dp;
	register struct MsgPort* reg_d2 __asm("d2") = port;
	register struct MsgPort* reg_d3 __asm("d3") = replyport;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID SendPkt([d1] struct DosPacket* dp, [d2] struct MsgPort* port, [d3] struct MsgPort* replyport)\n\t"
		"jsr -246(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
}

inline VOID ReplyPkt(struct DosPacket* dp, LONG res1, LONG res2)
{
	// LVO: -258
	// dp [d1]
	// res1 [d2]
	// res2 [d3]

	register struct DosPacket* reg_d1 __asm("d1") = dp;
	register LONG reg_d2 __asm("d2") = res1;
	register LONG reg_d3 __asm("d3") = res2;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID ReplyPkt([d1] struct DosPacket* dp, [d2] LONG res1, [d3] LONG res2)\n\t"
		"jsr -258(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
}

inline VOID AbortPkt(struct MsgPort* port, struct DosPacket* pkt)
{
	// LVO: -264
	// port [d1]
	// pkt [d2]

	register struct MsgPort* reg_d1 __asm("d1") = port;
	register struct DosPacket* reg_d2 __asm("d2") = pkt;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID AbortPkt([d1] struct MsgPort* port, [d2] struct DosPacket* pkt)\n\t"
		"jsr -264(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
}

inline BOOL LockRecord(BPTR fh, ULONG offset, ULONG length, ULONG mode, ULONG timeout)
{
	// LVO: -270
	// fh [d1]
	// offset [d2]
	// length [d3]
	// mode [d4]
	// timeout [d5]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register ULONG reg_d2 __asm("d2") = offset;
	register ULONG reg_d3 __asm("d3") = length;
	register ULONG reg_d4 __asm("d4") = mode;
	register ULONG reg_d5 __asm("d5") = timeout;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL LockRecord([d1] BPTR fh, [d2] ULONG offset, [d3] ULONG length, [d4] ULONG mode, [d5] ULONG timeout)\n\t"
		"jsr -270(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5"
	);
	return retVal;
}

inline BOOL LockRecords(struct RecordLock* recArray, ULONG timeout)
{
	// LVO: -276
	// recArray [d1]
	// timeout [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct RecordLock* reg_d1 __asm("d1") = recArray;
	register ULONG reg_d2 __asm("d2") = timeout;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL LockRecords([d1] struct RecordLock* recArray, [d2] ULONG timeout)\n\t"
		"jsr -276(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline BOOL UnLockRecord(BPTR fh, ULONG offset, ULONG length)
{
	// LVO: -282
	// fh [d1]
	// offset [d2]
	// length [d3]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register ULONG reg_d2 __asm("d2") = offset;
	register ULONG reg_d3 __asm("d3") = length;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL UnLockRecord([d1] BPTR fh, [d2] ULONG offset, [d3] ULONG length)\n\t"
		"jsr -282(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline BOOL UnLockRecords(struct RecordLock* recArray)
{
	// LVO: -288
	// recArray [d1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct RecordLock* reg_d1 __asm("d1") = recArray;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL UnLockRecords([d1] struct RecordLock* recArray)\n\t"
		"jsr -288(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BPTR SelectInput(BPTR fh)
{
	// LVO: -294
	// fh [d1]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR SelectInput([d1] BPTR fh)\n\t"
		"jsr -294(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BPTR SelectOutput(BPTR fh)
{
	// LVO: -300
	// fh [d1]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR SelectOutput([d1] BPTR fh)\n\t"
		"jsr -300(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG FGetC(BPTR fh)
{
	// LVO: -306
	// fh [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG FGetC([d1] BPTR fh)\n\t"
		"jsr -306(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG FPutC(BPTR fh, LONG ch)
{
	// LVO: -312
	// fh [d1]
	// ch [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register LONG reg_d2 __asm("d2") = ch;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG FPutC([d1] BPTR fh, [d2] LONG ch)\n\t"
		"jsr -312(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG UnGetC(BPTR fh, LONG character)
{
	// LVO: -318
	// fh [d1]
	// character [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register LONG reg_d2 __asm("d2") = character;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG UnGetC([d1] BPTR fh, [d2] LONG character)\n\t"
		"jsr -318(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG FRead(BPTR fh, APTR block, ULONG blocklen, ULONG number)
{
	// LVO: -324
	// fh [d1]
	// block [d2]
	// blocklen [d3]
	// number [d4]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register APTR reg_d2 __asm("d2") = block;
	register ULONG reg_d3 __asm("d3") = blocklen;
	register ULONG reg_d4 __asm("d4") = number;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG FRead([d1] BPTR fh, [d2] APTR block, [d3] ULONG blocklen, [d4] ULONG number)\n\t"
		"jsr -324(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4"
	);
	return retVal;
}

inline LONG FWrite(BPTR fh, CONST APTR block, ULONG blocklen, ULONG number)
{
	// LVO: -330
	// fh [d1]
	// block [d2]
	// blocklen [d3]
	// number [d4]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register CONST APTR reg_d2 __asm("d2") = block;
	register ULONG reg_d3 __asm("d3") = blocklen;
	register ULONG reg_d4 __asm("d4") = number;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG FWrite([d1] BPTR fh, [d2] CONST APTR block, [d3] ULONG blocklen, [d4] ULONG number)\n\t"
		"jsr -330(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4"
	);
	return retVal;
}

inline STRPTR FGets(BPTR fh, STRPTR buf, ULONG buflen)
{
	// LVO: -336
	// fh [d1]
	// buf [d2]
	// buflen [d3]
	// ret: STRPTR [d0]

	register STRPTR retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register STRPTR reg_d2 __asm("d2") = buf;
	register ULONG reg_d3 __asm("d3") = buflen;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# STRPTR FGets([d1] BPTR fh, [d2] STRPTR buf, [d3] ULONG buflen)\n\t"
		"jsr -336(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline LONG FPuts(BPTR fh, CONST_STRPTR str)
{
	// LVO: -342
	// fh [d1]
	// str [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register CONST_STRPTR reg_d2 __asm("d2") = str;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG FPuts([d1] BPTR fh, [d2] CONST_STRPTR str)\n\t"
		"jsr -342(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline VOID VFWritef(BPTR fh, CONST_STRPTR format, CONST LONG* argarray)
{
	// LVO: -348
	// fh [d1]
	// format [d2]
	// argarray [d3]

	register BPTR reg_d1 __asm("d1") = fh;
	register CONST_STRPTR reg_d2 __asm("d2") = format;
	register CONST LONG* reg_d3 __asm("d3") = argarray;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID VFWritef([d1] BPTR fh, [d2] CONST_STRPTR format, [d3] CONST LONG* argarray)\n\t"
		"jsr -348(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
}

inline LONG VFPrintf(BPTR fh, CONST_STRPTR format, CONST APTR argarray)
{
	// LVO: -354
	// fh [d1]
	// format [d2]
	// argarray [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register CONST_STRPTR reg_d2 __asm("d2") = format;
	register CONST APTR reg_d3 __asm("d3") = argarray;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG VFPrintf([d1] BPTR fh, [d2] CONST_STRPTR format, [d3] CONST APTR argarray)\n\t"
		"jsr -354(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline LONG Flush(BPTR fh)
{
	// LVO: -360
	// fh [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG Flush([d1] BPTR fh)\n\t"
		"jsr -360(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG SetVBuf(BPTR fh, STRPTR buff, LONG type, LONG size)
{
	// LVO: -366
	// fh [d1]
	// buff [d2]
	// type [d3]
	// size [d4]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register STRPTR reg_d2 __asm("d2") = buff;
	register LONG reg_d3 __asm("d3") = type;
	register LONG reg_d4 __asm("d4") = size;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG SetVBuf([d1] BPTR fh, [d2] STRPTR buff, [d3] LONG type, [d4] LONG size)\n\t"
		"jsr -366(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4"
	);
	return retVal;
}

inline BPTR DupLockFromFH(BPTR fh)
{
	// LVO: -372
	// fh [d1]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR DupLockFromFH([d1] BPTR fh)\n\t"
		"jsr -372(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BPTR OpenFromLock(BPTR lock)
{
	// LVO: -378
	// lock [d1]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = lock;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR OpenFromLock([d1] BPTR lock)\n\t"
		"jsr -378(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BPTR ParentOfFH(BPTR fh)
{
	// LVO: -384
	// fh [d1]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR ParentOfFH([d1] BPTR fh)\n\t"
		"jsr -384(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL ExamineFH(BPTR fh, struct FileInfoBlock* fib)
{
	// LVO: -390
	// fh [d1]
	// fib [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register struct FileInfoBlock* reg_d2 __asm("d2") = fib;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL ExamineFH([d1] BPTR fh, [d2] struct FileInfoBlock* fib)\n\t"
		"jsr -390(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG SetFileDate(CONST_STRPTR name, CONST struct DateStamp* date)
{
	// LVO: -396
	// name [d1]
	// date [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register CONST struct DateStamp* reg_d2 __asm("d2") = date;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG SetFileDate([d1] CONST_STRPTR name, [d2] CONST struct DateStamp* date)\n\t"
		"jsr -396(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG NameFromLock(BPTR lock, STRPTR buffer, LONG len)
{
	// LVO: -402
	// lock [d1]
	// buffer [d2]
	// len [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = lock;
	register STRPTR reg_d2 __asm("d2") = buffer;
	register LONG reg_d3 __asm("d3") = len;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG NameFromLock([d1] BPTR lock, [d2] STRPTR buffer, [d3] LONG len)\n\t"
		"jsr -402(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline LONG NameFromFH(BPTR fh, STRPTR buffer, LONG len)
{
	// LVO: -408
	// fh [d1]
	// buffer [d2]
	// len [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register STRPTR reg_d2 __asm("d2") = buffer;
	register LONG reg_d3 __asm("d3") = len;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG NameFromFH([d1] BPTR fh, [d2] STRPTR buffer, [d3] LONG len)\n\t"
		"jsr -408(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline WORD SplitName(CONST_STRPTR name, ULONG separator, STRPTR buf, LONG oldpos, LONG size)
{
	// LVO: -414
	// name [d1]
	// separator [d2]
	// buf [d3]
	// oldpos [d4]
	// size [d5]
	// ret: WORD [d0]

	register WORD retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register ULONG reg_d2 __asm("d2") = separator;
	register STRPTR reg_d3 __asm("d3") = buf;
	register LONG reg_d4 __asm("d4") = oldpos;
	register LONG reg_d5 __asm("d5") = size;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# WORD SplitName([d1] CONST_STRPTR name, [d2] ULONG separator, [d3] STRPTR buf, [d4] LONG oldpos, [d5] LONG size)\n\t"
		"jsr -414(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5"
	);
	return retVal;
}

inline LONG SameLock(BPTR lock1, BPTR lock2)
{
	// LVO: -420
	// lock1 [d1]
	// lock2 [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = lock1;
	register BPTR reg_d2 __asm("d2") = lock2;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG SameLock([d1] BPTR lock1, [d2] BPTR lock2)\n\t"
		"jsr -420(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG SetMode(BPTR fh, LONG mode)
{
	// LVO: -426
	// fh [d1]
	// mode [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register LONG reg_d2 __asm("d2") = mode;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG SetMode([d1] BPTR fh, [d2] LONG mode)\n\t"
		"jsr -426(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG ExAll(BPTR lock, struct ExAllData* buffer, LONG size, LONG data, struct ExAllControl* control)
{
	// LVO: -432
	// lock [d1]
	// buffer [d2]
	// size [d3]
	// data [d4]
	// control [d5]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = lock;
	register struct ExAllData* reg_d2 __asm("d2") = buffer;
	register LONG reg_d3 __asm("d3") = size;
	register LONG reg_d4 __asm("d4") = data;
	register struct ExAllControl* reg_d5 __asm("d5") = control;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG ExAll([d1] BPTR lock, [d2] struct ExAllData* buffer, [d3] LONG size, [d4] LONG data, [d5] struct ExAllControl* control)\n\t"
		"jsr -432(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5"
	);
	return retVal;
}

inline LONG ReadLink(struct MsgPort* port, BPTR lock, CONST_STRPTR path, STRPTR buffer, ULONG size)
{
	// LVO: -438
	// port [d1]
	// lock [d2]
	// path [d3]
	// buffer [d4]
	// size [d5]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct MsgPort* reg_d1 __asm("d1") = port;
	register BPTR reg_d2 __asm("d2") = lock;
	register CONST_STRPTR reg_d3 __asm("d3") = path;
	register STRPTR reg_d4 __asm("d4") = buffer;
	register ULONG reg_d5 __asm("d5") = size;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG ReadLink([d1] struct MsgPort* port, [d2] BPTR lock, [d3] CONST_STRPTR path, [d4] STRPTR buffer, [d5] ULONG size)\n\t"
		"jsr -438(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5"
	);
	return retVal;
}

inline LONG MakeLink(CONST_STRPTR name, LONG dest, LONG soft)
{
	// LVO: -444
	// name [d1]
	// dest [d2]
	// soft [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register LONG reg_d2 __asm("d2") = dest;
	register LONG reg_d3 __asm("d3") = soft;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG MakeLink([d1] CONST_STRPTR name, [d2] LONG dest, [d3] LONG soft)\n\t"
		"jsr -444(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline LONG ChangeMode(LONG type, BPTR fh, LONG newmode)
{
	// LVO: -450
	// type [d1]
	// fh [d2]
	// newmode [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register LONG reg_d1 __asm("d1") = type;
	register BPTR reg_d2 __asm("d2") = fh;
	register LONG reg_d3 __asm("d3") = newmode;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG ChangeMode([d1] LONG type, [d2] BPTR fh, [d3] LONG newmode)\n\t"
		"jsr -450(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline LONG SetFileSize(BPTR fh, LONG pos, LONG mode)
{
	// LVO: -456
	// fh [d1]
	// pos [d2]
	// mode [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = fh;
	register LONG reg_d2 __asm("d2") = pos;
	register LONG reg_d3 __asm("d3") = mode;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG SetFileSize([d1] BPTR fh, [d2] LONG pos, [d3] LONG mode)\n\t"
		"jsr -456(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline LONG SetIoErr(LONG result)
{
	// LVO: -462
	// result [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register LONG reg_d1 __asm("d1") = result;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG SetIoErr([d1] LONG result)\n\t"
		"jsr -462(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL Fault(LONG code, STRPTR header, STRPTR buffer, LONG len)
{
	// LVO: -468
	// code [d1]
	// header [d2]
	// buffer [d3]
	// len [d4]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register LONG reg_d1 __asm("d1") = code;
	register STRPTR reg_d2 __asm("d2") = header;
	register STRPTR reg_d3 __asm("d3") = buffer;
	register LONG reg_d4 __asm("d4") = len;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL Fault([d1] LONG code, [d2] STRPTR header, [d3] STRPTR buffer, [d4] LONG len)\n\t"
		"jsr -468(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4"
	);
	return retVal;
}

inline BOOL PrintFault(LONG code, CONST_STRPTR header)
{
	// LVO: -474
	// code [d1]
	// header [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register LONG reg_d1 __asm("d1") = code;
	register CONST_STRPTR reg_d2 __asm("d2") = header;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL PrintFault([d1] LONG code, [d2] CONST_STRPTR header)\n\t"
		"jsr -474(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG ErrorReport(LONG code, LONG type, ULONG arg1, struct MsgPort* device)
{
	// LVO: -480
	// code [d1]
	// type [d2]
	// arg1 [d3]
	// device [d4]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register LONG reg_d1 __asm("d1") = code;
	register LONG reg_d2 __asm("d2") = type;
	register ULONG reg_d3 __asm("d3") = arg1;
	register struct MsgPort* reg_d4 __asm("d4") = device;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG ErrorReport([d1] LONG code, [d2] LONG type, [d3] ULONG arg1, [d4] struct MsgPort* device)\n\t"
		"jsr -480(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4"
	);
	return retVal;
}

inline LONG RunCommand(BPTR seg, LONG stack, CONST_STRPTR paramptr, LONG paramlen)
{
	// LVO: -504
	// seg [d1]
	// stack [d2]
	// paramptr [d3]
	// paramlen [d4]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = seg;
	register LONG reg_d2 __asm("d2") = stack;
	register CONST_STRPTR reg_d3 __asm("d3") = paramptr;
	register LONG reg_d4 __asm("d4") = paramlen;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG RunCommand([d1] BPTR seg, [d2] LONG stack, [d3] CONST_STRPTR paramptr, [d4] LONG paramlen)\n\t"
		"jsr -504(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4"
	);
	return retVal;
}

inline STRPTR GetArgStr()
{
	// LVO: -534
	// ret: STRPTR [d0]

	register STRPTR retVal __asm("d0");

	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# STRPTR GetArgStr()\n\t"
		"jsr -534(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL SetArgStr(CONST_STRPTR string)
{
	// LVO: -540
	// string [d1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = string;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL SetArgStr([d1] CONST_STRPTR string)\n\t"
		"jsr -540(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG MaxCli()
{
	// LVO: -552
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# ULONG MaxCli()\n\t"
		"jsr -552(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL SetCurrentDirName(CONST_STRPTR name)
{
	// LVO: -558
	// name [d1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL SetCurrentDirName([d1] CONST_STRPTR name)\n\t"
		"jsr -558(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL GetCurrentDirName(STRPTR buf, LONG len)
{
	// LVO: -564
	// buf [d1]
	// len [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register STRPTR reg_d1 __asm("d1") = buf;
	register LONG reg_d2 __asm("d2") = len;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL GetCurrentDirName([d1] STRPTR buf, [d2] LONG len)\n\t"
		"jsr -564(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline BOOL SetProgramName(CONST_STRPTR name)
{
	// LVO: -570
	// name [d1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL SetProgramName([d1] CONST_STRPTR name)\n\t"
		"jsr -570(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL GetProgramName(STRPTR buf, LONG len)
{
	// LVO: -576
	// buf [d1]
	// len [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register STRPTR reg_d1 __asm("d1") = buf;
	register LONG reg_d2 __asm("d2") = len;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL GetProgramName([d1] STRPTR buf, [d2] LONG len)\n\t"
		"jsr -576(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline BOOL SetPrompt(CONST_STRPTR name)
{
	// LVO: -582
	// name [d1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL SetPrompt([d1] CONST_STRPTR name)\n\t"
		"jsr -582(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL GetPrompt(STRPTR buf, LONG len)
{
	// LVO: -588
	// buf [d1]
	// len [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register STRPTR reg_d1 __asm("d1") = buf;
	register LONG reg_d2 __asm("d2") = len;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL GetPrompt([d1] STRPTR buf, [d2] LONG len)\n\t"
		"jsr -588(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline BPTR SetProgramDir(BPTR lock)
{
	// LVO: -594
	// lock [d1]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = lock;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR SetProgramDir([d1] BPTR lock)\n\t"
		"jsr -594(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BPTR GetProgramDir()
{
	// LVO: -600
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR GetProgramDir()\n\t"
		"jsr -600(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG SystemTagList(CONST_STRPTR command, CONST struct TagItem* tags)
{
	// LVO: -606
	// command [d1]
	// tags [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = command;
	register CONST struct TagItem* reg_d2 __asm("d2") = tags;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG SystemTagList([d1] CONST_STRPTR command, [d2] CONST struct TagItem* tags)\n\t"
		"jsr -606(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG AssignLock(CONST_STRPTR name, BPTR lock)
{
	// LVO: -612
	// name [d1]
	// lock [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register BPTR reg_d2 __asm("d2") = lock;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG AssignLock([d1] CONST_STRPTR name, [d2] BPTR lock)\n\t"
		"jsr -612(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline BOOL AssignLate(CONST_STRPTR name, CONST_STRPTR path)
{
	// LVO: -618
	// name [d1]
	// path [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register CONST_STRPTR reg_d2 __asm("d2") = path;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL AssignLate([d1] CONST_STRPTR name, [d2] CONST_STRPTR path)\n\t"
		"jsr -618(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline BOOL AssignPath(CONST_STRPTR name, CONST_STRPTR path)
{
	// LVO: -624
	// name [d1]
	// path [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register CONST_STRPTR reg_d2 __asm("d2") = path;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL AssignPath([d1] CONST_STRPTR name, [d2] CONST_STRPTR path)\n\t"
		"jsr -624(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline BOOL AssignAdd(CONST_STRPTR name, BPTR lock)
{
	// LVO: -630
	// name [d1]
	// lock [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register BPTR reg_d2 __asm("d2") = lock;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL AssignAdd([d1] CONST_STRPTR name, [d2] BPTR lock)\n\t"
		"jsr -630(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG RemAssignList(CONST_STRPTR name, BPTR lock)
{
	// LVO: -636
	// name [d1]
	// lock [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register BPTR reg_d2 __asm("d2") = lock;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG RemAssignList([d1] CONST_STRPTR name, [d2] BPTR lock)\n\t"
		"jsr -636(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline VOID FreeDeviceProc(struct DevProc* dp)
{
	// LVO: -648
	// dp [d1]

	register struct DevProc* reg_d1 __asm("d1") = dp;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID FreeDeviceProc([d1] struct DevProc* dp)\n\t"
		"jsr -648(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID UnLockDosList(ULONG flags)
{
	// LVO: -660
	// flags [d1]

	register ULONG reg_d1 __asm("d1") = flags;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID UnLockDosList([d1] ULONG flags)\n\t"
		"jsr -660(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL RemDosEntry(struct DosList* dlist)
{
	// LVO: -672
	// dlist [d1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct DosList* reg_d1 __asm("d1") = dlist;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL RemDosEntry([d1] struct DosList* dlist)\n\t"
		"jsr -672(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG AddDosEntry(struct DosList* dlist)
{
	// LVO: -678
	// dlist [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct DosList* reg_d1 __asm("d1") = dlist;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG AddDosEntry([d1] struct DosList* dlist)\n\t"
		"jsr -678(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreeDosEntry(struct DosList* dlist)
{
	// LVO: -702
	// dlist [d1]

	register struct DosList* reg_d1 __asm("d1") = dlist;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID FreeDosEntry([d1] struct DosList* dlist)\n\t"
		"jsr -702(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL IsFileSystem(CONST_STRPTR name)
{
	// LVO: -708
	// name [d1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL IsFileSystem([d1] CONST_STRPTR name)\n\t"
		"jsr -708(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL Format(CONST_STRPTR filesystem, CONST_STRPTR volumename, ULONG dostype)
{
	// LVO: -714
	// filesystem [d1]
	// volumename [d2]
	// dostype [d3]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = filesystem;
	register CONST_STRPTR reg_d2 __asm("d2") = volumename;
	register ULONG reg_d3 __asm("d3") = dostype;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL Format([d1] CONST_STRPTR filesystem, [d2] CONST_STRPTR volumename, [d3] ULONG dostype)\n\t"
		"jsr -714(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline LONG Relabel(CONST_STRPTR drive, CONST_STRPTR newname)
{
	// LVO: -720
	// drive [d1]
	// newname [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = drive;
	register CONST_STRPTR reg_d2 __asm("d2") = newname;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG Relabel([d1] CONST_STRPTR drive, [d2] CONST_STRPTR newname)\n\t"
		"jsr -720(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG Inhibit(CONST_STRPTR name, LONG onoff)
{
	// LVO: -726
	// name [d1]
	// onoff [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register LONG reg_d2 __asm("d2") = onoff;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG Inhibit([d1] CONST_STRPTR name, [d2] LONG onoff)\n\t"
		"jsr -726(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG AddBuffers(CONST_STRPTR name, LONG number)
{
	// LVO: -732
	// name [d1]
	// number [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register LONG reg_d2 __asm("d2") = number;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG AddBuffers([d1] CONST_STRPTR name, [d2] LONG number)\n\t"
		"jsr -732(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG CompareDates(CONST struct DateStamp* date1, CONST struct DateStamp* date2)
{
	// LVO: -738
	// date1 [d1]
	// date2 [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST struct DateStamp* reg_d1 __asm("d1") = date1;
	register CONST struct DateStamp* reg_d2 __asm("d2") = date2;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG CompareDates([d1] CONST struct DateStamp* date1, [d2] CONST struct DateStamp* date2)\n\t"
		"jsr -738(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG DateToStr(struct DateTime* datetime)
{
	// LVO: -744
	// datetime [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct DateTime* reg_d1 __asm("d1") = datetime;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG DateToStr([d1] struct DateTime* datetime)\n\t"
		"jsr -744(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG StrToDate(struct DateTime* datetime)
{
	// LVO: -750
	// datetime [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct DateTime* reg_d1 __asm("d1") = datetime;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG StrToDate([d1] struct DateTime* datetime)\n\t"
		"jsr -750(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BPTR InternalLoadSeg(BPTR fh, BPTR table, CONST LONG* funcarray, LONG* stack)
{
	// LVO: -756
	// fh [d0]
	// table [a0]
	// funcarray [a1]
	// stack [a2]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register BPTR reg_d0 __asm("d0") = fh;
	register BPTR reg_a0 __asm("a0") = table;
	register CONST LONG* reg_a1 __asm("a1") = funcarray;
	register LONG* reg_a2 __asm("a2") = stack;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR InternalLoadSeg([d0] BPTR fh, [a0] BPTR table, [a1] CONST LONG* funcarray, [a2] LONG* stack)\n\t"
		"jsr -756(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
	return retVal;
}

inline BOOL InternalUnLoadSeg(BPTR seglist, VOID (*CONST freefunc)(VOID))
{
	// LVO: -762
	// seglist [d1]
	// freefunc [a1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = seglist;
	register void* reg_a1 __asm("a1") = freefunc;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL InternalUnLoadSeg([d1] BPTR seglist, [a1] VOID (*CONST freefunc)(VOID))\n\t"
		"jsr -762(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BPTR NewLoadSeg(CONST_STRPTR file, CONST struct TagItem* tags)
{
	// LVO: -768
	// file [d1]
	// tags [d2]
	// ret: BPTR [d0]

	register BPTR retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = file;
	register CONST struct TagItem* reg_d2 __asm("d2") = tags;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BPTR NewLoadSeg([d1] CONST_STRPTR file, [d2] CONST struct TagItem* tags)\n\t"
		"jsr -768(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG AddSegment(CONST_STRPTR name, BPTR seg, LONG system)
{
	// LVO: -774
	// name [d1]
	// seg [d2]
	// system [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register BPTR reg_d2 __asm("d2") = seg;
	register LONG reg_d3 __asm("d3") = system;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG AddSegment([d1] CONST_STRPTR name, [d2] BPTR seg, [d3] LONG system)\n\t"
		"jsr -774(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline LONG RemSegment(struct Segment* seg)
{
	// LVO: -786
	// seg [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct Segment* reg_d1 __asm("d1") = seg;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG RemSegment([d1] struct Segment* seg)\n\t"
		"jsr -786(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG CheckSignal(LONG mask)
{
	// LVO: -792
	// mask [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register LONG reg_d1 __asm("d1") = mask;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG CheckSignal([d1] LONG mask)\n\t"
		"jsr -792(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG FindArg(CONST_STRPTR keyword, CONST_STRPTR arg_template)
{
	// LVO: -804
	// keyword [d1]
	// arg_template [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = keyword;
	register CONST_STRPTR reg_d2 __asm("d2") = arg_template;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG FindArg([d1] CONST_STRPTR keyword, [d2] CONST_STRPTR arg_template)\n\t"
		"jsr -804(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG ReadItem(CONST_STRPTR name, LONG maxchars, struct CSource* cSource)
{
	// LVO: -810
	// name [d1]
	// maxchars [d2]
	// cSource [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register LONG reg_d2 __asm("d2") = maxchars;
	register struct CSource* reg_d3 __asm("d3") = cSource;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG ReadItem([d1] CONST_STRPTR name, [d2] LONG maxchars, [d3] struct CSource* cSource)\n\t"
		"jsr -810(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline LONG StrToLong(CONST_STRPTR string, LONG* value)
{
	// LVO: -816
	// string [d1]
	// value [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = string;
	register LONG* reg_d2 __asm("d2") = value;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG StrToLong([d1] CONST_STRPTR string, [d2] LONG* value)\n\t"
		"jsr -816(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG MatchFirst(CONST_STRPTR pat, struct AnchorPath* anchor)
{
	// LVO: -822
	// pat [d1]
	// anchor [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = pat;
	register struct AnchorPath* reg_d2 __asm("d2") = anchor;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG MatchFirst([d1] CONST_STRPTR pat, [d2] struct AnchorPath* anchor)\n\t"
		"jsr -822(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG MatchNext(struct AnchorPath* anchor)
{
	// LVO: -828
	// anchor [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct AnchorPath* reg_d1 __asm("d1") = anchor;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG MatchNext([d1] struct AnchorPath* anchor)\n\t"
		"jsr -828(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID MatchEnd(struct AnchorPath* anchor)
{
	// LVO: -834
	// anchor [d1]

	register struct AnchorPath* reg_d1 __asm("d1") = anchor;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID MatchEnd([d1] struct AnchorPath* anchor)\n\t"
		"jsr -834(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG ParsePattern(CONST_STRPTR pat, STRPTR buf, LONG buflen)
{
	// LVO: -840
	// pat [d1]
	// buf [d2]
	// buflen [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = pat;
	register STRPTR reg_d2 __asm("d2") = buf;
	register LONG reg_d3 __asm("d3") = buflen;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG ParsePattern([d1] CONST_STRPTR pat, [d2] STRPTR buf, [d3] LONG buflen)\n\t"
		"jsr -840(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline BOOL MatchPattern(CONST_STRPTR pat, STRPTR str)
{
	// LVO: -846
	// pat [d1]
	// str [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = pat;
	register STRPTR reg_d2 __asm("d2") = str;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL MatchPattern([d1] CONST_STRPTR pat, [d2] STRPTR str)\n\t"
		"jsr -846(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline VOID FreeArgs(struct RDArgs* args)
{
	// LVO: -858
	// args [d1]

	register struct RDArgs* reg_d1 __asm("d1") = args;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID FreeArgs([d1] struct RDArgs* args)\n\t"
		"jsr -858(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline STRPTR FilePart(CONST_STRPTR path)
{
	// LVO: -870
	// path [d1]
	// ret: STRPTR [d0]

	register STRPTR retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = path;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# STRPTR FilePart([d1] CONST_STRPTR path)\n\t"
		"jsr -870(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline STRPTR PathPart(CONST_STRPTR path)
{
	// LVO: -876
	// path [d1]
	// ret: STRPTR [d0]

	register STRPTR retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = path;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# STRPTR PathPart([d1] CONST_STRPTR path)\n\t"
		"jsr -876(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline BOOL AddPart(STRPTR dirname, CONST_STRPTR filename, ULONG size)
{
	// LVO: -882
	// dirname [d1]
	// filename [d2]
	// size [d3]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register STRPTR reg_d1 __asm("d1") = dirname;
	register CONST_STRPTR reg_d2 __asm("d2") = filename;
	register ULONG reg_d3 __asm("d3") = size;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL AddPart([d1] STRPTR dirname, [d2] CONST_STRPTR filename, [d3] ULONG size)\n\t"
		"jsr -882(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline BOOL StartNotify(struct NotifyRequest* notify)
{
	// LVO: -888
	// notify [d1]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register struct NotifyRequest* reg_d1 __asm("d1") = notify;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL StartNotify([d1] struct NotifyRequest* notify)\n\t"
		"jsr -888(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID EndNotify(struct NotifyRequest* notify)
{
	// LVO: -894
	// notify [d1]

	register struct NotifyRequest* reg_d1 __asm("d1") = notify;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID EndNotify([d1] struct NotifyRequest* notify)\n\t"
		"jsr -894(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BOOL SetVar(CONST_STRPTR name, CONST_STRPTR buffer, LONG size, LONG flags)
{
	// LVO: -900
	// name [d1]
	// buffer [d2]
	// size [d3]
	// flags [d4]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register CONST_STRPTR reg_d2 __asm("d2") = buffer;
	register LONG reg_d3 __asm("d3") = size;
	register LONG reg_d4 __asm("d4") = flags;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL SetVar([d1] CONST_STRPTR name, [d2] CONST_STRPTR buffer, [d3] LONG size, [d4] LONG flags)\n\t"
		"jsr -900(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4"
	);
	return retVal;
}

inline LONG GetVar(CONST_STRPTR name, STRPTR buffer, LONG size, LONG flags)
{
	// LVO: -906
	// name [d1]
	// buffer [d2]
	// size [d3]
	// flags [d4]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register STRPTR reg_d2 __asm("d2") = buffer;
	register LONG reg_d3 __asm("d3") = size;
	register LONG reg_d4 __asm("d4") = flags;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG GetVar([d1] CONST_STRPTR name, [d2] STRPTR buffer, [d3] LONG size, [d4] LONG flags)\n\t"
		"jsr -906(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4"
	);
	return retVal;
}

inline LONG DeleteVar(CONST_STRPTR name, ULONG flags)
{
	// LVO: -912
	// name [d1]
	// flags [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register ULONG reg_d2 __asm("d2") = flags;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG DeleteVar([d1] CONST_STRPTR name, [d2] ULONG flags)\n\t"
		"jsr -912(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG CliInitNewcli(struct DosPacket* dp)
{
	// LVO: -930
	// dp [a0]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct DosPacket* reg_a0 __asm("a0") = dp;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG CliInitNewcli([a0] struct DosPacket* dp)\n\t"
		"jsr -930(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG CliInitRun(struct DosPacket* dp)
{
	// LVO: -936
	// dp [a0]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register struct DosPacket* reg_a0 __asm("a0") = dp;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG CliInitRun([a0] struct DosPacket* dp)\n\t"
		"jsr -936(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG WriteChars(CONST_STRPTR buf, ULONG buflen)
{
	// LVO: -942
	// buf [d1]
	// buflen [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = buf;
	register ULONG reg_d2 __asm("d2") = buflen;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG WriteChars([d1] CONST_STRPTR buf, [d2] ULONG buflen)\n\t"
		"jsr -942(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG PutStr(CONST_STRPTR str)
{
	// LVO: -948
	// str [d1]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = str;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG PutStr([d1] CONST_STRPTR str)\n\t"
		"jsr -948(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline LONG VPrintf(CONST_STRPTR format, CONST APTR argarray)
{
	// LVO: -954
	// format [d1]
	// argarray [d2]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = format;
	register CONST APTR reg_d2 __asm("d2") = argarray;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG VPrintf([d1] CONST_STRPTR format, [d2] CONST APTR argarray)\n\t"
		"jsr -954(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline LONG ParsePatternNoCase(CONST_STRPTR pat, STRPTR buf, LONG buflen)
{
	// LVO: -966
	// pat [d1]
	// buf [d2]
	// buflen [d3]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = pat;
	register STRPTR reg_d2 __asm("d2") = buf;
	register LONG reg_d3 __asm("d3") = buflen;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# LONG ParsePatternNoCase([d1] CONST_STRPTR pat, [d2] STRPTR buf, [d3] LONG buflen)\n\t"
		"jsr -966(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3"
	);
	return retVal;
}

inline BOOL MatchPatternNoCase(CONST_STRPTR pat, STRPTR str)
{
	// LVO: -972
	// pat [d1]
	// str [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = pat;
	register STRPTR reg_d2 __asm("d2") = str;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL MatchPatternNoCase([d1] CONST_STRPTR pat, [d2] STRPTR str)\n\t"
		"jsr -972(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline BOOL SameDevice(BPTR lock1, BPTR lock2)
{
	// LVO: -984
	// lock1 [d1]
	// lock2 [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register BPTR reg_d1 __asm("d1") = lock1;
	register BPTR reg_d2 __asm("d2") = lock2;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL SameDevice([d1] BPTR lock1, [d2] BPTR lock2)\n\t"
		"jsr -984(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline VOID ExAllEnd(BPTR lock, struct ExAllData* buffer, LONG size, LONG data, struct ExAllControl* control)
{
	// LVO: -990
	// lock [d1]
	// buffer [d2]
	// size [d3]
	// data [d4]
	// control [d5]

	register BPTR reg_d1 __asm("d1") = lock;
	register struct ExAllData* reg_d2 __asm("d2") = buffer;
	register LONG reg_d3 __asm("d3") = size;
	register LONG reg_d4 __asm("d4") = data;
	register struct ExAllControl* reg_d5 __asm("d5") = control;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# VOID ExAllEnd([d1] BPTR lock, [d2] struct ExAllData* buffer, [d3] LONG size, [d4] LONG data, [d5] struct ExAllControl* control)\n\t"
		"jsr -990(a6)\n\t"
		: 
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_d3),"r"(reg_d4),"r"(reg_d5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2", "d3", "d4", "d5"
	);
}

inline BOOL SetOwner(CONST_STRPTR name, LONG owner_info)
{
	// LVO: -996
	// name [d1]
	// owner_info [d2]
	// ret: BOOL [d0]

	register BOOL retVal __asm("d0");

	register CONST_STRPTR reg_d1 __asm("d1") = name;
	register LONG reg_d2 __asm("d2") = owner_info;
	register void* reg_a6 __asm("a6") = DOSBase;
	__asm volatile (
		"# BOOL SetOwner([d1] CONST_STRPTR name, [d2] LONG owner_info)\n\t"
		"jsr -996(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

#endif
