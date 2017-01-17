//Remove duplicates from an unsorted linked list

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
	node* current = head;
	while(current != nullptr)
	{
		cout<<current->data<<" ";
		current = current->next;
	}
	cout<<endl;
}

void remove_duplicates(node* head)
{
	node* ptr1 = head;
	node* ptr2, *dup;
	while(ptr1 != nullptr && ptr1->next != nullptr)
	{
		ptr2 = ptr1;
		while(ptr2->next != nullptr)
		{
			if(ptr1->data == ptr2->next->data)
			{
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete dup;
			}
			else
			{
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}

int main()
{
	node* head = nullptr;
	push(&head, 21);	
	push(&head, 43);	
	push(&head, 41);	
	push(&head, 21);
	push(&head, 12);
	push(&head, 11);
	push(&head, 12);

	/*push(&head, 10);	
	push(&head, 11);	
	push(&head, 12);	
	push(&head, 11);
	push(&head, 11);
	push(&head, 12);
	push(&head, 10);*/

	cout<<"List has duplicate values:";
	print_list(head);

	remove_duplicates(head);
	cout<<"After remove duplicate values:";
        print_list(head);

	return 0;
}
