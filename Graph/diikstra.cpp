 #include <iostream>
using namespace std;
#define inf INT_MAX
int search(int arr[],int n,bool vec[])
{
	int index,i,j,m=INT_MAX;
	for(i=0;i<=n;i++)
	{
		if(vec[i]==false && m>arr[i])
		{
				m=arr[i];
				index=i;
		}
	}
	return index;
}
int main()
{
	int arr[100][100],i,j,k,n,t,s;
	cin>>t;
	while(t--)
	{
		cin>>n;
			for(i=0;i<=n;i++)
		{
				for(j=0;j<=n;j++)
					cin>>arr[i][j];
		}
			int key[100];
			bool vec[100];
			for(i=0;i<=n;i++)
				{
					key[i]=INT_MAX;
					vec[i]=false;
				}
				key[0]=0;
		    for(i=0;i<=n;i++)
		    {
		    	j=search(key,n,vec);
		    	vec[j]=true;
		    	for(k=0;k<=n;k++)
		    	{
		    		if(arr[j][k] && vec[k]==false && key[j]!=INT_MAX && key[k]>arr[j][k]+key[j])
		    		{
		    			key[k]=arr[j][k]+key[j];
		    		}
		    	}
		    }
		    for(i=0;i<=n;i++)
		    {
		    	cout<<i<<" Weight min  are "<<key[i]<<" \n";
		    }
	}
   return 0;
}