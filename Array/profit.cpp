 #include <iostream>
using namespace std;
int main()
{
	int t,i,max_profit,arr[100000],n,profit[100000];
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(i=0;i<n;i++)
	       cin>>arr[i];
        memset(profit,0,sizeof(profit));
        max_profit=arr[n-1];
        for(i=n-2;i>=0;i--)
        {
        	   if(max_profit<arr[i])
        	   	max_profit=arr[i];
        	   profit[i]=max(profit[i+1],max_profit-arr[i]);
        }
        max_profit=arr[0];
        for(i=1;i<n;i++)
        {
        	   if(max_profit > arr[i])
        	   	    max_profit=arr[i];
        	  profit[i]=max(profit[i-1],profit[i]+arr[i]-max_profit);
        }
        cout<<profit[n-1]<<"\n";
	}
}