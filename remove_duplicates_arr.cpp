//Remove duplicates from array
//Date:Fri Oct 16 09:59:13 IST 2015

#include<iostream>

using namespace std;

void Print_Array(int arr[], int len)
{
	for(int i = 0; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void Sort_Array(int arr[], int len)
{
	int i, j, key;
	for(i = 1; i < len; i++)
	{
		key = arr[i];
		for(j = i-1; j < len && key < arr[j]; j--)
		{
			arr[j+1] = arr[j];
		}
	arr[j+1] = key;
	} 
}

void Remove_Dupl_Elem(int arr[], int len)
{
	int i , j;
	for(i = 0; i < len; i++)
	{
		for(j = i+1; j < len; j++)
		{
			if(arr[i] == arr[j])
			{
				arr[j] = 0;
			}
		}
	}
	cout<<"\n";
	Print_Array(arr, len);
}

void Remove_Zero(int arr[], int len)
{
	cout<<"\nAfter remove duplicate elems: ";
	for(int i = 0; i < len ; i++)
	{
		if(arr[i] != 0)
		{
			cout<<arr[i]<<" ";
		}
	}
}

int main()
{
	int arr[] = {1, 2, 3, 1, 3, 6, 6};
	int len = sizeof(arr)/sizeof(arr[0]);

	cout<<"\nArray elems: ";
	Print_Array(arr, len);

	cout<<"\nSorted elems: ";
	Sort_Array(arr, len);
	Print_Array(arr, len);

	//Sorted elems: 1 1 2 3 3 6 6
	Remove_Dupl_Elem(arr, len);
	Sort_Array(arr, len);
	Remove_Zero(arr, len);

	cout<<"\n";
	return 0;
}
