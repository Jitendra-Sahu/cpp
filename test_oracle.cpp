#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	//printf("%d", printf("Oracle"));

	int i = 1;

/*	for(i=0; i=-1; i=1)
	{
		cout<<i<<endl;
		if(i != 0)
		{
			break;
		}
	}*/

	int a=2, b=3, c=2;

	printf("%d, %d, %d", a+b+c, (c=a*2), (b = a+c));

	return 0;
}
