#include<iostream>

using namespace std;

class ScopeDSTR
{
	public:
		ScopeDSTR() { cout<<"\n Inside CTR"; }
		~ScopeDSTR() { cout<<"\n Inside DSTR\n"; }
};

int main()
{
	cout<<"\n Inside main";
	ScopeDSTR dstr;

	cout<<"\n Before return";
	return 0;
	cout<<"\n After return";
}
