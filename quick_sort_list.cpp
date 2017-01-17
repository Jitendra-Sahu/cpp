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
	if(head == nullptr)
		return;
	cout<<head->data<<" ";
	print_list(head->next);
}

node* gettail(node* cur)
{
	while(cur != NULL && cur->next != NULL)
		cur = cur->next;

	return cur;
}

node* partition(node* head, node* end, node** newHead, node** newEnd)
{
	node* pivot = end;
	node* prev = nullptr;
	node* cur = head;
	node* tail = pivot;

	while(cur != pivot)
	{
		if(cur->data < pivot->data)
		{
			if((*newHead) == NULL)
				(*newHead) = cur;
			prev = cur;
			cur = cur->next;
		}
		else
		{
			if(prev)
				prev->next = cur->next;
			node* temp = cur->next;
			cur->next = nullptr;
			tail->next = cur;
			tail = cur;
			cur = temp;
		}
	}
	
	if((*newHead) == nullptr)
		(*newHead) = pivot;

	(*newEnd) = tail;

	return pivot;
}
node* quicksortrecur(node* head, node* end)
{
	if(!head || (head == end))
		return head;

	node* newHead = nullptr;
	node* newEnd = nullptr;

	node* pivot = partition(head, end, &newHead, &newEnd);
	
	if(newHead != pivot)
	{
		node* temp = newHead;
		while(temp->next != pivot)
			temp = temp->next;
		temp->next = NULL;
	
		newHead = quicksortrecur(newHead, temp);

		temp = gettail(newHead);
		temp->next =pivot;
	}
	pivot->next = quicksortrecur(pivot->next, newEnd);
	
	return newHead;
}
	
void quicksort(node** head)
{
	*head = quicksortrecur(*head, gettail(*head));
	return;
}

int main()
{
	node* head = nullptr;
	push(&head, 5);
	push(&head, 20);
	push(&head, 4);
	push(&head, 3);
	push(&head, 30);

	cout<<"List before sorting: ";
	print_list(head);

	quicksort(&head);
	cout<<"\nList after sorting: ";
	print_list(head);

	cout<<endl;
	return 0;
}
