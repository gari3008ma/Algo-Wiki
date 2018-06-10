#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,j,n,n1;
	string str,ptr;
	cin>>t;
	while(t--)
	{
	     cin>>str>>ptr;
	     n=str.length();
	     n1=ptr.length();
	     int dp[n+1][n1+1];
	     bool b;
	     for(i=0;i<=n;i++)
	     {
	     		b=i&1;
	     		for(j=0;j<=n1;j++)
	     		{
	     			if(i==0 || j==0)
	     			{
	     				dp[b][j]=0;
	     			}
	     			else if(str[i-1]==ptr[j-1])
	     			{
	     				dp[b][j]=dp[1-b][j-1]+1;
	     			}
	     			else
	     			{
	     				dp[b][j]=max(dp[1-b][j],dp[b][j-1]);
	     			}
	     		}
	     }
	     cout<<dp[b][n1]<<"\n";
	}
}