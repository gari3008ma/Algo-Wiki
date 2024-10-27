 #include <iostream>
using namespace std;

int dp_sol(int n)
{
	if(n==0 || n==1)
		return 1;
	
	return 1+dp_sol(n/2);
}
int sol(int n)
{
	int i,dp[100000],j;
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	dp[1]=0;
	for(i=2;i<=n;i++)
	{
		dp[i]=1+dp[i/2];
	}
        return dp[n];
}
int correct(int n)
{
	int i=2,dp[100000],j;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	dp[1]=2;
	do{
		dp[i]=dp[i-1]+dp[i-2];
	}while(dp[i++]<=n);
        return i-2;
}
int main()
{
		int n,t,a,b,c,k;
		cin>>t;
		while(t--)
		{
			cin>>n;
			cout<<correct(n)<<"\n";
		}
}
