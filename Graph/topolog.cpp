 #include <iostream>
using namespace std;
class Graph
{
	int val;
	list<int> *adj;
	void dfsutil(int v, bool visited[],stack<int>& s1);
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
void Graph :: dfsutil(int v,bool visited[],stack<int> &s1)
{
	visited[v]=true;
	list<int> ::iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		       if(!visited[*it])
		       {
		       	   dfsutil(*it,visited,s1);
		       }
	}
	s1.push(v);
}
void Graph :: DFS()
{
	bool visited[val];
	stack<int> s1;
	char p;
	for(int i=0;i<val;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<val;i++)
	{
		if(visited[i]==false)
	    dfsutil(i,visited,s1);
    }
    while(!s1.empty())
    {
    	p=s1.top()+'a';
    	cout<<p<<" ";
    	s1.pop();
    }
}
int main()
{
	int t,k,N;
	cin>>t;
	while(t--)
	{
		cin>>N>>k;
        string dict[N];
	Graph g(k);
   int i,j;
   for(i=0;i<N;i++)
   	  cin>> dict[i];
   for(i=0;i<N-1;i++)
   {
       string s1=dict[i];
       string s2=dict[i+1];
       for(j=0;j<s1.length();j++)
       {
           if(s1[j]!=s2[j])
           {
                      g.addedge(s1[j]-'a',s2[j]-'a');
                      break;
           }
       }
   }
   g.DFS();
}
    return 0;
}