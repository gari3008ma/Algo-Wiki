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
void rot(struct node **head,int k)
{
    struct node *tmp=(*head),*post;
    int i=1;
    if((*head)==NULL)
        return;
    while(tmp!=NULL && i<k)
    {
             tmp=tmp->next;
             i++;
    }
    post=tmp->next;
    if((i)==k)
    {
            tmp->next=NULL;
            tmp=(*head);
            (*head)=post;
            while(post->next!=NULL)
                post=post->next;
            post->next=tmp;
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
    node * head = NULL;
    Push_data(&head,10);
    Push_data(&head,20);
    Push_data(&head,30);
    Push_data(&head,40);
     Push_data(&head,50);
      Push_data(&head,60);
    Print(head);
    rot(&head,4);
    Print(head);
    return 0;
}
