


 #include <iostream>
using namespace std;
int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		n=str.length();
		int count[300];
		memset(count,0,sizeof(count));
		for(i=0;i<n;i++)
		{
				count[str[i]]++;
		}
		j=0;
		for(i=0;i<300;i++)
		{
			if(count[i]%2!=0)
				j++;
		}
		if(j>1)
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
}