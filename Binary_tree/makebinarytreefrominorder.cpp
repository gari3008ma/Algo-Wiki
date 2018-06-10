#include<bits/stdc++.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int data)
{
    struct node* node = (struct node*)
                           malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int maxu(int arr[],int low,int high)
{
            int i,j=INT_MIN,v=low;
            for(i=low;i<=high;i++)
            {
                       if(arr[i]>j)
                       {
                              v=i;
                              j=arr[i];
                       }
            }
            return v;
}
struct node *buildtree(int arr[],int low,int high)
{
            int i;
            if(low>high)
                return NULL;
           i=maxu(arr,low,high);
        struct node *  root= newnode(arr[i]);
          root->left= buildtree(arr,low,i-1);
           root->right=buildtree(arr,i+1,high);

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
     int inorder[] = {5};
    int len = sizeof(inorder)/sizeof(inorder[0]);
    struct node *root = buildtree(inorder, 0, len - 1);
    printf("\n Inorder traversal of the constructed tree is \n");
    printInorder(root);
    return 0;
    return 0;
}
