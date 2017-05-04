//Selection sort implementation ascending order

#include<iostream>

using namespace std;

int main()
{
	int size, i, j, temp, arr[10];
	cout<<"\nEnter the size of the list: ";
	cin>>size;

	for(i = 0; i < size; ++i)
	{
		cin>>arr[i];
	}

	for(i = 0; i < size; ++i)
	{
		for(j = i+1; j < size; ++j)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	cout<<"\nAfter sorting: ";
	for(i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
