#include<bits/stdc++.h>


using namespace std;
int max(int a,int b)
{
    return (a>b?a:b);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,i,arr[1000],curr,maxsum,sum;
   cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>arr[i];
        maxsum=INT_MIN;
        sum=0;
        curr=arr[0];
        for(i=1;i<n;i++)
        {
            if(curr > maxsum)
                {
                    maxsum=curr;
                   // cout<<maxsum<<" ";
                }
            if(curr<0)
                curr=0;
            curr=curr+arr[i];
        }
        if(curr > maxsum)
                {
                    maxsum=curr;
                    //cout<<maxsum<<" ";
                }
        cout<<maxsum<<" ";
        maxsum=INT_MIN;
        sort(arr,arr+n);
        curr=arr[n-1];
        for(i=n-2;i>=0;i--)
        {
            if(maxsum<curr)
                maxsum=curr;
            curr=curr+arr[i];
        }
        if(maxsum<curr)
                maxsum=curr;
        cout<<maxsum<<"\n";
    }
    return 0;
}