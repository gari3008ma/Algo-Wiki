// C program to remove all half nodes
#include <stdio.h>
#include <stdlib.h>
 
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
struct node *removehalfnodes(struct node *root)
{
     if(root==NULL)
         return root;
     if(root->left==NULL && root->right==NULL)
         return root;
  root->left= removehalfnodes(root->left);
    root->right=removehalfnodes(root->right);
    if(root->left==NULL && root->right!=NULL)
     {
       struct node * tmp=root->right;
        root->data=tmp->data;
        root->left=tmp->left;
        root->right=tmp->right;
        free(tmp);
    }
    if(root->right==NULL && root->left!=NULL)
    {
        struct node *tmp=root->left;
            root->data=tmp->data;
            root->left=tmp->left;
            root->right=tmp->right;
             free(tmp);
    }    
    return root;
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
 
    NewRoot = removehalfnodes(root);
 
    printf("\nInorder traversal of the modified tree \n");
    printInoder(NewRoot);
    return 0;
}