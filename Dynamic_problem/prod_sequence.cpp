 #include <iostream>
using namespace std;
int count(int arr[],int n,int k,int i)
{
		int dp[1000][1000],j;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=k;j++)
			{
				dp[i][j]=dp[i-1][j];
				if(arr[i-1]<j)
				dp[i][j]=1+dp[i][j]+dp[i][j/arr[i-1]];
			}
		}
		return dp[n][k];
}
int main()
{
	int t,n,arr[10000],i,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cin>>k;
		cout<<count(arr,n,k,0)<<"\n";
	}
}
