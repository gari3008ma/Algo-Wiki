 #include <iostream>
using namespace std;
struct nodes* newNode(int data)
{
    struct nodes *temp = new struct nodes;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}node;
int sum(node *head,int l,int k,int r)
{
      if(head==NULL)
         return 0;
       if(l==k)
         {
             return head->data;
         }
       r=r +   sum(head->left,l+1,k,r);
       r= r+ sum(head->right,l+1,k,r);
          return r;
}

int main()
{
    int t,n,i;
    struct nodes *root = new struct nodes;
    cin>>t;
     root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    while(t--)
    {
        cout<<sum(root,1,2,0)<<"\n";
    }
}
