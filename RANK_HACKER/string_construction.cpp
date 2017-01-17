/*

Sample Input

2
abcd
abab
Sample Output

4
2
Explanation

Query 0: We start with  and .

Append character '' to  at a cost of  dollar, .
Append character '' to  at a cost of  dollar, .
Append character '' to  at a cost of  dollar, .
Append character '' to  at a cost of  dollar, .
Because the total cost of all operations is  dollars, we print  on a new line.

Query 1: We start with  and .

Append character '' to  at a cost of  dollar, .
Append character '' to  at a cost of  dollar, .
Append substring  to  at no cost, .
Because the total cost of all operations is  dollars, we print  on a new line.

*/

#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string s;
        cin >> s;
        std::vector<bool> added_chars(26, false);
        int count = 0;
        for (int i=0; i < s.size() && count != 26; ++i)     {
            if (added_chars[int(s[i])-97]==0) {
                added_chars[int(s[i])-97] = 1;
                ++count;
            }
        }
        cout << count << std::endl;
    }
    return 0;
}

