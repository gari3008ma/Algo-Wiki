#include<iostream>
#include<algorithm>
using namespace std;
int binary(int arr[],int low,int high)
{
	if(low>high)
		return -1;
   else
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==1 &&(arr[mid-1]==0 || mid==0))
           return mid;
        else if(arr[mid]==0)
        {
            return binary(arr,mid+1,high);
        }
        else
        {
            return binary(arr,low,mid-1);
        }
    }
}
int main()
 {
	int t,row,col,i,j,arr[100][100],temp,max,index;
	cin>>t;
	while(t--)
	{
	    cin>>row>>col;
	    index=0;
	    for(i=0;i<row;i++)
	    {
	        for(j=0;j<col;j++)
	          cin>>arr[i][j];
	    }
	    max=-1;
	    for(i=0;i<row;i++)
	    {
	        temp=binary(arr[i],0,col);
	        if(temp!=(-1)  &&(col-temp)>max)
	        {
	            max=(col-temp);
	            index=i;
	        }
	    }
	    cout<<index<<"\n";
	}
	return 0;
}