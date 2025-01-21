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
typedef vector<pll> vpll;
typedef vector<vpii > vvpii;
typedef vector<vpll > vvpll;
typedef vector<string> vs;

#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define traverse(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define SIZE 10009
#define INF 10000000000

struct node{
	node *left,*right;
	int data;
} ;

void PrintArray(int array[],int len){
	rep(i,len)
		cout<<array[i]<<" ";
	cout<<endl;
}
void PrintPath(node * root,int path[],int pathLen){
	if(root){
		path[pathLen++] = root->data;
		if(root->left || root->right){
			PrintPath(root->left,path,pathLen);
			PrintPath(root->right,path,pathLen);
		} else{ // leaf node
			PrintArray(path,pathLen);
		}
	}
}

node * newNode(int x){
	node * tmp = new node();
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->data = x;
	return tmp;
}


void Level(node * root,int depth){
	if(!root)
		return;
	if(depth == 1)
		cout<<root->data<<" ";
	else{
		Level(root->left, depth - 1);
		Level(root->right,depth - 1);
	}
}


void LevelTraverse(node * root){
	reps(i,1,4){
		Level(root,i);
		cout<<endl;
	}
}
void LevelOrder(node *root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node * tmp = q.front();
		q.pop();
		cout<<tmp->data<<" ";
		if(tmp->left)
			q.push(tmp->left);
		if(tmp->right)
			q.push(tmp->right);
	}
	cout<<endl;
}
int countLeafNode(node *root){
	if(!root)
		return 0;
	if(!(root->left) && !(root->right))
		return 1;	
	return countLeafNode(root->left) + countLeafNode(root->right);
}
void spiralTravarsal(node * root){
	if(root){
		stack<node*> s1,s2;
		s1.push(root);
		while(!(s1.empty()) || !(s2.empty())){
			while(!(s1.empty())){
				node * tmp = s1.top(); s1.pop();
				cout<<tmp->data<<" ";
				if(tmp->right)
					s2.push(tmp->right);
				if(tmp->left)
					s2.push(tmp->left);
			}

			while(!(s2.empty())){
				node * tmp = s2.top(); s2.pop();
				cout<<tmp->data<<" ";
				if(tmp->left)
					s1.push(tmp->left);
				if(tmp->right)
					s1.push(tmp->right);
			}
		}
		cout<<endl;
	}
}
int main(){
	boost;
	node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
	int path[45],len = 0;
	cout<<"all root to leaf path : "<<endl;
	PrintPath(root,path,len); 
	cout<<"Level ordre traverals "<<endl;
	LevelOrder(root);
	LevelTraverse(root);
	cout<<"count leaf : "<<countLeafNode(root)<<endl;
	cout<<"spiral order traversal "<<endl;
	spiralTravarsal(root);
	return 0;
}