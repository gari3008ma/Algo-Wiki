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
		sort(arr,arr+n);
		for(i=0;i<n;i++)
		{	
			for(j=i+1;j<n;j++)
			{
				k=j+1;
				l=n-1;
				while(k<l)
				{
					if(arr[i]+arr[j]+arr[k]+arr[l]==sum)
					{
						cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<" "<<arr[l]<<" \n";
							l--;
							k++;
					}
					else if((arr[i]+arr[j]+arr[k]+arr[l])<sum)
						k++;
					else
						l--;
				}
			}
		}
	}
	return 0;
}