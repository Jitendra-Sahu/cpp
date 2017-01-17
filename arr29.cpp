//equilibrium-index-of-an-array
//Date:Mon Nov 16 16:55:59 IST 2015

#include<iostream>

using namespace std;

int equili(int arr[], int n)
{
	int sum =0;
	int left_sum = 0;
	int i;

	for(i=0; i<n; i++)
		sum+=arr[i];

	for(i=0; i<n; i++)
	{
		sum -=arr[i];
		
		if(left_sum == sum)
			return i;
		
		left_sum += arr[i];
	}
	return -1;
}

int main()
{
	int arr[] = {-7, 1, 5, 2, -4, 3, 0};
	int len = sizeof(arr)/sizeof(arr[0]);
	int equ_point = equili(arr, len);

	cout<<"\nEquilibrium point: "<<equ_point<<"\n";
	return 0;
}
