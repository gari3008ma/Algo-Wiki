#include<bits/stdc++.h>
using namespace std;
//#define pair<int,int> ipair
pair<int,int> findp(map<pair<int,int>,int> mp)
{
	map<pair<int,int>,int> ::iterator it=mp.begin();
	map<pair<int,int>,int> ::iterator et;
	int min=INT_MAX;
	pair<int,int> ans;
	for(;it!=mp.end();it++)
	{
			if(it->second < min)
			{
				min=it->second;
				ans=it->first;
				et=it;
			}
	}
	mp.erase(et);
	return ans;
}
int main()
{
	vector<vector<pair<int,int> > > graph;
	int i,j,k,e,v,u,w;
	cin>>v>>e; 
	graph.resize(v+1);
	while(e--)
	{
		cin>>u>>v>>w;
		graph[u].push_back(make_pair(v,w));
		graph[v].push_back(make_pair(u,w));
	}
	map<pair<int,int>,int> mp;
	pair<int,int> pi;
	k=0;
	for(k=0;k<(v);k++)
	{
			pi=findp(mp);
			cout<<pi.first<<pi.second<<"\n";
	}
}