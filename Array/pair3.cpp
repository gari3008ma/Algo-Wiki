 #include <iostream>
using namespace std;
int main()
{
	int t,n,i,x,arr[1000],brr[1000],l,r,res_l,res_r,diff,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>x;
		for(i=0;i<n;i++)
			cin>>arr[i];
		for(i=0;i<m;i++)
			cin>>brr[i];
		l=0;
		r=m-1;
		diff=INT_MAX;
       while(l<r)
       {
       	if(arr[l]+brr[r]-x <diff)
       	{
       		diff = arr[l]+brr[r]-x;
       		res_l=l;
       		res_r=r;
       		diff= arr[l]+brr[r]-x;
       	}
       	else if(arr[l]+brr[r]<x)
       		l++;
       	else
       		r--;
       }
       cout<<arr[res_l]<<" "<<brr[res_r]<<"\n";
	}
	return 0;
}