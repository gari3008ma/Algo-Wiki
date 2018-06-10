#include<bits/stdc++.h>
using namespace std;
            int binary(int arr[],int start,int end ,int value)
 {
	              int low=start,mid,high=end;
	while(low <= high)
	{
		mid =  (low+high)/2;
		if(arr[mid] == value)
			 return mid;
	   	else if(arr[mid] > value)
	   	   low=mid-1;
	    else 
	       high =  mid+1;	
	}
	return -1;
 }
int findPivot(int arr[], int low, int high)
{
   // base cases
   if (high < low)  return -1;
   if (high == low) return low;
 
   int mid = (low + high)/2;   /*low + (high - low)/2;*/
   if (mid < high && arr[mid] > arr[mid + 1])
       return mid;
   if (mid > low && arr[mid] < arr[mid - 1])
       return (mid-1);
   if (arr[low] >= arr[mid])
       return findPivot(arr, low, mid-1);
   return findPivot(arr, mid + 1, high);
}
int main()
{
	int t,i,n,arr[1000],k;
	scanf("%d",&t);
	cout<<"oo";
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		scanf("%d",&k);
		i=0;
		i=findPivot(arr,0,n);
		int start1=0 ,end1=i,start2=i+1,end2=n;
		if(binary(arr,start1,end1,k)  != (-1))
			printf("%d ",binary(arr,start1,end1,k));
		 if(binary(arr,start2,end2,k)!= (-1))
			printf("%d ",binary(arr,start2,end2,k));
	}
	return 0;
}