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
typedef pair<int,int> ipair;
struct disjoint
{
     int n,*parent,*rank;
     disjoint(int n)
     {
         this->n=n;//impo
         parent= new int[n+1];//impo
         rank = new int[n+1];
         for(int i=0;i<n;i++)
         {
         	parent[i]=i;
         	rank[i]=0;
         }
     }
     int find(int u)
     {
        if(u!=parent[u])
        {
            parent[u]=find(parent[u]);
        }
          return parent[u];
     }
     void addedge(int u,int v)
     {
          int parx=find(u);
          int pary=find(v);
          if(parx!=pary)
          {
                   if(rank[parx] > rank[pary])
                     {
                              parent[pary]=parx;
                     }
                    else
                    {
                               parent[parx]=pary;  
                    }     
                    if(rank[parx]==rank[pary])
                    {
                              rank[parx]++;
                    }
          }
     }
};
struct graph
{
	int v,e;
	vector<pair<int,ipair> > edge;//impo
    graph(int V,int E)
    {
          this->v=V;
          this->e=E;
    }
    void addedges(int u,int v,int w)
     {
           edge.push_back(make_pair(w,make_pair(u,v)));//impo
     }
     int MST();
};
int graph :: MST()
{
        sort(edge.begin(),edge.end());
        int count=0,w,x,y,sum=0;
        pair<int,int> p;
        vector<pair<int,ipair> > :: iterator it = edge.begin();
        disjoint ds(v);
         for(;it!=edge.end();it++)
         {
         	   w = it->first;
         	   p = it->second;
         	   cout<<w<<"\n";
               x=ds.find(p.first);
               y=ds.find(p.second);
              if(x!=y)
              {
              	cout<<"Added edge is :"<<x<<" "<<y<<"\n";
              	sum=sum+w;
              	ds.addedge(x,y);
              	//count++;
              }
         }
         return sum;
}


int main()
{
	int u,v,e,x,y,w;
	cin>>v>>e;
	graph Graph(v,e);
	cout<<"Initialised the graph \n";
	while(e--)
	{
		cin>>x>>y>>w;
		Graph.addedges(x,y,w);
	}
	x=Graph.MST();
	cout<<"Made the Graph\n";
	cout<<"MST weight is "<<x;
}
