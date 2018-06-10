#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *del(struct node *head)
{
    if(head==NULL)
       return head;
    struct node *tmp=head->next,*pre=head;
    if(tmp!=NULL && tmp->data > pre->data)
      {
          free(pre);
          head=tmp;
          pre=tmp;
          tmp=tmp->next;
      }
      while(tmp!=NULL)
      {
                 if(tmp->data > pre->data)
      {
          free(pre);
      }
          pre=tmp;
          tmp=pre->next;
      }
      return head;
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
    int count = 0;
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
        count++;
    }
}
int main(void)
{
    struct node* head = NULL;
    for(int i = 20; i > 0; i--)
      push(&head, i);

     printf("\n Given linked list \n");
     printList(head);
     head = del(head);

     printf("\n Modified Linked list \n");
     printList(head);

     getchar();
     return(0);
}
