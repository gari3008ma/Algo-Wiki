#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
bool ances(struct node *root,int f[],int s,int *n)
{
                           if(root==NULL)
                              return false;
                        if(root->data==s)
                           {
                              f[*n]=root->data;
                                  (*n)++;
                              return true;
                            }
                      if(ances(root->left,f,s,n)|| ances(root->right,f,s,n))
                      {
                                  f[*n]=root->data;
                                  (*n)++;
                                  return true;
                      }
                      return false;
}
int lca(struct node *root,int a,int b)
{
            if(root==NULL)
               return 0;
    int a1[100],b1[100],n1=0,n2=0;
    int *d1=&n1,*d2=&n2;
    bool p=ances(root,a1,a,d1);
    bool q=ances(root,b1,b,d2);
    int i,j;
    for(i=0;i<(*d1);i++)
    cout<<" "<<a1[i]<<"\n";
    cout<<"->\n";
    for(j=0;j<(*d2);j++)
    cout<<b1[j]<<"\n";
    cout<<"->\n";
    return 0;
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int main()
{
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << lca(root, 4, 5);
    cout << "\nLCA(4, 6) = " <<lca(root, 4, 6);
    cout << "\nLCA(3, 4) = " <<lca(root, 3, 4);
    cout << "\nLCA(2, 4) = " <<lca(root, 2, 4);
    return 0;
}
