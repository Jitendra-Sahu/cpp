//Pairwise swap elements of a given linked list by changing links

#include<iostream>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
};


void push(Node** head_ref, int data)
{
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = *head_ref;
	*head_ref = temp1;	
}

void display(Node* head_ref)
{
	Node* temp = head_ref;
	while(temp != NULL)
	{
		cout<<" "<<temp->data;
		temp = temp->next;
	}
	cout<<endl;
}

void pairwiseSwap(Node** head_ref)
{
	if(*head_ref == NULL || (*head_ref)->next == NULL)
		return;

	Node* prev = *head_ref;
	Node* curr = (*head_ref)->next;

	*head_ref = curr;

	while(true)
	{
		Node* next = curr->next;
		curr->next = prev;

		if(next == NULL || next->next == NULL)
		{
			prev->next = next;
			break;
		}
		prev->next = next->next;
	
		prev = next;
		curr = prev->next;
	}
}
		
int main()
{

	cout<<"\n Created list\n";
	cout<<"================\n";
	Node* head = NULL;
	push(&head,3);
	push(&head,2);
	push(&head,7);
	push(&head,5);
	push(&head,9);
	push(&head,1);

	display(head);
	pairwiseSwap(&head);
	display(head);

	return 0;
}	
