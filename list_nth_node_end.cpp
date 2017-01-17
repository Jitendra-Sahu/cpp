//Find n’th node from the end of a Linked List

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

void printNthFromLast(int pos)
{
	Node *temp = head;
	int len = 0;

	while(temp != NULL)
	{
		temp = temp->next;
		++len;
	}

	temp = head;

	for(int i=0; i < len-pos+1; ++i)
	{
		temp = temp->next;
	}

	cout<<pos<<"th element from end of list: "<<temp->data<<endl;

	/*
	Node* current = head;
	Node* result = head;
	int len = 0;
	while(current != nullptr)
	{
		current = current->next;
		if(len++ > pos)
		{
			result = result->next;
		}
	}
	cout<<pos<<"th element from end of list: "<<result->data<<endl;
	*/
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

	int pos = 3;
	printNthFromLast(pos);

	return 0;
}	
