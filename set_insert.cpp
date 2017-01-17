#include<iostream>
#include<set>

using namespace std;

set<int> setofNum;

void checkAndInsert(int num)
{
	if(setofNum.insert(num).second)
	{
		cout<<"\n insertion success";
	}
	else
	{
		cout<<"\n item already present";
	}
}
	
int main()
{
	checkAndInsert(2);
	checkAndInsert(1);
	checkAndInsert(8);
	checkAndInsert(5);
	checkAndInsert(2);
	cout<<"\n size of set: "<<setofNum.size();

	cout<<"\n element in set: ";
	for(set<int>::iterator it=setofNum.begin(); it != setofNum.end(); ++it)
	{
		cout<<*it<<" ";
	}

	//search an element in set
	set<int>::iterator it = setofNum.find(5);
	if(it != setofNum.end())
	{
		cout<<"\n5 found";
	}
	else
	{
		cout<<"\n5 not found";
	}
	cout<<endl;

	return 0;
}
	
