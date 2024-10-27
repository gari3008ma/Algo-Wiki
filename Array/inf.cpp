 #include <iostream>
using namespace std;
int binary(int arr[],int low,int high,int x)
{
	if(low>high)
		return -1;
	else
	{
		int mid=low+high/2;
		if(arr[mid]==x)
			return mid;
		else if(arr[mid]<x)
			return binary(arr,mid+1,high,x);
		else
			return binary(arr,low,mid-1,x);
	}
}
int main()
{
	int n,i,t,arr[1000],l,r,val,key;
	cin>>t;
	while(t--)
	{
				cin>>n>>key;
			for(i=0;i<n;i++)
				{
					cin>>arr[i];
				}
			l=0;
			r=1;
			val=arr[0];
			while(val<key)
			{
				l=r;
				r=2*r;
				val=arr[r];
			}
			val=binary(arr,l,r,key);
			if(val!=(-1))
				cout<<"Found\n";
			else
				cout<<"Not Found\n";
	}
	return 0;
}