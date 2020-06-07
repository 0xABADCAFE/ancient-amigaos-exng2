#ifndef _INLINE_TIMER_H
#define _INLINE_TIMER_H

#ifndef TIMER_BASE_NAME
#define TIMER_BASE_NAME TimerBase
#endif

static __inline VOID AddTime(struct timeval * dest, CONST struct timeval * src)
{
  ((VOID (*)(struct timeval * __asm("a0"), CONST struct timeval * __asm("a1"), struct Device * __asm("a6")))
  (((char *) TIMER_BASE_NAME) - 42))(dest, src, TIMER_BASE_NAME);
}

static __inline VOID SubTime(struct timeval * dest, CONST struct timeval * src)
{
  ((VOID (*)(struct timeval * __asm("a0"), CONST struct timeval * __asm("a1"), struct Device * __asm("a6")))
  (((char *) TIMER_BASE_NAME) - 48))(dest, src, TIMER_BASE_NAME);
}

static __inline LONG CmpTime(CONST struct timeval * dest, CONST struct timeval * src)
{
  return ((LONG (*)(CONST struct timeval * __asm("a0"), CONST struct timeval * __asm("a1"), struct Device * __asm("a6")))
  (((char *) TIMER_BASE_NAME) - 54))(dest, src, TIMER_BASE_NAME);
}

static __inline ULONG ReadEClock(struct EClockVal * dest)
{
  return ((ULONG (*)(struct EClockVal * __asm("a0"), struct Device * __asm("a6")))
  (((char *) TIMER_BASE_NAME) - 60))(dest, TIMER_BASE_NAME);
}

static __inline VOID GetSysTime(struct timeval * dest)
{
  ((VOID (*)(struct timeval * __asm("a0"), struct Device * __asm("a6")))
  (((char *) TIMER_BASE_NAME) - 66))(dest, TIMER_BASE_NAME);
}

#endif /*  _INLINE_TIMER_H  */
