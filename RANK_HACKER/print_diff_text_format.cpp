/*
Input Format

The first line contains an integer, , the number of test cases. 
Each of the  subsequent lines describes a test case as  space-separated floating-point numbers: , , and , respectively.

Constraints

Each number will fit into a double.
Output Format

For each test case, print  lines containing the formatted , , and , respectively. Each , , and  must be formatted as follows:

: Strip its decimal (i.e., truncate it) and print its hexadecimal representation (including the  prefix) in lower case letters.
: Print it to a scale of  decimal places, preceded by a  or  sign (indicating if it's positive or negative), right justified, and left-padded with underscores so that the printed result is exactly  characters wide.
: Print it to a scale of exactly nine decimal places, expressed in scientific notation using upper case.

Sample Input

1  
100.345 2006.008 2331.41592653498
Sample Output

0x64             
_______+2006.01  
2.331415927E+03
Explanation

For the first line of output,  (in reverse, ). 
The second and third lines of output are formatted as described in the Output Format section.

*/

#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		/* Enter your code here */
		
		//Solution 1
		string integer = to_string(abs((int)B));
		cout << setw(0) << "0x" << nouppercase <<hex << (long)A << endl;
		if (B >= 0) {
			cout << setw(15 - (integer.length() + 3)) << setfill('_') << fixed << setprecision(2) << '+' << B << endl;
		} else {
			cout << setw(15) << setfill('_') << fixed << setprecision(2) << '-' << B << endl;
		}
    		cout << setprecision (9) <<uppercase << fixed << scientific << C <<endl;

		//Solution 2
        	/*unsigned long long int a = (unsigned long long int)(A);

        	cout << resetiosflags(ios::uppercase);

        	cout.flags(ios::left | ios::hex | ios :: showbase);

        	cout <<  a << endl;
        	int b = (int)B,cnt = 0; 
        	while(b) { b = b/10; cnt++; } cnt += 4; cnt = 15 - cnt; 
        	cout << setw(cnt + 1) << internal; cout.precision(2);           
        	cout << setfill('_') << fixed << setprecision(2) << nouppercase ; 
        	if(B > 0) 
        	{
            		cout<<"+"; cout << B<< endl;
        	}
        	cout << setw(0) << scientific << setprecision(9) << uppercase << C << endl;*/
	}
	return 0;
}
