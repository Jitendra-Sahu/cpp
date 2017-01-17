//find-the-first-missing-number
//Date:Thu Nov 19 14:39:27 IST 2015

#include<iostream>

using namespace std;

int search_miss_num(int arr[], int low, int high, int i)
{
	if(high >= low)
	{
		int mid = (low + high) /2;
		if(arr[mid] == i)
			return mid;
		if(i < arr[mid])
			return search_miss_num(arr, low, mid-1, i);
		if(i > arr[mid])
			return search_miss_num(arr, mid+1, high, i);
	}
	return -1;
}

int main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 10};
	int len = sizeof(arr)/sizeof(arr[0]);
	int m = arr[len-1] + 1;

	int miss_num;
	//Find the missing number
	for(int i = 0; i < m-1; i++)
	{
		miss_num = search_miss_num(arr, 0, len-1, i);
		if(miss_num == -1)
		{
			cout<<"\nFirst Missing element: "<<i<<"\n";
			break;
		}
	}
	
	return 0;
}
