#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node *revers(struct node *root)
{
          if(root==NULL||root->next==NULL)
            return root;
            struct node *tmp=revers(root->next);
           root->next->next=root;
           root->next=NULL;
            return  tmp;
         //cout<<pre->data<<" "<<root->data<<"\n";
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
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node* res = NULL;
    struct node* a = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
     printList(a);
    res=revers(a);

    printf(" Linked List is: \n");
    printList(res);

    return 0;
}

