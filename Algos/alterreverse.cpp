 #include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node *next;
};
void push(struct node** head_ref, int new_key)
{
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->key  = new_key;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
    printf("%d",(*head_ref)->key);
    return ;
}
void alternate(struct node *head,struct node ** head1,struct node ** head2)
{
       if(head==NULL)
          return ;
       while(head !=NULL)
       {
                    push(head1,head->key);
                    printf("%d",(*head1)->key);
                    head=head->next;
                    if(head!=NULL)
                    push(head2,head->key);
                    head=head->next;
       }

       return;
}
int main()
{
   printf("hello");
    struct node *head = NULL,*tmp,*head1=NULL,*head2=NULL;
    printf("hello");
    struct node **m=&head1;
    struct node **p=&head2;
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    push(&head, 14);
     tmp=head;
     printf("%d",head1->key);
    while(head1!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    alternate(head,m,p);
     tmp=head1;
     printf("%d",head1->key);
    while(head1!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    printf("\n");
    tmp=head2;
    while(head2!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    return 0;
}

