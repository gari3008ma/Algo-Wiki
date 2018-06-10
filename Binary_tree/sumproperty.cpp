bool issum(struct Node *root)
{
      if(root==NULL)
         return 1;
      if(root==NULL ||(root->left==NULL && root->right==NULL))
         return 1;
      else
      {
            if(root->left!=NULL)
               int l=root->left->data;
            if(root->right!=NULL)
                int r=root->right->data;
            return((root->data==l+r)&&issum(root->left)&&issum(root->right)) ;
      }
}
