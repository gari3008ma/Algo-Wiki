#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
   int data;
   struct node* left;
   struct node* right;
};

void ances(struct node *root,int key1,int arr[],int* index)
{
        if(root==NULL)
           return ;
           if(key1==root->data)
              return ;
          arr[*index]=root->data;
                                 (*index)++;
          ances(root->left,key1,arr,index);
          ances(root->left,key1,arr,index);
}
int LCA(struct node *root,int key1 ,int key2)
{
              int key1arr[1000],key2arr[1000],i,j,index1=0,index2=0,index;
              ances(root,key1,key1arr,&index1);
              ances(root,key2,key2arr,&index2);
              if(index1 >index2)
              index=index2;
              else
              index=index1;
              for(i=0;i<index;i++)
              {
                    if(key1arr[i]!=key2arr[i])
                       {
                         if(i==0)
                           return -1;
                         else
                           return key1arr[i-1];  
                       }
              }
}
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
int main()
{
  struct node *tmp=NULL;
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);

  cout<<LCA(root,2,3)<<" ";

  getchar();
  return 0;
}
