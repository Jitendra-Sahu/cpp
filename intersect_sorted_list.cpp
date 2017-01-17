//Intersection of two Sorted Linked Lists

#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node* next;
};

void push(node** head, int ref_data)
{
	node* temp = new node();
	temp->data = ref_data;
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

node* sorted_intersect(node* a, node* b)
{
	if(a == nullptr || b == nullptr)
		return NULL;

	if(a->data < b->data)
		return sorted_intersect(a->next, b);
	if(a->data > b->data)
		return sorted_intersect(a, b->next);

	node* temp = new node();
	temp->data = a->data;

	temp->next = sorted_intersect(a->next, b->next);
	
	return temp;
}	

int main()
{
	node* a = nullptr;
	node* b = nullptr;
	node* intersect = nullptr;

	push(&a, 6);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);

	push(&b, 8);
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);

	intersect = sorted_intersect(a, b);

	cout<<"Two list items are\n";
	print_list(a);
	print_list(b);
	cout<<"List containing common items of a & b: ";
	print_list(intersect);

	return 0;
}
	
