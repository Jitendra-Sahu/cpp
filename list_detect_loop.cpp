//Write a program function to detect loop in a linked list

#include<iostream>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
};

Node *head = NULL;

void push(int pos, int data)
{
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	
	//Push at start
	if(pos == 1)
	{
		temp1->next = head;
		head = temp1;
		return;
	}

	Node* temp2 = head;
	for(int i=0; i < pos-2; ++i)
		temp2 = temp2->next;

	temp1->next = temp2->next;
	temp2->next = temp1;
}

void display()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<" "<<temp->data;
		temp = temp->next;
	}
	cout<<endl;
}

bool detectloop()
{
	Node *slow_p = head;
	Node *fast_p = head;

	while(slow_p != NULL && fast_p != NULL && fast_p->next != NULL)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if(slow_p == fast_p)
		{
			return true;
		}
	}
	return false;
}

int main()
{

	cout<<"\n Create list with position";
	cout<<"================";
	push(1,3);
	push(2,1);
	push(3,2);
	push(4,3);
	push(5,1);
	push(6,3);
	push(7,3);

	display();
	head->next->next->next = head;

	bool res = detectloop();

	if(res)
	{
		cout<<"\n List has loop";
	}
	else
	{
		cout<<"\n There is no loop";
	}

	cout<<endl;
	return 0;
}	
