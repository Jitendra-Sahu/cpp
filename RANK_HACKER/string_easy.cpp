#include <iostream>
#include <string>
using namespace std;

int main() {
   // Complete the program
    string str1, str2;
    cin>>str1>>str2;
    int len1 = str1.size();
    int len2 = str2.size();
    cout<<len1<<" "<<len2<<endl;
    string str3 = str1 + str2;
    cout<<str3<<endl;
    int new_len = len1 + len2 + 2;
    char c[new_len];
    int i = 0;
    string::iterator it;
    for(it = str1.begin(); it != str1.end(); ++it)
    {
            c[i] = *it;
	    ++i;
    }
    for(it = str2.begin(); it != str2.end(); ++it)
    {
           c[i] = *it;
           ++i;
    }
    c[0] = str2[0];
    c[len1] = ' ';
    c[len1 + 1] = str1[0];
    c[len1 + 2] = str2[1];
    for(int i = 0; i < new_len; ++i)
    {
        cout<<c[i];
    }
	cout<<endl;
    return 0;
}
