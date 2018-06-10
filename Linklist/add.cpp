#include <stdio.h>
#include <stdlib.h>
 
// A linked list node
struct node
{
    int data;
    struct node *next;
};
int add1(struct node * head)
{
          if(head==NULL)
                return 1;
            int carry = add1(head->next);
            int sum = head->data +carry ;
            head->data = sum %10;
            carry = sum/10;
            return carry ;
}
struct node *addone1(struct node *head)
{
                            int carry =add1(head);
                            if(carry)
                            {
                                            struct node *v = (struct node *)malloc(sizeof(struct node));
                                            v->data = carry;
                                            v->next = head;
                                            head= v;
                            }
                            return head;
}
struct node *revers(struct node *head)
{
                   if(head==NULL || head->next==NULL)
                       return head;
            struct node *tmp=revers(head->next);
            head->next->next=head;
            head->next=NULL;
            return tmp;
}
struct node *addone(struct node *head)
{
        int carry = 1,sum=0;
        head = revers(head);
        struct node *tmp = head;
        while(tmp->next!=NULL)
        {
                    sum = tmp->data + carry;
                    tmp->data = sum%10;
                    //printf(" %d -> %d",tmp->data,sum);
                    carry = sum/10;
                    tmp = tmp->next;

        }
        printf("\n");
                    sum = tmp->data + carry;
                    tmp->data = sum%10;
                    carry = sum/10;
                    if(carry)
                    {
                                            struct node *v = (struct node *)malloc(sizeof(struct node));
                                            v->data = carry;
                                            v->next = NULL;
                                            tmp->next = v;
                    }
                    head=revers(head);
                    return head;
}
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
    
    struct node* head = NULL;
    push(&head, 9);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);
   head= addone1(head);
    printf("\nLinked list after addition is :\n");
    printList(head);
 
    return 0;
}