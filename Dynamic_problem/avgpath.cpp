#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j,k,mat[100][100],t;
	cin>>t;
	while(t--)
	{
	     cin>>n>>m;
	     for(i=0;i<n;i++)
	     {
	        for(j=0;j<m;j++)
	            cin>>mat[i][j];
	     }
	     int dp[100][100];
	     memset(dp,0,sizeof(dp));
	     dp[0][0]=mat[0][0];
	     for(i=1;i<n;i++)
	     dp[i][0]=dp[i-1][0]+mat[i][0];
	     for(j=1;j<m;j++)
	     dp[0][j]=dp[0][j-1]+mat[0][j];
	     for(i=1;i<n;i++)
	     {
	        for(j=1;j<=m;j++)
	        {
	             dp[i][j]=max(dp[i-1][j],dp[i][j-1])+mat[i][j];
	        }
	     }
	     int res=(double)dp[n-1][m-1]/(2*n-1);
	     cout<<res<<"\n";
	}
}