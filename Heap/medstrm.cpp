 #include <iostream>
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
int signum(int a,int b)
{
    if(a > b)
      return 1;
     else if(b > a)
       return -1;
     else
       return 0;
}
int getmedian(int val,int & median,priority_queue<int> &l,priority_queue<int ,vector<int>,greater<int> > &r)
{
    int s=signum(l.size(),r.size());
    switch(s)
    {
        case 1:
        if(val < median)
        {
            r.push(l.top());
            l.pop();
            l.push(val);
        }
        else
        {
            r.push(val);
        }
        median=(l.top()+r.top())/2;
        break;
        case 0:
        if(val < median)
        {
            l.push(val);
            median=l.top();
        }
        else
        {
            r.push(val);
            median =r.top();
        }
        break;
        case -1:
        if(val < median)
        {
            l.push(val);
        }
        else
        {
            l.push(r.top());
            r.pop();
            r.push(val);
        }
        median=(l.top()+r.top())/2;
        break;
    }
    return median;
}
int main()
 {
	int n,ele,m;
	priority_queue<int> *l;
	priority_queue<int ,vector<int>,greater<int> > *r;
		priority_queue<int> maxheap;
	priority_queue<int ,vector<int>,greater<int> > minheap;
	l=&maxheap;
	r=&minheap;
	cin>>n;
	m=0;
	while(n--)
	{
	    cin>>ele;
	    cout<<getmedian(ele,m,*l,*r)<<"\n";
	}
	return 0;
}