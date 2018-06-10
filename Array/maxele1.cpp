#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,arr[100],i,j,k,index;
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>arr[i];
	for(i=0;i<n;i++)
		arr[arr[i]%k]+=k;
	j=INT_MIN;
	for(i=0;i<n;i++)
	{
			if(arr[i]>j)
			{
				j=arr[i];
				index=i;
			}
	}
	cout<<index<<" ";
	return 0;
}