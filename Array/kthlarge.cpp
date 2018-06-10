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
int main()
{
	int t,n,i,arr[100000],count,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(i=0;i<n;i++)
			cin>>arr[i];
		priority_queue<int,vector<int>,greater<int> > qrr;
		count=1;
		for(i=0;i<k;i++)
			qrr.push(arr[i]);
		while(i<n)
		{
			if(qrr.top()<arr[i])
              {
                   qrr.pop();
                   qrr.push(arr[i]);
               }
               i++;
		}
		for(i=0;i<k;i++)
		{
			cout<<qrr.top()<<" ";
			qrr.pop();
		}
		//cout<<p<<"\n";
	}
	return 0;
}