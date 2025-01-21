 #include <iostream>
using namespace std;
struct node
{
  int data;
  struct node *next;
};
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}
void append(struct node **head,int v)
{
          struct node *tmp=(struct node *)malloc(sizeof(struct node));
          tmp->data=v;
          tmp->next=*head;
          *head =tmp;
}
void insertafter(struct node *tmp,int a)
{
     struct node *r=(struct node*)malloc(sizeof(struct node));
     r->data=a;
     r->next=tmp->next;
     tmp->next=r;
}
int main()
{
  struct node* head = NULL;
  append(&head, 6);
  push(&head, 7);
  push(&head, 1);
  append(&head, 4);
  insertafter(head->next, 8);
  printf("\n Created Linked list is: ");
  printList(head);

  return 0;
}
