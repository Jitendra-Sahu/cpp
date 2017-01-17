//Delete alternate nodes of a Linked List

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
	node* temp = head;
	while(temp != nullptr)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void deleteAlt(node* head)
{
	if(head == nullptr)
		return;

	node* prev = head;
	node* temp = head->next;

	while(prev != nullptr && temp != nullptr)
	{
		prev->next = temp->next;
		delete(temp);

		prev = prev->next;
		if(prev != nullptr)
			temp = prev->next;
	}	
}

void recur_deleteAlt(node* head)
{
	if(head == nullptr)
                return;

	node* temp = head->next;
	if(temp == nullptr)
		return;

	head->next = temp->next;

	delete(temp);
	recur_deleteAlt(head->next);
}

int main()
{
	node* head = nullptr;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout<<"List before calling deleteAlt():";
	print_list(head);

	cout<<"List after calling deleteAlt():";
	//deleteAlt(head);
	recur_deleteAlt(head);
	print_list(head);

	return 0;
}	
