//find-the-number-occurring-odd-number-of-times
//Date: Mon Oct 19 10:35:48 IST 2015

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
		for(j = i-1; j >= 0 && key < arr[j]; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

int main()
{
	int arr[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
	int len = sizeof(arr)/sizeof(arr[0]);

	//Sort the array
	Sort_Array(arr, len);
	//cout<<"\n Numbers: ";
	//Numbers: 2 2 2 2 3 3 4 4 4 4 5 5 5
	//Find the odd occuring number
	int count = 1;
	for(int i = count; i < len; i++)
	{
		count = 0;
		for(int j = 0; j < len; j++)
		{
			if(arr[i] == arr[j])
			{
				count += 1;
			}
		}
		if((count % 2) != 0)
		{
			cout<<"\n Odd occuring number: "<<arr[i];
			break;
		}
	}
	cout<<"\n";
	return 0;
}
