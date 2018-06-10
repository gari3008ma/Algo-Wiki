#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vi> vvi; 
typedef vector<pii> vpii;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define traverse(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define SIZE 5009

vector< vector< pair<int,int> > > graph;
vector<int> visited;
struct node
{
    int data;
    node *left, *right;
};
/* Helper function to create a new node */
node* newNode(int data)
{
    node* node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
int search(int pre[],int post[],int ss,int se,int x)
{
    int i,j;
    for(i=ss;i<=se;i++)
    {
        if(post[i]==x)
            return i;
    }
}
struct node *constructTreeUtil(int pre[],int post[],int *preind,int ss,int se,int n)
{
    if(ss>se|| se>=n||ss<0 || (*preind)>=n)
        return NULL;
    struct node *root=newNode(pre[(*preind)]);
    (*preind)++;
       if(ss==se)
          return root;
    int index=search(pre,post,ss,se,pre[(*preind)]);
    if(index<=se)
   {
    root->left=constructTreeUtil(pre,post,(preind),ss,index,n);
    root->right=constructTreeUtil(pre,post,(preind),index+1,se,n);
}
    return root;
}
struct node *constructTree (int pre[], int post[], int size)
{
    int preIndex = 0;
    return constructTreeUtil (pre, post, &preIndex, 0, size - 1, size);
}
 
// A utility function to print inorder traversal of a Binary Tree
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
 
// Driver program to test above functions
int main ()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    struct node *root = constructTree(pre, post, size);
 
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
 
    return 0;
}