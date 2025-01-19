#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif 
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
void dijikstra(int n,int src)
{
         priority_queue<pll,vector<pll>,greater<pll> > gqueue;
         vector<ll> dist(n,INT_MAX);
        // vector<ll> visited(n,false);
         gqueue.push(make_pair(0,src));
         dist[src]=0;
         int u,i,j;
         vector< pair<int,int> > :: iterator it;
         while(!gqueue.empty())
         {
                u=gqueue.top().second;
                cout<<u<<" \n";
                gqueue.pop();
               // The first vertex in pair is the minimum distance vertex, extract it from priority queue.
        		// vertex label is stored in second of pair (it
        		// has to be done this way to keep the vertices
        		// sorted distance (distance must be first item in pair)
                for(it=graph[u].begin();it!=graph[u].end();it++)
                {
                	i=(*it).first;//node value
                	j=(*it).second;///weight
                	if(dist[i]>dist[u]+j)
                	{
                		dist[i]=dist[u]+j;
                		cout<<i<<" "<<dist[i]<<" ";
                		gqueue.push(make_pair(dist[i],i));
                	}
                }
         }
         for(i=0;i<n;i++)
         	cout<<i<<" "<<dist[i]<<"\n";
}
int main()
{
	int t,n,e,u,v,w;
	cin>>t;
	while(t--)
	{
		cin>>n>>e;
		graph.resize(n+1);
		while(e--)
		{
			cin>>u>>v>>w;
			graph[u].push_back(make_pair(v,w));
			graph[v].push_back(make_pair(u,w));
		}
		 dijikstra(n,0);
		graph.clear();
	}
}