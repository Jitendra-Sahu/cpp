//maximum-and-minimum-in-an-array
//Date:Tue Nov  3 11:29:52 IST 2015

#include<iostream>
#include<stdio.h>

using namespace std;

struct num
{
	int min;
	int max;
};

num getMinMax(int arr[], int size)
{
	struct num minmax;
	int i;

	if(size == 1)
	{
		minmax.min = arr[0];
		minmax.max = arr[0];
		return minmax;
	}

	if(arr[0] > arr[1])
	{
		minmax.min = arr[1];
		minmax.max = arr[0];
	}
	else
	{
		minmax.min = arr[0];
		minmax.max = arr[1];
	}

	for(i = 2; i < size; i++)
	{
		if(arr[i] > minmax.max)
		{
			minmax.max = arr[i];
		}
		else if(arr[i] < minmax.min)
		{
			minmax.min = arr[i];
		}
	}
	return minmax;
}

int main()
{
	int arr[] = {1000, 11, 445, 1, 330, 3000};
	int size = sizeof(arr)/sizeof(arr[0]);

	num minmax= getMinMax(arr, size);

	cout<<"\nMax elem in the array: "<<minmax.max;
	cout<<"\nMin elem in the array: "<<minmax.min<<"\n";

	return 0;
}
