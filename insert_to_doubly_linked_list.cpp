//Doubly Linked List Insertion

#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node* next;
		node* prev;
};

void push(node** head, int ref_data)
{
	node* temp = new node();
	temp->data = ref_data;
	temp->next = *head;
	temp->prev = nullptr;

	if(*head != nullptr)
		(*head)->prev = temp;
	(*head) = temp;
}

void insertAfter(node* prev_node, int ref_data)
{
	if(prev_node == nullptr)
	{
		cout<<"\nThe given prev node can't be NULL";
		return;
	}
	node* temp = new node();
	temp->data = ref_data;
	temp->next = prev_node->next;
	prev_node->next = temp;
	temp->prev = prev_node;

	if(temp->next != nullptr)
		temp->next->prev = temp;
}

void append(node** head, int ref_data)
{
	node* temp = new node();
	node* last = *head;
	temp->data = ref_data;
	temp->next = nullptr;
	if(*head == nullptr)
	{
		temp->prev = nullptr;
		*head = temp;
		return;
	}
	while(last->next != nullptr)
		last = last->next;
	last->next = temp;
	temp->prev = last;

	return;
}

void print_list(node* head)
{
	node* last = nullptr;
	cout<<"\nTraversal in fwd direction: ";
	while(head != nullptr)
	{
		cout<<head->data<<" ";
		last = head;
		head = head->next;
	}
	cout<<"\nTraversal in bkd direction: ";
	while(last != nullptr)
	{
		cout<<last->data<<" ";
		last = last->prev;
	}
	cout<<endl;
}

int main()
{
	node* head = nullptr;
	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	insertAfter(head->next,8);
	cout<<"\nCreated DLL is:";
	print_list(head);

	return 0;
} 
