#include <iostream>
using namespace std;
int main()
{
	//Write code here
	int input, remainder, size, i = 0, j = 0;
	cin>>size;
	int *myOddData, *myEvenData;
	myOddData = new int[size];
	myEvenData = new int[size];
	
	int arr[size];
	for(int k = 0; k < size; ++k)
	{
	    cin>>arr[k];
	}
	int temp = 0;
	while(temp < size)
	{
	    remainder = arr[temp] % 2;
	    if(remainder == 0)
	    {
	        myEvenData[i] = arr[temp];
	        ++i;
	    }
	    else
	    {
	        myOddData[j] = arr[temp];
	        ++j;
	    }
	  
	    ++temp;
	}
	int sumEvenData = 0, sumOddData = 0;
	for(int p = 0; p < i; ++p)
	{
	    sumEvenData += myEvenData[p];
	}
	
	int avgEven = sumEvenData / i;
	
	for(int p = 0; p < j; ++p)
	{
	    sumOddData += myOddData[p];
	}
	
	int avgOdd = sumOddData / j;
	
	int total = avgEven + avgOdd;
	
	cout<<total;
	
	delete [] myEvenData;
	delete [] myOddData;
	
	return 0;
}
