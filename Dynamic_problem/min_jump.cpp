 #include <iostream>
using namespace std;
int CountSegment(int arr[100000],int n)
{
	int dp_jump[100000],i,j,k;
	dp_jump[0]=0;
	for(i=1;i<n;i++)
		{
			dp_jump[i]=INT_MAX;
			for(j=0;j<i;j++)
			{
				if(dp_jump[j]!=INT_MAX && j+arr[j]>=i)
					{
						dp_jump[i]=min(dp_jump[i],dp_jump[j]+1);
						break;					
					}
			}
		}
		return (dp_jump[n-1]);
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
		a=CountSegment(arr,n);
		cout<<a<<"\n";
	}
}
