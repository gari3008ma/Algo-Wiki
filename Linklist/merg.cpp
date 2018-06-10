#include <stdio.h>
#include <stdlib.h>
 
// A linked list node
struct node
{
    int data;
    struct node *next;
};
 
/* Function to insert a node at the beginning */
void push(struct node ** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)  = new_node;
}
 
/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    /* Create following linked list
      1->2->3->4->5->6->7->8->9->10 */
    struct node* head = NULL;
    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("M = %d, N = %d \nGiven Linked list is :\n", M, N);
    printList(head);
 
    sortt(head);
 
    printf("\nLinked list after sorting is :\n");
    printList(head);
 
    return 0;
}
