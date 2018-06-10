#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,first,second,arr[1000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		first=0;
		second=0;
		for(i=0;i<n;i++)
		{
			if(first<arr[i])
			{
				second=first;
				first=arr[i];
			}
			else if(arr[i]>second && arr[i]!=first)
				second=arr[i];
		}
		cout<<first+second<<"\n";
	}
	return 0;
}