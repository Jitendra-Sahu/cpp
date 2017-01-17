//Delete last occurrence of an item from linked list

#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node* next;
};

node* newNode(int elem)
{
	node* temp = new node();
	temp->data = elem;
	temp->next = nullptr;
	return temp;
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

void deleteLast(node* head, int del_elem)
{
	node* temp = head->next;
	while(temp != nullptr)
	{
		if(temp->data == del_elem)
			break;
		else
			temp = temp->next;
	}
	
	node* del_node = temp->next;
	temp->next = del_node->next;
	delete del_node;
}

void deleteLast_1(node** head, int key)
{
	node* x = nullptr;
	node* temp = *head;

	while(temp)
	{
		if(temp->next && temp->next->data == key)
		{
			x = temp;
		}
		temp = temp->next;
	}

	if(x)
	{
		temp = x->next;
		x->next = x->next->next;
		delete temp;
	}
	else
	{
		if(*head && (*head)->data == key)
		{
			node* temp = *head;
			*head = (*head)->next;
			delete temp;
		}
	}
}

int main()
{
	node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(5);
	head->next->next->next->next = newNode(2);
	head->next->next->next->next->next = newNode(10);

	cout<<"Created Linked List: ";
	print_list(head);
	//deleteLast(head, 2);
	deleteLast_1(&head, 2);
	cout<<"Linked List after Deletion of 2: ";
	print_list(head);

	return 0;
} 
