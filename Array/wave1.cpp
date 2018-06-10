#include<bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
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
			for(i=0;i<n;i+=2)
			{
				if(i>0 && arr[i]<arr[i-1])
					swap(&arr[i],&arr[i-1]);
				if(i<n-1 && arr[i]<arr[i+1])
					swap(&arr[i],&arr[i+1]);
			}
			for(i=0;i<n;i++)
				cout<<arr[i]<<" ";
			cout<<"\n";
	}
	return 0;
}