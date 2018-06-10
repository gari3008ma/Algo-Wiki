#include<bits/stdc++.h>
using namespace std;
int min(int a,int b,int c)
{
	if(a>b)
		return(b>c?c:b);
	else
		return (a>c?c:a);
}
int main()
{
	int t,n,i,j,m,mat[100][100],sum[100][100];
	cin>>t;
	while(t--)
	{
	   cin>>n>>m;
	   int max_sum=INT_MIN,max_i=0,max_j=0;
	   for(i=0;i<n;i++)
	   {
	     for(j=0;j<m;j++)
	     {
	          cin>>mat[i][j];
	     }
	   }
	   for(i=0;i<n;i++)
	   	sum[i][0]=mat[i][0];
	   for(i=0;i<m;i++)
	   	sum[0][i]=mat[0][i];
	   for(i=1;i<n;i++)
	   {
	   	for(j=1;j<m;j++)
	   	{
	   		if(mat[i][j]==1)
	   		{
	   			sum[i][j]=min(sum[i-1][j-1],sum[i-1][j],sum[i][j-1])+1;
	   		}
	   		else
	   			sum[i][j]=0;
	   		if(sum[i][j]>max_sum)
	   		{
	   			max_sum=sum[i][j];
	   			max_i=i;
	   			max_j=j;
	   		}
	   	}
	   }
	   cout<<max_sum<<" "<<max_i<<" "<<max_j;
	   for(i=max_i-max_sum+1;i<=max_i;i++)
	   {
	   	  for(j=max_j+1-max_sum;j<=max_j;j++)
	   	  	  cout<<mat[i][j]<<" ";
	   	  	cout<<"\n";
	   }
	   
	}
}