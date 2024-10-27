 #include <iostream>
using namespace std;
struct node
{
     struct node *left,*right;
     int data;
};
int height(struct node *root)
{
      if(root==NULL)
          return 0;
      else
      {
                int l=height(root->left);
                int r=height(root->right);
                if(l>r)
                    return l+1;
                else
                     return r+1;
      }
}
void sum(struct node *root,int l )
{
          if(root==NULL)
              return 0;
          if(l==1)
            s=s+root->data;
          else if(l>1)
          {
                sum(root>left,l-1);
                sum(root->right,l-1);
          }
}
void klevel(struct node *root,int k)
{
     int i,h;
     h=height(root);
     if(h<k)
     cout<<"0\n";
     else
     suml(root,k);
}
int main()
{

    klevel(root,k)
}
