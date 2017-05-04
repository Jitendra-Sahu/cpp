#include<iostream>

using namespace std;

/*class complex {
	private:
		double real;
		double img;
	public:
		explicit complex(double r=0.0, double i=0.0):real(r),img(i){}
		bool operator == (complex rhs)
		{
			return(real==rhs.real && img == rhs.img) ? true :false;
		}
};

int main()
{
	complex com1(3.0, 0.0);
	if(com1 == (complex)3.0)
		cout<<"Same\n";
	else
		cout<<"Not Same\n";

	return 0;
}*/

class Test {
	private:
		int x;
		int &ref;
	public:
		Test(int i):x(i), ref(i) {}
//		Test(const Test& t):x(t.x), ref(t.ref) {}
		void print() {cout<<ref<<endl;}
		void setX(int i) { x = i;}
		Test& operator=(const Test& t) { x = t.x; return *this;}
};

int main()
{
	Test t1(10);
	Test t2(20);
	t2 = t1;
	t1.setX(40);
	t1.print();
	t2.print();

	return 0;
}
