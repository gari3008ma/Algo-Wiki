#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	int lrang;
	int rrang;
	struct node *left;
	struct node *right;
};
struct node *newnode(int arr[],int ind)
{
	struct node *root=(struct node *)malloc(sizeof(struct node *));
	root->val=arr[ind];
	root->left=NULL;
	root->right=NULL;
	root->lrang=ind;
	root->rrang=ind;
	return root;
}
struct node *newn(int l,int r)
{
	struct node *root=(struct node *)malloc(sizeof(struct node *));
	root->val=0;
	root->left=NULL;
	root->right=NULL;
	root->lrang=l;
	root->rrang=r;
	return root;
}
struct node *makesegment(int arr[],int l,int r,int n)
{
	if(l==r)
	{
		struct node *nod=newnode(arr,l);
		return nod;
	}
	cout<<"Hello";
	struct node *root = newn(l,r);
	root->left=makesegment(arr,l,(l+r)/2,n);
	root->right=makesegment(arr,((l+r)/2)+1,r,n);
    root->val=root->val+root->right->val+root->left->val;
	return root;
}
void inorder(struct node *root)
{
	  if(root==NULL)
	  	return ;
	  inorder(root->left);
	  cout<<root->val<<" ";
	  inorder(root->right);
}
int main()
{
	int t,n,i,arr[10000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		struct node *root=makesegment(arr,0,n-1,n);
		inorder(root);
	}
	return 0;
}