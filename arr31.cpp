//check-if-array-elements-are-consecutive
//Date:Thu Nov 19 11:30:36 IST 2015

#include<iostream>

using namespace std;

void print(int arr[], int len)
{
	for(int i = 0; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void sort(int arr[], int len)
{
	int i, key, j;
	for(i = 1; i < len-1; i++)
	{
		key = arr[i];
		for(j = i-1; j >= 0 && arr[j] > key; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

void sort_sel(int arr[], int len)
{
	int i, pos_min,j, temp;
	for(i = 0; i < len; i++)
	{
		pos_min = i;
		for(j = i+1; j < len; j++)
		{
			if(arr[pos_min] > arr[j])
			{
				pos_min = j;
			}
		}
		if(pos_min != i)
		{
			temp = arr[i];
			arr[i] = arr[pos_min];
			arr[pos_min] = temp;
		}
	}  
}

bool chk_consecutive(int arr[], int len)
{
	int i, diff;
	for(i = 0; i < len-1; i++)
	{
		diff = arr[i+1] - arr[i];
	}
	if(diff == 1)
		return true;

	return false;
}

int main()
{
	//int arr[]= {5, 4, 2, 3, 1, 6};
	int arr[]= {34, 23, 52, 12, 3};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	//Insertion sort
	//sort(arr, len);

	//Selection sort
	sort_sel(arr, len);

	cout<<"\nSorted array: ";
	print(arr, len);

	bool res = chk_consecutive(arr, len);
	if(res)
	{
		cout<<"\nArray has consecutive element\n";
	}
	else
	{
		cout<<"\nArray doesn't have consecutive element\n";
	}
	cout<<"\n";
	return 0;
}

