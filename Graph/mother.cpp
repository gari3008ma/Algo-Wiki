#include<bits/stdc++.h>
using namespace std;
void dfs(bool visited[],int src,vector<vector<int> > graph)
{
	visited[src]=true;
	for(int i=0;i<graph[src].size();i++)
	{
		if(!visited[graph[src][i]])
		{
			dfs(visited,graph[src][i],graph);
		}
	}
}
int main()
{
	vector<vector<int> > graph;
	int e,u,v,w,i,j,k;
	cin>>v>>e;
	graph.resize(v+1);
	while(e--)
	{
		cin>>k>>w;
		graph[k].push_back(w);
	}
	bool visited[v+1];
    memset(visited,false,sizeof(visited));
	for(i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			dfs(visited,i,graph);
			j=i;
		}
	}
	memset(visited,false,sizeof(visited));
	w=j;
	dfs(visited,j,graph);
	 j=0;
	 for(i=0;i<v;i++)
	 {
	 	if(visited[i]==false)
	 	{
	 		cout<<"False";
	 		j=1;
	 		break;
	 	}
	 }
	 if(j==0)
	 	cout<<"True  "<<w;
	return 0;
}