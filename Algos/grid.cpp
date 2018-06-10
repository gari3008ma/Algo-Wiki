#include<bits/stdc++.h>
using namespace std;
bool isvalid(int x,int y)
{
	return (x>=0 && y>=0 && x<100 && y<100);
}
int step(bool visited[100][100],int a,int b,int a1,int b1)
{
	        if(visited[a1][b1]==true)
	           return 0;
	        if(a==a1 && b==b1)
	        	return 0;
	        visited[a][b]=true;  
	        int row[]={-1,-1,-1,0,0,1,1,1};
	        int col[]={-1,0,1,-1,1,-1,0,1};
	        int i,count=0;
	        for(i=0;i<8;i++)
	        {
	              if(isvalid(a+row[i],b+col[i]) && !visited[a+row[i]][b+col[i]])
	              {
	                    count= 1 + step(visited,a+row[i],b+col[i],a1,b1);
	              }
	        }
	        return count;
}
int main()
{
    int t,i,j=0,n,m,n1,m1;
    bool visited[100][100];
    memset(visited,false,sizeof(visited));
    cin>>t;
    cin>>n>>m;
    for(i=1;i<t;i++)
    {
      cin>>n1>>m1;
      j=j+max(abs(n1-n),abs(m1-m));
      //cout<<j<<"\n";
      n=n1;
      m=m1;
    }
    cout<<j;
	return 0;
}
