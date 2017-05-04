//Write a c program to check given number is strong number or not
//A number is called strong number if sum of the factorial of its digit is equal to number itself

#include<iostream>

using namespace std;

int factorial(int num)
{
	if(num == 1)
		return 1;
	else
		return(num * factorial(num-1));
}

int main()
{
	long int in_num, temp;
	cout<<"Enter number to check as strong number: ";
	cin>>in_num;

	temp = in_num;
	int sum = 0, rem, fact;
	while(in_num)
	{
		rem = in_num % 10;
		fact = factorial(rem);
		in_num = in_num / 10;
		sum = sum + fact;
	}

	if(temp == sum)
		cout<<temp<<" is strong number\n";
	else
		cout<<temp<<" not a strong number\n";

	return 0;
}	
