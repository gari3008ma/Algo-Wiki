 #include <iostream>
using namespace std;
int main()
{
    int t,n,i,j,arr[1000];
    cin>>n;
    for(i=0;i<n;i++)
    	cin>>arr[i];
    j=floorc(arr,0,n-1);
    if(j==(-1))
    	cout<<"not found\n";
    else
    	cout<<" "<<arr[j]<<"\n";
   
	return 0;
}