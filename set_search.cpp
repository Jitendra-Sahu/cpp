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

	//search an element in set
	set<string>::iterator it = setofNum.find("sixth");
	if(it != setofNum.end())
	{
		cout<<"\nsixth found";
	}
	else
	{
		cout<<"\nsixth not found";
	}
	cout<<endl;

	return 0;
}
	
