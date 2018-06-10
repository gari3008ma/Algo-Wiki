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
int  bfs(int n)
{
           queue<int> bfsq;
           bfsq.push(1);
           int u,v,w,count=0,i,j,pre=0;
           bool visited[10000],color[10000];
           memset(visited,false,sizeof(visited));
           visited[u]=true;
           for(i=1;i<=n;i++)
           {
                for(v=0;v<graph[i].size();v++)
              {
                cout<<i<<" "<<graph[i][v].first<<" ";
              }
              cout<<"\n";
           }
          memset(color,-1,sizeof(color));
           color[1]=0;
           while(!bfsq.empty())
           {
              u=bfsq.front();
              //
              pre=color[u];
              bfsq.pop();
              for(v=0;v<graph[u].size();v++)
              {
                  j=graph[u][v].first;
                  if(j==u)
                    return 0;
                  if(!visited[j])
                  {
                    visited[j]=true;
                    bfsq.push(j);
                    color[j]=1-pre;
                  }
                  else if(color[j]==color[u])
                      return 0;
              }
              //pre=1-pre;
             // count++;
           }
           return 1;
}
int main(){

    int n,m,u,v,w,t;
    cin>>t;
    while(t--){
    cin>>n;
    graph.resize(n+1);
    visited.resize(n+1,0);
    cin>>m; // number of edges

    rep(i,m){
        cin>>u>>v;
        w=1;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w)); //uncomment this code if the graph is undirected
    }
        if( bfs(n))
          cout<<"No Suspicious bugs found!";
        else
          cout<<"Suspicious bugs found!";
         graph.clear();
    }
    return 0;
}