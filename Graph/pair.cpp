#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int val;
    list<int> *adj;
    void dfsutil(int i,bool visited[],int *count);
    public:
    Graph(int val);
    void addedge(int u,int v);
    int dfs();
};
Graph ::  Graph(int val)
{
    this->val=val;
    adj = new list<int>[val+1];
}
void Graph :: addedge(int u,int v)
{
     adj[u].push_back(v);
}
int Graph:: dfs()
{
    bool visited[val];
    int count=0;
    for(int i=0;i<=val;i++)
       visited[i]=false;
    for(int i=1;i<=val;i++)
    {
        if(!visited[i])
        {
             cout<<"hello\n";
            dfsutil(i,visited,&count);
        }
    }
    return count;
}
void Graph:: dfsutil(int i,bool visited[],int *count)
{
    visited[i]=true;
    list<int> :: iterator it;
    for(it=adj[i].begin();it!=adj[i].end();it++)
    {
        cout<<"hello"<<i<<"\n";
          if(!visited[*it])
		       {
		           if(abs(i-(*it))%2==0)
		           {
                    cout<<(*count)<<" ";
		               (*count)++;
		           }
		       	   dfsutil(*it,visited,count);
		       }
    }
}
int main()
 {
	int t,n,u,v;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    Graph g(n);
	    n=n-1;
	    while(n--)
	    {
	        cin>>u>>v;
	        g.addedge(u,v);
	    }
	    cout<<g.dfs()<<"\n";
	}
	return 0;
}