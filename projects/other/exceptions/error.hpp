/*

  Evil low level -> high level exception test code

*/

#ifndef _ERROR_HPP_
# define _ERROR_HPP_
# include <exec/tasks.h>

struct RuntimeError {};
struct ZeroDivide         : public RuntimeError {};
struct SegmentationFault  : public RuntimeError {};
struct BadAlignment       : public RuntimeError {};
struct RangeError         : public RuntimeError {};

class Trap {
  private:
    Task* task;
    void* oldTrap;

  public:
    void  enable();
    void  disable();

    Trap();
    ~Trap();
};

#endif
