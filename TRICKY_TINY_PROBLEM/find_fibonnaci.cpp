//print Fibonacci series

#include<iostream>

using namespace std;

int print_fibo(int range)
{
	int res;
	if(range == 0)
		return 0;
	else
	{
		if(range == 1)
			return 1;
		else
		{
			res = print_fibo(range-1) + print_fibo(range-2);
			return res;
		}
	}	
}
	

int main()
{
	int num_range, i, res;
	cout<<"Enter the series range: ";
	cin>>num_range;

	for(i = 0; i < num_range; ++i)
	{
		res = print_fibo(i);
		cout<<res<<" ";
	}
	cout<<endl;	
	return 0;
}

