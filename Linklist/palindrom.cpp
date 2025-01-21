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
struct Node
{
    string data;
    Node* next;
};
bool wrecur(struct Node *head,string a)
{
    int i=0,l=a.length();
    for(i=0;i<(l);i++)
    {
        if(a[i]!=a[l-i-1])
            return false;
    }
    return true;
}
bool recur(struct Node *head,string a)
{
    if(head==NULL)
         return true;
     string b;
     bool tmp=recur(head->next,a);
     b=b+(head->data);
     if(b==a)
        tmp=true;
    else
        tmp= false;
    return tmp;
}
bool ispalin(struct Node *head)
{
    if(head==NULL || head->next==NULL)
                 return true;
    string str;
    struct Node *tmp=head;
    int i=0,l=0,c=0;
    while(tmp!=NULL)
    {
            str=str+(tmp->data);
            tmp = tmp->next;
    }
    string :: iterator it = str.begin();
    string :: iterator et = str.end()-1;
    //cout<<(*et)<<" ";
    l=str.length();
    l=l/2;
    while(it!=str.end() && et!=str.begin() && it!=et && c!=(l/2+1))
    {
                   if((*it)!=(*et))
                   {
                    return false;
                   }
                   it++;
                   et--;
                   c++;
    }
    return true;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " -> ";
        node = node->next;
    }
    printf("NULL\n");
}
 
/* Function to create a new node with given data */
Node *newNode(const char *str)
{
    Node *new_node = new Node;
    new_node->data = str;
    new_node->next = NULL;
    return new_node;
}
 
/* Driver program to test above function*/
int main()
{
    Node *tmp;
    Node *head = newNode("a");
    head->next = newNode("bc");
    head->next->next = newNode("d");
    head->next->next->next = newNode("dcb");
    head->next->next->next->next = newNode("a");
   string a;
   tmp=head;
   while(tmp!=NULL)
   {
    a=a+(tmp->data);
    tmp=tmp->next;
   }
    wrecur(head,a)? printf("true\n"):
                        printf("false\n");
 
    return 0;
}

