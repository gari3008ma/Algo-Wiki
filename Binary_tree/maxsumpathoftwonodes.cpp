 #include <iostream>
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
int maxi(int a,int b)
{
     return a>b ?a:b;
}
int buildtree(struct node *root,int *max)
{
            if (root==NULL)
                return 0;
         if(root->left==NULL && root->right==NULL)
             return (root->data);
            int l=buildtree(root->left,max);
            int r=buildtree(root->right,max);
            //cout<<(*max)<<" ";
            if(root->left!=NULL && root->right!=NULL)
             {
                
              (*max) = maxi((*max),(l + r + (root->data)));
                return maxi(l,r)+root->data;
            }
            return (!root->left )? (r+root->data): (l+root->data);
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
   int p=INT_MIN;
       int num = buildtree(root,&p);
   printf("Maximum number of the constructed tree is   %d      ",p);
    return 0;
}
