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
struct node
{
  int data;
  struct node *next; 
  struct node *nextt;  
};
void insrt(struct node *head_ref)
{
                if((head_ref)==NULL ||(head_ref)->next==NULL)
                     return ;
                  struct node *tmp=(head_ref),*vmp;
                  int a[100],i=0,j;
                  while(tmp!=NULL)
                  {
                       a[i]=tmp->data;
                       i++;
                       tmp=tmp->next;
                  } 
                  sort(a,a+i);
                  tmp=head_ref;
                  while(tmp!=NULL)
                 {
                       
                      for(j=0;j<i;j++)
                  {
                          if(tmp->data ==a[j] &&j<=(i-2))
                              {
                                j=j+1;
                                vmp=head_ref;
                                while(vmp!=NULL)
                                  {
                                        if(a[j]==vmp->data)
                                                break;
                                        vmp=vmp->next;
                                  } 
                                   tmp->nextt=vmp;
                                   break;
                              }
                  }
                  
                  tmp=tmp->next;
              }
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data; 
     new_node->nextt=NULL;
    new_node->next = (*head_ref);      
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   if(node->nextt!=NULL)
   { printf("->%d \n", node->nextt->data);
}
   node = node->next;
  }
} 
int main()
{
  /* Start with the empty list */
  struct node* head = NULL;
  push(&head, 2);
  push(&head, 4);
  push(&head, 8);
  push(&head, 10);
  
  printf("\n Original Linked list ");
  printList(head);
  insrt(head);
  printf("\n changed Linked list ");
  printList(head);           
  
  getchar();
}
