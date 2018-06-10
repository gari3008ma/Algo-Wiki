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
            queue<struct node *> a,b;
                 int h=0,i,j;
                 struct node *tmp;
                 if(root==NULL)
                   return h;
            a.push(root);
            while(!a.empty() || !b.empty())
            {
              i=0;
                     while(!a.empty())
                   {
                         tmp=a.front();
                         i++;
                    if(tmp->left!=NULL)
                         {
                                b.push(tmp->left);
                         }
                    if(tmp->right!=NULL)
                        {
                                b.push(tmp->right);
                        }
                        a.pop();
                    }
                                if(i>0)
                                 h++;
                                 else
                                 break;
                                 i=0;
                                         while(!b.empty())
                   {
                         tmp=b.front();
                         i++;
                    if(tmp->left!=NULL)
                         {
                                a.push(tmp->left);
                         }
                    if(tmp->right!=NULL)
                        {
                                a.push(tmp->right);
                        }
                        b.pop();
                    }
                    if(i>0)
                        h++;
                    else
                        break;

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
