 #include <iostream>
using namespace std;
int main()
{
	int t,n,arr[1000],i,index,k,tmp[1000],arr2[1000],m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)
			cin>>arr[i];
		for(i=0;i<m;i++)
			cin>>arr2[i];
		sort(arr,arr+n);
		map<int,int>mp;
		for(i=0;i<n;i++)
			mp[arr[i]]++;
		k=0;
		for(i=0;i<m;i++)
		{
			if(mp[arr2[i]]>0)
			{
				while(mp[arr2[i]])
				{
					tmp[k]=arr2[i];
					mp[arr2[i]]--;
					k++;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(mp[arr[i]]>0)
			{
				while(mp[arr[i]])
				{
					tmp[k]=arr[i];
					mp[arr[i]]--;
					k++;
				}
			}
		}
		for(i=0;i<k;i++)
			arr[i]=tmp[i];
		for(i=0;i<k;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
	}
		return 0;
}