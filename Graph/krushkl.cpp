#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int src;
	int dest;
	int weight;
};
struct graph
{
	int v;
	int e;
	struct edge *eg;
};
struct graph *creategraph(int V,int E)
{
	struct graph *gf=(struct graph *)malloc(sizeof(struct graph));
	gf->v=V;
	gf->e=E;
	struct edge *Edge=(struct edge *)malloc(gf->e *(sizeof(struct edge)));
	return gf;
}
struct ranku
{
	int parent;
	int rank;
};
int find(struct ranku eg[],int i)
{
	if(eg[i].parent !=i)
	{
		return find(eg,eg[i].parent);
	}
	return eg[i].parent;
}
void unioni(struct ranku eg[],int x,int y)
{
	int x_=find(eg,x);
	int y_=find(eg,y);
	if(eg[x_].rank < eg[y_].rank)
	{
			eg[x_].parent=y_;
	}
	else if(eg[x_].rank > eg[y_].rank)
	{
				eg[y_].parent=x_;
	}
	else
	{
			eg[y_].parent=x_;
			eg[x_].rank++;
	}
}
int myComp(const void *a,const void * b)
{
	struct edge* a1 = (struct edge*)a;
    struct edge* b1 = (struct edge*)b;
    return a1->weight > b1->weight;
}
void KruskalMST(struct graph *gf)
{
     struct ranku eg[100];
     struct edge result[100]; 
     int i=0,ei=0,ver=gf->v;
     qsort(gf->eg, gf->e, sizeof(gf->eg[0]), myComp);
     for(i=0;i<(gf->v);i++)
     {
     	eg[i].parent=i;
     	eg[i].rank=0;
     }
     	while(ei<ver)
     	{
     		struct edge next_edge=gf->eg[ei];
     		ei++;
     		int x=find(eg,next_edge.src);
     		int y=find(eg,next_edge.dest);
     		if(x!=y)
     		{
     				result[i++]=next_edge;
     				unioni(eg,x,y);
     		}
     	}
     	for(int j=0;j<i;j++)
     	{
     		      cout<<result[j].src<<" "<<result[j].dest<<" "<<result[j].weight<<"\n";
     	}
}
int main()
{
	int v=4;
	int e=5;
	struct graph *gh=creategraph(v,e);
	gh->eg[0].src = 0;
    gh->eg[0].dest = 1;
    gh->eg[0].weight = 10;
 
    // add edge 0-2
    gh->eg[1].src = 0;
    gh->eg[1].dest = 2;
    gh->eg[1].weight = 6;
 
    // add edge 0-3
    gh->eg[2].src = 0;
    gh->eg[2].dest = 3;
    gh->eg[2].weight = 5;
 
    // add edge 1-3
    gh->eg[3].src = 1;
    gh->eg[3].dest = 3;
    gh->eg[3].weight = 15;
 
    // add edge 2-3
    gh->eg[4].src = 2;
    gh->eg[4].dest = 3;
    gh->eg[4].weight = 4;
 
    KruskalMST(gh);
}