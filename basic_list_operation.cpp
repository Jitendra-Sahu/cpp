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

void delete_node(int pos)
{
	Node *temp1 = head;
	if(pos == 1)
	{
		head = temp1->next;
		delete temp1;
		return;
	}

	for(int i = 0; i < pos-2; ++i)
	{
		temp1 = temp1->next;
	}

	Node *temp2 = temp1->next;
	temp1->next = temp2->next;
	delete(temp2->next);
}

void reverse()
{
	Node *cur, *prev, *nxt;
	cur = head;
	prev = NULL;

	while(cur != NULL)
	{
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	head = prev;
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

	display();

//	int pos = 3;
//	delete_node(pos);

//	cout<<"\n After delete the node";
//	display();

	cout<<"\n ===== ";
	cout<<"\n Reverse the list: ";
	reverse();
	display();

	return 0;
}	
