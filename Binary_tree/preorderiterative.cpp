#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
void iterativePreorder(struct node *root)
{
        stack<struct node *> a;
        struct node *tmp;
        a.push(root);
        while(!a.empty())
        {
                 tmp=a.top();
                 a.pop();
                  cout<<tmp->data<<" ";
                 if(tmp->right!=NULL)
                    a.push(tmp->right);
                 if(tmp->left!=NULL)
                    a.push(tmp->left);
        }
}
int main()
{
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  iterativePreorder(root);
  return 0;
}
