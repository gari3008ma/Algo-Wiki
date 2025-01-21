 #include <iostream>

using namespace std;
struct node
{
	bool iscom;
	struct node *child[2];
};
struct node *newnode()
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->iscom=false;
	tmp->child[0]=tmp->child[1]=NULL;
	return tmp;
}
bool insert(struct node **root,int mat[100][100],int r,int c,int i,int j)
{
	if((*root)==NULL)
		(*root)=newnode();
	if(j<c)
	{
			return insert(&((*root)->child[mat[i][j]]),mat,r,c,i,j++);
	}
	else
	{
		if(!((*root)->iscom))
		{
			return (*root)->iscom = 1;
		}
		return 0;
	}
}
void print(int mat[100][100],int r,int c)
{
	int i;
	for(i=0;i<c;i++)
	{
		cout<<mat[r][i]<<" ";
	}
	cout<<"\n";
}
int main()
{
	int t,r,c,i,j,mat[100][100];
	cin>>t;
	while(t--)
	{
		cin>>r>>c;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin>>mat[i][j];
			}
		}
		node *root=NULL;
       for(i=0;i<r;i++)
       {
       	     if(insert(&root,mat,r,c,i,0));
       	           print(mat,i,c);
       }
	}
	return 0;
}