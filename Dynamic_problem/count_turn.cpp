 #include <iostream>
using namespace std;
int sum(int arr[10000],int n,int low,int high,int turn,int dp[1000][1000])
{
	if(low==high)
		return arr[low]*turn;
	if(dp[low][high]!=0)
		return dp[low][high];
	dp[low][high]=max(arr[low]*turn+sum(arr,n,low+1,high,turn+1,dp),arr[high]*turn+sum(arr,n,low,high-1,turn+1,dp));
	return dp[low][high];
}
int main()
{
	int t,n,m,i,j,arr[10000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		int dp[1000][1000];
		memset(dp,0,sizeof(dp));
		cout<<sum(arr,n,0,n-1,1,dp)<<"\n";
	}
}
