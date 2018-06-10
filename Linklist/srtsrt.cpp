#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node*rev(struct node *head)
{
    if(head==NULL || head->next==NULL)
        return head;
            struct node *tmp=rev(head->next);
            head->next->next=head;
            head->next=head;
            return tmp;
}
struct node *sortu(struct node *head)
{
    if(head==NULL || head->next==NULL)
      return head;
      head=rev(head);
      struct node *tmp=head,*pre;
        vector<struct node *>a;
      while(tmp!=NULL)
      {
        if(tmp->data <0)
            {
                a.push_back(tmp);
                pre=tmp->next;
                free(tmp);
               tmp=pre;
            }
            else
                tmp=tmp->next;
      }
      //printList(head);
        head=rev(head);
        vector<struct node *> :: iterator it = a.begin();
        
       return head;
}
struct node *sort1(struct node *head)
{
    if(head==NULL || head->next==NULL)
      return head;
  struct node *tmp=head,*pre=head,*cur=head->next;
   while(cur!=NULL)
   {
            if(pre->data >cur->data)
            {
                pre->next=cur->next;
                cur->next=head;
                head=cur;
            }
            pre=cur;
            cur=pre->next;
   }
   return head;
}
void push(struct node ** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
     new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}
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
    push(&head, -10);
    push(&head, -9);
    push(&head, 8);
    push(&head, 7);
    push(&head, -6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf(" \nGiven Linked list is :\n");
    printList(head);
 
    head=sort1(head);
 
    printf("\nLinked list after sorting is :\n");
    printList(head);
 
    return 0;
}
