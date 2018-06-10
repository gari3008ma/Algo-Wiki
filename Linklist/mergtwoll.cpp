#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
void bifar(struct node **head1,struct node **head2)
{
    
    struct node *tmp=(*head1),*re;
    while(tmp!=NULL)
    {
                re=tmp->next;
                if((*head2)!=NULL)
               { 
                 tmp->next=(*head2);
                (*head2)=(*head2)->next;
                tmp->next->next=re;
                }
                if(tmp->next!=NULL)
                tmp=tmp->next->next;
    }
}
void push (struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
/* Drier program to test above function*/
int main(void)
{
    struct node *head1 = NULL,*head2=NULL;
    push(&head1, 10);
    push(&head1, 11);
    push(&head1, 20);
    push(&head1, 24);
    push(&head2, 12);
    push(&head2, 113);
    push(&head2, 24);
    push(&head2, 18);
    push(&head2, 29);
 
    printf("Linked List Before change\n");
    printList(head1);
    printList(head2);
    bifar(&head1,&head2);
    printf("Linked List After change\n");
    printList(head1);
    printList(head2);
 return 0;
}