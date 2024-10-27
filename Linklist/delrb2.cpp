 #include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
struct node *revers(struct node *head)
{
                if(head==NULL || head->next==NULL)
                             return head;
       struct node *tmp=revers(head->next);
       head->next->next=head;
       head->next=NULL;
                    return tmp;
}
struct node *bigdel(struct node *head)
{
               if(head==NULL || head->next==NULL)
                   return head;
                struct node *tmp,*pre,*u;
            head=revers(head);
            tmp=head,pre=head;
                    while(tmp!=NULL  && tmp->next!=NULL)
                    {
                            if(tmp->key < pre->key)
                            {
                                 u = tmp->next;
                                 tmp->next = pre->next;
                                 free(pre);
                            }
                            else
                            {
                                tmp=tmp->next;
                                pre=tmp;
                            }
                    }
                    printf("\n");
                    head=revers(head);
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



