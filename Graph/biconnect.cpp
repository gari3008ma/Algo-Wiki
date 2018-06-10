#include<bits/stdc++.h>
using namespace std;
#define NIL -1
bool dfs(vector<vector<int> > graph,int u,bool visited[],int parent[],int low[],int disc[])
{
	visited[u]=true;
	static int t=0;
	low[u]=t+1;
	disc[u]=t+1;
	int child=0;
	t++;
	vector<int> :: iterator it;
	for(it=graph[u].begin();it!=graph[u].end();it++)
	{
		int v=(*it);
		//cout<<child<<" ";
		if(!visited[v])
		{
				parent[v]=u;
				child++;
				if(dfs(graph,v,visited,parent,low,disc))
					return true;
				low[u]=min(low[u],low[v]);
				if(parent[u]==NIL && child >1)
					return true;
				if(parent[u]!=NIL && low[v]>=disc[u])
					return true;
		}
		else if(v!=parent[u])
		{
			low[u]=min(low[u],disc[v]);
		}
	}
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<vector<int> > graph,g;
		int n,i,e,u,v;
		cin>>n>>e;
		int parent[n+1],low[n+1],disc[n+1];
		graph.resize(n+1);
		bool *visited= new bool[n+1];
		while(e--)
		{
			cin>>u>>v;
			graph[u].push_back(v);
		}
        memset(visited,false,sizeof(visited));
        memset(parent,-1,sizeof(parent));
        memset(low,0,sizeof(low));
        memset(disc,0,sizeof(disc));
        if(dfs(graph,0,visited,parent,low,disc))
        cout<<"Articulated point present\n";

        for(i=0;i<n;i++)
        	if(visited[i]==false)
               cout<<"Notconnected \n";
           cout<<"\n";
           
	}

	return 0;
}