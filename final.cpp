#include<iostream>

using namespace std;

class Final;

class MakeFinal
{
	private:
		MakeFinal(){cout<<"\nMakeFinal CTR";}
		friend class Final;
};

class Final : virtual public MakeFinal
{
	public:
		Final(){cout<<"\nFinal CTR";}
};

/*class Derived: public Final
{
	public:
		Derived(){cout<<"\nDerived CTR";}
		void show() {cout<<"Derived::show()";}
};*/

int main()
{
	//Derived d;
	//d.show();
	Final fin;

	return 0;
}
