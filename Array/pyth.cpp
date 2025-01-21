 #include <iostream>
using namespace std;
int main()
{
	int t,n,i,l,r,arr[1000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			{
				cin>>arr[i];
				arr[i]=arr[i]*arr[i];
			}
		sort(arr,arr+n);
	  for(i=(n-1);i>=2;i--)
	  {
	  	   l=0;
	  	   r=i-1;
	  	   while(l<r)
	  	   {
	  	   	  if(arr[l]+arr[r]==arr[i])
	  	   	  	{
	  	   	  		cout<<l<<" "<<r<<" "<<i;
	  	   	  		break;
	  	   	  	}
	  	   	  else if(arr[l]+arr[r]<arr[i])
	  	   	  	l++;
	  	   	  else
	  	   	  	r--;
	  	   }
	  }
	}
	return 0;
}