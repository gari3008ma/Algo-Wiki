#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;
struct node
{
    char data;
    struct node* next;
};
bool ispalindrome(struct node *head)
{
        stack<struct node*> a;
        struct node *tmp=head;
        while(tmp!=NULL)
        {
              a.push(tmp);
              tmp=tmp->next;
        }
        tmp=head;
        while(tmp!=NULL)
        {
               if(tmp->data!=a.top()->data)
                 return false;
               else
               {
                  a.pop();
                  tmp=tmp->next;
               }
        }
        return true;
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
