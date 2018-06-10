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

vector< vector<int> > graph;
vector<int> visited;

void dfs(int u,int d,int s,int *c,bool recstck[]){
    visited[u] = true;
    recstck[u]=true;
    vector<int> :: iterator it;
    for( it = graph[u].begin(); it!=graph[u].end(); ++it){
        
        if(!visited[(*it)]){
            dfs((*it),d,s,c,recstck);
        }
        if((*it)==d && recstck[s]==true)
            (*c)++;
    }
    recstck[u]=false;
}

int main(){

    int n,m,u,v,w,s,d,c=0;
    cin>>n;
    graph.resize(n+1);
    visited.resize(n+1,0);
    cin>>m; 
    rep(i,m){
              cin>>u>>v;
              graph[u].push_back(v);
    }
    cin>>s>>d;
    bool recstck[10000];
    memset(recstck,false,sizeof(recstck));
    dfs(s,s,d,&c,recstck);
     cout<<c<<"\n";

    return 0;
}