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

void dfs(int u){
    visited[u] = true;
    cout<<u<<endl;
    // traverse the vector for given node u
    for(int i = 0; i < graph[u].size(); ++i){
        int v = graph[u][i].first; // graph[idx][i] is vector of pairs. 
        int w = graph[u][i].second;
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){

    int n,m,u,v,w;

    cin>>n;
    
    graph.resize(n+1);
    visited.resize(n+1,0);

    cin>>m; // number of edges

    rep(i,m){
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w)); //uncomment this code if the graph is undirected
    }

    dfs(1);
    mst(n);

    return 0;
}