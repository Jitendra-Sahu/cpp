//segregate-0s-and-1s-in-an-array-by-traversing-array-once
//Date:Tue Nov  3 15:09:00 IST 2015

#include<iostream>

using namespace std;

void segregate(int arr[], int size)
{	
	int left = 0;
	int right = size -1;
	
	while(left < right)
	{
		while(arr[left] == 0 && left < right)
			left++;
		while(arr[right] == 1 && left < right)
			right--;

		if(left < right)
		{
			arr[left] = 0;
			arr[right] = 1;
			left++;
			right--;
		}
	}
}

int main()
{
	int arr[] = {0, 1, 0, 1, 1, 1};
	int size = sizeof(arr)/sizeof(arr[0]);

	segregate(arr, size);

	cout<<"\nArray after segregation: ";
	for(int i = 0; i < size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
