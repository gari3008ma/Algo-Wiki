 #include <iostream>
using namespace std;
int main()
{
	int arr[1000],i,n,max_till=INT_MIN,count=0,j,min;
	cin>>n;
	for(i=0;i<n;i++)
	  cin>>arr[i];
  min=arr[0];
  for(i=1;i<n;i++)
  {
  	
  			if((arr[i]-min)>0 &&(i-j)>max_till)
  			{
  				max_till = (i-j);

  			}
        else if(arr[i]<min)
       {
         min=arr[i];
         j=i;
       }
  	
  }	
  cout<<max_till<<" ";
  return 0;
}