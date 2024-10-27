 #include <iostream>
using namespace std;
int main()
{
	int n,i,t,arr[1000],k,max,sum,ind,res;
	cin>>t;
	while(t--)
	{
				cin>>n>>k;
			for(i=0;i<n;i++)
				{
					cin>>arr[i];
				}
				max=INT_MIN;
				sum=0;
				for(i=0;i<k;i++)
					sum+=arr[i];
				max=sum;
				ind=i-k;
				for(i=k;i<n;i++)
				{
					sum+=(arr[i]-arr[i-k]);
					if(sum>max)
						{
							max=sum;
							ind=i-k+1;
						}

				}
				cout<<ind<<" "<<ind+k<<" "<<max<<"\n";
	}
	return 0;
}