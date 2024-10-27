 #include <iostream>
using namespace std;
int main()
{
	int i,j,n,arr[1000],start,end,p;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
    for(i=0;i<(n-1);i++)
    {
    	if(arr[i]>arr[i+1])
    		{
    			start=i;
    			break;
    		}
    }
    for(j=(n-1);j>=1;j--)
    {
    	if(arr[j]<arr[j-1])
    		{
    			end=j;
    			break;
    		}
    }
    if(start<end)
   {
           for(i=start;i<=end;i++)
           {
           	   p=arr[i];
           	   j=i;
           	        while(j>=start && arr[j]<arr[j-1])
           	        {
           	        	arr[j]=arr[j-1];
           	        	j--;
           	        }
           	        	arr[j]=p;
           }
           i=start-1;
           while(i>=0)
           {
           	if(arr[i]>arr[start])
           		start=i;
           	i--;
           }
           j=end;
           while(j<=(n-1))
           {
           	 if(arr[j] < arr[end])
           	 	end=j;
           	 j++;
           }
           cout<<start<<" "<<end<<" \n";
   }
}