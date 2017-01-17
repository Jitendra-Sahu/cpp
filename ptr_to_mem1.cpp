#include<iostream>
#include <signal.h>

using namespace std;

class Fred
{
	public:
		void memberFn();
		static void staticMemberFn();
};

void Fred::staticMemberFn()
{
	cout<<"static member function";
}

Fred* object_which_will_handle_signal;

void Fred_memberFn_wrapper(void*)
{
	object_which_will_handle_signal->memberFn();
}

int main()
{
	signal(SIGINT, Fred_memberFn_wrapper);
	//signal(SIGINT, Fred::staticMemberFn);

	return 0;
}
