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
class minheap
{
	int *harr;//pointer to array contaning elements of heap
	int capacity;//Maximum capacity of heap
	int heap_size;//current size of heap
public:
	//constructor 
	minheap(int x);
	// to heapify a subtree with root at given index
	void minheapify(int index);//1 operation
	int parent(int i)//2 operation
	{          
		return (i-1)/2;
    }		
	int leftchild(int i)//3 operation
	{         
		return (2*i+1);
     }		
	int rightchild(int i)//4 operation
	{       
	    return (2*i+2);
	}	
	int extractmin();//5 operation
	// Decreases key value of key at index i to new_val


    void decreaseKey(int i, int new_val);//6 operation
     // Returns the minimum key (key at root) from min heap

    int getMin() { return harr[0]; }//7 operation
 
    void insertkey(int x);//8 operation

    void  deleteKey(int x);//9 operation

};
  minheap :: minheap(int x)
  {
  	           capacity=x;
  	           heap_size=0;
  	           harr= new int[x];
  }
  void minheap :: insertkey(int x)
  {
  	  if(heap_size == capacity)
  	  {
  	  	    printf("Overflow : couldn't insert key\n");
  	  	     return;
  	  }
  			heap_size++;
  			int tmp;
  			int i = heap_size - 1;
  			harr[i] = x;
         while(harr[parent(i)] > harr[i] && i>=0)
         {
         	       tmp= harr[parent(i)];
         	       harr[parent(i)]=harr[i];
         	       harr[i]=tmp;
         	       i=parent(i);
         }
  }
  void minheap :: minheapify(int i)
  {
  	      if(i >= heap_size)
  	      	  return ;
        int l = leftchild(i);
        int r = rightchild(i);
        int smallest=i;
        if( l < heap_size && harr[l]<harr[smallest])
        	smallest=l;
        if(r < heap_size && harr[r]<harr[smallest])
        	smallest=r;
        if(smallest!=i)
        {
        	int tmp=harr[smallest];
        	harr[smallest]=harr[i];
         	       harr[i]=tmp;
        	minheapify(smallest);
        }
  }
  int minheap:: extractmin()
  {
  	  if(heap_size==0)
  	  	return INT_MAX;
  	  if(heap_size==1)
  	  {
  	  					int tmp=harr[0];
  	  					heap_size--;
  	  					return tmp;
  	  }
  	  int tmp=harr[0];
  	  harr[0]=harr[heap_size-1];
  	  heap_size--;
  	  minheapify(0);
  	  return tmp;
  
  }
  void minheap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    int tmp;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       tmp= harr[parent(i)];
         	       harr[parent(i)]=harr[i];
         	       harr[i]=tmp;
       i = parent(i);
    }
}
  void minheap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractmin();
}

  int main()
{
    minheap h(11);
    h.insertkey(3);
    h.insertkey(2);
    h.deleteKey(1);
    h.insertkey(15);
    h.insertkey(5);
    h.insertkey(4);
    h.insertkey(45);
    cout << h.extractmin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}