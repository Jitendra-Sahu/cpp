/*
You are given four integers: , , , . You will use them in order to create the sequence  with the following pseudo-code.

a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31) 
Your task is to calculate the number of distinct integers in the sequence .

Sample Input

3 1 1 1
Sample Output

3

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
 
#define SetBit(A,k)     ( A[(k/32)] |= (1 << (k%32)) )
#define ClearBit(A,k)   ( A[(k/32)] &= ~(1 << (k%32)) )            
#define TestBit(A,k)    ( A[(k/32)] & (1 << (k%32)) )
 
typedef unsigned long long ULONG;
 
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	ULONG N, S, P, Q, num;
	//N = 100000000; S = 2065188356; P = 657733125; Q = 1636844041;
	cin >> N >> S >> P >> Q;
 
	ULONG p_231 = static_cast<ULONG>(pow(2, 31));
	int *bitarr = new int[p_231 / 32];
	memset(bitarr, 0, sizeof(int) * (p_231 / 32));
 
	ULONG prev = S % p_231;
	SetBit(bitarr, prev);
	ULONG result = 1;
 
	for (ULONG i = 1; i < N; i++) {
		num = prev * P + Q;
		prev = num % p_231;
 
		if (!TestBit(bitarr, prev)) {
			SetBit(bitarr, prev);
			result++;
		}
	}
 
	cout << result;
 
	delete[] bitarr;
 
	return 0;
}
