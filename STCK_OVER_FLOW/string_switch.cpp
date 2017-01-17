#include <iostream>
#include <string>
using namespace std;

int main() {
   // Complete the program
  string firstString, secondString;
    cin>>firstString>>secondString;
    cout<<firstString.length()<<" "<<secondString.length()<<"\n";
    cout<<firstString<<secondString<<"\n";
    string wierdString;
    wierdString = secondString[0];
    for ( int i = 1; i <= firstString.length(); i++ ) {
        wierdString += firstString[i];
    }
    wierdString = wierdString + " " + firstString[0];
    for ( int j = 1; j <= secondString.length(); j++ ) {
        wierdString += secondString[j];
    }
    cout << wierdString;
    return 0;
}
