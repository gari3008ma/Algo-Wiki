#include<bits/stdc++.h>
using namespace std;
void swp(int* a,int *b)
{
	int tmp;
	tmp=(*a);
	(*b)=(*a);
	(*a)=tmp;
}
int main()
{
	int n,i,t,arr[1000],k,brr[1000],j,tmp;
	cin>>t;
	while(t--)
	{
				cin>>n>>k;
			for(i=0;i<n;i++)
				{
					cin>>arr[i];
				}
			for(j=0;j<k;j++)
					cin>>brr[j];
				i=0;
				j=0;
				while(i<n)
				{
						if(arr[i]>brr[j])
						{
								 
								tmp=(arr[i]);
								(arr[i])=(brr[j]);
								(brr[j])=tmp;
								sort(brr,brr+k);
						}
						else
							i++;
				}
				for(i=0;i<n;i++)
					cout<<arr[i]<<" ";
				cout<<"\n";
				for(i=0;i<k;i++)
					 cout<<brr[i]<<" ";
					cout<<"\n";
	}
	return 0;
}