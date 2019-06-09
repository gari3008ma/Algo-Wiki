#include<bits/stdc++.h>
using namespace std;
int count_way(int n,int m)
{
	int dp[1000][1000],i,j,k;
	memset(dp,0,sizeof(dp));
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(j<i)
				dp[i][j]=0;
			else if(j==1)
				dp[i][j]=j;
			else
			{
				dp[i][j]=dp[i-1][j/2]+dp[i][j-1];
			}
		}
	}
	return dp[n][m];
}
int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<count_way(n,m)<<"\n";
	}
}
