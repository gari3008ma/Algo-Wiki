
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
struct node *constructTree(int arr[],char pre[],int i)
{
           if(pre[i]=='L')
           {
                     return (newnode(pre[i]));
           }
        struct node *root=newnode(arr[i]);
        i++;
        root->left=constructTree(arr,pre,i);
        root->right=constructTree(arr,pre,i);
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
     int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);

    // construct the above tree
struct node *root = constructTree (pre, preLN, n);

    // Test the constructed tree
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printInorder (root);

    return 0;
}
