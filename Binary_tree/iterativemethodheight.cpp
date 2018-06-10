#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int treeHeight(struct node *root)
 {
            queue<struct node *> a;
                 int h=0,nodecount;
                 struct node *tmp;
                 if(root==NULL)
                   return h;
            a.push(root);
            while(1)
            {
                        nodecount = a.size();
                        if(nodecount==0)
                            break;
                          else
                          h++;
                     while(nodecount>0)
                   {
                         tmp=a.front();
                         nodecount--;
                    if(tmp->left!=NULL)
                         {
                                a.push(tmp->left);
                         }
                    if(tmp->right!=NULL)
                        {
                                a.push(tmp->right);
                        }
                        a.pop();
                    }
            }
            return h;

 }
node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Height of tree is " << treeHeight(root);
    return 0;
}
