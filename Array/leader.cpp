#include<bits/stdc++.h>
using namespace std;
void rever(int arr[],int i,int n)
{
	if(i>=n)
		return;
       int t=arr[i];
       arr[i]=arr[n];
       arr[n]=t;
       rever(arr,i+1,n-1);
}
int main()
{
	    int i,n,j,arr[1000],c;
	    cin>>n;
	    for(i=0;i<n;i++)
	    		cin>>arr[i];
	    rever(arr,0,n-1);
	   int max_so=INT_MIN;
	    c=0;
	    for(i=0;i<n;i++)
	    {
	    	if(arr[i] > max_so)
	    			{
	    				max_so=arr[i];
	    				c++;
	    			}
	    }	
	    rever(arr,0,n-1);
	    cout<<c<<" \n";
}