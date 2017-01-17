#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    char a;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    for(auto &c: s)
    //for(int i = 0; i < s.length(); ++i)
    {
        //char c = s[i];
        if(isalpha(c))
        {
            a = isupper(c) ? 'A':'a';
            c = a + (c - a + k) % 26;
        }
    }
    /*for(int i = 0; i < s.length(); ++i)
    {
        cout<<s[i];
    }*/
    cout<<s;
    return 0;
}
