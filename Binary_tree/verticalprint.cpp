 #include <iostream>
#include<map>
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode (int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int get_second( pair<int, int> i ){ return i.second; }
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}
void vertical(struct node *root,map<int,int> &tmp)
{
           if(root==NULL)
              return;
              if(root->left!=NULL)
        tmp[root->left->data]=tmp[root->data]-1;
        if(root->right!=NULL)
        tmp[root->right->data]=tmp[root->data]+1;
        vertical(root->left,tmp);
        vertical(root->right,tmp);
}
void printA(struct node *root)
{
   map<int,int> a,b;
   set<int> c;
                if(root==NULL)
                     return ;
                     a[root->data]=0;
       vertical(root,a);
     map<int,int>::iterator it =a.begin()  ;
     for(it=a.begin();it!=a.end();it++)
           {
                        c.insert(it->second);
                        cout<<it->first<<" ->"<<it->second<<"\n";
            }
            set<int>::iterator j =c.begin()  ;
     for(j=c.begin();j!=c.end();j++)
           {
                        for(it=a.begin();it!=a.end();it++)
           {
                    if(*j==it->second)
                        cout<<it->first<<" ";
            }
            cout<<"$";
            }
}
int main()
{
    struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);
  printA(root);
    printf("\n Inorder traversal of the constructed tree is \n");
    printInorder(root);
    return 0;
}
