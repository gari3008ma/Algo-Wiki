#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node * form(struct node *root)
{
                if(root==NULL)
                    return root ;
                    if(root->left)
              {
                struct node *l= form(root->left);
                for(;l->right!=NULL;l=l->right);
                l->right=root;
                root->left=l;
              }
              if(root->right)
                {
                   struct node *r= form(root->right);
                for(;r->left!=NULL;r=r->left);
                r->left=root;
                root->right=r;
                }
                 return root;
}
struct node *doublelist(struct node *root)
{
      if(root==NULL)
         return NULL;
      root=form(root);
      while(root->left!=NULL)
      {
              root=root->left;
      }
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
    struct node *root  = newNode(6);
    root->left         = newNode(3);
    root->right        = newNode(3);
    root=doublelist(root);
       while(root!=NULL)
      {
              printf("%d ",root->data);
              root=root->right;
      }
    getchar();
    return 0;
}

