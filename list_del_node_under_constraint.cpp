//Delete a given node in Linked List under given constraints

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

void deleteNode(node* head, node* del_node)
{
	if(head == del_node)
	{
		if(head->next == nullptr)
		{
			cout<<"\nThere is only one node, list can't be empty";
			return;
		}
		head->data = head->next->data;
		del_node = head->next;
		head->next = head->next->next;
		delete del_node;
		return;
	}
	
	node* prev = head;
	while(prev->next != nullptr && prev->next != del_node)
		prev = prev->next;

	if(prev->next == nullptr)
	{
		cout<<"\nGiven node is not present";
		return;
	}
	prev->next = prev->next->next;
	delete del_node;
	
	return;
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

	cout<<"Given Linked List: ";
	print_list(head);

	cout<<"Deleting node "<<head->next->next->data;
	deleteNode(head, head->next->next);

	cout<<"\nModified Linked List: ";
	print_list(head);

	cout<<"Deleting first node";
	deleteNode(head, head);

	cout<<"\nModified Linked List: ";
        print_list(head);

	return 0;
}
