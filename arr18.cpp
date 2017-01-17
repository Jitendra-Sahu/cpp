//binary search in an array
//Date:Mon Nov  2 12:12:20 IST 2015

#include<iostream>

using namespace std;

//insertion sort
void sort(int arr[], int n)
{
	int i, key, j;
	for(i=1; i < n; i++)
	{
		key = arr[i];
		for(j = i-1; j >=0 && key < arr[j]; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

//Non reursive method
/*void binarySearch(int arr[], int low, int high, int key)
{
	if (high < low)
	{
		cout<<"\nInsufficient elements"<<"\n";
       		return ;
	}
	int mid = (low + high)/2;  

	while(low <= high)
	{
		if(arr[mid] < key)
		{
			low = mid +1;
		}
		else if(arr[mid] == key)
		{
			cout<<"\nIndex of the element "<<key<<" : "<<mid+1<<"\n";
			break;
		}
		else
		{
			high = mid -1;
		}
		mid = (low + high)/2;
	}
}*/

//Recursive
int binarySearch(int arr[],int low, int high, int key)
{
	if(low > high)
	{
		cout<<"\nInsufficient elements"<<"\n";
                return -1;
        }
	int mid = (low + high)/2;
	if(arr[mid] == key)
	{
		return mid;
	}
	if(key > arr[mid])
	{
		return binarySearch(arr, (mid+1), high, key);
	}
	return binarySearch(arr, low, (mid-1), key);
	
}

int main()
{
	//int arr[] = {-4, 5, 8, 9, 11, 43, 485};
	int arr[] = {11, -4, 9, 43, 5, 485, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	int key = 11;
	int low = 0;
	int high =n-1;

	//insertion sort
	sort(arr, n);
	cout<<"\n Elements: ";
	for(int i = 0 ; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}

	//Non recursive
	//binarySearch(arr, low, high, key);
	
	//Recursive
	int index = binarySearch(arr, low, high, key);
	cout<<"\nIndex of the element "<<key<<" : "<<index+1<<"\n";
	return 0;
}
