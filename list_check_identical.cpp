//Identical Linked Lists

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

bool areIdentical(node* head1, node* head2)
{
	if(head1 == nullptr || head2 == nullptr)
		return false;

	while(head1 != nullptr && head2 != nullptr)
	{
		if(head1->data != head2->data)
		{
			return false;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	return true;
}
		

int main()
{
	node* a = nullptr;
	node* b = nullptr;
	push(&a, 1);
	push(&a, 2);
	push(&a, 3);
	push(&a, 4);
	push(&b, 1);
	push(&b, 2);
	push(&b, 3);
	push(&b, 4);

	cout<<"Two lists are:\n";
	print_list(a);
	print_list(b);

	bool res = areIdentical(a, b);
	if(res)
		cout<<"Lists are identical\n";
	else
		cout<<"No similarties in between\n";

	return 0;
}
