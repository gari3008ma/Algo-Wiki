#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data,count;
  struct node *left;
  struct node *right;

};
struct datafreq
{
    int data;
    int freq;
};
struct node* newnode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->count = 1;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d %d\n", root->data,root->count);
        inorder(root->right);
    }
}
struct node *insert(struct node *root,int value)
{
	if(root==NULL)
	{
		  return (newnode(value));
	}
	if(root->data < value)
	{
		root->right=insert(root->right,value);
	}
	else if(root->data > value)
	{
		root->left=insert(root->left,value);
	}
  else
  {
        root->count+=1;
   }
	   return root;
  
}
void store(struct node *root,struct datafreq p[],int *index)
{
  if (root != NULL)
    {
        inorder(root->left);
        p[*index].data=root->data;
        p[*index].freq=root->count;
        (*index)++;
        inorder(root->right);
    }
}
bool compare(struct datafreq a,struct datafreq b)
{   
  if(a.freq!=b.freq)
  return (a.freq < b.freq);
else
  return a.freq==b.freq;
}
int main()
{
    int n,i,arr[100],index=0;
    datafreq p[100];
    struct node *root=NULL;
    cin>>n;
    for(i=0;i<n;i++)
    {
      cin>>arr[i];
      root=insert(root,arr[i]);
    }
  //inorder(root);//Used print data in sorted order with freq
  store(root,p,&index);
   stable_sort(p,p+index,compare);//used to sort data according to frequency
    for(i=0;i<index;i++)
      cout<<p[i].data<<" "<<p[i].freq<<" \n";
    
  return 0;
}