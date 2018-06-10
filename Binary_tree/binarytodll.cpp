#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void doublelist(struct node *root,struct node **head)
{
          if(root==NULL)
                return ;
          struct node *pre=NULL;
          doublelist(root->left,head);
           if(pre==NULL)
                 *head=root;
           else
        {
                root->left=pre;
                pre->right=root;
        }
        pre=root;
        doublelist(root->right,head);
}
struct node* newNode(int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return(tmp);
}
int main()
{
    struct node *root  = newNode(6);
    root->left         = newNode(3);
    root->right        = newNode(3);
    struct node *head=NULL;
    doublelist(root,&head);
       while(root!=NULL)
      {
              printf("%d ",root->data);
              root=root->right;
      }
    getchar();
    return 0;
}
