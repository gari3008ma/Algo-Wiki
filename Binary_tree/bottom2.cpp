// C++ Program to print Bottom View of Binary Tree
 #include <iostream>
using namespace std;
 
// Tree node class
struct Node
{
    int data; //data of the node
    int hd; //horizontal distance of the node
    Node *left, *right; //left and right references
 
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};
 
// Method that prints the bottom view.
void bottomView(Node *root)
{
    
          if(root==NULL)
               return ;
           queue<struct Node *> revl;
           struct Node *tmp;
           int hd=0,lvl;
           map<int,int> arr;
           root->hd=hd;
           revl.push(root);
           while(!revl.empty())
           {          
                       lvl=revl.size();                      
                       while(lvl--)
                       {
                            tmp=revl.front();
                            hd=tmp->hd;
                            revl.pop();
                            arr[hd]=(tmp->data);
                            if(tmp->left!=NULL)
                            {
                              revl.push(tmp->left);
                              tmp->left->hd=hd-1;
                            }
                            if(tmp->right!=NULL)
                            {
                              revl.push(tmp->right);
                              tmp->right->hd=hd+1;
                            }
                       }
                       
           }
           map<int,int> ::iterator it = arr.begin();
           for(it = arr.begin();it!=arr.end();it++)
           {
                cout<<(it)->second<<" ";
           }
}
 
// Driver Code
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;
}