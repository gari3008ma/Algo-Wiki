#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
	int c;
		c=(*a);
		(*a)=(*b);
		(*b)=c;
}
int main()
{
	int n,i,t,arr[1000],k,ind[1000];
	cin>>t;
	while(t--)
	{
				cin>>n;
			for(i=0;i<n;i++)
				{
					cin>>arr[i];
				}
			for(i=0;i<n;i++)
			     {
			     	cin>>ind[i];
			     }	
			     i=0;
			     while(i<n)
			     {
			     	if(i!=ind[i])
			     	{
			     		swap(&arr[i],&arr[ind[i]]);
			     		swap(&ind[i],&ind[ind[i]]);
			     	}
			     	else
			     		i++;
			     }
			     for(i=0;i<n;i++)
			     	cout<<arr[i]<<" ";
			     cout<<"\n";
	}
	return 0;
}