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
int minfind(bool availe[10000],int dist[10000],int n)
{
    int i,min=INT_MAX,ind=0;
    for(i=0;i<n;i++)
    {
            if(availe[i] && dist[i] !=INT_MAX &&dist[i]<min)
            {
                min=dist[i];
                ind=i;
               cout<<ind;
            }
    }
    return ind;
}
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
void mst(int n)
{
    int parent[10000],dist[10000],i,k;
    bool availe[10000];
    memset(availe,true,sizeof(availe));
    memset(dist,INT_MAX,sizeof(dist));
    memset(parent,-1,sizeof(parent));
    dist[0]=0;
    parent[0]=0;
    for(i=0;i<n;i++)
    {
         for(int j= 0; j < graph[i].size(); ++j){
        int v = graph[i][j].first; // graph[idx][i] is vector of pairs. 
        int w = graph[i][j].second;
       cout<<i<<" "<<v<<" "<<w<<" ";
    }
    cout<<"\n";
    }
    for(i=0;i<n;i++)
    {
                    k=minfind(availe,dist,n);
                    availe[k]=false;
                cout<<k<<"->   ";
        for(int j = 0; j < graph[k].size(); ++j){
                     int v = graph[k][j].first; // graph[idx][i] is vector of pairs. 
                     int w = graph[k][j].second;
                     cout<<v<<"hello"<<w<<" ";
                      if((availe[v] && dist[v]>w))
                      {
                            dist[v]=w;
                            parent[v]=k;
                            cout<<v<<" ";
                      }
                }
                cout<<"\n";
    }
    for(i=0;i<n;i++)
        cout<<i<<"  "<<parent[i]<<" "<<dist[i]<<" \n";
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
    //dfs(1);
    mst(n);
   graph.clear();
    return 0;
}