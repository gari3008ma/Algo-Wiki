#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[100],n,i,tmp[100],lft,rght,k=0;
	bool itr=true;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	rght=n-1;
	lft=0;
	while(lft<=rght)
	{
			if(itr)
			{
				tmp[k]=arr[rght];
				k++;
				rght--;
			}
			else
			{
				tmp[k]=arr[lft];
				k++;
				lft++;
			}
			itr=!itr;
	}
	for(i=0;i<k;i++)
		arr[i]=tmp[i];
	for(i=0;i<k;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}