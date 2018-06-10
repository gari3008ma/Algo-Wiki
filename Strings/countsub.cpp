#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    n=str.length();
	    int dp[n+1];
	    int last[300];
	    memset(dp,1,sizeof(dp));
	    memset(last,-1,sizeof(last));
	    dp[0]=1;
	    for(i=1;i<=n;i++)
	    {
	    	dp[i]=dp[i-1]*2;
	    	//cout<<dp[i-1]<<"\n";
	    	if(last[str[i-1]]!=-1)
	    	{
	    		dp[i]=dp[i]-dp[last[str[i-1]]];
	    	}
	    	last[str[i-1]]=i-1;
	    }
	    cout<<dp[n]<<"\n";
	}
}