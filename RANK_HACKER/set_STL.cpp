#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    /*int size,y, x;
    cin>>size;
    set<int>st;
    for(int i=0; i < size; ++i)
    {
        cin>>y>>x;
        if(y == 1)
        {
            st.insert(x);
        }
        set<int>::iterator it = st.find(x);
        if(it == st.end())
        {
            cout<<"No"<<endl;
        }
        else
        {
            if(y == 2)
            {
                st.erase(it);
            }
            else if(y == 3)
            {
                cout<<"Yes"<<endl;
            }
        }
    }*/
	set <int> s;
	int n,a,b;
	cin>>n;
	for(int i=0;i<n;i++){

    		cin>>a>>b;
    		switch(a)
        	{
        		case 1:s.insert(b);break;
        		case 2:s.erase(b);break;
        		case 3: set<int>::iterator itr=s.find(b);
        		if(itr==s.end())
            			cout<<"No"<<endl;
        		else
            			cout<<"Yes"<<endl;break;
    		}
	}
return 0;
}
