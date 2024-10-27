 #include <iostream>
using namespace std;
void srt(int arr[],int start1,int high1,int start2,int high2)
{
	int i=start1,j=start2+1,k=0,tmp[1000];
	while(i<= high1 && j<= high2)
	{
		if(arr[i]==arr[j])
		{
			tmp[k]=arr[i];
			k++;
			i++;
			tmp[k]=arr[j];
			k++;
			j++;
		}
		else if(arr[i]<arr[j])
		{
			tmp[k]=arr[i];
			k++;
			i++;
		}
		else 
		{
			tmp[k]=arr[j];
			k++;
			j++;
		}
	}
	if(i<high1)
	{
		while(i<high1)
		{
			tmp[k]=arr[i];
			k++;i++;
		}
	}
	if(j<high2)
	{
		while(j<high2)
		{
			tmp[k]=arr[j];
			k++;
			j++;
		}
	}
	j=0;
	i=start1;
	while(i<high2 && j<k)
		{
			arr[i]=tmp[j];
			j++;
			i++;
			cout<<" hello";
		}
		cout<<"\n";
}
void merg(int arr[],int low,int high)
{
	if(low>high)
		return ;
	else
	{
		int mid=(low + high)/2;
		merg(arr,low,mid);
		merg(arr,mid+1,high);
		srt(arr,low,mid,mid+1,high);
		cout<<" hello";
	}
}
int main()
{
	int arr[100],i,n,j,diff,flag=0;
	cin>>n>>diff;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
    }
    merg(arr,0,n-1);
    i=0;
    j=1;
    while(i<n && j<n)
    {
    	if(arr[j]-arr[i]==diff)
    		{
    			flag=1;
    			break;
    		}
    	else if((arr[j]-arr[i]) > diff)
    	{
    		i++;
    	}
    	else
    		j++;
    }
    if(flag==0)
    	cout<<"-1\n";
    else
    	cout<<j<<" "<<i<<"\n";
    return 0;
}    		