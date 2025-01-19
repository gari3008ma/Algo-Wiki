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
typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *down;
} Node;

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->right;
    }
}

void merge(struct Node *root,struct Node *nw)
 {
    if(root == NULL){
        cout<<"we got null root "<<endl;
    }
    cout<<"inserting "<<nw->data<<" in "<<root->data<<endl;
    cout<<"the list now is "<<endl;
    printList(root);
    cout<<endl;
    Node *tmp=root,*re=root,*root_pers=root;
    //root->down=NULL;
    while(root != NULL && (root->data)<(nw->data))
       { cout<<"root.data "<<root->data<<" : "<<nw->data<<endl; 
             tmp=root;
            root=root->right;
        }
    if(root == NULL){
        cout<<"root now is null"<<endl;
    }
   re=tmp->right;
   tmp->right=nw;
   nw->right=re;
   
    //return re;
 }

struct Node *flatten(struct Node *root)
{
    cout<<"calling merge for "<<root->data<<" down->"<<root->down;
    if(root==NULL || root->right == NULL)
         return root;
    cout<<"calling merge for "<<root->data<<" down->"<<root->down;
    merge(root,root->down);
    cout<<"after merging "<<endl;
    printList(root);
    cout<<endl<<endl;
    cout<<"now flattening "<<root->right->data<<endl;
     return flatten(root->right);
}

void push (Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = (Node *) malloc(sizeof(Node));
    new_node->right = NULL;

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->down = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}


int main()
{
    Node* root = NULL;
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );

    push( &( root->right ), 20 );
    push( &( root->right ), 10 );

    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );

    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );

    // Let us flatten the list
    root = flatten(root);

    // Let us print the flatened linked list
    printList(root);

    return 0;
}