#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
void mmtree(struct node *root,int *p)
{
             if(root==NULL)
              return ;
            if(root->data < (*p))
              ( *p)= (root->data);
     mmtree(root->left,p);
     mmtree(root->right,p);
}
void printInorder(struct node *root)
{
                   if(root==NULL)
                      return ;
                  printInorder(root->left);
                  printf("%d  ",root->data);
                  printInorder(root->right);
}
int main()
{
    struct node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
    int p=INT_MAX; 
      mmtree(root,&p);
   cout<<p<<" ";
    return 0;
}
