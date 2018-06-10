#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct node
{
  int data;
  struct node *next;   
};
void sortu(struct node ** head_ref,struct node *tmp)
{
           if((*head_ref)==NULL ||((*head_ref)->data >tmp->data))
                {
                            tmp->next=(*head_ref);
                            (*head_ref)=tmp;
                }
            else
            {
                    struct node *current=(*head_ref)->next;
                    struct node *pre=(*head_ref);
                    while(current!=NULL && (current->data<tmp->data))
                        {
                                pre=current;
                                current=current->next;
                        }
                        pre->next=tmp;
                        tmp->next=current;
            }    
}
void insrt(struct node **head_ref)
{
                if((*head_ref)==NULL ||(*head_ref)->next==NULL)
                     return ;
                  struct node *tmp=(*head_ref),*newhead=NULL,*next;
                  while(tmp!=NULL)
                  {
                    next=tmp->next;
                    sortu(&newhead,tmp);
                    tmp=next;
                  } 
                  (*head_ref)=newhead;
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
  printf("\n sorted Linked list ");
  printList(head);           
  
  getchar();
}
