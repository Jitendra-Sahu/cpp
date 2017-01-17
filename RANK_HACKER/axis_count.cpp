/*
There are two kangaroos on an x-axis ready to jump in the positive direction (i.e, toward positive infinity). The first kangaroo starts at location  and moves at a rate of  meters per jump. The second kangaroo starts at location  and moves at a rate of  meters per jump. Given the starting locations and movement rates for each kangaroo, can you determine if they'll ever land at the same location at the same time?

0 3 4 2

0->3->6->9->12
4->6->8->10->12

print "YES"

0 2 5 3

print "NO"
*/

#include<iostream>

using namespace std;

int main(){
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;
    /*if(x2 > x1 && v2 > v1)
    {
        cout<<"NO";
    }
    else
    {
        int sum1 = x1;
        int sum2 = x2;
        while(sum1 != INT_MAX && sum2 != INT_MAX)
        {
            sum1 += v1;
            sum2 += v2;
            if(sum1 == sum2)
            {
                cout<<"YES";
                break;
            }
        }
    }*/
    int dx = x1 - x2;
    int dv = v2 - v1;
    if(dv == 0)
    {
        cout<<"NO";
    }
    else if((dx % dv == 0) && (dx / dv > 0))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}
