#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node *next;
};
void first(struct node **head,int v)
{
            if(head==NULL)
                return ;
            struct node *tmp=(struct node *)malloc(sizeof(struct node));
            tmp->data=v;
            tmp->next=*head;
            *head=tmp;
            return ;
}
void last(struct node **head,int v)
{
            struct node *jmp;
            if(*head==NULL)
                {
                struct node *tmp=(struct node *)malloc(sizeof(struct node));
            tmp->data=v;
            tmp->next=NULL;
            *head=tmp;
                return;
                }
            struct node *tmp=(struct node *)malloc(sizeof(struct node));
            tmp->data=v;
            tmp->next=NULL;
            jmp=*head;
            while(jmp->next!=NULL)
            jmp=jmp->next;
            jmp->next=tmp;
            return;
}
void insertatpos(struct node *vmp,int v)
{
          struct node *tmp=(struct node *)malloc(sizeof(struct node));
            tmp->data=v;
            tmp->next=vmp->next;
            vmp=tmp;
            return;
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
  last(&head, 6);
  first(&head, 7);
  first(&head, 1);
  last(&head, 4);
  insertatpos(head->next, 8);
  printf("\n Created Linked list is: ");
  printList(head);

  return 0;
}
