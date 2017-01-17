#include<iostream>

using namespace std;

void left_rotate_by_one(int arr[], int len)
{
	int i = 0;
	int temp = arr[0];
	for(i = 0; i < len-1; ++i)
	{
		arr[i] = arr[i+1];
	}
	arr[i] = temp;
}

void left_rotate_arr(int arr[], int len, int d)
{
	for(int i = 0; i < d; ++i)
	{
		left_rotate_by_one(arr, len);
	}
}

void print_array(int arr[], int arr_len)
{
	for(int i=0; i < arr_len; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int arr_len = sizeof(arr)/sizeof(arr[0]);

	cout<<"\n Array elements -->";
	print_array(arr, arr_len);

	//rotate the array
	left_rotate_arr(arr, arr_len, 2);

	cout<<"\n Array elements -->";
        print_array(arr, arr_len);

	return 0;
}
