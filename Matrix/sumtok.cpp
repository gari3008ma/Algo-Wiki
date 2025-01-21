 #include <iostream>
using namespace std;
bool isvalid(int i,int j,int row,int col)
{
	return (i>=0 && j>=0 && i<row && j<col);
}
bool count(int mat[50][50],int i,int j,int row,int col,int k)
{
			if(k==0)
				return true;
			if(!isvalid(i,j,row,col))
				return false;
			
			
			 return (count(mat,i+1,j,row,col,k-mat[i][j])||count(mat,i,j+1,row,col,k-mat[i][j]));

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
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(count(mat,i,j,n,m,k))
						c++;
				}
			}
			cout<<c<<"\n";
		}	
}