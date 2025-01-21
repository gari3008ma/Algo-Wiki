#include <iostream>
using namespace std;
int i,j,arr[100],n;
int isempty()
{
          if(j==i)
          return 1;
          else
          return 0;
}
int dequeu()
{
           int p;
      if(!isempty())
         {
              p=arr[j];
              j++;
              return p;
         }
      else
      return 0;
}
void enque(int a)
{
        if(i>=n)
        {
            printf("cann't fill queue\n");
                return ;
        }
        else
        {
            arr[i]=a;
            i++;
        }
}

int isfull()
{
     if(i==n)
     return 1;
     else
     return 0;

}
int main()
{
        int t,a;
        n=10;
        while(1)
        {
                    printf("choose 1 for insertion\n");
                    printf("choose 2 for deletion\n");
                    printf("choose 3 for to check empty queue\n");
                    printf("choose 4 for to check full queue\n");
                    cin>>a;
                  switch(a)
                  {
                            case 1:enque(a);
                                   break;
                            case 2:cout<<dequeu()<<" extracted element \n";
                                   break;
                            case 3:cout<<isempty()<<" value of empty\n";
                                   break;
                            case 4:cout<<isfull()<<" \n";
                                   break;
                            default: break;
                  }
        }
           return 0;
}
