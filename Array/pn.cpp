#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,prev,arr[1000],k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		prev = arr[0];
		arr[0] = arr[0]*arr[1];
		for(i=1;i<n-1;i++)
		{
			k=prev*arr[i+1];
			prev=arr[i];
			arr[i]=k;
		}
		arr[n-1]=arr[n-1]*prev;
		for(i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
	}
	return 0;
}