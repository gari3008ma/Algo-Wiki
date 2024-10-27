 #include <iostream>
using namespace std;
int CountSegment(int arr[100000],int n)
{
	int dp_jump[100000],i,j,k,maxi;
	dp_jump[0]=0;
	for(i=0;i<n;i++)
	{
		dp_jump[i]=arr[i];
		maxi=0;
		for(j=1;j<=sqrt(i+1);j++)
		{
				if((i+1)%j==0 && (i+1)!=j)
				{
					if(dp_jump[j-1]>maxi)
					maxi=dp_jump[j-1];
					if(j!=1 && dp_jump[(i+1)/j-1]>maxi)
						maxi = dp_jump[(i+1)/j-1];
				}
		}
		dp_jump[i]=dp_jump[i]+maxi;
	}
		for(i=0;i<n;i++)
			cout<<dp_jump[i]<<"\n";
}
int main()
{
	int t,n,i,arr[10000],a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		CountSegment(arr,n);
		//cout<<a<<"\n";
	}
}
