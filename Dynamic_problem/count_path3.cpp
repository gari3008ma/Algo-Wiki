#include<bits/stdc++.h>
using namespace std;
int count_path(int n,int m)
{
	int dp[1000];
	int i,j,k;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(i=0;i<n;i++)
	for(j=1;j<m;j++)
	  dp[j]=dp[j]+dp[j-1];
	return dp[m-1];
}
int main()
{
	int t,n,m,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<count_path(n,m)<<"\n";
	}
}
