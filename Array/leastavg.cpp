#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,average,arr[100000],sum[100000],n,k,s,e;
	cin>>t;
	while(t--)
	{
	    cin>>n>>k;
	    for(i=0;i<n;i++)
	       cin>>arr[i];
	   average=INT_MAX;
	   sum[0]=arr[0];
        for(i=1;i<n;i++)
        	sum[i]=sum[i-1]+arr[i];
	   for(i=k;i<n;i++)
	   {
	   	     if(average >sum[i]-sum[i-k])
	   	     	  {
	   	     	  	average=sum[i]-sum[i-k];
	   	     	  	e=i;
	   	     	  	s=i-k+1;
	   	     	  }
	   }
	   cout<<(average/3)<<" "<<s<<" "<<e<<"\n";
	}
	return 0;
}	   