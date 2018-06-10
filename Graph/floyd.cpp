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
int main()
{
	int t,n,i,j,k;
	int graph[1000][1000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cin>>graph[i][j];
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(graph[i][j]+graph[j][k]<graph[i][k])
						graph[i][k]=graph[i][j]+graph[j][k];
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout<<graph[i][j]<<" ";
			cout<<"\n";
		}
	}
}