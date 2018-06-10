#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
	if(n==0)
		return 1;
	return n*fact(n-1);
}
int main()
{
	int t,n,i,count[30],p;
	string str;
	cin>>t;
	while(t--)
	{
			cin>>str;
			n=str.length();
			memset(count,0,sizeof(count));
			p=1;
			for(i=0;i<n;i++)
			{
					count[str[i]-'a']++;
					p=p*(i+1);
			}
			for(i=0;i<30;i++)
			{
				if(count[i]>0)
				{
					p=p/(count[i]);
				}
			}
			cout<<p<<"\n";
	}
}