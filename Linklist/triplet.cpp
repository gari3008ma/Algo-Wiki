#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    node * next;
    int data;
}node;

void Push_node(node** head,node *n){
    node * tmp = *head;//point tmp where head is pointing
    if(tmp){
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = n;
    }else{
        *head = n;
    }

}
void trip(struct node *head1,struct node *head2,struct node *head3,int v)
{
                map<int,bool> a,b,c;
                int k,g;
                struct node*tmp;
            tmp=head1;
    while(tmp!=NULL)
    {
            a[tmp->data]=true;
            tmp=tmp->next;
    }
            tmp=head2;
    while(tmp!=NULL)
    {
            b[tmp->data]=true;
            tmp=tmp->next;
    }
            tmp=head3;
    while(tmp!=NULL)
    {
            c[tmp->data]=true;
            tmp=tmp->next;
    }
        map<int,bool> :: iterator it=a.begin();
        while(it!=a.end())
        {
                k=v-(*it).first;
                //cout<<k<<" ->"<<(*it).first<<"\n";
                map<int,bool> :: iterator ie=b.begin();
                while(ie!=b.end())
                {
                    g=k-(*ie).first;
                    if(c[g]==true)
                        cout<<(*it).first<<" "<<(*ie).first<<" "<<g<<"\n";
                    ie++;
                }
                it++;
        }
}
void Push_data(node ** head,int data){

    node * n = new node;
    n->data = data;
    n->next = NULL;
    Push_node(head,n);
}

void Print(node * head){
    node *tmp = head;
    while(tmp){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}
int main(){
    node * head1= NULL,*head2=NULL,*head3=NULL,*tmp;
    Push_data(&head1,12);
    Push_data(&head1,6);
    Push_data(&head1,29);
    Push_data(&head2,23);
    Push_data(&head2,5);
    Push_data(&head2,8);
    Push_data(&head3,90);
    Push_data(&head3,20);
    Push_data(&head3,59);
    Print(head1);
    Print(head2);
    Print(head3);
    trip(head1,head2,head3,101);
    return 0;
}
