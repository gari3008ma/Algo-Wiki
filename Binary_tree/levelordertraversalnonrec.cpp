#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
void printLevelOrder(struct node *root)
{
            queue<struct node *> a;
            struct node *tmp;
            tmp=root;
            a.push(tmp);
            while(!a.empty())
            {
                   tmp=a.front();
                    cout<<tmp->data<<" ";
                    if(tmp->left!=NULL)
                 a.push(tmp->left);
                 if(tmp->right!=NULL)
                 a.push(tmp->right);
                 a.pop();
            }
}
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);

    return 0;
}
