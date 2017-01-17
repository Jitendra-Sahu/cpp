//Delete a Linked List node at a given position

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

void del_pos(node** head, int pos)
{
	node* temp1 = *head;
	if(head == NULL)
	{
		return;
	}
	if(pos == 1)
	{
		*head = temp1->next;
		(*head)->data = temp1->next->data;
		delete temp1;
	}

	for(int i =0; i < pos-2; ++i)
		temp1 = temp1->next;

	node* temp2 = temp1->next;
	temp1->next = temp2->next;

	delete temp2;
}

int main()
{
	node* head = nullptr;
	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);
	push(&head, 8);

	cout<<"Created Linked List: ";
	print_list(head);

	int pos = 5;
	del_pos(&head, pos);
	cout<<"List after delete@ "<<pos<<": ";
	print_list(head);

	return 0;
}
