#include<bits/stdc++.h>
using namespace std;
#define NIL -1
void dfs(vector<vector<int> > graph,int u,bool visited[],int parent[],int low[],int disc[])
{
	visited[u]=true;
	static int t=0;
	disc[u]=t+1;
	low[u]=t+1;
	t++;
	int children=0;
	vector<int> :: iterator it;
	for(it=graph[u].begin();it!=graph[u].end();it++)
	{
		if(!visited[(*it)])
		{
			children++;
			parent[(*it)]=u;
			dfs(graph,(*it),visited,parent,low,disc);
			low[u]=min(low[(*it)],low[u]);
			if(parent[u]==NIL && children >1)
				cout<<u<<" ";
			if(parent[u]!=NIL && low[(*it)]>disc[u])
				cout<<u<<" ";
		}
		else if((*it)!=parent[u])
		{
			low[u]=min(low[u],disc[(*it)]);
		}
	}
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
		bool visited[n+1];
		while(e--)
		{
			cin>>u>>v;
			graph[u].push_back(v);
		}
        cin>>u;
        memset(visited,false,sizeof(visited));
        memset(parent,-1,sizeof(parent));
        memset(low,0,sizeof(low));
        memset(disc,0,sizeof(disc));
        dfs(graph,u,visited,parent,low,disc);
        
	}

	return 0;
}