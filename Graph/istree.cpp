#include<bits/stdc++.h>
using namespace std;
bool iscycle(vector<vector<int> > graph,bool visited[],int v,int parent)
{
	visited[v]=true;
	vector<int> :: iterator it;
	for(it=graph[v].begin();it!=graph[v].end();it++)
	{
		if(!visited[(*it)])
		{
			if(iscycle(graph,visited,(*it),v))
				return true;
		}
		else if((*it)!=parent)
			return true;
	}
	return false;
}
bool istree(vector<vector<int> > graph,int n)
{
	bool visited[n+1];
	int i,j;
   if(iscycle(graph,visited,0,-1))
   	return false;
   for(i=0;i<n;i++)
   {
   	if(visited[i]==false)
   		return false;
   }
   return true;
}
int main()
{
	int g;
	cin>>g;
	while(g--)
	{
		vector<vector<int> > graph;
	int t,e,u,v,n,i;
      cin>>n>>e;
      graph.resize(n+1);
      while(e--)
      {
      		cin>>u>>v;
      		graph[u].push_back(v);
      		graph[v].push_back(u);
      }
      if(istree(graph,n))
      	cout<<"Yes\n";
      else 
      	cout<<"No\n";
  }
	return 0;
}