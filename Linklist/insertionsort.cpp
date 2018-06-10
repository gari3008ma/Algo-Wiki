#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct node
{
  int data;
  struct node *next;   
};
void insrt(struct node **head_ref)
{
    if((*head_ref)==NULL ||(*head_ref)->next==NULL)
                return ;
     struct node *tmp=(*head_ref),*mp,*vr;
     vector<struct node *> a[100];
     int i=0,j=0,c,b,k;
     while(tmp!=NULL)
     {
              a[i]=tmp;
              tmp=tmp->next;
              i++;
     }
          tmp=(*head_ref);
          while(j<i)
          {
                  mp=a[j];
                  c=mp->data;
                  k=j-1;
                  if(k>=0)
                  {
                    mp=a[k];
                    b=mp->data;
                  }
                  while(k>=0 && (b >c))
                  {
                          a[k+1]=a[k];
                          k--;
                          if(k>=0)
                  {
                    mp=a[k];
                    b=mp->data;
                  }
                  
                  }
                    a[k]=a[j];
                    j++;
          }
          k=0;
          while(k<i)
          {
            tmp=a[k];
            cout<<tmp->data<<" \n";
          }
}     
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;  
    new_node->next = (*head_ref);      
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
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
  insrt(&head);
  printf("\n Reversed Linked list ");
  printList(head);           
  
  getchar();
}
