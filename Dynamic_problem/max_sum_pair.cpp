#include<bits/stdc++.h>
using namespace std;
int max_sum(int arr[10000],int n,int k,int s)
{
   if(i<0 || i>=n)
	return 0;
   
   for(int j=s;j<n;j++)
	if(arr[j]-arr[s]==k)
	sum=sum+arr[j]+arr[s];

	return sum+max_sum(arr,n,k,s+1);
}
int dp_sol(int arr[10000],int k)
{
	
}
int main()
{
		int n,t,i,j,arr[100000],index,k;
		cin>>t;
		while(t--)
		{
			cin>>n;
			for(i=0;i<n;i++)
				cin>>arr[i];
			cin>>k;
			cout<<max_sum(arr,n,k,0)<<"\n";
		}
}
