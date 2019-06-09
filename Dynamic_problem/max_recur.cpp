#include<bits/stdc++.h>
using namespace std;
int break_recur(int n)
{
    if(n==0||n==1)
	return n;
	return max(break_recur(n/3)+break_recur(n/2)+break_recur(n/4),n/3+n/4+n/2);
}
int dp_sol(int n)
{
	int i,j,dp[10000];
	memset(dp,0,sizeof(dp));
	dp[1]=1;
	for(i=2;i<=n;i++)
	{
		dp[i]=max(dp[i/3]+dp[i/2]+dp[i/4],i/2+i/4+i/3);
	}
	return dp[n];
}
int main()
{
		int n,t,i,j,arr[100000],index,k;
		cin>>t;
		while(t--)
		{
			cin>>n;
			//for(i=0;i<n;i++)
			//	cin>>arr[i];
			//cin>>index>>k;
			cout<<dp_sol(n)<<"\n";
		}
}
