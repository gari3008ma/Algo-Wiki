#include <iostream>
#include <queue>
using namespace std;
struct node
{
    struct node *left, *right;
    int key;
};

node* newNode(int key)
{
    node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *nextright(struct node *root,struct node *prev,int k)
{
         struct node *i;
               if(root==NULL)
                  return NULL;
                if(root->key==k)
                {
                        if(prev==NULL)
                           return NULL;
                         else
                         {
                             return prev->left;
                         }
                }
                prev=root;
           i=nextright(root->left,prev,k);
           i=nextright(root->left,prev,k);
           return i;
}
void test(node *root, int k)
{
    struct node *prev=NULL;
    node *nr = nextright(root,prev, k);
    if (nr != NULL)
      cout << "Next Right of " << k << " is " << nr->key << endl;
    else
      cout << "No next right node found for " << k << endl;
}
int main()
{
    node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);

    test(root, 10);
    test(root, 2);
    test(root, 6);
    test(root, 5);
    test(root, 8);
    test(root, 4);
    return 0;
}
