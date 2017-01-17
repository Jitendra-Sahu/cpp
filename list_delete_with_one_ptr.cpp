//Given only a pointer/reference to a node to be deleted in a singly linked list, how do you delete it?

#include<iostream>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
};

Node *head = NULL;

void push(int data)
{
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = head;
	
	head = temp1;
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

void deleteNode(Node* node)
{
	Node* temp = node->next;
	node->data = temp->data;
	node->next = temp->next;
	delete(temp);
}

int main()
{

	cout<<"\n Create list with position";
	cout<<"================";
	push(3);
	push(1);
	push(2);
	push(8);
	push(12);

	display();

	deleteNode(head);

	display();

	return 0;
}	
