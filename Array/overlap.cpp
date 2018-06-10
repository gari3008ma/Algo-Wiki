#include<stdio.h>
struct pair
{
	int first;
	int second;
};
int main()
{
	int t,n,i,j,k,l;
	pair arr[100],tmp[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&arr[i].first,&arr[i].second);
	    }
	    	for(i=1;i<n;i++)
		{
			k = arr[i].first;
			l = arr[i].second;
			j = i-1;
			while(j>=0 && arr[j].first > k)
			{
				arr[j+1].first=arr[j].first;
				arr[j+1].second=arr[j].second;
				j--;
			}
			arr[j+1].first=k;
			arr[j+1].second=l;
		}	
		for(i=0;i<n;i++)
		{
			printf("sorted array %d %d\n",arr[i].first,arr[i].second);
	    }
		j=0;
		tmp[j].first=arr[0].first;
		tmp[j].second=arr[0].second;
		for(i=1;i<n;i++)
		{
              if(arr[i].first<= tmp[j].second)
              {
              		tmp[j].second=arr[i].second;
              }
              else
              {
              	j++;
              	tmp[j].first=arr[i].first;
              	tmp[j].second=arr[i].second;
              }
		}
		for(i=0;i<=j;i++)
		{
			printf("%d %d ",tmp[i].first,tmp[i].second);
		}
		printf("\n");
	}
	return 0;
}
