#include <iostream>

class vec
{
public:
    int  arr[2];
};


int main()
{
    vec a = { { 1,2 } };// works 
    vec b = { 1,2 };// works too ,but why ?
    std::cin.get();
}
