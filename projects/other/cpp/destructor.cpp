#include <cstdio>

class Base {
  public:
   virtual void test1();
  public:
    virtual ~Base();
};

Base::~Base()
{
  std::puts("~Base()");
}

void Base::test1()
{
  std::puts("Nonstatic Base::test1()");
}

class Derived1 : public Base {
  public:
    static void test1();
  public:
    ~Derived1();
};

Derived1::~Derived1()
{
  std::puts("~Derived1()");
}

void Derived1::test1()
{
  std::puts("Static Derived1::test1()");
}

int main (int argN, char** argV)
{
  Base* obj1 = new Base();
  Base* obj2 = new Derived1();

  obj1->test1();
  obj2->test1();
  Derived1::test1();
  delete obj2;
  delete obj1;
}
