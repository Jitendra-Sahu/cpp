#include<iostream>

using namespace std;

int print(int n)
{
  if(n == 1)
    return 1;
  else
  {
     cout<<n<<" ";
     return (print(n-1));
  }
}

int add(int n)
{
  if(n == 1)
    return 1;
  else
  {
    return(n+add(n-1));
  } 
}

int main()
{
  cout<<"Welcome \n";
  int n;
  cout<<"Enter the number: ";
  cin>>n;
  cout<<"\n Print value:"<<print(n)<<"\n";
  cout<<"\n Add value:"<<add(n)<<"\n";
  return 0;
}
