 #include <iostream>
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
int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int count[300];
		n=str.length();
		memset(count,0,sizeof(count));
		for(i=0;i<n;i++)
			count[str[i]]++;
		for(i=0;i<n;i++)
		{
			if(count[str[i]]==1)
				str.erase(str.begin()+i+1);
		}
		cout<<str<<"\n";
		if(str.length()==0)
			cout<<"Non repating\n";
		else if(ispal(str))
		{
			j=str.length();
			if(j%2!=0 && (j>2)&& (j/2-1 >=0)&&str[j/2]==str[j/2-1])
				cout<<"Repatng\n";
			else
				cout<<"Non Repating\n";
		}
		else
			cout<<"Repating\n";
	}
}