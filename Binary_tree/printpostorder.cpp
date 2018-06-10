#include <iostream>
using namespace std;
             int findingmax(int arr[],int a,int n)
{
            int i;
               for(i=0;i<n ;i++)
               {
                    if(arr[i] == a)
                    {
                        return i;
                    }
               }
               return -1;
}
void printpostorder(int in[],int pre[],int n)
{
            int root=findingmax(in,pre[0],n);
            if(root<0)
               return;
            printpostorder(in,pre+1,root);
            printpostorder(in+root+1,pre+root+1,n-root-1);
            
}
int main()
{
   int in[] = {4, 2, 5, 1, 3, 6};
   int pre[] =  {1, 2, 4, 5, 3, 6};
   int n = sizeof(in)/sizeof(in[0]);
   cout << "Postorder traversal " << endl;
   printpostorder(in, pre, n);
   return 0;
}

