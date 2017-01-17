#include<iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node* next;
};

void push(Node** head, int new_data)
{
	Node* temp = new Node();
	temp->data = new_data;
	temp->next = *head;
	*head = temp;
}

void moveToFront(Node** head)
{
	if(*head == nullptr || (*head)->next == nullptr)
		return;

	Node* secLast = nullptr;
	Node* last = *head;

	while(last->next != nullptr)
	{
		secLast = last;
		last = last->next;
	}

	secLast->next = nullptr;
	last->next = *head;

	*head = last;
}

void printList(Node* head)
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int main()
{
	Node *head = nullptr;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout<<"Linked list before moving last to front\n";
	printList(head);

	//Move the last to front
	moveToFront(&head);

	cout<<"\nLinked list after move last to front\n";
        printList(head);
	cout<<endl;
	return 0;
}
