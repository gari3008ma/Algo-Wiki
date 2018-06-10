#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
  struct node *prev;    
};
void clone(struct node **head_ref)
{
     
}     
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->prev = NULL;
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
 
    /* change prev of head node to new node */
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;    
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
} 
 
/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct node* head = NULL;
  push(&head, 2);
  push(&head, 4);
  push(&head, 8);
  push(&head, 10);
  
  printf("\n Original Linked list ");
  printList(head);
  
  /* Reverse doubly linked list */
  clone(&head);
  
  printf("\n Reversed Linked list ");
  printList(head);           
  
  getchar();
}
