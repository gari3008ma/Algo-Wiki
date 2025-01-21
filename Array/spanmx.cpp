 #include <iostream>
using namespace std;
int main()
{
	int t,arr1[100000],arr2[100000],diff[100000],i,j,dif,max,index,n,sum1,sum2;
	cin>>t;
	while(t--)
	{
			cin>>n;
			for(i=0;i<n;i++)
				cin>>arr1[i];
			for(i=0;i<n;i++)
				cin>>arr2[i];
			for(i=0;i<2*n+1;i++)
					diff[i]=-1;
				sum1=0;
				sum2=0;
				max=-1;
			for(i=0,j=0;i<n && j<n;i++,j++)
			{
					sum1+=arr1[i];
					sum2+=arr2[j];
					dif=sum1-sum2;
					index=n+dif;
					if(dif==0)
					{
						max=i+1;
					}
					else if(diff[index]==-1)
						diff[index]=i;
					else
					{
						if((i-diff[index])>max)
							max = i-diff[index];
                        
					}
			}	
			cout<<max<<"\n";
	}
}