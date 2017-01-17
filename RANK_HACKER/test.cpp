#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;
/*
bool chkalnum(string str)
{
    for(int i=0; i < str.length(); i++){
        if(!isalnum(str[i])){
            return false;
        }
   }
        return true;
}

bool isOnlyDouble(const char* str)
{
    char* endptr = 0;
    strtod(str, &endptr);

    if(*endptr != '\0' || endptr == str)
        return false;
    return true;
}

int main()
{
	//Write code here
	string str;
	getline(cin, str);
    try
    {
	int num = stoi(str);
        if(num)
	{
                cout<<"This input is of type Integer.";
		return;
	}
        if(isOnlyDouble(str.c_str()))
	{
                cout<<"This input is of type Float.";
		return;
	}
        if(chkalnum(str))
                cout<<"This is something else";
    }
    catch(...)
    {
        cout<<"This input is of type string.";
    }
}*/

int main()
{
/*	string str;
	getline(cin, str);

	try
	{	

	if(stoi(str))
		cout<<stoi(str);
	}
	catch(double d)
	{
		cout<<"This is double\n";
	}
	catch(string s)
	{
		cout<<"This is string\n";
	}
	catch(...)
	{
		cout<<"This is else\n";
	}*/
	int i = -1;
	for(int m = 1; m < 3; ++m)
	{
		//i = -1;
		cout<<i<<endl;
		++i;
	}
}
