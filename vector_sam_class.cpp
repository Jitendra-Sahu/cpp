#include<iostream>
#include<vector>

using namespace std;

class Sample
{	
public:
        Sample () 
	{
		cout<<"\n Default constrctor";
	}
	Sample(const Sample& obj)
        {
                cout<<"\n Sample object copied";
        }
        Sample& operator=(const Sample& obj)
        {
                cout<<"\n Sample :: assignment operator";
        }
};

int main()
{
        vector<Sample> vecSample;
	Sample obj;

	vecSample.push_back(obj);
        cout<<"\n Capacity of vector: "<<vecSample.capacity();
        cout<<"\n size of vector: "<<vecSample.size();

        cout<<endl;

        return 0;
}
