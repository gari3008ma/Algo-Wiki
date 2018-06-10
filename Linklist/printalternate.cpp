#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
void alternate(struct node *head)
{
       if(head==NULL)
          return ;
          cout<<head->key<<" ";
          if(head->next!=NULL)
       alternate(head->next->next);
          cout<<head->key<<" ";
       return;
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
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    tmp=head;
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    cout<<"\n";
    alternate(head);

    return 0;
}

