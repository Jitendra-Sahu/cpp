//Merge two sorted linked lists

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
	while(head != nullptr)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

node* sorted_merge(node* a, node* b)
{
	node* res = nullptr;
	if(a == nullptr)
		return(b);
	else if(b == nullptr)
		return(a);

	if(a->data <= b->data)
	{
		res = a;
		res->next = sorted_merge(a->next, b);
	}
	else
	{
		res = b;
		res->next = sorted_merge(a, b->next);
	}
	return(res);
}

int main()
{
	node* a = nullptr;
	node* b = nullptr;
	node* res = nullptr;

	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	cout<<"1st List:"; 
	print_list(a);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);
	cout<<"2nd List:"; 
	print_list(b);

	res = sorted_merge(a, b);
	
	cout<<"Sorted two list:";
	print_list(res);

	return 0;
}
	
