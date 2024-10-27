 #include <iostream>
using namespace std;
bool bfsutil(vector<vector<pair<int,int> > > graph,int parent[],int n)
{
    bool visited[n+1];
    int i;
    memset(visited,false,sizeof(visited));
    queue<int> q;
    q.push(0);
    visited[0]=true;
    parent[0]=-1;
    vector<vector<int,int> > :: iterator it;
    while(!q.empty())
    {
           int s=q.front();
           q.pop();
           for(i=0;i<graph[s].size();i++)
           {
               if(visited[graph[s][i].first]==false &&(graph[s][i].second)>0)
               {
                   q.push(graph[s][i].first);
                   visited[graph[s][i].first]=true;
                   parent[graph[s][i].first]=s;
               }
           }
    }
    return visited[n-1];
}
int main()
 {
	int t,i,j,n,m,u,v,w;
	cin>>t;
	while(t--)
	{
	    vector<vector<pair<int,int> > > graph;
	    cin>>n>>m;
	    graph.resize(n+1);
	    while(m--)
	    {
	        cin>>u>>v>>w;
	        graph[u-1].push_back(make_pair(v-1,w));
	        graph[v-1].push_back(make_pair(u-1,w));
	    }
	    int parent[n+1];
	    int max_flow=0;
	    while(bfsutil(graph,parent,n))
	    {
	        int path_flow = INT_MAX;
        for (v=n-1; v!=0; v=parent[v])
        {
            u = parent[v];
            for(i=0;i<graph[u].size();i++)
           {
               if(graph[u][i].first==v)
               {
                   path_flow = min(path_flow, graph[u][i].second);
               }
           }
            
        }
        for (v=n-1; v != 0; v=parent[v])
        {
            u = parent[v];
             for(i=0;i<graph[u].size();i++)
           {
               if(graph[u][i].first==v)
               {
                   graph[u][i].second -= path_flow;
                  for(i=0;i<graph[v].size();i++)
           {
               if(graph[v][i].first==u)
               {
                   graph[v][i].second += path_flow;
               }
           }
               }
           }
            
        }
        max_flow += path_flow;
        cout<<"Hello";
	    }
	    cout<<max_flow<<"\n";
	}
	return 0;
}