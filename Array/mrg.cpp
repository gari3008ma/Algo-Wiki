 #include <iostream>
using namespace std;
void swap(int *a,int *b)
{
	int tmp;
	tmp=(*a);
	(*a)=(*b);
	(*b)=tmp;
}
void rev(int arr[],int s,int e)
{
     while(s<e)
     {
     	swap(&arr[s],&arr[e]);
     	s++;
     	e--;
     }
}
int main()
{
	int t,n,arr[1000],i,j,size,count;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
   count=0;
		if(n%2==0)
		{
			size=n/2;
			rev(arr,n/2,n-1);
			i=0;
			j=size;
			while(i<size && j<n)
			{
				if(arr[i]!=arr[j])
					count++;
				i++;
				j++;
			}
		}
		else
		{
			rev(arr,n/2+1,n-1);
			i=0;
			j=n/2+1;
				while(i<(n/2+1) && j<n)
				{
					if(arr[i]!=arr[j])
						count++;
					i++;
					j++;
				}
		}
		cout<<count<<"\n";
	}
}