 #include <iostream>
using namespace std;
int main()
{
	int t,n,m,i,j,dp[100][100];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(j=0;j<9;j++)
			dp[0][j]=j+1;
		for(i=1;i<=n;i++)
			dp[i][0]=1;
		for(i=1;i<n;i++)
		for(j=1;j<9;j++)
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		cout<<dp[n-1][8]<<"\n";	
	}
}
