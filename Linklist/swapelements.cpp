#include<bits/stdc++.h>
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
struct node *fundu(struct node *head,int x)
{
           struct node*tmp=NULL;
           while(head!=NULL)
           {
               if(x==head->key)
                  {
                      return tmp;
                  }
                  tmp=head;
                  head=head->next;
           }
           return NULL;
}
void swapu(struct node **head,int a,int b)
{
                struct node *prevx=NULL,*prevy=NULL,*x=NULL,*y=NULL,*tmp;
                if(a==b)
                 return ;
                if(((*head)->key==a) || ((*head)->key==b))
                {
                      if((*head)->key==a)
                       prevy=fundu(*head,b);
                      else
                       prevy=fundu(*head,a);
                        y=prevy->next;
                        x=*head;
                       prevy->next=x;
                        tmp=x->next;
                        x->next=y->next;
                          y->next=tmp;
                          *head=y;
                          return ;
                }
                prevx=fundu(*head,a);
                prevy=fundu(*head,b);
                 y=prevy->next;
                 x=prevx->next;
                 prevx->next=y;
                 prevy->next=x;
                 tmp=x->next;
                 x->next=y->next;
                 y->next=tmp;
                return ;
}
int main()
{
    struct node* head = NULL,*tmp;
    int x = 21;
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
     printf("\n");
    swapu(&head,10,14);
    tmp=head;
    while(tmp!=NULL)
{
     printf("%d ",tmp->key);
     tmp=tmp->next;
     }
    return 0;
}


