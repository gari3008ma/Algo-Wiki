#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int m(int arr[],int s,int e)
{
	int v=INT_MAX;
	for(int i=s;i<e;i++)
	{
			if(arr[i]<v)
				v=arr[i];
	}
	return v;
}
int mm(int arr[],int s,int e)
{
	int v=INT_MIN;
	for(int i=s;i<e;i++)
	{
			if(arr[i] >= v)
				v=arr[i];
	}
	return v;
}
bool iscon(int arr[],int s,int e)
{
	int min,max,j,k,i,n;
	int *hash=(int *)calloc(sizeof(int),n);
	min=m(arr,s,e);
	max=mm(arr,s,e);
	if(max-min+1 == (e-s))
	{
				for(i=s;i<e;i++)
				{
					if(hash[arr[i]]!=false)
						return false;
					hash[arr[i]]=true;
				}
				return true;
  }
  return false;
}
int main()
{
	    int t,n,i,j,arr[100];
	    cin>>n;
	    for(i=0;i<n;i++)
	    	cin>>arr[i];
	    if(iscon(arr,0,n))
	    	cout<<"TRUE \n";
	    else
	    	cout<<"FALSE \n";
}