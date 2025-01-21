 #include <iostream>
using namespace std;
void swap(int* a,int *b)
{
	int tmp;
	tmp=(*a);
	(*a) = (*b);
	(*b)=tmp;
}
void pivot(int arr[],int start,int end)
{
	int x=0,first=start,second=start+1,i;
	while(first<end && second<end)
	{
			if(arr[first]>=x)
			{
				swap(&arr[first],&arr[second]);
				second++;
			}
			else
			{
				first++;
				second++;
			}
	}
	second=first+1;
	first=start;
	cout<<"\n";
	while(first < second && second <end && arr[first]<0)
	{
		swap(&arr[first],&arr[second]);
		first=first+2;
		second=second+1;
	}
}
int main()
{
	int n,arr[100],i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	pivot(arr,0,n);
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
}