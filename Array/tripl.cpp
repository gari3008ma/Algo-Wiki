#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,k,arr[1000],brr[1000],l,r,s,crr[1000],m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		for(i=0;i<n;i++)
			cin>>arr[i];
		for(i=0;i<m;i++)
			cin>>brr[i];
		for(i=0;i<k;i++)
			cin>>crr[i];
		l=0;
		r=0;
		s=0;
		while(l<n && r<m && s<k)
		{
			if(arr[l]==brr[r]&&brr[r]==crr[s])
			{
				cout<<arr[l]<<" "<<brr[r]<<" "<<crr[s]<<" ";
				l++;
				r++;
				s++;
			}
			else if(arr[l] < brr[r])
			{
					l++;
			}
			else if(brr[r]<crr[s])
			{
					r++;
			}
			else
				s++;
		}
		cout<<"\n";
	}
	return 0;
}