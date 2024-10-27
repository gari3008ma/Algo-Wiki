#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
void push(struct node** head_ref, int new_key)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->key  = new_key;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void moveu(struct node **head,struct node **head_ref)
{
        struct node *tmp=*head_ref;
        if(tmp==NULL)
        {
                   *head_ref=*head;
                   *head=(*head)->next;
                   (*head_ref)->next=NULL;
        }
        else
        {
                   while(tmp->next!=NULL)
                   {
                            tmp=tmp->next;
                   }
                   tmp->next=*head;
                   *head=(*head)->next;
                   tmp=tmp->next;
                   tmp->next=NULL;
        }
}
void nth(struct node **head,struct node **head1,struct node **head2)
{
             if(*head==NULL)
                 return;
                 while(*head)
                 {
                                moveu(head,head1);
                                if((*head)!=NULL)
                                    moveu(head,head2);
                 }
}
int main()
{
    struct node* head = NULL,**head1,**head2,*tmp;
    *head1=NULL;
    *head2=NULL;
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    tmp=head;
    while(tmp!=NULL)
{
     printf("%d ",tmp->key);
     tmp=tmp->next;
     }
     nth(&head,head1,head2);


    return 0;
}

