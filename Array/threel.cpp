 #include <iostream>
using namespace std;
int main()
{
	int arr[1000],min=0,sml[1000],i,max,n,lrg[10];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		sml[i]=0;
		lrg[i]=0;
	}
	min=0;
	max=n-1;
	sml[0]= -1;
	for(i=1;i<n;i++)
	{
		 if(arr[i]<=arr[min])
		 {
		 	min=i;
		 	sml[i]=-1;
		 }
		 else
		 	sml[i]=min;
	}
	lrg[n-1]=-1;
	for(i=n-1;i>=0;i--)
	{
		 if(arr[i]>=arr[max])
		 {
		 	max=i;
		 	lrg[i]=-1;
		 }
		 else
		 	lrg[i]=max;
	}
	for(i=0;i<n;i++)
	{
		if(sml[i]!=(-1)&& lrg[i]!=(-1))
		{
			printf("%d %d %d\n",arr[sml[i]],arr[i],arr[lrg[i]]);
				break;
		}
	}
	return 0;
}
