#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
struct node *miniverse(struct node *first,struct node *last)
{
            if(first->next==last || first->next==NULL)
              return first;
              cout<<"$ "<<first->key<<"\n";
        struct node *tmp=miniverse(first->next,last);
        first->next->next=first;
        first->next=last->next;
        cout<<first->key<<"\n";
        return first;
}
struct node *duplicatel(struct node *head,int k)
{
       if(head==NULL)
          return head;
           struct node *pre,*last;
      int flag=1;
      struct node *tmp=head;
      pre=tmp;
                int i =k-1;
                while(i-- && tmp->next!=NULL)
                      {
                      cout<<" ->"<<tmp->key<<" \n";
                       tmp=tmp->next;
                      }
                        last=tmp;
                        head=last;
             tmp=miniverse(pre,last);
             if(tmp)
             tmp=tmp->next;
       while(tmp!=NULL)
       {
               pre=tmp;
                i =k-1;
                while(i-- && tmp->next!=NULL)
                        tmp=tmp->next;
                        last=tmp;
             tmp=miniverse(pre,last);
             if(tmp)
             tmp=tmp->next;
       }
}
void push(struct node** head_ref, int new_key)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->key  = new_key;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
int main()
{
    struct node* head = NULL,*tmp;
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    push(&head, 14);
    tmp=head;

    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    tmp=duplicatel(head,3);
     printf("\n");
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    return 0;
}


