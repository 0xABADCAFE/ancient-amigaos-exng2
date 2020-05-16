#ifndef _INLINE_AMIGA_EXEC_HPP_
#define _INLINE_AMIGA_EXEC_HPP_
inline ULONG Supervisor(ULONG (*CONST userFunction)(VOID))
{
	// LVO: -30
	// userFunction [a5]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register void* reg_a5 __asm("a5") = userFunction;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG Supervisor([a5] ULONG (*CONST userFunction)(VOID))\n\t"
		"jsr -30(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a5),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a5"
	);
	return retVal;
}

inline VOID InitCode(ULONG startClass, ULONG version)
{
	// LVO: -72
	// startClass [d0]
	// version [d1]

	register ULONG reg_d0 __asm("d0") = startClass;
	register ULONG reg_d1 __asm("d1") = version;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID InitCode([d0] ULONG startClass, [d1] ULONG version)\n\t"
		"jsr -72(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID InitStruct(CONST APTR initTable, APTR memory, ULONG size)
{
	// LVO: -78
	// initTable [a1]
	// memory [a2]
	// size [d0]

	register CONST APTR reg_a1 __asm("a1") = initTable;
	register APTR reg_a2 __asm("a2") = memory;
	register ULONG reg_d0 __asm("d0") = size;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID InitStruct([a1] CONST APTR initTable, [a2] APTR memory, [d0] ULONG size)\n\t"
		"jsr -78(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a2),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline VOID MakeFunctions(APTR target, CONST APTR functionArray, ULONG funcDispBase)
{
	// LVO: -90
	// target [a0]
	// functionArray [a1]
	// funcDispBase [a2]

	register APTR reg_a0 __asm("a0") = target;
	register CONST APTR reg_a1 __asm("a1") = functionArray;
	register ULONG reg_a2 __asm("a2") = funcDispBase;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID MakeFunctions([a0] APTR target, [a1] CONST APTR functionArray, [a2] ULONG funcDispBase)\n\t"
		"jsr -90(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline APTR InitResident(CONST struct Resident* resident, ULONG segList)
{
	// LVO: -102
	// resident [a1]
	// segList [d1]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register CONST struct Resident* reg_a1 __asm("a1") = resident;
	register ULONG reg_d1 __asm("d1") = segList;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR InitResident([a1] CONST struct Resident* resident, [d1] ULONG segList)\n\t"
		"jsr -102(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID Alert(ULONG alertNum)
{
	// LVO: -108
	// alertNum [d7]

	register ULONG reg_d7 __asm("d7") = alertNum;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Alert([d7] ULONG alertNum)\n\t"
		"jsr -108(a6)\n\t"
		: 
		: "r"(reg_d7),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d7"
	);
}

inline VOID Debug(ULONG flags)
{
	// LVO: -114
	// flags [d0]

	register ULONG reg_d0 __asm("d0") = flags;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Debug([d0] ULONG flags)\n\t"
		"jsr -114(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID Disable()
{
	// LVO: -120

	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Disable()\n\t"
		"jsr -120(a6)\n\t"
		: 
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID Enable()
{
	// LVO: -126

	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Enable()\n\t"
		"jsr -126(a6)\n\t"
		: 
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID Forbid()
{
	// LVO: -132

	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Forbid()\n\t"
		"jsr -132(a6)\n\t"
		: 
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID Permit()
{
	// LVO: -138

	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Permit()\n\t"
		"jsr -138(a6)\n\t"
		: 
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG SetSR(ULONG newSR, ULONG mask)
{
	// LVO: -144
	// newSR [d0]
	// mask [d1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = newSR;
	register ULONG reg_d1 __asm("d1") = mask;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG SetSR([d0] ULONG newSR, [d1] ULONG mask)\n\t"
		"jsr -144(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline APTR SuperState()
{
	// LVO: -150
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR SuperState()\n\t"
		"jsr -150(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID UserState(APTR sysStack)
{
	// LVO: -156
	// sysStack [d0]

	register APTR reg_d0 __asm("d0") = sysStack;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID UserState([d0] APTR sysStack)\n\t"
		"jsr -156(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AddIntServer(LONG intNumber, struct Interrupt* interrupt)
{
	// LVO: -168
	// intNumber [d0]
	// interrupt [a1]

	register LONG reg_d0 __asm("d0") = intNumber;
	register struct Interrupt* reg_a1 __asm("a1") = interrupt;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID AddIntServer([d0] LONG intNumber, [a1] struct Interrupt* interrupt)\n\t"
		"jsr -168(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID RemIntServer(LONG intNumber, struct Interrupt* interrupt)
{
	// LVO: -174
	// intNumber [d0]
	// interrupt [a1]

	register LONG reg_d0 __asm("d0") = intNumber;
	register struct Interrupt* reg_a1 __asm("a1") = interrupt;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID RemIntServer([d0] LONG intNumber, [a1] struct Interrupt* interrupt)\n\t"
		"jsr -174(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID Cause(struct Interrupt* interrupt)
{
	// LVO: -180
	// interrupt [a1]

	register struct Interrupt* reg_a1 __asm("a1") = interrupt;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Cause([a1] struct Interrupt* interrupt)\n\t"
		"jsr -180(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline APTR Allocate(struct MemHeader* freeList, ULONG byteSize)
{
	// LVO: -186
	// freeList [a0]
	// byteSize [d0]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register struct MemHeader* reg_a0 __asm("a0") = freeList;
	register ULONG reg_d0 __asm("d0") = byteSize;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR Allocate([a0] struct MemHeader* freeList, [d0] ULONG byteSize)\n\t"
		"jsr -186(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID Deallocate(struct MemHeader* freeList, APTR memoryBlock, ULONG byteSize)
{
	// LVO: -192
	// freeList [a0]
	// memoryBlock [a1]
	// byteSize [d0]

	register struct MemHeader* reg_a0 __asm("a0") = freeList;
	register APTR reg_a1 __asm("a1") = memoryBlock;
	register ULONG reg_d0 __asm("d0") = byteSize;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Deallocate([a0] struct MemHeader* freeList, [a1] APTR memoryBlock, [d0] ULONG byteSize)\n\t"
		"jsr -192(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline APTR AllocMem(ULONG byteSize, ULONG requirements)
{
	// LVO: -198
	// byteSize [d0]
	// requirements [d1]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = byteSize;
	register ULONG reg_d1 __asm("d1") = requirements;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR AllocMem([d0] ULONG byteSize, [d1] ULONG requirements)\n\t"
		"jsr -198(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline APTR AllocAbs(ULONG byteSize, APTR location)
{
	// LVO: -204
	// byteSize [d0]
	// location [a1]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = byteSize;
	register APTR reg_a1 __asm("a1") = location;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR AllocAbs([d0] ULONG byteSize, [a1] APTR location)\n\t"
		"jsr -204(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreeMem(APTR memoryBlock, ULONG byteSize)
{
	// LVO: -210
	// memoryBlock [a1]
	// byteSize [d0]

	register APTR reg_a1 __asm("a1") = memoryBlock;
	register ULONG reg_d0 __asm("d0") = byteSize;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID FreeMem([a1] APTR memoryBlock, [d0] ULONG byteSize)\n\t"
		"jsr -210(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG AvailMem(ULONG requirements)
{
	// LVO: -216
	// requirements [d1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register ULONG reg_d1 __asm("d1") = requirements;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG AvailMem([d1] ULONG requirements)\n\t"
		"jsr -216(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreeEntry(struct MemList* entry)
{
	// LVO: -228
	// entry [a0]

	register struct MemList* reg_a0 __asm("a0") = entry;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID FreeEntry([a0] struct MemList* entry)\n\t"
		"jsr -228(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID Insert(struct List* list, struct Node* node, struct Node* pred)
{
	// LVO: -234
	// list [a0]
	// node [a1]
	// pred [a2]

	register struct List* reg_a0 __asm("a0") = list;
	register struct Node* reg_a1 __asm("a1") = node;
	register struct Node* reg_a2 __asm("a2") = pred;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Insert([a0] struct List* list, [a1] struct Node* node, [a2] struct Node* pred)\n\t"
		"jsr -234(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2"
	);
}

inline VOID AddHead(struct List* list, struct Node* node)
{
	// LVO: -240
	// list [a0]
	// node [a1]

	register struct List* reg_a0 __asm("a0") = list;
	register struct Node* reg_a1 __asm("a1") = node;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID AddHead([a0] struct List* list, [a1] struct Node* node)\n\t"
		"jsr -240(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AddTail(struct List* list, struct Node* node)
{
	// LVO: -246
	// list [a0]
	// node [a1]

	register struct List* reg_a0 __asm("a0") = list;
	register struct Node* reg_a1 __asm("a1") = node;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID AddTail([a0] struct List* list, [a1] struct Node* node)\n\t"
		"jsr -246(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID Remove(struct Node* node)
{
	// LVO: -252
	// node [a1]

	register struct Node* reg_a1 __asm("a1") = node;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Remove([a1] struct Node* node)\n\t"
		"jsr -252(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID Enqueue(struct List* list, struct Node* node)
{
	// LVO: -270
	// list [a0]
	// node [a1]

	register struct List* reg_a0 __asm("a0") = list;
	register struct Node* reg_a1 __asm("a1") = node;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Enqueue([a0] struct List* list, [a1] struct Node* node)\n\t"
		"jsr -270(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline APTR AddTask(struct Task* task, CONST APTR initPC, CONST APTR finalPC)
{
	// LVO: -282
	// task [a1]
	// initPC [a2]
	// finalPC [a3]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register struct Task* reg_a1 __asm("a1") = task;
	register CONST APTR reg_a2 __asm("a2") = initPC;
	register CONST APTR reg_a3 __asm("a3") = finalPC;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR AddTask([a1] struct Task* task, [a2] CONST APTR initPC, [a3] CONST APTR finalPC)\n\t"
		"jsr -282(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a2),"r"(reg_a3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "a3"
	);
	return retVal;
}

inline VOID RemTask(struct Task* task)
{
	// LVO: -288
	// task [a1]

	register struct Task* reg_a1 __asm("a1") = task;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID RemTask([a1] struct Task* task)\n\t"
		"jsr -288(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BYTE SetTaskPri(struct Task* task, LONG priority)
{
	// LVO: -300
	// task [a1]
	// priority [d0]
	// ret: BYTE [d0]

	register BYTE retVal __asm("d0");

	register struct Task* reg_a1 __asm("a1") = task;
	register LONG reg_d0 __asm("d0") = priority;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# BYTE SetTaskPri([a1] struct Task* task, [d0] LONG priority)\n\t"
		"jsr -300(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG SetSignal(ULONG newSignals, ULONG signalSet)
{
	// LVO: -306
	// newSignals [d0]
	// signalSet [d1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = newSignals;
	register ULONG reg_d1 __asm("d1") = signalSet;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG SetSignal([d0] ULONG newSignals, [d1] ULONG signalSet)\n\t"
		"jsr -306(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG SetExcept(ULONG newSignals, ULONG signalSet)
{
	// LVO: -312
	// newSignals [d0]
	// signalSet [d1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = newSignals;
	register ULONG reg_d1 __asm("d1") = signalSet;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG SetExcept([d0] ULONG newSignals, [d1] ULONG signalSet)\n\t"
		"jsr -312(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG Wait(ULONG signalSet)
{
	// LVO: -318
	// signalSet [d0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = signalSet;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG Wait([d0] ULONG signalSet)\n\t"
		"jsr -318(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID Signal(struct Task* task, ULONG signalSet)
{
	// LVO: -324
	// task [a1]
	// signalSet [d0]

	register struct Task* reg_a1 __asm("a1") = task;
	register ULONG reg_d0 __asm("d0") = signalSet;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Signal([a1] struct Task* task, [d0] ULONG signalSet)\n\t"
		"jsr -324(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BYTE AllocSignal(LONG signalNum)
{
	// LVO: -330
	// signalNum [d0]
	// ret: BYTE [d0]

	register BYTE retVal __asm("d0");

	register LONG reg_d0 __asm("d0") = signalNum;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# BYTE AllocSignal([d0] LONG signalNum)\n\t"
		"jsr -330(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreeSignal(LONG signalNum)
{
	// LVO: -336
	// signalNum [d0]

	register LONG reg_d0 __asm("d0") = signalNum;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID FreeSignal([d0] LONG signalNum)\n\t"
		"jsr -336(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline LONG AllocTrap(LONG trapNum)
{
	// LVO: -342
	// trapNum [d0]
	// ret: LONG [d0]

	register LONG retVal __asm("d0");

	register LONG reg_d0 __asm("d0") = trapNum;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# LONG AllocTrap([d0] LONG trapNum)\n\t"
		"jsr -342(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreeTrap(LONG trapNum)
{
	// LVO: -348
	// trapNum [d0]

	register LONG reg_d0 __asm("d0") = trapNum;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID FreeTrap([d0] LONG trapNum)\n\t"
		"jsr -348(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AddPort(struct MsgPort* port)
{
	// LVO: -354
	// port [a1]

	register struct MsgPort* reg_a1 __asm("a1") = port;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID AddPort([a1] struct MsgPort* port)\n\t"
		"jsr -354(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID RemPort(struct MsgPort* port)
{
	// LVO: -360
	// port [a1]

	register struct MsgPort* reg_a1 __asm("a1") = port;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID RemPort([a1] struct MsgPort* port)\n\t"
		"jsr -360(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID PutMsg(struct MsgPort* port, struct Message* message)
{
	// LVO: -366
	// port [a0]
	// message [a1]

	register struct MsgPort* reg_a0 __asm("a0") = port;
	register struct Message* reg_a1 __asm("a1") = message;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID PutMsg([a0] struct MsgPort* port, [a1] struct Message* message)\n\t"
		"jsr -366(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ReplyMsg(struct Message* message)
{
	// LVO: -378
	// message [a1]

	register struct Message* reg_a1 __asm("a1") = message;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID ReplyMsg([a1] struct Message* message)\n\t"
		"jsr -378(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AddLibrary(struct Library* library)
{
	// LVO: -396
	// library [a1]

	register struct Library* reg_a1 __asm("a1") = library;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID AddLibrary([a1] struct Library* library)\n\t"
		"jsr -396(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID RemLibrary(struct Library* library)
{
	// LVO: -402
	// library [a1]

	register struct Library* reg_a1 __asm("a1") = library;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID RemLibrary([a1] struct Library* library)\n\t"
		"jsr -402(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID CloseLibrary(struct Library* library)
{
	// LVO: -414
	// library [a1]

	register struct Library* reg_a1 __asm("a1") = library;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID CloseLibrary([a1] struct Library* library)\n\t"
		"jsr -414(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline APTR SetFunction(struct Library* library, LONG funcOffset, ULONG (*CONST newFunction)(VOID))
{
	// LVO: -420
	// library [a1]
	// funcOffset [a0]
	// newFunction [d0]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register struct Library* reg_a1 __asm("a1") = library;
	register LONG reg_a0 __asm("a0") = funcOffset;
	register void* reg_d0 __asm("d0") = newFunction;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR SetFunction([a1] struct Library* library, [a0] LONG funcOffset, [d0] ULONG (*CONST newFunction)(VOID))\n\t"
		"jsr -420(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID SumLibrary(struct Library* library)
{
	// LVO: -426
	// library [a1]

	register struct Library* reg_a1 __asm("a1") = library;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID SumLibrary([a1] struct Library* library)\n\t"
		"jsr -426(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AddDevice(struct Device* device)
{
	// LVO: -432
	// device [a1]

	register struct Device* reg_a1 __asm("a1") = device;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID AddDevice([a1] struct Device* device)\n\t"
		"jsr -432(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID RemDevice(struct Device* device)
{
	// LVO: -438
	// device [a1]

	register struct Device* reg_a1 __asm("a1") = device;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID RemDevice([a1] struct Device* device)\n\t"
		"jsr -438(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BYTE OpenDevice(CONST_STRPTR devName, ULONG unit, struct IORequest* ioRequest, ULONG flags)
{
	// LVO: -444
	// devName [a0]
	// unit [d0]
	// ioRequest [a1]
	// flags [d1]
	// ret: BYTE [d0]

	register BYTE retVal __asm("d0");

	register CONST_STRPTR reg_a0 __asm("a0") = devName;
	register ULONG reg_d0 __asm("d0") = unit;
	register struct IORequest* reg_a1 __asm("a1") = ioRequest;
	register ULONG reg_d1 __asm("d1") = flags;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# BYTE OpenDevice([a0] CONST_STRPTR devName, [d0] ULONG unit, [a1] struct IORequest* ioRequest, [d1] ULONG flags)\n\t"
		"jsr -444(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a1),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID CloseDevice(struct IORequest* ioRequest)
{
	// LVO: -450
	// ioRequest [a1]

	register struct IORequest* reg_a1 __asm("a1") = ioRequest;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID CloseDevice([a1] struct IORequest* ioRequest)\n\t"
		"jsr -450(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BYTE DoIO(struct IORequest* ioRequest)
{
	// LVO: -456
	// ioRequest [a1]
	// ret: BYTE [d0]

	register BYTE retVal __asm("d0");

	register struct IORequest* reg_a1 __asm("a1") = ioRequest;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# BYTE DoIO([a1] struct IORequest* ioRequest)\n\t"
		"jsr -456(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID SendIO(struct IORequest* ioRequest)
{
	// LVO: -462
	// ioRequest [a1]

	register struct IORequest* reg_a1 __asm("a1") = ioRequest;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID SendIO([a1] struct IORequest* ioRequest)\n\t"
		"jsr -462(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline BYTE WaitIO(struct IORequest* ioRequest)
{
	// LVO: -474
	// ioRequest [a1]
	// ret: BYTE [d0]

	register BYTE retVal __asm("d0");

	register struct IORequest* reg_a1 __asm("a1") = ioRequest;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# BYTE WaitIO([a1] struct IORequest* ioRequest)\n\t"
		"jsr -474(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID AbortIO(struct IORequest* ioRequest)
{
	// LVO: -480
	// ioRequest [a1]

	register struct IORequest* reg_a1 __asm("a1") = ioRequest;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID AbortIO([a1] struct IORequest* ioRequest)\n\t"
		"jsr -480(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AddResource(APTR resource)
{
	// LVO: -486
	// resource [a1]

	register APTR reg_a1 __asm("a1") = resource;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID AddResource([a1] APTR resource)\n\t"
		"jsr -486(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID RemResource(APTR resource)
{
	// LVO: -492
	// resource [a1]

	register APTR reg_a1 __asm("a1") = resource;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID RemResource([a1] APTR resource)\n\t"
		"jsr -492(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline APTR OpenResource(CONST_STRPTR resName)
{
	// LVO: -498
	// resName [a1]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register CONST_STRPTR reg_a1 __asm("a1") = resName;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR OpenResource([a1] CONST_STRPTR resName)\n\t"
		"jsr -498(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline APTR RawDoFmt(CONST_STRPTR formatString, CONST APTR dataStream, VOID (*CONST putChProc)(VOID), APTR putChData)
{
	// LVO: -522
	// formatString [a0]
	// dataStream [a1]
	// putChProc [a2]
	// putChData [a3]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register CONST_STRPTR reg_a0 __asm("a0") = formatString;
	register CONST APTR reg_a1 __asm("a1") = dataStream;
	register void* reg_a2 __asm("a2") = putChProc;
	register APTR reg_a3 __asm("a3") = putChData;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR RawDoFmt([a0] CONST_STRPTR formatString, [a1] CONST APTR dataStream, [a2] VOID (*CONST putChProc)(VOID), [a3] APTR putChData)\n\t"
		"jsr -522(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a2),"r"(reg_a3),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "a2", "a3"
	);
	return retVal;
}

inline ULONG GetCC()
{
	// LVO: -528
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG GetCC()\n\t"
		"jsr -528(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG TypeOfMem(CONST APTR address)
{
	// LVO: -534
	// address [a1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register CONST APTR reg_a1 __asm("a1") = address;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG TypeOfMem([a1] CONST APTR address)\n\t"
		"jsr -534(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline ULONG Procure(struct SignalSemaphore* sigSem, struct SemaphoreMessage* bidMsg)
{
	// LVO: -540
	// sigSem [a0]
	// bidMsg [a1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct SignalSemaphore* reg_a0 __asm("a0") = sigSem;
	register struct SemaphoreMessage* reg_a1 __asm("a1") = bidMsg;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG Procure([a0] struct SignalSemaphore* sigSem, [a1] struct SemaphoreMessage* bidMsg)\n\t"
		"jsr -540(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID Vacate(struct SignalSemaphore* sigSem, struct SemaphoreMessage* bidMsg)
{
	// LVO: -546
	// sigSem [a0]
	// bidMsg [a1]

	register struct SignalSemaphore* reg_a0 __asm("a0") = sigSem;
	register struct SemaphoreMessage* reg_a1 __asm("a1") = bidMsg;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID Vacate([a0] struct SignalSemaphore* sigSem, [a1] struct SemaphoreMessage* bidMsg)\n\t"
		"jsr -546(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID InitSemaphore(struct SignalSemaphore* sigSem)
{
	// LVO: -558
	// sigSem [a0]

	register struct SignalSemaphore* reg_a0 __asm("a0") = sigSem;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID InitSemaphore([a0] struct SignalSemaphore* sigSem)\n\t"
		"jsr -558(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ObtainSemaphore(struct SignalSemaphore* sigSem)
{
	// LVO: -564
	// sigSem [a0]

	register struct SignalSemaphore* reg_a0 __asm("a0") = sigSem;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID ObtainSemaphore([a0] struct SignalSemaphore* sigSem)\n\t"
		"jsr -564(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ReleaseSemaphore(struct SignalSemaphore* sigSem)
{
	// LVO: -570
	// sigSem [a0]

	register struct SignalSemaphore* reg_a0 __asm("a0") = sigSem;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID ReleaseSemaphore([a0] struct SignalSemaphore* sigSem)\n\t"
		"jsr -570(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG AttemptSemaphore(struct SignalSemaphore* sigSem)
{
	// LVO: -576
	// sigSem [a0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct SignalSemaphore* reg_a0 __asm("a0") = sigSem;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG AttemptSemaphore([a0] struct SignalSemaphore* sigSem)\n\t"
		"jsr -576(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ObtainSemaphoreList(struct List* sigSem)
{
	// LVO: -582
	// sigSem [a0]

	register struct List* reg_a0 __asm("a0") = sigSem;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID ObtainSemaphoreList([a0] struct List* sigSem)\n\t"
		"jsr -582(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ReleaseSemaphoreList(struct List* sigSem)
{
	// LVO: -588
	// sigSem [a0]

	register struct List* reg_a0 __asm("a0") = sigSem;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID ReleaseSemaphoreList([a0] struct List* sigSem)\n\t"
		"jsr -588(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AddSemaphore(struct SignalSemaphore* sigSem)
{
	// LVO: -600
	// sigSem [a1]

	register struct SignalSemaphore* reg_a1 __asm("a1") = sigSem;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID AddSemaphore([a1] struct SignalSemaphore* sigSem)\n\t"
		"jsr -600(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID RemSemaphore(struct SignalSemaphore* sigSem)
{
	// LVO: -606
	// sigSem [a1]

	register struct SignalSemaphore* reg_a1 __asm("a1") = sigSem;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID RemSemaphore([a1] struct SignalSemaphore* sigSem)\n\t"
		"jsr -606(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG SumKickData()
{
	// LVO: -612
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG SumKickData()\n\t"
		"jsr -612(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID AddMemList(ULONG size, ULONG attributes, LONG pri, APTR base, CONST_STRPTR name)
{
	// LVO: -618
	// size [d0]
	// attributes [d1]
	// pri [d2]
	// base [a0]
	// name [a1]

	register ULONG reg_d0 __asm("d0") = size;
	register ULONG reg_d1 __asm("d1") = attributes;
	register LONG reg_d2 __asm("d2") = pri;
	register APTR reg_a0 __asm("a0") = base;
	register CONST_STRPTR reg_a1 __asm("a1") = name;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID AddMemList([d0] ULONG size, [d1] ULONG attributes, [d2] LONG pri, [a0] APTR base, [a1] CONST_STRPTR name)\n\t"
		"jsr -618(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a0),"r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
}

inline VOID CopyMem(CONST APTR source, APTR dest, ULONG size)
{
	// LVO: -624
	// source [a0]
	// dest [a1]
	// size [d0]

	register CONST APTR reg_a0 __asm("a0") = source;
	register APTR reg_a1 __asm("a1") = dest;
	register ULONG reg_d0 __asm("d0") = size;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID CopyMem([a0] CONST APTR source, [a1] APTR dest, [d0] ULONG size)\n\t"
		"jsr -624(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID CopyMemQuick(CONST APTR source, APTR dest, ULONG size)
{
	// LVO: -630
	// source [a0]
	// dest [a1]
	// size [d0]

	register CONST APTR reg_a0 __asm("a0") = source;
	register APTR reg_a1 __asm("a1") = dest;
	register ULONG reg_d0 __asm("d0") = size;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID CopyMemQuick([a0] CONST APTR source, [a1] APTR dest, [d0] ULONG size)\n\t"
		"jsr -630(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID CacheClearU()
{
	// LVO: -636

	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID CacheClearU()\n\t"
		"jsr -636(a6)\n\t"
		: 
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID CacheClearE(APTR address, ULONG length, ULONG caches)
{
	// LVO: -642
	// address [a0]
	// length [d0]
	// caches [d1]

	register APTR reg_a0 __asm("a0") = address;
	register ULONG reg_d0 __asm("d0") = length;
	register ULONG reg_d1 __asm("d1") = caches;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID CacheClearE([a0] APTR address, [d0] ULONG length, [d1] ULONG caches)\n\t"
		"jsr -642(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG CacheControl(ULONG cacheBits, ULONG cacheMask)
{
	// LVO: -648
	// cacheBits [d0]
	// cacheMask [d1]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = cacheBits;
	register ULONG reg_d1 __asm("d1") = cacheMask;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG CacheControl([d0] ULONG cacheBits, [d1] ULONG cacheMask)\n\t"
		"jsr -648(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline APTR CreateIORequest(CONST struct MsgPort* port, ULONG size)
{
	// LVO: -654
	// port [a0]
	// size [d0]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register CONST struct MsgPort* reg_a0 __asm("a0") = port;
	register ULONG reg_d0 __asm("d0") = size;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR CreateIORequest([a0] CONST struct MsgPort* port, [d0] ULONG size)\n\t"
		"jsr -654(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID DeleteIORequest(APTR iorequest)
{
	// LVO: -660
	// iorequest [a0]

	register APTR reg_a0 __asm("a0") = iorequest;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID DeleteIORequest([a0] APTR iorequest)\n\t"
		"jsr -660(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID DeleteMsgPort(struct MsgPort* port)
{
	// LVO: -672
	// port [a0]

	register struct MsgPort* reg_a0 __asm("a0") = port;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID DeleteMsgPort([a0] struct MsgPort* port)\n\t"
		"jsr -672(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ObtainSemaphoreShared(struct SignalSemaphore* sigSem)
{
	// LVO: -678
	// sigSem [a0]

	register struct SignalSemaphore* reg_a0 __asm("a0") = sigSem;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID ObtainSemaphoreShared([a0] struct SignalSemaphore* sigSem)\n\t"
		"jsr -678(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline APTR AllocVec(ULONG byteSize, ULONG requirements)
{
	// LVO: -684
	// byteSize [d0]
	// requirements [d1]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = byteSize;
	register ULONG reg_d1 __asm("d1") = requirements;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR AllocVec([d0] ULONG byteSize, [d1] ULONG requirements)\n\t"
		"jsr -684(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreeVec(APTR memoryBlock)
{
	// LVO: -690
	// memoryBlock [a1]

	register APTR reg_a1 __asm("a1") = memoryBlock;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID FreeVec([a1] APTR memoryBlock)\n\t"
		"jsr -690(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline APTR CreatePool(ULONG requirements, ULONG puddleSize, ULONG threshSize)
{
	// LVO: -696
	// requirements [d0]
	// puddleSize [d1]
	// threshSize [d2]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register ULONG reg_d0 __asm("d0") = requirements;
	register ULONG reg_d1 __asm("d1") = puddleSize;
	register ULONG reg_d2 __asm("d2") = threshSize;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR CreatePool([d0] ULONG requirements, [d1] ULONG puddleSize, [d2] ULONG threshSize)\n\t"
		"jsr -696(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_d0),"r"(reg_d1),"r"(reg_d2),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc", "d2"
	);
	return retVal;
}

inline VOID DeletePool(APTR poolHeader)
{
	// LVO: -702
	// poolHeader [a0]

	register APTR reg_a0 __asm("a0") = poolHeader;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID DeletePool([a0] APTR poolHeader)\n\t"
		"jsr -702(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline APTR AllocPooled(APTR poolHeader, ULONG memSize)
{
	// LVO: -708
	// poolHeader [a0]
	// memSize [d0]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register APTR reg_a0 __asm("a0") = poolHeader;
	register ULONG reg_d0 __asm("d0") = memSize;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR AllocPooled([a0] APTR poolHeader, [d0] ULONG memSize)\n\t"
		"jsr -708(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID FreePooled(APTR poolHeader, APTR memory, ULONG memSize)
{
	// LVO: -714
	// poolHeader [a0]
	// memory [a1]
	// memSize [d0]

	register APTR reg_a0 __asm("a0") = poolHeader;
	register APTR reg_a1 __asm("a1") = memory;
	register ULONG reg_d0 __asm("d0") = memSize;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID FreePooled([a0] APTR poolHeader, [a1] APTR memory, [d0] ULONG memSize)\n\t"
		"jsr -714(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG AttemptSemaphoreShared(struct SignalSemaphore* sigSem)
{
	// LVO: -720
	// sigSem [a0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register struct SignalSemaphore* reg_a0 __asm("a0") = sigSem;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG AttemptSemaphoreShared([a0] struct SignalSemaphore* sigSem)\n\t"
		"jsr -720(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID ColdReboot()
{
	// LVO: -726

	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID ColdReboot()\n\t"
		"jsr -726(a6)\n\t"
		: 
		: "r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID StackSwap(struct StackSwapStruct* newStack)
{
	// LVO: -732
	// newStack [a0]

	register struct StackSwapStruct* reg_a0 __asm("a0") = newStack;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID StackSwap([a0] struct StackSwapStruct* newStack)\n\t"
		"jsr -732(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ChildFree(APTR tid)
{
	// LVO: -738
	// tid [d0]

	register APTR reg_d0 __asm("d0") = tid;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID ChildFree([d0] APTR tid)\n\t"
		"jsr -738(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ChildOrphan(APTR tid)
{
	// LVO: -744
	// tid [d0]

	register APTR reg_d0 __asm("d0") = tid;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID ChildOrphan([d0] APTR tid)\n\t"
		"jsr -744(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ChildStatus(APTR tid)
{
	// LVO: -750
	// tid [d0]

	register APTR reg_d0 __asm("d0") = tid;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID ChildStatus([d0] APTR tid)\n\t"
		"jsr -750(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID ChildWait(APTR tid)
{
	// LVO: -756
	// tid [d0]

	register APTR reg_d0 __asm("d0") = tid;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID ChildWait([d0] APTR tid)\n\t"
		"jsr -756(a6)\n\t"
		: 
		: "r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline APTR CachePreDMA(CONST APTR address, ULONG* length, ULONG flags)
{
	// LVO: -762
	// address [a0]
	// length [a1]
	// flags [d0]
	// ret: APTR [d0]

	register APTR retVal __asm("d0");

	register CONST APTR reg_a0 __asm("a0") = address;
	register ULONG* reg_a1 __asm("a1") = length;
	register ULONG reg_d0 __asm("d0") = flags;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# APTR CachePreDMA([a0] CONST APTR address, [a1] ULONG* length, [d0] ULONG flags)\n\t"
		"jsr -762(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

inline VOID CachePostDMA(CONST APTR address, ULONG* length, ULONG flags)
{
	// LVO: -768
	// address [a0]
	// length [a1]
	// flags [d0]

	register CONST APTR reg_a0 __asm("a0") = address;
	register ULONG* reg_a1 __asm("a1") = length;
	register ULONG reg_d0 __asm("d0") = flags;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID CachePostDMA([a0] CONST APTR address, [a1] ULONG* length, [d0] ULONG flags)\n\t"
		"jsr -768(a6)\n\t"
		: 
		: "r"(reg_a0),"r"(reg_a1),"r"(reg_d0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID AddMemHandler(struct Interrupt* memhand)
{
	// LVO: -774
	// memhand [a1]

	register struct Interrupt* reg_a1 __asm("a1") = memhand;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID AddMemHandler([a1] struct Interrupt* memhand)\n\t"
		"jsr -774(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline VOID RemMemHandler(struct Interrupt* memhand)
{
	// LVO: -780
	// memhand [a1]

	register struct Interrupt* reg_a1 __asm("a1") = memhand;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# VOID RemMemHandler([a1] struct Interrupt* memhand)\n\t"
		"jsr -780(a6)\n\t"
		: 
		: "r"(reg_a1),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
}

inline ULONG ObtainQuickVector(APTR interruptCode)
{
	// LVO: -786
	// interruptCode [a0]
	// ret: ULONG [d0]

	register ULONG retVal __asm("d0");

	register APTR reg_a0 __asm("a0") = interruptCode;
	register void* reg_a6 __asm("a6") = SysBase;
	__asm volatile (
		"# ULONG ObtainQuickVector([a0] APTR interruptCode)\n\t"
		"jsr -786(a6)\n\t"
		: "=r"(retVal)
		: "r"(reg_a0),"r"(reg_a6)
		: "a0", "a1", "d0", "d1", "a6", "cc"
	);
	return retVal;
}

#endif
