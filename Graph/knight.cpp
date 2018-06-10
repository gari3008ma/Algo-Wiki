#include<bits/stdc++.h>
using namespace std;
void dfsutil(int x,int y,int n,float *pos,float *neg,int count,int k)
{
	count++;
	if(count>k)
		return ;
	if(count<=k &&(x<0 || y<0 || x>=n || y>=n))
		  {
		  	(*neg)++;
		  	return;
		  }
	if((*neg)==0.0)
	{
		(*pos)++;
		  return;
	}	  
	for(int row=x-1;row<=x+1 ;row++)
	{
		for(int col=y-1;col<=y+1 ;col++)
		{
				dfsutil(row,col,n,pos,neg,count,k);
		}
	}
}
int main()
{
	int t,n,x,y,count,k;
	float pos,neg;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		 cin>>x>>y;
		 pos=0.0;
		 neg=0.0;
		 count=0;
		 dfsutil(x,y,n,&pos,&neg,count,k);
		 cout<<(pos/(pos+neg))<<"\n";
	}
}