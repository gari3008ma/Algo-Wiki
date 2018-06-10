
#include<bits/stdc++.h>
using namespace std;
bool ispal(char str[],int s,int e)
{
			if(s==e)
				return true;
			while(s<e)
			{
				if(str[s]!=str[e])
					return false;
				s++;
				e--;
			}
			return true;
}
int main()
{
	int q,start,end,count;
	char str[1000];
	cin>>str;
	cin>>q;
	while(q--)
	{
		cin>>start>>end;
		if(ispal(str,start,end))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}