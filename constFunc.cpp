#include<iostream>

using namespace std;

class constTest
{
	public:
		void test_const() const
		{
			cout<<"\n const method";
		}
		void test_non_const()
		{
			cout<<"\n non const method";
		}
		constTest(){
			cout<<"\n CTOR";
		}
		~constTest(){
			cout<<"\n DCTOR"<<endl;
		}
};

int main()
{
	constTest non_const_obj;
	constTest const const_obj;
	
	non_const_obj.test_const();
	non_const_obj.test_non_const();
	
	const_obj.test_const();

	return 0;
}
