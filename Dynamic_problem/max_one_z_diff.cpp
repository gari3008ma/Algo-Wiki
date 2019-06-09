#include<bits/stdc++.h>
using namespace std;
int z_o_diff(int arr[100000],int n)
{
	int i,j,k,curr_sum=0,max_sum=INT_MIN;	

	for(int i=0;i<n;i++)
		if(arr[i]==0)
			arr[i]=-1;
	
	for(i=0;i<n;i++)
	{
		if(curr_sum>max_sum)
			max_sum=curr_sum;
		if(curr_sum<0)
			curr_sum=0;
		curr_sum=curr_sum+arr[i];
	}
	if(curr_sum>max_sum)
		max_sum=curr_sum;
	return max_sum;
}

int main()
{
	int t,n,arr[100000],i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
	}
}
