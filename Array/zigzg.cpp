 #include <iostream>
using namespace std;
void swp(int *a,int* b)
{
	int c;
	c=(*a);
	(*a)=(*b);
	(*b)=c;
}
int main()
{
	int n,i,t,arr[1000],flg;
	cin>>t;
	while(t--)
	{
				cin>>n;
			for(i=0;i<n;i++)
				{
					cin>>arr[i];
				}
				flg=true;
			for(i=0;i<n-1;i++)
			{
				if(flg)
				{
					if(arr[i+1]<arr[i])
					swp(&arr[i+1],&arr[i]);
				}
				else
				{
					if(arr[i+1]>arr[i])
					swp(&arr[i+1],&arr[i]);
				}
					flg=!flg;
			}
			for(i=0;i<n;i++)
				cout<<arr[i]<<" ";
			cout<<"\n";
	}
	return 0;
}