#include<bits/stdc++.h>
using namespace std;
bool ispre(int arr[],int k)
{
	
}
int main()
{
	int t,n,i,k,arr[1000];
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(i=0;i<n;i++)
			cin>>arr[i];
		if(ispre(arr,k))
			cout<<"True\n";
		else
			cout<<"False\n";
	}
	return 0;
}