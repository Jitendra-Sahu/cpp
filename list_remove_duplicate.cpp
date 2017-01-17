//Remove duplicates from a sorted linked list

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

void delete_node(node* del_node)
{
	node* temp = del_node->next;
	del_node->data = temp->data;
	del_node->next = temp->next;
	delete temp;
}

void remove_duplicates(node* head)
{
	node* current = head;
	while(current->next != nullptr)
	{
		if(current->data == current->next->data)
		{
			delete_node(current);
		}
		else
		{
			current = current->next;
		}
	}
}

/*
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
  Node* current = head;
  while(head->next != nullptr)
  {
      if(head->data == head->next->data)
      {
          head->next = head->next->next;
      }
      else
      {
          head = head->next;
      }
  }
  return current;
}*/

int main()
{
	node* head = nullptr;
	push(&head, 60);
	push(&head, 43);
	push(&head, 43);
	push(&head, 38);
	push(&head, 38);
	push(&head, 38);
	push(&head, 21);
	push(&head, 11);
	push(&head, 11);
	push(&head, 11);

	cout<<"List has duplicate values:";
	print_list(head);

	remove_duplicates(head);
	cout<<"After remove duplicate values:";
        print_list(head);

	return 0;
}
