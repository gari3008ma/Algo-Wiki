 #include <iostream>
using namespace std;
int max_len(int arr[10000],int n,int index,int k)
{
    int dp[1000][1000],i,j;
    memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)
	if(arr[0]<arr[i])
		dp[0][i]=arr[0]+arr[i];
	else
		dp[0][i]=arr[i];

    for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
			{
				if(arr[j]>arr[i] && j>i)
				{
						if(dp[i-1][i]+arr[j]>dp[i-1][j])
							dp[i][j]=dp[i-1][i]+arr[j];
						else
							dp[i][j]=dp[i-1][j];
				}
				else
						dp[i][j]=dp[i-1][j];
			}
	}
	return dp[index][k];
}
int main()
{
		int n,t,i,j,arr[100000],index,k;
		cin>>t;
		while(t--)
		{
			cin>>n;
			for(i=0;i<n;i++)
				cin>>arr[i];
			cin>>index>>k;
			cout<<max_len(arr,n,index,k)<<"\n";
		}
}
