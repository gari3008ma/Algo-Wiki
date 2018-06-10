#include<bits/stdc++.h>
using namespace std;
int countright(string str,int j)
{
	int len=str.length();
	int i,count=0;
	for(i=j+1;i<len;i++)
	{
		if(str[i]<str[j])
			count++;
	}
	return count;
}
int fact(int m)
{
	if(m<=1)
		return 1;
	return (m*fact(m-1));
}
int main()
{
	int t,i,len,m,sum;
	string str;
	cin>>t;
	while(t--)
	{
			cin>>str;
			len=str.length();
			m = fact(len);
			sum=1;
			for(i=0;i<len;i++)
			{
					m = m/(len-i);
					cout<<m<<" ";
                   sum=sum+(m*countright(str,i));
                  cout<<m<<" ";
			}
			cout<<sum<<"\n";
			str.clear();
	}
   return 0;
}