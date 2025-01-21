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
int midu(struct node *head)
{
               struct node  *slowptr=head,*fastptr=head;
               if(head==NULL)
                return -1;
                while(fastptr!=NULL && fastptr->next!=NULL)
                {
                      slowptr=slowptr->next;
                      fastptr=fastptr->next->next;
                }
                return slowptr->key;
}
int main()
{
    struct node* head = NULL,*tmp;
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
     printf("\n[%d]",midu(head));


    return 0;
}


