 #include <iostream>
using namespace std;
void swap ( int* a, int* b )
{
    int t = (*a);
    (*a) = (*b);
    (*b) = t;
}
 
/* This function is same in both iterative and recursive*/
int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h-1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
void quicksort(int arr[],int low,int high)
{
	     int tmp,mpm,index;
         stack<int> st;
         st.push(low);
         st.push(high);
         while(!st.empty())
         {
              tmp=st.top();
              st.pop();
              mpm=st.top();
              st.pop();
              index=partition(arr,mpm,tmp);
              if((index-1) > mpm)
              {
              	st.push(mpm);
              	st.push(index-1);
              }
              if(tmp > (index+1))
              {
              	st.push(index+1);
              	st.push(tmp);
              }
         }
         
}
	int main()
{
	int n,arr[100],i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	quicksort(arr,0,n-1);
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
}