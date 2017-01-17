#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vecInt;

	for(int i=0; i < 5; ++i)
	{
		vecInt.push_back(i);
	}

	vector<int>::iterator it=vecInt.begin();

	cout<<"\n Vector elements:";
	while(it != vecInt.end())
	{
		cout<<"\t"<<*it;
		++it;
	}

	cout<<"\n size of vector : "<<vecInt.size();
	
	cout<<endl;

	return 0;
}
	
