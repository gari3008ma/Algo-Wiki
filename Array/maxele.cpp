 #include <iostream>
using namespace std;
int floorc(int arr[],int low,int high )
{ 
	        if(low==high)
	  	         low;
	  	     if((low+1==high)&&arr[low]<arr[high])
	  	     	return high;
	  	     if((low+1==high) && arr[low]>arr[high])
	  	     	return low;
	   	   int mid = (low+high)/2;
	   	   if(arr[mid]>arr[mid-1]&& arr[mid]>arr[mid+1])
	   	   	  return mid;
	   	   	 if(arr[mid+1] < arr[mid] && arr[mid]<arr[mid-1])
	   	   		return floorc(arr,low,mid-1);
	   	   	else 
	   	   		return floorc(arr,mid+1,high);  	
}
int main()
{
    int t,n,i,j,arr[1000];
    cin>>n;
    for(i=0;i<n;i++)
    	cin>>arr[i];
    j=floorc(arr,0,n-1);
    if(j==(-1))
    	cout<<"not found\n";
    else
    	cout<<" "<<arr[j]<<"\n";
   
	return 0;
}