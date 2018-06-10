// C++ program to find count of single valued subtrees
#include<bits/stdc++.h>
using namespace std;
 
// A Tree node
struct Node
{
    int data;
    struct Node* left, *right;
};
 
// Utility function to create a new node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}
 

bool countSingleRec(Node* root, int &count)
{
    // Return false to indicate NULL
    if (root == NULL)
       return true;
 
   
    bool left = countSingleRec(root->left, count);
    bool right = countSingleRec(root->right, count);
 
    
    if (left == false || right == false)
       return false;

    if (root->left && root->data != root->left->data)
        return false;
 
    // Same for right subtree
    if (root->right && root->data != root->right->data)
        return false;
    count++;
    return true;
}

int countSingle(Node* root)
{
    // Initialize result
    int count = 0;
 
    // Recursive function to count
    countSingleRec(root, count);
 
    return count;
}
 
// Driver program to test
int main()
{
    /* Let us construct the below tree
            5
          /   \
        4      5
      /  \      \
     4    4      5 */
    Node* root        = newNode(5);
    root->left        = newNode(4);
    root->right       = newNode(5);
    root->left->left  = newNode(4);
    root->left->right = newNode(4);
    root->right->right = newNode(5);
 
    cout << "Count of Single Valued Subtrees is "
         << countSingle(root);
    return 0;
}