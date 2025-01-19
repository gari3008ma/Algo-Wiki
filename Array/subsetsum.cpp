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
bool findindex(int arr[],int sum,queue<int> q,int n)
{
	int i,j,start=0,current=arr[0];
	q.push(0);
	map<int,bool> mp;
	for(i=0;i<=n;i++)
	{
		while(current> sum && start<(i-1))
		{
			current=current - arr[start];
			q.pop();
			start++;
		}
		if(current ==sum)
			break;
		if(i<n)
		{
			current=current+arr[i];
		    q.push(i);
	    }
	}
	while(!q.empty())
	{
		   mp[q.front()]=true;
		   q.pop();
	}
	start=0;
	for(i=0;i<n;i++)
	{
		if(mp[i]!=true)
		start=start+arr[i];
	}
	if(start==sum)
	{
		return 1;
	}
}
int main()
{
	int n,arr[1000],i,j,sum=0;
	queue<int> q;
	cin>>n;
	for(i=0;i<n;i++)
		{
			cin>>arr[i];
			sum=sum+arr[i];
		}
	if(sum%2!=0)
	{
		cout<<"NO\n";
	}
	else
	{
		if(findindex(arr,sum/2,q,n))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}