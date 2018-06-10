#include<bits/stdc++.h>
using namespace std;
void maxutil(int arr[],int end,int index,int data[],int r,int i)
{
	if(index==r)
   { for(int j=0;j<r;j++)
    {
    	cout<<data[j];
    }
    cout<<"\n";
    return;
  }
  if(i>=end)
  	return;
  data[index]=arr[i];
  maxutil(arr,end,index+1,data,r,i+1);
 maxutil(arr,end,index,data,r,i+1);
}
void recur(int arr[],int start,int end,int r)
{
	int data[r];
	maxutil(arr,start,end,index,data,r);
}
int main()
{
	int t,n,i,j,arr[100],max_sum,current;
	cin>>t;
     while(t--)
     {
     	cin>>n;
     	for(i=0;i<n;i++)
     		cin>>arr[i];
     	recur(arr,0,n,k);
     }
 }