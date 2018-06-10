#include<bits/stdc++.h>
using namespace std;
int swap(int arr[],int start,int end)
{
	int i,j=0,k;
	for(i=start;i<end;i++)
	{
              if(arr[i]<=0)
              {
              	k=arr[i];
              	arr[i]=arr[j];
              	arr[j]=k; 
              	j++;
              }
	}
	return j;
}
int main()
{
    int t,n,i,j,arr[1000],k=0;
    cin>>n;
    for(i=0;i<n;i++)
    	cin>>arr[i];
    i=swap(arr,0,n);
    sort(arr,arr+n);
    for(j=i;j<n;j++)
    {
    	if(arr[j]>(k+1))
    		{
    			cout<< k+1;
    			break;
    		}
    		k++;
    }
	return 0;
}