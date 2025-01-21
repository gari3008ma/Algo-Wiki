 #include <iostream>
using namespace std;
int dp[50][50];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
bool isvalid(int i,int j,int n,int m)
{
   return (i>=0 && j>=0 && i<n && j<m);
}
bool iscor(char b,char c)
{
	return (b-c==1);
}
int countutil(char mat[50][50],int i,int j,int n,int m,char s)
{
	if(!isvalid(i,j,n,m)||(!iscor(mat[i][j],s)))
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int ans=0;
	for(int k=0;k<8;k++)
		ans=max(ans,1+countutil(mat,i+dx[k],j+dy[k],n,m,mat[i][j]));
	return dp[i][j]=ans;
}
int count(char mat[50][50],int n,int m,char s)
{
	memset(dp,-1,sizeof(dp));
	int i,j,k,ans=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mat[i][j]==s)
			{
					for(k=0;k<8;k++)
					{
							ans=max(ans,1+countutil(mat,i+dx[k],j+dy[k],n,m,s));
					}
			}
		}
	}
	return ans;
}
int main()
{
	int t,i,j,n,m;
	char mat[50][50];
	cin>>t;
	while(t--)
	{
	   cin>>n>>m;
	   for(i=0;i<n;i++)
	   {
	       for(j=0;j<m;j++)
	          cin>>mat[i][j];
	   }
	   char val;
	   cin>>val;
	   cout<<count(mat,n,m,val)<<"\n";
	}
}