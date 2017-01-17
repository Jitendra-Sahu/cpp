/*
Sample Input

3
aaab
baa
aaa
Sample Output

3
0
-1
Explanation

Test Case 1: "aaab" 
Removing 'b' at index  results in a palindrome, so we print  on a new line.

Test Case 2: "baa" 
Removing 'b' at index  results in a palindrome, so we print  on a new line.

Test Case 3: "aaa" 
This string is already a palindrome, so we print ; however, , , and  are also all acceptable answers, as the string will still be a palindrome if any one of the characters at those indices are removed.
*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int firstBad(const string &s, int first, int last) {
    for (int i = first, j = last; i <= j; ++i, --j)
        if (s[i] != s[j])
            return i;
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int size;
    cin>>size;
    for(int m = 0; m < size; ++m)
    {
        string s;
        cin>>s;
        int last = s.length() - 1;
        int i = firstBad(s, 0, last);
        if (i != -1) {
            if (firstBad(s, i, last - i - 1) == -1) {
                i = last - i;
            } else if (firstBad(s, i + 1, last - i) != -1) {
                i = -1;
            }
        }
        cout << i << endl;
    }
    return 0;
}

