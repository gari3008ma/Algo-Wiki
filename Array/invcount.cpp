 #include <iostream>
using namespace std;

int merg(int arr[],int tmp[],int low1,int mid,int high2)
{
	int high1=mid-1,low2=mid,i,j,k,count=0;
	i=low1;
	j=low2;
	k=0;
	while(i<=high1 && j<=high2)
	{
		if(arr[i]<=arr[j])
		{
				tmp[k]=arr[i];
				k++;
				i++;
		}
		else
		{
			tmp[k]=arr[j];
			j++;
			k++;
			count+=high1-i+1;
		}
	}
	if(i!=high1)
	{
		while(i<=high1)
		{
			tmp[k]=arr[i];
			k++;
			i++;
		}
	}
	else if(j!=high2)
	{
		while(j<=high2)
		{
			tmp[k]=arr[j];
			k++;
			j++;
		}
	}
	j=low1;
	for(i=0;i<k;i++)
		cout<<tmp[k]<<" ";
	cout<<"\n";
	for(i=0;i<k &&j<=high2;i++,j++)
	{
		arr[j]=tmp[k];
	}
	return count;
}
int count(int arr[],int temp[],int low,int high)
{
	int ivc =0;
	if(low>high)
		return 0;
	else
	{
		
		int mid=(low+high)/2;
		cout<<" value is "<<mid<<" "<<low<<" "<<high<<" ";
		 ivc=count(arr,temp,low,mid);
		ivc=ivc+count(arr,temp,mid+1,high);
		ivc=ivc +merg(arr,temp,low,mid,high);
		cout<<ivc <<" \n";
		
	}
	return ivc;
}
int mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return count(arr, temp, 0, array_size - 1);
}
int main()
{
	int t,i,n,arr[1000];
	cin>>t;
	while(t--)
	{
	  cin>>n;
	  for(i=0;i<n;i++)
	     cin>>arr[i];
	 cout<<mergeSort(arr,n)<<"\n";   
	}
}