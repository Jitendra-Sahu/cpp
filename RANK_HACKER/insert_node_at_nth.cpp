//Insert Node at nth position in a linked list

#include<iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node* next;
};

Node* InsertNth(Node* head, int new_data, int position)
{
	Node* ToBeInserted = new Node();
	ToBeInserted->data = new_data;
	ToBeInserted->next = nullptr;

	if(head == NULL)
	{
		return (head = ToBeInserted);
	}
	if(position == 0)
	{
		ToBeInserted->next = head;
		head = ToBeInserted;
		return head;
	}
		
	Node* traverse = head;

	//while((position-2) > 0)
	for(int i=0; i < position-2; ++i)
	{
		traverse = traverse->next;
	//	position--;
	}
				
	ToBeInserted->next = traverse->next;
	traverse->next = ToBeInserted;
				
	return head;
}

void print_list(Node* head)
{
	while(head != nullptr)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main()
{
	Node* head = nullptr;
	head = InsertNth(head, 3, 0);
	head = InsertNth(head, 5, 1);
	head = InsertNth(head, 4, 2);
	head = InsertNth(head, 2, 4);
	head = InsertNth(head, 10, 1);

	cout<<"List element:";
	print_list(head);

	return 0;
}
