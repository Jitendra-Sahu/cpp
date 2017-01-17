//maximum-sum-such-that-no-two-elements-are-adjacent
//Date:Wed Oct 28 16:16:45 IST 2015

#include<iostream>

using namespace std;

int Max_Sum(int arr[], int len)
{
	int num1 = arr[0];
	int num2 = 0;
	int num2_new;
	for(int i = 1; i < len; i++)
	{
		num2_new = (num1 > num2)? num1 : num2;
		num1 = num2 + arr[i];
		num2 = num2_new;
	}
	return ((num1 > num2)? num1 : num2);

}

int main()
{
	//int arr[] = {5, 5, 10, 100, 10, 5};
	int arr[] = {5,  5, 10, 40, 50, 35};
	int len = sizeof(arr)/sizeof(arr[0]);
	int max_sum = Max_Sum(arr, len);
	cout<<"\n Maximum sum : "<<max_sum<<"\n";

	return 0;
}

