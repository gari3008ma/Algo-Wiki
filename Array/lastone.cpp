#include<bits/stdc++.h>
using namespace std;
int binary(int arr[],int low,int high)
{
	if(low>high)
		return -1;
	else
	{
		int mid=low+(high-low)/2;
		
	     if(arr[mid]==1 &&(mid==high || arr[mid+1]==0))
			return mid;
		else if(arr[mid] ==1)
			return binary(arr,mid+1,high);
		else
			return binary(arr,low,mid-1);
	}
}
int main()
{
	int t,n,i,x,arr[1000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		cout<<binary(arr,0,n-1)<<"\n";
	}
	return 0;
}