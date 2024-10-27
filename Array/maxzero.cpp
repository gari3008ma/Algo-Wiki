 #include <iostream>
using namespace std;
int main()
{
	int t,n,i,arr[1000],prv,prvprv,curr,max,ind;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		curr=0;
		prv=-1;
		prvprv=-1;
		for(curr=0;curr<n;curr++)
		{
			if(arr[curr]==0)
			{
				if((curr-prvprv) > max)
					{
						max=(curr-prvprv);
						ind=prv;
					}
					prvprv=prv;
					prv=curr;
			}
		}
		if((curr-prvprv) > max)
					{
						max=(curr-prvprv);
						ind=prv;
					}
					cout<<ind<<"\n";
	}
	return 0;
}