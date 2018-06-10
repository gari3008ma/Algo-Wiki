#include<bits/stdc++.h>
#include<stdlib.h>
#include <time.h>
 using namespace std;
/* Link list node */
struct node
{
    int key;
    struct node* next;
};
 
struct node *newNode(int new_key)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->key  = new_key;
    new_node->next =  NULL;
 
    return new_node;
}
void push(struct node** head_ref, int new_key)
{
    /* allocate node */
    struct node* new_node = new node;
 
    /* put in the key  */
    new_node->key  = new_key;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}
 void rearrang(struct node *head)
 {
                    struct node *tmp=head,*cur,*v;
                    vector<struct node *> a;
                        while(tmp!=NULL)
                        {
                                a.push_back(tmp);
                                tmp=tmp->next;
                        }
                         vector<struct node *> :: iterator it =a.end()-1;
                        tmp=head;
                             while(tmp!=NULL && it!=a.begin() && tmp!=(*it))
                        {
                                cur=tmp->next;
                                tmp->next=(*it);
                                (*it)->next=cur;
                                *it--;
                                (*it)->next=NULL;
                                tmp=cur;
                        }
 }
int main()
{
    struct node *head = NULL,*u;
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);
    u=head;
    while(u!=NULL)
    {
        cout<<u->key<<" ";
        u=u->next;
    }
    cout<<" \n";
    rearrang(head);
    u=head;
    while(u!=NULL)
    {
        cout<<u->key<<" ";
        u=u->next;
    }
    cout<<" \n";
    return 0;
}