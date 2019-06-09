#include<bits/stdc++.h>
using namespace std;
int CountSegment(int a,int b,int c,int n)
{
		int dp[100000],i,j,k;
		memset(dp,-1,sizeof(dp));
		dp[0]=1;
		for(i=0;i<=n;i++)
		{
			if(dp[i]!=-1){
				if(i+a<=n)
				{
					dp[i+a]=max(dp[i]+1,dp[i+a]);
				}
				if(i+b<=n)
				{
					dp[i+b]=max(dp[i]+1,dp[i+b]);
				}
				if(i+c<=n)
				{
					dp[i+c]=max(dp[i]+1,dp[i+c]);
				}			
			}
		}
		return dp[n];
}
int main()
{
	int t,n,i,arr[10000],a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b>>c;
		cout<<CountSegment(n,a,b,c)<<"\n";
	}
}
