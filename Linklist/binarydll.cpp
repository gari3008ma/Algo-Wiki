#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void doublelist(struct node *root,struct node **head)
{
            if(root==NULL)
                return;
       struct node *pre=NULL;
       doublelist(root->left,head);
       if(pre==NULL)
           *head=root;
       else
        {
            root->left=pre;
            pre->right=root;
         }
         pre=root;
        doublelist(root->right,head);
}
struct node *formdll(struct node *root)
{
                if(root==NULL)
                   return root;
            doublelist(root,&root);
        while(root->left!=NULL)
        root=root->left;
        return root;
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int main()
{
    struct node *head=NULL;
    struct node *root  = newNode(6);
    root->left         = newNode(3);
    root->right        = newNode(3);
    doublelist(root,&head);
       while(head!=NULL)
      {
              printf("%d ",head->data);
              head=head->right;
      }
    getchar();
    return 0;
}
