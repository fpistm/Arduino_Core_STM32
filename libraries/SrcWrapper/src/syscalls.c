/**
  * \file syscalls_stm32.c
  *
  * Implementation of newlib syscall.
  *
  */

#include "stm32_def.h"
#if defined (  __GNUC__  ) /* GCC CS3 */
  #include <sys/stat.h>
#endif
#include <errno.h>
#undef errno
extern int errno;

__attribute__((weak))
caddr_t _sbrk(int incr)
{
  extern char _estack; /* Defined in the linker script */
  extern char _Min_Stack_Size; /* Defined in the linker script */
  extern char _end; /* Defined by the linker */
  static char *heap_end = &_end ;
  char *prev_heap_end = heap_end;

  if (heap_end + incr > (char *)__get_MSP()) {
    /* Heap and stack collision */
    errno = ENOMEM;
    return (caddr_t) -1;
  }
  /* Ensure to keep minimum stack size defined in the linker script */
  if (heap_end + incr >= (char *)(&_estack - &_Min_Stack_Size)) {
    errno = ENOMEM;
    return (caddr_t) -1;
  }

  heap_end += incr ;
  return (caddr_t) prev_heap_end ;
}

__attribute__((weak))
int _close(int file)
{
  (void)file;
  return -1;
}

__attribute__((weak))
int _fstat(int file, struct stat *st)
{
  (void)file;
  st->st_mode = S_IFCHR ;
  return 0;
}

__attribute__((weak))
int _isatty(int file)
{
  (void)file;
  return 1;
}

__attribute__((weak))
int _lseek(int file, int ptr, int dir)
{
  (void)file;
  (void)ptr;
  (void)dir;
  return 0;
}

__attribute__((weak))
int _read(int file, char *ptr, int len)
{
  (void)file;
  (void)ptr;
  (void)len;
  return 0;
}

/* Moved to Print.cpp to support Print::printf()
__attribute__((weak))
int _write(int file, char *ptr, int len)
{
  (void)file;
  (void)ptr;
  (void)len;
  return 0;
}
*/

__attribute__((weak))
void _exit(int status)
{
  (void)status;
  for (; ;) ;
}

__attribute__((weak))
int _kill(int pid, int sig)
{
  (void)pid;
  (void)sig;
  errno = EINVAL;
  return -1;
}

__attribute__((weak))
int _getpid(void)
{
  return 1;
}
