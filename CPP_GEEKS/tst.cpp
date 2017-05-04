#include<iostream>

using namespace std;

/*int myfunc()
{
	int x= 2;
	cout<<"\nAddress of x:"<<&x;
	return(x);
}
*/
/*
void func(int x)
{
	cout<<"int called";
	cout<<endl<<x<<endl;
}

void func(char x)
{
	cout<<"char called";
	cout<<endl<<x<<endl;
}
*/
/*class Pet {
	public:
		virtual string getDescription() const {
			return "This is pet class";
		}
};

class Dog : public Pet {
	public:
		virtual string getDescription() const {
			return "This is dog";
		}
};

void describe(const Pet &p)
{
	cout<<p.getDescription()<<endl;
}*/

/*class Test {
	public:
		static void fun(int i);
		void fun(int i);
		int gun(int *ptr);
		int gun(int ptr[]);
		int f(int x);
		int f(const int& x);
};
*/
/*
class Base {
	public:
		int f(int i)
		{
			cout<<"f(int)";
			return (i+3);
		}
};

class Derived : public Base
{
	public:
		double f(double d)
		{
			cout<<"f(double)";
			return (d+3.3);
		}
};
*/
/*
class Test {
	public:
		static void fun()const
		{
			//return this;
		}
};
*/
class A {
	public:
		A() { cout<<"A ctr"<<endl;}
		A& func() { return *this;}
};
class B {
	public:
		B() { cout<<"B ctr called"<<endl;}
		static A a;
		static A getA() {return a;}
};
A B::a;

int main()
{
	/*int p = myfunc();
	cout<<"\nAddress of p:"<<&p;
	cout<<endl<<p<<endl;
	*/

//	func('V');
//	Dog *d = new Dog();
//	p = &d;
//	Pet p;
//	Dog d;
//	describe(d);
//	describe(p);
//	Test t;
//	int i = 10;
//	t.fun(i);
//	Derived *d = new Derived();
//	cout<<"\n"<<d->f(3);
//	cout<<"\n"<<d->f(3.3)<<endl;
//	delete d;
//	Test::fun();
	B b;
//	A a = B::getA();
	A a = b.getA();
	return 0;
}
