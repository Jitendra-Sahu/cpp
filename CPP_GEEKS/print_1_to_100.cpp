/*
  Print 1 to 100 in C++, without loop and recursion
*/


#include<iostream>

using namespace std;

//1st Approach
/* 
class A
{
	public:
		static int a;
		A()
		{
			cout<<a++<<endl;
		}
		~A()
		{
			cout<<"DSTR"<<endl;
		}
};

int A::a = 1;
*/

//2nd Approach
template<int N>
class PrintOneToN
{
	public:
		static void print()
		{
			PrintOneToN<N-1>::print();
			cout<<N<<endl;
		}
};

template<>
class PrintOneToN<1>
{
	public:
		static void print()
		{
			cout<<"1"<<endl;
		}
};

int main()
{
	//int N = 10;
	//A a[10];
	//A *a = new A[N];

	//delete []a;

	const int N= 10;
	PrintOneToN<N>::print();

	return 0;
}
