#include<bits/stdc++.h>
using namespace std;
#define NA -1
int  movetoend(int mplusn[],int m1)
{
	int i,k,flag=0;
	for(i=m1-1;i>=0;i--)
	{
		flag=0;
		if(mplusn[i]==(NA))
		{
			for(k=i-1;k>=0;k--)
			{
				if(mplusn[k]!=(NA))
				{
					swap(mplusn[k],mplusn[i]);
					flag=1;
					break;
				}
			}
			if(flag==(0))
			{
				k=i;
				for(i=0;i<(m1);i++)
               {
  	                 printf("%d ",mplusn[i]);
                }
                printf("\n");
                return k;
			}	

		}
	}
}
void merge(int mplusn[],int n[],int ns,int ms,int start)
{
				int i=start+1,j=0,k=0,r;
				
				while(k<(ms+ns))
				{
					if((mplusn[i]<n[j])&&(i<(ms+ns)) || (j==ns))
					{
							mplusn[k]=mplusn[i];
							k++;
							i++;
					}
					else
					{
						mplusn[k]=n[j];
						j++;
						k++;
					}
				}
}
int main()
{
  int mplusn[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
  int n[] = {5, 7, 9, 25},i;
  int ns = sizeof(n)/sizeof(n[0]);
  int ms = sizeof(mplusn)/sizeof(mplusn[0]) - ns;
  int start = movetoend(mplusn, ms+ns);
  printf("%d\n",start);
  merge(mplusn, n, ms, ns,start);
  for(i=0;i<(ms+ns);i++)
  {
  	        printf("%d ",mplusn[i]);
  }
    printf("\n");
  return 0;
}