 #include <iostream>
using namespace std;
int main()
{
	int m,n,i,j,arr[1000],brr[1000];
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>arr[i];
	for(i=0;i<m;i++)
		cin>>brr[i];
	int max1=0,max2=0,max=0;
	while(i<m || j<n)
	{
		if(i==m)
		{
			max1=max1+arr[j];
			j++;
			max2=0;
		}
		else if(j==n)
		{
			max2=max2+brr[i];
			i++;
			max1=0;
		}
		else if(i==(m-1)  || (j==(n-1)))
		{
				max1=max1+arr[i];
				i++;
				max2=max2+brr[j];
				j++;
				if(max1 > max2)
				{
					max=max+max1;
				}
				else
				{
					max=max+max2;
				}
				max1=0;
				max2=0;

		}
		else if(arr[i]==brr[j])
		{
				if(max1 > max2)
				{
					max=max+max1+arr[j];
					i++;
					j++;
					
				}
				else
				{
					max=max+max2+brr[i];
					i++;
					j++;
				}
				max1=0;
				max2=0;
		}
		else
		{
               max1=max1+arr[j];
               j++;
               max2=max2+brr[i];
               i++;
		}
	}
	if(max1<max2)
		max=max+max2;
	else
		max=max+max1;
	cout<<max<<"\n";
}