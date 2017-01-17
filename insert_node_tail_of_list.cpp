//Insert a node at the tail of a linked list solution

#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node* next;
};

void print_list(node* head)
{
	while(head != nullptr)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void append(node** head, int new_data)
{
	node* temp = new node();
	temp->data = new_data;
	temp->next = nullptr;

	if(*head == nullptr)
	{
		*head = temp;
	}
	else
	{
		node* curr = new node();
		curr = *head;
		while(curr->next != nullptr)
			curr = curr->next;
		curr->next = temp;
	}
}

void add_front(node** head, int new_data)
{
	node* temp = new node();
	temp->data = new_data;
	temp->next = *head;
	*head = temp;
}

int main()
{
	node* head = nullptr;
	append(&head, 6);
	append(&head, 7);
	append(&head, 1);

	print_list(head);

	add_front(&head, 6);
	add_front(&head, 7);
	add_front(&head, 1);

	print_list(head);
	
	return 0;
}
