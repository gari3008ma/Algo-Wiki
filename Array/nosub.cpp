 #include <iostream>
using namespace std;
int main()
{
	int t,n,i,k,arr[1000],res;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		res=1;
		for(i=0;i<n && arr[i]<=res;i++)
		{
			res=res+arr[i];
		}
		cout<<res<<"\n";
	}
	return 0;
}