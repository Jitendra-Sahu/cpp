#include<iostream>

using namespace std;

/*int* f()
{
	int x =10;
	return (&x);
}*/

int main()
{
	/*int *y = f();
	cout<<(*y)<<endl;*/
	int x = 10;
	int y = 20;
	if((x = 11) & (y == 20))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
