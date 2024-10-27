 #include <iostream>
using namespace std;
int min(int a,int b)
{
	return (a>b?b:a);
}
void reformind(int index[],int one,int indexone,int two,int indextwo)
{
	index[one]=indexone;
	index[two]=indextwo;
}
void swap(int *a,int *b)
{
	int tmp;
	tmp=(*a);
	(*a)=(*b);
	(*b)=tmp;
}
int minutil(int arr[],int brr[],int index[],int i,int n)
{
	if(i>n)
	{
		return 0;
	}
	if(brr[arr[i]]==arr[i+1])
		return minutil(arr,brr,index,i+2,n);
	int one =arr[i+1];
	int indextwo=i+1;
	int two=arr[index[brr[arr[i]]]];
	int indexone=index[brr[arr[i]]];
	swap(arr[i+1],arr[indexone]);
	reformind(index,one,indexone,two,indextwo);
	int a=minutil(arr,brr,index,i+2,n);
	swap(&arr[i+1],&arr[indexone]);
	reformind(index,one,indexone,two,indextwo);
	 one =arr[i];
	indextwo=i;
	 two=arr[index[brr[arr[i+1]]]];
	 indexone=index[brr[arr[i+1]]];
	 int b=minutil(arr,brr,index,i+2,n);
	 swap(&arr[i],&arr[indexone]);
	reformind(index,one,indexone,two,indextwo);
	return 1+min(a,b);
}
int minswap(int arr[],int brr[],int n)
{
	int index[2*n];
	for(int i=1;i<=n;i++)
	{
		index[arr[i]]=i;
	}
	return minutil(arr,brr,index,1,n);
}
int main()
{
    int i,n,j,t,arr[1000],brr[1000];
    cin>>n;
    arr[0]=0;
    for(i=1;i<=n;i++)
    {
    	cin>>arr[i];
    }
    brr[0]=0;
    for(i=1;i<=n;i++)
    {
    	cin>>brr[i];
    }
    cout<<minswap(arr,brr,n)<<"\n";
	return 0;
}