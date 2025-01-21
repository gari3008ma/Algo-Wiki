#include<iostream>
 #include <iostream>
using namespace std;
int max(int a,int b)
{
	return (a>b ?a:b);
}
int main()
 {
	long long int arr[100],n,t,i,current,max_sofar,min_sofar,tmp;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(i=0;i<n;i++)
	        cin>>arr[i];
	    max_sofar=1;
	    min_sofar=1;
	    current = INT_MIN;
	    for(i=0;i<n;i++)
	    {
	           if(arr[i]>0)
	           {
	                max_sofar=max_sofar*arr[i];
	                min_sofar=max(min_sofar,1);
	           }
	           else if(arr[i]==0)
	           {
	           		max_sofar=1;
	                min_sofar=1;
	           }
	           else
	           {
	           			tmp=max_sofar;
	           			max_sofar=max(max_sofar*arr[i],1);
	           			min_sofar=tmp*arr[i];
	           }
	           if(current<max_sofar)
	           current=max_sofar;
	    }
	    cout<<current<<"\n";
	}
	return 0;
}