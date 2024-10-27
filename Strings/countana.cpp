 #include <iostream>
using  namespace std;
int tonum(char c)
{
	int a=c-'a';
	return a;
}
int main()
{
	int t,i,j,sum,count,n;
	string str;
	cin>>t;
	while(t--)
	{
		cin>>str;
		map<vector<int> ,int> mp;
		n=str.length();
		for(i=0;i<n;i++)
		{
			vector<int> vec(26,0);
			for(j=i;j<n;j++)
			{
				vec[tonum(str[j])]++;
				mp[vec]++;
			}
		}
		map<vector<int> ,int>  :: iterator it;
		sum=0;
		count=0;
		for(it=mp.begin();it!=mp.end();it++)
		{
			count=it->second;
			sum=sum+(count*(count-1))/2;
		}
		cout<<sum<<"\n";
	}
}