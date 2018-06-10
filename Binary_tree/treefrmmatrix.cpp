#include <bits/stdc++.h>
using namespace std;
# define N 6
struct Node
{
    int data;
    Node *left, *right;
};
Node* newNode(int data)
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
Node *formtree(int i,struct Node * arr[],int mat[N][N],int j)
{
            if(mat[i][j]&&arr[i]==NULL)
                arr[i]=newNode(i);
            formtree(i,arr,mat,j++);
            
}
Node *ancestorTree(int mat[N][N])
{
       int i,j,k;
       struct Node *arr[100];
       memset(arr,NULL,sizeof(arr));
       //vector<vector<int> qrr;
       for(i=0;i<N;i++)
       {
         if(arr[i]==NULL)
            formtree(i,arr,mat,0);
       }
}
int main()
{
    int mat[N][N] = {{ 0, 0, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 0 }
    };
 
    Node* root = ancestorTree(mat);
 
    cout << "Inorder traversal of tree is \n";
    printInorder(root);
 
    return 0;
}