#include<bits/stdc++.h>
using namespace std;
int max_three_con(int arr[10000],int n)
{
    int dp[100000],i,j,k;
    memset(dp,0,sizeof(dp));
	if(n>=1)
	dp[0]=arr[0];
	if(n>=2)
	dp[1]=arr[0]+arr[1];
	if(n>=3)
	dp[2]=max(dp[1],max(arr[0]+arr[2],arr[2]+arr[1]));
	for(i=3;i<n;i++)
	dp[i]=max(dp[i-1],max(dp[i-2]+arr[i],dp[i-3]+dp[i-1]+arr[i]));
	return dp[n-1];
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
			//cin>>index>>k;
			cout<<max_three_con(arr,n)<<"\n";
		}
}
