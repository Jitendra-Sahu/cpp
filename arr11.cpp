//array-rotation
//Date:Wed Oct 21 15:48:24 IST 2015

#include<iostream>

using namespace std;

void print_array(int arr[], int len)
{
	for(int i = 0; i < len ; i++)
        {
                cout<<arr[i]<<" ";
        }
	cout<<"\n";
}

void rotate_array(int arr[], int len)
{
	int i, temp;
	temp = arr[0];
	for (i = 0; i < len-1; i++)
	{
		arr[i] = arr[i+1];
	}
	arr[i] = temp;
}


void leftrotate_array(int arr[], int size, int times)
{
	for(int i = 0; i < times; i++)
	{
		rotate_array(arr, size);
	}
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int size = 7;
	int freq = 2;
	cout<<"\nArray: ";
	print_array(arr,size);

	leftrotate_array(arr, size, freq);	
	
	cout<<"\nAfter rotation: ";
	print_array(arr,size);
	return 0;
}
