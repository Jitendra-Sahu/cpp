#include<iostream>

using namespace std;

class Myclass
{
  public:
         Myclass();
         ~Myclass();
	char** Names;
};

Myclass::Myclass()
{
	cout<<"\n CTR calling\n";
	*Names = new char[100];
	cout<<"\n CTR calling-1\n";
        for (int j=0;j<100;j++)
        {
		cout<<"\n CTR calling-2\n";
		Names[j]=new char [10];
	}
	cout<<"\n CTR calling-3\n";
}

Myclass::~Myclass()
{
	cout<<"Name is: "<<Names[0]<<endl;
	delete Names[0];
}

int main()
{
	Myclass a;

	return 0;
}
