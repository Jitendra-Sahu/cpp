//Bubble Sort

#include<iostream>
#include<vector>

using namespace std;

void swap (int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int a_i = 0; a_i < n; ++a_i)
		cin>>a[a_i];

	int no_of_swaps = 0;
	//Sorting
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n-1; ++j)
		{
			if(a[j] > a[j+1])
			{
				swap(a[j], a[j+1]);
				no_of_swaps++;
			}
		}
		if(no_of_swaps == 0)
			break;
	}

	cout<<"Array is sorted in "<<no_of_swaps<<" swaps."<<"\n";
    	cout<<"First Element: "<<a[0]<<"\n";
    	cout<<"Last Element: "<<a[n-1]<<"\n";
    
	return 0;
}
