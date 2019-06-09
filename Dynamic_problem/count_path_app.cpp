#include<bits/stdc++.h>
using namespace std;
int count_p(char mat[1000][1000],int i,int j,int n,int m,int dp[1000][1000])
{
		if(i<0 && j<0 && i>n && j>m)
			return 0;
		if(dp[i][j])
			return dp[i][j];
		if(mat[i][j]=='#')
			return 1;
		if(mat[0][0]==0)
		dp[0][0]=1;
		for(i=1;i<n;i++)
			if(dp[i][j]=='.')
			dp[i][0]=dp[i-1][0];
		for(j=1;j<m;j++)
			if(dp[0][j]=='.')
			dp[0][j]=dp[0][j-1];
		for(i=1;i<n;i++)
		{
			for(j=1;j<m;j++)
			{
				if(mat[i][j]=='.')
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
				//cout<<mat[i][j]<<" value of its dp is"<<dp[i][j]<<"\n";
			}
		}
			return dp[n-1][m-1];
}

int main()
{
		int t,n,m,i,j,k,dp[1000][1000];
		char mat[1000][1000];
		cin>>t;
		while(t--)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>mat[i][j];
			}
		}
		memset(dp,0,sizeof(dp));
		cout<<count_p(mat,0,0,n,m,dp)<<"\n";
	}
}
