#include<bits/stdc++.h>
using namespace std;
int binary(int arr[],int low,int high,int x)
{
	if(low>high)
		return -1;
	else
	{
		int mid=low+(high-low)/2;
		
	     if(arr[mid]>x &&(mid==0 || arr[mid-1]<x))
			return mid-1;
		else if(arr[mid]==x || (arr[mid]<x && mid==high))
			return mid;
		else if(arr[mid] <x)
			binary(arr,mid+1,high,x);
		else
			binary(arr,low,mid-1,x);
	}
}
int main()
{
	int t,n,i,x,arr[1000],brr[1000],m,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>x;
		for(i=0;i<n;i++)
			cin>>arr[i];
		for(i=0;i<m;i++)
			cin>>brr[i];
		sort(arr,arr+n);
		sort(brr,brr+m);
		i=binary(arr,0,n-1,x);
		j=binary(brr,0,m-1,x);
		if(arr[i]>brr[j])
		{
			x=x-arr[i];
			j=binary(brr,0,m-1,x);
			cout<<arr[i]<<" "<<brr[j]<<"\n";
		}
		else
		{
			x=x-brr[j];
			i=binary(arr,0,n-1,x);
			cout<<brr[j]<<" "<<arr[i]<<"\n";
		}
	}
	return 0;
}
