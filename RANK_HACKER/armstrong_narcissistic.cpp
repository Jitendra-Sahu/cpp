/*
Sample input = 1634
Sample output = True

1634 = 1 ^4 + 6 ^4 + 3 ^4 + 4^4

372 != 3 ^3 + 7 ^3 + 2 ^3
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
	//Write code here
	int num;
	cin>>num;
	int sum = 0;
	int temp = num;
	vector<int> v;
	while(num != 0)
	{
	    v.push_back(num % 10);
	    num = num / 10;
	}
	
    vector<int>::iterator it = v.begin();
    for(it; it != v.end(); ++it)
	{
	    sum += pow(*it, v.size());
	}
	
	if(temp == sum)
	{
	    cout<<"True";
	}
	else
	{
	    cout<<"False";
	}
	
	return 0;
}
