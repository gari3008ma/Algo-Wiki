 #include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int addsum(struct node *root)
{
         if(root==NULL)
             return 0;
          return root->data+addsum(root->left)+addsum(root->right);
}
void sumtree(struct node *root)
{
           if(root==NULL)
               return ;
           if(root->left!=NULL )
           {
                        root->data=root->data + addsum(root->left);
           }  
           sumtree(root->left);
           sumtree(root->right);
}

void printInorder(struct node *root)
{
                   if(root==NULL)
                      return ;
                  printInorder(root->left);
                  printf("%d  ",root->data);
                  printInorder(root->right);
}
int main()
{
    struct node *root  = newNode(1);
    root->left         = newNode(2);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(5);
    root->right->right = newNode(6);
   printInorder(root);
   printf("Left Sum Tree  ");
   sumtree(root);
 printInorder(root);
    return 0;
}
