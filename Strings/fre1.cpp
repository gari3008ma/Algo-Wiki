#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,j,count=0;
	string str;
	cin>>t;
	while(t--)
	{
			cin>>str;
			count=0;
			int freq[300]={0};
			for(i=0;i<str.length();i++)
			{
					freq[str[i]]++;
			}
			j=0;
			for(i=0;i<256;i++)
			{
					if(freq[i] > freq[j])
					{
						count=j;
					  j=i;
					}
					if(freq[i]!=freq[j] && freq[i]> freq[count])
					count=i;
			}
			char p=
			cout<<str[count]<<"\n";
			str.clear();
	}
}