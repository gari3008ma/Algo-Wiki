 #include <iostream>
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
				int i,j=0,k,r;
				for(i=start+1; i<(ms+ns);i++)
				{
						if(mplusn[i] > n[j] &&start>=0)
						{
							for(k=start;k<(i-1);k++)
							{
								swap(mplusn[k],mplusn[k+1]);
							}
						    start=start-1;
							mplusn[i-1]=n[j];
							i--;
						}
						else if(mplusn[i] <= n[j] && start >=0)
						{
							for(k=start;k<(i);k++)
							{
								swap(mplusn[k],mplusn[k+1]);
							}
							start=start-1;
							mplusn[i]=n[j];
							
						}
						for(r=0;r<(ms+ns);r++)
                   {
  	                       printf("%d ",mplusn[r]);
                   }
                       printf("\n");
                       
						j++;
                      if(j>=ns)
                      	break;
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