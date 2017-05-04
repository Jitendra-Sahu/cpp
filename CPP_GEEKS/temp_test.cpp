#include<iostream>

using namespace std;

/*template<typename T>
void fun(const T&x)
{
	static int count=10;
	cout<<++count<<endl;
	return;
}*/
template<class T>
void fun(T a)
{
	cout<<"\n The main tmp fun():"<<a<<endl;
}

template<>
void fun(int b)
{
	cout<<"\n Specialize tmp func(): "<<b<<endl;
}

int main()
{
//	fun<int>(1);
//	fun<int>(2);
//	fun<double>(2.3);
	fun<double>(3.4);
	fun<char>('f');
	fun<int>(10);
	
	return 0;
}
	
