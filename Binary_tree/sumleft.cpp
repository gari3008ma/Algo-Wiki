// C program to remove all half nodes
#include <bits/stdc++.h>
#include <stdlib.h>
 using namespace std;
struct node
{
    int data;
    struct node* left, *right;
};
 
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}
 void printInoder(struct node*root)
{
    if (root != NULL)
    {
        printInoder(root->left);
        printf("%d ",root->data);
        printInoder(root->right);
    }
}
void leafsum(struct node *root,int *sum,bool left)
{
           if(root==NULL)
                   return ;
               if(root->left==NULL && root->right==NULL && left)
                  (*sum) = (*sum) +root->data;
              leafsum(root->left,sum,1);
              leafsum(root->right,sum,0);
}
int sum(struct node *root)
{
    int sumi=0;
    leafsum(root,&sumi,0);
    return (sumi);
}
int main(void)
{
    struct node*NewRoot=NULL;
    struct node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);
 
    printf("Inorder traversal of given tree \n");
    printInoder(root);
     int  sumu= sum(root);
    printf("\nInorder traversal of the modified tree %d\n",sumu);
    
    return 0;
}