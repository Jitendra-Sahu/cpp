#include<iostream>

using namespace std;

class base
{
	public:
		int a;
		base() :a(0) {}
		virtual int getA() { return a;}
};

class derived : public base
{
        public:
                int b;
                derived() :b(1) {}
                int getB() { return b;}
};

void display(base* obj, int ele)
{
	for(int i = 0; i < ele; ++i)
	{
		cout<<(obj + i) -> getA()<<endl;
	}
}

int main()
{
	const int i = 3;
	base arrb[i];
	display(arrb, 3);

	derived arrd[i];
	display(arrd, 3);

	return 0;
}
