//find-duplicates-in-on-time-and-constant-extra-space
//Date:Fri Oct 16 09:48:09 IST 2015

#include<iostream>
#include<stdlib.h>

using namespace std;

void show_Duplicate(int arr[], int len)
{
	int i;
	cout<<"\nDuplicates numbers are: ";
	for(i = 0; i < len; i++)
	{
		if(arr[abs(arr[i])] >= 0)
		{
			arr[abs(arr[i])] = -arr[abs(arr[i])];
		}
		else
			cout<<abs(arr[i])<<" ";
	}
	cout<<"\n";
}

int main()
{
	int arr[] = {1, 2, 3, 1, 3, 6, 6};
	int len = sizeof(arr)/sizeof(arr[0]);
	show_Duplicate(arr, len);	
	return 0;
}
