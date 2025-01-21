 #include <iostream>
using namespace std;

int dp_sol(int n,int a,int b,int c)
{
	if(n<0)
 	return 0;
	if(n==0)
		return 1;
	dp_sol(n-a,a,b,c);
	dp_sol(n-a-b,a,b,c);
	dp_sol(n-a-b-c,a,b,c);
	dp_sol(n-b,a,b,c);
	dp_sol(n-c,a,b,c);
	return max(1+dp_sol(n-a,a,b,c),max(1+dp_sol(n-b,a,b,c),1+dp_sol(n-c,a,b,c)));
}
int main()
{
		int n,t,a,b,c,k;
		cin>>t;
		while(t--)
		{
			cin>>n>>a>>b>>c;
			cout<<dp_sol(n,a,b,c)<<"\n";
		}
}
