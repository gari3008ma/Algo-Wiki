#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
void sortlist(struct node *head)
{
    int a=0,b=0,c=0;
    struct node *tmp=head,*pre;
    while(tmp!=NULL)
    {
        if(tmp->data==0)
        a++;
        else if(tmp->data==1)
        b++;
        else if(tmp->data==2)
        c++;
        tmp=tmp->next;
    }
    tmp=head;
    while(tmp!=NULL)
    {
              if(a>0)
              {
                  tmp->data=0;
                  a--;
                  tmp=tmp->next;
                  continue;
              }
              else if(b>0)
              {
                  tmp->data=1;
                  b--;
                  tmp=tmp->next;
                  continue;
              }
              else if(c>0)
              {
                    tmp->data=2;
                    c--;
                    tmp=tmp->next;
                    continue;
              }
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
    struct node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
 
    printf("Linked List Before Sorting\n");
    printList(head);
 
    sortlist(head);
 
    printf("Linked List After Sorting\n");
    printList(head);
 return 0;
}