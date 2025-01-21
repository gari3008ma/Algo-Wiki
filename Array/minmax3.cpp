 #include <iostream>
using namespace std;
struct pair
{
	int min;
	int max;
};
struct pair mm(int arr[],int j)
{
	struct pair pp;
	if(j==1)
  {
  	pp.min=arr[0];
  	pp.max=arr[0];
  }
  else if(j==2)
  {
  			if(arr[0]>arr[1])
  			{
  				pp.min=arr[1];
  				pp.max=arr[0];
  			}
  			else
  			{
  				pp.min=arr[0];
  				pp.max=arr[1];
  			}
  }
  else
  {
  	             for(int i=0;i<j;i=i+2)
  	             {
  	             	   if(arr[i]>arr[i+1])
  	             	   {
  	             	   	   if(arr[i+1] < pp.min)
  	             	   	   		pp.min=arr[i];
  	             	   	   	if(arr[i]> pp.max)
  	             	   	   		pp.max=arr[i];
  	             	   }
  	             	   else
  	             	   {
  	             	     	if(arr[i] < pp.min)
  	             	   	   		pp.min=arr[i];
  	             	   	   	if(arr[i+1]> pp.max)
  	             	   	   		pp.max=arr[i+1];
  	             	   }
  	             }
  }
  return pp;
}
int main()
 {
	int t,i,n,a[10000];
	cin>>t;
	while(t--)
	{
	       cin>>n;
	       for(i=0;i<n;i++)
	       {
	         cin>>a[i];
	       }
	       struct pair p=mm(a,n);
	       cout<<p.min<<" "<<p.max<<" ";
	}
	return 0;
}