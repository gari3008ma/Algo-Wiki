 #include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node* next;
};
struct node *revrs(struct node *head)
{
                if(head==NULL ||head->next==NULL)
                    return head;
           struct node *tmp=revrs(head->next);
           head->next->next=head;
           head->next=NULL;
           return tmp;
}
struct node *seg(struct node *head1,struct node *head2)
{
        struct node *tmp,*pre,*post=NULL,*head3=NULL;
        vector<struct node *> a{100},b{100};
        int i=0,j=0,add=0,carry=0;
        tmp=head1;
        while(tmp!=NULL)
           {
                    a[i]=tmp;
                    tmp=tmp->next;
                    i++;
           }
           tmp=head2;
        while(tmp!=NULL)
           {
                    b[j]=tmp;
                    j++;
                    tmp=tmp->next;
           }
           i=i-1;
           j=j-1;

          while(i>=0 || j>=0)
          {
                     add=0;
                     if(i>=0)
                     {
                            pre=a[i];
                            i--;
                            add=add+pre->key;
                     }
                     if(j>=0)
                     {
                            pre=b[j];
                            add=add+pre->key;
                            j--;
                     }
                     carry=add/10;
                     struct node *p=(struct node *)malloc(sizeof(struct node));
                     p->next=post;
                     p->key=add%10+carry;
                      head3=p;
                      post=p;
          }
         return head3;
}
struct node *seg1(struct node *head1,struct node *head2)
{
                 struct node *tmp,*pre,*post=NULL,*head3=NULL;
                 int add=0,carry=0;
                 head1=revrs(head1);
                 head2=revrs(head2);
                 tmp=head1;
                 pre=head2;
                 while(tmp || pre)
                 {
                         add=0;
                         add=add+ (tmp?tmp->key:0);
                         add=add+ (pre?pre->key:0);
                         carry=add/10;
                     struct node *p=(struct node *)malloc(sizeof(struct node));
                     p->key=add%10+carry;
                     p->next=NULL;
                     if(head3==NULL)
                     {
                        head3=p;
                        post=p;
                     }
                     else
                     {
                          post->next=p;
                          post=p;
                     }
                     if(tmp!=NULL)
                     tmp=tmp->next;
                     if(pre!=NULL)
                     pre=pre->next;
                 }
                 head3=revrs(head3);
                 head1=revrs(head1);
                 head2=revrs(head2);
                 return head3;
}

void push(struct node** head_ref, int new_key)
{
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
    new_node->key  = new_key;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
int main()
{
    struct node* head1 = NULL,*head2=NULL,*tmp;
    push(&head1, 0);
    push(&head1, 0);
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 4);
    push(&head1, 4);
    tmp=head1;
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    push(&head2, 7);
    push(&head2, 6);
    push(&head2, 1);
    tmp=head2;
         printf("\n");
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    tmp=seg1(head1,head2);
     printf("\n");
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
     tmp=head2;
         printf("\n");
    while(tmp!=NULL)
    {
         printf("%d ",tmp->key);
         tmp=tmp->next;
    }
    return 0;
}
