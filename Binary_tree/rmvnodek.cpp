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
struct node *removehalfnodes(struct node *root,int index,int k)
{
     if(root==NULL)
         return root;
        
  root->left= removehalfnodes(root->left,index+1,k);
    root->right=removehalfnodes(root->right,index+1,k);     
    if(root->left==NULL && root->right==NULL && index <k)
         {
                    
                        free(root);
                    return NULL;
                
         }
    return root;
}
int main(void)
{
     int k = 4;
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);
    root->right->right = newNode(6);
    root->right->right->left = newNode(8);
 
    printf("Inorder traversal of given tree \n");
    printInoder(root);
    vector<struct node*>arr;
    map<struct node*,int> brr;
  struct node *NewRoot = removehalfnodes(root,1,k);
    printf("\nInorder traversal of the modified tree \n");
    printInoder(NewRoot);
    return 0;
}