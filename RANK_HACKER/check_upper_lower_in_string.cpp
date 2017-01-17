//Count alphabet in upper & lower case

#include<iostream>
#include<string>
#include<locale>

using namespace std;

int main()
{
	string in_str;
	getline(cin, in_str);
	int c1 = 0, c2 = 0;
	char c;
	locale loc;
	for(string::size_type i = 0; i < in_str.length(); ++i)
	{
		c = in_str[i];
		if(isupper(c, loc))
			++c1;
		else if(islower(c, loc))
			++c2;
		else
			continue;
	}
	cout<<c1<<"\n"<<c2<<"\n";

	return 0;
}
