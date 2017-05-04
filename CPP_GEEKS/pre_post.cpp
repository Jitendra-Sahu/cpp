#include<iostream>

using namespace std;

class Integer {
	private:
		int x_;
	public:
		Integer(int i = 0) : x_(i) {}
		Integer& operator++()
		{
			x_+=1;
			return *this;
		}
		const Integer operator++(int)
		{
			Integer temp = *this;
			++*this;
			return temp;
		}
		void print() {cout<<x_<<endl;}
};

int main()
{
	Integer obj(5);
	++obj;
	obj.print();
	obj++;
	obj.print();

	return 0;
}
