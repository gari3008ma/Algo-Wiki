#include<iostream>
using namespace std;
#define N 20
bool issafe(int Mcell[N][N],bool visited[N][N],int i,int j,int n,int m)
{
    return (i>=0 && j>=0 && i<n && j<m &&  !visited[i][j] && Mcell[i][j]==3);
}
void findtwo(int Mcell[N][N],bool visited[N][N],int i,int j,int n,int m,bool *isp)
{
    int r[]={-1,1,0,0};
    int c[]={0,0,-1,1};
    visited[i][j]=true;
    if(Mcell[i][j]==2)
    {
        (*isp)=true;
        cout<<(*isp);
    }
        for(int b=0;b<4;b++)
        {
            if(issafe(Mcell,visited,i+r[b],j+c[b],n,m))
            {
            	cout<<"HEKO";
                findtwo(Mcell,visited,i,j,n,m,isp);
            }
        }
}
int main()
{
	int t,n,i,j;
	int Mcell[N][N];
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            cin>>Mcell[i][j];
	        }
	    }
	    bool isp=false;
	    bool visited[N][N]={{false}};
	    for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	    if(!visited[i][j]&& (Mcell[i][j]==0||Mcell[i][j]==3))
	    findtwo(Mcell,visited,i,j,n,n,&isp);
	    if(isp==true)
	    cout<<"1\n";
	    else
	    cout<<"0\n";
	}
	return 0;
}