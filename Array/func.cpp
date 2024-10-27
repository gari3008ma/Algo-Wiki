 #include <iostream>
using namespace std;
int function(int x)
{
	return (x*x + 2*x -45);
}
int findpos(int i)
{
	while(function(i)<=0)
		i++;
	return i;
}
int binary(int low,int high)
{
	if(low > high)
		return -1;
	else
	{
		int mid= (low+high)/2;
		if(function(mid)>0 &&(function(mid-1)<0 || mid==low))
			return mid;
		else if(function(mid)>0)
			return binary(low,mid-1);
		else 
			return binary(mid+1,high);
	}
}
int main()
{
	int n,i,j;
    i=findpos(0);
    cout<<binary(i/2,i)<<" ";
}