
// A C++ program to swap Kth node from beginning with kth node from end
#include <iostream>
#include <stdlib.h>
using namespace std;
 
// A Linked List node
struct Node
{
    int data;
    struct Node *next;
};
 
/* Utility function to insert a node at the beginning */
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
/* Utility function for displaying linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
 
/* Utility function for calculating length of linked list */
int countNodes(struct Node *s)
{
    int count = 0;
    while (s != NULL)
    {
        count++;
        s = s->next;
    }
    return count;
}
 
/* Function for swapping kth nodes from both ends of linked list */
void swapKth(struct Node **head_ref, int k)
{
    int len=countNodes(*head_ref);
    struct Node *tmp,*x,*y,*pre1,*pre2;
    tmp = (*head_ref);
    if(k>len || len==1)
    	return;
    tmp=(*head_ref);
    pre1=tmp;
    int i=1,j=len-k+1;
    if(j==k)
    	return ;

    while(tmp && i<k)
    {
    	pre1=tmp;
    	tmp=tmp->next;
    	i++;
    }
    x=tmp;
    tmp=(*head_ref);
    pre2=tmp;
    i=1;
    while(tmp && i< j)
    {
    	    pre2=tmp;
    		tmp=tmp->next;
    		i++;
    }
    y=tmp;
    if(k==1)
    {
    	tmp=y->next;
    	y->next=x->next;
    	pre2->next=x;
    	x->next=tmp;
    	(*head_ref)=y;
    }
    else if(j==1)
    {
         tmp = x->next;
         x->next=y->next;
         pre1->next=y;
         y->next = tmp;
         (*head_ref)=x;
    }
    else if(pre1==y)
    {
        y->next=x->next;
        x->next=y;
        pre2->next=x;
    }
    else if(pre2==x)
    {
    	x->next = y->next;
    	y->next = x;
    	pre1->next=y;
    }
    else
    {
    	pre1->next=y;
    	pre2->next=x;
    	tmp=x->next;
    	x->next=y->next;
    	y->next=tmp;
    }
}
 
// Driver program to test above functions
int main()
{
    // Let us create the following linked list for testing
    // 1->2->3->4->5->6->7->8
    struct Node *head = NULL;
    for (int i = 8; i >= 1; i--)
       push(&head, i);
 
    cout << "Original Linked List: ";
    printList(head);
 
    for (int k = 1; k < 9; k++)
    {
        swapKth(&head, k);
        cout << "\nModified List for k = " << k << endl;
        printList(head);
    }
 
    return 0;
}