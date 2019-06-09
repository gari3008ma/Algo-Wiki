#include<bits/stdc++.h>
using namespace std;
int count_path(int arr[10000],int n,int i,int sum)
{
		if(i>n || i<0)
			return 0;
		if(sum<0)
			return 0;
		if(sum==0)
			return 1;
		if(arr[i]>sum)
			return count_path(arr,n,i+1,sum);
		return count_path(arr,n,i+1,sum)+count_path(arr,n,i,sum-arr[i]);
}
int main()
{
	int t,n,sum,i,j,arr[10000];
	cin>>t;
	while(t--)
	{
		cin>>n>>sum;
		for(i=0;i<n;i++)
			cin>>arr[i];
		cout<<count_path(arr,n,0,sum)<<"\n";
	}
}
