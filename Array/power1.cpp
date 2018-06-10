#include<bits/stdc++.h>
using namespace std;
int binary(int brr[],int start,int end,int x)
{
       if(start >end)
       	return -1;
       else
       {
       	   int mid=(start+end)/2;
       	   if(brr[mid]>x &&(mid==0||  brr[mid-1]<x))
       	   	  return mid;
       	   	else if(brr[mid]> x)
       	   		binary(brr,start,mid-1,x);
       	   	else
       	   		binary(brr,mid+1,end,x);
       }
}
int main()
{
	int n1,n2,i,j,arr[1000],brr[1000];
	cin>>n1>>n2;
	for(i=0;i<n1;i++)
		cin>>arr[i];
	for(j=0;j<n2;j++)
		cin>>brr[j];
	sort(brr,brr+n2);
	for(i=0;i<n1;i++)
	{
			j=binary(brr,0,n2-1,arr[i]);
			//cout<<j<<"\n";
			if(pow((arr[i]),brr[j]) >pow(brr[j],arr[i]) && j!= -1)
			{
				cout<<arr[i]<<" "<<brr[j]<<" ";
			}
	}
}