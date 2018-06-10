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
void rotright(int *rot,int time,int n)
{
	(*rot)=((*rot)-time)%n;
}
void rotleft(int *rot,int time,int n)
{
	(*rot)=((*rot)+time)%n;
}
void getv(int rot,int l,int r,int n,int sum[])
{
	l=(l+(rot)+n)%n;
	r=(r+rot+n)%n;
	if(r>l)
			cout<<sum[r+1]-sum[l]<<"\n";
	else
	       cout<<sum[n-1]+sum[r+1]-sum[l]<<"\n";	
}
int main()
{
	int t,i,n,arr[10000],sum[10000],q,rot,time,a,type,l,r;
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum[0]=0;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			sum[i+1]=sum[i]+arr[i];
		}
		cin>>q;
		rot=0;
        while(q--)
        {
        		cin>>type;
        		if(type==1)
        		{
        			cin>>a;
        			rotright(&rot,a,n);
        		}
        		else if(type==2)
        		{
        			cin>>a;
        			rotleft(&rot,a,n);
        		}
        		else
        		{
        			cin>>l>>r;
        			getv(rot,l,r,n,sum);
        		}

        }
	}
}