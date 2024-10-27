 #include <iostream>
using namespace std;
struct edge
{
	int src;
	int dest;
};
struct Graph
{
	int v,e;
	struct edge * ege;
};
struct Graph *creategraph(int a,int b)
{
	Graph *g;
	g->v=a;
	g->e=b;
	g->edge=(struct edge *)malloc(b*sizeof(struct edge));
	return g;
}
int main()
{
	  int V = 3, E = 3;
    struct Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );
 
    return 0;
}