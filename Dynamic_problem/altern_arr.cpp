#include<bits/stdc++.h>
using namespace std;
int CountSegment(int arr[2][1000],int n)
{
	int dp_jump[100000],i,j,k,maxi,inc,excl;
	inc = max(arr[0][0],arr[1][0]);
	excl = 0;
	maxi=0;
	for(i=1;i<n;i++)
	{
		maxi=max(inc,excl);
		inc = excl + max(arr[0][i],arr[1][i]);
		excl=maxi;
	}
		return max(inc,excl);
}
int main()
{
	int t,n,i,arr[2][1000],j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<2;i++)
		for(j=0;j<n;j++)
			cin>>arr[i][j];
		cout<<CountSegment(arr,n)<<"\n";
		//cout<<a<<"\n";
	}
}
