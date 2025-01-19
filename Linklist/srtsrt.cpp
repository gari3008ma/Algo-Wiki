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
struct node*rev(struct node *head)
{
    if(head==NULL || head->next==NULL)
        return head;
            struct node *tmp=rev(head->next);
            head->next->next=head;
            head->next=head;
            return tmp;
}
struct node *sortu(struct node *head)
{
    if(head==NULL || head->next==NULL)
      return head;
      head=rev(head);
      struct node *tmp=head,*pre;
        vector<struct node *>a;
      while(tmp!=NULL)
      {
        if(tmp->data <0)
            {
                a.push_back(tmp);
                pre=tmp->next;
                free(tmp);
               tmp=pre;
            }
            else
                tmp=tmp->next;
      }
      //printList(head);
        head=rev(head);
        vector<struct node *> :: iterator it = a.begin();
        
       return head;
}
struct node *sort1(struct node *head)
{
    if(head==NULL || head->next==NULL)
      return head;
  struct node *tmp=head,*pre=head,*cur=head->next;
   while(cur!=NULL)
   {
            if(pre->data >cur->data)
            {
                pre->next=cur->next;
                cur->next=head;
                head=cur;
            }
            pre=cur;
            cur=pre->next;
   }
   return head;
}
void push(struct node ** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
     new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct node* head = NULL;
    push(&head, -10);
    push(&head, -9);
    push(&head, 8);
    push(&head, 7);
    push(&head, -6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf(" \nGiven Linked list is :\n");
    printList(head);
 
    head=sort1(head);
 
    printf("\nLinked list after sorting is :\n");
    printList(head);
 
    return 0;
}
