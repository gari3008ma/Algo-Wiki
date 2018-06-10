#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,arr[1000],j,k,l,sum;
	cin>>t;
	while(t--)
	{
		cin>>n>>sum;
		for(i=0;i<n;i++)
			cin>>arr[i];
		for(i=0;i<n;i++)
		{	
			for(j=i+1;j<n;j++)
			{
				for(k=j+1;k<n;k++)
				{
					for(l=k+1;l<n;l++)
						if(sum==(arr[i]+arr[j]+arr[k]+arr[l]))
						{
							cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<" "<<arr[l]<<" \n";
							break;
						}
				}
			}
		}
	}
	return 0;
}