#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *middle, *right;
};
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->middle = node->right = NULL;
    return node;
}
void push(Node** tail_ref, Node* node)
{
    if (*tail_ref == NULL)
    {
        *tail_ref = node;
        node->left = node->middle = node->right = NULL;
 
        return;
    }
    (*tail_ref)->right = node;
    node->left = (*tail_ref);
    node->right = node->middle = NULL;
    (*tail_ref) = node;
}
 void  TernaryTreeToList(struct Node *root, struct Node **head);
{
    
}
int main()
{
    Node* root = newNode(30);
 
    root->left = newNode(5);
    root->middle = newNode(11);
    root->right = newNode(63);
 
    root->left->left = newNode(1);
    root->left->middle = newNode(4);
    root->left->right = newNode(8);
 
    root->middle->left = newNode(6);
    root->middle->middle = newNode(7);
    root->middle->right = newNode(15);
 
    root->right->left = newNode(31);
    root->right->middle = newNode(55);
    root->right->right = newNode(65);
 
    Node* head = NULL;
 
    TernaryTreeToList(root, &head);
 
    printList(head);
 
    return 0;
}