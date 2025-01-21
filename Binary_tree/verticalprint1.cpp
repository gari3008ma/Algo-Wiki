 #include <iostream>
#include<stdlib.h>
using namespace std;
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
void findlmax(struct node *root,int *max,int j)
{
                if(root==NULL)
                    return ;
                if((*max)<j)
                    (*max)=j;
                findlmax(root->left,max,j+1);
                findlmax(root->right,max,j-1);
}
void findrmax(struct node *root,int *max,int j)
{
                if(root==NULL)
                    return ;
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
                printverticall(root->left,i,j+1);
                printverticall(root->right,i,j-1);
}
void printverticalr(struct node *root,int i,int j)
{
             if(root==NULL)
                    return ;
                if(i==j)
                printf("%d ",root->data);
                printverticalr(root->left,i,j-1);
                printverticalr(root->right,i,j+1);
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
            cout<<"\n";
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
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
   printf("Vertical number of the constructed tree node is ");
     printtree(root);
   
    return 0;
}
