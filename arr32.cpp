//check-if-array-elements-are-consecutive
//Mark visited array elements as negative (best approach with space as O(1)
//Date:Thu Nov 19 12:40:44 IST 2015

#include<iostream>

using namespace std;

int getMin(int arr[], int len)
{
	int i, min;
	min = arr[0];
	for(i = 1; i < len; i++)
	{
		if(arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
	
}

int getMax(int arr[], int len)
{
	int i, max;
        max = arr[0];
        for(i = 1; i < len; i++)
        {
                if(arr[i] > max)
                {
                        max = arr[i];
                }
        }
        return max;

}

bool test_consecutive(int arr[], int len)
{
	if(len < 1)
		return false;

	int min = getMin(arr, len);
	int max = getMax(arr, len);

	if((max - min + 1) == len)
	{
		int i;
		for(i = 0; i < len; i++)
		{
			int j;
			if(arr[i] < 0)
				j = -arr[i] - min;
			else
				j = arr[i] - min;

			if(arr[j] > 0)
				arr[j] = -arr[j];
			else
				return false;
		}
		return true;
	}
	return false;
}

int main()
{
	//int arr[]= {1, 4, 5, 3, 2, 6};
	int arr[]= {83, 78, 80, 81, 79, 82};
	int len = sizeof(arr)/sizeof(arr[0]);

	bool res = test_consecutive(arr, len);
	if(res)
	{
		cout<<"\nArray elements are consecutive\n";
	}
	else
	{
		cout<<"\nArray elements are not consecutive\n";
	}
	return 0;
}
