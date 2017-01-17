#include<iostream>
#include<stack>
#include<map>
#include<iterator>
#include<string>

using namespace std;

bool isOpenBracket(char val, map<char, char> mapOfBrackets)
{
	map<char, char>::iterator it = mapOfBrackets.begin();
	while(it != mapOfBrackets.end())
	{
		if(it->second == val)
		{	
			return true;
		}
		++it;
	}
	return false;
}
		
bool testBracket(string s)
{
	stack<char> bracketStack;
	map<char, char> bracketMap;

	bracketMap['}'] = '{';
	bracketMap[']'] = '[';
	bracketMap[')'] = '(';

	for(int i =0; i < s.size(); i++)
	{
		if(isOpenBracket(s[i], bracketMap))
			bracketStack.push(s[i]);
		if(bracketMap.find(s[i]) != bracketMap.end())
		{
			if(bracketStack.empty())
				return false;
			if(bracketStack.top() != bracketMap[s[i]])
			{
				return false;
			}
			else
				bracketStack.pop();
		}
	}
	if(bracketStack.size() > 0)
		return false;
	else
		return true;
}

int main()
{
	cout<<"\n Bracket test: "<<testBracket("([(2+11)]+)")<<endl;
	return 0;
}
