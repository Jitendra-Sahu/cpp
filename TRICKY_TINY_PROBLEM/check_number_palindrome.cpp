//palindrome Program For Number

#include<iostream>

using namespace std;

int main()
{
	long int in_num, temp;
	int sum = 0, rem;
	cout<<"\nEnter number to check palindrome: ";
	cin>>in_num;

	temp = in_num;
	/*while(in_num)*/
	for(; in_num != 0; in_num = in_num / 10)
	{
		rem = in_num % 10;
		//in_num = in_num / 10;
		sum = (sum * 10) + rem;
	}

	if(temp == sum)
	{
		cout<<temp<<" is palindrome";
	}
	else
	{
		cout<<temp<<" not a palindrome";
	}
	cout<<endl;

	return 0;
}
