#include<bits/stdc++.h>
using namespace std;

class minheap
{
	int size;
	int arr[1000];
public:
	minheap(int brr[],int n)
	{
		size=n;
		for(int i=0;i<n;i++)
		{
			arr[i]=brr[i];
		}
	}
	void buildheap();
	void heapify(int x);
	int parent(int x)
	{
		return (x-1)/2;
	}
	int left(int x)
	{
		return(2*x+1);
	}
	int right(int x)
	{
		return (2*x+2);
	}
	void printheap();
};
void minheap::buildheap()
{
	int i=(size-1)/2;
      while(i>=0)
      {
      	heapify(i);
      	i--;
      }
      printheap();
}
void swap(int *a,int *b)
{
	int tmp=(*a);
	(*a)=(*b);
	(*b)=tmp;
}
void minheap::heapify(int i)
{
	int smallest=i;
	int l=(i*2+1);
	int r=(i*2+2);
	if(l<size && arr[l]<arr[smallest])
           smallest=l;
    if(r<size && arr[r]<arr[smallest])
           smallest=r;
    if(smallest!=i)
     {
           	    swap(&arr[smallest],&arr[i]);
           	   heapify(smallest);
     }   
}
void minheap :: printheap()
{
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
	int t,n,arr[1000],i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		minheap hp(arr,n);
		hp.buildheap();
	}
}