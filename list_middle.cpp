//Write a C function to print the middle of a given linked list

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

void printmid()
{
	Node* slow_p = head;
	Node* fast_p = head;

	if(head != NULL)
	{
		while(fast_p != NULL && fast_p->next != NULL)
		{
			slow_p = slow_p ->next;
			fast_p = fast_p->next->next;
		}
		cout<<"\n The middle data is: "<<slow_p->data<<endl;
	}
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

int main()
{

	cout<<"\n Create list with position";
	cout<<"================";
	push(1,3);
	push(2,4);
	push(3,6);
	push(4,7);
	push(5,9);
	push(6,8);
	push(7,5);

	display();

	printmid();
	return 0;
}	
