#include<bits/stdc++.h>
using namespace std;
typedef struct qnode
{
	int framenum;
	qnode *next;
	qnod *prev;
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