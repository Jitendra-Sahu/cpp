#include <iostream>
    using namespace std;
    int main(void)
    {
        const char *one = "Test";
        cout << one << endl;
        const char *two = one;
        cout << two << endl;
        return 0;
    }
