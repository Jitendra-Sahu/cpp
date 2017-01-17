//Given a base- integer, , convert it to binary (base-). Then find and print the base- integer denoting the maximum number of consecutive 's in 's binary rep//resentation.

#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i=0, rem=0, max=0;
    while(n > 0)
    {
        rem = n % 2;
        if(rem == 1)
        {
            i++;
            if(i > max)
            {
                max = i;
            }
        }
        else
        {
            i = 0;
        }
        n = n/2;
    }    
    cout<<max<<endl;
    return 0;
}
