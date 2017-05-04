#include<iostream>

using namespace std;

int main()
{
	long int i_num;
	cout<<"Enter any number";
	cin>>i_num;

	cout<<"\n Enter number is .... ";
	(i_num % 2) == 0 ? cout<<"Even" : cout<<"Odd";

	cout<<"\n";

	return 0;
}
