//Program for sorting of string

#include<iostream>

using namespace std;

int main()
{
	int i, j, n;
	char str[20][20], temp[20];
	cout<<"\nEnter the no. of string to be sorted: ";
	cin>>n;

	for(i = 0; i < n; ++i)
	{
		cin>>str[i];
	}

	for(i = 0; i < n; ++i)
	{
		for(j = i+1; j < n; ++j)
		{
			if(strcmp(str[i], str[j]) > 0)
			{
				strcpy(temp,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],temp);
			}
		}
	}

	cout<<"\nAfter sort: ";
	for(i = 0; i < n; ++i)
	{
		cout<<"\n"<<str[i];
	}

	return 0;
}
