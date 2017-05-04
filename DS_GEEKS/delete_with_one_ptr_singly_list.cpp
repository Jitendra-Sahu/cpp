//Given only a pointer/reference to a node to be deleted in a singly linked list, how do you delete it?

#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node* next;
		~node() { cout<<"DSTR....."<<endl; }
};

/*void push(node **head, int elem)
{
	node* temp = new node();
	temp->data = elem;
	temp->next = *head;
	*head = temp;
}*/

node* push(node *head, int elem)
{
	node* temp = new node();
	temp->data = elem;
	temp->next = head;
	head = temp;

	return head;
}

void print_list(node *head)
{
	node *temp = head;
	while(temp != nullptr)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

//void del_list(node **head)
void del_list(node *head)
{
	//When head as recieved as single star, all the changes happened here on local variable, so code need to overwrite the data value & data address for complete swap/delete. Where as if you pass head as double pointer the address of head will pass, so address overwrite will take care of data value swap also & changes reflect to original location also.

	node *temp = head->next;
	head->data = temp->data;
	head->next = temp->next;
	delete temp;

	/*node* temp = head;
	head = head->next;
	delete temp;
	print_list(head);*/

	/*node* temp = *head;
	cout<<"head address: "<<*head<<endl;
	cout<<"temp address: "<<temp<<endl;
	*head = temp->next;
	//(*head)->data = temp->next->data;
	delete temp;*/
}

int main()
{
	node *head = nullptr;
	head = push(head, 1);
	head = push(head, 4);
	head = push(head, 12);
	head = push(head, 6);

	cout<<"List on as new entry: ";
	print_list(head);

	cout<<"\n";
	//del_list(&head);
	del_list(head);
	cout<<"List after delete first node: ";
        print_list(head);

	//cout<<"\n";
	
	return 0;
}
