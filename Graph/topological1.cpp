 #include <iostream>
using namespace std;
class adjlistnode
{
	int v;
	int weight;
public:
	adjlistnode();
	int getv();
	int getw();
};
class Graph
{
	int val;
	list<adjlistnode> *adj;
	void topoutil();
public:
	Graph(int val);
	void addedge(int u,int v);
	void topo();
};
Graph :: Graph(int val)
{
	this->val=val;
	adj = new list<adjlistnode>[val];
}
void Graph :: addedge(int u,int v)
{
	adj[u].push_back(v);
}
void Graph :: topo()
{
				queue<int> q1;
				bool visited[val];
				int i,j;
				for(i=0;i<val;i++)
					visited[i]=false;
				q1.push(2);
				visited[2] = true;
			    list<int> :: iterator it;
				while(!q1.empty())
				{
					cout<<q1.front()<<" ";
					j=q1.front();
					q1.pop();
					
					for(it=adj[j].begin();it!=adj[j].end();it++)
					{
						        if(visited[*it]==false)
						        		{
						        			q1.push(*it);
						        			visited[*it] = true;
						        		}
					}
				}
}