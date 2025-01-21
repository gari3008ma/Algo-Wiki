 #include <iostream>
using namespace std;
bool isvalid(int i,int j,int n,int m)
{
	return (i>=0 && j>=0 && i<n&& j<m);
}
int count(int mat[100][100],int dp[100][100],int i,int j,int n,int m)
{
	  if(i<0 || j<0 || i>=n || j>=m)
	  	  return 0;
	  if(isvalid(i,j+1,n,m)&& ((mat[i][j+1]==mat[i][j]+1)||(mat[i][j+1]==mat[i][j]-1)))	
	  	  return dp[i][j]=1+count(mat,dp,i,j+1,n,m);
	  if(isvalid(i+1,j,n,m)&&((mat[i+1][j]==mat[i][j]+1)||(mat[i+1][j]==mat[i][j]-1)))
	      return dp[i][j]=1+count(mat,dp,i+1,j,n,m)	;
	  return dp[i][j]=1;
}
int main()
{
	int t,n,i,j,m,mat[100][100];
	cin>>t;
	while(t--)
	{
	       cin>>n>>m;
	       	for(i=0;i<n;i++)
	       	{
	       	   for(j=0;j<m;j++)
	       	      cin>>mat[i][j];
	       	}
	       	int dp[100][100];
	       	memset(dp,0,sizeof(dp));
	       	cout<<count(mat,dp,0,0,n,m)<<"\n";
	}
}