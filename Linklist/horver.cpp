 #include <iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;
struct node
{
    int x,y;
    struct node *next;
};
struct node *midd(struct node *head)
{
           if(head==NULL || head->next==NULL ||head->next->next==NULL)
                            return head;
                struct node *tmp=head,*fe,*pre=head;
                int a=tmp->x,b=tmp->y;
                tmp=head->next;
                return head;
}
void push(struct node** head_ref, int new_data,int b)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->x  = new_data;
     new_node->y  = b;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d %d ->", node->x,node->y);
        node = node->next;
    }
}
int main()
{
    struct node *start = NULL;
    push(&start, 0,10);
    push(&start, 1,10);
    push(&start, 5,10);
    push(&start, 7,10);
    push(&start, 7,5);
    push(&start, 20,5);
    push(&start, 40,5);
    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);
    start=midd(start);
    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);
    getchar();
    return 0;
}
