#include<iostream>
#include<typeinfo>

using namespace std;

template<typename T> void foo(T* x)
{
	cout<<"foo<"<<typeid(T).name()<< ">(T*)\n";
}

void foo(int x)
{
	cout<<"foo(int) version\n";
}

void foo(double x)
{
	cout<<"foo(double) version\n";
}

int main()
{
	foo(42);
	foo(42.0);
	foo("abcdef");

	return 0;
}
