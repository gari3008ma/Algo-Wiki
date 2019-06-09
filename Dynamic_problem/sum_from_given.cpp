#include<bits/stdc++.h>
using namespace std;
int solution(int n,int m)
{
		int i,j,k,dp[1000][1000];
		memset(dp,0,sizeof(dp));
			dp[0][n+1]=1;
		for(j=n;j>=m;j--)
		for(i=0;i<=n;i++)
			{
				if(j>i)
				dp[i][j]=0;
				else if(i==j)
				dp[i][j]=1;
				else{
					k=i-j>=0? dp[i-j][j]:0;
									
					dp[i][j]=dp[i][j+1]+k;
				}
			}
		return dp[n][m];	
}
int main()
{
	int t,n,m,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<solution(n,m)<<"\n";
	}
}
