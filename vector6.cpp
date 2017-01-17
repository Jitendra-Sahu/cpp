#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int main()
{
	int arr[10] = {1,2,5,4,5,1,5,7,8,9};
	vector<int> vecarr(arr, arr+10);

	int elem = 5;

	vecarr.erase(remove(vecarr.begin(), vecarr.end(), elem),vecarr.end());

	vector<int>::iterator it = vecarr.begin();
	for(; it != vecarr.end(); ++it)
		cout<<*it;

	cout<<endl;
}
