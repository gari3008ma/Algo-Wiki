#include<bits/stdc++.h>
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
bool ismr(struct node *root1,struct node *root2)
{
             if(root1==NULL && root2==NULL)
               return true;
             if(root1==NULL || root2==NULL)
                return false;
             if(root1->data!=root2->data)
               return false;
          return ismr(root1->left,root2->right) && ismr(root1->right,root2->left);
}
bool ismror(struct node *root)
{
            if(root==NULL)
              return true;
           return ismr(root->left,root->right);
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
    struct node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
   
       if(ismror(root))
          printf("Mirror tree     ");
        else
          printf("Not Mirror tree     ");
    return 0;
}