#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int val;
	list<int> *adj;
	void dfsutil(int v, bool visited[]);
public:
	Graph(int val);
	void addedge(int u,int v);
	void DFS();
};
Graph :: Graph(int val)
{
	this->val=val;
	adj= new list<int> [val];
}
void Graph :: addedge(int u,int v)
{
	      adj[u].push_back(v);
}
void Graph :: dfsutil(int v,bool visited[])
{
	visited[v]=true;
	cout<<v<<" ";
	list<int> ::iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		       if(!visited[*it])
		       {
		       	   dfsutil(*it,visited);
		       }
	}
}
void Graph :: DFS()
{
	bool visited[val];
	for(int i=0;i<val;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<val;i++)
	{
		if(visited[i]==false)
	    dfsutil(i,visited);
    }
}
int main()
{
			Graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
 
    cout << "Following is Depth First Traversaln";
    g.DFS();
 
    return 0;
}