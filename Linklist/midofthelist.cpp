#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
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
int midnode(struct node *head)
{
        struct node *slow=head;
        struct node *fast=head;
        while(slow!=NULL || fast!=NULL)
        {
               slow=slow->next;
               fast=fast->next->next;
        }
        return slow->data;
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
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
    cout<<midnode(head)<<"\n";
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}
