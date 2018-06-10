#include<bits/stdc++.h>
using namespace std;
bool safe(int i,int j,int n,int m)
{
	   return (i>=0 && j>=0 && i<n && j<m);
}
int countone(int mat[100][100],bool visited[100][100],int i,int j,int n,int m)
{
	visited[i][j]=true;
	int count=0;
	int row[]={-1,-1,-1,0,0,1,1,1};
	int col[]={-1,0,1,-1,1,-1,0,1};
	for(int k=0;k<8;i++)
	{
		   if(safe(i+row[k],j+col[k],n,m)&&(!visited[i+row[k]][j+col[k]] )&& mat[i+row[k]][j+col[k]])
		   {
		   	       count = 1+ countone(mat,visited,i+row[k],j+col[k],n,m);
		   	       cout<<count<<"";
		   }
	}
	return count;
}
int main()
{
				int t,n,i,j,m,mat[100][100],count,max,p;
				cin>>t;
				while(t--)
				{
					    cin>>n>>m;
					    for(i=0;i<n;i++)
					    {
					    	    for(j=0;j<m;j++)
					    	    {
					    	    	cin>>mat[i][j];
					    	    }
					    }
					    count = 0;
					    bool visited[100][100];
					    max = INT_MIN;
					    memset(visited,false,sizeof(visited));
					    cout<<"hello";
					    for(i=0;i<n;i++)
					    {
					    	    for(j=0;j<m;j++)
					    	    {
					    	    	cout<<"hello";
					    	    	   if(mat[i][j] &&(!visited[i][j]))
					    	    	   {
					    	    	   				p=countone(mat,visited,i,j,n,m);
					    	    	   				if(p>max)
					    	    	   					max=p;
					    	    	   				count++;
					    	    	   				cout<<"hello";
					    	    	   }
					    	    }
					    }
					    cout<<count<<" "<<max<<"\n";
				}
				return 0;
}