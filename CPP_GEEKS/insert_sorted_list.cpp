//Insert in a sorted linked list

#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node* next;
};

void push(node** head, int new_data)
{
	node* temp = new node();
	temp->data = new_data;
	temp->next = *head;
	*head = temp;
}

void print_list(node* head)
{
	node* temp = head;
	while(temp != nullptr)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

void insert_node(node** head, int item)
{
	node* temp = *head;
	while(temp != nullptr && temp->next->data < item)
	{
		temp = temp->next;
	}
	node* new_node = new node();
	new_node->data = item;
	new_node->next = temp->next;
	temp->next = new_node;
}

int main()
{
	node *head = nullptr;
	push(&head,13);
	push(&head,7);
	push(&head,3);
	push(&head,1);

	print_list(head);
	cout<<endl;

	insert_node(&head, 4);

	print_list(head);
        cout<<endl;
	
	return 0;
}
