//Counts of distinct consecutive sub-string of length two using C++ STL

#include<iostream>
#include<map>
#include<string>

using namespace std;

void print_distinct_substr(string str)
{
	map<pair<char,char>, int> dpairs;

	for(int i =0; i < str.size() - 1; ++i)
		dpairs[make_pair(str[i], str[i+1])]++;

	for(map<pair<char,char>, int>::iterator it = dpairs.begin(); it != dpairs.end(); ++it)
		cout<<it->first.first<<it->first.second<<"-"<<it->second<<" ";

	cout<<"\n";
}
	
int main()
{
	string str = "abcabcdabcdeabcdefabcdefg";
	//string str = "abcacdcacabacaassddssklac";
	print_distinct_substr(str);

	return 0;
}
