#include<bits/stdc++.h>
using namespace std;
int dp_sol(vector<vector<int> > mat,int n,int m)
{
	int i,j,k,dp[100000];
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<=i;j++)
		{
			mat[i][j]+=max(mat[i+1][j],mat[i+1][j+1]);
		}
	}
		return mat[0][0];
}
int main()
{
	int t,n,i,j;
	vector<vector<int> > mat;
	vector<vector<int> > A{  {1, 0, 0}, 
                      {4, 8, 0}, 
                      {1, 5, 3} }; 
	cout<<dp_sol(A,2,2)<<"\n";
	
}
