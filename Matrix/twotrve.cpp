#include<bits/stdc++.h>

using namespace std;

bool isvalid(int x,int y,int n,int m)
{
		return (x>=0 && y>=0 && x<n && y<m);
}

int max(int a,int b,int c)
{
	a  =  a>b?a:b;
    a  =  a>c?a:c;
    return a;
}
int sumr(int x1,int y1,int x2,int y2,int mat[100][100],int n,int m,bool visited[100][100])
{
	if(!isvalid(x1,y1,n,m))
		   return INT_MIN;
	if(!isvalid(x2,y2,n,m))
		   return INT_MIN;
	if(x1==x2 && y1==y2)
		return INT_MIN;
	if(x1==n-1 && y1==0 &&x2==n-1 && y2==m-1)
		   return mat[x1][y1]+mat[x2][y2];
	if(x1>=n-1 || x2>=n-1)	
		   return INT_MIN;
	int row[]={1,1,1};
	int col[]={-1,0,1};
	int sum1[3];
	//visited[x1][y1]=true;
	//visited[x2][y2]=true;
		for(int i=0;i<3;i++)
		{
			sum1[i]=mat[x1][y1]+mat[x2][y2]+max(sumr(x1+row[i],y1+col[i],x2+row[0],y2+col[0],mat,n,m,visited),sumr(x1+row[i],y1+col[i],x2+row[1],y2+col[1],mat,n,m,visited),sumr(x1+row[i],y1+col[i],x2+row[2],y2+col[2],mat,n,m,visited));
		}
		return max(sum1[0],sum1[1],sum1[2]);
}
int main()
{
	     int t,n,mat[100][100],m,i,j;
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
	     		int y=sumr(0,0,0,m-1,mat,n,m,visited);
	     		cout<<y;
	     }
}