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
int nthnode(struct node *head,int n,int i)
{
         if(head==NULL)
             return 0;
          if(i==n)
                return head->key;
          i++;
          int v=nthnode(head->next,n,i);
          return v;
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

    printf("\n%d",nthnode(head,5,0));
    return 0;
}
