#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
void moveu(struct node ** head)
{
    struct node *tmp=*head,*pre=*head;
    if((*head)==NULL || (*head)->next==NULL)
           return;
    while(tmp->next!=NULL)
    {
                pre=tmp;
                tmp=tmp->next;
    }
    pre->next=NULL;
    tmp->next=*head;
    *head=tmp;
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
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
     tmp=head;
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    cout<<"\n";
    moveu(&head);
    tmp=head;
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    return 0;
}

