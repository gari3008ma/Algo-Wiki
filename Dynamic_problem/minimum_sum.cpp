 #include <iostream>
using namespace std;
int sum(int arr[10000],int n)
{
		int curr_sum=0,min_sum=INT_MAX,i,j;
		for(i=0;i<n;i++)
		{
			if(curr_sum>0)
			curr_sum=arr[i];
			else
			curr_sum+=arr[i];
			min_sum=min(min_sum,curr_sum);
		}
		return min_sum;
}
int main()
{
	int t,n,i,arr[10000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>arr[i];
		cout<<sum(arr,n)<<"\n";
	}
}
