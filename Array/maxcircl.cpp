#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,j,arr[100],max_sum,current,start,end,max;
	cin>>t;
     while(t--)
     {
     	cin>>n;
     	for(i=0;i<n;i++)
     		cin>>arr[i];
     	start=0;
     	end=n-1;
     	max=INT_MIN;
  while(start <(n))
    {
    	current=arr[start];
     	max_sum= INT_MIN;
     	for(i=start+1;i<=end ;i++)
     	{
     		if(current > max_sum)
     		{
     			max_sum=current;
     		}
     		if(current<0)
     			{
     				current = 0;
                }
                j=i%n;
     		current = current +arr[j];
     	}
     	if(max_sum > max)
     		max=max_sum;
     	
     	start++;
     	end++;
     }
     cout<<max<<"\n";
     }

}