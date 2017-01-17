//check-for-majority-element-in-a-sorted-array
//Date:Tue Nov  3 09:58:43 IST 2015

#include<iostream>

using namespace std;

//Linear search
/*bool isMajority(int arr[], int n, int x)
{
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == x)
		{
			++count;
		}
	}
	if(count >= (n/2))
	{
		return true;
	}
	return false;
}*/

//Binary search
int _binarySearch(int arr[], int low, int high, int x)
{
	if(high >= low)
	{
		int mid = (low +high)/2;
		if(arr[mid] == x)
			return mid;
		if(x > arr[mid])
			return _binarySearch(arr, mid+1, high, x);
		return _binarySearch(arr, low, mid-1, x);
	}
	return -1;
}

bool isMajority(int arr[], int n, int x)
{
	int i = _binarySearch(arr, 0, n-1, x);	

	if(i == -1)
		return false;

	if(((i + n/2) <= (n-1)) && (arr[i+n/2] == x))
		return true;
	else
		return false;
}

int main()
{
	int arr[] = {1, 2, 2, 2, 2, 3, 3, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 3;

	bool res = isMajority(arr, n, x);

	if(res)
	{
		cout<<"\n"<<x<<" appears more than "<<n/2<<" times\n";
	}
	else
	{
		cout<<"\n"<<x<<" doesn't appears more than "<<n/2<<" times\n";
	}
	return 0;
}	
