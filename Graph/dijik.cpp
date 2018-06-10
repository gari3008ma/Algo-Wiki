#include<bits/stdc++.h>
using namespace std;

int minu(map<int,bool> mp,int parent[],int n)
{
    int i,j=INT_MAX,k;
    for(i=1;i<=n;i++)
    {
        if(parent[i]!=INT_MAX && mp[i]==false && j>=parent[i])
       {
            j=parent[i];
            k=i;
     }
    }
    cout<<k<<" ";
    return k;
}
int dijikstra(vector< vector<int> > graph,int n)
{
    map<int,bool> visited;
    int parent[n+2],m,i,t;
    for(i=0;i<=n;i++)
       parent[i]=INT_MAX;
       parent[0]=0;
       parent[1]=0;
    vector< vector<int> > :: iterator it;   
    while(visited.size()!=n)
    {
        m=minu(visited,parent,n);
        cout<<m<<" "<<visited.size()<<" " ;
        visited[m]=true;
        for(i=0;i<graph[m].size();i++)
        {
            t=graph[m][i];
            if(parent[m]!=INT_MAX && !visited[t] && parent[m]+1<parent[t])
            {
                parent[t]=parent[m]+1;
                cout<<"Hello"<<t<<" :::"<<parent[t]<<"\n";
            }
        }
        
        for(i=0;i<graph[m].size();i++)
           cout<<graph[m][i]<<" ";
         cout<<"\n";
    }
    return parent[n];
}
int main()
{
        int t,n,i,j,k;
        cin>>t;
        while(t--)
        {
               cin>>n;
               vector< vector<int> > graph;
               graph.resize(n+1);
               for(i=1;i<=n;i++)
               {
                   if(i+1 <=n)
                   graph[i].push_back(i+1);
                   if(3*i <=n)
                   graph[i].push_back(3*i);
               }
               cout<<dijikstra(n)<<"\n";
               for(i=1;i<=n;i++)
               {
                cout<<i<<" ->";
                for(j=0;j<graph[i].size();j++)
                    cout<<graph[i][j]<<" ";
                  cout<<"\n";
               }
        }
	return 0;
}