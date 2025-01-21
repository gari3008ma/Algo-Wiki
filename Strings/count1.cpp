 #include <iostream>
using namespace std;
int main()
{
	int t;
	char c;
	string str;
	cin>>t;
	while(t--)
	{
	    cin>>str;
	    cin>>c;
	    cout<<count(str.begin(),str.end(),c)<<"\n";
	    str.clear();
	}
}