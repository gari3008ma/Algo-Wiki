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
void dfs(vector<int> graph[], int ind,bool visited[],stack<int>& st)
{
    visited[ind]=true;
    vector<int> :: iterator it;
    for(it=graph[ind].begin();it!=graph[ind].end();it++)
    {
        if(!visited[(*it)])
           dfs(graph,(*it),visited,st);
    }
    st.push(ind);
}
int *topoSort(vector<int> graph[], int N)
{
    stack<int> st;
    bool visited[N+1];
    int i,j,arr[2*N+1];
    for(i=0;i<=N;i++)
       visited[i]=false;
    for(i=0;i<N;i++)
    {
        if(visited[i]==false)
        {
            dfs(graph,i,visited,st);
        }
    }
    i=0;
    arr[0]=0;
   while(!st.empty())
    {
        arr[i]=st.top();
        i++;
       cout<<st.top();
        st.pop();
    }//
    //reverse(arr,arr+i);
  return arr;
}
int main()
{
	int n,i,j,e,u,v;
	cin>>n>>e;
	vector<int>  graph[n+1];
	while(e--)
	{
			cin>>u>>v;
			graph[u].push_back(v);
	}
	int *arr=topoSort(graph,n);
}