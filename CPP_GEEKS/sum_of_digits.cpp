/*
  How can we sum the digits of a given number in single statement?
*/

#include<iostream>

using namespace std;

int getSum(long int n)
{
	int sum = 0;
	for(; n > 0; sum += n % 10, n /= 10);
	return sum;
}

int main()
{
	long int n = 687;
	
	long int res = getSum(n);
	
	cout<<"Sum: "<<res<<endl;

	return 0;
}
