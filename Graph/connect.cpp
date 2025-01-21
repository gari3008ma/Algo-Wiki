 #include <iostream>
using namespace std;
void dfs(vector<vector<int> > graph,int u,bool visited[],int * ind)
{
	visited[u]=true;
	(*ind)++;
	vector<int> :: iterator it;
	for(it=graph[u].begin();it!=graph[u].end();it++)
	{
		if(!visited[(*it)])
		{
			dfs(graph,(*it),visited,ind);
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
		bool p;
		graph.resize(n+1);
		bool visited[n+1];
		while(e--)
		{
			cin>>u>>v;
			graph[u].push_back(v);
		}
        cin>>u;
        memset(visited,false,sizeof(visited));
        e=0;
        dfs(graph,u,visited,&e);
        if(e==n)
        	cout<<"Yes\n";
        else
        	cout<<"No\n";
        vector<int> :: iterator it;
        g.resize(n+1);
     	for(i=0;i<n;i++)
     	{
     		for(it=graph[i].begin();it!=graph[i].end();it++)
     		{
     			g[(*it)].push_back(i);
     		}
     	}
        e=0;
         memset(visited,false,sizeof(visited));
        dfs(g,u,visited,&e);
        if(e==n)
        	cout<<"Yes\n";
        else
        	cout<<"No\n";
	}

	return 0;
}