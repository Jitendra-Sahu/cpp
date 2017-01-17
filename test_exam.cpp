//Sort & search array element
//Date:Mon Nov 16 11:37:58 IST 2015

#include<iostream>

using namespace std;

void print(int arr[], int len)
{
	for(int i =0; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void sort(int arr[], int len)
{
	int i, j, key;
	for(i = 1; i < len; i++)
	{
		key = arr[i];
		for( j = i-1; j >= 0 && key < arr[j]; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

void sort_sel(int arr[], int len)
{
	int i, j, pos_max, temp;
	for(i=0; i < len; i++)
	{
		pos_max = i;
		for(j=i+1; j < len; j++)
		{
			if(arr[pos_max] > arr[j])
			{
				pos_max = j;
			}
		}
		if(pos_max != i)
		{
			temp = arr[i];
			arr[i] = arr[pos_max];
			arr[pos_max] = temp;
		}
	}
}

int search(int arr[], int low, int high, int elem)
{
	if( high >= low)
	{
		int mid = (high + low) /2;
	
		if(arr[mid] == elem)
			return mid;
		if(elem < arr[mid])
			return search(arr, low, mid-1, elem);
		if(elem > arr[mid])
			return search(arr, mid+1, high, elem);
	}
	return -1;
}

int main()
{
	int arr[] = {10, 1, 200, 30, 25, 40, 32, 31, 5, 50, 6};
	int len = sizeof(arr)/sizeof(arr[0]);

	//Before sort
	cout<<"\nBefore sort: ";
	print(arr, len);

	//sort
	sort(arr, len);

	//selection sort
	//sort_sel(arr, len);
	
	//print the array
	cout<<"\nAfter sort: ";
	print(arr, len);

	int elem = 55;
	int low = 0;
	//Binary search
	int pos = search(arr, low, len-1, elem);

	if(pos != -1)
	{
		cout<<"\nElement "<<elem<<" found at position: "<<pos+1<<"\n"; 
	}
	else
	{
		cout<<"\nElement "<<elem<<" NOT found"<<"\n";
	}

	return 0;
}
	
