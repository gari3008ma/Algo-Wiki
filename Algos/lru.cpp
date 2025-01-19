 #include <iostream>
using namespace std;
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
typedef struct qnode
{
	int framenum;
	qnode *next;
	qnode *prev;
}qnode;
typedef struct queue
{
	int pnum;//number of frames filled
	int totalfrm;//total number of frames 
	queue *tail;
	queue *head;
}queue;
typedef struct hash
{
		int count;//total number of possibel pages 
	    qnode* *arr;
}hash;
qnode* newqnode( unsigned pageNumber )
{
    // Allocate memory and assign 'pageNumber'
    qnode* temp = (qnode *)malloc( sizeof( qnode ) );
    temp->framenum = pageNumber;
 
    // Initialize prev and next as NULL
    temp->prev = temp->next = NULL;
 
    return temp;
}
queue *creatque(int frm)
{
	struct queue *tmp=(struct queue *)malloc(sizeof(struct queue ));
		tmp->pnum=0;
		tmp->totalfrm=frm;
		tmp->tail=tmp->head=NULL;
		return tmp;
}
hash *creathsh(int capacity)
{
	struct hash *tmp=(struct hash *)malloc(sizeof(struct hash));
		tmp->totalfrm=capacity;
		
		tmp->arr=(struct queue * *)malloc(tmp->capacity *(sizeof(struct queue *)));
		int i=0;
		for(i=0;i<(tmp->capacity);i++)
		{
				tmp->arr[i]=NULL;
		}
		return tmp;
}
int allfrmfull(queue * que)
{
	if(pnum==totalfrm)
		return 1;
	else
		return 0;
}
int isempty(queue *que)
{
	if(queue->rear==NULL)
		return 1;
	else
		return 0;
}
void dequeu(struct queue *que)
{
	if(isempty(que))
			return ;
		if(que->front==que->rear)
		{
			que->front=NULL;
		}
		qnode *tmp = que->rear;
		que->rear = que->rear->prev;
		if(que->rear)
		{
			que->rear->next=NULL;
		}
		free(tmp);
		que->count--;
}

void enque(queue *que,hash *hsh ,int pagenumber)
{
	         if(allfrmfull(que))
	         {
	         	hsh->arr[que->rear->framenum]=NULL;
	         	dequeu(que);
	         }
	         qnode *tmp=newqnode(pagenumber);
	         tmp->next=que->front;
	         if(isempty(que))
	           // Else change the front
    {
        que->front->prev = tmp;
        que->front = tmp;
    }
 
    // Add page entry to hash also
    hash->array[ pageNumber ] = temp;
 
    // increment number of full frames
    queue->count++;
    }
int main()
{
	
}