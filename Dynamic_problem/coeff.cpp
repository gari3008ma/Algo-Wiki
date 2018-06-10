#include<bits/stdc++.h>
using namespace std;
int findcoe(int coef[],int start,int end,int rhs)
{
	int i,j,k;
	int dp[rhs+1];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
		for(i=0;i<end;i++)
		{
			for(j=coef[i];j<=rhs;j++)
			{
				dp[j]+=dp[j-coef[i]];
			}
		}
		return dp[rhs];
}
int main()
{
	int t,n,i,j,coef[1000],rhs;
	cin>>t;
	while(t--)
	{
	   cin>>n>>rhs;
	   for(i=0;i<n;i++)
	   {
	       cin>>coef[i];
	   }
	   cout<<findcoe(coef,0,n,rhs)<<"\n";
	}
}