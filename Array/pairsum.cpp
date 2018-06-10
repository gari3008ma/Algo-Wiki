#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,t,arr[1000],prr[1000],k,c;
	cin>>t;
	while(t--)
	{
				cin>>n>>k;
			for(i=0;i<n;i++)
				{
					cin>>prr[i];
				}
				arr[0]=(prr[0]+prr[1]-prr[k-1])/2;
			for(i=0;i<k-1;i++)
			{
				arr[i+1]=prr[i]-arr[0];
			}
			for(i=0;i<k;i++)
				cout<<arr[i]<<" ";
			cout<<"\n";
	}
	return 0;
}