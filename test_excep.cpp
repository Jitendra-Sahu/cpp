#include<iostream>

using namespace std;

class VectorInSpecialMemory
{
	public:
		VectorInSpecialMemory(int s):sz(s), elem(AllocateInSpecialMemory(s))
		{
			if(elem == NULL)
				throw bad_alloc();
		}
	private:
		int sz;
		int* elem;
};

int main()
{
	return 0;
}
