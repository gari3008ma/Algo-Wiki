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
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
bool ances(struct node *root,int f[],int s,int *n)
{
                           if(root==NULL)
                              return false;
                        if(root->data==s)
                           {
                              f[*n]=root->data;
                                  (*n)++;
                              return true;
                            }
                      if(ances(root->left,f,s,n)|| ances(root->right,f,s,n))
                      {
                                  f[*n]=root->data;
                                  (*n)++;
                                  return true;
                      }
                      return false;
}
int lca(struct node *root,int a,int b)
{
            if(root==NULL)
               return 0;
    int a1[100],b1[100],n1=0,n2=0;
    int *d1=&n1,*d2=&n2;
    bool p=ances(root,a1,a,d1);
    bool q=ances(root,b1,b,d2);
    int i,j;
    for(i=0;i<(*d1);i++)
    cout<<" "<<a1[i]<<"\n";
    cout<<"->\n";
    for(j=0;j<(*d2);j++)
    cout<<b1[j]<<"\n";
    cout<<"->\n";

    if(q && p)
    {

                 for( i=0;i<(n1);i++)
                 {

                           // cout<<" "<<a1[i]<<" ";
                            for(int j=0;j<(n2);j++)
                            {
                           // cout<<" "<<b1[j]<<" ";
                                        if(a1[i]==b1[j])
                                               return a1[i];
                            }

                 }
    }
    return 0;
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
int main()
{
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << lca(root, 4, 5);
    cout << "\nLCA(4, 6) = " <<lca(root, 4, 6);
    cout << "\nLCA(3, 4) = " <<lca(root, 3, 4);
    cout << "\nLCA(2, 4) = " <<lca(root, 2, 4);
    return 0;
}
