#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,j,mat[100][100],k;
	cin>>t;
	while(t--)
	{
	   cin>>n;
	   for(i=0;i<n;i++)
	   {
	     for(j=0;j<n;j++)
	     {
	         cin>>mat[i][j];
	     }
	   }
	   bool itr=true;
	   k=0;
	   while(k<n)
	   {
	      if(itr)
	      {
	      		for(i=0;i<n;i++)
	      		cout<<mat[k][i]<<" ";
	      		cout<<"\n";
	      		itr=false;
	      		k++;
	      }
	      else
	      {
	      		for(i=n-1;i>=0;i--)
	      		  cout<<mat[k][i]<<" ";
	      		  cout<<"\n";
	      		  itr=true;
	      		  k++;
	      }
	   }
	}
}