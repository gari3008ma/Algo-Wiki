 #include <iostream>
using namespace std;
int dp[100][100][2];
bool isvalid(int i,int j,int n,int m)
{
	return (i>=0 && j>=0 && i<n && j<m);
}
int count(char mat[100][100],int i,int j,int n,int m,int dir)
{
	   if(!isvalid(i,j,n,m) || mat[i][j]=='#')
	   	return 0;
	   if(dp[i][j][dir]!=-1)
	   	  return dp[i][j][dir];
	  dp[i][j][dir]=(mat[i][j]=='E')?0:1;
	   	if(dir==1)
	   	dp[i][j][dir]+=max(count(mat,i,j+1,n,m,1),count(mat,i+1,j,n,m,0));
	   if(dir==0)
	   dp[i][j][dir]+= max(count(mat,i+1,j,n,m,1),count(mat,i,j-1,n,m,0));
	return dp[i][j][dir];
}
int main()
{
	int t,n,m,i,j;
	char mat[100][100];
	cin>>t;
	while(t--)
	{
			cin>>n>>m;
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
					   cin>>mat[i][j];
			}
			memset(dp,-1,sizeof(dp));
				cout<<count(mat,0,0,n,m,1)<<"\n";
	}
	return 0;
}