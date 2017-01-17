//Write a function to get Nth node in a Linked List

#include<iostream>
#include<assert.h>

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
	if(head == NULL)
	{
		head = temp1;
		return;
	}
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

int getNth(int index)
{
	Node* temp = head;
	int count = 0;
	while(temp != NULL)
	{
		if(count == index)
			return (temp->data);
		++count;
		temp = temp->next;
	}
	assert(0);
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
	push(0,3);
	push(1,4);
	push(2,6);
	push(1,7);

	display();

	int pos = 2;
	int data = getNth(pos);
	cout<<"\n 2nd index data: "<<data<<endl;

	return 0;
}	
