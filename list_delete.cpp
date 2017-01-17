//Write a function to delete a Linked List

#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node* next;
};

void push(node** head, int elem)
{
	node* temp = new node();
	temp->data = elem;
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
	cout<<endl;
}

void deleteAll(node** head)
{
	node* current = *head;
	while(current != nullptr)
	{
		node* temp = current->next;
		delete current;
		current = temp;
	}
	*head = nullptr;
}

int main()
{
	node* head = nullptr;
	push(&head, 1);
	push(&head, 4);
	push(&head, 1);
	push(&head, 12);
	push(&head, 1);

	cout<<"List before delete all:\n";
	print_list(head);

	deleteAll(&head);
	cout<<"List after delete all:\n";
	if(head != nullptr)
	{
		print_list(head);
	}
	else
	{
		cout<<"No element left in list\n";
	}

	return 0;
}

