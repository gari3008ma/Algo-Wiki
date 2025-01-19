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
using namespace std;
struct node
{
	int val;
	int lrang;
	int rrang;
	struct node *left;
	struct node *right;
};
struct node *newnode(int arr[],int ind)
{
	struct node *root=(struct node *)malloc(sizeof(struct node *));
	root->val=arr[ind];
	root->left=NULL;
	root->right=NULL;
	root->lrang=ind;
	root->rrang=ind;
	return root;
}
struct node *newn(int l,int r)
{
	struct node *root=(struct node *)malloc(sizeof(struct node *));
	root->val=0;
	root->left=NULL;
	root->right=NULL;
	root->lrang=l;
	root->rrang=r;
	return root;
}
struct node *makesegment(int arr[],int l,int r,int n)
{
	if(l==r) {
		struct node *nod=newnode(arr,l);
		return nod;
	}
	cout<<"Hello";
	struct node *root = newn(l,r);
	root->left=makesegment(arr,l,(l+r)/2,n);
	root->right=makesegment(arr,((l+r)/2)+1,r,n);
    root->val=root->val+root->right->val+root->left->val;
	return root;
}
void inorder(struct node *root)
{
	  if(root==NULL)
	  	return ;
	  inorder(root->left);
	  cout<<root->val<<" ";
	  inorder(root->right);
}
int main()
{
	int t,n,i,arr[10000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		struct node *root=makesegment(arr,0,n-1,n);
		inorder(root);
	}
	return 0;
}