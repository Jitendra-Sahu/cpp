//search-an-element-in-a-sorted-and-pivoted-array
//Date: Mon Oct 19 17:53:39 IST 2015

#include<iostream>

using namespace std;

int Search_Elem(int arr[], int len, int key)
{
	for(int i=0; i < len; i++)
	{
		if(key == arr[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int len = sizeof(arr)/sizeof(arr[0]);
	int key = 4;

	int index = Search_Elem(arr, len, key);
	cout<<"\n Found element at index: "<<index+1<<"\n";

	return 0;
}
