#include <bits/stdc++.h>
#include <string>
#include <queue>
using namespace std;
struct ListNode
{
    int data;
    ListNode* next;
};
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left, *right;
};
void push(struct ListNode** head_ref, int new_data)
{
    struct ListNode* new_node = new ListNode;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
BinaryTreeNode* newBinaryTreeNode(int data)
{
    BinaryTreeNode *temp = new BinaryTreeNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void convertList2Binary(struct ListNode *head,struct BinaryTreeNode *root)
{
        struct BinaryTreeNode *mp=root;
        struct ListNode *tmp=head;
        queue<struct BinaryTreeNode *> g;
        if(head!=NULL)
         {
                  root= newBinaryTreeNode(tmp->data);
                  g.push(root);
         }
        while(tmp)
        {
                  mp= g.front();
                  g.pop();

                  if(tmp->next!=NULL)
                   {
                         tmp=tmp->next;
                         mp->left=newBinaryTreeNode(tmp->data);
                         g.push(mp->left);
                   }
                   if(tmp->next!=NULL)
                   {
                         tmp=tmp->next;
                         mp->right=newBinaryTreeNode(tmp->data);
                         g.push(mp->right);
                   }
        }


}
void inorderTraversal(BinaryTreeNode* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->data << " ";
        inorderTraversal( root->right );
    }
}
 int main()
{
    struct ListNode* head = NULL;
    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */

    BinaryTreeNode *root;
    convertList2Binary(head, root);

    cout << "Inorder Traversal of the constructed Binary Tree is: \n";
    inorderTraversal(root);
    return 0;
}
