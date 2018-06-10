#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,arr[100][100],p,p1,q1,q,i,j;
	cin>>t;
	while(t--)
	{
    cin>>n>>m;
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<m;j++)
    		  cin>>arr[i][j];
    	}
    	cin>>p>>q>>p1>>q1;
    	int aux[100][100];
    	for(i=0;i<m;i++)
    		aux[0][i]=arr[0][i];
    	for(i=1;i<n;i++)
    	{
    		for(j=0;j<m;j++)
    		{
    				aux[i][j]=arr[i][j]+aux[i-1][j];
    		}
    	}
    	for(i=0;i<n;i++)
    	{
    		for(j=1;j<m;j++)
    		{
    			aux[i][j]+=aux[i][j-1];
    		}
    	}
    	int res=aux[p1][q1];
    	if(p>0)
    		res=res-aux[p-1][q1];
    	if(q>0)
    		res=res-aux[p1][q-1];
    	if(p>0 && q>0)
    		res=res+aux[p-1][q-1];
    	cout<<res<<"\n";
	}
	return 0;
}