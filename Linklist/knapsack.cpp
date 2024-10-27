 #include <iostream>
using namespace std;
int min(int a,int b)
{
	return (a>b?b:a);
}
int knap(int val[],int wt[],int n,int w)
{
	if(n==0 || w<=0)
		return 0;
	int dp[n+1][w+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(wt[i-1]<j)
			{
					dp[i][j]=min(val[i-1] + dp[i-1][j-wt[i-1]]  , dp[i-1][j]);
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return (dp[n][w]);
}
int main()
{
	int t,n,val[100],wt[100],w,i;
	cin>>t;
	while(t--)
	{
			cin>>n>>w;
			for(i=0;i<n;i++)
				cin>>val[i];
			for(i=0;i<n;i++)
				cin>>wt[i];
			cout<<knap(val,wt,n,w)<<"\n";
	}
}