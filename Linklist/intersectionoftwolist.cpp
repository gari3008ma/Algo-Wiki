#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
struct node *intersect(struct node *head,struct node *head1)
{
       struct node *head3,*pre;
       int f=0;
       while(head && head1)
       {
             if(head->key > head1->key)
            {
                head1=head1->next;
            }
              else if(head1->key > head->key)
            {
                head=head->next;
            }
            else
            {
                 struct node *tmp=(struct node *)malloc(sizeof(struct node));
                 tmp->key=head->key;
                 tmp->next=NULL;
                 if(f==0)
                 {
                        head3=tmp;
                        pre=tmp;
                        f=1;
                 }
                 else
                 {
                        pre->next=tmp;
                        pre=tmp;
                 }
            }
       }
       return head3;
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
    struct node* a = NULL;
  struct node* b = NULL;
  push(&a, 6);
  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);
  push(&b, 8);
  push(&b, 6);
  push(&b, 4);
  push(&b, 2);
    tmp=a;
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    tmp=intersect(a,b);
     printf("\n");
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    return 0;
}
