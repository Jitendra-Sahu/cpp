//Count Inversions in an array
//Date:Wed Oct 28 23:03:24 IST 2015

#include<iostream>

using namespace std;

void Print_Inversion(int arr[], int n)
{
	int inver_count = 0;
	for(int i =0; i < n-1; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if(arr[i] > arr[j])
			{
				++inver_count;
			}
		}
	}
	cout<<"\nNumber of inversion: "<<inver_count<<"\n";
}

int main()
{
	int arr[] = {1, 20, 6, 4, 5};
	int len = sizeof(arr)/sizeof(arr[0]);
	Print_Inversion(arr, len);
	return 0;
}
