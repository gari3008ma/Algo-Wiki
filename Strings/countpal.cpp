 #include <iostream>
using namespace std;
int min(int a,int b)
{
	    return (a>b?b:a);
}
int count(string str,int l,int h)
{
	int n=str.length();
	int i,gap,j;
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	for(gap=1;gap<n;gap++)
	{
		for(i=0,j=gap;j<n;i++,j++)
		{
			if(str[i]==str[j])
				dp[i][j]=dp[i+1][j-1];
			else
				dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
		}
	}
	return dp[0][n-1];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		cout<<count(str,0,str.length()-1)<<"\n";
	}
}