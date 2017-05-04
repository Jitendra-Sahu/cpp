//program to find given number is prime or not

#include<iostream>

using namespace std;

int main()
{
	int in_num, i, count = 0;
	cout<<"Enter a number: ";
	cin>>in_num;

	for(i = 2; i <= in_num/2; ++i) 
	{
		if((in_num % i) == 0)
		{
			++count;
			break;
		}
	}

	if(count == 0 && in_num != i)
		cout<<in_num<<" is prime number\n";
	else
		cout<<in_num<<" not a prime number\n";

	return 0;
}

