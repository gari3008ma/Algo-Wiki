#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
int searchu(struct node *head1,struct node *head2)
{
              map<struct node*,bool> a;
              struct node *tmp;
              tmp=head1;
              while(tmp!=NULL)
              {
                     a[tmp]=true;
                     tmp=tmp->next;
              }
              tmp=head2;
              while(tmp!=NULL)
              {
                   if(a[tmp]==true)
                   {
                         int p=tmp->data;
                          return p;
                     }
                     tmp=tmp->next;
              }
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
    struct node* head = NULL;
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

    cout<<searchu(head1, head2);
    cout<<"\n";
    return 0;
}

