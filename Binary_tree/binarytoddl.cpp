#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
void extractleaflist(struct Node *root,struct Node *p,struct Node *n)
{
                         if(root==NULL)
                            return ;
                if(root->left==NULL && root->right==NULL)
                {
                            struct Node *mp;
                            mp=(struct Node *)malloc(sizeof(struct Node));
                            mp->data=root->data;
                            mp->left=p;
                            mp->right=n;
                            p=mp;
                }
                extractleaflist(root->left,p,n);
                extractleaflist(root->right,p,n);
}
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
void print(struct Node *root)
{
    if (root != NULL)
    {
         print(root->left);
         printf("%d ",root->data);
         print(root->right);
    }
}
void printList(struct Node *head)
{
     while (head)
     {
         printf("%d ", head->data);
         head = head->right;
     }
}
int main()
{
     struct Node *head = NULL;
     struct Node *gi = NULL;
     struct Node *u=NULL;
     struct Node *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->right = newNode(6);
     root->left->left->left = newNode(7);
     root->left->left->right = newNode(8);
     root->right->right->left = newNode(9);
     root->right->right->right = newNode(10);

     printf("Inorder Trvaersal of given Tree is:\n");
     print(root);

             extractleaflist(root, head,gi);

             while(head!=NULL)
             {
                u=head;
                head=head->left;
                cout<<head->data<<" \n";
             }

     printf("\nExtracted Double Linked list is:\n");
     printList(u);

     printf("\nInorder traversal of modified tree is:\n");
     print(root);
     return 0;
}
