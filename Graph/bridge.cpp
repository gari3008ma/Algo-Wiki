
 #include <iostream>
using namespace std;
#define NIL -1
void dfs(vector<vector<int> > graph,int u,bool visited[],int parent[],int low[],int disc[])
{
	static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    vector<int>::iterator i;
    for (i = graph[u].begin(); i != graph[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
 
        // If v is not visited yet, then recur for it
        if (!visited[v])
        {
            parent[v] = u;
            dfs(graph,v,visited, parent,low, disc);
            low[u]  = min(low[u], low[v]);
            if (low[v] > disc[u])
              cout << u <<" " << v << endl;
        }
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
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
			graph[v].push_back(u);
		}
        cin>>u;
        memset(visited,false,sizeof(visited));
        memset(parent,-1,sizeof(parent));
        memset(low,0,sizeof(low));
        memset(disc,0,sizeof(disc));
        for(i=0;i<n;i++)
        	if(visited[i]==false)
        dfs(graph,u,visited,parent,low,disc);
        
	}

	return 0;
}