#include<iostream>
#include<typeinfo>

using namespace std;

class Base
{
	public:
		virtual void foo() = 0;
		virtual void bar() = 0;
};

class Der1 : public virtual Base
{
	public:
		virtual void foo();
};

void Der1::foo()
{
	cout<<"Type of object:"<<typeid(*this).name()<<endl;
	bar();
}

class Der2 : virtual public Base
{
        public:
                virtual void bar();
};

void Der2::bar()
{
	cout<<"Bar method defined...\n";
}

class Join : public Der1, public Der2
{
	public:
		//...
};

int main()
{
	Join* p1 = new Join();
	Der1* p2 = p1;
	Der2* p3 = p1;

	p1->foo();
	p2->foo();
	p3->foo();
}
