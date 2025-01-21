
 #include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
struct node *seg(struct node *head)
{
        if(head==NULL || head->next==NULL)
            return head;
        struct node *tmp,*pre,*add,*vmp;
        tmp=head;
        while(tmp->next!=NULL)
           tmp=tmp->next;
        add=tmp;
        pre=head;
        vmp=head;
        while(pre!=(tmp->next))
        {
                    if((pre->key)%2!=0)
                    {
                            if(pre==head)
                            {
                                    add->next=pre;
                                    add=pre;
                                    head=pre->next;
                                    pre->next=NULL;
                                    pre=head;
                                    vmp=pre;
                            }
                           else
                           {
                                    vmp->next=pre->next;
                                    add->next=pre;
                                    pre->next=NULL;
                                    add=pre;
                                    pre=vmp->next;
                           }
                    }
                    else
                    {
                            vmp=pre;
                            pre=pre->next;
                    }
        }
        printf("\n");
        tmp=head;
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
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
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    push(&head, 14);
    tmp=head;
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    tmp=seg(head);
     printf("\n");
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    return 0;
}
