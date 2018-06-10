
#include<stdio.h>
#include<stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode (int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}
int main()
{
    int inorder[] = {5, 10, 40, 30, 28};
    int len = sizeof(inorder)/sizeof(inorder[0]);
    struct node *root = buildTree(inorder, 0, len - 1);
    printf("\n Inorder traversal of the constructed tree is \n");
    printInorder(root);
    return 0;
}
