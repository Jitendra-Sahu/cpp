//Write a function that counts the number of times a given int occurs in a Linked List 

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

int getcount(int val)
{
	Node *temp = head;
	int count = 0;
	while(temp != NULL)
	{
		if(temp->data == val)
		{
			++count;
		}
		temp = temp->next;
	}
	return count;
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

	int value = 2;
	int count = getcount(value);

	cout<<"\n Number: "<<value<<" present "<<count<<" number of times"<<endl;
	return 0;
}	
