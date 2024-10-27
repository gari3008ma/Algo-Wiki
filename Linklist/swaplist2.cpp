 #include <iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *pairswap(struct node *head)
{
    if(head==NULL || head->next==NULL)
                return head;
    struct node *pre=head,*cur=head->next,*tmp,*node;
             head=cur;

                tmp=cur->next;
                 cur->next=pre;
                 pre->next=tmp;
                 cur=pre->next;
    while(cur!=NULL && cur->next!=NULL)
    {
                 tmp=cur->next->next;
                 cur->next->next=cur;
                 pre->next=cur->next;
                 cur->next=tmp;
                 pre=cur;
                 cur=pre->next;
    }
    node=head;
    printf("\n");
     while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    return head;
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node *start = NULL;
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);
    start=pairswap(start);
    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);
    getchar();
    return 0;
}