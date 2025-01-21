 #include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
int len(struct node * head)
{
   int c=0;
   while(head!=NULL)
   {
       head=head->next;
       c++;
   }
   return c;
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
    int x = 21;
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    printf("%d",len(head));
    tmp=head;
    while(tmp!=NULL)
   {
       printf("%d  ",tmp->key);
       tmp=tmp->next;
   }
    return 0;
}

