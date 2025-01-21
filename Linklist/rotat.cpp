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

typedef struct node{
    node * next;
    int data;
}node;

void Push_node(node** head,node *n){
    node * tmp = *head;//point tmp where head is pointing
    if(tmp){
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = n;
    }else{
        *head = n;
    }

}
void rot(struct node **head,int k)
{
    struct node *tmp=(*head),*post;
    int i=1;
    if((*head)==NULL)
        return;
    while(tmp!=NULL && i<k)
    {
             tmp=tmp->next;
             i++;
    }
    post=tmp->next;
    if((i)==k)
    {
            tmp->next=NULL;
            tmp=(*head);
            (*head)=post;
            while(post->next!=NULL)
                post=post->next;
            post->next=tmp;
    }
}
void Push_data(node ** head,int data){

    node * n = new node;
    n->data = data;
    n->next = NULL;
    Push_node(head,n);
}

void Print(node * head){
    node *tmp = head;
    while(tmp){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}
int main(){
    node * head = NULL;
    Push_data(&head,10);
    Push_data(&head,20);
    Push_data(&head,30);
    Push_data(&head,40);
     Push_data(&head,50);
      Push_data(&head,60);
    Print(head);
    rot(&head,4);
    Print(head);
    return 0;
}
