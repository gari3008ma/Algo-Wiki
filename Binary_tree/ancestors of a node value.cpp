#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
   int data;
   struct node* left;
   struct node* right;
};
void printAncestors(struct node *root,int num,struct node *ans)
{
         if(root==NULL)
            return ;
        if(root->data==num)
          {
                        printf("%d ",num);
                        ans=root;
          }
             printAncestors(root->left,num,ans)  ;
       if(ans)
       {
                    num=root->data;
       }
      printAncestors(root->right,num,ans)  ;
}
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
int main()
{
  struct node *tmp=NULL;
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);

  printAncestors(root, 7,tmp);

  getchar();
  return 0;
}
