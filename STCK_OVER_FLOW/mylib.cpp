#include "mylib.h"
#include<vector>
using namespace std;

    int summation(int n) {
    vector<int> numbers;
    int sum = 0;
    for(int i = 1; i <=n; i++) 
        numbers.push_back(i);
    for(int j = 0; j < numbers.size(); j++)
        sum += numbers[j];

    return sum;
    }
