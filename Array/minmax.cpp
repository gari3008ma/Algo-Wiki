#include<stdio.h>
//#define reps(i,a,n) for(int i=a;i<n;i++)
struct pair
{
	int minu;
	int maxi;
};
struct pair mm(int arr[],int start,int end)
{
	        struct pair p;
			if(start==end)
			{
				
				p.minu=arr[start];
				p.maxi=arr[start];
				return p;
			}
			if((end-start)==1)
			{
				
				p.minu=(arr[start] < arr[end] ? arr[start]:arr[end] );
				p.maxi=(arr[start] > arr[end] ? arr[start]:arr[end] );
				return p;
			}
			else
				{
					int mid=(start+end)/2;
				struct pair p1=mm(arr,start,mid);
				struct pair p2=mm(arr,mid+1,end);

				
				if(p1.minu > p2.minu)
					p.minu =p2.minu;
				else
					p.minu=p1.minu;

				if(p1.maxi >p2.maxi)
					p.maxi=p1.maxi;
				else
					p.maxi =p2.maxi;
				return p;
			
			}
}
int main()
 {
	int t,i,n,a[10000];
	scanf("%d",&t);
	while(t--)
	{
	       scanf("%d",&n);
	       	       for(i=0;i<n;i++)
	       {
	         scanf("%d",&a[i]);
	       }
	       struct pair l=mm(a,0,n-1);
           printf("%d %d\n",l.minu,l.maxi);
	}
	return 0;
}