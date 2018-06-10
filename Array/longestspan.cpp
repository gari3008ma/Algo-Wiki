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
	int t,i,n,arr[100000],brr[100000],sum1,sum2;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>brr[i];
		}
		map<int,int> mp;
		sum1=0;
		sum2=0;
		for(i=0;i<n;i++)
		{
				sum1=sum1+arr[i];
				sum2=sum2+brr[i];
				mp[sum1-sum2]++;
		}
	}
}