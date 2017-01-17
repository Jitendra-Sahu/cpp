//write-a-program-to-reverse-an-array
//Date: Wed Oct 21 12:38:24 IST 2015

#include<iostream>

using namespace std;

void print_Array(int arr[], int len)
{
	for(int i = 0; i < len ; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void reverse_Array(int arr[], int end)
{
	int temp = 0;
	int start = 0;
	while(start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int len = sizeof(arr)/sizeof(arr[0]);

	cout<<"\nArray: ";
	print_Array(arr, len);

	//reverse array
	reverse_Array(arr, len);

	cout<<"\n Reverse Array: ";
	print_Array(arr, len);
	cout<<"\n";
	return 0;
}
