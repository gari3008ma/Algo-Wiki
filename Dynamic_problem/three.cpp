 #include <iostream>
using namespace std;
int main()
{
	int t,n,i,j,arr[100];
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int sum[n];
	    sum[0]=arr[0];
	    sum[1]=arr[0]+arr[1];
	    sum[2]=max(sum[1],arr[1]+arr[2]);
	    for(i=3;i<n;i++)
	    {
	       sum[i]=max(max(sum[i-1],sum[i-2]+arr[i]),arr[i]+arr[i-1]+sum[i-3]);
	    }
	    cout<<sum[n-1]<<"\n";
	}
}