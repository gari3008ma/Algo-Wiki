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
int search(int arr[],int a,int b,int v)
{
     int i;
     for(i=a;i<b;i++)
     {
          if(arr[i]==v)
            return i;
     }
}
int * tree(int arr[],int brr[],int instart,int inend,int n)
{
       int prr[1000],i,j,k=0;
       for(i=0;i<n;i++)
       {
            for(j=instart;j<inend;j++)
            {
                  if(brr[i]==arr[j])
                  {
                       prr[k]=arr[j];
                       k++;
                  }
            }
       }
       return prr;
}
struct node *buildtree(int arr[],int brr[],int instart,int inend ,int n)
{
            if(instart >inend )
                return NULL;
               struct node *root=newNode(arr[index]);
              if(instart==inend)
                return root;
              int index=search(arr,brr[0],instart,inend);
               
              int *l=tree(arr,brr,instart,index-1,n);
              int *r=tree(arr+index+1,brr,index+1,inend,n);
             node->left = buildtree(arr,l,instart,index-1,n);
             node->right = buildtree(arr+index+1,r,index+1,inend,n);
               delete(l);
               delete(r);
               return root;
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
   
      int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    Node *root = buildtree(in, level, 0, n - 1, n);
 
    /* Let us test the built tree by printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
 
    return 0;
}
