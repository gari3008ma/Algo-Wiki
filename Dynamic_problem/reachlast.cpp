#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,i,j,mat[100][100],dp[100][100];
	cin>>t;
	while(t--)
	{
	   cin>>n>>m;
	   for(i=0;i<n;i++)
	   {
	      for(j=0;j<m;j++)
	         cin>>mat[i][j];
	   }
	   int dp[n+1][m+1];
	   memset(dp,0,sizeof(dp));
	   dp[0][0]=mat[0][0];
	   for(i=1;i<n;i++)
	     dp[i][0]=mat[i][0]+dp[i-1][0];
	   for(i=1;i<n;i++)
	   {
	     for(j=1;j<i+1 && j<m;j++)
	     {
	        dp[i][j]=mat[i][j]+max(dp[i-1][j-1],dp[i-1][j]);
	     }
	   }  
	   int res=0;
	   for(i=0;i<m;i++)
	   {
	   	if(res<dp[n-1][i])
	   		res=dp[n-1][i];
	   }
	   cout<<res<<"\n";
	}
}