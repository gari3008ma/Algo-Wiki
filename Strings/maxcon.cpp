#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,j;
	string str[100],ptr;
	cin>>t;
	while(t--)
	{
			cin>>n;
			map<string,vector<int > > mp;
			for(i=0;i<n;i++)
			{
				  cin>>str[i];
			}
			for(i=0;i<n;i++)
			{
					ptr=str[i];
					sort(ptr.begin(),ptr.end());
					mp[ptr].push_back(i);
			}
			map<string,vector<int > > ::  iterator it = mp.begin();
			vector<int> :: iterator vt;
			for(;it!=mp.end();it++)
			{
				for(vt=((*it).second.begin());vt!=(*it).second.end();vt++)
				{
						cout<<str[*vt]<<" ";
				}
				cout<<"\n";
			}
	}
}