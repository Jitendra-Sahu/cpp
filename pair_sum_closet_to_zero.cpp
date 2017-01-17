//Two elements whose sum is closest to zero
//Date:Mon Nov  2 11:51:03 IST 2015

#include<iostream>
#include<stdlib.h>

using namespace std;

void Min_Sum_Pair(int arr[], int len)
{
	int min_sum;
	if(len < 2)
	{
		cout<<"\n Insufficient numbers";
		return;
	}

	int min_l = 0;
	int min_r = 1;
	min_sum = arr[min_l] + arr[min_r];

	for(int l = 0; l < len -1; l++)
	{
		for(int r = l+1; r < len; r++)
		{
			int sum = arr[l] + arr[r];
			if(abs(min_sum) > abs(sum))
			{
				min_sum = sum;
				min_l = l;
				min_r = r;
			}
		}	
	}
	cout<<"\n Min sum of two numbers from list: "<<arr[min_l]<<" "<<arr[min_r]<<"\n";
}

int main()
{
	int arr[] = {1, 60, -10, 70, -80, 85, -82};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	Min_Sum_Pair(arr, len);

	return 0;
}
