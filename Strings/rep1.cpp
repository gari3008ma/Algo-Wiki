#include<bits/stdc++.h>
using namespace std;
bool ispal(string str)
{
	int l=0;
	int h=str.length()-1;
	while(l<h)
	{
		if(str[l]!=str[h])
			return false;
		l++;
		h--;
	}
	return true;
}
bool isrep(string str)
{
		int count[300],i,j=0,c=0;
		memset(count,0,sizeof(count));
		for(i=0;i<str.length();i++)
			{
				count[str[i]]++;
				if(count[str[i]] >=3)
					return true;
			}
		for(i=0;i<str.length();i++)
		{
				if(count[str[i]]>1)
				{
					str[j++]=str[i];
				}
		}
		str[j]='\0';
		if(ispal(str))
			{
					if(j%2!=0 )
					{
						if(str[j/2-1]==str[j/2])
							return true;
					}
					return false;
			}
			return true;
}
int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		if(isrep(str))
			cout<<"Repeating\n";
		else
			cout<<"Non-Repeating\n";
	}
	return 0;
}	