 #include <iostream>
using namespace std;
int z_o_diff(int arr[100000],int n)
{
	int i,j,k,dp[100000];
	memset(dp,0,sizeof(dp));
	dp[n-1]=1;
	for(i=n-2;i>=0;i--)
	{
		if(arr[i]*arr[i+1]<0)
		dp[i]=dp[i+1]+1;
		else
		dp[i]=1;
	}
	
	return (*(max_element(dp,dp+n)));
}

int main()
{
	int t,n,arr[100000],i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		cout<<z_o_diff(arr,n);
	}
}
