 #include <iostream>
using namespace std;
int main()
{
	int t,n,i,arr[100],sum,f;
	map<int,bool> mp;
	cin>>t;
	while(t--)
	{
              cin>>n;
              for(i=0;i<n;i++)
              {
					cin>>arr[i];
			   }
			   sum=0;
			   f=0;
			   for(i=0;i<n;i++)		
			   {
			   	   sum=sum+arr[i];
			   	   if(sum==0 ||mp[sum]==true)
			   	   {
			   	   	  cout<<"Found\n";
			   	   	  f=1;
			   	   	  break;
			   	   }
			   	   mp[sum]=true;
			   }
			   	if(f==0)
			   		cout<<"NOt found\n";
			   	mp.clear();
	}
	return 0;
}