//Merge sort
//Date:Mon Nov  2 17:40:08 IST 2015

#include<iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l+1;
	int n2 = r -m;

	int L[n1], R[n2];

	for(i = 0; i < n1; i++)
		L[i] = arr[i+l];
	for(j = 0; j < n2; j++)
		R[j] = arr[m+1+j];

	i = 0;
	j = 0;
	k = l;

	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1)
	{
		arr[k] = L[i];
		k++;
		i++;
	}

	while(j < n2)
	{
		arr[k] = R[j];
		k++;
		j++;
	}
}

void mergesort(int arr[], int low, int high)
{
	if(low < high)
	{
		int mid = (low+high)/2;
		mergesort(arr, low, mid);
		mergesort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}

int main()
{
	int arr[] = {11, -4, 9, 43, 5, 485, 8};
	int n = sizeof(arr)/sizeof(arr[0]);

	mergesort(arr, 0, n-1);
	cout<<"\nSorted Array: ";
	for(int i =0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}

	cout<<"\n";
	return 0;
}
