#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void leftview(struct node *root)
{
           queue<struct node *> a;
           struct node *tmp;
           int s,s1;
           if(root==NULL)
             return;
           a.push(root);
           while(!a.empty())
           {
                s=a.size();
                s1=s;
                cout<<a.front()->data<<" ";
                while(s--)
                {
                     tmp=a.front();
                     a.pop();
                     if(tmp->left!=NULL)
                     a.push(tmp->left);
                     if(tmp->right!=NULL)
                     a.push(tmp->right);

                }
           }
}
int main()
{
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    leftview(root);

    return 0;
}
