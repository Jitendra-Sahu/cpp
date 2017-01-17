//next-greater-element
//Date:Thu Nov 19 10:27:31 IST 2015

#include<iostream>

using namespace std;

void next_great_elem(int arr[], int len)
{
	int i, j, next;
	for(i = 0; i < len; i++)
	{
		next = -1;
		for(j=i+1; j < len; j++)
		{
			if(arr[i] < arr[j])
			{
				next = arr[j];
				break;
			}
		}
	cout<<"\nNext great element of arr["<<i<<"] "<<arr[i]<<"--> "<<next;
	}
}

int main()
{
	//int arr[]= {11, 13, 21, 3};
	int arr[]= {13, 7, 6, 12};
	int len = sizeof(arr)/sizeof(arr[0]);
	next_great_elem(arr, len);

	cout<<"\n";
	return 0;
}
