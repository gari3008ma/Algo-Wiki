// A C++ program to find the closesr leaf of a given key in Binary Tree
#include <iostream>
#include <climits>
using namespace std;
 
/* A binary tree Node has key, pocharer to left and right children */
struct Node
{
    char key;
    struct Node* left, *right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pocharers. */
Node *newNode(char k)
{
    Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}
int min(int a,int b)
{
     return (a>b?b:a);
}
int rootdown(struct Node *root,int v)
{
    if(root==NULL)
        return INT_MAX;
    if(root->left==NULL && root->right==NULL)
    {
           return v;
    }
    return min(rootdown(root->left,v+1),rootdown(root->right,v+1));
}
int printl(struct Node *root,char tmp,int index,struct Node* arr[])
{
         if(root==NULL)
             return INT_MAX ;
        
        if(root->key==tmp)
        {
                int dis1=rootdown(root,0);
                for(int i=index-1;i>=0;i--)
                {
                        cout<<"index of this is "<<i<<" "<<arr[i]->key<<" min dis of __  "<<rootdown(arr[i],0)<<"   "<<"valuse of dis1 "<<dis1<<"\n";
                        dis1=min(dis1,index-i+rootdown(arr[i],0));
                        cout<<" "<<dis1<<" \n";
                }
                return dis1;
        }
        arr[index]=root;
        index++;
        return min(printl(root->left,tmp,index,arr),printl(root->right,tmp,index,arr));
}
int findClosest(struct Node *root,char tmp)
{
        struct Node * arr[1000];
        return printl(root,tmp,0,arr);
}
/* Driver program to test above functions*/
int main()
{
    // Let us construct the BST shown in the above figure
    struct Node *root        = newNode('A');
    root->left               = newNode('B');
    root->right              = newNode('C');
    root->right->left        = newNode('E');
    root->right->right       = newNode('F');
    root->right->left->left  = newNode('G');
    root->right->left->left->left  = newNode('I');
    root->right->left->left->right = newNode('J');
    root->right->right->right      = newNode('H');
    root->right->right->right->left = newNode('K');
 
    char k = 'H';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 'C';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 'E';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 'B';
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
 
    return 0;
}