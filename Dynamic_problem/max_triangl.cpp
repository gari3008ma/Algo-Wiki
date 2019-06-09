#include<bits/stdc++.h>
using namespace std;
int dp_sol(vector<vector<int> > mat)
{
	int i,j,k,n=mat.size(),dp[100000];
	for(i=0;i<mat[n-1].size();i++)
		dp[i]=mat[n-1][i];
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<mat[i+1].size()-1;j++)
			dp[j]=min(dp[j],dp[j+1])+mat[i][j];	
	}
	return dp[0];
}
int main()
{
	int t,n,i,j;
	vector<vector<int> > mat;
	vector<vector<int> > A{ { 2 }, 
                            { 3, 9 }, 
                            { 1, 6, 7 } }; 
	cout<<dp_sol(A)<<"\n";
	
}
