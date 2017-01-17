#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int main()
{
	vector<int> vecarr;
	for(int i=0; i < 5; ++i)
		vecarr.push_back(i);

	vector<int>::iterator it = vecarr.begin();
	for(;it != vecarr.end(); ++it)
		cout<<*it;

	cout<<endl;

	it = find(vecarr.begin(), vecarr.end(), 3);
	if(it != vecarr.end())
		it = vecarr.erase(it);

	cout<<"\n After erase: ";
	for(;it != vecarr.end(); ++it)
                cout<<*it;

	cout<<endl;

	return 0;
}
