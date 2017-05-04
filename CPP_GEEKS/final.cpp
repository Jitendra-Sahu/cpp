#include<iostream>

using namespace std;

class Final;

class MakeFinal
{
	private:
		MakeFinal(){cout<<"Inside MakeFinal()"<<endl;}
	friend class Final;
};

class Final:virtual MakeFinal
{
	public:
		Final(){cout<<"Inside Final()"<<endl;}
};

/*class Derived : public Final
{
	public:
		Derived(){cout<<"Inside Derived()"<<endl;}
};
*/
int main()
{
//	Derived d;
	Final fin;

	return 0;
}
