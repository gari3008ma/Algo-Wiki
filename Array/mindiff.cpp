#include<bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
	return (a>b?b:a);
}
int max(int a,int b)
{
	return (a>b? a:b);
}
int maxdiff(int arr[],int n,int k)
{
		sort(arr,arr+n);
		int i,nwmax,nwmin,res,val1,val2;
    if((arr[n-1]-arr[0]) <= k)
    		{
    			for(i=0;i<n;i++)
    				arr[i]+=k;
    			return (arr[n-1]-arr[0]);
    		}
    else
    {
    			arr[n-1]=arr[n-1]-k;
    			arr[0]=arr[0]+k;
    			nwmax=max(arr[n-1],arr[0]);
    			nwmin=min(arr[0],arr[n-1]);
    			for(i=1;i<n-1;i++)
    			{
    				if(arr[i]<nwmin)
    				{
    					arr[i]=arr[i]+k;
    				}
    				else if(arr[i]>nwmax)
    				{
    					arr[i]=arr[i]-k;
    				}
    				else if(nwmax-arr[i]<arr[i]-nwmin)
    					arr[i]=arr[i]-k;
    				else
    					arr[i]=arr[i]+k;
    				nwmin=min(nwmin,arr[i]);
    				nwmax=max(arr[i],nwmax);
    			}
    			return nwmax-nwmin;
    }		
}
int main()
{
	int n,i,t,arr[1000],mxdiff,k;
	cin>>t;
	while(t--)
	{
				cin>>n;
			for(i=0;i<n;i++)
				{
					cin>>arr[i];
				}
				cin>>k;
			mxdiff = maxdiff(arr,n,k);
           for(i=0;i<n;i++)
           	cout<<arr[i]<<" ";
           cout<<" \n";
           cout<<mxdiff<<"\n";
	}
	return 0;
}