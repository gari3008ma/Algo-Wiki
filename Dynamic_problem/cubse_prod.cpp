 #include <iostream>
using namespace std;
int count(int arr[],int n,int k,int i)
{
		if(i<0 || i>=n)
			return 0;
		if(k==0)
		return 1;
		if(arr[i]>k)
		return count(arr,n,k,i+1);
		return 1+count(arr,n,k/arr[i],i+1)+count(arr,n,k,i+1);
}
int main()
{
	int t,n,arr[10000],i,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cin>>k;
		cout<<count(arr,n,k,0)<<"\n";
	}
}
