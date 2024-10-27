 #include <iostream>

using namespace std;
void dfs(vector<int> graph[], int ind,bool visited[],stack<int>& st)
{
    visited[ind]=true;
    vector<int> :: iterator it;
    for(it=graph[ind].begin();it!=graph[ind].end();it++)
    {
        if(!visited[(*it)])
           dfs(graph,(*it),visited,st);
    }
    st.push(ind);
}
int *topoSort(vector<int> graph[], int N)
{
    stack<int> st;
    bool visited[N+1];
    int i,j,arr[2*N+1];
    for(i=0;i<=N;i++)
       visited[i]=false;
    for(i=0;i<N;i++)
    {
        if(visited[i]==false)
        {
            dfs(graph,i,visited,st);
        }
    }
    i=0;
    arr[0]=0;
   while(!st.empty())
    {
        arr[i]=st.top();
        i++;
       cout<<st.top();
        st.pop();
    }//
    //reverse(arr,arr+i);
  return arr;
}
int main()
{
	int n,i,j,e,u,v;
	const char *str[]
	cin>>n>>e;
	vector<vector<int> > graph;
	while(e--)
	{
			cin>>u>>v;
			graph[u].push_back(v);
	}
	int *arr=topoSort(graph,n);
}