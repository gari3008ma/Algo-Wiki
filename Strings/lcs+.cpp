 #include <iostream>
using namespace std;
int toint(char p)
{
    return (p-'a');
}
int max(int c,int d)
{
	return (c>d? c:d);
}
int main()
 {
	int t,i,j,lcs[109][109],lcs1[109][109],n,m;
	string str,str1;
	cin>>t;
	while(t--)
	{
	    cin>>str>>str1;
	    n=str.length();
	    m=str1.length();
	    vector<int> topos[m+1];
	    for(i=1;i<=m;i++)
	    {
	        topos[toint(str1[i-1])].push_back(i);
	    }
	    for(i=0;i<=n+1;i++)
	    {
	        for(j=0;j<=m+1;j++)
	           {
	               lcs[i][j]=0;
	               lcs1[i][j]=0;
	           }
	    }
	    int count=0;
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=m;j++)
	        {
	            if(str[i-1]==str1[j-1])
	            {
	                lcs[i][j]=lcs[i-1][j-1]+1;
	            }
	            else
	            {
	                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
	            }
	        }
	    }
	    for(i=n;i>=1;i--)
	    {
	        for(j=m;j>=1;j--)
	        {
	            if(str[i-1]==str1[j-1])
	            {
	                lcs1[i][j]=lcs1[i+1][j+1]+1;
	            }
	            else
	            {
	                lcs1[i][j]=max(lcs1[i][j+1],lcs1[i+1][j]);
	            }
	        }
	    }
	    for(i=0;i<=n;i++)
	    {
	        for(char k='a';k<='z';k++)
	        {
	            for(j=0;j<(topos[toint(k)].size());j++)
	                 {
	                     int p=topos[toint(k)][j];
	                     if(lcs[i][p-1]+lcs1[i+1][p+1]==lcs[n][m])
	                        count++;
	                 }
	        }
	    }
	   // cout<<lcs[n][m]<<" "<<lcs1[n][m];
	    cout<<count<<"\n";
	    str.clear();
	    str1.clear();
	}
	return 0;
}