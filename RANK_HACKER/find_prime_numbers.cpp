//Prime numbers in two intervals

#include <iostream>
using namespace std;
int main()
{
	//Write code here
	int num1, num2, n;
	cin>>num1;
	cin>>num2;
	int count =0;
	for(n = num1; n <= num2; ++n)
	{
	    int count1 = 0;
	    for(int j = 2; j <= n/2; ++j)
	    {
	        if(n % j == 0)
	        {
	            ++count1;
	            break;
	        }
	   }
	   if(count1 == 0 && n!= 1)
	   {
	        ++count;
	   }
	 }
	 cout<<count;
	 return 0;
}
