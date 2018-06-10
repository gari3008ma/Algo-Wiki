#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left, *right;
};
int height(struct node *root )
{
         int lht,rht;
         if(root==NULL)
             return 0;
         else
         {
                lht=height(root->left);
                rht=height(root->right);
                if(lht>rht)
                   return (lht+1);
                else
                   return(rht+1);
         }
}
void printlevel(struct node *root,int i)
{
          if(root==NULL)
             return ;
          if(i==1)
            cout<<root->data<<" ";
           else if(i>1)
           {
                printlevel(root->left,i-1);
                printlevel(root->right,i-1);
           }
}
void printLevelOrder(struct node *root)
{
            int h,i;
            h=height(root);
            for(i=1;i<=h;i++)
            {
                       printlevel(root,i);
            }
}
struct node* newNode(int data)
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
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);

    return 0;
}
