 void path(TreeNode *A,int B,vector<vector<int> > &arr,vector<int> line,int sum)
 {
        if(A==NULL)
           return;
           line.push_back(A->val);
       sum=sum+A->val;
       if(A->left==NULL && A->right==NULL)
       {
           if(sum==B)
       {
           arr.push_back(line);
           line.pop_back();
       }
       return;
       }
       path(A->left,B,arr,line,sum);
       path(A->right,B,arr,line,sum);
       line.pop_back();
 }
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
      vector <vector<int> > arr;
      vector<int> brr;
      int sum=0;
      path(A,B,arr,brr,sum);
      return arr;
}
