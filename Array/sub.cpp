 #include <iostream>
using namespace std;
int main()
{
	int t,n,i,arr[1000],sum,start,end,max;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		sum=0;
		start=0;
		end=0;
		max=-1;
		for(i=0;i<n;i++)
		{
			if ((end-start)>sum)
			{
					start=end;
					sum=0;
			}
			if(max <=(end-start))
				max=(end-start);
			sum=sum+arr[i];
			end++;
		}
		cout<<max<<"\n";
	}
}