#include<bits/stdc++.h>
using namespace std;
bool findindex(int arr[],int sum,queue<int> q,int n)
{
	int i,j,start=0,current=arr[0];
	q.push(0);
	map<int,bool> mp;
	for(i=0;i<=n;i++)
	{
		while(current> sum && start<(i-1))
		{
			current=current - arr[start];
			q.pop();
			start++;
		}
		if(current ==sum)
			break;
		if(i<n)
		{
			current=current+arr[i];
		    q.push(i);
	    }
	}
	while(!q.empty())
	{
		   mp[q.front()]=true;
		   q.pop();
	}
	start=0;
	for(i=0;i<n;i++)
	{
		if(mp[i]!=true)
		start=start+arr[i];
	}
	if(start==sum)
	{
		return 1;
	}
}
int main()
{
	int n,arr[1000],i,j,sum=0;
	queue<int> q;
	cin>>n;
	for(i=0;i<n;i++)
		{
			cin>>arr[i];
			sum=sum+arr[i];
		}
	if(sum%2!=0)
	{
		cout<<"NO\n";
	}
	else
	{
		if(findindex(arr,sum/2,q,n))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}