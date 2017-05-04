#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
	list<int> mylist;
	mylist.push_back(4);
	mylist.push_front(2);
	mylist.push_back(7);
	mylist.push_front(5);

	list<int> mylist2;
        mylist2.push_back(8);
        mylist2.push_front(3);
        mylist2.push_back(9);
        mylist2.push_front(6);

	cout<<"Before swap\n";
	list<int>::iterator it = mylist.begin();
	for(it; it != mylist.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	list<int>::iterator it2 = mylist2.begin();


	for(; it2 != mylist2.end(); ++it2)
        {
                cout<<*it2<<" ";
        }

	cout<<endl;
	swap(mylist, mylist2);
	cout<<"After swap\n";
	cout<<"Length of list1: "<<mylist.size();
	cout<<"Length of list2: "<<mylist2.size();
        for(it = mylist.begin(); it != mylist.end(); ++it)
        {
                cout<<*it<<" ";
        }
        cout<<endl;

        for(it2 = mylist2.begin(); it2 != mylist2.end(); ++it2)
        {
                cout<<*it2<<" ";
        }


	cout<<endl;
	return 0;
}
