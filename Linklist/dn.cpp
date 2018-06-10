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
void deletn(struct node *head,struct node *tmp)
{
    struct node *pre,*post;
    if(head==NULL)
        return;
        if(tmp==head)
        {
                pre=head;
                post=head->next;
                while(post!=NULL)
                {
                        pre->data=post->data;
                        pre=post;
                        post=pre->next;
                }
                free(pre);
        }
        else
        {
                    pre=head;
                    while(pre->next!=tmp)
                    pre=pre->next;
                    pre->next=pre->next->next;
                    free(tmp);
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
    node * head = NULL,*tmp;
    Push_data(&head,3);
    Push_data(&head,4);
    Push_data(&head,6);
    Print(head);
    tmp=head->next;
    deletn(head,tmp);
    Print(head);
    return 0;
}
