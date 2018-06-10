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

int main(){
	int i,n,arr[1000],brr[1000],low,high;
	map <int,int> d;
	cin>>n;
   rep(i,n);
   {
   	cin>>arr[i];
   	brr[i]=arr[i];
    d[brr[i]]=d[brr[i]]+1;
   }
   low=0;
   high=n-1;
  while(low<high)
{
	    while(arr[low]==0 && low<high)
	    	low++;
	    while(arr[high]==1 && low<high)
	    	high--;
	  if(low<high)
	  { 
	  	arr[low]=0;
	  	arr[high]=1;
	   low++;
	   high--;
	  }
}
rep(i,n)
{
	cout<<brr[i]<<" ";
}
	return 0;
}