//Given a linked list which is sorted, how will you insert in sorted way

#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
class node
{
    public:
    int data;
    node* next;
};
 
/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
void sortedInsert(node** head_ref, node* new_node)
{
    node* current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
 
/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST sortedInsert */
 
/* A utility function to create a new node */
node *newNode(int new_data)
{
    /* allocate node */
    node* new_node =
        (node*) malloc(sizeof(node));
 
    /* put in the data  */
    new_node->data  = new_data;
    new_node->next =  NULL;
 
    return new_node;
}
 
/* Function to print linked list */
void printList(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
 
/* Drier program to test count function*/
int main()
{
    /* Start with the empty list */
    node* head = NULL;
    node *new_node = newNode(5);
    sortedInsert(&head, new_node);
    new_node = newNode(10);
    sortedInsert(&head, new_node);
    new_node = newNode(7);
    sortedInsert(&head, new_node);
    new_node = newNode(3);
    sortedInsert(&head, new_node);
    new_node = newNode(1);
    sortedInsert(&head, new_node);
    new_node = newNode(9);
    sortedInsert(&head, new_node);
    printf("\n Created Linked List\n");
    printList(head);
 
    return 0;
}
