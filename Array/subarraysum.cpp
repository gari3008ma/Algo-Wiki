 #include <iostream>
using namespace std;
int main()
{
    int n,i,start=0,arr[1000],cur_sum,sum,curr;
    cin>>n;
    for(i=0;i<n;i++)
    	cin>>arr[i];
    cin>>sum;
    curr=arr[0];
    for(i=1;i<=n;i++)
    {
    	    while(curr>sum && start<(i-1))
    	    {
    	    	curr=curr-arr[start];
    	    	start++;
    	    }
    	    if(curr==sum)
    	    {
    	    	cout<<"Required Sum is :"<<curr<<"indexes are "<<start<<" "<<(i-1);
    	    	break;
    	    }
    	    if(i<n)
    	    	curr=curr+arr[i];
    }
	return 0;
}