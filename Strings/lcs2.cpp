#include<bits/stdc++.h>
using namespace std;
void lcsone(string str,string ptr)
{
	int len=str.length(),len1=ptr.length(),i,j;
	int dp[len+1][len1+1];
	memset(dp,0,sizeof(dp));
	string res,p,q;
	for(i=0;i<=len;i++)
	{
		for(j=0;j<=len1;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(str[i-1]==ptr[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	while(i>=0 && j>=0)
	{
		if(str[i-1]==ptr[j-1])
				{
					res=res+str[i-1];
					i--;
					j--;
				}
		else if(dp[i-1][j] > dp[i][j-1])
		{
			i--;
		}	
		else
			j--;
	}
	cout<<res<<"\n";
	j=0;
	int k;
 /*for(i=0;i<len;i++)
 {
 			if(res[j]!=str[i])
 				str[k++] = str[i]
 }
 */
  res=res+q+p;
  cout<<res<<"\n";
}
int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
			string str,ptr;
			cin>>str>>ptr;
			lcsone(str,ptr);
	}
	return 0;
}