 #include <iostream>
using namespace std;
int countway(int n,int s)
{
	if(n==0)
		return 1;
	if(n<0 || s>n)
		return 0;
	return countway(n-s,s+1)+countway(n,s+1);
}
int main()
{
		long long int n,m,i,j;
		cin>>n>>m;
		cout<<countway(n,m);
}
