 #include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,a,n) for(int i=a;i<n;i++)
int main()
{
	    int i,n,arr[1000],j,k,r;
	    bool t;
	    cin>>n;
	    rep(i,n)
	    {
	    		scanf("%d",&arr[i]);
	    }
	    cin>>r;
	    j=n-2;
	    for(i=0;i<(n-1);i++)
	    {
	    	t=false;
	    	for(k=0;k<=j;k++)
	    	{
	    		if(arr[k]>arr[k+1])
	    	  		{
	    				arr[k]=arr[k+1]+arr[k];
	    				arr[k+1]=arr[k]-arr[k+1];
	    				arr[k]=arr[k]-arr[k+1];
	    				t=true;
	    			}

	   		 }
	   		 //cout<<arr[j];
	   		 if(t==false)
	   		 	break;
	    	j--;
	    }
	    reps(i,r,n)
	    cout<<arr[i]<<" ";
	    return 0;
}