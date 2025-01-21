 #include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
void minmaxdis(struct node *root,int hd,int *minu,int *maxu)
{
                    if(root==NULL)
                        return ;
                    if((hd)>(*maxu))
                        (*maxu)=(hd);
                    else if((hd)<(*minu))
                        (*minu)=(hd);
                    minmaxdis(root->left,hd-1,minu,maxu);
                    minmaxdis(root->right,hd+1,minu,maxu);
}
void printvertical(struct node *root,int i,int j,vector<int> arr)
{
                if(root==NULL)
                    return ;
                if(i==j)
                    arr.push_back(root->data);
                printvertical(root->left,i,j-1,arr);
                printvertical(root->right,i,j+1,arr);
}
void printtree(struct node *root)
{
            int lw=0,rw=0,hd=0,i;
            minmaxdis(root,hd,&lw,&rw);
            cout<<lw<<" "<<rw<<" ";
            vector<int> arr; 
            vector<int>:: iterator it;
            for( i=(lw);i<=(rw);i++)
            {
                printvertical(root,i,0,arr);
                it=arr.end();
                cout<<(*it)<<" ";
                arr.clear();
            }
            cout<<"\n";
              return;
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
   struct  node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    printInorder(root);
   printf("Vertical number of the constructed tree node is ");
     printtree(root);
   
    return 0;
}
