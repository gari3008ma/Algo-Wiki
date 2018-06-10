#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vi> vvi; 
typedef vector<pii> vpii;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define traverse(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define SIZE 5009

vector< pair<int,pii> > graph;
vector<int> visited;
int find(int a,int parent[],int rank[])
{
	if(parent[a]==a)
		return a;
	return find(parent[a],parent,rank);
}
bool union(int a,int b,int parent[],int rank[])
{
	int x=find(a,parent,rank);
	int y=find(b,parent,rank);
	if(x==y)
		  return true;
	else
	{
		if(rank[x]>rank[y])
		{
			parent[y]=x;
			
		}
		else if(rank[x]<rank[y])
		{
			parent[x]=y;
			
		}
		if(rank[x]==rank[y])
		{
			parent[y]=x;
			rank[x]++;
		}
		return false;
	}	
}
int main()
{
	int n,m,u,v,w;
    cin>>n;   
    graph.resize(n+1);
    visited.resize(n+1,0);
    cin>>m; // number of edges
    int sum=0;
    rep(i,m){
        cin>>u>>v>>w;
        graph.push_back(u,make_pair(v,w));
        graph.push_back(v,make_pair(u,w)); //uncomment this code if the graph is undirected
    }
    sort(graph.begin(),graph.end());
    vector< pair<int,pii> > :: iterator it=graph.begin();
    int parent[100],rank[100];
    for(i=0;i<=n;i++)
    {
    	parent[i]=i;
    	rank[i]=0;
    }
   for(i=0;i<m;i++)
   {
   	   u=graph[i].first;
   	   v=graph[i].first.first;
   	   w=graph[i].first.second;
   	   if(union(u,v,parent,rank))
   	   {
   	   	   cout<<"added edge"<<u<<" "<<v<<"\n";
   	   	   sum=sum+w;
   	   }
   }
   cout<<sum<<"\n";
}