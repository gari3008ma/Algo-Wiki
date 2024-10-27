 #include <iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;
struct node
{
    char data;
    struct node* next;
};
struct node *findmid(struct node *head)
{
    int m=0,i=1;
    struct node *tmp=head;
    while(tmp!=NULL)
    {
               if(i%2!=0)
                        m++;
            i++;
            tmp=tmp->next;
    }
    i=1;
    tmp=head;
    while(i<m)
    {
         tmp=tmp->next;
         i++;
    }
    return tmp;
}
bool ispalindrome(struct node *head)
{
       struct node *tmp=findmid(head);
       struct node *vmp=reverseu(head,tmp);
       while(vmp!=head && )
}
void push(struct node** head_ref, char new_data)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node* head = NULL;
    char str[] = "abacaba";
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
       push(&head, str[i]);
       printList(head);
       ispalindrome(head)? printf("Is Palindrome\n\n"):
                           printf("Not Palindrome\n\n");
    }

    return 0;
}

