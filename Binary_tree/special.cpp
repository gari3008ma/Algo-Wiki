#include <bits/stdc++.h>
using namespace std;
# define N 6
struct Node
{
    int data;
    Node *left, *right;
};
Node* newnode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
int search(int in[],int s,int e)
{
  int ind,i,max=INT_MIN;
    for(i=s;i<=e;i++)
    {
         if(in[i]>max)
         {
            max=in[i];
            ind=i;
         }
    }
    return ind;
}
struct Node* formmat(int inorder[],int ss,int se)
{
           if(root==NULL)
              return NULL;
   int mid=search(inorder,ss,se);
   struct Node *root=newnode(inorder[mid]);
   if(ss==se)
      return root;
    root->left=formmat(inorder,ss,mid-1);
    root->right=formmat(inorder,mid+1,se);  
    return root;
}

int main()
{
     
    Node *root = formmat(inorder,0,n);
 
    cout << "Inorder traversal of tree is \n";
    printInorder(root);
 
    return 0;
}