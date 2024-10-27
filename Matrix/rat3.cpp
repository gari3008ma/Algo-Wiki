 #include <iostream>
using namespace std;
bool isvalid(int i,int j,int n,int m)
{
	  return (i>=0 && j>=0 && i<n && j<m);
}
void countway(int mat[11][11],int i,int j,int n,int m,string str,bool visited[11][11])
{
	            visited[i][j]=true;
	            if(i==n-1 && j==m-1)
	            	{
	            		cout<<str<<" ";
	            		
	            	}
	            int row[]={1,0,0,-1};
	            int col[]={0,-1,1,0};
	            for(int k=0;k<4;k++)
	            {
	            	if(isvalid(i+row[k],j+col[k],n,m) && mat[i+row[k]][j+col[k]]!=0 && !visited[i+row[k]][j+col[k]])
	            {
	            	     //cout<<str;
	            	     if(k==0)
                         str=str+'D';
                         else if(k==1)
                         str=str+'L';
                         else if(k==2)
                         str=str+'R';
                         else
                         str=str+'U'	;
                         countway(mat,i+row[k],j+col[k],n,m,str,visited);
                         if(!str.empty())
	                         str.erase(str.end()-1);
	            }
	        }
	        visited[i][j]=false;
	        //if(!str.empty())
	        //str.erase(str.end()-1);
	        return ;
}
int main()
{
	int t,n,x,i,sum=1,m,mat[11][11],j;
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
			bool visited[11][11];
			//int count[100][100];
			string str;
			//memset(count,0,sizeof(count));
			memset(visited,false,sizeof(visited));
			countway(mat,0,0,n,n,str,visited);
			cout<<"\n";
	}
	return 0;
}