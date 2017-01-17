//find-the-missing-number
//Date: Mon Oct 19 16:34:17 IST 2015

#include<iostream>

using namespace std;

int getMissingNo(int a[], int len)
{
	int i, total = 0;
	total = ((len+1) * (len+2))/2;
	for(i = 0; i < len; i++)
	{
		total = total - a[i];
	}
	return total;
}

int getMissingNoi_XOR(int a[], int n)
{
    int i;
    int x1 = a[0]; /* For xor of all the elemets in arary */
    int x2 = 1; /* For xor of all the elemets from 1 to n+1 */
     
    for (i = 1; i< n; i++)
        x1 = x1^a[i];
            
    for ( i = 2; i <= n+1; i++)
        x2 = x2^i;         
    
    return (x1^x2);
}

int main()
{
	int a[] = {1,2,4,5,6};
	int len = sizeof(a)/sizeof(a[0]);

	int miss_no = getMissingNo(a, len);

	cout<<"\nMissing Number: "<<miss_no<<"\n";
	return 0;
}
