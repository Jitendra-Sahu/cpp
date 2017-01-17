//Two elements whose sum is closest to zero
//Date:Fri Oct 30 11:11:28 IST 2015

#include<iostream>

using namespace std;

void print_array(int arr[], int len)
{
	cout<<"\nArray elems: ";
	for(int i = 0; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void sort(int arr[], int len)
{
	int key, i, j;
	for(i = 1; i < len; i++)
	{
		key = arr[i];
		for(j = i-1; j >= 0 && key < arr[j]; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
		
}

void Sum_Pair(int arr[], int len)
{
	sort(arr, len);
	print_array(arr, len);
	cout<<"\nCloset sum elements: "<<arr[0]<<" "<<arr[len-1];
	cout<<"\n";
}

int main()
{
	int arr[] = {1, 60, -10, 70, -80, 85, -82};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	Sum_Pair(arr, len);

	return 0;
}
