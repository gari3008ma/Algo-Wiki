 #include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
void duplicatedel(struct node *head)
{
       struct node *tmp=head,*pre1,*pre;
       int i;
       while(tmp!=NULL)
       {
              i = tmp->key;
              pre1=tmp;
              pre=tmp->next;
              while(pre->key!=i && pre!=NULL)
                   {
                       pre1=pre;
                       pre=pre->next;
                   }
                   if(pre!=NULL)
              {

                    pre1->next=pre->next;
                   free(pre);
              }
              tmp=tmp->next;
       }
       return;
}
void push(struct node** head_ref, int new_key)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->key  = new_key;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
int main()
{
    struct node* head = NULL,*tmp;
    push(&head, 10);
    push(&head, 30);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    push(&head,14);
    tmp=head;
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    duplicatedel(head);
     tmp=head;
     printf("\n");
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    return 0;
}

