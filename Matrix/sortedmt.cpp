 #include <iostream>
using namespace std;
#define INF 10000000
void youngify(int mat[100][100],int i,int j,int n,int m)
{
		int down=(i+1<n)?mat[i+1][j]:INF;
		int right=(j+1<m)?mat[i][j+1]:INF;
		if(down == INF && right==INF)
			return ;
		if(right<down)
		{
			mat[i][j]=right;
			mat[i][j+1]=INF;
			youngify(mat,i,j++,n,m);
		}
		else
		{
			mat[i][j]=down;
			mat[i+1][j]=INF;
			youngify(mat,i++,j,n,m);
		}
}
int minify(int mat[100][100],int n,int m)
{
	int ret=mat[0][0];
	mat[0][0]=INF;
	youngify(mat,0,0,n,m);
	return ret;
}
void printsort(int mat[100][100],int n,int m)
{
	int i;
	for(i=0;i<(n*m);i++)
	{
		cout<<minify(mat,n,m)<<" ";
	}
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
	   printsort(mat,n,m);
	}
}