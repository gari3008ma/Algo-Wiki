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
void cop(struct node **head,struct node *tmp)
{
    if((*head)==NULL||((*head)->key <tmp->key))
    {
        tmp->next=(*head);
        (*head)=tmp;
    }
    else
    {
        struct node *vm=(*head),*pre=(*head);
        while(vm->key > tmp->key && vm->next!=NULL)
        {
            pre=vm;
            vm=vm->next;
        }
        pre->next=tmp;
        tmp->next=vm;
    }
}
struct node *sortmerg(struct node *head1,struct node *head2)
 {
        if(head1==NULL && head2==NULL )
            return NULL;
                struct node *tmp,*c,*head3=NULL;
                tmp=head1;
                if(head1==NULL)
                {
                    head1=head2;
                }
                else if(head1!=NULL && head2!=NULL)
                {
                            tmp=head1;
                    while(tmp->next!=NULL)
                          tmp=tmp->next; 
                      tmp->next=head2;
                }  
                tmp=head1;
                while(tmp!=NULL)
                {
                    c=tmp->next;
                    cop(&head3,tmp);
                    tmp=c;
                }
                return head3;
 }
 void printList(struct node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->key << " ";
        Node = Node->next;
    }
}
int main()
{
    struct node* res = NULL;
    node *a = newNode(5);
    a->next = newNode(10);
    a->next->next = newNode(15);
 
    node *b = newNode(2);
    b->next = newNode(3);
    b->next->next = newNode(20);
 
    cout << "List A before merge: \n";
    printList(a);
 
    cout << "\nList B before merge: \n";
    printList(b);
 
    /* merge 2 increasing order LLs in descresing order */
    res = sortmerg(a, b);
 
    cout << "\nMerged Linked List is: \n";
    printList(res);
 
    return 0;
}