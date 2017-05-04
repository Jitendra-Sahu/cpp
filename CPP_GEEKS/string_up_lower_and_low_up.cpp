//Conversion from uppercase to lower case
//Conversion from lower case to uppercase

#include<iostream>

using namespace std;

int main()
{
	char str[10];
	cout<<"\nEnter string in both upper/lower: ";
	cin>>str;

	for(int i =0; str[i] != '\0'; ++i)
	{
		if(str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
		}
		else if(str[i] >= 97 && str[i] <= 122)
		{
			str[i] -= 32;
		}
	}

	cout<<"\nAfter operation: "<<str;

	cout<<endl;

	return 0;
}
