 #include <iostream>
using namespace std;
class Graph
{
	int v;
	list<int> *adj;
	bool dfsutil(bool visited[],bool stackutil[],int x);
	public:
	Graph(int x);
	void addedge(int u ,int v);
	bool dfs(int x);
};
Graph :: Graph(int x)
{
	this->v=x;
	adj=new list<int>[x];
}
void Graph :: addedge(int u,int v)
{
	adj[u].push_back(v);
}
bool Graph :: dfsutil(bool visited[],bool stackutil[],int x)
{
	visited[x]=true;
	stackutil[x]=true;
	cout<<x<<" ";
	list<int> :: iterator it;
	for(it=adj[x].begin();it!=adj[x].end();it++)
	{
		      if(!visited[*it] && dfsutil(visited,stackutil ,*it))
	                    return true;
	         if(stackutil[*it])
	         	return true;
	}
	stackutil[x]=false;
	return false;
} 
bool Graph :: dfs(int x)
{
	  bool visited[100]={false};
	  bool stackutil[100]={false};
	  int i;
	  for(i=0;i<v;i++)
	  if(dfsutil(visited,stackutil,i))
	  	return true;
    return false;
}
int main()
{
	int i,n,u,v;
	cin>>n;
	Graph g(n);
	for(i=0;i<n;i++)
	{
		cin>>u>>v;
		g.addedge(u,v);
	}
	if(g.dfs(0))
		cout<<"Contain Cycle\n";
	else
		cout<<"Don't contain cycle\n";
}
