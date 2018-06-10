#include <bits/stdc++.h>
using namespace std;
# define N 6
struct Node
{
    int data;
    Node *left, *right;
};
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    printInorder(node->left);
    printInorder(node->right);
}
void tree(struct Node *root)
{
    if(root==NULL)
        return;
    tree(root->left);
    tree(root->right);
    if(root->left==NULL)
        root->left=root->right;
    else
        root->left->right=root->right;
    root->right=NULL;
}
int main()
{
Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(8);
    printInorder(root);
    tree(root);
    printInorder(root);
}