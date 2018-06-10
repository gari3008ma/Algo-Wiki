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
struct node*rev(struct node *head)
{
                if(head==NULL || head->next==NULL)
                       return head;
              struct node *tmp=rev(head->next);
              head->next->next=head;
              head->next=NULL;
              return tmp;     
} 
void cop(struct node **head,struct node *tmp)
{
    if((*head)==NULL)
    {
        tmp->next=NULL;
        (*head)=tmp;
    }
    else
    {
        struct node *vm=(*head);
        while(vm->next!=NULL)
        {
            vm=vm->next;
        }
        vm->next=tmp;
        tmp->next=NULL;
    }
}
struct node *sortmerg(struct node *head1,struct node *head2)
 {
                head1=rev(head1);
                head2=rev(head2);
                struct node *tmp,*c,*head3=NULL;
                while(head1!=NULL && head2!=NULL)
                {
                    if(head1->key >head2->key)
                    {
                        c=head1;
                        head1=head1->next;
                        cop(&head3,c);
                    }
                    else if(head2->key >head1->key)
                     {   c=head2;
                        head2=head2->next;
                        cop(&head3,c);
                    }
                    else
                    {
                        c=head2;
                        head2=head2->next;
                        cop(&head3,c);
                         c=head1;
                        head1=head1->next;
                        cop(&head3,c);
                    }
                }
                if(head2!=NULL)
                {
                    struct node *vm=(head3);
                     while(vm->next!=NULL)
                     {
                                vm=vm->next;
                    }
                                 vm->next=head2;
                }
                if(head1!=NULL)
                {
                    struct node *vm=(head3);
                     while(vm->next!=NULL)
                     {
                                vm=vm->next;
                    }
                                 vm->next=head1;
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