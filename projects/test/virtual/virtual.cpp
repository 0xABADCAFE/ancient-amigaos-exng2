#include <cstdio>

class Virtual {
	protected:
		virtual void v() = 0;
	public:
		virtual ~Virtual() { }
};

class ConcreteBase : public Virtual {
	protected:
		void v();
	public:
		void test();
		~ConcreteBase() {}
};

class ConcreteDerived : public ConcreteBase {
	protected:
		void v();
	public:
		void test2();
		~ConcreteDerived() {}
};

int main()
{
	ConcreteBase*			p1 = new ConcreteBase();
	ConcreteDerived*	p2 = new ConcreteDerived();
	ConcreteBase*			p3 = p2;

	p1->test();
	p2->test();
	p2->test2();
	p3->test();

	delete p2;
	delete p1;
	return 0;
}

void ConcreteBase::v()
{
	std::puts(" -> void ConcreteBass::v()\n");
}

void ConcreteDerived::v()
{
	std::puts(" -> void ConcreteDerived::v()\n");
}

void ConcreteBase::test()
{
	std::printf("void ConcreteBass::test()");
	v();
}

void ConcreteDerived::test2()
{
	std::printf("void ConcreteDerived::test2()");
	v();
}
