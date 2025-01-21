 #include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node *intersect(struct node *head,struct node *head1)
{
       struct node *head3,*pre;
       struct node dummy;
       head3=&dummy;
       dummy.next=NULL;
       while(head && head1)
       {
             if(head->data > head1->data)
            {
                head1=head1->next;
            }
              else if(head1->data > head->data)
            {
                head=head->next;
            }
            else
            {
                 struct node *tmp=(struct node *)malloc(sizeof(struct node));
                 tmp->data=head->data;
                 tmp->next=NULL;
                 head3->next=tmp;
                 head3=tmp;
                 head=head->next;
                 head1=head1->next;
            }
       }
       return dummy.next;
}
void push(struct node** head_ref, int new_key)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_key;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
int main()
{
    struct node* head = NULL,*head3;
    int i;
    struct node* newNode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;

  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;

  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;

  head1->next->next->next = NULL;

 head3=head1;
 while(head3!=NULL)
    {
         printf("%d ",head3->data);
         head3=head3->next;
    }
    head3=head2;
     printf("\n");
      while(head3!=NULL)
    {
         printf("%d ",head3->data);
         head3=head3->next;
    }
     printf("\n");
     head3=intersect(head1,head2);
    while(head3!=NULL)
    {
         printf("%d ",head3->data);
         head3=head3->next;
    }

    return 0;
}
