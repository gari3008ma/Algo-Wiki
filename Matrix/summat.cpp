#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,j,m,mat[100][100],s,k;
	cin>>t;
	while(t--)
	{
	   cin>>n>>m;
	   for(i=0;i<n;i++)
	   {
	      for(j=0;j<m;j++)
	         cin>>mat[i][j];
	   }
	   cin>>k;
	   int sum[100][100];
	   s=0;k=0;
	   for(i=0;i<m;i++)
	   {
	   		s=0;
	   	   for(j=0;j<k;j++)
	   	   	  s+=mat[j][i];
	   	   	sum[0][i]=s;
	   	   	for(j=1;j<n-k+1;j++)
	   	   	{
	   	   		s=s-mat[j-1][i]+mat[j+k-1][i];
	   	   		sum[j][i]=s;
	   	   	}
	   }
	   for(i=0;i<n-k+1;i++)
	   {
	   			s=0;
	   	   for(j=0;j<k;j++)
	   	   	  s=s+sum[i][j];
	   	     cout<<s<<" ";
	   	   	for(j=1;j<m-k+1;j++)
	   	   	{
	   	   		s=s-sum[i][j-1]+sum[i][j+k-1];
	   	   		cout<<s<<" ";
	   	   	}
	   	   	cout<<"\n";
	   }
	}
}
