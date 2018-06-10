#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100

struct Node
{
    char key;
    struct Node *left, *right;
};
void storeinorder(struct Node* root,char arr[],int *i)
{
	if(root==NULL)
		{
			arr[*i]='$';
			(*i)++;
			return;
	}
	storeinorder(root->left,arr,i);
	arr[*i]=root->key;
	(*i)++;
	storeinorder(root->right,arr,i);
}
void storepreorder(struct Node* root,char arr[],int *i)
{
	if(root==NULL)
		{
			arr[*i]='$';
			(*i)++;
			return;
		}
	arr[*i]=root->key;
	(*i)++;
	storeinorder(root->left,arr,i);
	
	storeinorder(root->right,arr,i);
}
bool issubtree(struct Node *root,struct Node *root2 )
{
	if(root2==NULL)
		return true;
	if(root==NULL)
		return false;
	char arr1[10000],arr2[10000],ar1[10000],ar2[10000];
	int m=0,n=0;
			storeinorder(root,arr1,&m);
			storeinorder(root2,ar1,&n);
			
			arr1[m]='\0';
			ar1[n]='\0';
			m=0;
			n=0;
			storepreorder(root,arr2,&m);
			storepreorder(root,ar2,&n);
			arr2[m]='\0';
			ar2[n]='\0';
			if(strstr(arr1,ar1)==NULL)
				return false;
			return (strstr(arr2,ar2)!=NULL);
}
Node *newNode(char item)
{
    Node *temp =  new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
int main()
{
    Node *T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    Node *S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');
    S->right->left=newNode('f');
 
    if (issubtree(T, S))
        cout << "Yes: S is a subtree of T";
    else
    cout << "No: S is NOT a subtree of T";
 
    return 0;
}