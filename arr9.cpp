//Merge an array of size n into another array of size m+n
//Date: Tue Oct 20 11:22:37 IST 2015

#include<iostream>

#define NA -1

using namespace std;


void print_Array(int arr[], int len)
{
	//int len = sizeof(arr)/sizeof(arr[0]);
	for(int i =0; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void merge(int mPlusN[], int N[], int m, int n)
{
  int i = n;  /* Current index of i/p part of mPlusN[]*/
  int j = 0; /* Current index of N[]*/
  int k = 0; /* Current index of of output mPlusN[]*/
  while (k < (m+n))
  {
    /* Take an element from mPlusN[] if
       a) value of the picked element is smaller and we have
          not reached end of it
       b) We have reached end of N[] */
    if ((i < (m+n) && mPlusN[i] <= N[j]) || (j == n))
    {
      mPlusN[k] = mPlusN[i];
      k++;
      i++;
    }
    else  // Otherwise take emenet from N[]
    {
      mPlusN[k] = N[j];
      k++;
      j++;
    }
  }
}

void arrange_Array(int arr_1[], int len)
{
	int i = 0, j = len -1;
	for(i = len -1; i >= 0; i--)
	{
		if(arr_1[i] != NA)
		{
			arr_1[j] = arr_1[i];
			j--;
		}
	}
}

int main()
{
	int arr_1[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
	//int arr_1[] = {2, 8, 13, 15, 20};
	int arr_2[] = {5, 7, 9, 25};
	int len_2 = sizeof(arr_2)/sizeof(arr_2[0]);
	int len_1 = sizeof(arr_1)/sizeof(arr_1[0]);

	arrange_Array(arr_1, len_1);
	cout<<"\nAfter rearrange: ";
	print_Array(arr_1, len_1);
	merge(arr_1, arr_2, len_1, len_2);
	cout<<"\n Merge Array: ";
	//print_Array(arr_1, len_1 + len_2);
	print_Array(arr_1, len_1);
	cout<<"\n";

	return 0;
}
