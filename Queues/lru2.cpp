 #include <iostream>
using namespace std;
typedef struct QNode
{
	int pagenumber;
	struct QNode *next;
	struct QNode *prev;
}QNode;
typedef struct Queue
{
	int count;
	int totalpage;
	struct QNode *front;
	struct QNode *rear;
}Queue;
typedef struct Hash
{
	int capacity;
	struct QNode* *array;
}Hash;
QNode *newqnode(int x)
{
	struct QNode *tmp=(struct QNode *)malloc((sizeof(struct QNode )));
	tmp->pagenumber=x;
	tmp->prev=NULL;
	tmp->next=NULL;
	return tmp;
}
Queue *createqueue(int val)
{
	struct Queue *tmp=(struct Queue *)malloc((sizeof(struct Queue )));
	tmp->count=0;
	tmp->totalpage=val;
	tmp->front=NULL;
	tmp->rear=NULL;
	return tmp;
}
hash *createHash(int cap)
{
	struct hash * hshtabl=(struct Hash *)malloc(sizeof(struct Hash ));;
	hshtabl->capacity = cap;
	hshtabl->array = (struct QNode **)malloc(hshtabl->capacity*(sizeof(struct QNode)));
	for(int i=0;i<hshtabl->capacity;i++)
	{
	       hshtabl->array[i]=NULL;
	}
	return hshtabl;
}
bool isfull(struct Queue *qp)
{
	if(qp->count== qp->totalpage)
	         return true;
	else
	         return false;         
}
bool isempty(struct Queue *qp)
{
	    if( qp->rear==NULL)
	      return true;
	      else
	      return false;
}
void dequeue(struct Hash *hsh,struct Queue *que)
{
	if(isempty(que))
		return -1;
	if(que->front==que->rear)
		  {
		  	que->front=NULL;
		  }
	struct QNode *required = que->rear;
	que->rear  = que->rear->prev;

	if(que->rear)
		que->rear->next=NULL;
	free(required);
	que->count--;
}
void enqueu(struct Queue *que,struct Hash *hsh,int x)
{
	if(isfull(que))
	{
		hsh->array[que->rear->pagenumber]=NULL;
		dequeue(hsh,que);
	}
	QNode *tmp=newqnode(x);
	tmp->next=que->front;
	if(isempty(que))
	{
		que->front=que->rear=tmp;
	}
	else
	{
		que->front->prev=tmp;
	que->front=tmp;
	}
	hsh->array[x]=tmp;
	que->count++;
}
void setlru(struct Hash *hsh,struct Queue *que,int x)
{
	struct QNode *reqpage=hsh->array[x];
	if(reqpage == NULL)
	      {
	      		enqueu(que,hsh,x);
	      		return ;
	      }
	else if(que->front!= reqpage)      
	{
                reqpage->prev->next=reqpage->next;
                if(reqpage->next)
                {
                	reqpage->next->prev=reqpage->prev;
                }
                if(reqpage==que->rear)
                {
                	que->rear=reqpage->prev;
                	que->rear->next=NULL;
                }
                reqpage->next = que->front;
                reqpage->prev=NULL;
                reqpage->next->prev=reqpage;
                que->front=reqpage;
	}
}
int main()
{
	Queue *que=createqueue(4);
	Hash *hsh=createHash(4);
	setlru(hsh,que,1);
	setlru(hsh,que,2);
	setlru(hsh,que,3);
	setlru(hsh,que,4);
	setlru(hsh,que,5);
	 printf ("%d ", que->front->pagenumber);
    printf ("%d ", que->front->next->pagenumber);
    printf ("%d ", que->front->next->next->pagenumber);
    printf ("%d ", que->front->next->next->next->pagenumber);
 
	return 0;
}