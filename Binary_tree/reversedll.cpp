#include <bits/stdc++.h>
using namespace std;
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
void push(struct Node *tmp,struct Node **head)
{
        tmp->right=(*head);
        tmp->left=NULL;
        if((*head)!=NULL)
            (*head)->left=tmp;
    (*head)=tmp;
}
void btodll(struct Node *root)
{
       if(root==NULL)
          return;
      deque<struct Node *> qur;
      stack<struct Node *> st;
      struct Node *tmp,*ptr;
      int level=0,nodecount;
      qur.push_back(root);
      while(!qur.empty())
      {
        nodecount=qur.size();
        if(level&1)
          {
                    while(nodecount--)
            {
                    tmp=qur.front();
                    cout<<tmp->data<<" ";
                    st.push(tmp);
                    qur.pop_front();
                    if(tmp->left)
                     qur.push_back(tmp->left);
                    if(tmp->right)
                     qur.push_back(tmp->right);
            }
          }
       else
         {
                     while(nodecount--)
            {
                    tmp=qur.back();
                    cout<<tmp->data<<" ";
                    st.push(tmp);
                    qur.pop_back();
                    if(tmp->right)
                     qur.push_front(tmp->right);
                    if(tmp->left)
                     qur.push_front(tmp->left);
            }
          }
           level++;
      }
      struct Node **head=NULL;
     while(!st.empty())
      {
        tmp=st.top();
        st.pop();
        push(tmp,head);
      }
      /*
      while((*head)->right!=NULL)
      {
        cout<<(*head)->data<<" ";
        (*head)=(*head)->right;
      }
      */
}
int main()
{
      Node *root =  newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    //root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    //root->right->right->right  = newNode(15);
    btodll(root);
}