#include <bits/stdc++.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}
void deletenode(struct node **tmp,int v)
{
        struct node *vmp=*tmp,*prev=*tmp;
        int i=0;
        if(i==v)
        {
             (*tmp)=(vmp)->next;
             free(vmp);
             return;
        }
        while(vmp!=NULL && i!=v)
        {
               prev=vmp;
               vmp=vmp->next;
               i++;
        }
        if(vmp==NULL)
          return;
        prev->next=vmp->next;
        free(vmp);
        return ;
}
int main()
{
    struct node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    puts("Created Linked List: ");
    printList(head);
    deletenode(&head, 3);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}

