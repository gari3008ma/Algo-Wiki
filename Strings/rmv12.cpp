 #include <iostream>
using namespace std;
bool isrot(string src,string rrc)
{
	string tmp;
	tmp=src+src;
	void *ptr;
	
	if(tmp.find(rrc)!=  string ::npos)
		return true;
	else
	return false;
}
int main()
{
	int i,j,k;
	string src,rrc;
	cin>>src;
	cin>>rrc;
	if(isrot(src,rrc))
		cout<<"Yes\n";
	else
		cout<<"No\n";

}