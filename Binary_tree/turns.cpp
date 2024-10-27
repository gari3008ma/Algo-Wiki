 #include <iostream>


#include<map>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode (int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}
struct node *lca(struct node * root,int a,int b,struct node *low)
{
	if(root==NULL)
		return NULL;
	if(root->data==a || root->data==b)
		  return root;	
    struct node *l=lca(root->left,a,b,low);
    struct node *r=lca(root->right,a,b,low);
    if(l&&r)
    	low=l;
    return l!=NULL?l:r;
}
int main()
{
    struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);
 // printA(root);
    printf("\n Inorder traversal of the constructed tree is \n");
    printInorder(root);
    lca(root,7,3);
    return 0;
}
