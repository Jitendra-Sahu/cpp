//check given string is palindrome number or not

#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	string str;
	cout<<"Enter string to check palindrome: ";
	getline(cin, str);

	stack<char>st;
	int i = 0;
	for(;i < str.length(); ++i)
	{
		st.push(str[i]);
	}

	i = 0;
	bool pal_status = true;
	while(!st.empty() && i < str.length())
	{
		if(st.top() != str[i])
		{
			pal_status = false;
			break;
		}
		++i;
		st.pop();
		
	}
	cout<<endl;

	if(pal_status)
	{
		cout<<str<<" is palindrome"<<endl;
	}
	else
	{
		cout<<str<<" not palindrome"<<endl;
	}

	return 0;
}
