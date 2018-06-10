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
bool issub(struct node *root,int t)
{
            if(root==NULL)
                return true;
            if(root->data!=t)
                return false;
            return (issub(root->left,t)&&issub(root->right,t));
}
void valuenode(struct node *root,int *k)
{
    if(root==NULL)
        return ;
    if(issub(root,root->data))
        (*k)++;
    valuenode(root->left,k);
    valuenode(root->right,k);
}
int main(void)
{
     
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
    int k = 0;
    valuenode(root,&k);
    printf("\nvalue of tree%d \n",k);
    return 0;
}