 #include <iostream>
using namespace std;
struct node
{
	char data;
	struct node *next;
	struct node *prev;
};
void append(char val,struct node **head,struct node **tail)
{
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
				tmp->data=val;
				tmp->prev=NULL;
				tmp->next=NULL;
		if((*head)==NULL &&(*tail)==NULL)
		{
				(*head)=tmp;
				(*tail)=tmp;
		}
		else 
		{
			tmp->prev=(*tail);
			(*tail)->next=tmp;
			tmp->next=NULL;
			(*tail)=tmp;
		}
}
void rmov(struct node * tmp,struct node **head,struct node ** tail)
{
			if(tmp==(*head))
			{
				(*head)=(*head)->next;
			}
			 if(tmp==(*tail))
			{
				(*tail)=(*tail)->prev;
				
			}
			 if(tmp->prev!=NULL)
			{
				tmp->prev->next=tmp->next;
				
			}
			if(tmp->next!=NULL)
			{
				tmp->next->prev=tmp->prev;
			}
				free(tmp);
			
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool visited[10000];
	struct node *arr[10000];
	struct node *head=NULL,*tail=NULL;
	char strm[505];
	int i;
	for(i=0;i<n;i++)
		cin>>strm[i];
	for(i=0;i<10000;i++)
	{
		visited[i]=false;
		arr[i]=NULL;
	}
	
	char c;
	i=0;
	while(i<n)
	{
			c=strm[i];
			if(visited[c]==false)
			{
				if(arr[c]==NULL)
				{
						append(c,&head,&tail);
						arr[c]=tail;
				}
				else
				{
					rmov(arr[c],&head,&tail);
					arr[c]=NULL;
					visited[c]=true;
				}
			}
			if(head!=NULL)
				cout<<head->data<<" ";
			else
				cout<<"-1 ";
			i++;
	}
	cout<<"\n";
}
}