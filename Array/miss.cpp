#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int binary(int arr[],int low,int high)
{
	    if(low>high)
	    	return -1;
	    if(arr[low]!=low)
	    	return low;
	    int mid=(low+high)/2;
	    if( arr[mid] == mid)
	    	return binary(arr,mid+1,high);
	    return binary(arr,low,mid);
}
int main()
{
	     int n,t,i,arr[100];
	     cin>>n;
	     for(i=0;i<n;i++)
	     		cin>>arr[i];
	     t=binary(arr,0,n);
	     cout<<t<<" \n";
}