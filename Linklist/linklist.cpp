#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void deletenode(struct node **head,int v)
{
      struct node *tmp=*head;
      while(tmp!=NULL)
      {
            if(tmp->data=v)
               {

               }
               tmp=tmp->next;
      }
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    puts("Created Linked List: ");
    printList(head);
    deletenode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}
Run on IDE
