//Write a c program to check given number is perfect number or not
/*In number theory, a perfect number is a positive integer that is equal to the sum of its proper positive divisors, that is, the sum of its positive divisors excluding the number itself*/

#include<iostream>

using namespace std;

int main()
{
	int in_num, i = 1, sum = 0;
	cout<<"Enter a number to check as perfect number: ";
	cin>>in_num;

	while(i < in_num)
	{
		if((in_num % i) == 0)
		{
			sum += i;
		}
		++i;
	}

	if(sum == in_num)
		cout<<in_num<<" is perfect number\n";
	else
		cout<<in_num<<" not a perfect number\n";

	return 0;
}

