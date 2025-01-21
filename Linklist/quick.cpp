 #include <iostream>
using namespace std;
int findpiv(int a[],int l,int h)
{
	int p=l,i=l+1,c;
   while(i<=h)
   {
          
          i++;
   }
   //cout<<"\n";
   return p;
}
void quicksort(int a[],int l,int h)
{
    if(l>=h)
       return ;
   //cout<<"k";
	int pivot=findpiv(a,l,h);
	cout<<pivot<<" pivot->";
	quicksort(a,l,pivot-1);
	quicksort(a,pivot+1,h);
	//cout<<" l"<<l<<" h"<<h<<" \n";
}
 int main()
 {
    int a[100],i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
 }