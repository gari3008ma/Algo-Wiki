#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node *dis(struct node *root,int x,int y)
{
          if(root==NULL)
              return root;
          if(root->data==x || root->data==y)
              return root;
          struct node *l_eft=dis(root->left,x,y); 
          struct node *r_ight=dis(root->right,x,y);
          if(l_eft && r_ight)
            return root;
         return l_eft!=NULL? l_eft:r_ight;        
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int main()
{
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << dis(root, 4, 5)->data;
    cout << "\nLCA(4, 6) = " <<dis(root, 4, 6)->data;
    cout << "\nLCA(3, 4) = " <<dis(root, 3, 4)->data;
    cout << "\nLCA(2, 4) = " <<dis(root, 2, 4)->data;
    return 0;
}
