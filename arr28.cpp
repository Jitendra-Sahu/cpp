//Quick sort
//Date:Mon Nov 16 15:27:39 IST 2015

#include<iostream>

using namespace std;

void print(int arr[], int len)
{
	for(int i=0; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void sort(int arr[], int low, int high)
{
	int i = low, j = high;
	int temp;
	int pivot = arr[(low + high)/2];

	while(i <= j)
	{
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot)
			j--;
		if(i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if(low < j)
		sort(arr, low, j);
	if(i < high)
		sort(arr, i, high); 
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int len = sizeof(arr)/sizeof(arr[0]);

	int low = 0;
	int high = len -1;
	cout<<"\nBefore sort: ";
	print(arr, len);

	//Quick sort
	sort(arr, low, high);

	cout<<"\nAfter sort: ";
	print(arr, len);
	cout<<"\n";

	return 0;
}
