#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int val;
	list<int> *adj;
public:
	Graph(int val);
	void addedge(int u,int v);
	void bfs();
};
Graph :: Graph(int val)
{
	this->val=val;
	adj = new list<int>[val];
}
void Graph :: addedge(int u,int v)
{
	adj[u].push_back(v);
}
void Graph :: bfs()
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
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) n";
    g.bfs();
 
    return 0;
}