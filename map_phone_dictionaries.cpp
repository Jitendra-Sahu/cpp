#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, long> phoneBook;
    string name;
    long ph_no;
    int N;
    cin>>N;
    for(int i=1; i <=N; ++i)
    {
        cin>>name;
        cin.ignore();
        cin>>ph_no;
        phoneBook.insert(make_pair(name,ph_no));
    }
    while(cin>>name)
    {
        map<string, long>::iterator it= phoneBook.begin();
        it = phoneBook.find(name);

        if(it != phoneBook.end())
        {
            cout<<(*it).first<<"="<<(*it).second<<endl;
        }
        else
        {
            cout<<"Not found"<<endl;
        } 
    }
    return 0;
}
