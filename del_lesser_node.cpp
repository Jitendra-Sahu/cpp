//Delete nodes which have a greater value on right side

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
	while(head != nullptr)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void _del_lessernode(node* head)
{
	if(head == nullptr)
		return;

	node* current = head;
	node* max_node = head;
	node* temp;
	while(current != nullptr && current->next != nullptr)
	{
		if(current->next->data < max_node->data)
		{
			temp = current->next;
			current->next = temp->next;
			delete temp;
		}
		else
		{
			current = current->next;
			max_node = current;
		}
	}
}

void reverse_list(node** head)
{
	node* cur = *head;
	node* prev = nullptr;
	node* nxt;

	while(cur != nullptr)
	{
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	*head = prev;
}

void delLesserNode(node** head)
{
	reverse_list(head);
	
	_del_lessernode(*head);

	reverse_list(head);
}

int main()
{
	node* head = nullptr;
	push(&head, 3);
	push(&head, 2);
	push(&head, 6);
	push(&head, 5);
	push(&head, 11);
	push(&head, 10);
	push(&head, 15);
	push(&head, 12);

	cout<<"List elements are:\n";
	print_list(head);

	delLesserNode(&head);
	cout<<"Modified Linked list:\n";
        print_list(head);

	return 0;
}
