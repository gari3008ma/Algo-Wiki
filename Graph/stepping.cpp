#include<bits/stdc++.h>
using namespace std;
int bfs(int n,int m,int i)
{
	queue<int> q1;
	q1.push(i);
	int num,numa,numb,last,count=0;
	while(!q1.empty())
	{
			num=q1.front();
			q1.pop();
			if(num>=n && num<=m)
				count++;
			if(num==0 || num>m)
				continue;
			last=num%10;
			numa=num*10+last+1;
			numb=num*10+last-1;
			if(last==0)
			{
				q1.push(numa);
			}
			else if(last==9)
			{
				q1.push(numb);
			}
			else
			{
				q1.push(numa);
				q1.push(numb);
			}
	}
	return count;
}
int main()
{
	int t,n,i,m,res;//very easy to implement only look at corner cases//
	cin>>t;
	while(t--)
	{
			cin>>n>>m;
			res=0;
			for(i=0;i<=9;i++)
				res=res+bfs(n,m,i);
			cout<<res<<"\n";
	}
}