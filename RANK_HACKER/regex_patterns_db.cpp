#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<regex>

using namespace std;

int main()
{
	int N;
	cin>>N;
	regex e(".+@gmail\\.com$");
	vector<string>db;

	for(int i = 0; i < N; ++i)
	{
		string firstName;
		string emailID;
		cin>>firstName>>emailID;
		if(regex_match(emailID, e))
		{
			db.push_back(firstName);
		}
	}

	sort(db.begin(), db.end());

	for(vector<string>::iterator it = db.begin(); it != db.end(); ++it)
	{
		cout<<*it<<endl;
	}

	return 0;
}
