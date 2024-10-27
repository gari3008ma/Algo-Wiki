 #include <iostream>
using namespace std;

struct Node
{
    int val;
    struct Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->val = data;
    temp->left = temp->right =  NULL;
    return temp;
}
void deep(struct Node *root,int l,int index,bool b,int *v)
{
           if(root==NULL)
                return ;
           if(root->left==NULL && root->right==NULL&&b==true&&l>=index)
        {
                *v= root->val;
        }
            deep(root->left,l+1,index,true,v);
            deep(root->right,l+1,index,false,v);
}
int main()
{
    int v=0;
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
    deep(root,0,0,false,&v);
    cout<<v<<" ";
  }
