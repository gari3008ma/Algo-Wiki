 #include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
struct node *bigdel(struct node *head)
{
                 struct node *tmp=head,*pre;
                 int flag=0;
                 while(tmp!=NULL)
                 {
                        pre=tmp->next;
                        flag=0;
                        while(pre!=NULL)
                        {
                               if(pre->key   > tmp->key)
                               {
                                       flag=1;
                                       pre=tmp;
                                       tmp=tmp->next;
                                       if(head==pre)
                                       head=tmp;
                                       free(pre);
                                       break;
                               }
                               pre=pre->next;
                        }

                        if(flag==0 && tmp!=NULL)
                        tmp=tmp->next;
                 }
                 return head;
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
    tmp=bigdel(head);
     printf("\n");
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    return 0;
}


