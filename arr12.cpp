//leaders-in-an-array
//Date:Fri Oct 23 12:53:04 IST 2015

#include<iostream>

using namespace std;

void printLeaders(int arr[], int n)
{
	int i ;
	for(i = 1; i < n; i++)
	{
		for(int j = i-1; j < n; j++)
		{
			if(arr[i] > arr[j])
			{
				cout<<"\n"<<arr[i]<<"\n";
				continue;
			}
			else
			{
				break;
			}
		}
	if(i == n-1)
		cout<<"\n"<<arr[i]<<"\n";
	}
}

int main()
{
	int arr[] = {16, 17, 4, 3, 5, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	printLeaders(arr, n);
	return 0;
}
