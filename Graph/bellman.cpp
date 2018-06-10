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
vector< vector< pair<int,int> > > graph;
vector<int> visited;
 //It first calculates the shortest distances which have at-most one edge in the path. 
//Then, it calculates shortest paths with at-nost 2 edges, and so on. After the i-th iteration of outer loop, the shortest paths with at most i edges are calculated. 
//There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times.
// The idea is, assuming that there is no negative weight cycle, if we have calculated shortest paths with at most i edges,
// then an iteration over all edges guarantees to give shortest path with at-most (i+1) edges 
void bella(int n,int m)
{
	int i,dis[100000],j,k,u,w,v;
	memset(dis,INT_MAX,sizeof(dis));
	dis[0]=0;
	vector< pair<int,int> > :: iterator it;
		for(j=0;j<n;j++)
		{
			for(it=graph[j].begin();it!=graph[j].end();it++)
			{
				v=(*it).first;
				w=(*it).second;
					if(dis[j]!=INT_MAX && dis[v]>dis[j]+w)
					{
						dis[v]=dis[j]+w;
					}
			}
		}
	
	for(i=0;i<n;i++)
			cout<<i<<dis[i]<<"\n";
	           for(j=0;j<n;j++)
		{
			for(it=graph[j].begin();it!=graph[j].end();it++)
			{
				v=(*it).first;
				w=(*it).second;
					if(dis[j]!=INT_MAX && dis[v]>dis[j]+w)
					{
						cout<<"Negative Cycle\n";
						break;
					}
			}
		}
		for(i=0;i<n;i++)
			cout<<i<<dis[i]<<"\n";
}
int main()
{
	int n,m,u,v,w,i,j;
	cin>>n;
    
    graph.resize(n+1);
    visited.resize(n+1,0);

    cin>>m; // number of edges

    rep(i,m){
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w)); //uncomment this code if the graph is undirected
    }
    vector< pair<int,int> > :: iterator it;
     for(j=0;j<n;j++)
		{
			for(it=graph[j].begin();it!=graph[j].end();it++)
			{
				v=(*it).first;
				w=(*it).second;
			    cout<<j<<" "<<v<<" "<<w<<"\n";
			}
		}
    bella(n,m);
}