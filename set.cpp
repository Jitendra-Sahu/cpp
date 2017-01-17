#include<iostream>
#include<set>
#include<string>

using namespace std;

int main()
{
	set<string> setofNum;
	
	setofNum.insert("first");
	setofNum.insert("second");
	setofNum.insert("third");
	setofNum.insert("fourth");
	setofNum.insert("fifth");

	cout<<"\n size of set: "<<setofNum.size();

	cout<<"\n element in set: ";
	for(set<string>::iterator it=setofNum.begin(); it != setofNum.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	return 0;
}
	
