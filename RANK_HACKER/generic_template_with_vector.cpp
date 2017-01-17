/*
Write a single generic function named printArray; this function must take an array of generic elements as a parameter (the exception to this is C++, which takes a vector). The locked Solution class in your editor tests your function.
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printArray(vector<T> a)
{
    typename vector<T>::iterator it = a.begin();
    for(it; it != a.end(); ++it)
    {
        cout<<*it<<"\n";
    }
}

int main() {
  
    vector<int> vInt{1, 2, 3};
    vector<string> vString{"Hello", "World"};
    
    printArray<int>(vInt);
    printArray<string>(vString);
    
    return 0;
}
