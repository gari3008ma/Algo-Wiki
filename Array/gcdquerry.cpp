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
int gcd(int a,int b)
{
	if(a<b)
		{
			int tmp=a;
			a=b;
			b=tmp;
		}
   if(b==0)
   	 return a;
		return gcd(b,a%b);
}
int getq(int st[],int l,int r,int ind,int n,int ss,int se)
{
	if(l>se ||r<ss)
		return 0;
	if(l<=ss && r>=se)
		return st[ind];
	
	int mid=ss+(se-ss)/2;
	return gcd(getq(st,l,r,2*ind+1,n,ss,mid),getq(st,l,r,2*ind+2,n,mid+1,se));
}
int constructst(int arr[],int ss,int se,int ind,int st[])
{
	if(ss==se)
	{
		st[ind]=arr[ss];
		return st[ind];
	}
	int mid=ss+(se-ss)/2;
	st[ind]=gcd(constructst(arr,ss,mid,2*ind+1,st),constructst(arr,mid+1,se,2*ind+2,st));
	return st[ind];
}
int main()
{
	int t,n,arr[100000],i,l,r;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		cin>>l>>r;

         //length and size of segment tree
		 	int height = (int)(ceil(log2(n)));
   			int size = 2*(int)pow(2, height)-1;
   			int * st = new int[size+1];
   			constructst(arr, 0, n-1, 0,st);
   			for(i=0;i<size;i++)
   				cout<<st[i]<<" ";
   			cout<<"\n";
   			cout<<getq(st,l,r,0,n,0,n-1)<<"\n";
	}
}