#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};  
node *newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int pathindex=0;
void printkdis(struct node *root,struct node *target,int k,int path[],bool visited[])
{
         if(root==NULL ||target==NULL)
             return ;
           path[pathindex]=root->data;
           pathindex++;
          if(root==target &&(visited[pathindex-k-1]==false)&&(pathindex-k-1>=0))
          {
                printf("%d ",path[pathindex-k-1]);
                visited[pathindex-k-1]=true;
          }
          printkdis(root->left,target,k,path,visited);
           printkdis(root->right,target,k,path,visited);
}
void printInorder (struct node* root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}
int main ()
{
    node * root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    node * target = root->left->right;
    bool visited[1000]={false};
    int path[1000];
    printkdis(root, target, 2,path,visited);
    return 0;
}
