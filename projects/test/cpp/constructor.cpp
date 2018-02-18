#include <cstdio>


class Foo {
	private:
		int a;
		int b;
		int inst;

		static int instCnt;

	public:
		void print();

		Foo();												// default constructor

		Foo(int iA, int iB);					// main constructor
		Foo(const Foo&);							// copy constructor
		Foo& operator=(const Foo&);		// assignment operator


		Foo(int iA);									// implicit conversion constructor (from int)

		~Foo();
};


int main(int argN, char** argV)
{
	std::puts("\nFoo foo0");
	Foo foo0;
	foo0.print();

	std::puts("\nFoo foo1 = Foo(0,1)");
	Foo foo1 = Foo(0,1);
	foo1.print();

	std::puts("\nFoo foo2(2,3)");
	Foo foo2(2,3);
	foo2.print();

	std::puts("\nFoo foo3 = foo1");
	Foo foo3 = foo1;
	foo3.print();

	std::puts("\nfoo2 = foo3");
	foo2 = foo3;
	foo2.print();

	std::puts("\nfoo1 = foo1");
	foo1 = foo1;
	foo1.print();

	std::puts("\nFoo foo4 = 10");
	Foo foo4 = 10;
	foo4.print();

	std::puts("\nfoo3 = 5");
	foo3 = 5;
	foo3.print();

	std::puts("\n-------------\n");

	return 0;
}


int Foo::instCnt = 0;


void Foo::print()
{
	std::printf("Foo instance %d={%d,%d}\n", inst, a, b);
}

Foo::Foo() : a(0), b(0)
{
	inst = instCnt++;
	std::printf("*** constructed Foo instance %d via Foo()\n", inst);
}

Foo::Foo(int iA, int iB) : a(iA), b(iB)
{
	inst = instCnt++;
	std::printf("*** constructed Foo instance %d via Foo(int, int)\n", inst);
}

Foo::Foo(const Foo& f) : a(f.a), b(f.b)
{
	inst = instCnt++;
	std::printf("*** constructed Foo instance %d via copy construction of Foo instance %d\n", inst, f.inst);
}

Foo::Foo(int iA): a(iA), b(0)
{
	inst = instCnt++;
	std::printf("*** construced Foo instance %d via Foo(int)\n", inst);
}

Foo& Foo::operator=(const Foo& f)
{
	if (this != &f) {
		a = f.a;
		b = f.b;
		std::printf("*** Foo::operator=(), copied Foo instance %d data to Foo instance %d\n", f.inst, inst);
	} else {
		std::printf("*** Foo::operator=() - skipped copy due to self-assignment of Foo instance %d\n", inst);
	}
	return *this;
}

Foo::~Foo()
{
	std::printf("*** destroyed Foo instance %d\n", inst);
}

