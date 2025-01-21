 #include <iostream>
#include <cstdlib> // for malloc and free
using namespace std;
int main()
{
	long long int t,n,x,y,arr[10000],m,i;
	cin>>t;
	while(t--)
	{
			cin>>n>>m;
			x=0;y=0;
			for(i=0;i<n;i++)
			{
			    cin>>arr[i];
			    if(arr[i]>=(m/2))
			       x++;
			    else if(arr[i]<=(m/10))
			       y++;
			}
     if(x>=1 && y>=2)
     	cout<<"yes\n";
     else
     	cout<<"no\n";
	}
}