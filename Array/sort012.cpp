 #include <iostream>
using namespace std;
int main()
{
	int i,n,arr[100],mid=0,low=0,high;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	high=n-1;
	while(mid<=high)
	{
		if(arr[mid]==0)
		{
			arr[low] = arr[low] + arr[mid];
			arr[mid] = arr[low] - arr[mid];
			arr[low] = arr[low] - arr[mid];
			low++;
			mid++;
		}
		else if(arr[mid]==1)
		{
			mid++;
		}
		else if(arr[mid]==2)
		{
			arr[mid] = arr[high] + arr[mid];
			arr[high] = arr[mid] - arr[high];
			arr[mid] = arr[mid] - arr[high];
			high--;
		}
	}
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}