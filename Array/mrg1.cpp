 #include <iostream>
using namespace std;
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
   for(i=0,j=n-1; i<=j;)
   {
   	if(arr[i]==arr[j])
   	{
   		i++;
   		j--;
   	}
   	else if(arr[i]>arr[j])
   	{
   		j--;
   		arr[j]+=arr[j+1];
   		count++;
   	}
   	else
   	{
   		arr[i+1]+=arr[i];
   		i++;
   		count++;
   	}
   }
   cout<<count<<"\n";
}
}