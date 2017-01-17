#include<iostream>
#include<vector>

using namespace std;

class Sample
{
	public:
	Sample () {}
	Sample(const Sample& obj)
	{
		cout<<"\n Sample object copied";
	}
};

int main()
{

	//This program create big list of heap memory

        vector<Sample> vecSample;

	cout<<"\n Capacity of vector: "<<vecSample.capacity();
	cout<<"\n size of vector: "<<vecSample.size();

        for(int i=0; i < vecSample.capacity()+1; ++i)
        {
                vecSample.push_back(Sample());
        }

	cout<<"\n Capacity of vector: "<<vecSample.capacity();
	cout<<"\n size of vector: "<<vecSample.size();

        cout<<endl;

        return 0;
}

