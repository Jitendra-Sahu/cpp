#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node* next;
};

void push (node** head, int elem)
{
	node* temp = new node();
	temp->data = elem;
	temp->next = *head;
	*head = temp;
}

void print_reverse(node* head)
{
	if(head == nullptr)
	{
		return;
	}
		
	print_reverse(head->next);
	cout<<head->data<<" ";
}

int main()
{
	node* head = nullptr;
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout<<"reverse list printed recursive..";
	print_reverse(head);

	cout<<endl;
	return 0;
} 
