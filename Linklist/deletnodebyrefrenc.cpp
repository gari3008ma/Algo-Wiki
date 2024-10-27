 #include <iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
void push(struct node** head_ref, int new_data)
{
   struct node* new_node =
             (struct node*) malloc(sizeof(struct node));
   new_node->data  = new_data;
   new_node->next = (*head_ref);
   (*head_ref)    = new_node;
}
void printList(struct node *head)
{
   struct node *temp = head;
   while(temp != NULL)
   {
      printf("%d  ", temp->data);
      temp = temp->next;
   }
}
void deleteNode(struct node *node_ptr)
{
           if(node_ptr->next==NULL)
           {
                          node_ptr=NULL;
                          return;
           }
                  struct node *tmp=node_ptr->next;
                  node_ptr->data=tmp->data;
                  node_ptr->next=tmp->next;
                  free(tmp);

}
int main()
{
    struct node* head = NULL;
    struct node *tmp;
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
    tmp=head;
        while(tmp->data!=4)
        {
           tmp=tmp->next;
        }
        tmp=tmp->next;
    printf("Before deleting \n");
    printList(head);
    deleteNode(tmp);
    printf("\nAfter deleting \n");
    printList(head);
    getchar();
    return 0;
}
