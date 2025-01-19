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
#include <stdlib.h>
using namespace std;
struct node
{
  int data;
  struct node *next;   
};
void sortu(struct node ** head_ref,struct node *tmp)
{
           if((*head_ref)==NULL ||((*head_ref)->data >tmp->data))
                {
                            tmp->next=(*head_ref);
                            (*head_ref)=tmp;
                }
            else
            {
                    struct node *current=(*head_ref)->next;
                    struct node *pre=(*head_ref);
                    while(current!=NULL && (current->data<tmp->data))
                        {
                                pre=current;
                                current=current->next;
                        }
                        pre->next=tmp;
                        tmp->next=current;
            }    
}
void insrt(struct node **head_ref)
{
                if((*head_ref)==NULL ||(*head_ref)->next==NULL)
                     return ;
                  struct node *tmp=(*head_ref),*newhead=NULL,*next;
                  while(tmp!=NULL)
                  {
                    next=tmp->next;
                    sortu(&newhead,tmp);
                    tmp=next;
                  } 
                  (*head_ref)=newhead;
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;  
    new_node->next = (*head_ref);      
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
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
  insrt(&head);
  printf("\n sorted Linked list ");
  printList(head);           
  
  getchar();
}
