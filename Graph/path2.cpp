 #include <iostream>
using namespace std;
bool dfs(vector<vector<int> > graph,int u,int v,bool visited[])
{
		queue<int> q;
		visited[u]=true;
		q.push(u);
		vector<int> :: iterator it;
		while(!q.empty())
		{
			if(v==q.front())
				return true;
			u=q.front();
			q.pop();
			for(it=graph[u].begin();it!=graph[u].end();it++)
			{
				visited[(*it)]=true;
				q.push((*it));
					dfs(graph,(*it),v,visited);
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
		vector<vector<int> > graph;
		int n,i,e,u,v;
		cin>>n>>e;
		bool p;
		graph.resize(n+1);
		bool visited[n+1];
		while(e--)
		{
			cin>>u>>v;
			graph[u].push_back(v);
		}
        cin>>u>>v;
        memset(visited,false,sizeof(visited));
        if(dfs(graph,u,v,visited))
        	cout<<"YES\n";
        else
        	cout<<"NO\n";
	}

	return 0;
}