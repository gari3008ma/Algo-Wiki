 #include <iostream>
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
#include<stdlib.h> 
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