 #include <iostream>
using namespace std;
int main()
{
	  int t,n,arr[1000],i,larr[1000],max_sofar;
	  cin>>t;
	  while(t--)
	  {
	  	cin>>n;
	  	for(i=0;i<n;i++)
	  		cin>>arr[i];
	  	max_sofar=INT_MIN;
	  	larr[n-1]=-1;
	  	for(i=n-1;i>=1;i--)
	  	{
	  			if(arr[i]> max_sofar)
	  				{
	  					larr[i-1]=arr[i];
	  					max_sofar=arr[i];
	  			    }
	  			    else
	  			larr[i-1]=larr[i];
	  	}
	  	for(i=0;i<n;i++)
	  {
       	arr[i]=larr[i];
       	cout<<arr[i]<<" ";
       	}
       	cout<<"\n";
	  }
}