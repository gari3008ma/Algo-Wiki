#include <bits/stdc++.h>
#include <queue>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
    bool isThreaded;
};
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->left = temp->right = NULL;
    temp->key = key;
    return temp;
}
void printInorder(struct Node* node)
{
  if (node == NULL)
    return;
  printInorder(node->left);
  printf("%d ", node->key);
  printInorder(node->right);
}

void createThreaded(Node *root,bool flg,Node *pre)
{
         if(root==NULL)
            return;
    createThreaded(root->left,flg,pre); 
    createThreaded(root->right,!flg,pre);
    if(pre!=NULL && root->right==NULL)
    {
        pre=root->right;
    }
    else if(pre==NULL)
    {
        pre=root;
    }

}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    Node *pre=NULL;
    printInorder(root);
    createThreaded(root,true,pre);
     cout << "\nInorder traversal of creeated threaded tree is\n";
    printInorder(root);
    return 0;
}