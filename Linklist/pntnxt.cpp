#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct node
{
  int data;
  struct node *next; 
  struct node *nextt;  
};
void insrt(struct node *head_ref)
{
                if((head_ref)==NULL ||(head_ref)->next==NULL)
                     return ;
                  struct node *tmp=(head_ref),*vmp;
                  int a[100],i=0,j;
                  while(tmp!=NULL)
                  {
                       a[i]=tmp->data;
                       i++;
                       tmp=tmp->next;
                  } 
                  sort(a,a+i);
                  tmp=head_ref;
                  while(tmp!=NULL)
                 {
                       
                      for(j=0;j<i;j++)
                  {
                          if(tmp->data ==a[j] &&j<=(i-2))
                              {
                                j=j+1;
                                vmp=head_ref;
                                while(vmp!=NULL)
                                  {
                                        if(a[j]==vmp->data)
                                                break;
                                        vmp=vmp->next;
                                  } 
                                   tmp->nextt=vmp;
                                   break;
                              }
                  }
                  
                  tmp=tmp->next;
              }
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data; 
     new_node->nextt=NULL;
    new_node->next = (*head_ref);      
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   if(node->nextt!=NULL)
   { printf("->%d \n", node->nextt->data);
}
   node = node->next;
  }
} 
int main()
{
  /* Start with the empty list */
  struct node* head = NULL;
  push(&head, 2);
  push(&head, 4);
  push(&head, 8);
  push(&head, 10);
  
  printf("\n Original Linked list ");
  printList(head);
  insrt(head);
  printf("\n changed Linked list ");
  printList(head);           
  
  getchar();
}
