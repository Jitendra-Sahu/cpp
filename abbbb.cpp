#include<iostream>
#include<typeinfo>

using namespace std;

class A
{
	public:
	virtual ~A();
};

int main()
{
	A* a = NULL;
	//char c;
	//float x;
	//if(typeid(c) != typeid(x))
	//{
	//cout<<typeid(c).name()<<endl;
	try
	{
	cout<<typeid(*a).name()<<endl;
	}
	catch(bad_typeid)
	{
		cout<<"Object is NULL"<<endl;
	}
	return 0;
}

/*void division(char b)
{
	
}

int main()
{
	double op1 = 0, op2 = 0;
	try
	{
		division(op1, op2);
	}
	catch(const char* str)
	{
		cout<<"Bad operator:"<<str;
	}
	return 0;
}*/
