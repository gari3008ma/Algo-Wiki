 #include <iostream>
using namespace std;
#define R 4
#define C 4
int binary(int mat[R][C],int start,int end)
{
    
}
int rowwithmaxis(int mat[R][C])
{
	int i,j;
	for(i=0;i<R;i++)
	{
		j=binary(mat,0,C);
		if()
	}
}
int main()
{
	int i,j,k;
    bool mat[R][C] = { {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    
    printf("Index of row with maximum 1s is %d n", rowwithmaxis(mat));
 
    return 0;
}