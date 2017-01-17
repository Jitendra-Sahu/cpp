#include<iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node* next;
};

void removeLoop(Node* loop_node, Node* head)
{
	Node* ptr1 = loop_node;
	Node* ptr2 = loop_node;

	unsigned int k=1, i;
	while(ptr1->next != ptr2)
	{
		ptr1 = ptr1->next;
		++k;
	}

	ptr1 = head;
	ptr2 = head;
	
	for(i = 0; i < k; ++i)
		ptr2 = ptr2->next;

	while(ptr2 != ptr1)
	{
		ptr2 = ptr2->next;
		ptr1 = ptr1->next;
	}
	cout<<"\nptr1 data:"<<ptr1->data;
	cout<<"\nptr2 data:"<<ptr2->data;

	ptr2 = ptr2->next;
	while(ptr2->next != ptr1)
		ptr2 = ptr2->next;

	cout<<"\nptr2 data:"<<ptr2->data<<endl;
	ptr2->next = NULL;
}

int detectAndRemoveLoop(Node* head)
{
	Node* slow_p = head;
	Node* fast_p = head;

	while(slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		if(slow_p == fast_p)
		{
			cout<<"Loop detected:"<<slow_p->data<<endl;
			removeLoop(slow_p, head);
			return 1;
		}
	}
	return 0;
}

Node* newNode(int key)
{
	Node* temp = new Node();
	temp->data = key;
	temp->next = nullptr;

	return temp;
}

void print_list(Node* head)
{
	Node* temp = head;
	while(temp != nullptr)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int main()
{
	Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);

	/*Creating loop for testing*/
	head->next->next->next->next->next = head->next->next;

	detectAndRemoveLoop(head);

	cout<<"Linked List after remove the loop:";
	print_list(head);

	cout<<endl;
	return 0;
}

