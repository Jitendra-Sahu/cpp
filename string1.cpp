//Remove spaces from a given string

#include<iostream>
#include<string>

using namespace std;

void removeSpaces(char str[])
{
	int i = 0;
	int j = 0;
	while(str[i] != '\0')
	{
		if(str[i] != ' ')
		{
			str[j] = str[i];
			++j;
		}
		++i;
	}
	str[j] = '\0';
}

int main()
{
	char str[] = "g  eeks   for ge  eeks  ";
	cout<<str<<endl;
	removeSpaces(str);
	cout<<str<<endl;

	return 0;
}
