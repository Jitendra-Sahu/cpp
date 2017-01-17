//union-and-intersection-of-two-sorted-arrays-2
//Date:Wed Nov  4 10:21:19 IST 2015

#include<iostream>

using namespace std;

void printUnion(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	cout<<"\n Union of array:";
	while( i < m && j < n)
	{
		if(arr1[i] < arr2[j])
		{
			cout<<" "<<arr1[i++];
		}
		else if(arr1[i] > arr2[j])
		{
			cout<<" "<<arr2[j++];
		}
		else
		{
			cout<<" "<<arr2[j++];
			i++;
		}
	}

	while(i < m)
	{
		cout<<" "<<arr1[i++];
	}
	while(j < n)
	{
		cout<<" "<<arr2[j++];
	}
	cout<<"\n";
}

void printIntersection(int arr1[], int arr2[], int m, int n)
{
        int i = 0, j = 0;
        cout<<"\n Intersection of array:";
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(arr1[i] == arr2[j])
			{
				cout<<" "<<arr1[i];
				break;
			}
		}
	}
	cout<<"\n";	
}

int main()
{
	int arr1[] = {1, 2, 4, 5, 6};
	int arr2[] = {2, 3, 5, 7};
	int m = sizeof(arr1)/sizeof(arr1[0]);
	int n = sizeof(arr2)/sizeof(arr2[0]);

	printUnion(arr1, arr2, m, n);
	printIntersection(arr1, arr2, m, n);

	return 0;
}
