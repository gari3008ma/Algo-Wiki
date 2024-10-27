 #include <iostream>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int p=INT_MIN;
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int findlmax(struct node *root,int *max,int j)
{
                if(root==NULL)
                    return 0;
                if((*max)<j)
                    (*max)=j;
                findlmax(root->left,max,j+1);
                findlmax(root->right,max,j-1);
}
int findrmax(struct node *root,int *max,int j)
{
                if(root==NULL)
                    return 0;
                if((*max)<j)
                    (*max)=j;
                findlmax(root->left,max,j-1);
                findlmax(root->right,max,j+1);
}
void printverticall(struct node *root,int i,int j)
{
             if(root==NULL)
                    return ;
                if(i==j)
                printf("%d ",root->data);
                printvertical(root->left,i,j+1);
                printvertical(root->right,i,j-1);
}
void printverticalr(struct node *root,int i,int j)
{
             if(root==NULL)
                    return ;
                if(i==j)
                printf("%d ",root->data);
                printvertical(root->left,i,j-1);
                printvertical(root->right,i,j+1);
}
void printtree(struct node *root)
{
            int lw=0;
            findlmax(root->left,&lw,0);
            int rw=0;
            findrmax(root->right,&rw,0);
            for(int i=(lw);i>0;i--)
            {
                printverticall(root,i,0);
            }
            for(int i=0;i<(rw);i++)
            {
                printverticalr(root,i,0);
            }
              return;
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
   
     printtree(root);
   printf("Maximum number of the constructed tree is   %d      ",num);
    return 0;
}
