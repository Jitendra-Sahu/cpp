//search-an-element-in-a-sorted-and-pivoted-array
//Date:Mon Nov  2 22:31:33 IST 2015

#include<iostream>

using namespace std;

int findPivot(int arr[], int low, int high)
{
	if(high < low) 
	{
		return -1;
	}
	if(high == low)
	{
		return low;
	}

	int mid = (low + high)/2;
	if(mid < high && arr[mid] > arr[mid+1])
		return mid;
	if(mid > low && arr[mid] < arr[mid-1])
		return (mid-1);

	if(arr[low] >= arr[mid])
	{
		return findPivot(arr, low, mid-1);
	}
	return findPivot(arr, mid+1, high);
}

int binarySearch(int arr[], int low, int high, int key)
{
	if(high < low)
	{
		cout<<"\nInsufficient element in the array";
		return -1;
	}
	
	int mid = (low + high) /2;
	
	if(arr[mid] == key)
	{
		return mid;
	}
	if(arr[mid] < key)
		return binarySearch(arr, mid+1, high, key);
	return binarySearch(arr, 0, mid-1, key);
	
}

int pivotedBinarySearch(int arr[], int n, int key)
{
	int pivot = findPivot(arr, 0, n-1);

	if(pivot == -1)
	{
		return binarySearch(arr, 0, n-1, key);
	}

	if(arr[pivot] == key)
	{
		return pivot;
	}
	if(arr[0] <= key)
	{
		return binarySearch(arr, 0, pivot-1, key);
	}
	return binarySearch(arr, pivot+1, n-1, key);
}

int main()
{
	int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	int key = 3;

	int index = pivotedBinarySearch(arr, n, key);
	cout<<"\nIndex of "<<key<<" in pivoted array: "<<index+1<<"\n";
	return 0;
}	

