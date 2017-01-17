//Find the smallest and second smallest element in an array
//Date:Thu Oct 29 18:08:04 IST 2015

#include<iostream>

using namespace std;

void sort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		/* Move elements of A[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		for(j = i-1; j >=0 && key < arr[j]; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

void remove_duplicate(int arr[], int n)
{
	for(int i = 0; i < n ; i++)
	{
		if(arr[i] == arr[i+1])
		{
			arr[i] = arr[i+1];
			arr[i+1] = arr[i+2];
		}
	}
	arr[n-1] = 0;
}

void show_two_smallest(int arr[], int n)
{
	//Sort in the ascending order
	sort(arr, n);
	remove_duplicate(arr, n);
	cout<<"\nTwo smallest number: ";
	for(int i = 0; i < 2; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int main()
{
	int arr[] = {12, 13, 1, 10, 34, 7, 9, 1, 17};
	int len = sizeof(arr)/sizeof(arr[0]);
	show_two_smallest(arr, len);

	return 0;
}
