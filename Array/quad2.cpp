 #include <iostream>
using namespace std;
int main()
{
	int t,n,i,arr[1000],j,k,l,sum,r,brr[1000];
	cin>>t;
	while(t--)
	{
		cin>>n>>sum;
		for(i=0;i<n;i++)
			cin>>arr[i];
		r=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				brr[r]=arr[i]+arr[j];
				r++;
			}
		}
		sort(brr,brr+r);
				k=0;
				l=r-1;
				while(k<l)
				{
					if(brr[k]+brr[l]==sum)
					{
						cout<<"YES\n";
							l--;
							k++;
					}
					else if((brr[k]+brr[l])<sum)
						k++;
					else
						l--;
				}
			
		
	}
	return 0;
}