 #include <iostream>
using namespace std;
struct Node
{
    int data; //data of the node
   struct Node *left, *right; //left and right references
};
int bottomView(Node *root)
{
    
          if(root==NULL)
               return 0 ;
           queue<struct Node *> revl;
           struct Node *tmp;
           int lvl,hd=0,flag=0;
           revl.push(root);
           while(!revl.empty())
           {          
                       lvl=revl.size();                      
                       while(lvl--)
                       {
                            tmp=revl.front();
                            revl.pop();
                          if(tmp->left==NULL && tmp->right==NULL)
                          {
                                  flag=1;
                                  break;
                          }
                            if(tmp->left!=NULL)
                            {
                              revl.push(tmp->left);
                            }
                            if(tmp->right!=NULL)
                            {
                              revl.push(tmp->right);
                            }
                       }
                       hd++; 
                       if(flag==1)
                       {
                                         break;
                       }
                      
           }
           return hd;
}
 Node *newNode(int k)
{
    Node *node = new Node;
    node->data = k;
    node->right = node->left = NULL;
    return node;
}
// Driver Code
int main()
{
     Node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    cout << "min depth of the given binary tree :\n";
    cout<<bottomView(root)<<"\n";
    return 0;
}