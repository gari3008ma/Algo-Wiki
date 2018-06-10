#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
 
// Structure of a tree node
struct Node
{
    char key;
    struct Node *left, *right;
};
 
// A utility function to create a new BST node
Node *newNode(char item)
{
    Node *temp =  new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node *searchme(struct Node *root,struct Node *tmp)
{
    if(root==NULL)
        return NULL;
    if(root->key==tmp->key)
        return root;
    struct  Node *p=searchme(root->left,tmp);
    struct Node *pp= searchme(root->right,tmp);
    if(p!=NULL)
    return p;
    else if(pp!=NULL)
        return pp;
    else 
        return NULL;
}
bool issame(struct Node *root1,struct Node* root2)
{
             if(root1==NULL && root2==NULL)
                 return true;
             if(root1->key !=root2->key)
                return false;
            return (issame(root1->left,root2->left)&&issame(root1->right,root2->right));
}
bool issubtree(struct Node *root1,struct Node *root2)
{
                       struct Node *tmp=searchme(root1,root2);
                       cout<<tmp->key<"\n";
                        if(issame(tmp,root2))
                            return true;
                        else
                            return false;
}
int main()
{
    Node *T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    Node *S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');
 
    if (issubtree(T, S))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";
 
    return 0;
}