 #include <iostream>
using namespace std;
void dfs(bool visited[][50],vector<vector<int> > graph,int s,int v)
{
	visited[s][v]=true;
	for(int i=0;i<graph[v].size();i++)
	{
		if(!visited[s][graph[v][i]])
		{
			dfs(visited,graph,s,graph[v][i]);
		}
	}
}
int main()
{
	int v,e,i,j,k,u,w;
	cin>>v>>e;
	vector<vector<int> > graph;
	graph.resize(v+1);
	bool visited[50][50];
	while(e--)
	{
		cin>>w>>u;
		graph[w].push_back(u);
	}
        memset(visited, false, sizeof(visited));
	for(i=0;i<v;i++)
	{
		dfs(visited,graph,i,i);
	}
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(visited[i][j])
				cout<<1<<" ";
			else
				cout<<"0 ";
		}
		cout<<"\n";
	}
	return 0;
}