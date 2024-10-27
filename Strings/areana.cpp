 #include <iostream>
using namespace std;
int main()
{
	int t,i,flag;
	cin>>t;
	while(t--)
	{
	       char str[1000];
	       char str1[1000];
	       cin>>str>>str1;
	       int count[256]={0};
	       int count1[256]={0};
	       for(i=0;str[i]&&str1[i];i++)
	       {
	       			count[str[i]]++;
	       			count1[str1[i]]++;
	       }
	       flag=0;
	       if(str[i]||str1[i])
	       	cout<<"No\n";
	       else
	       {	
	       for(i=0;i<256;i++)
	       {
	          if(count[i]!=count1[i])
	              {
	                 cout<<"NO\n";
	                 break;
	              }
	       }
	       if(i==256)
	       {
	       			cout<<"YES\n";
	       }
	   }
	}
}