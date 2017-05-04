#include<iostream>
using namespace std;
 
/*class Test
{
private:
  int x;
public:
  Test(int x = 0) { this->x = x; }
  void change(Test *t) { this->x = t->x; }
  void print() { cout << "x = " << x << endl; }
};
 
int main()
{
  Test obj(5);
  Test *ptr = new Test (10);
  obj.change(ptr);
  obj.print();
  return 0;
}*/
/*
class Test
{
	public:
		Test() {cout<<"Test ctr called\n";}
		~Test() {cout<<"Test dstr called\n";}
};
void myfunc()
{
//	Test obj;
}
static Test obj;
int main()
{
	cout<<"main start\n";
	myfunc();
	cout<<"main terminates\n";
	return 0;
}
*/
/*
class B {
	public:
		virtual void show() {}
};
class D : public B {};

int main()
{
	B *b = new D;
	D *d = dynamic_cast<D*>(b);
	if(d != nullptr)
		cout<<"Cast success\n";
	else
		cout<<"Cast failed\n";

	return 0;
}*/
/*
class Derived;
class Base {
	private:
		virtual void fun() {cout<<"Base Fun\n";}
	friend int main();
};

class Derived: public Base {
public:
    void fun() { cout << "Derived Fun"; }
};
 
int main()
{
   Base *ptr = new Derived;
   ptr->fun();
   return 0;
}*/

class Test {
	private:
		int *ptr;
	public:
		Test(int i = 0) {ptr = new int(i);}
		void setValue(int i) {*ptr = i;}
		void print(){cout<<*ptr<<endl;}
		Test& operator=(const Test& t)
		{
			if(this == &t)
				return *this;
			(*ptr) = *(t.ptr);
			return(*this);
		}
};

int main()
{
	Test t1(5);
	Test t2;
	t2 = t1;
	t1.setValue(10);
	t1.print();
	t2.print();

	return 0;
}
