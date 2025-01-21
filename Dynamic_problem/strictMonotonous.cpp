 #include <iostream>
using namespace std;
int strictmono(int n,int s)
{
	queue<pair<int,int> > bfs;
	int i,j,v,f,s,level;
	for(i=1;i<=9;i++)
		bfs.push(make_pair(i,0));
	while(!bfs.empty() &&  level<n)
	{
		j=bfs.size();
		while(j--){
		        v=bfs.front();
			f=v.first;
			s=v.second;
			if(f+1<=9)
			{
				bfs.push(make_pair(f+1,s+1));
			}
			if(f-1>=0)
			{
				bfs.push(make_pair(f-1,s+1));
			}
			level=s+1;
		}
	}
}
int main()
{
		long long int n,m,i,j;
		cin>>n>>m;
		cout<<countway(n,m);
}
