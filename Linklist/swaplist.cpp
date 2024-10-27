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
    struct node *tmp=head,*re;
    re=tmp->next->next;
    tmp->next->next=tmp;
    head=tmp->next;
    tmp->next=re;
    tmp=tmp->next;
    while(tmp->next!=NULL)
    {
                re=tmp->next->next;
                tmp->next->next=tmp;
                tmp->next=re;
                tmp=tmp->next;
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
 
/* Druver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);
    head=pairswap(start);
    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);
    getchar();
    return 0;
}