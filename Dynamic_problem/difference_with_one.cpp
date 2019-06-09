#include<bits/stdc++.h>
using namespace std;
int max_len(int arr[10000],int n)
{
    int lis[10000],i,j,k;
    memset(lis,1,sizeof(lis));
    for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
			{
				if(abs(arr[j]-arr[i])<=1 && lis[i]<lis[j]+1 )
				lis[i]=lis[j]+1;
			}
	}
	return (*max_element(lis,lis+n));
}
int main()
{
		int n,t,i,j,arr[100000];
		cin>>t;
		while(t--)
		{
			cin>>n;
			for(i=0;i<n;i++)
				cin>>arr[i];
			cout<<max_len(arr,n)<<"\n";
		}
}
