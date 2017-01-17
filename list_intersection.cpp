//Write a function to get the intersection point of two Linked Lists

#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node* next;
};

int getCount(node* head)
{
	int count = 0;
	while(head != nullptr)
	{
		head = head->next;
		++count;
	}
	return count;
}

int _getIntersectionNode(int d, node* node1, node* node2)
{
	int i;
	node* current1 = node1;
	node* current2 = node2;

	for(i = 0; i < d; ++i)
	{
		if(current1 == NULL)
		{
			return -1;
		}
		current1 = current1->next;
	}
	while(current1 != NULL && current2 != NULL)
	{
		if(current1 == current2)
		{
			return current1->data;
		}
		current1 = current1->next;
		current2 = current2->next;
	}
	return -1;
}
int getIntersectionNode(node* head1, node* head2)
{
	int c1 = getCount(head1);
	int c2 = getCount(head2);
	int d;

	if(c1 > c2)
	{
		d = c1 - c2;
		return _getIntersectionNode(d, head1, head2);
	}
	else
	{
		d = c2 - c1;
		return _getIntersectionNode(d, head2, head1);
	}
}	

int main()
{
	node* newNode;
	node* head1 = new node();
	head1->data = 10;
	
	node* head2 = new node();
	head2->data = 3;

	newNode = new node();
	newNode->data = 6;
	head2->next = newNode;

	newNode = new node();
	newNode->data = 9;
        head2->next->next = newNode;

	newNode = new node();
        newNode->data = 15;
	head1->next = newNode;
        head2->next->next->next = newNode;

	newNode = new node();
	newNode->data = 30;
	head1->next->next = newNode;
	head1->next->next->next = NULL;

	int inter_data = getIntersectionNode(head1, head2);
	cout<<"Intersection Node:"<<inter_data<<endl;

	return 0;
}
