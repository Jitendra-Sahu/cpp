//segregate-even-and-odd-numbers
//Date:Tue Nov  3 15:40:09 IST 2015

#include<iostream>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void segregateEvenOdd(int arr[], int size)
{
	int left = 0;
	int right = size -1;

	while(left < right)
	{
		while(arr[left] % 2 == 0 && left < right)
			left++;
		while(arr[right] % 2 == 1 && left < right)
			right--;
		if(left < right)
		{
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
}

int main()
{
	int arr[] = {12, 34, 45, 9, 8, 90, 3};
	int size = sizeof(arr)/sizeof(arr[0]);

	segregateEvenOdd(arr, size);

	cout<<"\nSegregation Even & Odd numbers: ";
	for(int i=0;  i < size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
