//Prime number check

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int num)
{
    if(num < 2)
        return false;
    else if(num == 2)
        return true;
    else if(num % 2 == 0)
        return false;
        
    for(int i = 3, max = sqrt(num); i < max; i += 2)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    for(int i = 0; i < T; ++i)
    {
        int n;
        cin>>n;
        if(isPrime(n))
        {
            cout<<"Prime"<<endl;
        }
        else
        {
            cout<<"Not prime"<<endl;
        }
    }
    return 0;
}

