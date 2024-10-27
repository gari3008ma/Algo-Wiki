 #include <iostream>
using namespace std;
bool isvalid(int i,int j,int n,int m)
{
	  return (i>=0 && j>=0 && i<n && j<m);
}
void countway(int mat[100][100],int i,int j,int n,int m,bool visited[100][100],int count[100][100])
{
	            //visited[i][j]=true;
	            count[i][j]+=1;
	            int row[4]={0,1};
	            int col[4]={1,0};	
	            //if(i==n-1 && j==m-1)
	              // return ; 	
	    for(int k=0;k<2;k++)
	    {
	    	    if(mat[i+row[k]][j+col[k]]==0 && isvalid(i+row[k],j+col[k],n,m) )
	    	    {
	    	    	               
	    	    					countway(mat,i+row[k],j+col[k],n,m,visited,count);
	    	    					cout<<i<<" "<<j<<"\n";
	    	    }
	    }  
	    return ;	
}
int main()
{
	int t,n,x,i,sum=1,m,mat[100][100],j;
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
			bool visited[100][100];
			int count[100][100];
			memset(count,0,sizeof(count));
			memset(visited,false,sizeof(visited));
			countway(mat,0,0,n,m,visited,count);
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					cout<<count[i][j]<<" ";
				}
				cout<<"\n";
			}
	}
	return 0;
}