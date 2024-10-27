 #include <iostream>
using namespace std;
int diff(int a,int b)
{
	if(a-b>=0)
		return (a-b);
	else
		return (b-a);
}
int main()
{
	int n,i,t,arr[1000],a,b,sum;
	cin>>t;
	while(t--)
	{
				cin>>n;
			for(i=0;i<n;i++)
				{
					cin>>arr[i];
				}
				a=0;
				b=0;
				sum=0;
			for(i=0;i<n;i++)
			{
				if(a==0&&b==0&&arr[i]!=0)
				{
					a=arr[i];
				}
				else if(a!=0&&b==0&&arr[i]!=0)
				{
					b=arr[i];
						sum=sum+ diff(a,b);
						if(i<n)
							sum+=1;
				}
			}	
			cout<<sum<<"\n";
	}
	return 0;
}