 #include <iostream>
using namespace std;
bool isvalid(int i,int j,int row,int col)
{
	return (i>=0 && j>=0 && i<row && j<col);
}
int dp[50][50][1000];
int count(int mat[50][50],int i,int j,int row,int col,int k)
{
			if(!isvalid(i,j,row,col))
				return 0;
			if(i==0 && j==0)
				return (k==mat[i][j]);
			if(dp[i][j][k]!=-1)
				return dp[i][j][k];
			 dp[i][j][k]=(count(mat,i-1,j,row,col,k-mat[i][j])+count(mat,i,j-1,row,col,k-mat[i][j]));
   			return dp[i][j][k];
}
int main()
{
		int t,n,i,j,m,mat[50][50],k;
		cin>>t;
		while(t--)
		{
			cin>>n>>m;
			int c=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
					 cin>>mat[i][j];
			}
			cin>>k;
			memset(dp,-1,sizeof(dp));
					c=count(mat,n-1,m-1,n,m,k);
						
			cout<<c<<"\n";
		}	
}