 #include <iostream>
using namespace std;
struct stac
{
	int data;
	struct stac *next;
};
bool isempty(struct stac *st)
{
	if(st==NULL)
		return true;
	else
		return false;
}
void push(struct stac **st,int x)
{
		struct stac *tmp=(struct stac *)malloc(sizeof(struct stac));
		tmp->data = x;
		tmp->next=NULL;
		tmp->next=(*st);
			(*st)=tmp;
}
int pop(struct stac **st)
{
	int x;
		struct stac *tmp=(*st);
		x=(*st)->data;
		(*st)=(*st)->next;
		free(tmp);
		return x;
	}
int top(struct stac *st)
{
          return (st->data);
}
void inserts(struct stac **st,int val)
{
	if(isempty((*st)) || (*st)->data <=val)
	{
		push(st,val);
		return;
	}
	
		int t=pop(st);
	inserts(st,val);
	push(st,t);
}
void sort(struct stac ** st)
{
		if(isempty((*st)))
			return ;
		int x=pop(st);
		sort(st);
		inserts(st,x);
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
        struct stac *st=NULL;
        push(&st,1);
        push(&st,34);
        push(&st,2);
        sort(&st);
        while(st!=NULL)
        {
        	cout<<st->data<<" ";
        	st=st->next;
        }
   }
	return 0;
}