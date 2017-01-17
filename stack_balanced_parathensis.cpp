/*
  C++ Program to check for balanced parentheses in an expression using stack.
  Given an expression as string comprising of opening and closing characters
  of parentheses - (), curly braces - {} and square brackets - [], we need to 
  check whether symbols are balanced or not. 
*/

#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool ArePair(char opening, char closing)
{
	if(opening == '(' && closing == ')')
		return true;
	else if(opening =='{' && closing == '}')
		return true;
	else if(opening == '[' && closing == ']')
		return true;
	return false;
}

bool AreParanthesesBalanced(string exp)
{
	stack<char> st;
	for(int i =0; i < exp.length(); ++i)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			st.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(st.empty() || (!ArePair(st.top(), exp[i])))
				return false;
			else
				st.pop();
		}
	}
	return st.empty() ? true : false;
}

int main()
{
	string expression;
	cout<<"Enter an expression: ";
	cin>>expression;
	if(AreParanthesesBalanced(expression))
		cout<<"\nBalanced\n";
	else
		cout<<"\nNot Balanced\n";

	return 0;
}
	
