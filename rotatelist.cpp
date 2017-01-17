#include<iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node* next;
};

void push(Node** head, int new_data)
{
	Node* temp = new Node();
	temp->data = new_data;
	temp->next = *head;
	*head = temp;
}

void print_list(Node* head)
{
	Node* temp = head;
	while(temp != nullptr)
	{
		cout<<temp->data;
		temp = temp->next;
		if(temp != nullptr)
		{
			cout<<"->";
		}
	}
}

void rotate(Node** head, int k)
{
	if(k == 0)
		return;

	Node* current = *head;

	int count = 1;
	while(count < k && current != NULL)
	{
		current = current->next;
		++count;
	}

	if(current == NULL)
		return;

	Node* kthNode = current;
	
	while(current->next != nullptr)
	{
		current = current->next;
	}

	current->next = *head;
	*head = kthNode->next;

	kthNode->next = nullptr;
} 

int main()
{
	Node* head = NULL;
	
	for(int i = 60; i > 0; i -= 10)
	{
		push(&head, i);
	}

	cout<<"Here is Linked list: ";
	print_list(head);

	cout<<"\nRotated List: ";
	rotate(&head, 4);
	print_list(head);	
	cout<<endl;
	return 0;
}	
