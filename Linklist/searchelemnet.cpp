 #include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
bool searchu(struct node * head,int v)
{
    if(head==NULL)
        return false;
    if(head->key==v)
        return true;
    return searchu(head->next,v)  ;
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
    struct node* head = NULL;
    int x = 21;
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    searchu(head, 21)? printf("Yes") : printf("No");
    return 0;
}
