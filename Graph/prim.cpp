#include<bits/stdc++.h>
using namespace std;
int minval(bool inc[],int dist[],int v)
{
	int i,index,min=INT_MAX;
	for ( i = 0; i < v; ++i)
	{
		if(dist[i]<min && inc[i]==false)
		{
			        min=dist[i];
			        index=i;
		}
	}
	return index;
}
int main()
{
		  int v,e,i,j,k,f,s,l;
	      vector<vector<pair<int,int> > > graph;
	      cin>>v>>e;
	      graph.resize(v+2);
	      int par[100],dist[100];
	      bool inc[100];
	      for(i=0;i<v;i++)
	      {
	      	    dist[i]=INT_MAX;
	      	    par[i]=-1;
	      	    inc[i]=false;
	      }
	      dist[0]=0;
	  
	      
	       vector< pair<int,int> > :: iterator it;
	      while(e--)
	      {
	      	     cin>>j>>k>>i;
	      	     graph[j-1].push_back(make_pair(k-1,i));
	      	     graph[k-1].push_back(make_pair(j-1,i));
	      }
	      for(j=0;j<v-1;j++)
	      {
	      		i=minval(inc,dist,v);
	      		inc[i]=true;
	      		//cout<<i<<"\n";
	      		for(it=graph[i].begin();it!=graph[i].end();it++)
	      		{
                       f=(*it).first;
                       s=(*it).second;
                      // cout<<f<<s<<" ";
                       if(dist[f]>s && inc[f]==false)
                       {
                       			dist[f]=s;
                       			par[f]=i;
                      }
	      		}
	      		
	      }
	      int sum=0;
	      for(i=0;i<v;i++)
	      	{
	      	//cout<<par[i]<<" "<<i<<" "<<dist[i]<<"\n";
	      		sum=sum+dist[i];
	      	}
	      	cout<<sum<<"\n";
}