 #include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
 
struct Node *newNode(char item)
{
    struct Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void printbtwlevel(struct Node *root)
{
          if(root==NULL)
               return ;
             cout<<root->data<<" ";
             if(root->left==NULL)
              return;
         cout<<root->left->data<<" "<<root->right->data<<" ";
         if(root->left->left==NULL)
           return ;
            struct Node *first,*second;
           queue<struct Node *> revl;
           revl.push(root->left);
           revl.push(root->right);
           while(!revl.empty())
           {
               first=revl.front();
               revl.pop();
                second=revl.front();
               revl.pop();
               cout<<first->left->data<<" "<<second->right->data<<" "<<first->right->data<<" "<<second->left->data<<" ";
              
                      if(first->left->left!=NULL)
                           { 
                            revl.push(first->left);
                            revl.push(second->right);
                            revl.push(first->right);
                            revl.push(second->left);
                          }
                       
           }
}
void printInorder(struct Node *root)
{
    if (root == NULL) 
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
 
int main()
{
    Node *root = newNode(1);
 
    root->left        = newNode(2);
    root->right       = newNode(3);
 
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
 
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);
 
    root->left->left->left->left  = newNode(16);
    root->left->left->left->right  = newNode(17);
    root->left->left->right->left  = newNode(18);
    root->left->left->right->right  = newNode(19);
    root->left->right->left->left  = newNode(20);
    root->left->right->left->right  = newNode(21);
    root->left->right->right->left  = newNode(22);
    root->left->right->right->right  = newNode(23);
    root->right->left->left->left  = newNode(24);
    root->right->left->left->right  = newNode(25);
    root->right->left->right->left  = newNode(26);
    root->right->left->right->right  = newNode(27);
    root->right->right->left->left  = newNode(28);
    root->right->right->left->right  = newNode(29);
    root->right->right->right->left  = newNode(30);
    root->right->right->right->right  = newNode(31);
 
   
    cout<<"\n";
    printbtwlevel(root);
 
 
    return 0;
}