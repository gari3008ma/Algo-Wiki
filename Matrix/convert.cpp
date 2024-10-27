 #include <iostream>
using namespace std;
int main()
{
	int t,n,i,j,m;
	cin>>t;
	while(t--)
	 {
	 		cin>>n>>m;
	 		int l1=0,l2=0,arr[100][100],val=1,n1=n,m1=m;
	 		memset(arr,0,sizeof(arr));
	 		while(l1<n && l2<m)
	 		{
	 			for(i=l2;i<m;i++)
	 				arr[l1][i]=val;
	 			l1++;
	 			for(i=l1;i<n;i++)
	 				arr[i][m-1]=val;
	 			m--;
	 			if(l2<m)
	 			{
	 				for(i=m-1;i>=l2;i--)
	 					arr[n-1][i]=val;
	 				n--;
	 			}
	 			if(l1<n)
	 			{
	 				for(i=n-1;i>=l1;i--)
	 					arr[i][l2]=val;
	 				l2++;
	 			}
	 			val=1-val;
	 		}
	 		for(i=0;i<n1;i++)
	 		{
	 			for(j=0;j<m1;j++)
	 				cout<<arr[i][j]<<" ";
	 			cout<<"\n";
	 		}
	 }
    return 0;
}