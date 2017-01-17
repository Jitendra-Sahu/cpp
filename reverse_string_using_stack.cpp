#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	char str[] = "abc gfd";
	cout<<str<<endl;
	stack<char> S;
	int len = strlen(str);
	for(int i = 0; i < len; ++i)
	{
		S.push(str[i]);
	}
	for(int i = 0; i < len; ++i)
	{
		str[i] = S.top();
		S.pop();
	}
	cout<<str<<endl;

	return 0;
}
	
