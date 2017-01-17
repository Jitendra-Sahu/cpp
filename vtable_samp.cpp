#include<iostream>

using namespace std;

class Test
{
	public:
		virtual void fun1() {cout<<"Test::fun1 begin..\n";}
		virtual void fun2() {cout<<"Test::fun2 begin..\n";}
};

int main()
{
	Test obj;
	cout<<"VPTR's address: "<<(int*)(&obj+0)<<endl;
	cout << "VIRTUAL TABLE 's Address"<< (int*)((int*)(&obj+0)) << endl;
	// Calling Virtual table functions
	cout << "Value at 1st entry of VTable " << (int*)((int*)(int*)(&obj+0)+0) << endl;
	cout << "Value at 2nd entry of VTable " << (int*)((int*)(int*)(&obj+0)+1) << endl;

	return 0;
}
