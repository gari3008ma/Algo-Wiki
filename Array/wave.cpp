#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
	int tmp;
	tmp = (*a);
	(*a) = (*b);
	(*b) =tmp;
}
int pivot(int arr[],int low,int high)
{
		int i=low,j=low,x=arr[high];
		for(i=low;i<high;i++)
		{
			if(arr[i]<=x)
			{
				swap(&arr[i],&arr[j]);
				j++;
			}
		}
		swap(&arr[j],&arr[high]);
		return j;
}
void sortu(int  arr[],int low,int high)
{
	  if(low>high)
	  	return ;
	  else
	  {
	  	int p= pivot(arr,low,high);
	  	sortu(arr,low,p-1);
	  	sortu(arr,p+1,high);
	  }
}
int main()
{
	int t,n,arr[1000],i,index,k,tmp[1000];
	cin>>t;
	while(t--)
	{
			cin>>n;
			for(i=0;i<n;i++)
				cin>>arr[i];
			sortu(arr,0,n-1);
			index=(n/2);
			k=0;
			i=0;
			while(index<n && k<n)
			{
				tmp[k]=arr[index];
				index++;
				k++;
				if(k<n)
				{
				tmp[k]=arr[i];
				i++;
				k++;
			   }
			}
			for(i=0;i<k;i++)
				arr[i]=tmp[i];
			for(i=0;i<k;i++)
				cout<<arr[i]<<" ";
			cout<<"\n";
	}
	return 0;
}