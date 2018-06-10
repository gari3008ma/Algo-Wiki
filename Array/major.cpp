#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vi> vvi; 
typedef vector<pii> vpii;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define traverse(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define SIZE 5009
int binary(int arr[],int start,int end,int x)
{
				if(start> end)
					return -1;
				int mid=(start+end)/2;
				if((arr[mid]==x)&&( mid==0 || (arr[mid-1]<x) ))
					return mid;
				else if(arr[mid]<x)
					return binary(arr,mid+1,end,x);
				else
					return binary(arr,start,mid-1,x);

}
bool ismajor(int arr[],int n,int x)
{
	int index=binary(arr,0,n-1,x);
	if(index==-1)
		return false;
	if(  (index+n/2<(n-1))&&arr[index+n/2]==x )
		  return true;
    else
          return false;		
}
int main()
{
	int t,n,i,arr[10000],x;
	cin>>n;
	for(i=0;i<n;i++)
         cin>>arr[i];
     cin>>x;
    if(ismajor(arr,n,x))
    	cout<<"Yes\n";
    else
    	cout<<"No\n";
}    
