 #include <iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* sortedmerge(struct node *a,struct node *b)
{
    struct node *i,*j,*pre,*tmp;
    i=a;
    j=b;
    if(i==NULL && j==NULL)
      return NULL;
      pre=NULL;
    while(i!=NULL && j!=NULL)
    {

             while((i->data > j->data)&&j!=NULL)
             {
                             pre=j;
                             j=j->next;
             }

             tmp=i->next;
             i->next=j;
             j=i;
             if(pre!=NULL)
                {
                    pre->next=i;

                }
            i=tmp;
    }
    if(i!=NULL)
     pre->next=i;
   return b;
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node* res = NULL;
    struct node* a = NULL;
    struct node* b = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);

    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
    res = sortedmerge(a, b);

    printf("Merged Linked List is: \n");
    printList(res);

    return 0;
}
