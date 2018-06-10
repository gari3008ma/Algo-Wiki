#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,row,col,n,m,t;
	cin>>t;
	while(t--)
	{
	     int mat[50][50],row[50],col[50],sum=0,delr,delc;
	     cin>>n>>m;
	     for(i=0;i<n;i++)
	     {
	        for(j=0;j<m;j++)
	           cin>>mat[i][j];
	     }
	     cin>>delr>>delc;
	     memset(row,0,sizeof(row));
	     memset(col,0,sizeof(col));
	     for(i=0;i<n;i++)
	     {
	        for(j=0;j<m;j++)
	        {
	        	sum=sum+mat[i][j];
	        	row[i]+=mat[i][j];
	        	col[j]+=mat[i][j];
	        }
	     }
	     sum=sum-row[delr]-col[delc]+mat[delr][delc];
	     cout<<sum<<"\n";
	}
}