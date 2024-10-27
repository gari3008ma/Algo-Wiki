 #include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node* newNode(int data)
{
    struct node* node =(struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return(node);
}
void inorder(struct node *root,int inr[],int * ind)
{
	if(root==NULL)
		return ;
	inorder(root->left,inr,ind);
	inr[(*ind)]=root->data;
	(*ind)++;
	inorder(root->right,inr,ind);
}
void preorder(struct node *root,int pre[],int * ind)
{
	if(root==NULL)
		return ;
	pre[(*ind)]=root->data;
	(*ind)++;
	preorder(root->left,pre,ind);
	preorder(root->right,pre,ind);
}
int main()
{
     struct node *T       = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
    int inr1[1000],inr2[1000],pre[1000],pre1[1000];
            int j=0;
    		inorder(T,inr1,&j);
    		j=0;
    		preorder(T,pre,&j);
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
        j=0;
 		inorder(S,inr2,&j);
 		j=0;
 		preorder(S,pre1,&j);
 		int i;
   for(i=0;i<7;i++)
   	cout<<inr1[i]<<" ";
   cout<<"\n";
   for(i=0;i<7;i++)
   	cout<<pre[i]<<" ";
   cout<<"\n";
   for(i=0;i<4;i++)
   	 cout<<inr2[i]<<" ";
   cout<<"\n";
   for(i=0;i<4;i++)
   	  cout<<pre1[i]<<" ";
	return 0;
}