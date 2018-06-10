#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
	return (a>b?a:b);
}
int main()
{
	int n,i,t,arr[1000],profit[1000],max_price,min_price;
	cin>>t;
	while(t--)
	{
				cin>>n;
			for(i=0;i<n;i++)
				{
					cin>>arr[i];
					profit[i]=0;
				}
			max_price=arr[n-1];
			for(i=(n-2);i>=0;i--)
			{
                    if(max_price < arr[i])
                    	max_price=arr[i];
                    profit[i]=max(profit[i+1],max_price-arr[i]);
			}
			min_price=arr[0];
			for(i=1;i<n;i++)
			{
				if(min_price > arr[i])
					min_price = arr[i];
				profit[i]=max(profit[i-1],profit[i]+(arr[i]-min_price));
			}
			cout<<profit[n-1]<<" \n";
	}
	return 0;
}