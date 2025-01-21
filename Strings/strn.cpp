 #include <iostream>
using namespace std;
bool ispal(char str[],int s,int e)
{
	while(s<=e)
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
	int t,n,i,start,maxln;
	cin>>t;
	while(t--)
	{
	    char str[100];
			cin>>str;
			start=0;
			n=strlen(str);
			for(i=0;i<n-1;i++)
			{
				if(str[i]!=str[i+1])
					break;
			}
			if(i==(n-1))
				maxln=0;
			else if(ispal(str,0,n))
			maxln=strlen(str)-1;
            else
            	maxln=n;
		cout<<maxln<<"\n";
	}

	return 0;
}