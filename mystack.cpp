#include<iostream>

using namespace std;

class MyStack
{
	public:
		MyStack();
		MyStack(int size);
		~MyStack();
		void push(int data);
		int pop();
		void display();
	private:
		int* stk;
		int top, length;
};

MyStack::MyStack()
{
	top = -1;
	length = 0;
	stk = 0;
}

MyStack::MyStack(int size)
{
	top = -1;
	length = size;
	if(size == 0)
	{
		stk = 0;
	}
	else
		stk = new int[length];
}

MyStack::~MyStack()
{
	delete []stk;
}

void MyStack::push(int data)
{
	if(stk == 0)
	{
		cout<<"Stack is empty";
		cout<<"\nEnter size of stack: ";
		cin>>length;
		stk = new int[length];
	}
	if(top == (length-1))
	{
		cout<<"\nCan't push data "<<data<<", Stack full"<<endl;
		return;
	}
	else
	{
		++top;
		stk[top] = data;
	}
}

int MyStack::pop()
{
	if(top == -1 || stk == 0)
	{
		cout<<"\nStack is empty.";
		return -1;
	}
	else
	{
		int ret = stk[top];
		--top;
		return ret;
	}
}

void MyStack::display()
{
	for(int i = 0; i < top; ++i)
		cout<<stk[i]<<" ";
	cout<<endl;
}

int main()
{
	MyStack s1;
	s1.push(1);
    s1.display();
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();

	return 0;
}
