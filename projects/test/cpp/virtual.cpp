#include <cstdio>
#include <typeinfo.h>

class ClassA {
  public:
    virtual void log() const;
    virtual const char* getName() const;
    virtual ~ClassA() {}
};


class ClassB : public ClassA {
  public:
    void log() const;
};


class ClassC : public ClassB {
  public:
    void log() const;
};

class ClassD : public ClassB { };

class ClassE : public ClassC { };

class ClassF : public ClassD { };


const char* ClassA::getName() const
{
  return typeid(*this).name();
}

void ClassA::log() const
{
  std::printf("Using ClassA::log() for %s\n", getName());
}

void ClassB::log() const
{
  std::printf("Using ClassB::log() for %s\n", getName());
}

void ClassC::log() const
{
  std::printf("Using ClassC::log() for %s\n", getName());
}


void testBehaviour(ClassA& instance)
{
  instance.log();
}

int main(int argN, char** argV)
{
  ClassA typeA;
  ClassB typeB;
  ClassC typeC;
  ClassD typeD;
  ClassE typeE;
  ClassF typeF;


  testBehaviour(typeA);
  testBehaviour(typeB);
  testBehaviour(typeC);
  testBehaviour(typeD);
  testBehaviour(typeE);
  testBehaviour(typeF);


  return 0;
}
