#include<iostream>

using namespace std;

class A{
public:
	virtual void show () {
			cout<<"\n A::show()";
		}
	A() {
		cout<<"\n inside A::A()";
	}
};

class B : public A {
private :
	void show () {
                        cout<<"\n B::show()";
                }
public:
	B() {
		cout<<"\n inside B::B()";
        }
};

int main()
{
	B b;
	A *ptr = &b;
	ptr->show();
	b.show();
}
