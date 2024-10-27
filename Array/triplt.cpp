 #include <iostream>
using namespace std;
int main()
{
	int n,i,t,arr[1000],l,r,count,sum;
	cin>>t;
	while(t--)
	{
				cin>>n>>sum;
			for(i=0;i<n;i++)
				{
					cin>>arr[i];
				}
				count=0;
				sort(arr,arr+n);
					for(i=0;i<n;i++)
					{
							l=i+1;
							r=n-1;
							while(l<r)
							{
								if(arr[i]+arr[l]+arr[r]<sum)
								{
									count=count+(r-l);
									l++;
								}
								else
									r--;
							}
					}
					cout<<count<<"\n";
	}
	return 0;
}