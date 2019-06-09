#include<bits/stdc++.h>
using namespace std;
int dp_sol(int mat[100][100],int n,int i,int j)
{
	if(i<0 || i>=n || j<0 || j>=n)
		return 0;
	if(i==n-1)
		return mat[i][j];
	return mat[i][j]+max(dp_sol(mat,n,i+1,j),dp_sol(mat,n,i,j+1));
}
int dp_sol1(int mat[100][100],int n)
{
	int dp[1000][1000],x,y;
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)
		dp[0][i]=mat[0][i];
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i-1>=0 && i-1<n)
			x=dp[i-1][j];
			if(j-1>=0 && j-1<n)
			y=dp[i][j-1];
			dp[i][j]=mat[i][j]+max(x,y);
		}
	}
	return (*max_element(dp[n-1],dp[n-1]+n));
}
int main()
{
		int n,t,i,j,arr[100][100],index,k;
		cin>>t;
		while(t--)
		{
			cin>>n;
			for(i=0;i<n;i++)
			for(j=0;j<n;j++)			
				cin>>arr[i][j];
			//cin>>index>>k;
			j=INT_MIN;			
			for(i=0;i<n;i++)
				j=max(j,dp_sol(arr,n,0,i));
			cout<<j<<"\n";
			cout<<dp_sol1(arr,n)<<"DP solution";
		}
}
