#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node* next;
};

void insert(node** head, int data)
{
	node* new_node = new node();
	new_node->data = data;
	new_node->next = nullptr;

	if(*head == nullptr)
	{
		*head = new_node;
	}
	else
	{	
		node* last_node = new node();
		last_node = *head;
		while(last_node->next != nullptr)
			last_node = last_node->next;

		last_node->next = new_node;
	}
}

void display(node* head)
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
	node* head = nullptr;
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 1);

	display(head);

	return 0;
}

/*
int main()
{
int i,j,rows;
    printf("Enter the number of rows: ");
    scanf("%d",&rows);
    for(i=1;i<=rows;++i)
    {
        for(j=1;j<=i;++j)
        {
           printf("* ");
        }
        printf("\n");
    }
return 0;
}*/
