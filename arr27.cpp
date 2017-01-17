//Selection sort
//Date:Mon Nov 16 12:51:32 IST 2015

#include<iostream>

using namespace std;

void print(int arr[], int len)
{
	for(int i=0; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void sort(int arr[], int len)
{
	int i, j, min, temp;
	for(int i =0; i < len-1; i++)
	{
		min = i;
		for(j = i+1; j < len; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		if(min != i)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int len = sizeof(arr)/sizeof(arr[0]);

	cout<<"\nBefore sort: ";
	print(arr, len);

	//Selection sort
	sort(arr, len);

	cout<<"\nAfter sort: ";
	print(arr, len);
	cout<<"\n";

	return 0;
}
